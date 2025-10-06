/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "BinaryData.h"

//==============================================================================
// Here, the : followed by an AudioProcessor constructor call creates that class first. params(apvts) is also in the initializer list
SpatialAudioPluginAudioProcessor::SpatialAudioPluginAudioProcessor() : AudioProcessor(BusesProperties().withInput("Input", juce::AudioChannelSet::stereo(), true).withOutput("Output", juce::AudioChannelSet::stereo(), true)), params(apvts)
{
  initializeIRMap();
  loadIR(0, 90);
}

SpatialAudioPluginAudioProcessor::~SpatialAudioPluginAudioProcessor()
{
}

//==============================================================================

void SpatialAudioPluginAudioProcessor::initializeIRMap() {
  for (int i = 0; i < sizeof(elevationValues) / sizeof(elevationValues[0]); i++) {
    for (int j = 0; j <= 359; j++) {
      const char* name;
      int sz;
      if (elevationValues[i] >= 0) {
        juce::String nameStr = "azi_" + juce::String(j) + "_0_ele_" + juce::String(elevationValues[i]) + "_0_wav";
        name = nameStr.toRawUTF8();
        const char* getNamedResource =
            (const char*)HRIR_48k_24bit::getNamedResource(name, sz);
        irMap[j][i] = {sz, getNamedResource};
      } else {
        juce::String nameStr = "azi_" + juce::String(j) + "_0_ele_neg" + juce::String(std::abs(elevationValues[i])) + "_0_wav";
        name = nameStr.toRawUTF8();
        const char* getNamedResource =
            (const char*)HRIR_48k_24bit::getNamedResource(name, sz);
        irMap[j][i] = {sz, getNamedResource};
      }
    }
  }
}

void SpatialAudioPluginAudioProcessor::loadIR(int azi, int ele) {
  
  // Find the closest valid elevation value
  int closestElevation = 0;
  float smallestElevationDiff = 180.0f;
  for (int i = 0; i < 17; i++) {
    float elDiff = std::abs((ele-90) - elevationValues[i]);
    if (elDiff < smallestElevationDiff) {
      smallestElevationDiff = elDiff;
      closestElevation = elevationValues[i];
    }
  }

  if (azi == lastAzi && closestElevation == lastEle) {
    return;
  }
  
  // Load as binary data
  conv.loadImpulseResponse(irMap[azi][closestElevation].ir, 
                           irMap[azi][closestElevation].size,
                           juce::dsp::Convolution::Stereo::yes,
                           juce::dsp::Convolution::Trim::yes, 0,
                           juce::dsp::Convolution::Normalise::yes);
  lastAzi = azi;
  lastEle = closestElevation;
}

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
    return 0.0;
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

    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();

    // Set up convolution reverb:
    conv.reset();
    conv.prepare(spec);
}

void SpatialAudioPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SpatialAudioPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}
#endif

void SpatialAudioPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, [[maybe_unused]]juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    const int elev = params.elevationParam->get();
    const int azi = params.azimuthParam->get();

    loadIR(azi, elev);

    // Turn JUCE buffer into an AudioBlock
    juce::dsp::AudioBlock<float> block{ buffer };

    //Pass the new AudioBlock to the conv.process call
    conv.process(juce::dsp::ProcessContextReplacing<float>(block));

    float* channelDataL = buffer.getWritePointer(0);
    float* channelDataR = buffer.getWritePointer(1);

    auto& smoother = params.gainSmoother;
    smoother.setTargetValue(juce::Decibels::decibelsToGain(params.gainParam->get()));

    for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
        const auto gain = smoother.getNextValue();
        channelDataL[sample] = channelDataL[sample] * gain;
        channelDataR[sample] = channelDataR[sample] * gain;
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
