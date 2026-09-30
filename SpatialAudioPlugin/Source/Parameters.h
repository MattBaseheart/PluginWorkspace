/*
  ==============================================================================

    Parameters.h

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

const juce::ParameterID gainParamID{ "gain", 1 };
const juce::ParameterID azimuthParamID{ "azimuth", 1 };
const juce::ParameterID elevationParamID{ "elevation", 1 };

class Parameters 
{
public:

    Parameters(juce::AudioProcessorValueTreeState& apvts);

    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    // Elevation is stored as 0..180 so the host sees a positive range; 90 is level
    static constexpr int minElevation = 0;
    static constexpr int maxElevation = 180;
    static constexpr int minAzimuth = 0;
    static constexpr int maxAzimuth = 359;

    juce::AudioParameterFloat* gainParam;
    juce::LinearSmoothedValue<float> gainSmoother;

    juce::AudioParameterInt* azimuthParam;

    juce::AudioParameterInt* elevationParam;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Parameters)

};
