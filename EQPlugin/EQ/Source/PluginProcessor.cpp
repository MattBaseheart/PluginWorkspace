/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Parameters.h"

//==============================================================================
EQAudioProcessor::EQAudioProcessor() : AudioProcessor(BusesProperties().withInput("Input", juce::AudioChannelSet::stereo(), true).withOutput("Output", juce::AudioChannelSet::stereo(), true)), params(apvts)
{
    params.highCutFilter.setType(juce::dsp::StateVariableTPTFilterType::lowpass);
    params.lowCutFilter.setType(juce::dsp::StateVariableTPTFilterType::highpass);
}

EQAudioProcessor::~EQAudioProcessor()
{
}

//==============================================================================
const juce::String EQAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool EQAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool EQAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool EQAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double EQAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int EQAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int EQAudioProcessor::getCurrentProgram()
{
    return 0;
}

void EQAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String EQAudioProcessor::getProgramName (int index)
{
    return {};
}

void EQAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void EQAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

    params.gainSmoother.reset(sampleRate, 0.02);
    params.gainSmoother.setCurrentAndTargetValue(juce::Decibels::decibelsToGain(params.gainParam->get()));

    params.lowCutSmoother.reset(sampleRate, 0.02);
    params.lowCutSmoother.setCurrentAndTargetValue(params.lowCutParam->get());

    params.highCutSmoother.reset(sampleRate, 0.02);
    params.highCutSmoother.setCurrentAndTargetValue(params.highCutParam->get());

    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();

    params.lowCutFilter.prepare(spec);
    params.lowCutFilter.reset();

    params.highCutFilter.prepare(spec);
    params.highCutFilter.reset();


	
}

void EQAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool EQAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void EQAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    float gain = params.gainParam->get();

    auto& smoother = params.gainSmoother;
    smoother.setTargetValue(juce::Decibels::decibelsToGain(params.gainParam->get()));

    auto& highCutSmoother = params.highCutSmoother;
    highCutSmoother.setTargetValue(params.highCutParam->get());

    auto& lowCutSmoother = params.lowCutSmoother;
    lowCutSmoother.setTargetValue(params.lowCutParam->get());

    float* channelDataL = buffer.getWritePointer(0);
    float* channelDataR = buffer.getWritePointer(1);

    for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
        const auto gain = smoother.getNextValue();
		params.highCutFilter.setCutoffFrequency(highCutSmoother.getNextValue());
		params.lowCutFilter.setCutoffFrequency(lowCutSmoother.getNextValue());

        float inputSampleL = channelDataL[sample];
		float inputSampleR = channelDataR[sample];

        float outputSampleL = params.highCutFilter.processSample(0, inputSampleL);
        float outputSampleR = params.highCutFilter.processSample(1, inputSampleR);

		float finalSampleL = params.lowCutFilter.processSample(0, outputSampleL);
		float finalSampleR = params.lowCutFilter.processSample(1, outputSampleR);
        
        channelDataL[sample] = finalSampleL * gain;
        channelDataR[sample] = finalSampleR * gain;
    }
}

//==============================================================================
bool EQAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* EQAudioProcessor::createEditor()
{
    return new EQAudioProcessorEditor (*this);
}

//==============================================================================
void EQAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void EQAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new EQAudioProcessor();
}

// Custom Methods

