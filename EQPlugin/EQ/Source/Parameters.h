/*
  ==============================================================================

    Parameters.h
    Created: 27 Oct 2025 8:20:52pm
    Author:  mbase

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

const juce::ParameterID gainParamID{ "gain", 1 };
const juce::ParameterID lowCutParamID{ "lowCut", 1 };
const juce::ParameterID highCutParamID{ "highCut", 1 };

class Parameters 
{
public:
    Parameters(juce::AudioProcessorValueTreeState& apvts);

    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    float gain = 0.0f;
    float lowCut = 20.0f;
    float highCut = 20000.0f;

    juce::AudioParameterFloat* gainParam;
    juce::LinearSmoothedValue<float> gainSmoother;

    juce::AudioParameterFloat* lowCutParam;
    juce::LinearSmoothedValue<float> lowCutSmoother;

    juce::AudioParameterFloat* highCutParam;
    juce::LinearSmoothedValue<float> highCutSmoother;

	juce::dsp::StateVariableTPTFilter<float> lowCutFilter;
	juce::dsp::StateVariableTPTFilter<float> highCutFilter;

    //Only allow one unique instance of this class, and include leak detector
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Parameters)
};
