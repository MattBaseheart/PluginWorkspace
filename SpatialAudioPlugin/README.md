# Spatial Audio Plugin

A JUCE-based binaural spatializer. It renders the input as a single point source and positions it in 3D using measured head-related impulse responses (HRIRs), with azimuth, elevation, and output gain exposed as host parameters.

## Building

This project is built with the Projucer, not CMake.

1. Open [SpatialAudioPlugin.jucer](SpatialAudioPlugin.jucer) in the [Projucer](https://juce.com/discover/projucer) and resave it to regenerate the exporter for your platform, or open the checked-in solution directly at [Builds/VisualStudio2022/SpatialAudioPlugin.sln](Builds/VisualStudio2022/SpatialAudioPlugin.sln).
2. Build the Standalone and/or VST3 targets from Visual Studio 2022.

The project expects a local JUCE checkout; if the module paths in the `.jucer` file or the generated Visual Studio projects don't match your JUCE install location, resave the project from the Projucer to regenerate them.

## HRIR dataset

[HRIR_48k_24bit/](HRIR_48k_24bit) contains 9,201 WAV files (48 kHz, 24-bit, stereo) covering 360 azimuths and up to 17 elevations per azimuth, used to render the binaural output. The files carry no embedded metadata (checked: only `fmt `/`data` RIFF chunks, no `LIST`/`INFO` text), so their origin isn't recorded anywhere in this repository.

**TODO before publishing:** document where this dataset came from (e.g., which HRTF measurement database or recording session), its license, and any required attribution. Do not distribute built binaries or the raw WAV files until this is resolved.

## License

See [LICENSE.md](LICENSE.md) for the plugin source license. It does not cover the HRIR dataset (see above).
