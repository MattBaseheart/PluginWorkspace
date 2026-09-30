/*
  ==============================================================================

    HrtfConvolver.h

    Direct-form FIR binaural renderer. The whole HRIR set is decoded once at
    construction, so moving the source only switches which taps are read - there
    is no allocation, file parsing or background loading on the audio thread.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <vector>

class HrtfConvolver
{
public:
    HrtfConvolver();

    void prepare(double sampleRate);
    void reset();

    // Selects the nearest measured HRIR. azimuthDeg is 0-359, elevationDeg is -90..90.
    void setPosition(int azimuthDeg, int elevationDeg);

    // Renders a mono source into a stereo pair. outLeft/outRight may alias the caller's buffers.
    void process(const float* mono, float* outLeft, float* outRight, int numSamples);

    int getIrLength() const noexcept { return irLength; }
    bool isReady() const noexcept { return irLength > 0; }

private:
    static constexpr int numAzimuths = 360;
    static constexpr int numElevations = 17;
    static const int elevationValues[numElevations];

    int indexFor(int azimuthDeg, int elevationDeg) const noexcept;
    const float* tapsFor(int positionIndex, int ear) const noexcept;

    // Flat [position][ear][tap] table; ~12 MB of floats for the full 360x17 set
    std::vector<float> tapData;
    std::vector<float> history;

    int irLength = 0;
    int writePos = 0;

    int currentIndex = 0;
    int previousIndex = 0;
    int fadeRemaining = 0;
    int fadeLength = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HrtfConvolver)
};
