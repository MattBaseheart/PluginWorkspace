/*
  ==============================================================================

    LabeledSlider.h

    A titled slider (horizontal, vertical, or rotary) used for azimuth, elevation, and gain

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
class LabeledSlider  : public juce::Component
{
public:
    LabeledSlider(const juce::String& text, juce::AudioProcessorValueTreeState& apvts,
                  const juce::ParameterID& parameterID, juce::Slider::SliderStyle style);
    ~LabeledSlider() override;

    void resized() override;

    juce::Slider slider;
    juce::AudioProcessorValueTreeState::SliderAttachment attachment;
    juce::Label label;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LabeledSlider)
};
