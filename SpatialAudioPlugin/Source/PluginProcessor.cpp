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
  loadIR(0, 90, 44100);
}

SpatialAudioPluginAudioProcessor::~SpatialAudioPluginAudioProcessor()
{
}

//==============================================================================

void SpatialAudioPluginAudioProcessor::initializeIRMap() {
  for (int i = 0; i < sizeof(elevationValues) / sizeof(elevationValues[0]); i++) {
    for (int j = 0; j <= 359; j++) {
      const juce::String nameStr = elevationValues[i] >= 0
          ? "azi_" + juce::String(j) + "_0_ele_" + juce::String(elevationValues[i]) + "_0_wav"
          : "azi_" + juce::String(j) + "_0_ele_neg" + juce::String(std::abs(elevationValues[i])) + "_0_wav";

      // sz is left untouched by getNamedResource() when the name isn't found, so it must start at a known value
      int sz = 0;
      const char* ir = (const char*)HRIR_48k_24bit::getNamedResource(nameStr.toRawUTF8(), sz);
      jassert(ir != nullptr && sz > 0); // Every azimuth/elevation combination used by loadIR() should exist in the dataset
      irMap[j][elevationValues[i]] = {sz, ir};
    }
  }
}

void SpatialAudioPluginAudioProcessor::loadIR(int azi, int ele, int numSamples) {
  // Find the closest valid elevation value
  int closestElevation = 0;
  float smallestElevationDiff = 180.0f;
  for (int i = 0; i < 17; i++) {
    float elDiff = std::abs((ele - 90) - elevationValues[i]);
    if (elDiff < smallestElevationDiff) {
      smallestElevationDiff = elDiff;
      closestElevation = elevationValues[i];
    }
  }

  // A new position was requested: remember it and (re)start the settle delay
  if (azi != pendingAzi || closestElevation != pendingEle) {
    pendingAzi = azi;
    pendingEle = closestElevation;
    loadDelaySamples = loadDelayLengthSamples;
  }

  // Already loaded, nothing to do
  if (pendingAzi == lastAzi && pendingEle == lastEle)
    return;

  // Still waiting for the position to settle before loading its IR
  loadDelaySamples -= numSamples;
  if (loadDelaySamples > 0)
    return;

  // Look up the pending position defensively; the map is only ever populated by initializeIRMap
  const auto aziIt = irMap.find(pendingAzi);
  if (aziIt == irMap.end())
    return;
  const auto eleIt = aziIt->second.find(pendingEle);
  if (eleIt == aziIt->second.end())
    return;

  const auto& entry = eleIt->second;
  if (entry.ir == nullptr || entry.size <= 0)
    return; // Missing/invalid: keep the currently loaded IR

  // When convolution toggle is false, use conv1 - else use conv2
  auto& convToLoadInto = convolutionToggle ? conv1 : conv2;

  convToLoadInto.loadImpulseResponse(
      entry.ir, entry.size,
      juce::dsp::Convolution::Stereo::yes, juce::dsp::Convolution::Trim::yes,
      0, juce::dsp::Convolution::Normalise::no);

  // After loading new IR, toggle to the other convolution for next time
  convolutionToggle = !convolutionToggle;

  // Set the target value for the smoother to either 0.0 or 1.0 depending on which convolution is active
  convolutionMix.setTargetValue(convolutionToggle ? 1.0f : 0.0f);

  lastAzi = pendingAzi;
  lastEle = pendingEle;
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

    // Set up convolution buffers:
    convBuffer1.setSize(spec.numChannels, spec.maximumBlockSize, false, true);
    convBuffer2.setSize(spec.numChannels, spec.maximumBlockSize, false, true);
    monoSourceBuffer.setSize(spec.numChannels, spec.maximumBlockSize, false, true);

    convolutionMix.reset(sampleRate, 0.05);

    // Wait for the position to settle for 100ms before loading a new IR
    loadDelayLengthSamples = (int)std::round(sampleRate * 0.1);
    loadDelaySamples = 0;

    // Set up convolution reverb:
    conv1.reset();
    conv1.prepare(spec);

    conv2.reset();
    conv2.prepare(spec);
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

    int numSamples = buffer.getNumSamples();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, numSamples);

    const int elev = params.elevationParam->get();
    const int azi = params.azimuthParam->get();

    loadIR(azi, elev, numSamples);

    // Turn JUCE buffer into an AudioBlock
    juce::dsp::AudioBlock<float> block{ buffer };

    juce::dsp::AudioBlock<float> tempBlock1 {convBuffer1};
    juce::dsp::AudioBlock<float> tempBlock2 {convBuffer2};
    juce::dsp::AudioBlock<float> monoSourceBlock {monoSourceBuffer};

    // Make sure the tempBlocks are the correct size
    tempBlock1 = tempBlock1.getSubBlock(0, (size_t)numSamples);
    tempBlock2 = tempBlock2.getSubBlock(0, (size_t)numSamples);
    monoSourceBlock = monoSourceBlock.getSubBlock(0, (size_t)numSamples);

    // Downmix to mono and duplicate to both channels: an HRIR pair is one source filtered per-ear, not a stereo matrix
    const float* inputL = buffer.getReadPointer(0);
    const float* inputR = buffer.getReadPointer(1);
    float* monoL = monoSourceBuffer.getWritePointer(0);
    float* monoR = monoSourceBuffer.getWritePointer(1);
    for (int sample = 0; sample < numSamples; ++sample) {
        const float monoSample = 0.5f * (inputL[sample] + inputR[sample]);
        monoL[sample] = monoSample;
        monoR[sample] = monoSample;
    }

    //Pass the new AudioBlock to the conv.process call
    conv1.process(juce::dsp::ProcessContextNonReplacing<float>(monoSourceBlock, tempBlock1));
    conv2.process(juce::dsp::ProcessContextNonReplacing<float>(monoSourceBlock, tempBlock2));

    for (size_t s = 0; s < block.getNumSamples(); s++) {

        const auto conv2Weight = convolutionMix.getNextValue();
        const auto conv1Weight = 1.0f - conv2Weight;

        tempBlock1.setSample(0, s, conv1Weight * tempBlock1.getSample(0, s));
        tempBlock1.setSample(1, s, conv1Weight * tempBlock1.getSample(1, s));
        tempBlock2.setSample(0, s, conv2Weight * tempBlock2.getSample(0, s));
        tempBlock2.setSample(1, s, conv2Weight * tempBlock2.getSample(1, s));
    }

    block.clear();
    block += tempBlock1;
    block += tempBlock2;

    float* channelDataL = buffer.getWritePointer(0);
    float* channelDataR = buffer.getWritePointer(1);

    auto& smoother = params.gainSmoother;
    smoother.setTargetValue(juce::Decibels::decibelsToGain(params.gainParam->get()));

    const auto convolutionMakeupGain = juce::Decibels::decibelsToGain(convolutionMakeupGainDb);

    for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
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
