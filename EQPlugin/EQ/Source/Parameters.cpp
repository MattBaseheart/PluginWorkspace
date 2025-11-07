/*
  ==============================================================================

    Parameters.cpp
    Created: 27 Oct 2025 8:20:52pm
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

Parameters::Parameters(juce::AudioProcessorValueTreeState& apvts)
{
    castParameter(apvts, gainParamID, gainParam);
    castParameter(apvts, lowCutParamID, lowCutParam);
    castParameter(apvts, highCutParamID, highCutParam);

	highCutFilter.setType(juce::dsp::StateVariableTPTFilterType::lowpass);
	lowCutFilter.setType(juce::dsp::StateVariableTPTFilterType::highpass);

	highCutFilter.setResonance(0.707f);
	lowCutFilter.setResonance(0.707f);
}

juce::AudioProcessorValueTreeState::ParameterLayout Parameters::createParameterLayout()
{
    // Create parameter layout here
    juce::AudioProcessorValueTreeState::ParameterLayout layout;

    // Example parameter
    layout.add(std::make_unique<juce::AudioParameterFloat>(gainParamID, "Output Gain", juce::NormalisableRange<float> { -12.0f, 12.0f }, 0.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>(lowCutParamID, "Low Cut Frequency", juce::NormalisableRange<float> { 20.0f, 20000.0f, 1.0f, 0.3f }, 20.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>(highCutParamID, "High Cut Frequency", juce::NormalisableRange<float> { 20.0f, 20000.0f, 1.0f, 0.3f }, 20000.0f));
    return layout;
}
