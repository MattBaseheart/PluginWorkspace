/*
  ==============================================================================

    SpatialLookAndFeel.h

    Red / white / black theme. Draws vertical linear sliders as a dark track with
    a red value fill and a white thumb.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SpatialLookAndFeel : public juce::LookAndFeel_V4
{
public:
    // Shared palette so the editor and visualizer can match the sliders
    inline static const juce::Colour background { 0xff0e0e0e };
    inline static const juce::Colour panel      { 0xff1a1a1a };
    inline static const juce::Colour accent     { 0xffd21f26 };
    inline static const juce::Colour light      { 0xfff2f2f2 };
    inline static const juce::Colour track      { 0xff333333 };

    SpatialLookAndFeel();
    ~SpatialLookAndFeel() override; // out-of-line to anchor the vtable in the .cpp

    void drawLinearSlider(juce::Graphics&, int x, int y, int width, int height,
                          float sliderPos, float minSliderPos, float maxSliderPos,
                          juce::Slider::SliderStyle, juce::Slider&) override;

    void drawRotarySlider(juce::Graphics&, int x, int y, int width, int height,
                          float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle,
                          juce::Slider&) override;
};
