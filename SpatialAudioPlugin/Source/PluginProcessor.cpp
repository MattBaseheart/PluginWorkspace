/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
// Here, the : followed by an AudioProcessor constructor call creates that class first. params(apvts) is also in the initializer list
SimpleDelayPluginAudioProcessor::SimpleDelayPluginAudioProcessor() : AudioProcessor(BusesProperties().withInput("Input", juce::AudioChannelSet::stereo(), true).withOutput("Output", juce::AudioChannelSet::stereo(), true)), params(apvts)
{
    // 
  loadIR("C:/Users/mbase/Downloads/D2_HRIR_WAV/D2_HRIR_WAV/48K_24bit/azi_99,0_ele_35,3.wav");
}

SimpleDelayPluginAudioProcessor::~SimpleDelayPluginAudioProcessor()
{
}

//==============================================================================


// juce::AudioBuffer SimpleDelayPluginAudioProcessor::loadDirectoryIR(
//    string directoryName) {
//  /*
//    - Find all files in the dir
//    - currSample = 0
//    - startIndexes[]
//    - AudioBuffer
//    - For each x
//        - startIndex[x] = currSample
//        - currSample += file x.length
//  */
//}

//void SimpleDelayPluginAudioProcessor : UpdateIR(juce::AudioBuffer) 
//{
//  /*
//    Take two floats (one for each param)
//    Map them to an index in the datamap of files
//    Always use floor, not round
//
//
//
//  */
//}


//UpdateIR(startIndex[5], startIndex[6])

void SimpleDelayPluginAudioProcessor::loadIR(const juce::String& filename)
{
  juce::File result = juce::File(filename);
  conv.loadImpulseResponse(result, juce::dsp::Convolution::Stereo::yes,
                           juce::dsp::Convolution::Trim::yes, result.getSize(),
                           juce::dsp::Convolution::Normalise::yes);
}

const juce::String SimpleDelayPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SimpleDelayPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SimpleDelayPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SimpleDelayPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SimpleDelayPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SimpleDelayPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SimpleDelayPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SimpleDelayPluginAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SimpleDelayPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void SimpleDelayPluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SimpleDelayPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    params.prepareToPlay(sampleRate);
    params.reset();

    DBG("==========================================================================================");
    DBG(sampleRate);
    DBG(params.azimuth);
    DBG(params.elevation);
    DBG(params.gain);
    DBG("==========================================================================================");

    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();

    DBG("A");
    // Set up convolution reverb:
    conv.reset();
    conv.prepare(spec);
}

void SimpleDelayPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SimpleDelayPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}
#endif

void SimpleDelayPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, [[maybe_unused]]juce::MidiBuffer& midiMessages)
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

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.

    params.update();

    DBG("-----------------------------------------");
    // Find the azimuth[] and elevation[] values closest to params.azimuth and
    // params.elevation
    int closestElevation = 0;
    float smallestElevationDiff = 180.0f;
    DBG("Elevation: " + juce::String(params.elevation));
    DBG("Azimuth: " + juce::String(params.azimuth));
    for (int i = 0; i < 17; i++) {
      float elDiff = std::abs((params.elevation - 90) - elevationValues[i]);
      if (elDiff < smallestElevationDiff) {
        DBG("Found a closer elevation: " + juce::String(elevationValues[i]) +
            " with diff: " + juce::String(elDiff));
        smallestElevationDiff = elDiff;
        closestElevation = elevationValues[i];
      }
    }
    int closestAzimuth = (int)params.azimuth;

    DBG("C:/Users/mbase/Downloads/D2_HRIR_WAV/D2_HRIR_WAV/48K_24bit/azi_" +
        juce::String(closestAzimuth) + ",0_ele_" +
        juce::String(closestElevation) + ",0.wav");
    // Load the IR file that corresponds to the closest azimuth and elevation
    loadIR("C:/Users/mbase/Downloads/D2_HRIR_WAV/D2_HRIR_WAV/48K_24bit/azi_" +
           juce::String(closestAzimuth) + ",0_ele_" +
           juce::String(closestElevation) + ",0.wav");

    // Turn JUCE buffer into an AudioBlock
    juce::dsp::AudioBlock<float> block{ buffer };

    //Pass the new AudioBlock to the conv.process call
    conv.process(juce::dsp::ProcessContextReplacing<float>(block));
    
    float* channelDataL = buffer.getWritePointer(0);
    float* channelDataR = buffer.getWritePointer(1);

    for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
        params.smoothen();

        channelDataL[sample] = channelDataL[sample] * params.gain;
        channelDataR[sample] = channelDataR[sample] * params.gain;
    }
    
}

//==============================================================================
bool SimpleDelayPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

// The PluginProcessor creates an instance of the Editor here
juce::AudioProcessorEditor* SimpleDelayPluginAudioProcessor::createEditor()
{
    return new SimpleDelayPluginAudioProcessorEditor (*this);
}

//==============================================================================
void SimpleDelayPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    copyXmlToBinary(*apvts.copyState().createXml(), destData);
}

void SimpleDelayPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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
    return new SimpleDelayPluginAudioProcessor();
}
