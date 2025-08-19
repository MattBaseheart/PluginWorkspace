/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Parameters.h"

//==============================================================================
/**
*/
class SimpleDelayPluginAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    SimpleDelayPluginAudioProcessor();
    ~SimpleDelayPluginAudioProcessor() override;

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

    void loadIR(const juce::String& filename);

    juce::AudioProcessorValueTreeState apvts{ *this, nullptr, "Parameters", Parameters::createParameterLayout() };
    
private:
    // Here, the params between {} are passed onto the constructor
    // *this - connect the instance to this AudioProcessor object
    // nullptr - don't use a undo manager here
    // createParameterLayout() - provide a helper function that will generate a full list of parameters
    
    Parameters params;
    juce::dsp::Convolution conv;
    juce::dsp::ProcessSpec spec;

    int elevationValues[17] = {-81, -75, -60, -54, -45, -30, -25, -15, 0, 15,  25,  30,  45,  54,  60,  75,  90};
    
    //DelayLine is a class template, needs additional properties
    juce::dsp::DelayLine<float, juce::dsp::DelayLineInterpolationTypes::Linear> delayLine;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleDelayPluginAudioProcessor)
};
