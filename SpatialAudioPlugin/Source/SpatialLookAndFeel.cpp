/*
  ==============================================================================

    SpatialLookAndFeel.cpp

  ==============================================================================
*/

#include "SpatialLookAndFeel.h"

SpatialLookAndFeel::SpatialLookAndFeel()
{
    setColour(juce::ResizableWindow::backgroundColourId, background);
    setColour(juce::Slider::textBoxTextColourId, light);
    setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
    setColour(juce::Label::textColourId, light);
}

SpatialLookAndFeel::~SpatialLookAndFeel() = default;

void SpatialLookAndFeel::drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height,
                                          float sliderPos, float /*minSliderPos*/, float /*maxSliderPos*/,
                                          juce::Slider::SliderStyle /*style*/, juce::Slider& slider)
{
    const auto trackWidth = 6.0f;
    const auto thumbRadius = 9.0f;

    if (slider.isHorizontal()) {
        const auto centreY = (float)y + (float)height * 0.5f;
        const auto left = (float)x;

        g.setColour(track);
        g.fillRoundedRectangle(left, centreY - trackWidth * 0.5f, (float)width, trackWidth, trackWidth * 0.5f);

        // Value fill runs from the left of the track up to the thumb
        g.setColour(accent);
        g.fillRoundedRectangle(left, centreY - trackWidth * 0.5f, juce::jmax(0.0f, sliderPos - left), trackWidth, trackWidth * 0.5f);

        g.setColour(light);
        g.fillEllipse(sliderPos - thumbRadius, centreY - thumbRadius, thumbRadius * 2.0f, thumbRadius * 2.0f);
        g.setColour(juce::Colours::black.withAlpha(0.4f));
        g.drawEllipse(sliderPos - thumbRadius, centreY - thumbRadius, thumbRadius * 2.0f, thumbRadius * 2.0f, 1.0f);
    } else {
        const auto centreX = (float)x + (float)width * 0.5f;
        const auto top = (float)y;
        const auto bottom = (float)(y + height);

        g.setColour(track);
        g.fillRoundedRectangle(centreX - trackWidth * 0.5f, top, trackWidth, (float)height, trackWidth * 0.5f);

        // Value fill runs from the thumb down to the bottom of the track
        g.setColour(accent);
        g.fillRoundedRectangle(centreX - trackWidth * 0.5f, sliderPos, trackWidth, juce::jmax(0.0f, bottom - sliderPos), trackWidth * 0.5f);

        g.setColour(light);
        g.fillEllipse(centreX - thumbRadius, sliderPos - thumbRadius, thumbRadius * 2.0f, thumbRadius * 2.0f);
        g.setColour(juce::Colours::black.withAlpha(0.4f));
        g.drawEllipse(centreX - thumbRadius, sliderPos - thumbRadius, thumbRadius * 2.0f, thumbRadius * 2.0f, 1.0f);
    }
}

void SpatialLookAndFeel::drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height,
                                          float sliderPos, float rotaryStartAngle, float rotaryEndAngle,
                                          juce::Slider& /*slider*/)
{
    const auto bounds = juce::Rectangle<float>((float)x, (float)y, (float)width, (float)height).reduced(6.0f);
    const auto lineW = 4.0f;
    const auto radius = juce::jmin(bounds.getWidth(), bounds.getHeight()) * 0.5f;
    const auto arcRadius = radius - lineW;
    const auto centreX = bounds.getCentreX();
    const auto centreY = bounds.getCentreY();
    const auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

    juce::Path backArc;
    backArc.addCentredArc(centreX, centreY, arcRadius, arcRadius, 0.0f, rotaryStartAngle, rotaryEndAngle, true);
    g.setColour(track);
    g.strokePath(backArc, juce::PathStrokeType(lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));

    juce::Path valueArc;
    valueArc.addCentredArc(centreX, centreY, arcRadius, arcRadius, 0.0f, rotaryStartAngle, angle, true);
    g.setColour(accent);
    g.strokePath(valueArc, juce::PathStrokeType(lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));

    const auto bodyRadius = arcRadius - 4.0f;
    g.setColour(panel);
    g.fillEllipse(centreX - bodyRadius, centreY - bodyRadius, bodyRadius * 2.0f, bodyRadius * 2.0f);

    const juce::Point<float> thumb(centreX + arcRadius * std::cos(angle - juce::MathConstants<float>::halfPi),
                                   centreY + arcRadius * std::sin(angle - juce::MathConstants<float>::halfPi));
    g.setColour(light);
    g.drawLine(centreX, centreY, thumb.x, thumb.y, 2.0f);
}
