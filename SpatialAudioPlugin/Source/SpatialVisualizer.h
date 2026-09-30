/*
  ==============================================================================

    SpatialVisualizer.h

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "HeadMesh.h"
#include <cmath>
#include <vector>

/**
    Shows where the binaural source sits relative to the listener.

    The scene uses x = right, y = up, z = front. Azimuth and elevation set the
    direction, gain sets the distance. Drag empty space to orbit the camera;
    drag the source marker itself to move it.
*/
class SpatialVisualizer : public juce::Component, private juce::Timer
{
public:
    SpatialVisualizer(juce::AudioProcessorValueTreeState& apvts,
                      const juce::ParameterID& azimuthParamID,
                      const juce::ParameterID& elevationParamID,
                      const juce::ParameterID& gainParamID);
    ~SpatialVisualizer() override;

    void paint(juce::Graphics&) override;
    void mouseDown(const juce::MouseEvent&) override;
    void mouseDrag(const juce::MouseEvent&) override;
    void mouseUp(const juce::MouseEvent&) override;

    void setTopView();   // camera looks straight down (bird's-eye)
    void setFrontView(); // camera looks at the face (straight ahead)

private:
    struct Vec3
    {
        float x = 0.0f, y = 0.0f, z = 0.0f;

        Vec3 operator-(Vec3 other) const noexcept { return { x - other.x, y - other.y, z - other.z }; }
        Vec3 operator*(float scale) const noexcept { return { x * scale, y * scale, z * scale }; }

        float dot(Vec3 other) const noexcept { return x * other.x + y * other.y + z * other.z; }

        Vec3 cross(Vec3 other) const noexcept
        {
            return { y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x };
        }

        Vec3 normalised() const noexcept
        {
            const auto length = std::sqrt(x * x + y * y + z * z);
            return length > 1.0e-6f ? Vec3{ x / length, y / length, z / length } : Vec3{ 0.0f, 0.0f, 1.0f };
        }
    };

    // A shaded polygon, already projected to screen space and ready to depth sort
    struct Facet
    {
        juce::Point<float> points[4];
        int numPoints = 3;
        float depth = 0.0f;
        juce::Colour colour;
    };

    void timerCallback() override;

    // Projection. updateViewport() must run before any of the others.
    void updateViewport();
    Vec3 toCameraSpace(Vec3 p) const noexcept;
    juce::Point<float> project(Vec3 p) const noexcept;
    float depthOf(Vec3 p) const noexcept { return toCameraSpace(p).z; }

    float sourceDistance() const;
    Vec3 sourcePosition() const;
    void setSourceFromScreen(juce::Point<float> screenPos);

    void rebuildHeadFacets();
    void addFacet(const Vec3* verts, int numVerts, juce::Colour dark, juce::Colour lit);

    void drawOrbitRings(juce::Graphics&, bool nearSide) const;
    void drawHead(juce::Graphics&) const;
    void drawSourceMarker(juce::Graphics&) const;
    void drawReadout(juce::Graphics&) const;

    static constexpr float cameraDistance = 4.0f;
    static constexpr float ringRadius = 1.5f;
    static constexpr float minSourceDistance = 1.5f;
    static constexpr float maxSourceDistance = 3.4f;

    // Fixed key light, upper-left and slightly in front of the listener (pre-normalised)
    static constexpr Vec3 lightDirection { -0.4243f, 0.5657f, 0.7071f };

    juce::AudioParameterInt* azimuthParam = nullptr;
    juce::AudioParameterInt* elevationParam = nullptr;
    juce::AudioParameterFloat* gainParam = nullptr;

    HeadMesh headMesh;
    std::vector<Facet> facets; // reused every frame so painting doesn't reallocate

    juce::Point<float> viewCentre;
    float focalLength = 1.0f;

    float cameraYaw = -0.5f;
    float cameraPitch = 0.35f;
    juce::Point<float> lastDragPos;

    // When true, dragging edits azimuth/elevation instead of orbiting the camera
    bool draggingSource = false;

    // Cached by paint() so mouseDown can hit-test the marker
    juce::Point<float> sourceScreenPos;
    float sourceMarkerRadius = 6.0f;
    float sourceHitRadius = 12.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SpatialVisualizer)
};
