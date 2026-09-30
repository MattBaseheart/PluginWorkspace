/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Parameters.h"
#include "LabeledSlider.h"
#include "SpatialLookAndFeel.h"
#include "SpatialVisualizer.h"

//==============================================================================
/**
*/
class SpatialAudioPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SpatialAudioPluginAudioProcessorEditor (SpatialAudioPluginAudioProcessor&);
    ~SpatialAudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SpatialAudioPluginAudioProcessor& audioProcessor;

    // Declared first so it outlives the child components that reference it
    SpatialLookAndFeel lookAndFeel;

    SpatialVisualizer visualizer{ audioProcessor.apvts, azimuthParamID, elevationParamID, gainParamID };

    LabeledSlider azimuthSlider{ "Azimuth", audioProcessor.apvts, azimuthParamID, juce::Slider::SliderStyle::LinearHorizontal };
    LabeledSlider elevationSlider{ "Elevation", audioProcessor.apvts, elevationParamID, juce::Slider::SliderStyle::LinearVertical };
    LabeledSlider gainSlider{ "Gain", audioProcessor.apvts, gainParamID, juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag };

    juce::TextButton topViewButton{ "Top" };
    juce::TextButton frontViewButton{ "Front" };

    std::unique_ptr<juce::Drawable> logo;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpatialAudioPluginAudioProcessorEditor)
};
