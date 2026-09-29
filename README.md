# Audio Plugin Workshop

A collection of small JUCE audio-plugin projects exploring DSP, plugin interfaces, and build workflows. The projects are maintained independently, so each folder has its own project files and build setup.

## Plugins

| Project | Description | Project entry point |
| --- | --- | --- |
| [EQPlugin](EQPlugin/) | A three-control equalizer with output gain, low-cut, and high-cut controls. Its processor uses JUCE state-variable filters. | [EQ.jucer](EQPlugin/EQ/EQ.jucer) |
| [SimpleDelayPlugin](SimpleDelayPlugin/) | A stereo delay with gain, delay-time, and wet/dry mix controls. | [SimpleDelayPlugin.jucer](SimpleDelayPlugin/SimpleDelayPlugin.jucer) |
| [SpatialAudioPlugin](SpatialAudioPlugin/) | A stereo binaural spatializer with gain, azimuth, and elevation controls. It loads embedded head-related impulse responses (HRIRs) and processes audio with convolution. | [SpatialAudioPlugin.jucer](SpatialAudioPlugin/SpatialAudioPlugin.jucer) |

## Starter Projects

- [PluginTemplate](PluginTemplate/) is a CMake-based JUCE plugin starter, with CPM-managed JUCE and GoogleTest dependencies and a test target. It is a template rather than one of the three audio effects above.
- [SpatialAudioPlugin](SpatialAudioPlugin/) also contains a CMake starter structure. The implemented HRIR spatializer is the Projucer project under `SpatialAudioPlugin/Source`; the CMake `plugin/` directory is a separate, mostly template-style plugin target.

## Building

There is no workspace-level build. Build each project from its own project files.

### Projucer projects

`EQPlugin`, `SimpleDelayPlugin`, and the implemented `SpatialAudioPlugin` use JUCE Projucer projects and include Visual Studio 2022 build files. On Windows:

1. Open the project's `.jucer` file in Projucer.
2. Configure its JUCE module paths for your local JUCE installation, then save or regenerate the Visual Studio 2022 project if needed.
3. Open the generated solution in Visual Studio and build the desired Standalone or VST3 target.

The checked-in JUCE module paths may point to a machine-specific location, so verify them before building on another computer. Available formats depend on the project configuration and installed JUCE/toolchain support.

### CMake template projects

For [PluginTemplate](PluginTemplate/) or the separate CMake scaffold in [SpatialAudioPlugin](SpatialAudioPlugin/), use CMake 3.22 or newer and a C++ toolchain. From the relevant project directory:

```sh
cmake --preset default
cmake --build build
ctest --preset default
```

The default preset uses Ninja. CMake downloads JUCE and GoogleTest on the first configure; a working Git installation and network access are needed. The CMake plugin target currently declares Standalone and VST3 formats. Building the Spatial Audio CMake scaffold does not build the implemented HRIR processor.

## Repository Layout

```text
EQPlugin/           Projucer equalizer project
SimpleDelayPlugin/  Projucer stereo delay project
SpatialAudioPlugin/ Projucer spatializer, HRIR data, and CMake scaffold
PluginTemplate/     CMake/JUCE plugin starter and tests
```

## Project Status

This is a development portfolio of learning projects, not a unified product release. Build configuration, interface polish, and testing vary by project. Before presenting a plugin as a finished portfolio piece, validate it in a DAW or plugin host and add current screenshots, a short audio demo, and project-specific build notes.
