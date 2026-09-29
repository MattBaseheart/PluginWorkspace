/*
  ==============================================================================

    Parameters.cpp
    Created: 2 Mar 2025 3:09:12pm
    Author:  mbase

  ==============================================================================
*/

#include "Parameters.h"

template<typename T>
static void castParameter(juce::AudioProcessorValueTreeState& apvts, const juce::ParameterID& id, T& destination) 
{
    destination = dynamic_cast<T>(apvts.getParameter(id.getParamID()));
    jassert(destination);
}

static juce::String stringFromDegrees(float value, int) 
{
    return juce::String(int(value)) + " degrees";
}

static juce::String stringFromElevationDegrees(float value, int)
{
    // elevationParam is stored as 0-180 with 90 = level (0 degrees actual elevation)
    return juce::String(int(value) - 90) + " degrees";
}

Parameters::Parameters(juce::AudioProcessorValueTreeState& apvts)
{
    castParameter(apvts, gainParamID, gainParam);
    castParameter(apvts, elevationParamID, elevationParam);
    castParameter(apvts, azimuthParamID, azimuthParam);
}

//return type here is ParameterLayout, this is an implementation of createParameterLayout()
juce::AudioProcessorValueTreeState::ParameterLayout Parameters::createParameterLayout() {
    juce::AudioProcessorValueTreeState::ParameterLayout layout;

    layout.add(std::make_unique<juce::AudioParameterFloat>(gainParamID, "Output Gain", juce::NormalisableRange<float>{-12.0f, 12.0f}, 0.0f));
    layout.add(std::make_unique<juce::AudioParameterInt>(elevationParamID, "Elevation", minElevation, maxElevation, 90, juce::AudioParameterIntAttributes().withStringFromValueFunction(stringFromElevationDegrees)));
    layout.add(std::make_unique<juce::AudioParameterInt>(azimuthParamID, "Azimuth", minAzimuth, maxAzimuth, 180 , juce::AudioParameterIntAttributes().withStringFromValueFunction(stringFromDegrees)));
    return layout;
}