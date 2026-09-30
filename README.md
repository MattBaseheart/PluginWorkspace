# Audio Plugin Workshop

A collection of small JUCE audio-plugin projects exploring DSP, plugin interfaces, and build workflows. The projects are maintained independently, so each folder has its own project files and build setup.

## Plugins

| Project | Description | Project entry point |
| --- | --- | --- |
| [EQPlugin](EQPlugin/) | A three-control equalizer with output gain, low-cut, and high-cut controls. Its processor uses JUCE state-variable filters. | [EQ.jucer](EQPlugin/EQ/EQ.jucer) |
| [SimpleDelayPlugin](SimpleDelayPlugin/) | A stereo delay with gain, delay-time, and wet/dry mix controls. | [SimpleDelayPlugin.jucer](SimpleDelayPlugin/SimpleDelayPlugin.jucer) |
| [SpatialAudioPlugin](SpatialAudioPlugin/) | A stereo binaural spatializer with gain, azimuth, and elevation controls. It loads embedded head-related impulse responses (HRIRs) and processes audio with convolution. | [SpatialAudioPlugin.jucer](SpatialAudioPlugin/SpatialAudioPlugin.jucer) |

## Building

There is no workspace-level build. Build each project from its own project files.

### Projucer projects

`EQPlugin`, `SimpleDelayPlugin`, and the implemented `SpatialAudioPlugin` use JUCE Projucer projects and include Visual Studio 2022 build files. On Windows:

1. Open the project's `.jucer` file in Projucer.
2. Configure its JUCE module paths for your local JUCE installation, then save or regenerate the Visual Studio 2022 project if needed.
3. Open the generated solution in Visual Studio and build the desired Standalone or VST3 target.

The checked-in JUCE module paths may point to a machine-specific location, so verify them before building on another computer. Available formats depend on the project configuration and installed JUCE/toolchain support.

## Repository Layout

```text
EQPlugin/           Projucer equalizer project
SimpleDelayPlugin/  Projucer stereo delay project
SpatialAudioPlugin/ Projucer spatializer project
```

