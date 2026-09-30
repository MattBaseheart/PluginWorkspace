/*
  ==============================================================================

    LabeledSlider.cpp

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LabeledSlider.h"

//==============================================================================
LabeledSlider::LabeledSlider(const juce::String& text, juce::AudioProcessorValueTreeState& apvts,
                             const juce::ParameterID& parameterID, juce::Slider::SliderStyle style)
    : attachment(apvts, parameterID.getParamID(), slider)
{
    slider.setSliderStyle(style);
    if (style == juce::Slider::SliderStyle::LinearHorizontal)
        slider.setTextBoxStyle(juce::Slider::TextBoxRight, false, 48, 18);
    else
        slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 18);
    addAndMakeVisible(slider);

    label.setText(text, juce::NotificationType::dontSendNotification);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);
}

LabeledSlider::~LabeledSlider()
{
}

void LabeledSlider::resized()
{
    auto bounds = getLocalBounds();
    label.setBounds(bounds.removeFromTop(20));
    slider.setBounds(bounds);
}
