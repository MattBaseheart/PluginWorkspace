/*
  ==============================================================================

    Parameters.h
    Created: 2 Mar 2025 3:09:12pm
    Author:  mbase

  ==============================================================================
*/

//Read the Parameters.h ONLY ONCE even if it is referenced in multiple files
#pragma once

// Tells the C++ compiler what juce:: means
#include <JuceHeader.h>

// Create parameters as constants + tie a PID to it
const juce::ParameterID gainParamID{ "gain", 1 };
const juce::ParameterID azimuthParamID{ "azimuth", 1 };
const juce::ParameterID elevationParamID{ "elevation", 1 };

class Parameters 
{
public:

    Parameters(juce::AudioProcessorValueTreeState& apvts);

    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    static constexpr int minElevation = 0;
    static constexpr int maxElevation = 180;
    static constexpr int minAzimuth = 0;
    static constexpr int maxAzimuth = 360;

    juce::AudioParameterFloat* gainParam;
    juce::LinearSmoothedValue<float> gainSmoother;

    juce::AudioParameterInt* azimuthParam;

    juce::AudioParameterInt* elevationParam;

    //Only allow one unique instance of this class, and include leak detector
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Parameters)

};
