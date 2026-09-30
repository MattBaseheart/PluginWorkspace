/*
  ==============================================================================

    SpatialVisualizer.cpp

  ==============================================================================
*/

#include "SpatialVisualizer.h"
#include "SpatialLookAndFeel.h"
#include "BinaryData.h"
#include <algorithm>

namespace {

constexpr float elevationOffset = 90.0f; // the parameter stores 0..180 with 90 = level

const juce::Colour headDark { 0xff141414 };
const juce::Colour headLit  { 0xff9c9c9c };

} // namespace

SpatialVisualizer::SpatialVisualizer(juce::AudioProcessorValueTreeState& apvts,
                                     const juce::ParameterID& azimuthParamID,
                                     const juce::ParameterID& elevationParamID,
                                     const juce::ParameterID& gainParamID)
{
    azimuthParam = dynamic_cast<juce::AudioParameterInt*>(apvts.getParameter(azimuthParamID.getParamID()));
    elevationParam = dynamic_cast<juce::AudioParameterInt*>(apvts.getParameter(elevationParamID.getParamID()));
    gainParam = dynamic_cast<juce::AudioParameterFloat*>(apvts.getParameter(gainParamID.getParamID()));
    jassert(azimuthParam != nullptr && elevationParam != nullptr && gainParam != nullptr);

    headMesh.loadFromObj(HRIR_48k_24bit::Skull_obj, HRIR_48k_24bit::Skull_objSize);

    startTimerHz(30);
}

SpatialVisualizer::~SpatialVisualizer()
{
    stopTimer();
}

void SpatialVisualizer::timerCallback()
{
    // Parameters can change from automation as well as the mouse, so just repaint on every tick
    repaint();
}

//==============================================================================
// Projection

void SpatialVisualizer::updateViewport()
{
    const auto bounds = getLocalBounds().toFloat();
    viewCentre = bounds.getCentre();
    focalLength = juce::jmin(bounds.getWidth(), bounds.getHeight()) * 0.2f * cameraDistance;
}

SpatialVisualizer::Vec3 SpatialVisualizer::toCameraSpace(Vec3 p) const noexcept
{
    // Orbiting the scene by (yaw, pitch) is equivalent to orbiting the camera around it
    const auto cosYaw = std::cos(cameraYaw), sinYaw = std::sin(cameraYaw);
    const Vec3 yawed{ p.x * cosYaw + p.z * sinYaw, p.y, -p.x * sinYaw + p.z * cosYaw };

    const auto cosPitch = std::cos(cameraPitch), sinPitch = std::sin(cameraPitch);
    return { yawed.x,
             yawed.y * cosPitch - yawed.z * sinPitch,
             yawed.y * sinPitch + yawed.z * cosPitch };
}

juce::Point<float> SpatialVisualizer::project(Vec3 p) const noexcept
{
    const auto camera = toCameraSpace(p);
    const auto scale = focalLength / juce::jmax(0.2f, camera.z + cameraDistance);
    return { viewCentre.x + camera.x * scale, viewCentre.y - camera.y * scale };
}

//==============================================================================
// Source position

float SpatialVisualizer::sourceDistance() const
{
    return juce::jmap(gainParam->get(), -12.0f, 12.0f, maxSourceDistance, minSourceDistance);
}

SpatialVisualizer::Vec3 SpatialVisualizer::sourcePosition() const
{
    const auto azimuth = juce::degreesToRadians((float)azimuthParam->get());
    const auto elevation = juce::degreesToRadians((float)elevationParam->get() - elevationOffset);

    const Vec3 direction{ std::sin(azimuth) * std::cos(elevation),
                          std::sin(elevation),
                          std::cos(azimuth) * std::cos(elevation) };

    return direction * sourceDistance();
}

void SpatialVisualizer::setSourceFromScreen(juce::Point<float> screenPos)
{
    updateViewport();

    const float radius = sourceDistance();

    // Orthographic unprojection using the projection scale at the scene centre
    const float scale = focalLength / cameraDistance;
    float vx = (screenPos.x - viewCentre.x) / scale;
    float vy = -(screenPos.y - viewCentre.y) / scale;

    // Constrain to the source sphere, clamping to the rim when the cursor is outside it
    const float radial = vx * vx + vy * vy;
    float vz;
    if (radial >= radius * radius) {
        const float shrink = radius / std::sqrt(radial);
        vx *= shrink;
        vy *= shrink;
        vz = 0.0f;
    } else {
        vz = -std::sqrt(radius * radius - radial); // hemisphere facing the camera
    }

    // Inverse camera rotation (view -> world): undo pitch, then undo yaw
    const float cosPitch = std::cos(cameraPitch), sinPitch = std::sin(cameraPitch);
    const float px = vx;
    const float py = vy * cosPitch + vz * sinPitch;
    const float pz = -vy * sinPitch + vz * cosPitch;

    const float cosYaw = std::cos(cameraYaw), sinYaw = std::sin(cameraYaw);
    const float wx = px * cosYaw - pz * sinYaw;
    const float wy = py;
    const float wz = px * sinYaw + pz * cosYaw;

    const float normalisedY = juce::jlimit(-1.0f, 1.0f, wy / radius);
    const int elevation = juce::jlimit(0, 180,
        (int)std::lround(juce::radiansToDegrees(std::asin(normalisedY)) + elevationOffset));
    const int azimuth = ((int)std::lround(juce::radiansToDegrees(std::atan2(wx, wz))) % 360 + 360) % 360;

    azimuthParam->setValueNotifyingHost(azimuthParam->convertTo0to1((float)azimuth));
    elevationParam->setValueNotifyingHost(elevationParam->convertTo0to1((float)elevation));
}

//==============================================================================
// Mouse

void SpatialVisualizer::mouseDown(const juce::MouseEvent& e)
{
    // Grab the marker if the click landed on it, otherwise start orbiting
    draggingSource = e.position.getDistanceFrom(sourceScreenPos) <= sourceHitRadius;

    if (draggingSource) {
        azimuthParam->beginChangeGesture();
        elevationParam->beginChangeGesture();
    }

    lastDragPos = e.position;
}

void SpatialVisualizer::mouseDrag(const juce::MouseEvent& e)
{
    if (draggingSource) {
        setSourceFromScreen(e.position);
    } else {
        const auto delta = e.position - lastDragPos;
        cameraYaw += delta.x * 0.01f;
        cameraPitch = juce::jlimit(-juce::MathConstants<float>::halfPi,
                                    juce::MathConstants<float>::halfPi, cameraPitch - delta.y * 0.01f);
    }

    lastDragPos = e.position;
    repaint();
}

void SpatialVisualizer::mouseUp(const juce::MouseEvent&)
{
    if (draggingSource) {
        azimuthParam->endChangeGesture();
        elevationParam->endChangeGesture();
        draggingSource = false;
    }
}

void SpatialVisualizer::setTopView()
{
    cameraYaw = 0.0f;
    cameraPitch = -juce::MathConstants<float>::halfPi;
    repaint();
}

void SpatialVisualizer::setFrontView()
{
    cameraYaw = juce::MathConstants<float>::pi; // bring the face (+z) toward the viewer
    cameraPitch = 0.0f;
    repaint();
}

//==============================================================================
// Scene building

void SpatialVisualizer::addFacet(const Vec3* verts, int numVerts, juce::Colour dark, juce::Colour lit)
{
    Vec3 centroid;
    for (int i = 0; i < numVerts; ++i) {
        centroid.x += verts[i].x;
        centroid.y += verts[i].y;
        centroid.z += verts[i].z;
    }
    centroid = centroid * (1.0f / (float)numVerts);

    const auto edge1 = verts[1] - verts[0];
    const auto edge2 = verts[2] - verts[0];
    const auto normal = edge1.cross(edge2).normalised();

    if (toCameraSpace(normal).z >= 0.0f) return; // back-facing

    Facet facet;
    facet.numPoints = numVerts;
    for (int i = 0; i < numVerts; ++i) facet.points[i] = project(verts[i]);
    facet.depth = depthOf(centroid);

    const auto lambert = juce::jmax(0.0f, normal.dot(lightDirection));
    facet.colour = dark.interpolatedWith(lit, 0.18f + 0.82f * lambert);

    facets.push_back(facet);
}

void SpatialVisualizer::rebuildHeadFacets()
{
    facets.clear();

    const auto& verts = headMesh.getVertices();
    for (const auto& tri : headMesh.getTriangles()) {
        const auto& a = verts[(size_t)tri.a];
        const auto& b = verts[(size_t)tri.b];
        const auto& c = verts[(size_t)tri.c];
        const Vec3 corners[3] = { { a.x, a.y, a.z }, { b.x, b.y, b.z }, { c.x, c.y, c.z } };
        addFacet(corners, 3, headDark, headLit);
    }

    std::sort(facets.begin(), facets.end(),
              [](const Facet& a, const Facet& b) { return a.depth > b.depth; }); // far first
}

//==============================================================================
// Drawing

void SpatialVisualizer::drawOrbitRings(juce::Graphics& g, bool nearSide) const
{
    constexpr int segments = 64;

    auto drawRing = [&](bool vertical) {
        auto pointAt = [vertical](float t) {
            const auto s = ringRadius * std::sin(t), c = ringRadius * std::cos(t);
            return vertical ? Vec3{ 0.0f, s, c } : Vec3{ s, 0.0f, c };
        };

        auto previous = pointAt(0.0f);
        auto previousScreen = project(previous);
        auto previousDepth = depthOf(previous);

        for (int i = 1; i <= segments; ++i) {
            const auto t = juce::MathConstants<float>::twoPi * (float)i / (float)segments;
            const auto current = pointAt(t);
            const auto currentScreen = project(current);
            const auto currentDepth = depthOf(current);

            if (((previousDepth + currentDepth) * 0.5f < 0.0f) == nearSide) {
                g.setColour(juce::Colours::grey.withAlpha(nearSide ? 0.40f : 0.14f));
                g.drawLine(previousScreen.x, previousScreen.y, currentScreen.x, currentScreen.y, 1.0f);
            }

            previousScreen = currentScreen;
            previousDepth = currentDepth;
        }
    };

    drawRing(false);
    drawRing(true);
}

void SpatialVisualizer::drawHead(juce::Graphics& g) const
{
    for (const auto& facet : facets) {
        juce::Path path;
        path.startNewSubPath(facet.points[0]);
        for (int i = 1; i < facet.numPoints; ++i) path.lineTo(facet.points[i]);
        path.closeSubPath();

        g.setColour(facet.colour);
        g.fillPath(path);
    }
}

void SpatialVisualizer::drawSourceMarker(juce::Graphics& g) const
{
    const auto centreScreen = project({ 0.0f, 0.0f, 0.0f });

    g.setColour(juce::Colours::grey.withAlpha(0.35f));
    g.drawLine(centreScreen.x, centreScreen.y, sourceScreenPos.x, sourceScreenPos.y, 1.0f);

    // Marker lightness tracks elevation: black (below) -> red (level) -> white (above)
    const auto elevation = (float)elevationParam->get() / 180.0f;
    const auto colour = elevation < 0.5f
        ? juce::Colours::black.interpolatedWith(SpatialLookAndFeel::accent, elevation / 0.5f)
        : SpatialLookAndFeel::accent.interpolatedWith(SpatialLookAndFeel::light, (elevation - 0.5f) / 0.5f);

    const auto diameter = sourceMarkerRadius * 2.0f;
    g.setColour(colour);
    g.fillEllipse(sourceScreenPos.x - sourceMarkerRadius, sourceScreenPos.y - sourceMarkerRadius, diameter, diameter);
    g.setColour(SpatialLookAndFeel::light.withAlpha(0.6f));
    g.drawEllipse(sourceScreenPos.x - sourceMarkerRadius, sourceScreenPos.y - sourceMarkerRadius, diameter, diameter, 1.0f);
}

void SpatialVisualizer::drawReadout(juce::Graphics& g) const
{
    const auto text = juce::String(azimuthParam->get()) + " deg az / "
                    + juce::String(elevationParam->get() - (int)elevationOffset) + " deg el / "
                    + juce::String(gainParam->get(), 1) + " dB";

    g.setColour(SpatialLookAndFeel::light);
    g.setFont(13.0f);
    g.drawFittedText(text, getLocalBounds().removeFromBottom(18), juce::Justification::centred, 1);
}

void SpatialVisualizer::paint(juce::Graphics& g)
{
    updateViewport();
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    rebuildHeadFacets();

    const auto source = sourcePosition();
    sourceScreenPos = project(source);
    sourceMarkerRadius = juce::jmap(juce::jlimit(minSourceDistance, maxSourceDistance, sourceDistance()),
                                     minSourceDistance, maxSourceDistance, 8.0f, 5.0f);
    sourceHitRadius = juce::jmax(sourceMarkerRadius + 4.0f, 12.0f);

    const bool sourceBehindHead = depthOf(source) > 0.0f;

    drawOrbitRings(g, false);
    if (sourceBehindHead) drawSourceMarker(g);
    drawHead(g);
    if (!sourceBehindHead) drawSourceMarker(g);
    drawOrbitRings(g, true);

    drawReadout(g);
}
