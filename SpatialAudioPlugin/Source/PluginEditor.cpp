/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "BinaryData.h"

//==============================================================================
SpatialAudioPluginAudioProcessorEditor::SpatialAudioPluginAudioProcessorEditor (SpatialAudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setLookAndFeel(&lookAndFeel);

    logo = juce::Drawable::createFromImageData(HRIR_48k_24bit::BaseheartLabs_svg, HRIR_48k_24bit::BaseheartLabs_svgSize);
    if (logo != nullptr)
        logo->replaceColour(juce::Colours::black, SpatialLookAndFeel::light);

    addAndMakeVisible(azimuthSlider);
    addAndMakeVisible(elevationSlider);
    addAndMakeVisible(gainSlider);
    addAndMakeVisible(visualizer);

    for (auto* b : { &topViewButton, &frontViewButton }) {
        b->setColour(juce::TextButton::buttonColourId, SpatialLookAndFeel::panel);
        b->setColour(juce::TextButton::textColourOffId, SpatialLookAndFeel::light);
        addAndMakeVisible(*b);
    }
    topViewButton.onClick = [this] { visualizer.setTopView(); };
    frontViewButton.onClick = [this] { visualizer.setFrontView(); };

    setSize (500, 470);
}

SpatialAudioPluginAudioProcessorEditor::~SpatialAudioPluginAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

//==============================================================================
void SpatialAudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    juce::ColourGradient bg(SpatialLookAndFeel::panel, 0.0f, 0.0f,
                            SpatialLookAndFeel::background, 0.0f, (float)getHeight(), false);
    g.setGradientFill(bg);
    g.fillAll();

    auto header = getLocalBounds().removeFromTop(40);

    if (logo != nullptr) {
        auto logoArea = header.removeFromRight(96).toFloat().reduced(14, 7);
        logo->drawWithin(g, logoArea, juce::RectanglePlacement::centred, 0.9f);
    }

    g.setColour(SpatialLookAndFeel::light);
    g.setFont(juce::Font(juce::FontOptions(22.0f)).boldened());
    g.drawText("SPATIAL", header.reduced(16, 0), juce::Justification::centredLeft);

    g.setColour(SpatialLookAndFeel::accent);
    g.setFont(juce::FontOptions(12.0f));
    g.drawText("BINAURAL PANNER", header.reduced(16, 0), juce::Justification::centredRight);
}

void SpatialAudioPluginAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    bounds.removeFromTop(40); // header
    visualizer.setBounds(bounds.removeFromTop(270).reduced(20, 0));

    auto controls = bounds.reduced(16, 8);

    // Right: gain knob, then the vertical elevation slider
    gainSlider.setBounds(controls.removeFromRight(104));
    elevationSlider.setBounds(controls.removeFromRight(84));
    controls.removeFromRight(10);

    // Left column: horizontal azimuth slider on top, view presets below
    azimuthSlider.setBounds(controls.removeFromTop(controls.getHeight() - 40));
    controls.removeFromTop(6);
    const auto buttonWidth = (controls.getWidth() - 8) / 2;
    topViewButton.setBounds(controls.removeFromLeft(buttonWidth));
    controls.removeFromLeft(8);
    frontViewButton.setBounds(controls.removeFromLeft(buttonWidth));
}
