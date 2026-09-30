/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
// Here, the : followed by an AudioProcessor constructor call creates that class first. params(apvts) is also in the initializer list
SpatialAudioPluginAudioProcessor::SpatialAudioPluginAudioProcessor() : AudioProcessor(BusesProperties().withInput("Input", juce::AudioChannelSet::stereo(), true).withOutput("Output", juce::AudioChannelSet::stereo(), true)), params(apvts)
{
}

SpatialAudioPluginAudioProcessor::~SpatialAudioPluginAudioProcessor()
{
}

//==============================================================================

const juce::String SpatialAudioPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SpatialAudioPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SpatialAudioPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SpatialAudioPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SpatialAudioPluginAudioProcessor::getTailLengthSeconds() const
{
    // Report the HRIR length so hosts don't truncate the tail on render
    const auto sr = getSampleRate();
    return convolver.getIrLength() / (sr > 0.0 ? sr : 48000.0);
}

int SpatialAudioPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SpatialAudioPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SpatialAudioPluginAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SpatialAudioPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void SpatialAudioPluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SpatialAudioPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

    params.gainSmoother.reset(sampleRate, 0.02);
    params.gainSmoother.setCurrentAndTargetValue(juce::Decibels::decibelsToGain(params.gainParam->get()));

    monoBuffer.setSize(1, samplesPerBlock, false, false, true);

    convolver.prepare(sampleRate);
    convolver.setPosition(params.azimuthParam->get(), params.elevationParam->get() - 90);
    convolver.reset(); // start on the current position rather than fading in from the default
}

void SpatialAudioPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SpatialAudioPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    // processBlock reads two input channels, so require stereo in as well as out
    return layouts.getMainInputChannelSet() == juce::AudioChannelSet::stereo()
        && layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}
#endif

void SpatialAudioPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, [[maybe_unused]]juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    const int numSamples = buffer.getNumSamples();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, numSamples);

    convolver.setPosition(params.azimuthParam->get(), params.elevationParam->get() - 90);

    // An HRIR pair is one source filtered per ear, so collapse the input to a single source first
    auto* mono = monoBuffer.getWritePointer(0);
    {
        const float* inputL = buffer.getReadPointer(0);
        const float* inputR = buffer.getReadPointer(1);
        for (int i = 0; i < numSamples; ++i)
            mono[i] = 0.5f * (inputL[i] + inputR[i]);
    }

    float* channelDataL = buffer.getWritePointer(0);
    float* channelDataR = buffer.getWritePointer(1);
    convolver.process(mono, channelDataL, channelDataR, numSamples);

    auto& smoother = params.gainSmoother;
    smoother.setTargetValue(juce::Decibels::decibelsToGain(params.gainParam->get()));

    const auto convolutionMakeupGain = juce::Decibels::decibelsToGain(convolutionMakeupGainDb);

    for (int sample = 0; sample < numSamples; sample++) {
        const auto gain = smoother.getNextValue() * convolutionMakeupGain;

        // Hard safety ceiling: the fixed makeup gain above can otherwise clip full-scale input
        channelDataL[sample] = juce::jlimit(-1.0f, 1.0f, channelDataL[sample] * gain);
        channelDataR[sample] = juce::jlimit(-1.0f, 1.0f, channelDataR[sample] * gain);
    }
}

//==============================================================================
bool SpatialAudioPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

// The PluginProcessor creates an instance of the Editor here
juce::AudioProcessorEditor* SpatialAudioPluginAudioProcessor::createEditor()
{
    return new SpatialAudioPluginAudioProcessorEditor (*this);
}

//==============================================================================
void SpatialAudioPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    copyXmlToBinary(*apvts.copyState().createXml(), destData);
}

void SpatialAudioPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<juce::XmlElement> xml(getXmlFromBinary(data, sizeInBytes));
    if (xml.get() != nullptr && xml->hasTagName(apvts.state.getType())) {
        apvts.replaceState(juce::ValueTree::fromXml(*xml));
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SpatialAudioPluginAudioProcessor();
}
