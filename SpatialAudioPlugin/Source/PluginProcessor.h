/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Parameters.h"
#include "HrtfConvolver.h"

//==============================================================================
/**
*/
class SpatialAudioPluginAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    SpatialAudioPluginAudioProcessor();
    ~SpatialAudioPluginAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    juce::AudioProcessorValueTreeState apvts{ *this, nullptr, "Parameters", Parameters::createParameterLayout() };
    
private:
    // Here, the params between {} are passed onto the constructor
    // *this - connect the instance to this AudioProcessor object
    // nullptr - don't use a undo manager here
    // createParameterLayout() - provide a helper function that will generate a full list of parameters
    
    Parameters params;

    HrtfConvolver convolver;
    juce::AudioBuffer<float> monoBuffer; // input collapsed to mono, since an HRIR pair filters one source per ear

    // Dataset HRIRs measure ~-90 dBFS peak; a single global gain (not per-IR normalisation) restores level
    // without erasing the interaural level difference between positions
    static constexpr float convolutionMakeupGainDb = 20.0f;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpatialAudioPluginAudioProcessor)
};
