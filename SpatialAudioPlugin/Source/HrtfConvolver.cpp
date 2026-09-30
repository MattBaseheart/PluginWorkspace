/*
  ==============================================================================

    HrtfConvolver.cpp

  ==============================================================================
*/

#include "HrtfConvolver.h"
#include "BinaryData.h"
#include <cstdint>
#include <cstring>

const int HrtfConvolver::elevationValues[HrtfConvolver::numElevations] =
    { -81, -75, -60, -54, -45, -30, -25, -15, 0, 15, 25, 30, 45, 54, 60, 75, 90 };

namespace {

struct WavView
{
    const uint8_t* samples = nullptr;
    int numFrames = 0;
    int numChannels = 0;
    int bitsPerSample = 0;
};

uint16_t readLE16(const uint8_t* p) { return (uint16_t)(p[0] | (p[1] << 8)); }
uint32_t readLE32(const uint8_t* p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

// Minimal RIFF walk. Avoids building 6000+ AudioFormatReaders just to read 256 frames each.
bool parseWav(const void* raw, int size, WavView& out)
{
    const auto* p = static_cast<const uint8_t*>(raw);
    if (raw == nullptr || size < 44) return false;
    if (std::memcmp(p, "RIFF", 4) != 0 || std::memcmp(p + 8, "WAVE", 4) != 0) return false;

    int channels = 0, bits = 0;
    int pos = 12;

    while (pos + 8 <= size) {
        const uint8_t* id = p + pos;
        const auto chunkSize = (int)readLE32(p + pos + 4);
        const int body = pos + 8;
        if (chunkSize < 0 || body > size) return false;

        if (std::memcmp(id, "fmt ", 4) == 0 && body + 16 <= size) {
            channels = readLE16(p + body + 2);
            bits = readLE16(p + body + 14);
        } else if (std::memcmp(id, "data", 4) == 0) {
            if (channels <= 0 || bits <= 0) return false;
            const int bytesPerSample = bits / 8;
            const int available = juce::jmin(chunkSize, size - body);
            out.samples = p + body;
            out.numChannels = channels;
            out.bitsPerSample = bits;
            out.numFrames = available / (bytesPerSample * channels);
            return out.numFrames > 0;
        }

        pos = body + chunkSize + (chunkSize & 1);
    }
    return false;
}

float sampleAt(const WavView& w, int frame, int channel)
{
    const int bytesPerSample = w.bitsPerSample / 8;
    const uint8_t* s = w.samples + ((size_t)frame * (size_t)w.numChannels + (size_t)channel) * (size_t)bytesPerSample;

    switch (w.bitsPerSample) {
        case 24: {
            // Build into the top 24 bits so the arithmetic shift sign-extends
            const int32_t v = (int32_t)(((uint32_t)s[2] << 24) | ((uint32_t)s[1] << 16) | ((uint32_t)s[0] << 8));
            return (float)(v >> 8) / 8388608.0f;
        }
        case 16: {
            const auto v = (int16_t)(s[0] | (s[1] << 8));
            return (float)v / 32768.0f;
        }
        case 32: {
            float f = 0.0f;
            std::memcpy(&f, s, sizeof(float));
            return f;
        }
        default:
            return 0.0f;
    }
}

juce::String resourceNameFor(int azimuth, int elevation)
{
    return elevation >= 0
        ? "azi_" + juce::String(azimuth) + "_0_ele_" + juce::String(elevation) + "_0_wav"
        : "azi_" + juce::String(azimuth) + "_0_ele_neg" + juce::String(std::abs(elevation)) + "_0_wav";
}

} // namespace

HrtfConvolver::HrtfConvolver()
{
    for (int e = 0; e < numElevations; ++e) {
        for (int a = 0; a < numAzimuths; ++a) {
            int size = 0;
            const void* data = HRIR_48k_24bit::getNamedResource(resourceNameFor(a, elevationValues[e]).toRawUTF8(), size);

            WavView wav;
            if (!parseWav(data, size, wav)) {
                jassertfalse; // every azimuth/elevation pair should exist in the embedded dataset
                continue;
            }

            if (irLength == 0) {
                irLength = wav.numFrames;
                tapData.assign((size_t)numAzimuths * numElevations * 2 * (size_t)irLength, 0.0f);
            }

            const int frames = juce::jmin(wav.numFrames, irLength);
            const int positionIndex = e * numAzimuths + a;
            auto* left = tapData.data() + ((size_t)positionIndex * 2) * (size_t)irLength;
            auto* right = left + irLength;
            const int rightChannel = wav.numChannels > 1 ? 1 : 0;

            for (int k = 0; k < frames; ++k) {
                left[k] = sampleAt(wav, k, 0);
                right[k] = sampleAt(wav, k, rightChannel);
            }
        }
    }
}

void HrtfConvolver::prepare(double sampleRate)
{
    if (irLength <= 0) return;

    history.assign((size_t)irLength, 0.0f);
    // Short crossfade so position changes don't click
    fadeLength = juce::jmax(1, (int)std::round(sampleRate * 0.01));
    reset();
}

void HrtfConvolver::reset()
{
    std::fill(history.begin(), history.end(), 0.0f);
    writePos = 0;
    fadeRemaining = 0;
    previousIndex = currentIndex;
}

const float* HrtfConvolver::tapsFor(int positionIndex, int ear) const noexcept
{
    return tapData.data() + ((size_t)positionIndex * 2 + (size_t)ear) * (size_t)irLength;
}

int HrtfConvolver::indexFor(int azimuthDeg, int elevationDeg) const noexcept
{
    // SADIE measures azimuth anti-clockwise from straight ahead; this plugin treats it as
    // clockwise, so mirror through the front-back axis to convert between the two conventions
    const int azimuth = ((360 - azimuthDeg) % 360 + 360) % 360;

    int bestElevation = 0;
    int smallestDiff = 1000;
    for (int i = 0; i < numElevations; ++i) {
        const int diff = std::abs(elevationDeg - elevationValues[i]);
        if (diff < smallestDiff) {
            smallestDiff = diff;
            bestElevation = i;
        }
    }

    return bestElevation * numAzimuths + azimuth;
}

void HrtfConvolver::setPosition(int azimuthDeg, int elevationDeg)
{
    const int index = indexFor(azimuthDeg, elevationDeg);
    if (index == currentIndex) return;

    previousIndex = currentIndex;
    currentIndex = index;
    fadeRemaining = fadeLength;
}

void HrtfConvolver::process(const float* mono, float* outLeft, float* outRight, int numSamples)
{
    if (irLength <= 0 || history.size() != (size_t)irLength) {
        juce::FloatVectorOperations::clear(outLeft, numSamples);
        juce::FloatVectorOperations::clear(outRight, numSamples);
        return;
    }

    const float* currentLeft = tapsFor(currentIndex, 0);
    const float* currentRight = tapsFor(currentIndex, 1);
    const float* previousLeft = tapsFor(previousIndex, 0);
    const float* previousRight = tapsFor(previousIndex, 1);

    for (int n = 0; n < numSamples; ++n) {
        history[(size_t)writePos] = mono[n];

        float currL = 0.0f, currR = 0.0f;
        int index = writePos;

        if (fadeRemaining > 0) {
            float prevL = 0.0f, prevR = 0.0f;
            for (int k = 0; k < irLength; ++k) {
                const float s = history[(size_t)index];
                currL += currentLeft[k] * s;
                currR += currentRight[k] * s;
                prevL += previousLeft[k] * s;
                prevR += previousRight[k] * s;
                if (--index < 0) index = irLength - 1;
            }

            const float t = 1.0f - (float)fadeRemaining / (float)fadeLength;
            outLeft[n] = prevL + (currL - prevL) * t;
            outRight[n] = prevR + (currR - prevR) * t;
            --fadeRemaining;
        } else {
            for (int k = 0; k < irLength; ++k) {
                const float s = history[(size_t)index];
                currL += currentLeft[k] * s;
                currR += currentRight[k] * s;
                if (--index < 0) index = irLength - 1;
            }

            outLeft[n] = currL;
            outRight[n] = currR;
        }

        if (++writePos >= irLength) writePos = 0;
    }
}
