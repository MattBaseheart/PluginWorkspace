/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Parameters.h"
#include <map>

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

    void loadIR(int azi, int ele, int numSamples);
    void initializeIRMap();

    juce::AudioProcessorValueTreeState apvts{ *this, nullptr, "Parameters", Parameters::createParameterLayout() };
    
private:
    // Here, the params between {} are passed onto the constructor
    // *this - connect the instance to this AudioProcessor object
    // nullptr - don't use a undo manager here
    // createParameterLayout() - provide a helper function that will generate a full list of parameters
    
    Parameters params;
    juce::dsp::Convolution conv1;
    juce::AudioBuffer<float> convBuffer1; 
    juce::dsp::Convolution conv2;
    juce::AudioBuffer<float> convBuffer2; 
    juce::dsp::ProcessSpec spec;

    bool convolutionToggle = false;  // Toggle to switch between conv1 and conv2
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> convolutionMix;
    juce::SmoothedValue<float, juce::ValueSmoothingTypes::Linear> convolutionDebounce; //Set to 0, counts to 1 when parameter changes, only allow IR load when at 1

    float convWeight = 1.0f;  // Weighting factor for the convolution output (0.0 signifying conv1 used, 1.0 signifying conv2 used)
    float convTransitionSpeed = 0.1f; // Speed of transition between conv1 and conv2
    float timeSinceLastIRLoad = 0.0f; // Time since last IR load, used to throttle IR loading

    struct HRIR_48K_24bit_Entry {
      int size;
      const char* ir;
    };

    // Ordered 2D map: azimuth -> elevation -> IR value
    std::map<int, std::map<int, HRIR_48K_24bit_Entry>> irMap;

    int elevationValues[17] = {-81, -75, -60, -54, -45, -30, -25, -15, 0, 15,  25,  30,  45,  54,  60,  75,  90};
    
    //DelayLine is a class template, needs additional properties
    juce::dsp::DelayLine<float, juce::dsp::DelayLineInterpolationTypes::Linear> delayLine;

    // Initial values that are impossible, so the first run always triggers a load
    int lastAzi = -500;
    int lastEle = -500;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpatialAudioPluginAudioProcessor)
};
