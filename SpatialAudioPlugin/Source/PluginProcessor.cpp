/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "HRIR_48K_24bit.h"

//==============================================================================
// Here, the : followed by an AudioProcessor constructor call creates that class first. params(apvts) is also in the initializer list
SpatialAudioPluginAudioProcessor::SpatialAudioPluginAudioProcessor() : AudioProcessor(BusesProperties().withInput("Input", juce::AudioChannelSet::stereo(), true).withOutput("Output", juce::AudioChannelSet::stereo(), true)), params(apvts)
{
  initializeIRMap();
  loadIR(0, 90);
}

SpatialAudioPluginAudioProcessor::~SpatialAudioPluginAudioProcessor()
{
}

//==============================================================================

void SpatialAudioPluginAudioProcessor::initializeIRMap() {
  irMap[0][0] = {HRIR_48K_24bit::azi_0_0_ele_0_0_wavSize,
                 HRIR_48K_24bit::azi_0_0_ele_0_0_wav};
  irMap[0][15] = {HRIR_48K_24bit::azi_0_0_ele_15_0_wavSize,
                  HRIR_48K_24bit::azi_0_0_ele_15_0_wav};
  irMap[0][25] = {HRIR_48K_24bit::azi_0_0_ele_25_0_wavSize,
                  HRIR_48K_24bit::azi_0_0_ele_25_0_wav};
  irMap[0][30] = {HRIR_48K_24bit::azi_0_0_ele_30_0_wavSize,
                  HRIR_48K_24bit::azi_0_0_ele_30_0_wav};
  irMap[0][45] = {HRIR_48K_24bit::azi_0_0_ele_45_0_wavSize,
                  HRIR_48K_24bit::azi_0_0_ele_45_0_wav};
  irMap[0][54] = {HRIR_48K_24bit::azi_0_0_ele_54_0_wavSize,
                  HRIR_48K_24bit::azi_0_0_ele_54_0_wav};
  irMap[0][60] = {HRIR_48K_24bit::azi_0_0_ele_60_0_wavSize,
                  HRIR_48K_24bit::azi_0_0_ele_60_0_wav};
  irMap[0][75] = {HRIR_48K_24bit::azi_0_0_ele_75_0_wavSize,
                  HRIR_48K_24bit::azi_0_0_ele_75_0_wav};
  irMap[0][90] = {HRIR_48K_24bit::azi_0_0_ele_90_0_wavSize,
                  HRIR_48K_24bit::azi_0_0_ele_90_0_wav};
  irMap[0][-15] = {HRIR_48K_24bit::azi_0_0_ele_neg15_0_wavSize,
                   HRIR_48K_24bit::azi_0_0_ele_neg15_0_wav};
  irMap[0][-25] = {HRIR_48K_24bit::azi_0_0_ele_neg25_0_wavSize,
                   HRIR_48K_24bit::azi_0_0_ele_neg25_0_wav};
  irMap[0][-30] = {HRIR_48K_24bit::azi_0_0_ele_neg30_0_wavSize,
                   HRIR_48K_24bit::azi_0_0_ele_neg30_0_wav};
  irMap[0][-45] = {HRIR_48K_24bit::azi_0_0_ele_neg45_0_wavSize,
                   HRIR_48K_24bit::azi_0_0_ele_neg45_0_wav};
  irMap[0][-54] = {HRIR_48K_24bit::azi_0_0_ele_neg54_0_wavSize,
                   HRIR_48K_24bit::azi_0_0_ele_neg54_0_wav};
  irMap[0][-60] = {HRIR_48K_24bit::azi_0_0_ele_neg60_0_wavSize,
                   HRIR_48K_24bit::azi_0_0_ele_neg60_0_wav};
  irMap[0][-75] = {HRIR_48K_24bit::azi_0_0_ele_neg75_0_wavSize,
                   HRIR_48K_24bit::azi_0_0_ele_neg75_0_wav};
  irMap[0][-81] = {HRIR_48K_24bit::azi_0_0_ele_neg81_0_wavSize,
                   HRIR_48K_24bit::azi_0_0_ele_neg81_0_wav};
  irMap[0][-90] = {HRIR_48K_24bit::azi_0_0_ele_neg90_0_wavSize,
                   HRIR_48K_24bit::azi_0_0_ele_neg90_0_wav};
  irMap[1][0] = {HRIR_48K_24bit::azi_1_0_ele_0_0_wavSize,
                 HRIR_48K_24bit::azi_1_0_ele_0_0_wav};
  irMap[1][15] = {HRIR_48K_24bit::azi_1_0_ele_15_0_wavSize,
                  HRIR_48K_24bit::azi_1_0_ele_15_0_wav};
  irMap[1][25] = {HRIR_48K_24bit::azi_1_0_ele_25_0_wavSize,
                  HRIR_48K_24bit::azi_1_0_ele_25_0_wav};
  irMap[1][30] = {HRIR_48K_24bit::azi_1_0_ele_30_0_wavSize,
                  HRIR_48K_24bit::azi_1_0_ele_30_0_wav};
  irMap[1][45] = {HRIR_48K_24bit::azi_1_0_ele_45_0_wavSize,
                  HRIR_48K_24bit::azi_1_0_ele_45_0_wav};
  irMap[1][54] = {HRIR_48K_24bit::azi_1_0_ele_54_0_wavSize,
                  HRIR_48K_24bit::azi_1_0_ele_54_0_wav};
  irMap[1][60] = {HRIR_48K_24bit::azi_1_0_ele_60_0_wavSize,
                  HRIR_48K_24bit::azi_1_0_ele_60_0_wav};
  irMap[1][75] = {HRIR_48K_24bit::azi_1_0_ele_75_0_wavSize,
                  HRIR_48K_24bit::azi_1_0_ele_75_0_wav};
  irMap[1][90] = {HRIR_48K_24bit::azi_1_0_ele_90_0_wavSize,
                  HRIR_48K_24bit::azi_1_0_ele_90_0_wav};
  irMap[1][-15] = {HRIR_48K_24bit::azi_1_0_ele_neg15_0_wavSize,
                   HRIR_48K_24bit::azi_1_0_ele_neg15_0_wav};
  irMap[1][-25] = {HRIR_48K_24bit::azi_1_0_ele_neg25_0_wavSize,
                   HRIR_48K_24bit::azi_1_0_ele_neg25_0_wav};
  irMap[1][-30] = {HRIR_48K_24bit::azi_1_0_ele_neg30_0_wavSize,
                   HRIR_48K_24bit::azi_1_0_ele_neg30_0_wav};
  irMap[1][-45] = {HRIR_48K_24bit::azi_1_0_ele_neg45_0_wavSize,
                   HRIR_48K_24bit::azi_1_0_ele_neg45_0_wav};
  irMap[1][-54] = {HRIR_48K_24bit::azi_1_0_ele_neg54_0_wavSize,
                   HRIR_48K_24bit::azi_1_0_ele_neg54_0_wav};
  irMap[1][-60] = {HRIR_48K_24bit::azi_1_0_ele_neg60_0_wavSize,
                   HRIR_48K_24bit::azi_1_0_ele_neg60_0_wav};
  irMap[1][-75] = {HRIR_48K_24bit::azi_1_0_ele_neg75_0_wavSize,
                   HRIR_48K_24bit::azi_1_0_ele_neg75_0_wav};
  irMap[1][-81] = {HRIR_48K_24bit::azi_1_0_ele_neg81_0_wavSize,
                   HRIR_48K_24bit::azi_1_0_ele_neg81_0_wav};
  irMap[2][0] = {HRIR_48K_24bit::azi_2_0_ele_0_0_wavSize,
                 HRIR_48K_24bit::azi_2_0_ele_0_0_wav};
  irMap[2][15] = {HRIR_48K_24bit::azi_2_0_ele_15_0_wavSize,
                  HRIR_48K_24bit::azi_2_0_ele_15_0_wav};
  irMap[2][25] = {HRIR_48K_24bit::azi_2_0_ele_25_0_wavSize,
                  HRIR_48K_24bit::azi_2_0_ele_25_0_wav};
  irMap[2][30] = {HRIR_48K_24bit::azi_2_0_ele_30_0_wavSize,
                  HRIR_48K_24bit::azi_2_0_ele_30_0_wav};
  irMap[2][45] = {HRIR_48K_24bit::azi_2_0_ele_45_0_wavSize,
                  HRIR_48K_24bit::azi_2_0_ele_45_0_wav};
  irMap[2][54] = {HRIR_48K_24bit::azi_2_0_ele_54_0_wavSize,
                  HRIR_48K_24bit::azi_2_0_ele_54_0_wav};
  irMap[2][60] = {HRIR_48K_24bit::azi_2_0_ele_60_0_wavSize,
                  HRIR_48K_24bit::azi_2_0_ele_60_0_wav};
  irMap[2][75] = {HRIR_48K_24bit::azi_2_0_ele_75_0_wavSize,
                  HRIR_48K_24bit::azi_2_0_ele_75_0_wav};
  irMap[2][90] = {HRIR_48K_24bit::azi_2_0_ele_90_0_wavSize,
                  HRIR_48K_24bit::azi_2_0_ele_90_0_wav};
  irMap[2][-15] = {HRIR_48K_24bit::azi_2_0_ele_neg15_0_wavSize,
                   HRIR_48K_24bit::azi_2_0_ele_neg15_0_wav};
  irMap[2][-25] = {HRIR_48K_24bit::azi_2_0_ele_neg25_0_wavSize,
                   HRIR_48K_24bit::azi_2_0_ele_neg25_0_wav};
  irMap[2][-30] = {HRIR_48K_24bit::azi_2_0_ele_neg30_0_wavSize,
                   HRIR_48K_24bit::azi_2_0_ele_neg30_0_wav};
  irMap[2][-45] = {HRIR_48K_24bit::azi_2_0_ele_neg45_0_wavSize,
                   HRIR_48K_24bit::azi_2_0_ele_neg45_0_wav};
  irMap[2][-54] = {HRIR_48K_24bit::azi_2_0_ele_neg54_0_wavSize,
                   HRIR_48K_24bit::azi_2_0_ele_neg54_0_wav};
  irMap[2][-60] = {HRIR_48K_24bit::azi_2_0_ele_neg60_0_wavSize,
                   HRIR_48K_24bit::azi_2_0_ele_neg60_0_wav};
  irMap[2][-75] = {HRIR_48K_24bit::azi_2_0_ele_neg75_0_wavSize,
                   HRIR_48K_24bit::azi_2_0_ele_neg75_0_wav};
  irMap[2][-81] = {HRIR_48K_24bit::azi_2_0_ele_neg81_0_wavSize,
                   HRIR_48K_24bit::azi_2_0_ele_neg81_0_wav};
  irMap[3][0] = {HRIR_48K_24bit::azi_3_0_ele_0_0_wavSize,
                 HRIR_48K_24bit::azi_3_0_ele_0_0_wav};
  irMap[3][15] = {HRIR_48K_24bit::azi_3_0_ele_15_0_wavSize,
                  HRIR_48K_24bit::azi_3_0_ele_15_0_wav};
  irMap[3][25] = {HRIR_48K_24bit::azi_3_0_ele_25_0_wavSize,
                  HRIR_48K_24bit::azi_3_0_ele_25_0_wav};
  irMap[3][30] = {HRIR_48K_24bit::azi_3_0_ele_30_0_wavSize,
                  HRIR_48K_24bit::azi_3_0_ele_30_0_wav};
  irMap[3][45] = {HRIR_48K_24bit::azi_3_0_ele_45_0_wavSize,
                  HRIR_48K_24bit::azi_3_0_ele_45_0_wav};
  irMap[3][54] = {HRIR_48K_24bit::azi_3_0_ele_54_0_wavSize,
                  HRIR_48K_24bit::azi_3_0_ele_54_0_wav};
  irMap[3][60] = {HRIR_48K_24bit::azi_3_0_ele_60_0_wavSize,
                  HRIR_48K_24bit::azi_3_0_ele_60_0_wav};
  irMap[3][75] = {HRIR_48K_24bit::azi_3_0_ele_75_0_wavSize,
                  HRIR_48K_24bit::azi_3_0_ele_75_0_wav};
  irMap[3][90] = {HRIR_48K_24bit::azi_3_0_ele_90_0_wavSize,
                  HRIR_48K_24bit::azi_3_0_ele_90_0_wav};
  irMap[3][-15] = {HRIR_48K_24bit::azi_3_0_ele_neg15_0_wavSize,
                   HRIR_48K_24bit::azi_3_0_ele_neg15_0_wav};
  irMap[3][-25] = {HRIR_48K_24bit::azi_3_0_ele_neg25_0_wavSize,
                   HRIR_48K_24bit::azi_3_0_ele_neg25_0_wav};
  irMap[3][-30] = {HRIR_48K_24bit::azi_3_0_ele_neg30_0_wavSize,
                   HRIR_48K_24bit::azi_3_0_ele_neg30_0_wav};
  irMap[3][-45] = {HRIR_48K_24bit::azi_3_0_ele_neg45_0_wavSize,
                   HRIR_48K_24bit::azi_3_0_ele_neg45_0_wav};
  irMap[3][-54] = {HRIR_48K_24bit::azi_3_0_ele_neg54_0_wavSize,
                   HRIR_48K_24bit::azi_3_0_ele_neg54_0_wav};
  irMap[3][-60] = {HRIR_48K_24bit::azi_3_0_ele_neg60_0_wavSize,
                   HRIR_48K_24bit::azi_3_0_ele_neg60_0_wav};
  irMap[3][-75] = {HRIR_48K_24bit::azi_3_0_ele_neg75_0_wavSize,
                   HRIR_48K_24bit::azi_3_0_ele_neg75_0_wav};
  irMap[3][-81] = {HRIR_48K_24bit::azi_3_0_ele_neg81_0_wavSize,
                   HRIR_48K_24bit::azi_3_0_ele_neg81_0_wav};
  irMap[4][0] = {HRIR_48K_24bit::azi_4_0_ele_0_0_wavSize,
                 HRIR_48K_24bit::azi_4_0_ele_0_0_wav};
  irMap[4][15] = {HRIR_48K_24bit::azi_4_0_ele_15_0_wavSize,
                  HRIR_48K_24bit::azi_4_0_ele_15_0_wav};
  irMap[4][25] = {HRIR_48K_24bit::azi_4_0_ele_25_0_wavSize,
                  HRIR_48K_24bit::azi_4_0_ele_25_0_wav};
  irMap[4][30] = {HRIR_48K_24bit::azi_4_0_ele_30_0_wavSize,
                  HRIR_48K_24bit::azi_4_0_ele_30_0_wav};
  irMap[4][45] = {HRIR_48K_24bit::azi_4_0_ele_45_0_wavSize,
                  HRIR_48K_24bit::azi_4_0_ele_45_0_wav};
  irMap[4][54] = {HRIR_48K_24bit::azi_4_0_ele_54_0_wavSize,
                  HRIR_48K_24bit::azi_4_0_ele_54_0_wav};
  irMap[4][60] = {HRIR_48K_24bit::azi_4_0_ele_60_0_wavSize,
                  HRIR_48K_24bit::azi_4_0_ele_60_0_wav};
  irMap[4][75] = {HRIR_48K_24bit::azi_4_0_ele_75_0_wavSize,
                  HRIR_48K_24bit::azi_4_0_ele_75_0_wav};
  irMap[4][90] = {HRIR_48K_24bit::azi_4_0_ele_90_0_wavSize,
                  HRIR_48K_24bit::azi_4_0_ele_90_0_wav};
  irMap[4][-15] = {HRIR_48K_24bit::azi_4_0_ele_neg15_0_wavSize,
                   HRIR_48K_24bit::azi_4_0_ele_neg15_0_wav};
  irMap[4][-25] = {HRIR_48K_24bit::azi_4_0_ele_neg25_0_wavSize,
                   HRIR_48K_24bit::azi_4_0_ele_neg25_0_wav};
  irMap[4][-30] = {HRIR_48K_24bit::azi_4_0_ele_neg30_0_wavSize,
                   HRIR_48K_24bit::azi_4_0_ele_neg30_0_wav};
  irMap[4][-45] = {HRIR_48K_24bit::azi_4_0_ele_neg45_0_wavSize,
                   HRIR_48K_24bit::azi_4_0_ele_neg45_0_wav};
  irMap[4][-54] = {HRIR_48K_24bit::azi_4_0_ele_neg54_0_wavSize,
                   HRIR_48K_24bit::azi_4_0_ele_neg54_0_wav};
  irMap[4][-60] = {HRIR_48K_24bit::azi_4_0_ele_neg60_0_wavSize,
                   HRIR_48K_24bit::azi_4_0_ele_neg60_0_wav};
  irMap[4][-75] = {HRIR_48K_24bit::azi_4_0_ele_neg75_0_wavSize,
                   HRIR_48K_24bit::azi_4_0_ele_neg75_0_wav};
  irMap[4][-81] = {HRIR_48K_24bit::azi_4_0_ele_neg81_0_wavSize,
                   HRIR_48K_24bit::azi_4_0_ele_neg81_0_wav};
  irMap[5][0] = {HRIR_48K_24bit::azi_5_0_ele_0_0_wavSize,
                 HRIR_48K_24bit::azi_5_0_ele_0_0_wav};
  irMap[5][15] = {HRIR_48K_24bit::azi_5_0_ele_15_0_wavSize,
                  HRIR_48K_24bit::azi_5_0_ele_15_0_wav};
  irMap[5][25] = {HRIR_48K_24bit::azi_5_0_ele_25_0_wavSize,
                  HRIR_48K_24bit::azi_5_0_ele_25_0_wav};
  irMap[5][30] = {HRIR_48K_24bit::azi_5_0_ele_30_0_wavSize,
                  HRIR_48K_24bit::azi_5_0_ele_30_0_wav};
  irMap[5][45] = {HRIR_48K_24bit::azi_5_0_ele_45_0_wavSize,
                  HRIR_48K_24bit::azi_5_0_ele_45_0_wav};
  irMap[5][54] = {HRIR_48K_24bit::azi_5_0_ele_54_0_wavSize,
                  HRIR_48K_24bit::azi_5_0_ele_54_0_wav};
  irMap[5][60] = {HRIR_48K_24bit::azi_5_0_ele_60_0_wavSize,
                  HRIR_48K_24bit::azi_5_0_ele_60_0_wav};
  irMap[5][75] = {HRIR_48K_24bit::azi_5_0_ele_75_0_wavSize,
                  HRIR_48K_24bit::azi_5_0_ele_75_0_wav};
  irMap[5][90] = {HRIR_48K_24bit::azi_5_0_ele_90_0_wavSize,
                  HRIR_48K_24bit::azi_5_0_ele_90_0_wav};
  irMap[5][-15] = {HRIR_48K_24bit::azi_5_0_ele_neg15_0_wavSize,
                   HRIR_48K_24bit::azi_5_0_ele_neg15_0_wav};
  irMap[5][-25] = {HRIR_48K_24bit::azi_5_0_ele_neg25_0_wavSize,
                   HRIR_48K_24bit::azi_5_0_ele_neg25_0_wav};
  irMap[5][-30] = {HRIR_48K_24bit::azi_5_0_ele_neg30_0_wavSize,
                   HRIR_48K_24bit::azi_5_0_ele_neg30_0_wav};
  irMap[5][-45] = {HRIR_48K_24bit::azi_5_0_ele_neg45_0_wavSize,
                   HRIR_48K_24bit::azi_5_0_ele_neg45_0_wav};
  irMap[5][-54] = {HRIR_48K_24bit::azi_5_0_ele_neg54_0_wavSize,
                   HRIR_48K_24bit::azi_5_0_ele_neg54_0_wav};
  irMap[5][-60] = {HRIR_48K_24bit::azi_5_0_ele_neg60_0_wavSize,
                   HRIR_48K_24bit::azi_5_0_ele_neg60_0_wav};
  irMap[5][-75] = {HRIR_48K_24bit::azi_5_0_ele_neg75_0_wavSize,
                   HRIR_48K_24bit::azi_5_0_ele_neg75_0_wav};
  irMap[5][-81] = {HRIR_48K_24bit::azi_5_0_ele_neg81_0_wavSize,
                   HRIR_48K_24bit::azi_5_0_ele_neg81_0_wav};
  irMap[6][0] = {HRIR_48K_24bit::azi_6_0_ele_0_0_wavSize,
                 HRIR_48K_24bit::azi_6_0_ele_0_0_wav};
  irMap[6][15] = {HRIR_48K_24bit::azi_6_0_ele_15_0_wavSize,
                  HRIR_48K_24bit::azi_6_0_ele_15_0_wav};
  irMap[6][25] = {HRIR_48K_24bit::azi_6_0_ele_25_0_wavSize,
                  HRIR_48K_24bit::azi_6_0_ele_25_0_wav};
  irMap[6][30] = {HRIR_48K_24bit::azi_6_0_ele_30_0_wavSize,
                  HRIR_48K_24bit::azi_6_0_ele_30_0_wav};
  irMap[6][45] = {HRIR_48K_24bit::azi_6_0_ele_45_0_wavSize,
                  HRIR_48K_24bit::azi_6_0_ele_45_0_wav};
  irMap[6][54] = {HRIR_48K_24bit::azi_6_0_ele_54_0_wavSize,
                  HRIR_48K_24bit::azi_6_0_ele_54_0_wav};
  irMap[6][60] = {HRIR_48K_24bit::azi_6_0_ele_60_0_wavSize,
                  HRIR_48K_24bit::azi_6_0_ele_60_0_wav};
  irMap[6][75] = {HRIR_48K_24bit::azi_6_0_ele_75_0_wavSize,
                  HRIR_48K_24bit::azi_6_0_ele_75_0_wav};
  irMap[6][90] = {HRIR_48K_24bit::azi_6_0_ele_90_0_wavSize,
                  HRIR_48K_24bit::azi_6_0_ele_90_0_wav};
  irMap[6][-15] = {HRIR_48K_24bit::azi_6_0_ele_neg15_0_wavSize,
                   HRIR_48K_24bit::azi_6_0_ele_neg15_0_wav};
  irMap[6][-25] = {HRIR_48K_24bit::azi_6_0_ele_neg25_0_wavSize,
                   HRIR_48K_24bit::azi_6_0_ele_neg25_0_wav};
  irMap[6][-30] = {HRIR_48K_24bit::azi_6_0_ele_neg30_0_wavSize,
                   HRIR_48K_24bit::azi_6_0_ele_neg30_0_wav};
  irMap[6][-45] = {HRIR_48K_24bit::azi_6_0_ele_neg45_0_wavSize,
                   HRIR_48K_24bit::azi_6_0_ele_neg45_0_wav};
  irMap[6][-54] = {HRIR_48K_24bit::azi_6_0_ele_neg54_0_wavSize,
                   HRIR_48K_24bit::azi_6_0_ele_neg54_0_wav};
  irMap[6][-60] = {HRIR_48K_24bit::azi_6_0_ele_neg60_0_wavSize,
                   HRIR_48K_24bit::azi_6_0_ele_neg60_0_wav};
  irMap[6][-75] = {HRIR_48K_24bit::azi_6_0_ele_neg75_0_wavSize,
                   HRIR_48K_24bit::azi_6_0_ele_neg75_0_wav};
  irMap[6][-81] = {HRIR_48K_24bit::azi_6_0_ele_neg81_0_wavSize,
                   HRIR_48K_24bit::azi_6_0_ele_neg81_0_wav};
  irMap[7][0] = {HRIR_48K_24bit::azi_7_0_ele_0_0_wavSize,
                 HRIR_48K_24bit::azi_7_0_ele_0_0_wav};
  irMap[7][15] = {HRIR_48K_24bit::azi_7_0_ele_15_0_wavSize,
                  HRIR_48K_24bit::azi_7_0_ele_15_0_wav};
  irMap[7][25] = {HRIR_48K_24bit::azi_7_0_ele_25_0_wavSize,
                  HRIR_48K_24bit::azi_7_0_ele_25_0_wav};
  irMap[7][30] = {HRIR_48K_24bit::azi_7_0_ele_30_0_wavSize,
                  HRIR_48K_24bit::azi_7_0_ele_30_0_wav};
  irMap[7][45] = {HRIR_48K_24bit::azi_7_0_ele_45_0_wavSize,
                  HRIR_48K_24bit::azi_7_0_ele_45_0_wav};
  irMap[7][54] = {HRIR_48K_24bit::azi_7_0_ele_54_0_wavSize,
                  HRIR_48K_24bit::azi_7_0_ele_54_0_wav};
  irMap[7][60] = {HRIR_48K_24bit::azi_7_0_ele_60_0_wavSize,
                  HRIR_48K_24bit::azi_7_0_ele_60_0_wav};
  irMap[7][75] = {HRIR_48K_24bit::azi_7_0_ele_75_0_wavSize,
                  HRIR_48K_24bit::azi_7_0_ele_75_0_wav};
  irMap[7][90] = {HRIR_48K_24bit::azi_7_0_ele_90_0_wavSize,
                  HRIR_48K_24bit::azi_7_0_ele_90_0_wav};
  irMap[7][-15] = {HRIR_48K_24bit::azi_7_0_ele_neg15_0_wavSize,
                   HRIR_48K_24bit::azi_7_0_ele_neg15_0_wav};
  irMap[7][-25] = {HRIR_48K_24bit::azi_7_0_ele_neg25_0_wavSize,
                   HRIR_48K_24bit::azi_7_0_ele_neg25_0_wav};
  irMap[7][-30] = {HRIR_48K_24bit::azi_7_0_ele_neg30_0_wavSize,
                   HRIR_48K_24bit::azi_7_0_ele_neg30_0_wav};
  irMap[7][-45] = {HRIR_48K_24bit::azi_7_0_ele_neg45_0_wavSize,
                   HRIR_48K_24bit::azi_7_0_ele_neg45_0_wav};
  irMap[7][-54] = {HRIR_48K_24bit::azi_7_0_ele_neg54_0_wavSize,
                   HRIR_48K_24bit::azi_7_0_ele_neg54_0_wav};
  irMap[7][-60] = {HRIR_48K_24bit::azi_7_0_ele_neg60_0_wavSize,
                   HRIR_48K_24bit::azi_7_0_ele_neg60_0_wav};
  irMap[7][-75] = {HRIR_48K_24bit::azi_7_0_ele_neg75_0_wavSize,
                   HRIR_48K_24bit::azi_7_0_ele_neg75_0_wav};
  irMap[7][-81] = {HRIR_48K_24bit::azi_7_0_ele_neg81_0_wavSize,
                   HRIR_48K_24bit::azi_7_0_ele_neg81_0_wav};
  irMap[8][0] = {HRIR_48K_24bit::azi_8_0_ele_0_0_wavSize,
                 HRIR_48K_24bit::azi_8_0_ele_0_0_wav};
  irMap[8][15] = {HRIR_48K_24bit::azi_8_0_ele_15_0_wavSize,
                  HRIR_48K_24bit::azi_8_0_ele_15_0_wav};
  irMap[8][25] = {HRIR_48K_24bit::azi_8_0_ele_25_0_wavSize,
                  HRIR_48K_24bit::azi_8_0_ele_25_0_wav};
  irMap[8][30] = {HRIR_48K_24bit::azi_8_0_ele_30_0_wavSize,
                  HRIR_48K_24bit::azi_8_0_ele_30_0_wav};
  irMap[8][45] = {HRIR_48K_24bit::azi_8_0_ele_45_0_wavSize,
                  HRIR_48K_24bit::azi_8_0_ele_45_0_wav};
  irMap[8][54] = {HRIR_48K_24bit::azi_8_0_ele_54_0_wavSize,
                  HRIR_48K_24bit::azi_8_0_ele_54_0_wav};
  irMap[8][60] = {HRIR_48K_24bit::azi_8_0_ele_60_0_wavSize,
                  HRIR_48K_24bit::azi_8_0_ele_60_0_wav};
  irMap[8][75] = {HRIR_48K_24bit::azi_8_0_ele_75_0_wavSize,
                  HRIR_48K_24bit::azi_8_0_ele_75_0_wav};
  irMap[8][90] = {HRIR_48K_24bit::azi_8_0_ele_90_0_wavSize,
                  HRIR_48K_24bit::azi_8_0_ele_90_0_wav};
  irMap[8][-15] = {HRIR_48K_24bit::azi_8_0_ele_neg15_0_wavSize,
                   HRIR_48K_24bit::azi_8_0_ele_neg15_0_wav};
  irMap[8][-25] = {HRIR_48K_24bit::azi_8_0_ele_neg25_0_wavSize,
                   HRIR_48K_24bit::azi_8_0_ele_neg25_0_wav};
  irMap[8][-30] = {HRIR_48K_24bit::azi_8_0_ele_neg30_0_wavSize,
                   HRIR_48K_24bit::azi_8_0_ele_neg30_0_wav};
  irMap[8][-45] = {HRIR_48K_24bit::azi_8_0_ele_neg45_0_wavSize,
                   HRIR_48K_24bit::azi_8_0_ele_neg45_0_wav};
  irMap[8][-54] = {HRIR_48K_24bit::azi_8_0_ele_neg54_0_wavSize,
                   HRIR_48K_24bit::azi_8_0_ele_neg54_0_wav};
  irMap[8][-60] = {HRIR_48K_24bit::azi_8_0_ele_neg60_0_wavSize,
                   HRIR_48K_24bit::azi_8_0_ele_neg60_0_wav};
  irMap[8][-75] = {HRIR_48K_24bit::azi_8_0_ele_neg75_0_wavSize,
                   HRIR_48K_24bit::azi_8_0_ele_neg75_0_wav};
  irMap[8][-81] = {HRIR_48K_24bit::azi_8_0_ele_neg81_0_wavSize,
                   HRIR_48K_24bit::azi_8_0_ele_neg81_0_wav};
  irMap[9][0] = {HRIR_48K_24bit::azi_9_0_ele_0_0_wavSize,
                 HRIR_48K_24bit::azi_9_0_ele_0_0_wav};
  irMap[9][15] = {HRIR_48K_24bit::azi_9_0_ele_15_0_wavSize,
                  HRIR_48K_24bit::azi_9_0_ele_15_0_wav};
  irMap[9][25] = {HRIR_48K_24bit::azi_9_0_ele_25_0_wavSize,
                  HRIR_48K_24bit::azi_9_0_ele_25_0_wav};
  irMap[9][30] = {HRIR_48K_24bit::azi_9_0_ele_30_0_wavSize,
                  HRIR_48K_24bit::azi_9_0_ele_30_0_wav};
  irMap[9][45] = {HRIR_48K_24bit::azi_9_0_ele_45_0_wavSize,
                  HRIR_48K_24bit::azi_9_0_ele_45_0_wav};
  irMap[9][54] = {HRIR_48K_24bit::azi_9_0_ele_54_0_wavSize,
                  HRIR_48K_24bit::azi_9_0_ele_54_0_wav};
  irMap[9][60] = {HRIR_48K_24bit::azi_9_0_ele_60_0_wavSize,
                  HRIR_48K_24bit::azi_9_0_ele_60_0_wav};
  irMap[9][75] = {HRIR_48K_24bit::azi_9_0_ele_75_0_wavSize,
                  HRIR_48K_24bit::azi_9_0_ele_75_0_wav};
  irMap[9][90] = {HRIR_48K_24bit::azi_9_0_ele_90_0_wavSize,
                  HRIR_48K_24bit::azi_9_0_ele_90_0_wav};
  irMap[9][-15] = {HRIR_48K_24bit::azi_9_0_ele_neg15_0_wavSize,
                   HRIR_48K_24bit::azi_9_0_ele_neg15_0_wav};
  irMap[9][-25] = {HRIR_48K_24bit::azi_9_0_ele_neg25_0_wavSize,
                   HRIR_48K_24bit::azi_9_0_ele_neg25_0_wav};
  irMap[9][-30] = {HRIR_48K_24bit::azi_9_0_ele_neg30_0_wavSize,
                   HRIR_48K_24bit::azi_9_0_ele_neg30_0_wav};
  irMap[9][-45] = {HRIR_48K_24bit::azi_9_0_ele_neg45_0_wavSize,
                   HRIR_48K_24bit::azi_9_0_ele_neg45_0_wav};
  irMap[9][-54] = {HRIR_48K_24bit::azi_9_0_ele_neg54_0_wavSize,
                   HRIR_48K_24bit::azi_9_0_ele_neg54_0_wav};
  irMap[9][-60] = {HRIR_48K_24bit::azi_9_0_ele_neg60_0_wavSize,
                   HRIR_48K_24bit::azi_9_0_ele_neg60_0_wav};
  irMap[9][-75] = {HRIR_48K_24bit::azi_9_0_ele_neg75_0_wavSize,
                   HRIR_48K_24bit::azi_9_0_ele_neg75_0_wav};
  irMap[9][-81] = {HRIR_48K_24bit::azi_9_0_ele_neg81_0_wavSize,
                   HRIR_48K_24bit::azi_9_0_ele_neg81_0_wav};
  irMap[10][0] = {HRIR_48K_24bit::azi_10_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_10_0_ele_0_0_wav};
  irMap[10][15] = {HRIR_48K_24bit::azi_10_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_10_0_ele_15_0_wav};
  irMap[10][25] = {HRIR_48K_24bit::azi_10_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_10_0_ele_25_0_wav};
  irMap[10][30] = {HRIR_48K_24bit::azi_10_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_10_0_ele_30_0_wav};
  irMap[10][45] = {HRIR_48K_24bit::azi_10_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_10_0_ele_45_0_wav};
  irMap[10][54] = {HRIR_48K_24bit::azi_10_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_10_0_ele_54_0_wav};
  irMap[10][60] = {HRIR_48K_24bit::azi_10_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_10_0_ele_60_0_wav};
  irMap[10][75] = {HRIR_48K_24bit::azi_10_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_10_0_ele_75_0_wav};
  irMap[10][90] = {HRIR_48K_24bit::azi_10_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_10_0_ele_90_0_wav};
  irMap[10][-15] = {HRIR_48K_24bit::azi_10_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_10_0_ele_neg15_0_wav};
  irMap[10][-25] = {HRIR_48K_24bit::azi_10_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_10_0_ele_neg25_0_wav};
  irMap[10][-30] = {HRIR_48K_24bit::azi_10_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_10_0_ele_neg30_0_wav};
  irMap[10][-45] = {HRIR_48K_24bit::azi_10_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_10_0_ele_neg45_0_wav};
  irMap[10][-54] = {HRIR_48K_24bit::azi_10_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_10_0_ele_neg54_0_wav};
  irMap[10][-60] = {HRIR_48K_24bit::azi_10_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_10_0_ele_neg60_0_wav};
  irMap[10][-75] = {HRIR_48K_24bit::azi_10_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_10_0_ele_neg75_0_wav};
  irMap[10][-81] = {HRIR_48K_24bit::azi_10_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_10_0_ele_neg81_0_wav};
  irMap[11][0] = {HRIR_48K_24bit::azi_11_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_11_0_ele_0_0_wav};
  irMap[11][15] = {HRIR_48K_24bit::azi_11_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_11_0_ele_15_0_wav};
  irMap[11][25] = {HRIR_48K_24bit::azi_11_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_11_0_ele_25_0_wav};
  irMap[11][30] = {HRIR_48K_24bit::azi_11_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_11_0_ele_30_0_wav};
  irMap[11][45] = {HRIR_48K_24bit::azi_11_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_11_0_ele_45_0_wav};
  irMap[11][54] = {HRIR_48K_24bit::azi_11_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_11_0_ele_54_0_wav};
  irMap[11][60] = {HRIR_48K_24bit::azi_11_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_11_0_ele_60_0_wav};
  irMap[11][75] = {HRIR_48K_24bit::azi_11_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_11_0_ele_75_0_wav};
  irMap[11][90] = {HRIR_48K_24bit::azi_11_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_11_0_ele_90_0_wav};
  irMap[11][-15] = {HRIR_48K_24bit::azi_11_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_11_0_ele_neg15_0_wav};
  irMap[11][-25] = {HRIR_48K_24bit::azi_11_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_11_0_ele_neg25_0_wav};
  irMap[11][-30] = {HRIR_48K_24bit::azi_11_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_11_0_ele_neg30_0_wav};
  irMap[11][-45] = {HRIR_48K_24bit::azi_11_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_11_0_ele_neg45_0_wav};
  irMap[11][-54] = {HRIR_48K_24bit::azi_11_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_11_0_ele_neg54_0_wav};
  irMap[11][-60] = {HRIR_48K_24bit::azi_11_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_11_0_ele_neg60_0_wav};
  irMap[11][-75] = {HRIR_48K_24bit::azi_11_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_11_0_ele_neg75_0_wav};
  irMap[11][-81] = {HRIR_48K_24bit::azi_11_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_11_0_ele_neg81_0_wav};
  irMap[12][0] = {HRIR_48K_24bit::azi_12_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_12_0_ele_0_0_wav};
  irMap[12][15] = {HRIR_48K_24bit::azi_12_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_12_0_ele_15_0_wav};
  irMap[12][25] = {HRIR_48K_24bit::azi_12_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_12_0_ele_25_0_wav};
  irMap[12][30] = {HRIR_48K_24bit::azi_12_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_12_0_ele_30_0_wav};
  irMap[12][45] = {HRIR_48K_24bit::azi_12_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_12_0_ele_45_0_wav};
  irMap[12][54] = {HRIR_48K_24bit::azi_12_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_12_0_ele_54_0_wav};
  irMap[12][60] = {HRIR_48K_24bit::azi_12_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_12_0_ele_60_0_wav};
  irMap[12][75] = {HRIR_48K_24bit::azi_12_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_12_0_ele_75_0_wav};
  irMap[12][90] = {HRIR_48K_24bit::azi_12_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_12_0_ele_90_0_wav};
  irMap[12][-15] = {HRIR_48K_24bit::azi_12_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_12_0_ele_neg15_0_wav};
  irMap[12][-25] = {HRIR_48K_24bit::azi_12_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_12_0_ele_neg25_0_wav};
  irMap[12][-30] = {HRIR_48K_24bit::azi_12_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_12_0_ele_neg30_0_wav};
  irMap[12][-45] = {HRIR_48K_24bit::azi_12_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_12_0_ele_neg45_0_wav};
  irMap[12][-54] = {HRIR_48K_24bit::azi_12_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_12_0_ele_neg54_0_wav};
  irMap[12][-60] = {HRIR_48K_24bit::azi_12_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_12_0_ele_neg60_0_wav};
  irMap[12][-75] = {HRIR_48K_24bit::azi_12_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_12_0_ele_neg75_0_wav};
  irMap[12][-81] = {HRIR_48K_24bit::azi_12_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_12_0_ele_neg81_0_wav};
  irMap[13][0] = {HRIR_48K_24bit::azi_13_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_13_0_ele_0_0_wav};
  irMap[13][15] = {HRIR_48K_24bit::azi_13_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_13_0_ele_15_0_wav};
  irMap[13][25] = {HRIR_48K_24bit::azi_13_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_13_0_ele_25_0_wav};
  irMap[13][30] = {HRIR_48K_24bit::azi_13_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_13_0_ele_30_0_wav};
  irMap[13][45] = {HRIR_48K_24bit::azi_13_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_13_0_ele_45_0_wav};
  irMap[13][54] = {HRIR_48K_24bit::azi_13_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_13_0_ele_54_0_wav};
  irMap[13][60] = {HRIR_48K_24bit::azi_13_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_13_0_ele_60_0_wav};
  irMap[13][75] = {HRIR_48K_24bit::azi_13_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_13_0_ele_75_0_wav};
  irMap[13][90] = {HRIR_48K_24bit::azi_13_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_13_0_ele_90_0_wav};
  irMap[13][-15] = {HRIR_48K_24bit::azi_13_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_13_0_ele_neg15_0_wav};
  irMap[13][-25] = {HRIR_48K_24bit::azi_13_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_13_0_ele_neg25_0_wav};
  irMap[13][-30] = {HRIR_48K_24bit::azi_13_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_13_0_ele_neg30_0_wav};
  irMap[13][-45] = {HRIR_48K_24bit::azi_13_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_13_0_ele_neg45_0_wav};
  irMap[13][-54] = {HRIR_48K_24bit::azi_13_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_13_0_ele_neg54_0_wav};
  irMap[13][-60] = {HRIR_48K_24bit::azi_13_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_13_0_ele_neg60_0_wav};
  irMap[13][-75] = {HRIR_48K_24bit::azi_13_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_13_0_ele_neg75_0_wav};
  irMap[13][-81] = {HRIR_48K_24bit::azi_13_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_13_0_ele_neg81_0_wav};
  irMap[14][0] = {HRIR_48K_24bit::azi_14_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_14_0_ele_0_0_wav};
  irMap[14][15] = {HRIR_48K_24bit::azi_14_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_14_0_ele_15_0_wav};
  irMap[14][25] = {HRIR_48K_24bit::azi_14_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_14_0_ele_25_0_wav};
  irMap[14][30] = {HRIR_48K_24bit::azi_14_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_14_0_ele_30_0_wav};
  irMap[14][45] = {HRIR_48K_24bit::azi_14_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_14_0_ele_45_0_wav};
  irMap[14][54] = {HRIR_48K_24bit::azi_14_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_14_0_ele_54_0_wav};
  irMap[14][60] = {HRIR_48K_24bit::azi_14_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_14_0_ele_60_0_wav};
  irMap[14][75] = {HRIR_48K_24bit::azi_14_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_14_0_ele_75_0_wav};
  irMap[14][90] = {HRIR_48K_24bit::azi_14_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_14_0_ele_90_0_wav};
  irMap[14][-15] = {HRIR_48K_24bit::azi_14_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_14_0_ele_neg15_0_wav};
  irMap[14][-25] = {HRIR_48K_24bit::azi_14_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_14_0_ele_neg25_0_wav};
  irMap[14][-30] = {HRIR_48K_24bit::azi_14_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_14_0_ele_neg30_0_wav};
  irMap[14][-45] = {HRIR_48K_24bit::azi_14_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_14_0_ele_neg45_0_wav};
  irMap[14][-54] = {HRIR_48K_24bit::azi_14_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_14_0_ele_neg54_0_wav};
  irMap[14][-60] = {HRIR_48K_24bit::azi_14_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_14_0_ele_neg60_0_wav};
  irMap[14][-75] = {HRIR_48K_24bit::azi_14_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_14_0_ele_neg75_0_wav};
  irMap[14][-81] = {HRIR_48K_24bit::azi_14_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_14_0_ele_neg81_0_wav};
  irMap[15][0] = {HRIR_48K_24bit::azi_15_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_15_0_ele_0_0_wav};
  irMap[15][15] = {HRIR_48K_24bit::azi_15_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_15_0_ele_15_0_wav};
  irMap[15][25] = {HRIR_48K_24bit::azi_15_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_15_0_ele_25_0_wav};
  irMap[15][30] = {HRIR_48K_24bit::azi_15_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_15_0_ele_30_0_wav};
  irMap[15][45] = {HRIR_48K_24bit::azi_15_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_15_0_ele_45_0_wav};
  irMap[15][54] = {HRIR_48K_24bit::azi_15_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_15_0_ele_54_0_wav};
  irMap[15][60] = {HRIR_48K_24bit::azi_15_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_15_0_ele_60_0_wav};
  irMap[15][75] = {HRIR_48K_24bit::azi_15_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_15_0_ele_75_0_wav};
  irMap[15][90] = {HRIR_48K_24bit::azi_15_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_15_0_ele_90_0_wav};
  irMap[15][-15] = {HRIR_48K_24bit::azi_15_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_15_0_ele_neg15_0_wav};
  irMap[15][-25] = {HRIR_48K_24bit::azi_15_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_15_0_ele_neg25_0_wav};
  irMap[15][-30] = {HRIR_48K_24bit::azi_15_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_15_0_ele_neg30_0_wav};
  irMap[15][-45] = {HRIR_48K_24bit::azi_15_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_15_0_ele_neg45_0_wav};
  irMap[15][-54] = {HRIR_48K_24bit::azi_15_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_15_0_ele_neg54_0_wav};
  irMap[15][-60] = {HRIR_48K_24bit::azi_15_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_15_0_ele_neg60_0_wav};
  irMap[15][-75] = {HRIR_48K_24bit::azi_15_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_15_0_ele_neg75_0_wav};
  irMap[15][-81] = {HRIR_48K_24bit::azi_15_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_15_0_ele_neg81_0_wav};
  irMap[16][0] = {HRIR_48K_24bit::azi_16_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_16_0_ele_0_0_wav};
  irMap[16][15] = {HRIR_48K_24bit::azi_16_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_16_0_ele_15_0_wav};
  irMap[16][25] = {HRIR_48K_24bit::azi_16_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_16_0_ele_25_0_wav};
  irMap[16][30] = {HRIR_48K_24bit::azi_16_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_16_0_ele_30_0_wav};
  irMap[16][45] = {HRIR_48K_24bit::azi_16_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_16_0_ele_45_0_wav};
  irMap[16][54] = {HRIR_48K_24bit::azi_16_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_16_0_ele_54_0_wav};
  irMap[16][60] = {HRIR_48K_24bit::azi_16_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_16_0_ele_60_0_wav};
  irMap[16][75] = {HRIR_48K_24bit::azi_16_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_16_0_ele_75_0_wav};
  irMap[16][90] = {HRIR_48K_24bit::azi_16_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_16_0_ele_90_0_wav};
  irMap[16][-15] = {HRIR_48K_24bit::azi_16_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_16_0_ele_neg15_0_wav};
  irMap[16][-25] = {HRIR_48K_24bit::azi_16_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_16_0_ele_neg25_0_wav};
  irMap[16][-30] = {HRIR_48K_24bit::azi_16_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_16_0_ele_neg30_0_wav};
  irMap[16][-45] = {HRIR_48K_24bit::azi_16_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_16_0_ele_neg45_0_wav};
  irMap[16][-54] = {HRIR_48K_24bit::azi_16_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_16_0_ele_neg54_0_wav};
  irMap[16][-60] = {HRIR_48K_24bit::azi_16_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_16_0_ele_neg60_0_wav};
  irMap[16][-75] = {HRIR_48K_24bit::azi_16_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_16_0_ele_neg75_0_wav};
  irMap[16][-81] = {HRIR_48K_24bit::azi_16_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_16_0_ele_neg81_0_wav};
  irMap[17][0] = {HRIR_48K_24bit::azi_17_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_17_0_ele_0_0_wav};
  irMap[17][15] = {HRIR_48K_24bit::azi_17_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_17_0_ele_15_0_wav};
  irMap[17][25] = {HRIR_48K_24bit::azi_17_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_17_0_ele_25_0_wav};
  irMap[17][30] = {HRIR_48K_24bit::azi_17_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_17_0_ele_30_0_wav};
  irMap[17][45] = {HRIR_48K_24bit::azi_17_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_17_0_ele_45_0_wav};
  irMap[17][54] = {HRIR_48K_24bit::azi_17_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_17_0_ele_54_0_wav};
  irMap[17][60] = {HRIR_48K_24bit::azi_17_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_17_0_ele_60_0_wav};
  irMap[17][75] = {HRIR_48K_24bit::azi_17_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_17_0_ele_75_0_wav};
  irMap[17][90] = {HRIR_48K_24bit::azi_17_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_17_0_ele_90_0_wav};
  irMap[17][-15] = {HRIR_48K_24bit::azi_17_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_17_0_ele_neg15_0_wav};
  irMap[17][-25] = {HRIR_48K_24bit::azi_17_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_17_0_ele_neg25_0_wav};
  irMap[17][-30] = {HRIR_48K_24bit::azi_17_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_17_0_ele_neg30_0_wav};
  irMap[17][-45] = {HRIR_48K_24bit::azi_17_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_17_0_ele_neg45_0_wav};
  irMap[17][-54] = {HRIR_48K_24bit::azi_17_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_17_0_ele_neg54_0_wav};
  irMap[17][-60] = {HRIR_48K_24bit::azi_17_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_17_0_ele_neg60_0_wav};
  irMap[17][-75] = {HRIR_48K_24bit::azi_17_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_17_0_ele_neg75_0_wav};
  irMap[17][-81] = {HRIR_48K_24bit::azi_17_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_17_0_ele_neg81_0_wav};
  irMap[18][0] = {HRIR_48K_24bit::azi_18_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_18_0_ele_0_0_wav};
  irMap[18][15] = {HRIR_48K_24bit::azi_18_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_18_0_ele_15_0_wav};
  irMap[18][25] = {HRIR_48K_24bit::azi_18_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_18_0_ele_25_0_wav};
  irMap[18][30] = {HRIR_48K_24bit::azi_18_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_18_0_ele_30_0_wav};
  irMap[18][45] = {HRIR_48K_24bit::azi_18_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_18_0_ele_45_0_wav};
  irMap[18][54] = {HRIR_48K_24bit::azi_18_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_18_0_ele_54_0_wav};
  irMap[18][60] = {HRIR_48K_24bit::azi_18_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_18_0_ele_60_0_wav};
  irMap[18][75] = {HRIR_48K_24bit::azi_18_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_18_0_ele_75_0_wav};
  irMap[18][90] = {HRIR_48K_24bit::azi_18_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_18_0_ele_90_0_wav};
  irMap[18][-15] = {HRIR_48K_24bit::azi_18_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_18_0_ele_neg15_0_wav};
  irMap[18][-25] = {HRIR_48K_24bit::azi_18_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_18_0_ele_neg25_0_wav};
  irMap[18][-30] = {HRIR_48K_24bit::azi_18_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_18_0_ele_neg30_0_wav};
  irMap[18][-45] = {HRIR_48K_24bit::azi_18_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_18_0_ele_neg45_0_wav};
  irMap[18][-54] = {HRIR_48K_24bit::azi_18_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_18_0_ele_neg54_0_wav};
  irMap[18][-60] = {HRIR_48K_24bit::azi_18_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_18_0_ele_neg60_0_wav};
  irMap[18][-75] = {HRIR_48K_24bit::azi_18_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_18_0_ele_neg75_0_wav};
  irMap[18][-81] = {HRIR_48K_24bit::azi_18_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_18_0_ele_neg81_0_wav};
  irMap[19][0] = {HRIR_48K_24bit::azi_19_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_19_0_ele_0_0_wav};
  irMap[19][15] = {HRIR_48K_24bit::azi_19_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_19_0_ele_15_0_wav};
  irMap[19][25] = {HRIR_48K_24bit::azi_19_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_19_0_ele_25_0_wav};
  irMap[19][30] = {HRIR_48K_24bit::azi_19_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_19_0_ele_30_0_wav};
  irMap[19][45] = {HRIR_48K_24bit::azi_19_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_19_0_ele_45_0_wav};
  irMap[19][54] = {HRIR_48K_24bit::azi_19_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_19_0_ele_54_0_wav};
  irMap[19][60] = {HRIR_48K_24bit::azi_19_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_19_0_ele_60_0_wav};
  irMap[19][75] = {HRIR_48K_24bit::azi_19_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_19_0_ele_75_0_wav};
  irMap[19][90] = {HRIR_48K_24bit::azi_19_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_19_0_ele_90_0_wav};
  irMap[19][-15] = {HRIR_48K_24bit::azi_19_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_19_0_ele_neg15_0_wav};
  irMap[19][-25] = {HRIR_48K_24bit::azi_19_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_19_0_ele_neg25_0_wav};
  irMap[19][-30] = {HRIR_48K_24bit::azi_19_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_19_0_ele_neg30_0_wav};
  irMap[19][-45] = {HRIR_48K_24bit::azi_19_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_19_0_ele_neg45_0_wav};
  irMap[19][-54] = {HRIR_48K_24bit::azi_19_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_19_0_ele_neg54_0_wav};
  irMap[19][-60] = {HRIR_48K_24bit::azi_19_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_19_0_ele_neg60_0_wav};
  irMap[19][-75] = {HRIR_48K_24bit::azi_19_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_19_0_ele_neg75_0_wav};
  irMap[19][-81] = {HRIR_48K_24bit::azi_19_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_19_0_ele_neg81_0_wav};
  irMap[20][0] = {HRIR_48K_24bit::azi_20_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_20_0_ele_0_0_wav};
  irMap[20][15] = {HRIR_48K_24bit::azi_20_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_20_0_ele_15_0_wav};
  irMap[20][25] = {HRIR_48K_24bit::azi_20_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_20_0_ele_25_0_wav};
  irMap[20][30] = {HRIR_48K_24bit::azi_20_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_20_0_ele_30_0_wav};
  irMap[20][45] = {HRIR_48K_24bit::azi_20_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_20_0_ele_45_0_wav};
  irMap[20][54] = {HRIR_48K_24bit::azi_20_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_20_0_ele_54_0_wav};
  irMap[20][60] = {HRIR_48K_24bit::azi_20_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_20_0_ele_60_0_wav};
  irMap[20][75] = {HRIR_48K_24bit::azi_20_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_20_0_ele_75_0_wav};
  irMap[20][90] = {HRIR_48K_24bit::azi_20_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_20_0_ele_90_0_wav};
  irMap[20][-15] = {HRIR_48K_24bit::azi_20_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_20_0_ele_neg15_0_wav};
  irMap[20][-25] = {HRIR_48K_24bit::azi_20_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_20_0_ele_neg25_0_wav};
  irMap[20][-30] = {HRIR_48K_24bit::azi_20_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_20_0_ele_neg30_0_wav};
  irMap[20][-45] = {HRIR_48K_24bit::azi_20_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_20_0_ele_neg45_0_wav};
  irMap[20][-54] = {HRIR_48K_24bit::azi_20_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_20_0_ele_neg54_0_wav};
  irMap[20][-60] = {HRIR_48K_24bit::azi_20_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_20_0_ele_neg60_0_wav};
  irMap[20][-75] = {HRIR_48K_24bit::azi_20_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_20_0_ele_neg75_0_wav};
  irMap[20][-81] = {HRIR_48K_24bit::azi_20_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_20_0_ele_neg81_0_wav};
  irMap[21][0] = {HRIR_48K_24bit::azi_21_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_21_0_ele_0_0_wav};
  irMap[21][15] = {HRIR_48K_24bit::azi_21_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_21_0_ele_15_0_wav};
  irMap[21][25] = {HRIR_48K_24bit::azi_21_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_21_0_ele_25_0_wav};
  irMap[21][30] = {HRIR_48K_24bit::azi_21_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_21_0_ele_30_0_wav};
  irMap[21][45] = {HRIR_48K_24bit::azi_21_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_21_0_ele_45_0_wav};
  irMap[21][54] = {HRIR_48K_24bit::azi_21_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_21_0_ele_54_0_wav};
  irMap[21][60] = {HRIR_48K_24bit::azi_21_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_21_0_ele_60_0_wav};
  irMap[21][75] = {HRIR_48K_24bit::azi_21_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_21_0_ele_75_0_wav};
  irMap[21][90] = {HRIR_48K_24bit::azi_21_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_21_0_ele_90_0_wav};
  irMap[21][-15] = {HRIR_48K_24bit::azi_21_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_21_0_ele_neg15_0_wav};
  irMap[21][-25] = {HRIR_48K_24bit::azi_21_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_21_0_ele_neg25_0_wav};
  irMap[21][-30] = {HRIR_48K_24bit::azi_21_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_21_0_ele_neg30_0_wav};
  irMap[21][-45] = {HRIR_48K_24bit::azi_21_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_21_0_ele_neg45_0_wav};
  irMap[21][-54] = {HRIR_48K_24bit::azi_21_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_21_0_ele_neg54_0_wav};
  irMap[21][-60] = {HRIR_48K_24bit::azi_21_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_21_0_ele_neg60_0_wav};
  irMap[21][-75] = {HRIR_48K_24bit::azi_21_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_21_0_ele_neg75_0_wav};
  irMap[21][-81] = {HRIR_48K_24bit::azi_21_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_21_0_ele_neg81_0_wav};
  irMap[22][0] = {HRIR_48K_24bit::azi_22_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_22_0_ele_0_0_wav};
  irMap[22][15] = {HRIR_48K_24bit::azi_22_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_22_0_ele_15_0_wav};
  irMap[22][25] = {HRIR_48K_24bit::azi_22_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_22_0_ele_25_0_wav};
  irMap[22][30] = {HRIR_48K_24bit::azi_22_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_22_0_ele_30_0_wav};
  irMap[22][45] = {HRIR_48K_24bit::azi_22_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_22_0_ele_45_0_wav};
  irMap[22][54] = {HRIR_48K_24bit::azi_22_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_22_0_ele_54_0_wav};
  irMap[22][60] = {HRIR_48K_24bit::azi_22_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_22_0_ele_60_0_wav};
  irMap[22][75] = {HRIR_48K_24bit::azi_22_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_22_0_ele_75_0_wav};
  irMap[22][90] = {HRIR_48K_24bit::azi_22_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_22_0_ele_90_0_wav};
  irMap[22][-15] = {HRIR_48K_24bit::azi_22_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_22_0_ele_neg15_0_wav};
  irMap[22][-25] = {HRIR_48K_24bit::azi_22_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_22_0_ele_neg25_0_wav};
  irMap[22][-30] = {HRIR_48K_24bit::azi_22_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_22_0_ele_neg30_0_wav};
  irMap[22][-45] = {HRIR_48K_24bit::azi_22_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_22_0_ele_neg45_0_wav};
  irMap[22][-54] = {HRIR_48K_24bit::azi_22_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_22_0_ele_neg54_0_wav};
  irMap[22][-60] = {HRIR_48K_24bit::azi_22_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_22_0_ele_neg60_0_wav};
  irMap[22][-75] = {HRIR_48K_24bit::azi_22_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_22_0_ele_neg75_0_wav};
  irMap[22][-81] = {HRIR_48K_24bit::azi_22_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_22_0_ele_neg81_0_wav};
  irMap[23][0] = {HRIR_48K_24bit::azi_23_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_23_0_ele_0_0_wav};
  irMap[23][15] = {HRIR_48K_24bit::azi_23_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_23_0_ele_15_0_wav};
  irMap[23][25] = {HRIR_48K_24bit::azi_23_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_23_0_ele_25_0_wav};
  irMap[23][30] = {HRIR_48K_24bit::azi_23_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_23_0_ele_30_0_wav};
  irMap[23][45] = {HRIR_48K_24bit::azi_23_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_23_0_ele_45_0_wav};
  irMap[23][54] = {HRIR_48K_24bit::azi_23_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_23_0_ele_54_0_wav};
  irMap[23][60] = {HRIR_48K_24bit::azi_23_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_23_0_ele_60_0_wav};
  irMap[23][75] = {HRIR_48K_24bit::azi_23_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_23_0_ele_75_0_wav};
  irMap[23][90] = {HRIR_48K_24bit::azi_23_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_23_0_ele_90_0_wav};
  irMap[23][-15] = {HRIR_48K_24bit::azi_23_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_23_0_ele_neg15_0_wav};
  irMap[23][-25] = {HRIR_48K_24bit::azi_23_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_23_0_ele_neg25_0_wav};
  irMap[23][-30] = {HRIR_48K_24bit::azi_23_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_23_0_ele_neg30_0_wav};
  irMap[23][-45] = {HRIR_48K_24bit::azi_23_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_23_0_ele_neg45_0_wav};
  irMap[23][-54] = {HRIR_48K_24bit::azi_23_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_23_0_ele_neg54_0_wav};
  irMap[23][-60] = {HRIR_48K_24bit::azi_23_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_23_0_ele_neg60_0_wav};
  irMap[23][-75] = {HRIR_48K_24bit::azi_23_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_23_0_ele_neg75_0_wav};
  irMap[23][-81] = {HRIR_48K_24bit::azi_23_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_23_0_ele_neg81_0_wav};
  irMap[24][0] = {HRIR_48K_24bit::azi_24_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_24_0_ele_0_0_wav};
  irMap[24][15] = {HRIR_48K_24bit::azi_24_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_24_0_ele_15_0_wav};
  irMap[24][25] = {HRIR_48K_24bit::azi_24_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_24_0_ele_25_0_wav};
  irMap[24][30] = {HRIR_48K_24bit::azi_24_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_24_0_ele_30_0_wav};
  irMap[24][45] = {HRIR_48K_24bit::azi_24_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_24_0_ele_45_0_wav};
  irMap[24][54] = {HRIR_48K_24bit::azi_24_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_24_0_ele_54_0_wav};
  irMap[24][60] = {HRIR_48K_24bit::azi_24_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_24_0_ele_60_0_wav};
  irMap[24][75] = {HRIR_48K_24bit::azi_24_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_24_0_ele_75_0_wav};
  irMap[24][90] = {HRIR_48K_24bit::azi_24_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_24_0_ele_90_0_wav};
  irMap[24][-15] = {HRIR_48K_24bit::azi_24_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_24_0_ele_neg15_0_wav};
  irMap[24][-25] = {HRIR_48K_24bit::azi_24_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_24_0_ele_neg25_0_wav};
  irMap[24][-30] = {HRIR_48K_24bit::azi_24_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_24_0_ele_neg30_0_wav};
  irMap[24][-45] = {HRIR_48K_24bit::azi_24_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_24_0_ele_neg45_0_wav};
  irMap[24][-54] = {HRIR_48K_24bit::azi_24_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_24_0_ele_neg54_0_wav};
  irMap[24][-60] = {HRIR_48K_24bit::azi_24_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_24_0_ele_neg60_0_wav};
  irMap[24][-75] = {HRIR_48K_24bit::azi_24_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_24_0_ele_neg75_0_wav};
  irMap[24][-81] = {HRIR_48K_24bit::azi_24_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_24_0_ele_neg81_0_wav};
  irMap[25][0] = {HRIR_48K_24bit::azi_25_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_25_0_ele_0_0_wav};
  irMap[25][15] = {HRIR_48K_24bit::azi_25_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_25_0_ele_15_0_wav};
  irMap[25][25] = {HRIR_48K_24bit::azi_25_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_25_0_ele_25_0_wav};
  irMap[25][30] = {HRIR_48K_24bit::azi_25_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_25_0_ele_30_0_wav};
  irMap[25][45] = {HRIR_48K_24bit::azi_25_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_25_0_ele_45_0_wav};
  irMap[25][54] = {HRIR_48K_24bit::azi_25_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_25_0_ele_54_0_wav};
  irMap[25][60] = {HRIR_48K_24bit::azi_25_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_25_0_ele_60_0_wav};
  irMap[25][75] = {HRIR_48K_24bit::azi_25_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_25_0_ele_75_0_wav};
  irMap[25][90] = {HRIR_48K_24bit::azi_25_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_25_0_ele_90_0_wav};
  irMap[25][-15] = {HRIR_48K_24bit::azi_25_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_25_0_ele_neg15_0_wav};
  irMap[25][-25] = {HRIR_48K_24bit::azi_25_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_25_0_ele_neg25_0_wav};
  irMap[25][-30] = {HRIR_48K_24bit::azi_25_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_25_0_ele_neg30_0_wav};
  irMap[25][-45] = {HRIR_48K_24bit::azi_25_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_25_0_ele_neg45_0_wav};
  irMap[25][-54] = {HRIR_48K_24bit::azi_25_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_25_0_ele_neg54_0_wav};
  irMap[25][-60] = {HRIR_48K_24bit::azi_25_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_25_0_ele_neg60_0_wav};
  irMap[25][-75] = {HRIR_48K_24bit::azi_25_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_25_0_ele_neg75_0_wav};
  irMap[25][-81] = {HRIR_48K_24bit::azi_25_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_25_0_ele_neg81_0_wav};
  irMap[26][0] = {HRIR_48K_24bit::azi_26_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_26_0_ele_0_0_wav};
  irMap[26][15] = {HRIR_48K_24bit::azi_26_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_26_0_ele_15_0_wav};
  irMap[26][25] = {HRIR_48K_24bit::azi_26_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_26_0_ele_25_0_wav};
  irMap[26][30] = {HRIR_48K_24bit::azi_26_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_26_0_ele_30_0_wav};
  irMap[26][45] = {HRIR_48K_24bit::azi_26_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_26_0_ele_45_0_wav};
  irMap[26][54] = {HRIR_48K_24bit::azi_26_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_26_0_ele_54_0_wav};
  irMap[26][60] = {HRIR_48K_24bit::azi_26_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_26_0_ele_60_0_wav};
  irMap[26][75] = {HRIR_48K_24bit::azi_26_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_26_0_ele_75_0_wav};
  irMap[26][90] = {HRIR_48K_24bit::azi_26_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_26_0_ele_90_0_wav};
  irMap[26][-15] = {HRIR_48K_24bit::azi_26_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_26_0_ele_neg15_0_wav};
  irMap[26][-25] = {HRIR_48K_24bit::azi_26_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_26_0_ele_neg25_0_wav};
  irMap[26][-30] = {HRIR_48K_24bit::azi_26_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_26_0_ele_neg30_0_wav};
  irMap[26][-45] = {HRIR_48K_24bit::azi_26_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_26_0_ele_neg45_0_wav};
  irMap[26][-54] = {HRIR_48K_24bit::azi_26_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_26_0_ele_neg54_0_wav};
  irMap[26][-60] = {HRIR_48K_24bit::azi_26_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_26_0_ele_neg60_0_wav};
  irMap[26][-75] = {HRIR_48K_24bit::azi_26_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_26_0_ele_neg75_0_wav};
  irMap[26][-81] = {HRIR_48K_24bit::azi_26_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_26_0_ele_neg81_0_wav};
  irMap[27][0] = {HRIR_48K_24bit::azi_27_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_27_0_ele_0_0_wav};
  irMap[27][15] = {HRIR_48K_24bit::azi_27_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_27_0_ele_15_0_wav};
  irMap[27][25] = {HRIR_48K_24bit::azi_27_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_27_0_ele_25_0_wav};
  irMap[27][30] = {HRIR_48K_24bit::azi_27_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_27_0_ele_30_0_wav};
  irMap[27][45] = {HRIR_48K_24bit::azi_27_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_27_0_ele_45_0_wav};
  irMap[27][54] = {HRIR_48K_24bit::azi_27_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_27_0_ele_54_0_wav};
  irMap[27][60] = {HRIR_48K_24bit::azi_27_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_27_0_ele_60_0_wav};
  irMap[27][75] = {HRIR_48K_24bit::azi_27_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_27_0_ele_75_0_wav};
  irMap[27][90] = {HRIR_48K_24bit::azi_27_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_27_0_ele_90_0_wav};
  irMap[27][-15] = {HRIR_48K_24bit::azi_27_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_27_0_ele_neg15_0_wav};
  irMap[27][-25] = {HRIR_48K_24bit::azi_27_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_27_0_ele_neg25_0_wav};
  irMap[27][-30] = {HRIR_48K_24bit::azi_27_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_27_0_ele_neg30_0_wav};
  irMap[27][-45] = {HRIR_48K_24bit::azi_27_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_27_0_ele_neg45_0_wav};
  irMap[27][-54] = {HRIR_48K_24bit::azi_27_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_27_0_ele_neg54_0_wav};
  irMap[27][-60] = {HRIR_48K_24bit::azi_27_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_27_0_ele_neg60_0_wav};
  irMap[27][-75] = {HRIR_48K_24bit::azi_27_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_27_0_ele_neg75_0_wav};
  irMap[27][-81] = {HRIR_48K_24bit::azi_27_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_27_0_ele_neg81_0_wav};
  irMap[28][0] = {HRIR_48K_24bit::azi_28_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_28_0_ele_0_0_wav};
  irMap[28][15] = {HRIR_48K_24bit::azi_28_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_28_0_ele_15_0_wav};
  irMap[28][25] = {HRIR_48K_24bit::azi_28_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_28_0_ele_25_0_wav};
  irMap[28][30] = {HRIR_48K_24bit::azi_28_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_28_0_ele_30_0_wav};
  irMap[28][45] = {HRIR_48K_24bit::azi_28_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_28_0_ele_45_0_wav};
  irMap[28][54] = {HRIR_48K_24bit::azi_28_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_28_0_ele_54_0_wav};
  irMap[28][60] = {HRIR_48K_24bit::azi_28_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_28_0_ele_60_0_wav};
  irMap[28][75] = {HRIR_48K_24bit::azi_28_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_28_0_ele_75_0_wav};
  irMap[28][90] = {HRIR_48K_24bit::azi_28_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_28_0_ele_90_0_wav};
  irMap[28][-15] = {HRIR_48K_24bit::azi_28_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_28_0_ele_neg15_0_wav};
  irMap[28][-25] = {HRIR_48K_24bit::azi_28_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_28_0_ele_neg25_0_wav};
  irMap[28][-30] = {HRIR_48K_24bit::azi_28_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_28_0_ele_neg30_0_wav};
  irMap[28][-45] = {HRIR_48K_24bit::azi_28_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_28_0_ele_neg45_0_wav};
  irMap[28][-54] = {HRIR_48K_24bit::azi_28_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_28_0_ele_neg54_0_wav};
  irMap[28][-60] = {HRIR_48K_24bit::azi_28_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_28_0_ele_neg60_0_wav};
  irMap[28][-75] = {HRIR_48K_24bit::azi_28_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_28_0_ele_neg75_0_wav};
  irMap[28][-81] = {HRIR_48K_24bit::azi_28_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_28_0_ele_neg81_0_wav};
  irMap[29][0] = {HRIR_48K_24bit::azi_29_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_29_0_ele_0_0_wav};
  irMap[29][15] = {HRIR_48K_24bit::azi_29_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_29_0_ele_15_0_wav};
  irMap[29][25] = {HRIR_48K_24bit::azi_29_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_29_0_ele_25_0_wav};
  irMap[29][30] = {HRIR_48K_24bit::azi_29_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_29_0_ele_30_0_wav};
  irMap[29][45] = {HRIR_48K_24bit::azi_29_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_29_0_ele_45_0_wav};
  irMap[29][54] = {HRIR_48K_24bit::azi_29_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_29_0_ele_54_0_wav};
  irMap[29][60] = {HRIR_48K_24bit::azi_29_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_29_0_ele_60_0_wav};
  irMap[29][75] = {HRIR_48K_24bit::azi_29_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_29_0_ele_75_0_wav};
  irMap[29][90] = {HRIR_48K_24bit::azi_29_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_29_0_ele_90_0_wav};
  irMap[29][-15] = {HRIR_48K_24bit::azi_29_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_29_0_ele_neg15_0_wav};
  irMap[29][-25] = {HRIR_48K_24bit::azi_29_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_29_0_ele_neg25_0_wav};
  irMap[29][-30] = {HRIR_48K_24bit::azi_29_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_29_0_ele_neg30_0_wav};
  irMap[29][-45] = {HRIR_48K_24bit::azi_29_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_29_0_ele_neg45_0_wav};
  irMap[29][-54] = {HRIR_48K_24bit::azi_29_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_29_0_ele_neg54_0_wav};
  irMap[29][-60] = {HRIR_48K_24bit::azi_29_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_29_0_ele_neg60_0_wav};
  irMap[29][-75] = {HRIR_48K_24bit::azi_29_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_29_0_ele_neg75_0_wav};
  irMap[29][-81] = {HRIR_48K_24bit::azi_29_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_29_0_ele_neg81_0_wav};
  irMap[30][0] = {HRIR_48K_24bit::azi_30_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_30_0_ele_0_0_wav};
  irMap[30][15] = {HRIR_48K_24bit::azi_30_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_30_0_ele_15_0_wav};
  irMap[30][25] = {HRIR_48K_24bit::azi_30_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_30_0_ele_25_0_wav};
  irMap[30][30] = {HRIR_48K_24bit::azi_30_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_30_0_ele_30_0_wav};
  irMap[30][45] = {HRIR_48K_24bit::azi_30_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_30_0_ele_45_0_wav};
  irMap[30][54] = {HRIR_48K_24bit::azi_30_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_30_0_ele_54_0_wav};
  irMap[30][60] = {HRIR_48K_24bit::azi_30_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_30_0_ele_60_0_wav};
  irMap[30][75] = {HRIR_48K_24bit::azi_30_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_30_0_ele_75_0_wav};
  irMap[30][90] = {HRIR_48K_24bit::azi_30_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_30_0_ele_90_0_wav};
  irMap[30][-15] = {HRIR_48K_24bit::azi_30_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_30_0_ele_neg15_0_wav};
  irMap[30][-25] = {HRIR_48K_24bit::azi_30_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_30_0_ele_neg25_0_wav};
  irMap[30][-30] = {HRIR_48K_24bit::azi_30_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_30_0_ele_neg30_0_wav};
  irMap[30][-45] = {HRIR_48K_24bit::azi_30_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_30_0_ele_neg45_0_wav};
  irMap[30][-54] = {HRIR_48K_24bit::azi_30_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_30_0_ele_neg54_0_wav};
  irMap[30][-60] = {HRIR_48K_24bit::azi_30_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_30_0_ele_neg60_0_wav};
  irMap[30][-75] = {HRIR_48K_24bit::azi_30_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_30_0_ele_neg75_0_wav};
  irMap[30][-81] = {HRIR_48K_24bit::azi_30_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_30_0_ele_neg81_0_wav};
  irMap[31][0] = {HRIR_48K_24bit::azi_31_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_31_0_ele_0_0_wav};
  irMap[31][15] = {HRIR_48K_24bit::azi_31_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_31_0_ele_15_0_wav};
  irMap[31][25] = {HRIR_48K_24bit::azi_31_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_31_0_ele_25_0_wav};
  irMap[31][30] = {HRIR_48K_24bit::azi_31_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_31_0_ele_30_0_wav};
  irMap[31][45] = {HRIR_48K_24bit::azi_31_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_31_0_ele_45_0_wav};
  irMap[31][54] = {HRIR_48K_24bit::azi_31_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_31_0_ele_54_0_wav};
  irMap[31][60] = {HRIR_48K_24bit::azi_31_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_31_0_ele_60_0_wav};
  irMap[31][75] = {HRIR_48K_24bit::azi_31_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_31_0_ele_75_0_wav};
  irMap[31][90] = {HRIR_48K_24bit::azi_31_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_31_0_ele_90_0_wav};
  irMap[31][-15] = {HRIR_48K_24bit::azi_31_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_31_0_ele_neg15_0_wav};
  irMap[31][-25] = {HRIR_48K_24bit::azi_31_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_31_0_ele_neg25_0_wav};
  irMap[31][-30] = {HRIR_48K_24bit::azi_31_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_31_0_ele_neg30_0_wav};
  irMap[31][-45] = {HRIR_48K_24bit::azi_31_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_31_0_ele_neg45_0_wav};
  irMap[31][-54] = {HRIR_48K_24bit::azi_31_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_31_0_ele_neg54_0_wav};
  irMap[31][-60] = {HRIR_48K_24bit::azi_31_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_31_0_ele_neg60_0_wav};
  irMap[31][-75] = {HRIR_48K_24bit::azi_31_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_31_0_ele_neg75_0_wav};
  irMap[31][-81] = {HRIR_48K_24bit::azi_31_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_31_0_ele_neg81_0_wav};
  irMap[32][0] = {HRIR_48K_24bit::azi_32_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_32_0_ele_0_0_wav};
  irMap[32][15] = {HRIR_48K_24bit::azi_32_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_32_0_ele_15_0_wav};
  irMap[32][25] = {HRIR_48K_24bit::azi_32_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_32_0_ele_25_0_wav};
  irMap[32][30] = {HRIR_48K_24bit::azi_32_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_32_0_ele_30_0_wav};
  irMap[32][45] = {HRIR_48K_24bit::azi_32_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_32_0_ele_45_0_wav};
  irMap[32][54] = {HRIR_48K_24bit::azi_32_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_32_0_ele_54_0_wav};
  irMap[32][60] = {HRIR_48K_24bit::azi_32_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_32_0_ele_60_0_wav};
  irMap[32][75] = {HRIR_48K_24bit::azi_32_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_32_0_ele_75_0_wav};
  irMap[32][90] = {HRIR_48K_24bit::azi_32_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_32_0_ele_90_0_wav};
  irMap[32][-15] = {HRIR_48K_24bit::azi_32_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_32_0_ele_neg15_0_wav};
  irMap[32][-25] = {HRIR_48K_24bit::azi_32_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_32_0_ele_neg25_0_wav};
  irMap[32][-30] = {HRIR_48K_24bit::azi_32_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_32_0_ele_neg30_0_wav};
  irMap[32][-45] = {HRIR_48K_24bit::azi_32_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_32_0_ele_neg45_0_wav};
  irMap[32][-54] = {HRIR_48K_24bit::azi_32_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_32_0_ele_neg54_0_wav};
  irMap[32][-60] = {HRIR_48K_24bit::azi_32_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_32_0_ele_neg60_0_wav};
  irMap[32][-75] = {HRIR_48K_24bit::azi_32_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_32_0_ele_neg75_0_wav};
  irMap[32][-81] = {HRIR_48K_24bit::azi_32_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_32_0_ele_neg81_0_wav};
  irMap[33][0] = {HRIR_48K_24bit::azi_33_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_33_0_ele_0_0_wav};
  irMap[33][15] = {HRIR_48K_24bit::azi_33_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_33_0_ele_15_0_wav};
  irMap[33][25] = {HRIR_48K_24bit::azi_33_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_33_0_ele_25_0_wav};
  irMap[33][30] = {HRIR_48K_24bit::azi_33_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_33_0_ele_30_0_wav};
  irMap[33][45] = {HRIR_48K_24bit::azi_33_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_33_0_ele_45_0_wav};
  irMap[33][54] = {HRIR_48K_24bit::azi_33_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_33_0_ele_54_0_wav};
  irMap[33][60] = {HRIR_48K_24bit::azi_33_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_33_0_ele_60_0_wav};
  irMap[33][75] = {HRIR_48K_24bit::azi_33_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_33_0_ele_75_0_wav};
  irMap[33][90] = {HRIR_48K_24bit::azi_33_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_33_0_ele_90_0_wav};
  irMap[33][-15] = {HRIR_48K_24bit::azi_33_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_33_0_ele_neg15_0_wav};
  irMap[33][-25] = {HRIR_48K_24bit::azi_33_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_33_0_ele_neg25_0_wav};
  irMap[33][-30] = {HRIR_48K_24bit::azi_33_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_33_0_ele_neg30_0_wav};
  irMap[33][-45] = {HRIR_48K_24bit::azi_33_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_33_0_ele_neg45_0_wav};
  irMap[33][-54] = {HRIR_48K_24bit::azi_33_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_33_0_ele_neg54_0_wav};
  irMap[33][-60] = {HRIR_48K_24bit::azi_33_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_33_0_ele_neg60_0_wav};
  irMap[33][-75] = {HRIR_48K_24bit::azi_33_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_33_0_ele_neg75_0_wav};
  irMap[33][-81] = {HRIR_48K_24bit::azi_33_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_33_0_ele_neg81_0_wav};
  irMap[34][0] = {HRIR_48K_24bit::azi_34_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_34_0_ele_0_0_wav};
  irMap[34][15] = {HRIR_48K_24bit::azi_34_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_34_0_ele_15_0_wav};
  irMap[34][25] = {HRIR_48K_24bit::azi_34_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_34_0_ele_25_0_wav};
  irMap[34][30] = {HRIR_48K_24bit::azi_34_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_34_0_ele_30_0_wav};
  irMap[34][45] = {HRIR_48K_24bit::azi_34_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_34_0_ele_45_0_wav};
  irMap[34][54] = {HRIR_48K_24bit::azi_34_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_34_0_ele_54_0_wav};
  irMap[34][60] = {HRIR_48K_24bit::azi_34_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_34_0_ele_60_0_wav};
  irMap[34][75] = {HRIR_48K_24bit::azi_34_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_34_0_ele_75_0_wav};
  irMap[34][90] = {HRIR_48K_24bit::azi_34_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_34_0_ele_90_0_wav};
  irMap[34][-15] = {HRIR_48K_24bit::azi_34_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_34_0_ele_neg15_0_wav};
  irMap[34][-25] = {HRIR_48K_24bit::azi_34_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_34_0_ele_neg25_0_wav};
  irMap[34][-30] = {HRIR_48K_24bit::azi_34_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_34_0_ele_neg30_0_wav};
  irMap[34][-45] = {HRIR_48K_24bit::azi_34_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_34_0_ele_neg45_0_wav};
  irMap[34][-54] = {HRIR_48K_24bit::azi_34_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_34_0_ele_neg54_0_wav};
  irMap[34][-60] = {HRIR_48K_24bit::azi_34_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_34_0_ele_neg60_0_wav};
  irMap[34][-75] = {HRIR_48K_24bit::azi_34_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_34_0_ele_neg75_0_wav};
  irMap[34][-81] = {HRIR_48K_24bit::azi_34_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_34_0_ele_neg81_0_wav};
  irMap[35][0] = {HRIR_48K_24bit::azi_35_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_35_0_ele_0_0_wav};
  irMap[35][15] = {HRIR_48K_24bit::azi_35_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_35_0_ele_15_0_wav};
  irMap[35][25] = {HRIR_48K_24bit::azi_35_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_35_0_ele_25_0_wav};
  irMap[35][30] = {HRIR_48K_24bit::azi_35_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_35_0_ele_30_0_wav};
  irMap[35][45] = {HRIR_48K_24bit::azi_35_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_35_0_ele_45_0_wav};
  irMap[35][54] = {HRIR_48K_24bit::azi_35_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_35_0_ele_54_0_wav};
  irMap[35][60] = {HRIR_48K_24bit::azi_35_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_35_0_ele_60_0_wav};
  irMap[35][75] = {HRIR_48K_24bit::azi_35_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_35_0_ele_75_0_wav};
  irMap[35][90] = {HRIR_48K_24bit::azi_35_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_35_0_ele_90_0_wav};
  irMap[35][-15] = {HRIR_48K_24bit::azi_35_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_35_0_ele_neg15_0_wav};
  irMap[35][-25] = {HRIR_48K_24bit::azi_35_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_35_0_ele_neg25_0_wav};
  irMap[35][-30] = {HRIR_48K_24bit::azi_35_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_35_0_ele_neg30_0_wav};
  irMap[35][-45] = {HRIR_48K_24bit::azi_35_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_35_0_ele_neg45_0_wav};
  irMap[35][-54] = {HRIR_48K_24bit::azi_35_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_35_0_ele_neg54_0_wav};
  irMap[35][-60] = {HRIR_48K_24bit::azi_35_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_35_0_ele_neg60_0_wav};
  irMap[35][-75] = {HRIR_48K_24bit::azi_35_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_35_0_ele_neg75_0_wav};
  irMap[35][-81] = {HRIR_48K_24bit::azi_35_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_35_0_ele_neg81_0_wav};
  irMap[36][0] = {HRIR_48K_24bit::azi_36_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_36_0_ele_0_0_wav};
  irMap[36][15] = {HRIR_48K_24bit::azi_36_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_36_0_ele_15_0_wav};
  irMap[36][25] = {HRIR_48K_24bit::azi_36_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_36_0_ele_25_0_wav};
  irMap[36][30] = {HRIR_48K_24bit::azi_36_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_36_0_ele_30_0_wav};
  irMap[36][45] = {HRIR_48K_24bit::azi_36_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_36_0_ele_45_0_wav};
  irMap[36][54] = {HRIR_48K_24bit::azi_36_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_36_0_ele_54_0_wav};
  irMap[36][60] = {HRIR_48K_24bit::azi_36_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_36_0_ele_60_0_wav};
  irMap[36][75] = {HRIR_48K_24bit::azi_36_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_36_0_ele_75_0_wav};
  irMap[36][90] = {HRIR_48K_24bit::azi_36_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_36_0_ele_90_0_wav};
  irMap[36][-15] = {HRIR_48K_24bit::azi_36_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_36_0_ele_neg15_0_wav};
  irMap[36][-25] = {HRIR_48K_24bit::azi_36_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_36_0_ele_neg25_0_wav};
  irMap[36][-30] = {HRIR_48K_24bit::azi_36_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_36_0_ele_neg30_0_wav};
  irMap[36][-45] = {HRIR_48K_24bit::azi_36_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_36_0_ele_neg45_0_wav};
  irMap[36][-54] = {HRIR_48K_24bit::azi_36_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_36_0_ele_neg54_0_wav};
  irMap[36][-60] = {HRIR_48K_24bit::azi_36_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_36_0_ele_neg60_0_wav};
  irMap[36][-75] = {HRIR_48K_24bit::azi_36_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_36_0_ele_neg75_0_wav};
  irMap[36][-81] = {HRIR_48K_24bit::azi_36_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_36_0_ele_neg81_0_wav};
  irMap[37][0] = {HRIR_48K_24bit::azi_37_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_37_0_ele_0_0_wav};
  irMap[37][15] = {HRIR_48K_24bit::azi_37_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_37_0_ele_15_0_wav};
  irMap[37][25] = {HRIR_48K_24bit::azi_37_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_37_0_ele_25_0_wav};
  irMap[37][30] = {HRIR_48K_24bit::azi_37_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_37_0_ele_30_0_wav};
  irMap[37][45] = {HRIR_48K_24bit::azi_37_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_37_0_ele_45_0_wav};
  irMap[37][54] = {HRIR_48K_24bit::azi_37_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_37_0_ele_54_0_wav};
  irMap[37][60] = {HRIR_48K_24bit::azi_37_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_37_0_ele_60_0_wav};
  irMap[37][75] = {HRIR_48K_24bit::azi_37_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_37_0_ele_75_0_wav};
  irMap[37][90] = {HRIR_48K_24bit::azi_37_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_37_0_ele_90_0_wav};
  irMap[37][-15] = {HRIR_48K_24bit::azi_37_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_37_0_ele_neg15_0_wav};
  irMap[37][-25] = {HRIR_48K_24bit::azi_37_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_37_0_ele_neg25_0_wav};
  irMap[37][-30] = {HRIR_48K_24bit::azi_37_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_37_0_ele_neg30_0_wav};
  irMap[37][-45] = {HRIR_48K_24bit::azi_37_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_37_0_ele_neg45_0_wav};
  irMap[37][-54] = {HRIR_48K_24bit::azi_37_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_37_0_ele_neg54_0_wav};
  irMap[37][-60] = {HRIR_48K_24bit::azi_37_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_37_0_ele_neg60_0_wav};
  irMap[37][-75] = {HRIR_48K_24bit::azi_37_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_37_0_ele_neg75_0_wav};
  irMap[37][-81] = {HRIR_48K_24bit::azi_37_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_37_0_ele_neg81_0_wav};
  irMap[38][0] = {HRIR_48K_24bit::azi_38_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_38_0_ele_0_0_wav};
  irMap[38][15] = {HRIR_48K_24bit::azi_38_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_38_0_ele_15_0_wav};
  irMap[38][25] = {HRIR_48K_24bit::azi_38_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_38_0_ele_25_0_wav};
  irMap[38][30] = {HRIR_48K_24bit::azi_38_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_38_0_ele_30_0_wav};
  irMap[38][45] = {HRIR_48K_24bit::azi_38_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_38_0_ele_45_0_wav};
  irMap[38][54] = {HRIR_48K_24bit::azi_38_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_38_0_ele_54_0_wav};
  irMap[38][60] = {HRIR_48K_24bit::azi_38_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_38_0_ele_60_0_wav};
  irMap[38][75] = {HRIR_48K_24bit::azi_38_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_38_0_ele_75_0_wav};
  irMap[38][90] = {HRIR_48K_24bit::azi_38_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_38_0_ele_90_0_wav};
  irMap[38][-15] = {HRIR_48K_24bit::azi_38_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_38_0_ele_neg15_0_wav};
  irMap[38][-25] = {HRIR_48K_24bit::azi_38_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_38_0_ele_neg25_0_wav};
  irMap[38][-30] = {HRIR_48K_24bit::azi_38_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_38_0_ele_neg30_0_wav};
  irMap[38][-45] = {HRIR_48K_24bit::azi_38_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_38_0_ele_neg45_0_wav};
  irMap[38][-54] = {HRIR_48K_24bit::azi_38_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_38_0_ele_neg54_0_wav};
  irMap[38][-60] = {HRIR_48K_24bit::azi_38_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_38_0_ele_neg60_0_wav};
  irMap[38][-75] = {HRIR_48K_24bit::azi_38_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_38_0_ele_neg75_0_wav};
  irMap[38][-81] = {HRIR_48K_24bit::azi_38_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_38_0_ele_neg81_0_wav};
  irMap[39][0] = {HRIR_48K_24bit::azi_39_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_39_0_ele_0_0_wav};
  irMap[39][15] = {HRIR_48K_24bit::azi_39_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_39_0_ele_15_0_wav};
  irMap[39][25] = {HRIR_48K_24bit::azi_39_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_39_0_ele_25_0_wav};
  irMap[39][30] = {HRIR_48K_24bit::azi_39_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_39_0_ele_30_0_wav};
  irMap[39][45] = {HRIR_48K_24bit::azi_39_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_39_0_ele_45_0_wav};
  irMap[39][54] = {HRIR_48K_24bit::azi_39_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_39_0_ele_54_0_wav};
  irMap[39][60] = {HRIR_48K_24bit::azi_39_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_39_0_ele_60_0_wav};
  irMap[39][75] = {HRIR_48K_24bit::azi_39_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_39_0_ele_75_0_wav};
  irMap[39][90] = {HRIR_48K_24bit::azi_39_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_39_0_ele_90_0_wav};
  irMap[39][-15] = {HRIR_48K_24bit::azi_39_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_39_0_ele_neg15_0_wav};
  irMap[39][-25] = {HRIR_48K_24bit::azi_39_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_39_0_ele_neg25_0_wav};
  irMap[39][-30] = {HRIR_48K_24bit::azi_39_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_39_0_ele_neg30_0_wav};
  irMap[39][-45] = {HRIR_48K_24bit::azi_39_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_39_0_ele_neg45_0_wav};
  irMap[39][-54] = {HRIR_48K_24bit::azi_39_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_39_0_ele_neg54_0_wav};
  irMap[39][-60] = {HRIR_48K_24bit::azi_39_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_39_0_ele_neg60_0_wav};
  irMap[39][-75] = {HRIR_48K_24bit::azi_39_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_39_0_ele_neg75_0_wav};
  irMap[39][-81] = {HRIR_48K_24bit::azi_39_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_39_0_ele_neg81_0_wav};
  irMap[40][0] = {HRIR_48K_24bit::azi_40_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_40_0_ele_0_0_wav};
  irMap[40][15] = {HRIR_48K_24bit::azi_40_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_40_0_ele_15_0_wav};
  irMap[40][25] = {HRIR_48K_24bit::azi_40_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_40_0_ele_25_0_wav};
  irMap[40][30] = {HRIR_48K_24bit::azi_40_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_40_0_ele_30_0_wav};
  irMap[40][45] = {HRIR_48K_24bit::azi_40_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_40_0_ele_45_0_wav};
  irMap[40][54] = {HRIR_48K_24bit::azi_40_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_40_0_ele_54_0_wav};
  irMap[40][60] = {HRIR_48K_24bit::azi_40_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_40_0_ele_60_0_wav};
  irMap[40][75] = {HRIR_48K_24bit::azi_40_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_40_0_ele_75_0_wav};
  irMap[40][90] = {HRIR_48K_24bit::azi_40_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_40_0_ele_90_0_wav};
  irMap[40][-15] = {HRIR_48K_24bit::azi_40_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_40_0_ele_neg15_0_wav};
  irMap[40][-25] = {HRIR_48K_24bit::azi_40_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_40_0_ele_neg25_0_wav};
  irMap[40][-30] = {HRIR_48K_24bit::azi_40_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_40_0_ele_neg30_0_wav};
  irMap[40][-45] = {HRIR_48K_24bit::azi_40_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_40_0_ele_neg45_0_wav};
  irMap[40][-54] = {HRIR_48K_24bit::azi_40_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_40_0_ele_neg54_0_wav};
  irMap[40][-60] = {HRIR_48K_24bit::azi_40_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_40_0_ele_neg60_0_wav};
  irMap[40][-75] = {HRIR_48K_24bit::azi_40_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_40_0_ele_neg75_0_wav};
  irMap[40][-81] = {HRIR_48K_24bit::azi_40_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_40_0_ele_neg81_0_wav};
  irMap[41][0] = {HRIR_48K_24bit::azi_41_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_41_0_ele_0_0_wav};
  irMap[41][15] = {HRIR_48K_24bit::azi_41_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_41_0_ele_15_0_wav};
  irMap[41][25] = {HRIR_48K_24bit::azi_41_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_41_0_ele_25_0_wav};
  irMap[41][30] = {HRIR_48K_24bit::azi_41_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_41_0_ele_30_0_wav};
  irMap[41][45] = {HRIR_48K_24bit::azi_41_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_41_0_ele_45_0_wav};
  irMap[41][54] = {HRIR_48K_24bit::azi_41_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_41_0_ele_54_0_wav};
  irMap[41][60] = {HRIR_48K_24bit::azi_41_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_41_0_ele_60_0_wav};
  irMap[41][75] = {HRIR_48K_24bit::azi_41_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_41_0_ele_75_0_wav};
  irMap[41][90] = {HRIR_48K_24bit::azi_41_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_41_0_ele_90_0_wav};
  irMap[41][-15] = {HRIR_48K_24bit::azi_41_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_41_0_ele_neg15_0_wav};
  irMap[41][-25] = {HRIR_48K_24bit::azi_41_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_41_0_ele_neg25_0_wav};
  irMap[41][-30] = {HRIR_48K_24bit::azi_41_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_41_0_ele_neg30_0_wav};
  irMap[41][-45] = {HRIR_48K_24bit::azi_41_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_41_0_ele_neg45_0_wav};
  irMap[41][-54] = {HRIR_48K_24bit::azi_41_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_41_0_ele_neg54_0_wav};
  irMap[41][-60] = {HRIR_48K_24bit::azi_41_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_41_0_ele_neg60_0_wav};
  irMap[41][-75] = {HRIR_48K_24bit::azi_41_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_41_0_ele_neg75_0_wav};
  irMap[41][-81] = {HRIR_48K_24bit::azi_41_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_41_0_ele_neg81_0_wav};
  irMap[42][0] = {HRIR_48K_24bit::azi_42_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_42_0_ele_0_0_wav};
  irMap[42][15] = {HRIR_48K_24bit::azi_42_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_42_0_ele_15_0_wav};
  irMap[42][25] = {HRIR_48K_24bit::azi_42_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_42_0_ele_25_0_wav};
  irMap[42][30] = {HRIR_48K_24bit::azi_42_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_42_0_ele_30_0_wav};
  irMap[42][45] = {HRIR_48K_24bit::azi_42_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_42_0_ele_45_0_wav};
  irMap[42][54] = {HRIR_48K_24bit::azi_42_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_42_0_ele_54_0_wav};
  irMap[42][60] = {HRIR_48K_24bit::azi_42_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_42_0_ele_60_0_wav};
  irMap[42][75] = {HRIR_48K_24bit::azi_42_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_42_0_ele_75_0_wav};
  irMap[42][90] = {HRIR_48K_24bit::azi_42_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_42_0_ele_90_0_wav};
  irMap[42][-15] = {HRIR_48K_24bit::azi_42_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_42_0_ele_neg15_0_wav};
  irMap[42][-25] = {HRIR_48K_24bit::azi_42_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_42_0_ele_neg25_0_wav};
  irMap[42][-30] = {HRIR_48K_24bit::azi_42_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_42_0_ele_neg30_0_wav};
  irMap[42][-45] = {HRIR_48K_24bit::azi_42_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_42_0_ele_neg45_0_wav};
  irMap[42][-54] = {HRIR_48K_24bit::azi_42_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_42_0_ele_neg54_0_wav};
  irMap[42][-60] = {HRIR_48K_24bit::azi_42_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_42_0_ele_neg60_0_wav};
  irMap[42][-75] = {HRIR_48K_24bit::azi_42_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_42_0_ele_neg75_0_wav};
  irMap[42][-81] = {HRIR_48K_24bit::azi_42_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_42_0_ele_neg81_0_wav};
  irMap[43][0] = {HRIR_48K_24bit::azi_43_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_43_0_ele_0_0_wav};
  irMap[43][15] = {HRIR_48K_24bit::azi_43_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_43_0_ele_15_0_wav};
  irMap[43][25] = {HRIR_48K_24bit::azi_43_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_43_0_ele_25_0_wav};
  irMap[43][30] = {HRIR_48K_24bit::azi_43_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_43_0_ele_30_0_wav};
  irMap[43][45] = {HRIR_48K_24bit::azi_43_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_43_0_ele_45_0_wav};
  irMap[43][54] = {HRIR_48K_24bit::azi_43_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_43_0_ele_54_0_wav};
  irMap[43][60] = {HRIR_48K_24bit::azi_43_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_43_0_ele_60_0_wav};
  irMap[43][75] = {HRIR_48K_24bit::azi_43_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_43_0_ele_75_0_wav};
  irMap[43][90] = {HRIR_48K_24bit::azi_43_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_43_0_ele_90_0_wav};
  irMap[43][-15] = {HRIR_48K_24bit::azi_43_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_43_0_ele_neg15_0_wav};
  irMap[43][-25] = {HRIR_48K_24bit::azi_43_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_43_0_ele_neg25_0_wav};
  irMap[43][-30] = {HRIR_48K_24bit::azi_43_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_43_0_ele_neg30_0_wav};
  irMap[43][-45] = {HRIR_48K_24bit::azi_43_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_43_0_ele_neg45_0_wav};
  irMap[43][-54] = {HRIR_48K_24bit::azi_43_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_43_0_ele_neg54_0_wav};
  irMap[43][-60] = {HRIR_48K_24bit::azi_43_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_43_0_ele_neg60_0_wav};
  irMap[43][-75] = {HRIR_48K_24bit::azi_43_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_43_0_ele_neg75_0_wav};
  irMap[43][-81] = {HRIR_48K_24bit::azi_43_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_43_0_ele_neg81_0_wav};
  irMap[44][0] = {HRIR_48K_24bit::azi_44_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_44_0_ele_0_0_wav};
  irMap[44][15] = {HRIR_48K_24bit::azi_44_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_44_0_ele_15_0_wav};
  irMap[44][25] = {HRIR_48K_24bit::azi_44_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_44_0_ele_25_0_wav};
  irMap[44][30] = {HRIR_48K_24bit::azi_44_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_44_0_ele_30_0_wav};
  irMap[44][45] = {HRIR_48K_24bit::azi_44_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_44_0_ele_45_0_wav};
  irMap[44][54] = {HRIR_48K_24bit::azi_44_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_44_0_ele_54_0_wav};
  irMap[44][60] = {HRIR_48K_24bit::azi_44_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_44_0_ele_60_0_wav};
  irMap[44][75] = {HRIR_48K_24bit::azi_44_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_44_0_ele_75_0_wav};
  irMap[44][90] = {HRIR_48K_24bit::azi_44_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_44_0_ele_90_0_wav};
  irMap[44][-15] = {HRIR_48K_24bit::azi_44_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_44_0_ele_neg15_0_wav};
  irMap[44][-25] = {HRIR_48K_24bit::azi_44_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_44_0_ele_neg25_0_wav};
  irMap[44][-30] = {HRIR_48K_24bit::azi_44_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_44_0_ele_neg30_0_wav};
  irMap[44][-45] = {HRIR_48K_24bit::azi_44_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_44_0_ele_neg45_0_wav};
  irMap[44][-54] = {HRIR_48K_24bit::azi_44_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_44_0_ele_neg54_0_wav};
  irMap[44][-60] = {HRIR_48K_24bit::azi_44_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_44_0_ele_neg60_0_wav};
  irMap[44][-75] = {HRIR_48K_24bit::azi_44_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_44_0_ele_neg75_0_wav};
  irMap[44][-81] = {HRIR_48K_24bit::azi_44_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_44_0_ele_neg81_0_wav};
  irMap[45][0] = {HRIR_48K_24bit::azi_45_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_45_0_ele_0_0_wav};
  irMap[45][15] = {HRIR_48K_24bit::azi_45_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_45_0_ele_15_0_wav};
  irMap[45][25] = {HRIR_48K_24bit::azi_45_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_45_0_ele_25_0_wav};
  irMap[45][30] = {HRIR_48K_24bit::azi_45_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_45_0_ele_30_0_wav};
  irMap[45][45] = {HRIR_48K_24bit::azi_45_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_45_0_ele_45_0_wav};
  irMap[45][54] = {HRIR_48K_24bit::azi_45_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_45_0_ele_54_0_wav};
  irMap[45][60] = {HRIR_48K_24bit::azi_45_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_45_0_ele_60_0_wav};
  irMap[45][75] = {HRIR_48K_24bit::azi_45_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_45_0_ele_75_0_wav};
  irMap[45][90] = {HRIR_48K_24bit::azi_45_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_45_0_ele_90_0_wav};
  irMap[45][-15] = {HRIR_48K_24bit::azi_45_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_45_0_ele_neg15_0_wav};
  irMap[45][-25] = {HRIR_48K_24bit::azi_45_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_45_0_ele_neg25_0_wav};
  irMap[45][-30] = {HRIR_48K_24bit::azi_45_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_45_0_ele_neg30_0_wav};
  irMap[45][-45] = {HRIR_48K_24bit::azi_45_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_45_0_ele_neg45_0_wav};
  irMap[45][-54] = {HRIR_48K_24bit::azi_45_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_45_0_ele_neg54_0_wav};
  irMap[45][-60] = {HRIR_48K_24bit::azi_45_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_45_0_ele_neg60_0_wav};
  irMap[45][-75] = {HRIR_48K_24bit::azi_45_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_45_0_ele_neg75_0_wav};
  irMap[45][-81] = {HRIR_48K_24bit::azi_45_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_45_0_ele_neg81_0_wav};
  irMap[46][0] = {HRIR_48K_24bit::azi_46_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_46_0_ele_0_0_wav};
  irMap[46][15] = {HRIR_48K_24bit::azi_46_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_46_0_ele_15_0_wav};
  irMap[46][25] = {HRIR_48K_24bit::azi_46_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_46_0_ele_25_0_wav};
  irMap[46][30] = {HRIR_48K_24bit::azi_46_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_46_0_ele_30_0_wav};
  irMap[46][45] = {HRIR_48K_24bit::azi_46_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_46_0_ele_45_0_wav};
  irMap[46][54] = {HRIR_48K_24bit::azi_46_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_46_0_ele_54_0_wav};
  irMap[46][60] = {HRIR_48K_24bit::azi_46_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_46_0_ele_60_0_wav};
  irMap[46][75] = {HRIR_48K_24bit::azi_46_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_46_0_ele_75_0_wav};
  irMap[46][90] = {HRIR_48K_24bit::azi_46_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_46_0_ele_90_0_wav};
  irMap[46][-15] = {HRIR_48K_24bit::azi_46_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_46_0_ele_neg15_0_wav};
  irMap[46][-25] = {HRIR_48K_24bit::azi_46_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_46_0_ele_neg25_0_wav};
  irMap[46][-30] = {HRIR_48K_24bit::azi_46_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_46_0_ele_neg30_0_wav};
  irMap[46][-45] = {HRIR_48K_24bit::azi_46_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_46_0_ele_neg45_0_wav};
  irMap[46][-54] = {HRIR_48K_24bit::azi_46_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_46_0_ele_neg54_0_wav};
  irMap[46][-60] = {HRIR_48K_24bit::azi_46_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_46_0_ele_neg60_0_wav};
  irMap[46][-75] = {HRIR_48K_24bit::azi_46_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_46_0_ele_neg75_0_wav};
  irMap[46][-81] = {HRIR_48K_24bit::azi_46_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_46_0_ele_neg81_0_wav};
  irMap[47][0] = {HRIR_48K_24bit::azi_47_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_47_0_ele_0_0_wav};
  irMap[47][15] = {HRIR_48K_24bit::azi_47_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_47_0_ele_15_0_wav};
  irMap[47][25] = {HRIR_48K_24bit::azi_47_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_47_0_ele_25_0_wav};
  irMap[47][30] = {HRIR_48K_24bit::azi_47_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_47_0_ele_30_0_wav};
  irMap[47][45] = {HRIR_48K_24bit::azi_47_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_47_0_ele_45_0_wav};
  irMap[47][54] = {HRIR_48K_24bit::azi_47_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_47_0_ele_54_0_wav};
  irMap[47][60] = {HRIR_48K_24bit::azi_47_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_47_0_ele_60_0_wav};
  irMap[47][75] = {HRIR_48K_24bit::azi_47_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_47_0_ele_75_0_wav};
  irMap[47][90] = {HRIR_48K_24bit::azi_47_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_47_0_ele_90_0_wav};
  irMap[47][-15] = {HRIR_48K_24bit::azi_47_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_47_0_ele_neg15_0_wav};
  irMap[47][-25] = {HRIR_48K_24bit::azi_47_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_47_0_ele_neg25_0_wav};
  irMap[47][-30] = {HRIR_48K_24bit::azi_47_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_47_0_ele_neg30_0_wav};
  irMap[47][-45] = {HRIR_48K_24bit::azi_47_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_47_0_ele_neg45_0_wav};
  irMap[47][-54] = {HRIR_48K_24bit::azi_47_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_47_0_ele_neg54_0_wav};
  irMap[47][-60] = {HRIR_48K_24bit::azi_47_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_47_0_ele_neg60_0_wav};
  irMap[47][-75] = {HRIR_48K_24bit::azi_47_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_47_0_ele_neg75_0_wav};
  irMap[47][-81] = {HRIR_48K_24bit::azi_47_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_47_0_ele_neg81_0_wav};
  irMap[48][0] = {HRIR_48K_24bit::azi_48_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_48_0_ele_0_0_wav};
  irMap[48][15] = {HRIR_48K_24bit::azi_48_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_48_0_ele_15_0_wav};
  irMap[48][25] = {HRIR_48K_24bit::azi_48_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_48_0_ele_25_0_wav};
  irMap[48][30] = {HRIR_48K_24bit::azi_48_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_48_0_ele_30_0_wav};
  irMap[48][45] = {HRIR_48K_24bit::azi_48_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_48_0_ele_45_0_wav};
  irMap[48][54] = {HRIR_48K_24bit::azi_48_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_48_0_ele_54_0_wav};
  irMap[48][60] = {HRIR_48K_24bit::azi_48_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_48_0_ele_60_0_wav};
  irMap[48][75] = {HRIR_48K_24bit::azi_48_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_48_0_ele_75_0_wav};
  irMap[48][90] = {HRIR_48K_24bit::azi_48_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_48_0_ele_90_0_wav};
  irMap[48][-15] = {HRIR_48K_24bit::azi_48_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_48_0_ele_neg15_0_wav};
  irMap[48][-25] = {HRIR_48K_24bit::azi_48_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_48_0_ele_neg25_0_wav};
  irMap[48][-30] = {HRIR_48K_24bit::azi_48_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_48_0_ele_neg30_0_wav};
  irMap[48][-45] = {HRIR_48K_24bit::azi_48_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_48_0_ele_neg45_0_wav};
  irMap[48][-54] = {HRIR_48K_24bit::azi_48_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_48_0_ele_neg54_0_wav};
  irMap[48][-60] = {HRIR_48K_24bit::azi_48_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_48_0_ele_neg60_0_wav};
  irMap[48][-75] = {HRIR_48K_24bit::azi_48_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_48_0_ele_neg75_0_wav};
  irMap[48][-81] = {HRIR_48K_24bit::azi_48_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_48_0_ele_neg81_0_wav};
  irMap[49][0] = {HRIR_48K_24bit::azi_49_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_49_0_ele_0_0_wav};
  irMap[49][15] = {HRIR_48K_24bit::azi_49_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_49_0_ele_15_0_wav};
  irMap[49][25] = {HRIR_48K_24bit::azi_49_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_49_0_ele_25_0_wav};
  irMap[49][30] = {HRIR_48K_24bit::azi_49_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_49_0_ele_30_0_wav};
  irMap[49][45] = {HRIR_48K_24bit::azi_49_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_49_0_ele_45_0_wav};
  irMap[49][54] = {HRIR_48K_24bit::azi_49_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_49_0_ele_54_0_wav};
  irMap[49][60] = {HRIR_48K_24bit::azi_49_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_49_0_ele_60_0_wav};
  irMap[49][75] = {HRIR_48K_24bit::azi_49_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_49_0_ele_75_0_wav};
  irMap[49][90] = {HRIR_48K_24bit::azi_49_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_49_0_ele_90_0_wav};
  irMap[49][-15] = {HRIR_48K_24bit::azi_49_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_49_0_ele_neg15_0_wav};
  irMap[49][-25] = {HRIR_48K_24bit::azi_49_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_49_0_ele_neg25_0_wav};
  irMap[49][-30] = {HRIR_48K_24bit::azi_49_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_49_0_ele_neg30_0_wav};
  irMap[49][-45] = {HRIR_48K_24bit::azi_49_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_49_0_ele_neg45_0_wav};
  irMap[49][-54] = {HRIR_48K_24bit::azi_49_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_49_0_ele_neg54_0_wav};
  irMap[49][-60] = {HRIR_48K_24bit::azi_49_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_49_0_ele_neg60_0_wav};
  irMap[49][-75] = {HRIR_48K_24bit::azi_49_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_49_0_ele_neg75_0_wav};
  irMap[49][-81] = {HRIR_48K_24bit::azi_49_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_49_0_ele_neg81_0_wav};
  irMap[50][0] = {HRIR_48K_24bit::azi_50_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_50_0_ele_0_0_wav};
  irMap[50][15] = {HRIR_48K_24bit::azi_50_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_50_0_ele_15_0_wav};
  irMap[50][25] = {HRIR_48K_24bit::azi_50_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_50_0_ele_25_0_wav};
  irMap[50][30] = {HRIR_48K_24bit::azi_50_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_50_0_ele_30_0_wav};
  irMap[50][45] = {HRIR_48K_24bit::azi_50_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_50_0_ele_45_0_wav};
  irMap[50][54] = {HRIR_48K_24bit::azi_50_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_50_0_ele_54_0_wav};
  irMap[50][60] = {HRIR_48K_24bit::azi_50_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_50_0_ele_60_0_wav};
  irMap[50][75] = {HRIR_48K_24bit::azi_50_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_50_0_ele_75_0_wav};
  irMap[50][90] = {HRIR_48K_24bit::azi_50_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_50_0_ele_90_0_wav};
  irMap[50][-15] = {HRIR_48K_24bit::azi_50_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_50_0_ele_neg15_0_wav};
  irMap[50][-25] = {HRIR_48K_24bit::azi_50_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_50_0_ele_neg25_0_wav};
  irMap[50][-30] = {HRIR_48K_24bit::azi_50_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_50_0_ele_neg30_0_wav};
  irMap[50][-45] = {HRIR_48K_24bit::azi_50_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_50_0_ele_neg45_0_wav};
  irMap[50][-54] = {HRIR_48K_24bit::azi_50_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_50_0_ele_neg54_0_wav};
  irMap[50][-60] = {HRIR_48K_24bit::azi_50_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_50_0_ele_neg60_0_wav};
  irMap[50][-75] = {HRIR_48K_24bit::azi_50_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_50_0_ele_neg75_0_wav};
  irMap[50][-81] = {HRIR_48K_24bit::azi_50_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_50_0_ele_neg81_0_wav};
  irMap[51][0] = {HRIR_48K_24bit::azi_51_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_51_0_ele_0_0_wav};
  irMap[51][15] = {HRIR_48K_24bit::azi_51_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_51_0_ele_15_0_wav};
  irMap[51][25] = {HRIR_48K_24bit::azi_51_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_51_0_ele_25_0_wav};
  irMap[51][30] = {HRIR_48K_24bit::azi_51_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_51_0_ele_30_0_wav};
  irMap[51][45] = {HRIR_48K_24bit::azi_51_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_51_0_ele_45_0_wav};
  irMap[51][54] = {HRIR_48K_24bit::azi_51_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_51_0_ele_54_0_wav};
  irMap[51][60] = {HRIR_48K_24bit::azi_51_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_51_0_ele_60_0_wav};
  irMap[51][75] = {HRIR_48K_24bit::azi_51_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_51_0_ele_75_0_wav};
  irMap[51][90] = {HRIR_48K_24bit::azi_51_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_51_0_ele_90_0_wav};
  irMap[51][-15] = {HRIR_48K_24bit::azi_51_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_51_0_ele_neg15_0_wav};
  irMap[51][-25] = {HRIR_48K_24bit::azi_51_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_51_0_ele_neg25_0_wav};
  irMap[51][-30] = {HRIR_48K_24bit::azi_51_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_51_0_ele_neg30_0_wav};
  irMap[51][-45] = {HRIR_48K_24bit::azi_51_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_51_0_ele_neg45_0_wav};
  irMap[51][-54] = {HRIR_48K_24bit::azi_51_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_51_0_ele_neg54_0_wav};
  irMap[51][-60] = {HRIR_48K_24bit::azi_51_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_51_0_ele_neg60_0_wav};
  irMap[51][-75] = {HRIR_48K_24bit::azi_51_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_51_0_ele_neg75_0_wav};
  irMap[51][-81] = {HRIR_48K_24bit::azi_51_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_51_0_ele_neg81_0_wav};
  irMap[52][0] = {HRIR_48K_24bit::azi_52_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_52_0_ele_0_0_wav};
  irMap[52][15] = {HRIR_48K_24bit::azi_52_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_52_0_ele_15_0_wav};
  irMap[52][25] = {HRIR_48K_24bit::azi_52_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_52_0_ele_25_0_wav};
  irMap[52][30] = {HRIR_48K_24bit::azi_52_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_52_0_ele_30_0_wav};
  irMap[52][45] = {HRIR_48K_24bit::azi_52_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_52_0_ele_45_0_wav};
  irMap[52][54] = {HRIR_48K_24bit::azi_52_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_52_0_ele_54_0_wav};
  irMap[52][60] = {HRIR_48K_24bit::azi_52_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_52_0_ele_60_0_wav};
  irMap[52][75] = {HRIR_48K_24bit::azi_52_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_52_0_ele_75_0_wav};
  irMap[52][90] = {HRIR_48K_24bit::azi_52_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_52_0_ele_90_0_wav};
  irMap[52][-15] = {HRIR_48K_24bit::azi_52_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_52_0_ele_neg15_0_wav};
  irMap[52][-25] = {HRIR_48K_24bit::azi_52_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_52_0_ele_neg25_0_wav};
  irMap[52][-30] = {HRIR_48K_24bit::azi_52_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_52_0_ele_neg30_0_wav};
  irMap[52][-45] = {HRIR_48K_24bit::azi_52_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_52_0_ele_neg45_0_wav};
  irMap[52][-54] = {HRIR_48K_24bit::azi_52_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_52_0_ele_neg54_0_wav};
  irMap[52][-60] = {HRIR_48K_24bit::azi_52_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_52_0_ele_neg60_0_wav};
  irMap[52][-75] = {HRIR_48K_24bit::azi_52_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_52_0_ele_neg75_0_wav};
  irMap[52][-81] = {HRIR_48K_24bit::azi_52_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_52_0_ele_neg81_0_wav};
  irMap[53][0] = {HRIR_48K_24bit::azi_53_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_53_0_ele_0_0_wav};
  irMap[53][15] = {HRIR_48K_24bit::azi_53_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_53_0_ele_15_0_wav};
  irMap[53][25] = {HRIR_48K_24bit::azi_53_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_53_0_ele_25_0_wav};
  irMap[53][30] = {HRIR_48K_24bit::azi_53_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_53_0_ele_30_0_wav};
  irMap[53][45] = {HRIR_48K_24bit::azi_53_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_53_0_ele_45_0_wav};
  irMap[53][54] = {HRIR_48K_24bit::azi_53_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_53_0_ele_54_0_wav};
  irMap[53][60] = {HRIR_48K_24bit::azi_53_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_53_0_ele_60_0_wav};
  irMap[53][75] = {HRIR_48K_24bit::azi_53_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_53_0_ele_75_0_wav};
  irMap[53][90] = {HRIR_48K_24bit::azi_53_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_53_0_ele_90_0_wav};
  irMap[53][-15] = {HRIR_48K_24bit::azi_53_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_53_0_ele_neg15_0_wav};
  irMap[53][-25] = {HRIR_48K_24bit::azi_53_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_53_0_ele_neg25_0_wav};
  irMap[53][-30] = {HRIR_48K_24bit::azi_53_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_53_0_ele_neg30_0_wav};
  irMap[53][-45] = {HRIR_48K_24bit::azi_53_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_53_0_ele_neg45_0_wav};
  irMap[53][-54] = {HRIR_48K_24bit::azi_53_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_53_0_ele_neg54_0_wav};
  irMap[53][-60] = {HRIR_48K_24bit::azi_53_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_53_0_ele_neg60_0_wav};
  irMap[53][-75] = {HRIR_48K_24bit::azi_53_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_53_0_ele_neg75_0_wav};
  irMap[53][-81] = {HRIR_48K_24bit::azi_53_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_53_0_ele_neg81_0_wav};
  irMap[54][0] = {HRIR_48K_24bit::azi_54_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_54_0_ele_0_0_wav};
  irMap[54][15] = {HRIR_48K_24bit::azi_54_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_54_0_ele_15_0_wav};
  irMap[54][25] = {HRIR_48K_24bit::azi_54_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_54_0_ele_25_0_wav};
  irMap[54][30] = {HRIR_48K_24bit::azi_54_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_54_0_ele_30_0_wav};
  irMap[54][45] = {HRIR_48K_24bit::azi_54_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_54_0_ele_45_0_wav};
  irMap[54][54] = {HRIR_48K_24bit::azi_54_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_54_0_ele_54_0_wav};
  irMap[54][60] = {HRIR_48K_24bit::azi_54_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_54_0_ele_60_0_wav};
  irMap[54][75] = {HRIR_48K_24bit::azi_54_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_54_0_ele_75_0_wav};
  irMap[54][90] = {HRIR_48K_24bit::azi_54_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_54_0_ele_90_0_wav};
  irMap[54][-15] = {HRIR_48K_24bit::azi_54_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_54_0_ele_neg15_0_wav};
  irMap[54][-25] = {HRIR_48K_24bit::azi_54_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_54_0_ele_neg25_0_wav};
  irMap[54][-30] = {HRIR_48K_24bit::azi_54_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_54_0_ele_neg30_0_wav};
  irMap[54][-45] = {HRIR_48K_24bit::azi_54_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_54_0_ele_neg45_0_wav};
  irMap[54][-54] = {HRIR_48K_24bit::azi_54_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_54_0_ele_neg54_0_wav};
  irMap[54][-60] = {HRIR_48K_24bit::azi_54_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_54_0_ele_neg60_0_wav};
  irMap[54][-75] = {HRIR_48K_24bit::azi_54_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_54_0_ele_neg75_0_wav};
  irMap[54][-81] = {HRIR_48K_24bit::azi_54_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_54_0_ele_neg81_0_wav};
  irMap[55][0] = {HRIR_48K_24bit::azi_55_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_55_0_ele_0_0_wav};
  irMap[55][15] = {HRIR_48K_24bit::azi_55_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_55_0_ele_15_0_wav};
  irMap[55][25] = {HRIR_48K_24bit::azi_55_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_55_0_ele_25_0_wav};
  irMap[55][30] = {HRIR_48K_24bit::azi_55_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_55_0_ele_30_0_wav};
  irMap[55][45] = {HRIR_48K_24bit::azi_55_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_55_0_ele_45_0_wav};
  irMap[55][54] = {HRIR_48K_24bit::azi_55_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_55_0_ele_54_0_wav};
  irMap[55][60] = {HRIR_48K_24bit::azi_55_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_55_0_ele_60_0_wav};
  irMap[55][75] = {HRIR_48K_24bit::azi_55_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_55_0_ele_75_0_wav};
  irMap[55][90] = {HRIR_48K_24bit::azi_55_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_55_0_ele_90_0_wav};
  irMap[55][-15] = {HRIR_48K_24bit::azi_55_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_55_0_ele_neg15_0_wav};
  irMap[55][-25] = {HRIR_48K_24bit::azi_55_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_55_0_ele_neg25_0_wav};
  irMap[55][-30] = {HRIR_48K_24bit::azi_55_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_55_0_ele_neg30_0_wav};
  irMap[55][-45] = {HRIR_48K_24bit::azi_55_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_55_0_ele_neg45_0_wav};
  irMap[55][-54] = {HRIR_48K_24bit::azi_55_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_55_0_ele_neg54_0_wav};
  irMap[55][-60] = {HRIR_48K_24bit::azi_55_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_55_0_ele_neg60_0_wav};
  irMap[55][-75] = {HRIR_48K_24bit::azi_55_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_55_0_ele_neg75_0_wav};
  irMap[55][-81] = {HRIR_48K_24bit::azi_55_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_55_0_ele_neg81_0_wav};
  irMap[56][0] = {HRIR_48K_24bit::azi_56_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_56_0_ele_0_0_wav};
  irMap[56][15] = {HRIR_48K_24bit::azi_56_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_56_0_ele_15_0_wav};
  irMap[56][25] = {HRIR_48K_24bit::azi_56_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_56_0_ele_25_0_wav};
  irMap[56][30] = {HRIR_48K_24bit::azi_56_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_56_0_ele_30_0_wav};
  irMap[56][45] = {HRIR_48K_24bit::azi_56_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_56_0_ele_45_0_wav};
  irMap[56][54] = {HRIR_48K_24bit::azi_56_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_56_0_ele_54_0_wav};
  irMap[56][60] = {HRIR_48K_24bit::azi_56_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_56_0_ele_60_0_wav};
  irMap[56][75] = {HRIR_48K_24bit::azi_56_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_56_0_ele_75_0_wav};
  irMap[56][90] = {HRIR_48K_24bit::azi_56_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_56_0_ele_90_0_wav};
  irMap[56][-15] = {HRIR_48K_24bit::azi_56_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_56_0_ele_neg15_0_wav};
  irMap[56][-25] = {HRIR_48K_24bit::azi_56_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_56_0_ele_neg25_0_wav};
  irMap[56][-30] = {HRIR_48K_24bit::azi_56_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_56_0_ele_neg30_0_wav};
  irMap[56][-45] = {HRIR_48K_24bit::azi_56_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_56_0_ele_neg45_0_wav};
  irMap[56][-54] = {HRIR_48K_24bit::azi_56_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_56_0_ele_neg54_0_wav};
  irMap[56][-60] = {HRIR_48K_24bit::azi_56_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_56_0_ele_neg60_0_wav};
  irMap[56][-75] = {HRIR_48K_24bit::azi_56_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_56_0_ele_neg75_0_wav};
  irMap[56][-81] = {HRIR_48K_24bit::azi_56_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_56_0_ele_neg81_0_wav};
  irMap[57][0] = {HRIR_48K_24bit::azi_57_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_57_0_ele_0_0_wav};
  irMap[57][15] = {HRIR_48K_24bit::azi_57_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_57_0_ele_15_0_wav};
  irMap[57][25] = {HRIR_48K_24bit::azi_57_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_57_0_ele_25_0_wav};
  irMap[57][30] = {HRIR_48K_24bit::azi_57_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_57_0_ele_30_0_wav};
  irMap[57][45] = {HRIR_48K_24bit::azi_57_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_57_0_ele_45_0_wav};
  irMap[57][54] = {HRIR_48K_24bit::azi_57_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_57_0_ele_54_0_wav};
  irMap[57][60] = {HRIR_48K_24bit::azi_57_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_57_0_ele_60_0_wav};
  irMap[57][75] = {HRIR_48K_24bit::azi_57_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_57_0_ele_75_0_wav};
  irMap[57][90] = {HRIR_48K_24bit::azi_57_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_57_0_ele_90_0_wav};
  irMap[57][-15] = {HRIR_48K_24bit::azi_57_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_57_0_ele_neg15_0_wav};
  irMap[57][-25] = {HRIR_48K_24bit::azi_57_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_57_0_ele_neg25_0_wav};
  irMap[57][-30] = {HRIR_48K_24bit::azi_57_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_57_0_ele_neg30_0_wav};
  irMap[57][-45] = {HRIR_48K_24bit::azi_57_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_57_0_ele_neg45_0_wav};
  irMap[57][-54] = {HRIR_48K_24bit::azi_57_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_57_0_ele_neg54_0_wav};
  irMap[57][-60] = {HRIR_48K_24bit::azi_57_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_57_0_ele_neg60_0_wav};
  irMap[57][-75] = {HRIR_48K_24bit::azi_57_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_57_0_ele_neg75_0_wav};
  irMap[57][-81] = {HRIR_48K_24bit::azi_57_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_57_0_ele_neg81_0_wav};
  irMap[58][0] = {HRIR_48K_24bit::azi_58_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_58_0_ele_0_0_wav};
  irMap[58][15] = {HRIR_48K_24bit::azi_58_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_58_0_ele_15_0_wav};
  irMap[58][25] = {HRIR_48K_24bit::azi_58_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_58_0_ele_25_0_wav};
  irMap[58][30] = {HRIR_48K_24bit::azi_58_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_58_0_ele_30_0_wav};
  irMap[58][45] = {HRIR_48K_24bit::azi_58_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_58_0_ele_45_0_wav};
  irMap[58][54] = {HRIR_48K_24bit::azi_58_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_58_0_ele_54_0_wav};
  irMap[58][60] = {HRIR_48K_24bit::azi_58_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_58_0_ele_60_0_wav};
  irMap[58][75] = {HRIR_48K_24bit::azi_58_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_58_0_ele_75_0_wav};
  irMap[58][90] = {HRIR_48K_24bit::azi_58_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_58_0_ele_90_0_wav};
  irMap[58][-15] = {HRIR_48K_24bit::azi_58_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_58_0_ele_neg15_0_wav};
  irMap[58][-25] = {HRIR_48K_24bit::azi_58_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_58_0_ele_neg25_0_wav};
  irMap[58][-30] = {HRIR_48K_24bit::azi_58_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_58_0_ele_neg30_0_wav};
  irMap[58][-45] = {HRIR_48K_24bit::azi_58_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_58_0_ele_neg45_0_wav};
  irMap[58][-54] = {HRIR_48K_24bit::azi_58_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_58_0_ele_neg54_0_wav};
  irMap[58][-60] = {HRIR_48K_24bit::azi_58_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_58_0_ele_neg60_0_wav};
  irMap[58][-75] = {HRIR_48K_24bit::azi_58_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_58_0_ele_neg75_0_wav};
  irMap[58][-81] = {HRIR_48K_24bit::azi_58_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_58_0_ele_neg81_0_wav};
  irMap[59][0] = {HRIR_48K_24bit::azi_59_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_59_0_ele_0_0_wav};
  irMap[59][15] = {HRIR_48K_24bit::azi_59_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_59_0_ele_15_0_wav};
  irMap[59][25] = {HRIR_48K_24bit::azi_59_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_59_0_ele_25_0_wav};
  irMap[59][30] = {HRIR_48K_24bit::azi_59_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_59_0_ele_30_0_wav};
  irMap[59][45] = {HRIR_48K_24bit::azi_59_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_59_0_ele_45_0_wav};
  irMap[59][54] = {HRIR_48K_24bit::azi_59_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_59_0_ele_54_0_wav};
  irMap[59][60] = {HRIR_48K_24bit::azi_59_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_59_0_ele_60_0_wav};
  irMap[59][75] = {HRIR_48K_24bit::azi_59_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_59_0_ele_75_0_wav};
  irMap[59][90] = {HRIR_48K_24bit::azi_59_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_59_0_ele_90_0_wav};
  irMap[59][-15] = {HRIR_48K_24bit::azi_59_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_59_0_ele_neg15_0_wav};
  irMap[59][-25] = {HRIR_48K_24bit::azi_59_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_59_0_ele_neg25_0_wav};
  irMap[59][-30] = {HRIR_48K_24bit::azi_59_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_59_0_ele_neg30_0_wav};
  irMap[59][-45] = {HRIR_48K_24bit::azi_59_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_59_0_ele_neg45_0_wav};
  irMap[59][-54] = {HRIR_48K_24bit::azi_59_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_59_0_ele_neg54_0_wav};
  irMap[59][-60] = {HRIR_48K_24bit::azi_59_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_59_0_ele_neg60_0_wav};
  irMap[59][-75] = {HRIR_48K_24bit::azi_59_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_59_0_ele_neg75_0_wav};
  irMap[59][-81] = {HRIR_48K_24bit::azi_59_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_59_0_ele_neg81_0_wav};
  irMap[60][0] = {HRIR_48K_24bit::azi_60_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_60_0_ele_0_0_wav};
  irMap[60][15] = {HRIR_48K_24bit::azi_60_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_60_0_ele_15_0_wav};
  irMap[60][25] = {HRIR_48K_24bit::azi_60_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_60_0_ele_25_0_wav};
  irMap[60][30] = {HRIR_48K_24bit::azi_60_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_60_0_ele_30_0_wav};
  irMap[60][45] = {HRIR_48K_24bit::azi_60_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_60_0_ele_45_0_wav};
  irMap[60][54] = {HRIR_48K_24bit::azi_60_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_60_0_ele_54_0_wav};
  irMap[60][60] = {HRIR_48K_24bit::azi_60_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_60_0_ele_60_0_wav};
  irMap[60][75] = {HRIR_48K_24bit::azi_60_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_60_0_ele_75_0_wav};
  irMap[60][90] = {HRIR_48K_24bit::azi_60_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_60_0_ele_90_0_wav};
  irMap[60][-15] = {HRIR_48K_24bit::azi_60_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_60_0_ele_neg15_0_wav};
  irMap[60][-25] = {HRIR_48K_24bit::azi_60_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_60_0_ele_neg25_0_wav};
  irMap[60][-30] = {HRIR_48K_24bit::azi_60_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_60_0_ele_neg30_0_wav};
  irMap[60][-45] = {HRIR_48K_24bit::azi_60_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_60_0_ele_neg45_0_wav};
  irMap[60][-54] = {HRIR_48K_24bit::azi_60_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_60_0_ele_neg54_0_wav};
  irMap[60][-60] = {HRIR_48K_24bit::azi_60_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_60_0_ele_neg60_0_wav};
  irMap[60][-75] = {HRIR_48K_24bit::azi_60_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_60_0_ele_neg75_0_wav};
  irMap[60][-81] = {HRIR_48K_24bit::azi_60_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_60_0_ele_neg81_0_wav};
  irMap[61][0] = {HRIR_48K_24bit::azi_61_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_61_0_ele_0_0_wav};
  irMap[61][15] = {HRIR_48K_24bit::azi_61_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_61_0_ele_15_0_wav};
  irMap[61][25] = {HRIR_48K_24bit::azi_61_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_61_0_ele_25_0_wav};
  irMap[61][30] = {HRIR_48K_24bit::azi_61_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_61_0_ele_30_0_wav};
  irMap[61][45] = {HRIR_48K_24bit::azi_61_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_61_0_ele_45_0_wav};
  irMap[61][54] = {HRIR_48K_24bit::azi_61_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_61_0_ele_54_0_wav};
  irMap[61][60] = {HRIR_48K_24bit::azi_61_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_61_0_ele_60_0_wav};
  irMap[61][75] = {HRIR_48K_24bit::azi_61_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_61_0_ele_75_0_wav};
  irMap[61][90] = {HRIR_48K_24bit::azi_61_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_61_0_ele_90_0_wav};
  irMap[61][-15] = {HRIR_48K_24bit::azi_61_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_61_0_ele_neg15_0_wav};
  irMap[61][-25] = {HRIR_48K_24bit::azi_61_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_61_0_ele_neg25_0_wav};
  irMap[61][-30] = {HRIR_48K_24bit::azi_61_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_61_0_ele_neg30_0_wav};
  irMap[61][-45] = {HRIR_48K_24bit::azi_61_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_61_0_ele_neg45_0_wav};
  irMap[61][-54] = {HRIR_48K_24bit::azi_61_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_61_0_ele_neg54_0_wav};
  irMap[61][-60] = {HRIR_48K_24bit::azi_61_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_61_0_ele_neg60_0_wav};
  irMap[61][-75] = {HRIR_48K_24bit::azi_61_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_61_0_ele_neg75_0_wav};
  irMap[61][-81] = {HRIR_48K_24bit::azi_61_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_61_0_ele_neg81_0_wav};
  irMap[62][0] = {HRIR_48K_24bit::azi_62_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_62_0_ele_0_0_wav};
  irMap[62][15] = {HRIR_48K_24bit::azi_62_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_62_0_ele_15_0_wav};
  irMap[62][25] = {HRIR_48K_24bit::azi_62_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_62_0_ele_25_0_wav};
  irMap[62][30] = {HRIR_48K_24bit::azi_62_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_62_0_ele_30_0_wav};
  irMap[62][45] = {HRIR_48K_24bit::azi_62_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_62_0_ele_45_0_wav};
  irMap[62][54] = {HRIR_48K_24bit::azi_62_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_62_0_ele_54_0_wav};
  irMap[62][60] = {HRIR_48K_24bit::azi_62_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_62_0_ele_60_0_wav};
  irMap[62][75] = {HRIR_48K_24bit::azi_62_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_62_0_ele_75_0_wav};
  irMap[62][90] = {HRIR_48K_24bit::azi_62_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_62_0_ele_90_0_wav};
  irMap[62][-15] = {HRIR_48K_24bit::azi_62_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_62_0_ele_neg15_0_wav};
  irMap[62][-25] = {HRIR_48K_24bit::azi_62_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_62_0_ele_neg25_0_wav};
  irMap[62][-30] = {HRIR_48K_24bit::azi_62_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_62_0_ele_neg30_0_wav};
  irMap[62][-45] = {HRIR_48K_24bit::azi_62_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_62_0_ele_neg45_0_wav};
  irMap[62][-54] = {HRIR_48K_24bit::azi_62_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_62_0_ele_neg54_0_wav};
  irMap[62][-60] = {HRIR_48K_24bit::azi_62_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_62_0_ele_neg60_0_wav};
  irMap[62][-75] = {HRIR_48K_24bit::azi_62_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_62_0_ele_neg75_0_wav};
  irMap[62][-81] = {HRIR_48K_24bit::azi_62_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_62_0_ele_neg81_0_wav};
  irMap[63][0] = {HRIR_48K_24bit::azi_63_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_63_0_ele_0_0_wav};
  irMap[63][15] = {HRIR_48K_24bit::azi_63_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_63_0_ele_15_0_wav};
  irMap[63][25] = {HRIR_48K_24bit::azi_63_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_63_0_ele_25_0_wav};
  irMap[63][30] = {HRIR_48K_24bit::azi_63_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_63_0_ele_30_0_wav};
  irMap[63][45] = {HRIR_48K_24bit::azi_63_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_63_0_ele_45_0_wav};
  irMap[63][54] = {HRIR_48K_24bit::azi_63_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_63_0_ele_54_0_wav};
  irMap[63][60] = {HRIR_48K_24bit::azi_63_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_63_0_ele_60_0_wav};
  irMap[63][75] = {HRIR_48K_24bit::azi_63_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_63_0_ele_75_0_wav};
  irMap[63][90] = {HRIR_48K_24bit::azi_63_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_63_0_ele_90_0_wav};
  irMap[63][-15] = {HRIR_48K_24bit::azi_63_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_63_0_ele_neg15_0_wav};
  irMap[63][-25] = {HRIR_48K_24bit::azi_63_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_63_0_ele_neg25_0_wav};
  irMap[63][-30] = {HRIR_48K_24bit::azi_63_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_63_0_ele_neg30_0_wav};
  irMap[63][-45] = {HRIR_48K_24bit::azi_63_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_63_0_ele_neg45_0_wav};
  irMap[63][-54] = {HRIR_48K_24bit::azi_63_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_63_0_ele_neg54_0_wav};
  irMap[63][-60] = {HRIR_48K_24bit::azi_63_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_63_0_ele_neg60_0_wav};
  irMap[63][-75] = {HRIR_48K_24bit::azi_63_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_63_0_ele_neg75_0_wav};
  irMap[63][-81] = {HRIR_48K_24bit::azi_63_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_63_0_ele_neg81_0_wav};
  irMap[64][0] = {HRIR_48K_24bit::azi_64_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_64_0_ele_0_0_wav};
  irMap[64][15] = {HRIR_48K_24bit::azi_64_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_64_0_ele_15_0_wav};
  irMap[64][25] = {HRIR_48K_24bit::azi_64_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_64_0_ele_25_0_wav};
  irMap[64][30] = {HRIR_48K_24bit::azi_64_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_64_0_ele_30_0_wav};
  irMap[64][45] = {HRIR_48K_24bit::azi_64_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_64_0_ele_45_0_wav};
  irMap[64][54] = {HRIR_48K_24bit::azi_64_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_64_0_ele_54_0_wav};
  irMap[64][60] = {HRIR_48K_24bit::azi_64_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_64_0_ele_60_0_wav};
  irMap[64][75] = {HRIR_48K_24bit::azi_64_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_64_0_ele_75_0_wav};
  irMap[64][90] = {HRIR_48K_24bit::azi_64_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_64_0_ele_90_0_wav};
  irMap[64][-15] = {HRIR_48K_24bit::azi_64_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_64_0_ele_neg15_0_wav};
  irMap[64][-25] = {HRIR_48K_24bit::azi_64_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_64_0_ele_neg25_0_wav};
  irMap[64][-30] = {HRIR_48K_24bit::azi_64_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_64_0_ele_neg30_0_wav};
  irMap[64][-45] = {HRIR_48K_24bit::azi_64_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_64_0_ele_neg45_0_wav};
  irMap[64][-54] = {HRIR_48K_24bit::azi_64_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_64_0_ele_neg54_0_wav};
  irMap[64][-60] = {HRIR_48K_24bit::azi_64_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_64_0_ele_neg60_0_wav};
  irMap[64][-75] = {HRIR_48K_24bit::azi_64_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_64_0_ele_neg75_0_wav};
  irMap[64][-81] = {HRIR_48K_24bit::azi_64_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_64_0_ele_neg81_0_wav};
  irMap[65][0] = {HRIR_48K_24bit::azi_65_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_65_0_ele_0_0_wav};
  irMap[65][15] = {HRIR_48K_24bit::azi_65_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_65_0_ele_15_0_wav};
  irMap[65][25] = {HRIR_48K_24bit::azi_65_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_65_0_ele_25_0_wav};
  irMap[65][30] = {HRIR_48K_24bit::azi_65_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_65_0_ele_30_0_wav};
  irMap[65][45] = {HRIR_48K_24bit::azi_65_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_65_0_ele_45_0_wav};
  irMap[65][54] = {HRIR_48K_24bit::azi_65_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_65_0_ele_54_0_wav};
  irMap[65][60] = {HRIR_48K_24bit::azi_65_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_65_0_ele_60_0_wav};
  irMap[65][75] = {HRIR_48K_24bit::azi_65_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_65_0_ele_75_0_wav};
  irMap[65][90] = {HRIR_48K_24bit::azi_65_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_65_0_ele_90_0_wav};
  irMap[65][-15] = {HRIR_48K_24bit::azi_65_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_65_0_ele_neg15_0_wav};
  irMap[65][-25] = {HRIR_48K_24bit::azi_65_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_65_0_ele_neg25_0_wav};
  irMap[65][-30] = {HRIR_48K_24bit::azi_65_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_65_0_ele_neg30_0_wav};
  irMap[65][-45] = {HRIR_48K_24bit::azi_65_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_65_0_ele_neg45_0_wav};
  irMap[65][-54] = {HRIR_48K_24bit::azi_65_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_65_0_ele_neg54_0_wav};
  irMap[65][-60] = {HRIR_48K_24bit::azi_65_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_65_0_ele_neg60_0_wav};
  irMap[65][-75] = {HRIR_48K_24bit::azi_65_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_65_0_ele_neg75_0_wav};
  irMap[65][-81] = {HRIR_48K_24bit::azi_65_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_65_0_ele_neg81_0_wav};
  irMap[66][0] = {HRIR_48K_24bit::azi_66_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_66_0_ele_0_0_wav};
  irMap[66][15] = {HRIR_48K_24bit::azi_66_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_66_0_ele_15_0_wav};
  irMap[66][25] = {HRIR_48K_24bit::azi_66_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_66_0_ele_25_0_wav};
  irMap[66][30] = {HRIR_48K_24bit::azi_66_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_66_0_ele_30_0_wav};
  irMap[66][45] = {HRIR_48K_24bit::azi_66_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_66_0_ele_45_0_wav};
  irMap[66][54] = {HRIR_48K_24bit::azi_66_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_66_0_ele_54_0_wav};
  irMap[66][60] = {HRIR_48K_24bit::azi_66_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_66_0_ele_60_0_wav};
  irMap[66][75] = {HRIR_48K_24bit::azi_66_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_66_0_ele_75_0_wav};
  irMap[66][90] = {HRIR_48K_24bit::azi_66_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_66_0_ele_90_0_wav};
  irMap[66][-15] = {HRIR_48K_24bit::azi_66_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_66_0_ele_neg15_0_wav};
  irMap[66][-25] = {HRIR_48K_24bit::azi_66_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_66_0_ele_neg25_0_wav};
  irMap[66][-30] = {HRIR_48K_24bit::azi_66_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_66_0_ele_neg30_0_wav};
  irMap[66][-45] = {HRIR_48K_24bit::azi_66_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_66_0_ele_neg45_0_wav};
  irMap[66][-54] = {HRIR_48K_24bit::azi_66_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_66_0_ele_neg54_0_wav};
  irMap[66][-60] = {HRIR_48K_24bit::azi_66_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_66_0_ele_neg60_0_wav};
  irMap[66][-75] = {HRIR_48K_24bit::azi_66_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_66_0_ele_neg75_0_wav};
  irMap[66][-81] = {HRIR_48K_24bit::azi_66_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_66_0_ele_neg81_0_wav};
  irMap[67][0] = {HRIR_48K_24bit::azi_67_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_67_0_ele_0_0_wav};
  irMap[67][15] = {HRIR_48K_24bit::azi_67_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_67_0_ele_15_0_wav};
  irMap[67][25] = {HRIR_48K_24bit::azi_67_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_67_0_ele_25_0_wav};
  irMap[67][30] = {HRIR_48K_24bit::azi_67_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_67_0_ele_30_0_wav};
  irMap[67][45] = {HRIR_48K_24bit::azi_67_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_67_0_ele_45_0_wav};
  irMap[67][54] = {HRIR_48K_24bit::azi_67_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_67_0_ele_54_0_wav};
  irMap[67][60] = {HRIR_48K_24bit::azi_67_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_67_0_ele_60_0_wav};
  irMap[67][75] = {HRIR_48K_24bit::azi_67_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_67_0_ele_75_0_wav};
  irMap[67][90] = {HRIR_48K_24bit::azi_67_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_67_0_ele_90_0_wav};
  irMap[67][-15] = {HRIR_48K_24bit::azi_67_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_67_0_ele_neg15_0_wav};
  irMap[67][-25] = {HRIR_48K_24bit::azi_67_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_67_0_ele_neg25_0_wav};
  irMap[67][-30] = {HRIR_48K_24bit::azi_67_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_67_0_ele_neg30_0_wav};
  irMap[67][-45] = {HRIR_48K_24bit::azi_67_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_67_0_ele_neg45_0_wav};
  irMap[67][-54] = {HRIR_48K_24bit::azi_67_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_67_0_ele_neg54_0_wav};
  irMap[67][-60] = {HRIR_48K_24bit::azi_67_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_67_0_ele_neg60_0_wav};
  irMap[67][-75] = {HRIR_48K_24bit::azi_67_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_67_0_ele_neg75_0_wav};
  irMap[67][-81] = {HRIR_48K_24bit::azi_67_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_67_0_ele_neg81_0_wav};
  irMap[68][0] = {HRIR_48K_24bit::azi_68_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_68_0_ele_0_0_wav};
  irMap[68][15] = {HRIR_48K_24bit::azi_68_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_68_0_ele_15_0_wav};
  irMap[68][25] = {HRIR_48K_24bit::azi_68_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_68_0_ele_25_0_wav};
  irMap[68][30] = {HRIR_48K_24bit::azi_68_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_68_0_ele_30_0_wav};
  irMap[68][45] = {HRIR_48K_24bit::azi_68_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_68_0_ele_45_0_wav};
  irMap[68][54] = {HRIR_48K_24bit::azi_68_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_68_0_ele_54_0_wav};
  irMap[68][60] = {HRIR_48K_24bit::azi_68_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_68_0_ele_60_0_wav};
  irMap[68][75] = {HRIR_48K_24bit::azi_68_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_68_0_ele_75_0_wav};
  irMap[68][90] = {HRIR_48K_24bit::azi_68_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_68_0_ele_90_0_wav};
  irMap[68][-15] = {HRIR_48K_24bit::azi_68_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_68_0_ele_neg15_0_wav};
  irMap[68][-25] = {HRIR_48K_24bit::azi_68_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_68_0_ele_neg25_0_wav};
  irMap[68][-30] = {HRIR_48K_24bit::azi_68_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_68_0_ele_neg30_0_wav};
  irMap[68][-45] = {HRIR_48K_24bit::azi_68_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_68_0_ele_neg45_0_wav};
  irMap[68][-54] = {HRIR_48K_24bit::azi_68_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_68_0_ele_neg54_0_wav};
  irMap[68][-60] = {HRIR_48K_24bit::azi_68_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_68_0_ele_neg60_0_wav};
  irMap[68][-75] = {HRIR_48K_24bit::azi_68_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_68_0_ele_neg75_0_wav};
  irMap[68][-81] = {HRIR_48K_24bit::azi_68_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_68_0_ele_neg81_0_wav};
  irMap[69][0] = {HRIR_48K_24bit::azi_69_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_69_0_ele_0_0_wav};
  irMap[69][15] = {HRIR_48K_24bit::azi_69_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_69_0_ele_15_0_wav};
  irMap[69][25] = {HRIR_48K_24bit::azi_69_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_69_0_ele_25_0_wav};
  irMap[69][30] = {HRIR_48K_24bit::azi_69_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_69_0_ele_30_0_wav};
  irMap[69][45] = {HRIR_48K_24bit::azi_69_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_69_0_ele_45_0_wav};
  irMap[69][54] = {HRIR_48K_24bit::azi_69_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_69_0_ele_54_0_wav};
  irMap[69][60] = {HRIR_48K_24bit::azi_69_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_69_0_ele_60_0_wav};
  irMap[69][75] = {HRIR_48K_24bit::azi_69_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_69_0_ele_75_0_wav};
  irMap[69][90] = {HRIR_48K_24bit::azi_69_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_69_0_ele_90_0_wav};
  irMap[69][-15] = {HRIR_48K_24bit::azi_69_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_69_0_ele_neg15_0_wav};
  irMap[69][-25] = {HRIR_48K_24bit::azi_69_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_69_0_ele_neg25_0_wav};
  irMap[69][-30] = {HRIR_48K_24bit::azi_69_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_69_0_ele_neg30_0_wav};
  irMap[69][-45] = {HRIR_48K_24bit::azi_69_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_69_0_ele_neg45_0_wav};
  irMap[69][-54] = {HRIR_48K_24bit::azi_69_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_69_0_ele_neg54_0_wav};
  irMap[69][-60] = {HRIR_48K_24bit::azi_69_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_69_0_ele_neg60_0_wav};
  irMap[69][-75] = {HRIR_48K_24bit::azi_69_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_69_0_ele_neg75_0_wav};
  irMap[69][-81] = {HRIR_48K_24bit::azi_69_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_69_0_ele_neg81_0_wav};
  irMap[70][0] = {HRIR_48K_24bit::azi_70_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_70_0_ele_0_0_wav};
  irMap[70][15] = {HRIR_48K_24bit::azi_70_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_70_0_ele_15_0_wav};
  irMap[70][25] = {HRIR_48K_24bit::azi_70_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_70_0_ele_25_0_wav};
  irMap[70][30] = {HRIR_48K_24bit::azi_70_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_70_0_ele_30_0_wav};
  irMap[70][45] = {HRIR_48K_24bit::azi_70_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_70_0_ele_45_0_wav};
  irMap[70][54] = {HRIR_48K_24bit::azi_70_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_70_0_ele_54_0_wav};
  irMap[70][60] = {HRIR_48K_24bit::azi_70_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_70_0_ele_60_0_wav};
  irMap[70][75] = {HRIR_48K_24bit::azi_70_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_70_0_ele_75_0_wav};
  irMap[70][90] = {HRIR_48K_24bit::azi_70_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_70_0_ele_90_0_wav};
  irMap[70][-15] = {HRIR_48K_24bit::azi_70_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_70_0_ele_neg15_0_wav};
  irMap[70][-25] = {HRIR_48K_24bit::azi_70_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_70_0_ele_neg25_0_wav};
  irMap[70][-30] = {HRIR_48K_24bit::azi_70_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_70_0_ele_neg30_0_wav};
  irMap[70][-45] = {HRIR_48K_24bit::azi_70_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_70_0_ele_neg45_0_wav};
  irMap[70][-54] = {HRIR_48K_24bit::azi_70_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_70_0_ele_neg54_0_wav};
  irMap[70][-60] = {HRIR_48K_24bit::azi_70_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_70_0_ele_neg60_0_wav};
  irMap[70][-75] = {HRIR_48K_24bit::azi_70_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_70_0_ele_neg75_0_wav};
  irMap[70][-81] = {HRIR_48K_24bit::azi_70_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_70_0_ele_neg81_0_wav};
  irMap[71][0] = {HRIR_48K_24bit::azi_71_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_71_0_ele_0_0_wav};
  irMap[71][15] = {HRIR_48K_24bit::azi_71_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_71_0_ele_15_0_wav};
  irMap[71][25] = {HRIR_48K_24bit::azi_71_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_71_0_ele_25_0_wav};
  irMap[71][30] = {HRIR_48K_24bit::azi_71_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_71_0_ele_30_0_wav};
  irMap[71][45] = {HRIR_48K_24bit::azi_71_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_71_0_ele_45_0_wav};
  irMap[71][54] = {HRIR_48K_24bit::azi_71_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_71_0_ele_54_0_wav};
  irMap[71][60] = {HRIR_48K_24bit::azi_71_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_71_0_ele_60_0_wav};
  irMap[71][75] = {HRIR_48K_24bit::azi_71_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_71_0_ele_75_0_wav};
  irMap[71][90] = {HRIR_48K_24bit::azi_71_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_71_0_ele_90_0_wav};
  irMap[71][-15] = {HRIR_48K_24bit::azi_71_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_71_0_ele_neg15_0_wav};
  irMap[71][-25] = {HRIR_48K_24bit::azi_71_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_71_0_ele_neg25_0_wav};
  irMap[71][-30] = {HRIR_48K_24bit::azi_71_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_71_0_ele_neg30_0_wav};
  irMap[71][-45] = {HRIR_48K_24bit::azi_71_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_71_0_ele_neg45_0_wav};
  irMap[71][-54] = {HRIR_48K_24bit::azi_71_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_71_0_ele_neg54_0_wav};
  irMap[71][-60] = {HRIR_48K_24bit::azi_71_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_71_0_ele_neg60_0_wav};
  irMap[71][-75] = {HRIR_48K_24bit::azi_71_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_71_0_ele_neg75_0_wav};
  irMap[71][-81] = {HRIR_48K_24bit::azi_71_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_71_0_ele_neg81_0_wav};
  irMap[72][0] = {HRIR_48K_24bit::azi_72_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_72_0_ele_0_0_wav};
  irMap[72][15] = {HRIR_48K_24bit::azi_72_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_72_0_ele_15_0_wav};
  irMap[72][25] = {HRIR_48K_24bit::azi_72_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_72_0_ele_25_0_wav};
  irMap[72][30] = {HRIR_48K_24bit::azi_72_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_72_0_ele_30_0_wav};
  irMap[72][45] = {HRIR_48K_24bit::azi_72_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_72_0_ele_45_0_wav};
  irMap[72][54] = {HRIR_48K_24bit::azi_72_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_72_0_ele_54_0_wav};
  irMap[72][60] = {HRIR_48K_24bit::azi_72_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_72_0_ele_60_0_wav};
  irMap[72][75] = {HRIR_48K_24bit::azi_72_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_72_0_ele_75_0_wav};
  irMap[72][90] = {HRIR_48K_24bit::azi_72_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_72_0_ele_90_0_wav};
  irMap[72][-15] = {HRIR_48K_24bit::azi_72_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_72_0_ele_neg15_0_wav};
  irMap[72][-25] = {HRIR_48K_24bit::azi_72_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_72_0_ele_neg25_0_wav};
  irMap[72][-30] = {HRIR_48K_24bit::azi_72_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_72_0_ele_neg30_0_wav};
  irMap[72][-45] = {HRIR_48K_24bit::azi_72_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_72_0_ele_neg45_0_wav};
  irMap[72][-54] = {HRIR_48K_24bit::azi_72_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_72_0_ele_neg54_0_wav};
  irMap[72][-60] = {HRIR_48K_24bit::azi_72_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_72_0_ele_neg60_0_wav};
  irMap[72][-75] = {HRIR_48K_24bit::azi_72_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_72_0_ele_neg75_0_wav};
  irMap[72][-81] = {HRIR_48K_24bit::azi_72_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_72_0_ele_neg81_0_wav};
  irMap[73][0] = {HRIR_48K_24bit::azi_73_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_73_0_ele_0_0_wav};
  irMap[73][15] = {HRIR_48K_24bit::azi_73_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_73_0_ele_15_0_wav};
  irMap[73][25] = {HRIR_48K_24bit::azi_73_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_73_0_ele_25_0_wav};
  irMap[73][30] = {HRIR_48K_24bit::azi_73_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_73_0_ele_30_0_wav};
  irMap[73][45] = {HRIR_48K_24bit::azi_73_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_73_0_ele_45_0_wav};
  irMap[73][54] = {HRIR_48K_24bit::azi_73_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_73_0_ele_54_0_wav};
  irMap[73][60] = {HRIR_48K_24bit::azi_73_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_73_0_ele_60_0_wav};
  irMap[73][75] = {HRIR_48K_24bit::azi_73_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_73_0_ele_75_0_wav};
  irMap[73][90] = {HRIR_48K_24bit::azi_73_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_73_0_ele_90_0_wav};
  irMap[73][-15] = {HRIR_48K_24bit::azi_73_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_73_0_ele_neg15_0_wav};
  irMap[73][-25] = {HRIR_48K_24bit::azi_73_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_73_0_ele_neg25_0_wav};
  irMap[73][-30] = {HRIR_48K_24bit::azi_73_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_73_0_ele_neg30_0_wav};
  irMap[73][-45] = {HRIR_48K_24bit::azi_73_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_73_0_ele_neg45_0_wav};
  irMap[73][-54] = {HRIR_48K_24bit::azi_73_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_73_0_ele_neg54_0_wav};
  irMap[73][-60] = {HRIR_48K_24bit::azi_73_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_73_0_ele_neg60_0_wav};
  irMap[73][-75] = {HRIR_48K_24bit::azi_73_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_73_0_ele_neg75_0_wav};
  irMap[73][-81] = {HRIR_48K_24bit::azi_73_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_73_0_ele_neg81_0_wav};
  irMap[74][0] = {HRIR_48K_24bit::azi_74_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_74_0_ele_0_0_wav};
  irMap[74][15] = {HRIR_48K_24bit::azi_74_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_74_0_ele_15_0_wav};
  irMap[74][25] = {HRIR_48K_24bit::azi_74_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_74_0_ele_25_0_wav};
  irMap[74][30] = {HRIR_48K_24bit::azi_74_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_74_0_ele_30_0_wav};
  irMap[74][45] = {HRIR_48K_24bit::azi_74_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_74_0_ele_45_0_wav};
  irMap[74][54] = {HRIR_48K_24bit::azi_74_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_74_0_ele_54_0_wav};
  irMap[74][60] = {HRIR_48K_24bit::azi_74_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_74_0_ele_60_0_wav};
  irMap[74][75] = {HRIR_48K_24bit::azi_74_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_74_0_ele_75_0_wav};
  irMap[74][90] = {HRIR_48K_24bit::azi_74_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_74_0_ele_90_0_wav};
  irMap[74][-15] = {HRIR_48K_24bit::azi_74_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_74_0_ele_neg15_0_wav};
  irMap[74][-25] = {HRIR_48K_24bit::azi_74_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_74_0_ele_neg25_0_wav};
  irMap[74][-30] = {HRIR_48K_24bit::azi_74_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_74_0_ele_neg30_0_wav};
  irMap[74][-45] = {HRIR_48K_24bit::azi_74_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_74_0_ele_neg45_0_wav};
  irMap[74][-54] = {HRIR_48K_24bit::azi_74_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_74_0_ele_neg54_0_wav};
  irMap[74][-60] = {HRIR_48K_24bit::azi_74_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_74_0_ele_neg60_0_wav};
  irMap[74][-75] = {HRIR_48K_24bit::azi_74_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_74_0_ele_neg75_0_wav};
  irMap[74][-81] = {HRIR_48K_24bit::azi_74_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_74_0_ele_neg81_0_wav};
  irMap[75][0] = {HRIR_48K_24bit::azi_75_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_75_0_ele_0_0_wav};
  irMap[75][15] = {HRIR_48K_24bit::azi_75_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_75_0_ele_15_0_wav};
  irMap[75][25] = {HRIR_48K_24bit::azi_75_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_75_0_ele_25_0_wav};
  irMap[75][30] = {HRIR_48K_24bit::azi_75_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_75_0_ele_30_0_wav};
  irMap[75][45] = {HRIR_48K_24bit::azi_75_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_75_0_ele_45_0_wav};
  irMap[75][54] = {HRIR_48K_24bit::azi_75_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_75_0_ele_54_0_wav};
  irMap[75][60] = {HRIR_48K_24bit::azi_75_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_75_0_ele_60_0_wav};
  irMap[75][75] = {HRIR_48K_24bit::azi_75_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_75_0_ele_75_0_wav};
  irMap[75][90] = {HRIR_48K_24bit::azi_75_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_75_0_ele_90_0_wav};
  irMap[75][-15] = {HRIR_48K_24bit::azi_75_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_75_0_ele_neg15_0_wav};
  irMap[75][-25] = {HRIR_48K_24bit::azi_75_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_75_0_ele_neg25_0_wav};
  irMap[75][-30] = {HRIR_48K_24bit::azi_75_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_75_0_ele_neg30_0_wav};
  irMap[75][-45] = {HRIR_48K_24bit::azi_75_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_75_0_ele_neg45_0_wav};
  irMap[75][-54] = {HRIR_48K_24bit::azi_75_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_75_0_ele_neg54_0_wav};
  irMap[75][-60] = {HRIR_48K_24bit::azi_75_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_75_0_ele_neg60_0_wav};
  irMap[75][-75] = {HRIR_48K_24bit::azi_75_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_75_0_ele_neg75_0_wav};
  irMap[75][-81] = {HRIR_48K_24bit::azi_75_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_75_0_ele_neg81_0_wav};
  irMap[76][0] = {HRIR_48K_24bit::azi_76_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_76_0_ele_0_0_wav};
  irMap[76][15] = {HRIR_48K_24bit::azi_76_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_76_0_ele_15_0_wav};
  irMap[76][25] = {HRIR_48K_24bit::azi_76_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_76_0_ele_25_0_wav};
  irMap[76][30] = {HRIR_48K_24bit::azi_76_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_76_0_ele_30_0_wav};
  irMap[76][45] = {HRIR_48K_24bit::azi_76_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_76_0_ele_45_0_wav};
  irMap[76][54] = {HRIR_48K_24bit::azi_76_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_76_0_ele_54_0_wav};
  irMap[76][60] = {HRIR_48K_24bit::azi_76_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_76_0_ele_60_0_wav};
  irMap[76][75] = {HRIR_48K_24bit::azi_76_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_76_0_ele_75_0_wav};
  irMap[76][90] = {HRIR_48K_24bit::azi_76_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_76_0_ele_90_0_wav};
  irMap[76][-15] = {HRIR_48K_24bit::azi_76_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_76_0_ele_neg15_0_wav};
  irMap[76][-25] = {HRIR_48K_24bit::azi_76_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_76_0_ele_neg25_0_wav};
  irMap[76][-30] = {HRIR_48K_24bit::azi_76_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_76_0_ele_neg30_0_wav};
  irMap[76][-45] = {HRIR_48K_24bit::azi_76_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_76_0_ele_neg45_0_wav};
  irMap[76][-54] = {HRIR_48K_24bit::azi_76_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_76_0_ele_neg54_0_wav};
  irMap[76][-60] = {HRIR_48K_24bit::azi_76_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_76_0_ele_neg60_0_wav};
  irMap[76][-75] = {HRIR_48K_24bit::azi_76_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_76_0_ele_neg75_0_wav};
  irMap[76][-81] = {HRIR_48K_24bit::azi_76_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_76_0_ele_neg81_0_wav};
  irMap[77][0] = {HRIR_48K_24bit::azi_77_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_77_0_ele_0_0_wav};
  irMap[77][15] = {HRIR_48K_24bit::azi_77_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_77_0_ele_15_0_wav};
  irMap[77][25] = {HRIR_48K_24bit::azi_77_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_77_0_ele_25_0_wav};
  irMap[77][30] = {HRIR_48K_24bit::azi_77_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_77_0_ele_30_0_wav};
  irMap[77][45] = {HRIR_48K_24bit::azi_77_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_77_0_ele_45_0_wav};
  irMap[77][54] = {HRIR_48K_24bit::azi_77_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_77_0_ele_54_0_wav};
  irMap[77][60] = {HRIR_48K_24bit::azi_77_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_77_0_ele_60_0_wav};
  irMap[77][75] = {HRIR_48K_24bit::azi_77_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_77_0_ele_75_0_wav};
  irMap[77][90] = {HRIR_48K_24bit::azi_77_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_77_0_ele_90_0_wav};
  irMap[77][-15] = {HRIR_48K_24bit::azi_77_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_77_0_ele_neg15_0_wav};
  irMap[77][-25] = {HRIR_48K_24bit::azi_77_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_77_0_ele_neg25_0_wav};
  irMap[77][-30] = {HRIR_48K_24bit::azi_77_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_77_0_ele_neg30_0_wav};
  irMap[77][-45] = {HRIR_48K_24bit::azi_77_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_77_0_ele_neg45_0_wav};
  irMap[77][-54] = {HRIR_48K_24bit::azi_77_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_77_0_ele_neg54_0_wav};
  irMap[77][-60] = {HRIR_48K_24bit::azi_77_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_77_0_ele_neg60_0_wav};
  irMap[77][-75] = {HRIR_48K_24bit::azi_77_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_77_0_ele_neg75_0_wav};
  irMap[77][-81] = {HRIR_48K_24bit::azi_77_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_77_0_ele_neg81_0_wav};
  irMap[78][0] = {HRIR_48K_24bit::azi_78_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_78_0_ele_0_0_wav};
  irMap[78][15] = {HRIR_48K_24bit::azi_78_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_78_0_ele_15_0_wav};
  irMap[78][25] = {HRIR_48K_24bit::azi_78_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_78_0_ele_25_0_wav};
  irMap[78][30] = {HRIR_48K_24bit::azi_78_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_78_0_ele_30_0_wav};
  irMap[78][45] = {HRIR_48K_24bit::azi_78_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_78_0_ele_45_0_wav};
  irMap[78][54] = {HRIR_48K_24bit::azi_78_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_78_0_ele_54_0_wav};
  irMap[78][60] = {HRIR_48K_24bit::azi_78_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_78_0_ele_60_0_wav};
  irMap[78][75] = {HRIR_48K_24bit::azi_78_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_78_0_ele_75_0_wav};
  irMap[78][90] = {HRIR_48K_24bit::azi_78_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_78_0_ele_90_0_wav};
  irMap[78][-15] = {HRIR_48K_24bit::azi_78_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_78_0_ele_neg15_0_wav};
  irMap[78][-25] = {HRIR_48K_24bit::azi_78_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_78_0_ele_neg25_0_wav};
  irMap[78][-30] = {HRIR_48K_24bit::azi_78_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_78_0_ele_neg30_0_wav};
  irMap[78][-45] = {HRIR_48K_24bit::azi_78_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_78_0_ele_neg45_0_wav};
  irMap[78][-54] = {HRIR_48K_24bit::azi_78_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_78_0_ele_neg54_0_wav};
  irMap[78][-60] = {HRIR_48K_24bit::azi_78_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_78_0_ele_neg60_0_wav};
  irMap[78][-75] = {HRIR_48K_24bit::azi_78_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_78_0_ele_neg75_0_wav};
  irMap[78][-81] = {HRIR_48K_24bit::azi_78_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_78_0_ele_neg81_0_wav};
  irMap[79][0] = {HRIR_48K_24bit::azi_79_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_79_0_ele_0_0_wav};
  irMap[79][15] = {HRIR_48K_24bit::azi_79_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_79_0_ele_15_0_wav};
  irMap[79][25] = {HRIR_48K_24bit::azi_79_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_79_0_ele_25_0_wav};
  irMap[79][30] = {HRIR_48K_24bit::azi_79_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_79_0_ele_30_0_wav};
  irMap[79][45] = {HRIR_48K_24bit::azi_79_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_79_0_ele_45_0_wav};
  irMap[79][54] = {HRIR_48K_24bit::azi_79_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_79_0_ele_54_0_wav};
  irMap[79][60] = {HRIR_48K_24bit::azi_79_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_79_0_ele_60_0_wav};
  irMap[79][75] = {HRIR_48K_24bit::azi_79_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_79_0_ele_75_0_wav};
  irMap[79][90] = {HRIR_48K_24bit::azi_79_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_79_0_ele_90_0_wav};
  irMap[79][-15] = {HRIR_48K_24bit::azi_79_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_79_0_ele_neg15_0_wav};
  irMap[79][-25] = {HRIR_48K_24bit::azi_79_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_79_0_ele_neg25_0_wav};
  irMap[79][-30] = {HRIR_48K_24bit::azi_79_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_79_0_ele_neg30_0_wav};
  irMap[79][-45] = {HRIR_48K_24bit::azi_79_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_79_0_ele_neg45_0_wav};
  irMap[79][-54] = {HRIR_48K_24bit::azi_79_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_79_0_ele_neg54_0_wav};
  irMap[79][-60] = {HRIR_48K_24bit::azi_79_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_79_0_ele_neg60_0_wav};
  irMap[79][-75] = {HRIR_48K_24bit::azi_79_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_79_0_ele_neg75_0_wav};
  irMap[79][-81] = {HRIR_48K_24bit::azi_79_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_79_0_ele_neg81_0_wav};
  irMap[80][0] = {HRIR_48K_24bit::azi_80_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_80_0_ele_0_0_wav};
  irMap[80][15] = {HRIR_48K_24bit::azi_80_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_80_0_ele_15_0_wav};
  irMap[80][25] = {HRIR_48K_24bit::azi_80_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_80_0_ele_25_0_wav};
  irMap[80][30] = {HRIR_48K_24bit::azi_80_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_80_0_ele_30_0_wav};
  irMap[80][45] = {HRIR_48K_24bit::azi_80_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_80_0_ele_45_0_wav};
  irMap[80][54] = {HRIR_48K_24bit::azi_80_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_80_0_ele_54_0_wav};
  irMap[80][60] = {HRIR_48K_24bit::azi_80_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_80_0_ele_60_0_wav};
  irMap[80][75] = {HRIR_48K_24bit::azi_80_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_80_0_ele_75_0_wav};
  irMap[80][90] = {HRIR_48K_24bit::azi_80_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_80_0_ele_90_0_wav};
  irMap[80][-15] = {HRIR_48K_24bit::azi_80_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_80_0_ele_neg15_0_wav};
  irMap[80][-25] = {HRIR_48K_24bit::azi_80_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_80_0_ele_neg25_0_wav};
  irMap[80][-30] = {HRIR_48K_24bit::azi_80_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_80_0_ele_neg30_0_wav};
  irMap[80][-45] = {HRIR_48K_24bit::azi_80_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_80_0_ele_neg45_0_wav};
  irMap[80][-54] = {HRIR_48K_24bit::azi_80_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_80_0_ele_neg54_0_wav};
  irMap[80][-60] = {HRIR_48K_24bit::azi_80_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_80_0_ele_neg60_0_wav};
  irMap[80][-75] = {HRIR_48K_24bit::azi_80_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_80_0_ele_neg75_0_wav};
  irMap[80][-81] = {HRIR_48K_24bit::azi_80_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_80_0_ele_neg81_0_wav};
  irMap[81][0] = {HRIR_48K_24bit::azi_81_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_81_0_ele_0_0_wav};
  irMap[81][15] = {HRIR_48K_24bit::azi_81_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_81_0_ele_15_0_wav};
  irMap[81][25] = {HRIR_48K_24bit::azi_81_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_81_0_ele_25_0_wav};
  irMap[81][30] = {HRIR_48K_24bit::azi_81_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_81_0_ele_30_0_wav};
  irMap[81][45] = {HRIR_48K_24bit::azi_81_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_81_0_ele_45_0_wav};
  irMap[81][54] = {HRIR_48K_24bit::azi_81_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_81_0_ele_54_0_wav};
  irMap[81][60] = {HRIR_48K_24bit::azi_81_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_81_0_ele_60_0_wav};
  irMap[81][75] = {HRIR_48K_24bit::azi_81_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_81_0_ele_75_0_wav};
  irMap[81][90] = {HRIR_48K_24bit::azi_81_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_81_0_ele_90_0_wav};
  irMap[81][-15] = {HRIR_48K_24bit::azi_81_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_81_0_ele_neg15_0_wav};
  irMap[81][-25] = {HRIR_48K_24bit::azi_81_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_81_0_ele_neg25_0_wav};
  irMap[81][-30] = {HRIR_48K_24bit::azi_81_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_81_0_ele_neg30_0_wav};
  irMap[81][-45] = {HRIR_48K_24bit::azi_81_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_81_0_ele_neg45_0_wav};
  irMap[81][-54] = {HRIR_48K_24bit::azi_81_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_81_0_ele_neg54_0_wav};
  irMap[81][-60] = {HRIR_48K_24bit::azi_81_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_81_0_ele_neg60_0_wav};
  irMap[81][-75] = {HRIR_48K_24bit::azi_81_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_81_0_ele_neg75_0_wav};
  irMap[81][-81] = {HRIR_48K_24bit::azi_81_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_81_0_ele_neg81_0_wav};
  irMap[82][0] = {HRIR_48K_24bit::azi_82_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_82_0_ele_0_0_wav};
  irMap[82][15] = {HRIR_48K_24bit::azi_82_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_82_0_ele_15_0_wav};
  irMap[82][25] = {HRIR_48K_24bit::azi_82_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_82_0_ele_25_0_wav};
  irMap[82][30] = {HRIR_48K_24bit::azi_82_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_82_0_ele_30_0_wav};
  irMap[82][45] = {HRIR_48K_24bit::azi_82_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_82_0_ele_45_0_wav};
  irMap[82][54] = {HRIR_48K_24bit::azi_82_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_82_0_ele_54_0_wav};
  irMap[82][60] = {HRIR_48K_24bit::azi_82_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_82_0_ele_60_0_wav};
  irMap[82][75] = {HRIR_48K_24bit::azi_82_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_82_0_ele_75_0_wav};
  irMap[82][90] = {HRIR_48K_24bit::azi_82_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_82_0_ele_90_0_wav};
  irMap[82][-15] = {HRIR_48K_24bit::azi_82_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_82_0_ele_neg15_0_wav};
  irMap[82][-25] = {HRIR_48K_24bit::azi_82_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_82_0_ele_neg25_0_wav};
  irMap[82][-30] = {HRIR_48K_24bit::azi_82_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_82_0_ele_neg30_0_wav};
  irMap[82][-45] = {HRIR_48K_24bit::azi_82_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_82_0_ele_neg45_0_wav};
  irMap[82][-54] = {HRIR_48K_24bit::azi_82_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_82_0_ele_neg54_0_wav};
  irMap[82][-60] = {HRIR_48K_24bit::azi_82_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_82_0_ele_neg60_0_wav};
  irMap[82][-75] = {HRIR_48K_24bit::azi_82_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_82_0_ele_neg75_0_wav};
  irMap[82][-81] = {HRIR_48K_24bit::azi_82_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_82_0_ele_neg81_0_wav};
  irMap[83][0] = {HRIR_48K_24bit::azi_83_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_83_0_ele_0_0_wav};
  irMap[83][15] = {HRIR_48K_24bit::azi_83_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_83_0_ele_15_0_wav};
  irMap[83][25] = {HRIR_48K_24bit::azi_83_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_83_0_ele_25_0_wav};
  irMap[83][30] = {HRIR_48K_24bit::azi_83_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_83_0_ele_30_0_wav};
  irMap[83][45] = {HRIR_48K_24bit::azi_83_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_83_0_ele_45_0_wav};
  irMap[83][54] = {HRIR_48K_24bit::azi_83_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_83_0_ele_54_0_wav};
  irMap[83][60] = {HRIR_48K_24bit::azi_83_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_83_0_ele_60_0_wav};
  irMap[83][75] = {HRIR_48K_24bit::azi_83_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_83_0_ele_75_0_wav};
  irMap[83][90] = {HRIR_48K_24bit::azi_83_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_83_0_ele_90_0_wav};
  irMap[83][-15] = {HRIR_48K_24bit::azi_83_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_83_0_ele_neg15_0_wav};
  irMap[83][-25] = {HRIR_48K_24bit::azi_83_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_83_0_ele_neg25_0_wav};
  irMap[83][-30] = {HRIR_48K_24bit::azi_83_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_83_0_ele_neg30_0_wav};
  irMap[83][-45] = {HRIR_48K_24bit::azi_83_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_83_0_ele_neg45_0_wav};
  irMap[83][-54] = {HRIR_48K_24bit::azi_83_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_83_0_ele_neg54_0_wav};
  irMap[83][-60] = {HRIR_48K_24bit::azi_83_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_83_0_ele_neg60_0_wav};
  irMap[83][-75] = {HRIR_48K_24bit::azi_83_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_83_0_ele_neg75_0_wav};
  irMap[83][-81] = {HRIR_48K_24bit::azi_83_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_83_0_ele_neg81_0_wav};
  irMap[84][0] = {HRIR_48K_24bit::azi_84_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_84_0_ele_0_0_wav};
  irMap[84][15] = {HRIR_48K_24bit::azi_84_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_84_0_ele_15_0_wav};
  irMap[84][25] = {HRIR_48K_24bit::azi_84_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_84_0_ele_25_0_wav};
  irMap[84][30] = {HRIR_48K_24bit::azi_84_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_84_0_ele_30_0_wav};
  irMap[84][45] = {HRIR_48K_24bit::azi_84_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_84_0_ele_45_0_wav};
  irMap[84][54] = {HRIR_48K_24bit::azi_84_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_84_0_ele_54_0_wav};
  irMap[84][60] = {HRIR_48K_24bit::azi_84_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_84_0_ele_60_0_wav};
  irMap[84][75] = {HRIR_48K_24bit::azi_84_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_84_0_ele_75_0_wav};
  irMap[84][90] = {HRIR_48K_24bit::azi_84_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_84_0_ele_90_0_wav};
  irMap[84][-15] = {HRIR_48K_24bit::azi_84_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_84_0_ele_neg15_0_wav};
  irMap[84][-25] = {HRIR_48K_24bit::azi_84_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_84_0_ele_neg25_0_wav};
  irMap[84][-30] = {HRIR_48K_24bit::azi_84_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_84_0_ele_neg30_0_wav};
  irMap[84][-45] = {HRIR_48K_24bit::azi_84_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_84_0_ele_neg45_0_wav};
  irMap[84][-54] = {HRIR_48K_24bit::azi_84_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_84_0_ele_neg54_0_wav};
  irMap[84][-60] = {HRIR_48K_24bit::azi_84_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_84_0_ele_neg60_0_wav};
  irMap[84][-75] = {HRIR_48K_24bit::azi_84_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_84_0_ele_neg75_0_wav};
  irMap[84][-81] = {HRIR_48K_24bit::azi_84_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_84_0_ele_neg81_0_wav};
  irMap[85][0] = {HRIR_48K_24bit::azi_85_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_85_0_ele_0_0_wav};
  irMap[85][15] = {HRIR_48K_24bit::azi_85_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_85_0_ele_15_0_wav};
  irMap[85][25] = {HRIR_48K_24bit::azi_85_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_85_0_ele_25_0_wav};
  irMap[85][30] = {HRIR_48K_24bit::azi_85_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_85_0_ele_30_0_wav};
  irMap[85][45] = {HRIR_48K_24bit::azi_85_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_85_0_ele_45_0_wav};
  irMap[85][54] = {HRIR_48K_24bit::azi_85_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_85_0_ele_54_0_wav};
  irMap[85][60] = {HRIR_48K_24bit::azi_85_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_85_0_ele_60_0_wav};
  irMap[85][75] = {HRIR_48K_24bit::azi_85_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_85_0_ele_75_0_wav};
  irMap[85][90] = {HRIR_48K_24bit::azi_85_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_85_0_ele_90_0_wav};
  irMap[85][-15] = {HRIR_48K_24bit::azi_85_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_85_0_ele_neg15_0_wav};
  irMap[85][-25] = {HRIR_48K_24bit::azi_85_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_85_0_ele_neg25_0_wav};
  irMap[85][-30] = {HRIR_48K_24bit::azi_85_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_85_0_ele_neg30_0_wav};
  irMap[85][-45] = {HRIR_48K_24bit::azi_85_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_85_0_ele_neg45_0_wav};
  irMap[85][-54] = {HRIR_48K_24bit::azi_85_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_85_0_ele_neg54_0_wav};
  irMap[85][-60] = {HRIR_48K_24bit::azi_85_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_85_0_ele_neg60_0_wav};
  irMap[85][-75] = {HRIR_48K_24bit::azi_85_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_85_0_ele_neg75_0_wav};
  irMap[85][-81] = {HRIR_48K_24bit::azi_85_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_85_0_ele_neg81_0_wav};
  irMap[86][0] = {HRIR_48K_24bit::azi_86_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_86_0_ele_0_0_wav};
  irMap[86][15] = {HRIR_48K_24bit::azi_86_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_86_0_ele_15_0_wav};
  irMap[86][25] = {HRIR_48K_24bit::azi_86_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_86_0_ele_25_0_wav};
  irMap[86][30] = {HRIR_48K_24bit::azi_86_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_86_0_ele_30_0_wav};
  irMap[86][45] = {HRIR_48K_24bit::azi_86_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_86_0_ele_45_0_wav};
  irMap[86][54] = {HRIR_48K_24bit::azi_86_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_86_0_ele_54_0_wav};
  irMap[86][60] = {HRIR_48K_24bit::azi_86_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_86_0_ele_60_0_wav};
  irMap[86][75] = {HRIR_48K_24bit::azi_86_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_86_0_ele_75_0_wav};
  irMap[86][90] = {HRIR_48K_24bit::azi_86_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_86_0_ele_90_0_wav};
  irMap[86][-15] = {HRIR_48K_24bit::azi_86_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_86_0_ele_neg15_0_wav};
  irMap[86][-25] = {HRIR_48K_24bit::azi_86_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_86_0_ele_neg25_0_wav};
  irMap[86][-30] = {HRIR_48K_24bit::azi_86_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_86_0_ele_neg30_0_wav};
  irMap[86][-45] = {HRIR_48K_24bit::azi_86_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_86_0_ele_neg45_0_wav};
  irMap[86][-54] = {HRIR_48K_24bit::azi_86_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_86_0_ele_neg54_0_wav};
  irMap[86][-60] = {HRIR_48K_24bit::azi_86_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_86_0_ele_neg60_0_wav};
  irMap[86][-75] = {HRIR_48K_24bit::azi_86_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_86_0_ele_neg75_0_wav};
  irMap[86][-81] = {HRIR_48K_24bit::azi_86_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_86_0_ele_neg81_0_wav};
  irMap[87][0] = {HRIR_48K_24bit::azi_87_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_87_0_ele_0_0_wav};
  irMap[87][15] = {HRIR_48K_24bit::azi_87_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_87_0_ele_15_0_wav};
  irMap[87][25] = {HRIR_48K_24bit::azi_87_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_87_0_ele_25_0_wav};
  irMap[87][30] = {HRIR_48K_24bit::azi_87_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_87_0_ele_30_0_wav};
  irMap[87][45] = {HRIR_48K_24bit::azi_87_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_87_0_ele_45_0_wav};
  irMap[87][54] = {HRIR_48K_24bit::azi_87_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_87_0_ele_54_0_wav};
  irMap[87][60] = {HRIR_48K_24bit::azi_87_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_87_0_ele_60_0_wav};
  irMap[87][75] = {HRIR_48K_24bit::azi_87_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_87_0_ele_75_0_wav};
  irMap[87][90] = {HRIR_48K_24bit::azi_87_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_87_0_ele_90_0_wav};
  irMap[87][-15] = {HRIR_48K_24bit::azi_87_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_87_0_ele_neg15_0_wav};
  irMap[87][-25] = {HRIR_48K_24bit::azi_87_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_87_0_ele_neg25_0_wav};
  irMap[87][-30] = {HRIR_48K_24bit::azi_87_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_87_0_ele_neg30_0_wav};
  irMap[87][-45] = {HRIR_48K_24bit::azi_87_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_87_0_ele_neg45_0_wav};
  irMap[87][-54] = {HRIR_48K_24bit::azi_87_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_87_0_ele_neg54_0_wav};
  irMap[87][-60] = {HRIR_48K_24bit::azi_87_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_87_0_ele_neg60_0_wav};
  irMap[87][-75] = {HRIR_48K_24bit::azi_87_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_87_0_ele_neg75_0_wav};
  irMap[87][-81] = {HRIR_48K_24bit::azi_87_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_87_0_ele_neg81_0_wav};
  irMap[88][0] = {HRIR_48K_24bit::azi_88_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_88_0_ele_0_0_wav};
  irMap[88][15] = {HRIR_48K_24bit::azi_88_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_88_0_ele_15_0_wav};
  irMap[88][25] = {HRIR_48K_24bit::azi_88_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_88_0_ele_25_0_wav};
  irMap[88][30] = {HRIR_48K_24bit::azi_88_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_88_0_ele_30_0_wav};
  irMap[88][45] = {HRIR_48K_24bit::azi_88_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_88_0_ele_45_0_wav};
  irMap[88][54] = {HRIR_48K_24bit::azi_88_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_88_0_ele_54_0_wav};
  irMap[88][60] = {HRIR_48K_24bit::azi_88_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_88_0_ele_60_0_wav};
  irMap[88][75] = {HRIR_48K_24bit::azi_88_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_88_0_ele_75_0_wav};
  irMap[88][90] = {HRIR_48K_24bit::azi_88_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_88_0_ele_90_0_wav};
  irMap[88][-15] = {HRIR_48K_24bit::azi_88_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_88_0_ele_neg15_0_wav};
  irMap[88][-25] = {HRIR_48K_24bit::azi_88_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_88_0_ele_neg25_0_wav};
  irMap[88][-30] = {HRIR_48K_24bit::azi_88_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_88_0_ele_neg30_0_wav};
  irMap[88][-45] = {HRIR_48K_24bit::azi_88_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_88_0_ele_neg45_0_wav};
  irMap[88][-54] = {HRIR_48K_24bit::azi_88_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_88_0_ele_neg54_0_wav};
  irMap[88][-60] = {HRIR_48K_24bit::azi_88_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_88_0_ele_neg60_0_wav};
  irMap[88][-75] = {HRIR_48K_24bit::azi_88_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_88_0_ele_neg75_0_wav};
  irMap[88][-81] = {HRIR_48K_24bit::azi_88_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_88_0_ele_neg81_0_wav};
  irMap[89][0] = {HRIR_48K_24bit::azi_89_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_89_0_ele_0_0_wav};
  irMap[89][15] = {HRIR_48K_24bit::azi_89_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_89_0_ele_15_0_wav};
  irMap[89][25] = {HRIR_48K_24bit::azi_89_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_89_0_ele_25_0_wav};
  irMap[89][30] = {HRIR_48K_24bit::azi_89_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_89_0_ele_30_0_wav};
  irMap[89][45] = {HRIR_48K_24bit::azi_89_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_89_0_ele_45_0_wav};
  irMap[89][54] = {HRIR_48K_24bit::azi_89_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_89_0_ele_54_0_wav};
  irMap[89][60] = {HRIR_48K_24bit::azi_89_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_89_0_ele_60_0_wav};
  irMap[89][75] = {HRIR_48K_24bit::azi_89_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_89_0_ele_75_0_wav};
  irMap[89][90] = {HRIR_48K_24bit::azi_89_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_89_0_ele_90_0_wav};
  irMap[89][-15] = {HRIR_48K_24bit::azi_89_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_89_0_ele_neg15_0_wav};
  irMap[89][-25] = {HRIR_48K_24bit::azi_89_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_89_0_ele_neg25_0_wav};
  irMap[89][-30] = {HRIR_48K_24bit::azi_89_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_89_0_ele_neg30_0_wav};
  irMap[89][-45] = {HRIR_48K_24bit::azi_89_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_89_0_ele_neg45_0_wav};
  irMap[89][-54] = {HRIR_48K_24bit::azi_89_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_89_0_ele_neg54_0_wav};
  irMap[89][-60] = {HRIR_48K_24bit::azi_89_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_89_0_ele_neg60_0_wav};
  irMap[89][-75] = {HRIR_48K_24bit::azi_89_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_89_0_ele_neg75_0_wav};
  irMap[89][-81] = {HRIR_48K_24bit::azi_89_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_89_0_ele_neg81_0_wav};
  irMap[90][0] = {HRIR_48K_24bit::azi_90_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_90_0_ele_0_0_wav};
  irMap[90][15] = {HRIR_48K_24bit::azi_90_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_90_0_ele_15_0_wav};
  irMap[90][25] = {HRIR_48K_24bit::azi_90_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_90_0_ele_25_0_wav};
  irMap[90][30] = {HRIR_48K_24bit::azi_90_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_90_0_ele_30_0_wav};
  irMap[90][45] = {HRIR_48K_24bit::azi_90_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_90_0_ele_45_0_wav};
  irMap[90][54] = {HRIR_48K_24bit::azi_90_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_90_0_ele_54_0_wav};
  irMap[90][60] = {HRIR_48K_24bit::azi_90_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_90_0_ele_60_0_wav};
  irMap[90][75] = {HRIR_48K_24bit::azi_90_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_90_0_ele_75_0_wav};
  irMap[90][90] = {HRIR_48K_24bit::azi_90_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_90_0_ele_90_0_wav};
  irMap[90][-15] = {HRIR_48K_24bit::azi_90_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_90_0_ele_neg15_0_wav};
  irMap[90][-25] = {HRIR_48K_24bit::azi_90_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_90_0_ele_neg25_0_wav};
  irMap[90][-30] = {HRIR_48K_24bit::azi_90_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_90_0_ele_neg30_0_wav};
  irMap[90][-45] = {HRIR_48K_24bit::azi_90_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_90_0_ele_neg45_0_wav};
  irMap[90][-54] = {HRIR_48K_24bit::azi_90_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_90_0_ele_neg54_0_wav};
  irMap[90][-60] = {HRIR_48K_24bit::azi_90_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_90_0_ele_neg60_0_wav};
  irMap[90][-75] = {HRIR_48K_24bit::azi_90_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_90_0_ele_neg75_0_wav};
  irMap[90][-81] = {HRIR_48K_24bit::azi_90_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_90_0_ele_neg81_0_wav};
  irMap[91][0] = {HRIR_48K_24bit::azi_91_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_91_0_ele_0_0_wav};
  irMap[91][15] = {HRIR_48K_24bit::azi_91_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_91_0_ele_15_0_wav};
  irMap[91][25] = {HRIR_48K_24bit::azi_91_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_91_0_ele_25_0_wav};
  irMap[91][30] = {HRIR_48K_24bit::azi_91_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_91_0_ele_30_0_wav};
  irMap[91][45] = {HRIR_48K_24bit::azi_91_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_91_0_ele_45_0_wav};
  irMap[91][54] = {HRIR_48K_24bit::azi_91_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_91_0_ele_54_0_wav};
  irMap[91][60] = {HRIR_48K_24bit::azi_91_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_91_0_ele_60_0_wav};
  irMap[91][75] = {HRIR_48K_24bit::azi_91_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_91_0_ele_75_0_wav};
  irMap[91][90] = {HRIR_48K_24bit::azi_91_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_91_0_ele_90_0_wav};
  irMap[91][-15] = {HRIR_48K_24bit::azi_91_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_91_0_ele_neg15_0_wav};
  irMap[91][-25] = {HRIR_48K_24bit::azi_91_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_91_0_ele_neg25_0_wav};
  irMap[91][-30] = {HRIR_48K_24bit::azi_91_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_91_0_ele_neg30_0_wav};
  irMap[91][-45] = {HRIR_48K_24bit::azi_91_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_91_0_ele_neg45_0_wav};
  irMap[91][-54] = {HRIR_48K_24bit::azi_91_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_91_0_ele_neg54_0_wav};
  irMap[91][-60] = {HRIR_48K_24bit::azi_91_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_91_0_ele_neg60_0_wav};
  irMap[91][-75] = {HRIR_48K_24bit::azi_91_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_91_0_ele_neg75_0_wav};
  irMap[91][-81] = {HRIR_48K_24bit::azi_91_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_91_0_ele_neg81_0_wav};
  irMap[92][0] = {HRIR_48K_24bit::azi_92_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_92_0_ele_0_0_wav};
  irMap[92][15] = {HRIR_48K_24bit::azi_92_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_92_0_ele_15_0_wav};
  irMap[92][25] = {HRIR_48K_24bit::azi_92_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_92_0_ele_25_0_wav};
  irMap[92][30] = {HRIR_48K_24bit::azi_92_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_92_0_ele_30_0_wav};
  irMap[92][45] = {HRIR_48K_24bit::azi_92_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_92_0_ele_45_0_wav};
  irMap[92][54] = {HRIR_48K_24bit::azi_92_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_92_0_ele_54_0_wav};
  irMap[92][60] = {HRIR_48K_24bit::azi_92_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_92_0_ele_60_0_wav};
  irMap[92][75] = {HRIR_48K_24bit::azi_92_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_92_0_ele_75_0_wav};
  irMap[92][90] = {HRIR_48K_24bit::azi_92_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_92_0_ele_90_0_wav};
  irMap[92][-15] = {HRIR_48K_24bit::azi_92_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_92_0_ele_neg15_0_wav};
  irMap[92][-25] = {HRIR_48K_24bit::azi_92_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_92_0_ele_neg25_0_wav};
  irMap[92][-30] = {HRIR_48K_24bit::azi_92_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_92_0_ele_neg30_0_wav};
  irMap[92][-45] = {HRIR_48K_24bit::azi_92_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_92_0_ele_neg45_0_wav};
  irMap[92][-54] = {HRIR_48K_24bit::azi_92_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_92_0_ele_neg54_0_wav};
  irMap[92][-60] = {HRIR_48K_24bit::azi_92_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_92_0_ele_neg60_0_wav};
  irMap[92][-75] = {HRIR_48K_24bit::azi_92_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_92_0_ele_neg75_0_wav};
  irMap[92][-81] = {HRIR_48K_24bit::azi_92_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_92_0_ele_neg81_0_wav};
  irMap[93][0] = {HRIR_48K_24bit::azi_93_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_93_0_ele_0_0_wav};
  irMap[93][15] = {HRIR_48K_24bit::azi_93_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_93_0_ele_15_0_wav};
  irMap[93][25] = {HRIR_48K_24bit::azi_93_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_93_0_ele_25_0_wav};
  irMap[93][30] = {HRIR_48K_24bit::azi_93_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_93_0_ele_30_0_wav};
  irMap[93][45] = {HRIR_48K_24bit::azi_93_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_93_0_ele_45_0_wav};
  irMap[93][54] = {HRIR_48K_24bit::azi_93_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_93_0_ele_54_0_wav};
  irMap[93][60] = {HRIR_48K_24bit::azi_93_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_93_0_ele_60_0_wav};
  irMap[93][75] = {HRIR_48K_24bit::azi_93_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_93_0_ele_75_0_wav};
  irMap[93][90] = {HRIR_48K_24bit::azi_93_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_93_0_ele_90_0_wav};
  irMap[93][-15] = {HRIR_48K_24bit::azi_93_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_93_0_ele_neg15_0_wav};
  irMap[93][-25] = {HRIR_48K_24bit::azi_93_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_93_0_ele_neg25_0_wav};
  irMap[93][-30] = {HRIR_48K_24bit::azi_93_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_93_0_ele_neg30_0_wav};
  irMap[93][-45] = {HRIR_48K_24bit::azi_93_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_93_0_ele_neg45_0_wav};
  irMap[93][-54] = {HRIR_48K_24bit::azi_93_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_93_0_ele_neg54_0_wav};
  irMap[93][-60] = {HRIR_48K_24bit::azi_93_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_93_0_ele_neg60_0_wav};
  irMap[93][-75] = {HRIR_48K_24bit::azi_93_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_93_0_ele_neg75_0_wav};
  irMap[93][-81] = {HRIR_48K_24bit::azi_93_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_93_0_ele_neg81_0_wav};
  irMap[94][0] = {HRIR_48K_24bit::azi_94_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_94_0_ele_0_0_wav};
  irMap[94][15] = {HRIR_48K_24bit::azi_94_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_94_0_ele_15_0_wav};
  irMap[94][25] = {HRIR_48K_24bit::azi_94_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_94_0_ele_25_0_wav};
  irMap[94][30] = {HRIR_48K_24bit::azi_94_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_94_0_ele_30_0_wav};
  irMap[94][45] = {HRIR_48K_24bit::azi_94_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_94_0_ele_45_0_wav};
  irMap[94][54] = {HRIR_48K_24bit::azi_94_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_94_0_ele_54_0_wav};
  irMap[94][60] = {HRIR_48K_24bit::azi_94_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_94_0_ele_60_0_wav};
  irMap[94][75] = {HRIR_48K_24bit::azi_94_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_94_0_ele_75_0_wav};
  irMap[94][90] = {HRIR_48K_24bit::azi_94_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_94_0_ele_90_0_wav};
  irMap[94][-15] = {HRIR_48K_24bit::azi_94_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_94_0_ele_neg15_0_wav};
  irMap[94][-25] = {HRIR_48K_24bit::azi_94_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_94_0_ele_neg25_0_wav};
  irMap[94][-30] = {HRIR_48K_24bit::azi_94_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_94_0_ele_neg30_0_wav};
  irMap[94][-45] = {HRIR_48K_24bit::azi_94_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_94_0_ele_neg45_0_wav};
  irMap[94][-54] = {HRIR_48K_24bit::azi_94_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_94_0_ele_neg54_0_wav};
  irMap[94][-60] = {HRIR_48K_24bit::azi_94_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_94_0_ele_neg60_0_wav};
  irMap[94][-75] = {HRIR_48K_24bit::azi_94_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_94_0_ele_neg75_0_wav};
  irMap[94][-81] = {HRIR_48K_24bit::azi_94_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_94_0_ele_neg81_0_wav};
  irMap[95][0] = {HRIR_48K_24bit::azi_95_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_95_0_ele_0_0_wav};
  irMap[95][15] = {HRIR_48K_24bit::azi_95_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_95_0_ele_15_0_wav};
  irMap[95][25] = {HRIR_48K_24bit::azi_95_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_95_0_ele_25_0_wav};
  irMap[95][30] = {HRIR_48K_24bit::azi_95_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_95_0_ele_30_0_wav};
  irMap[95][45] = {HRIR_48K_24bit::azi_95_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_95_0_ele_45_0_wav};
  irMap[95][54] = {HRIR_48K_24bit::azi_95_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_95_0_ele_54_0_wav};
  irMap[95][60] = {HRIR_48K_24bit::azi_95_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_95_0_ele_60_0_wav};
  irMap[95][75] = {HRIR_48K_24bit::azi_95_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_95_0_ele_75_0_wav};
  irMap[95][90] = {HRIR_48K_24bit::azi_95_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_95_0_ele_90_0_wav};
  irMap[95][-15] = {HRIR_48K_24bit::azi_95_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_95_0_ele_neg15_0_wav};
  irMap[95][-25] = {HRIR_48K_24bit::azi_95_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_95_0_ele_neg25_0_wav};
  irMap[95][-30] = {HRIR_48K_24bit::azi_95_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_95_0_ele_neg30_0_wav};
  irMap[95][-45] = {HRIR_48K_24bit::azi_95_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_95_0_ele_neg45_0_wav};
  irMap[95][-54] = {HRIR_48K_24bit::azi_95_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_95_0_ele_neg54_0_wav};
  irMap[95][-60] = {HRIR_48K_24bit::azi_95_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_95_0_ele_neg60_0_wav};
  irMap[95][-75] = {HRIR_48K_24bit::azi_95_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_95_0_ele_neg75_0_wav};
  irMap[95][-81] = {HRIR_48K_24bit::azi_95_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_95_0_ele_neg81_0_wav};
  irMap[96][0] = {HRIR_48K_24bit::azi_96_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_96_0_ele_0_0_wav};
  irMap[96][15] = {HRIR_48K_24bit::azi_96_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_96_0_ele_15_0_wav};
  irMap[96][25] = {HRIR_48K_24bit::azi_96_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_96_0_ele_25_0_wav};
  irMap[96][30] = {HRIR_48K_24bit::azi_96_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_96_0_ele_30_0_wav};
  irMap[96][45] = {HRIR_48K_24bit::azi_96_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_96_0_ele_45_0_wav};
  irMap[96][54] = {HRIR_48K_24bit::azi_96_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_96_0_ele_54_0_wav};
  irMap[96][60] = {HRIR_48K_24bit::azi_96_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_96_0_ele_60_0_wav};
  irMap[96][75] = {HRIR_48K_24bit::azi_96_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_96_0_ele_75_0_wav};
  irMap[96][90] = {HRIR_48K_24bit::azi_96_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_96_0_ele_90_0_wav};
  irMap[96][-15] = {HRIR_48K_24bit::azi_96_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_96_0_ele_neg15_0_wav};
  irMap[96][-25] = {HRIR_48K_24bit::azi_96_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_96_0_ele_neg25_0_wav};
  irMap[96][-30] = {HRIR_48K_24bit::azi_96_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_96_0_ele_neg30_0_wav};
  irMap[96][-45] = {HRIR_48K_24bit::azi_96_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_96_0_ele_neg45_0_wav};
  irMap[96][-54] = {HRIR_48K_24bit::azi_96_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_96_0_ele_neg54_0_wav};
  irMap[96][-60] = {HRIR_48K_24bit::azi_96_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_96_0_ele_neg60_0_wav};
  irMap[96][-75] = {HRIR_48K_24bit::azi_96_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_96_0_ele_neg75_0_wav};
  irMap[96][-81] = {HRIR_48K_24bit::azi_96_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_96_0_ele_neg81_0_wav};
  irMap[97][0] = {HRIR_48K_24bit::azi_97_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_97_0_ele_0_0_wav};
  irMap[97][15] = {HRIR_48K_24bit::azi_97_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_97_0_ele_15_0_wav};
  irMap[97][25] = {HRIR_48K_24bit::azi_97_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_97_0_ele_25_0_wav};
  irMap[97][30] = {HRIR_48K_24bit::azi_97_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_97_0_ele_30_0_wav};
  irMap[97][45] = {HRIR_48K_24bit::azi_97_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_97_0_ele_45_0_wav};
  irMap[97][54] = {HRIR_48K_24bit::azi_97_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_97_0_ele_54_0_wav};
  irMap[97][60] = {HRIR_48K_24bit::azi_97_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_97_0_ele_60_0_wav};
  irMap[97][75] = {HRIR_48K_24bit::azi_97_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_97_0_ele_75_0_wav};
  irMap[97][90] = {HRIR_48K_24bit::azi_97_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_97_0_ele_90_0_wav};
  irMap[97][-15] = {HRIR_48K_24bit::azi_97_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_97_0_ele_neg15_0_wav};
  irMap[97][-25] = {HRIR_48K_24bit::azi_97_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_97_0_ele_neg25_0_wav};
  irMap[97][-30] = {HRIR_48K_24bit::azi_97_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_97_0_ele_neg30_0_wav};
  irMap[97][-45] = {HRIR_48K_24bit::azi_97_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_97_0_ele_neg45_0_wav};
  irMap[97][-54] = {HRIR_48K_24bit::azi_97_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_97_0_ele_neg54_0_wav};
  irMap[97][-60] = {HRIR_48K_24bit::azi_97_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_97_0_ele_neg60_0_wav};
  irMap[97][-75] = {HRIR_48K_24bit::azi_97_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_97_0_ele_neg75_0_wav};
  irMap[97][-81] = {HRIR_48K_24bit::azi_97_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_97_0_ele_neg81_0_wav};
  irMap[98][0] = {HRIR_48K_24bit::azi_98_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_98_0_ele_0_0_wav};
  irMap[98][15] = {HRIR_48K_24bit::azi_98_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_98_0_ele_15_0_wav};
  irMap[98][25] = {HRIR_48K_24bit::azi_98_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_98_0_ele_25_0_wav};
  irMap[98][30] = {HRIR_48K_24bit::azi_98_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_98_0_ele_30_0_wav};
  irMap[98][45] = {HRIR_48K_24bit::azi_98_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_98_0_ele_45_0_wav};
  irMap[98][54] = {HRIR_48K_24bit::azi_98_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_98_0_ele_54_0_wav};
  irMap[98][60] = {HRIR_48K_24bit::azi_98_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_98_0_ele_60_0_wav};
  irMap[98][75] = {HRIR_48K_24bit::azi_98_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_98_0_ele_75_0_wav};
  irMap[98][90] = {HRIR_48K_24bit::azi_98_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_98_0_ele_90_0_wav};
  irMap[98][-15] = {HRIR_48K_24bit::azi_98_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_98_0_ele_neg15_0_wav};
  irMap[98][-25] = {HRIR_48K_24bit::azi_98_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_98_0_ele_neg25_0_wav};
  irMap[98][-30] = {HRIR_48K_24bit::azi_98_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_98_0_ele_neg30_0_wav};
  irMap[98][-45] = {HRIR_48K_24bit::azi_98_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_98_0_ele_neg45_0_wav};
  irMap[98][-54] = {HRIR_48K_24bit::azi_98_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_98_0_ele_neg54_0_wav};
  irMap[98][-60] = {HRIR_48K_24bit::azi_98_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_98_0_ele_neg60_0_wav};
  irMap[98][-75] = {HRIR_48K_24bit::azi_98_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_98_0_ele_neg75_0_wav};
  irMap[98][-81] = {HRIR_48K_24bit::azi_98_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_98_0_ele_neg81_0_wav};
  irMap[99][0] = {HRIR_48K_24bit::azi_99_0_ele_0_0_wavSize,
                  HRIR_48K_24bit::azi_99_0_ele_0_0_wav};
  irMap[99][15] = {HRIR_48K_24bit::azi_99_0_ele_15_0_wavSize,
                   HRIR_48K_24bit::azi_99_0_ele_15_0_wav};
  irMap[99][25] = {HRIR_48K_24bit::azi_99_0_ele_25_0_wavSize,
                   HRIR_48K_24bit::azi_99_0_ele_25_0_wav};
  irMap[99][30] = {HRIR_48K_24bit::azi_99_0_ele_30_0_wavSize,
                   HRIR_48K_24bit::azi_99_0_ele_30_0_wav};
  irMap[99][45] = {HRIR_48K_24bit::azi_99_0_ele_45_0_wavSize,
                   HRIR_48K_24bit::azi_99_0_ele_45_0_wav};
  irMap[99][54] = {HRIR_48K_24bit::azi_99_0_ele_54_0_wavSize,
                   HRIR_48K_24bit::azi_99_0_ele_54_0_wav};
  irMap[99][60] = {HRIR_48K_24bit::azi_99_0_ele_60_0_wavSize,
                   HRIR_48K_24bit::azi_99_0_ele_60_0_wav};
  irMap[99][75] = {HRIR_48K_24bit::azi_99_0_ele_75_0_wavSize,
                   HRIR_48K_24bit::azi_99_0_ele_75_0_wav};
  irMap[99][90] = {HRIR_48K_24bit::azi_99_0_ele_90_0_wavSize,
                   HRIR_48K_24bit::azi_99_0_ele_90_0_wav};
  irMap[99][-15] = {HRIR_48K_24bit::azi_99_0_ele_neg15_0_wavSize,
                    HRIR_48K_24bit::azi_99_0_ele_neg15_0_wav};
  irMap[99][-25] = {HRIR_48K_24bit::azi_99_0_ele_neg25_0_wavSize,
                    HRIR_48K_24bit::azi_99_0_ele_neg25_0_wav};
  irMap[99][-30] = {HRIR_48K_24bit::azi_99_0_ele_neg30_0_wavSize,
                    HRIR_48K_24bit::azi_99_0_ele_neg30_0_wav};
  irMap[99][-45] = {HRIR_48K_24bit::azi_99_0_ele_neg45_0_wavSize,
                    HRIR_48K_24bit::azi_99_0_ele_neg45_0_wav};
  irMap[99][-54] = {HRIR_48K_24bit::azi_99_0_ele_neg54_0_wavSize,
                    HRIR_48K_24bit::azi_99_0_ele_neg54_0_wav};
  irMap[99][-60] = {HRIR_48K_24bit::azi_99_0_ele_neg60_0_wavSize,
                    HRIR_48K_24bit::azi_99_0_ele_neg60_0_wav};
  irMap[99][-75] = {HRIR_48K_24bit::azi_99_0_ele_neg75_0_wavSize,
                    HRIR_48K_24bit::azi_99_0_ele_neg75_0_wav};
  irMap[99][-81] = {HRIR_48K_24bit::azi_99_0_ele_neg81_0_wavSize,
                    HRIR_48K_24bit::azi_99_0_ele_neg81_0_wav};
  irMap[100][0] = {HRIR_48K_24bit::azi_100_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_100_0_ele_0_0_wav};
  irMap[100][15] = {HRIR_48K_24bit::azi_100_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_100_0_ele_15_0_wav};
  irMap[100][25] = {HRIR_48K_24bit::azi_100_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_100_0_ele_25_0_wav};
  irMap[100][30] = {HRIR_48K_24bit::azi_100_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_100_0_ele_30_0_wav};
  irMap[100][45] = {HRIR_48K_24bit::azi_100_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_100_0_ele_45_0_wav};
  irMap[100][54] = {HRIR_48K_24bit::azi_100_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_100_0_ele_54_0_wav};
  irMap[100][60] = {HRIR_48K_24bit::azi_100_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_100_0_ele_60_0_wav};
  irMap[100][75] = {HRIR_48K_24bit::azi_100_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_100_0_ele_75_0_wav};
  irMap[100][90] = {HRIR_48K_24bit::azi_100_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_100_0_ele_90_0_wav};
  irMap[100][-15] = {HRIR_48K_24bit::azi_100_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_100_0_ele_neg15_0_wav};
  irMap[100][-25] = {HRIR_48K_24bit::azi_100_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_100_0_ele_neg25_0_wav};
  irMap[100][-30] = {HRIR_48K_24bit::azi_100_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_100_0_ele_neg30_0_wav};
  irMap[100][-45] = {HRIR_48K_24bit::azi_100_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_100_0_ele_neg45_0_wav};
  irMap[100][-54] = {HRIR_48K_24bit::azi_100_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_100_0_ele_neg54_0_wav};
  irMap[100][-60] = {HRIR_48K_24bit::azi_100_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_100_0_ele_neg60_0_wav};
  irMap[100][-75] = {HRIR_48K_24bit::azi_100_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_100_0_ele_neg75_0_wav};
  irMap[100][-81] = {HRIR_48K_24bit::azi_100_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_100_0_ele_neg81_0_wav};
  irMap[101][0] = {HRIR_48K_24bit::azi_101_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_101_0_ele_0_0_wav};
  irMap[101][15] = {HRIR_48K_24bit::azi_101_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_101_0_ele_15_0_wav};
  irMap[101][25] = {HRIR_48K_24bit::azi_101_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_101_0_ele_25_0_wav};
  irMap[101][30] = {HRIR_48K_24bit::azi_101_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_101_0_ele_30_0_wav};
  irMap[101][45] = {HRIR_48K_24bit::azi_101_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_101_0_ele_45_0_wav};
  irMap[101][54] = {HRIR_48K_24bit::azi_101_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_101_0_ele_54_0_wav};
  irMap[101][60] = {HRIR_48K_24bit::azi_101_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_101_0_ele_60_0_wav};
  irMap[101][75] = {HRIR_48K_24bit::azi_101_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_101_0_ele_75_0_wav};
  irMap[101][90] = {HRIR_48K_24bit::azi_101_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_101_0_ele_90_0_wav};
  irMap[101][-15] = {HRIR_48K_24bit::azi_101_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_101_0_ele_neg15_0_wav};
  irMap[101][-25] = {HRIR_48K_24bit::azi_101_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_101_0_ele_neg25_0_wav};
  irMap[101][-30] = {HRIR_48K_24bit::azi_101_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_101_0_ele_neg30_0_wav};
  irMap[101][-45] = {HRIR_48K_24bit::azi_101_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_101_0_ele_neg45_0_wav};
  irMap[101][-54] = {HRIR_48K_24bit::azi_101_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_101_0_ele_neg54_0_wav};
  irMap[101][-60] = {HRIR_48K_24bit::azi_101_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_101_0_ele_neg60_0_wav};
  irMap[101][-75] = {HRIR_48K_24bit::azi_101_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_101_0_ele_neg75_0_wav};
  irMap[101][-81] = {HRIR_48K_24bit::azi_101_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_101_0_ele_neg81_0_wav};
  irMap[102][0] = {HRIR_48K_24bit::azi_102_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_102_0_ele_0_0_wav};
  irMap[102][15] = {HRIR_48K_24bit::azi_102_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_102_0_ele_15_0_wav};
  irMap[102][25] = {HRIR_48K_24bit::azi_102_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_102_0_ele_25_0_wav};
  irMap[102][30] = {HRIR_48K_24bit::azi_102_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_102_0_ele_30_0_wav};
  irMap[102][45] = {HRIR_48K_24bit::azi_102_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_102_0_ele_45_0_wav};
  irMap[102][54] = {HRIR_48K_24bit::azi_102_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_102_0_ele_54_0_wav};
  irMap[102][60] = {HRIR_48K_24bit::azi_102_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_102_0_ele_60_0_wav};
  irMap[102][75] = {HRIR_48K_24bit::azi_102_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_102_0_ele_75_0_wav};
  irMap[102][90] = {HRIR_48K_24bit::azi_102_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_102_0_ele_90_0_wav};
  irMap[102][-15] = {HRIR_48K_24bit::azi_102_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_102_0_ele_neg15_0_wav};
  irMap[102][-25] = {HRIR_48K_24bit::azi_102_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_102_0_ele_neg25_0_wav};
  irMap[102][-30] = {HRIR_48K_24bit::azi_102_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_102_0_ele_neg30_0_wav};
  irMap[102][-45] = {HRIR_48K_24bit::azi_102_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_102_0_ele_neg45_0_wav};
  irMap[102][-54] = {HRIR_48K_24bit::azi_102_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_102_0_ele_neg54_0_wav};
  irMap[102][-60] = {HRIR_48K_24bit::azi_102_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_102_0_ele_neg60_0_wav};
  irMap[102][-75] = {HRIR_48K_24bit::azi_102_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_102_0_ele_neg75_0_wav};
  irMap[102][-81] = {HRIR_48K_24bit::azi_102_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_102_0_ele_neg81_0_wav};
  irMap[103][0] = {HRIR_48K_24bit::azi_103_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_103_0_ele_0_0_wav};
  irMap[103][15] = {HRIR_48K_24bit::azi_103_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_103_0_ele_15_0_wav};
  irMap[103][25] = {HRIR_48K_24bit::azi_103_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_103_0_ele_25_0_wav};
  irMap[103][30] = {HRIR_48K_24bit::azi_103_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_103_0_ele_30_0_wav};
  irMap[103][45] = {HRIR_48K_24bit::azi_103_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_103_0_ele_45_0_wav};
  irMap[103][54] = {HRIR_48K_24bit::azi_103_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_103_0_ele_54_0_wav};
  irMap[103][60] = {HRIR_48K_24bit::azi_103_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_103_0_ele_60_0_wav};
  irMap[103][75] = {HRIR_48K_24bit::azi_103_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_103_0_ele_75_0_wav};
  irMap[103][90] = {HRIR_48K_24bit::azi_103_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_103_0_ele_90_0_wav};
  irMap[103][-15] = {HRIR_48K_24bit::azi_103_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_103_0_ele_neg15_0_wav};
  irMap[103][-25] = {HRIR_48K_24bit::azi_103_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_103_0_ele_neg25_0_wav};
  irMap[103][-30] = {HRIR_48K_24bit::azi_103_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_103_0_ele_neg30_0_wav};
  irMap[103][-45] = {HRIR_48K_24bit::azi_103_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_103_0_ele_neg45_0_wav};
  irMap[103][-54] = {HRIR_48K_24bit::azi_103_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_103_0_ele_neg54_0_wav};
  irMap[103][-60] = {HRIR_48K_24bit::azi_103_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_103_0_ele_neg60_0_wav};
  irMap[103][-75] = {HRIR_48K_24bit::azi_103_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_103_0_ele_neg75_0_wav};
  irMap[103][-81] = {HRIR_48K_24bit::azi_103_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_103_0_ele_neg81_0_wav};
  irMap[104][0] = {HRIR_48K_24bit::azi_104_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_104_0_ele_0_0_wav};
  irMap[104][15] = {HRIR_48K_24bit::azi_104_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_104_0_ele_15_0_wav};
  irMap[104][25] = {HRIR_48K_24bit::azi_104_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_104_0_ele_25_0_wav};
  irMap[104][30] = {HRIR_48K_24bit::azi_104_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_104_0_ele_30_0_wav};
  irMap[104][45] = {HRIR_48K_24bit::azi_104_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_104_0_ele_45_0_wav};
  irMap[104][54] = {HRIR_48K_24bit::azi_104_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_104_0_ele_54_0_wav};
  irMap[104][60] = {HRIR_48K_24bit::azi_104_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_104_0_ele_60_0_wav};
  irMap[104][75] = {HRIR_48K_24bit::azi_104_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_104_0_ele_75_0_wav};
  irMap[104][90] = {HRIR_48K_24bit::azi_104_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_104_0_ele_90_0_wav};
  irMap[104][-15] = {HRIR_48K_24bit::azi_104_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_104_0_ele_neg15_0_wav};
  irMap[104][-25] = {HRIR_48K_24bit::azi_104_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_104_0_ele_neg25_0_wav};
  irMap[104][-30] = {HRIR_48K_24bit::azi_104_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_104_0_ele_neg30_0_wav};
  irMap[104][-45] = {HRIR_48K_24bit::azi_104_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_104_0_ele_neg45_0_wav};
  irMap[104][-54] = {HRIR_48K_24bit::azi_104_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_104_0_ele_neg54_0_wav};
  irMap[104][-60] = {HRIR_48K_24bit::azi_104_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_104_0_ele_neg60_0_wav};
  irMap[104][-75] = {HRIR_48K_24bit::azi_104_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_104_0_ele_neg75_0_wav};
  irMap[104][-81] = {HRIR_48K_24bit::azi_104_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_104_0_ele_neg81_0_wav};
  irMap[105][0] = {HRIR_48K_24bit::azi_105_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_105_0_ele_0_0_wav};
  irMap[105][15] = {HRIR_48K_24bit::azi_105_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_105_0_ele_15_0_wav};
  irMap[105][25] = {HRIR_48K_24bit::azi_105_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_105_0_ele_25_0_wav};
  irMap[105][30] = {HRIR_48K_24bit::azi_105_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_105_0_ele_30_0_wav};
  irMap[105][45] = {HRIR_48K_24bit::azi_105_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_105_0_ele_45_0_wav};
  irMap[105][54] = {HRIR_48K_24bit::azi_105_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_105_0_ele_54_0_wav};
  irMap[105][60] = {HRIR_48K_24bit::azi_105_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_105_0_ele_60_0_wav};
  irMap[105][75] = {HRIR_48K_24bit::azi_105_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_105_0_ele_75_0_wav};
  irMap[105][90] = {HRIR_48K_24bit::azi_105_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_105_0_ele_90_0_wav};
  irMap[105][-15] = {HRIR_48K_24bit::azi_105_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_105_0_ele_neg15_0_wav};
  irMap[105][-25] = {HRIR_48K_24bit::azi_105_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_105_0_ele_neg25_0_wav};
  irMap[105][-30] = {HRIR_48K_24bit::azi_105_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_105_0_ele_neg30_0_wav};
  irMap[105][-45] = {HRIR_48K_24bit::azi_105_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_105_0_ele_neg45_0_wav};
  irMap[105][-54] = {HRIR_48K_24bit::azi_105_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_105_0_ele_neg54_0_wav};
  irMap[105][-60] = {HRIR_48K_24bit::azi_105_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_105_0_ele_neg60_0_wav};
  irMap[105][-75] = {HRIR_48K_24bit::azi_105_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_105_0_ele_neg75_0_wav};
  irMap[105][-81] = {HRIR_48K_24bit::azi_105_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_105_0_ele_neg81_0_wav};
  irMap[106][0] = {HRIR_48K_24bit::azi_106_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_106_0_ele_0_0_wav};
  irMap[106][15] = {HRIR_48K_24bit::azi_106_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_106_0_ele_15_0_wav};
  irMap[106][25] = {HRIR_48K_24bit::azi_106_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_106_0_ele_25_0_wav};
  irMap[106][30] = {HRIR_48K_24bit::azi_106_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_106_0_ele_30_0_wav};
  irMap[106][45] = {HRIR_48K_24bit::azi_106_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_106_0_ele_45_0_wav};
  irMap[106][54] = {HRIR_48K_24bit::azi_106_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_106_0_ele_54_0_wav};
  irMap[106][60] = {HRIR_48K_24bit::azi_106_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_106_0_ele_60_0_wav};
  irMap[106][75] = {HRIR_48K_24bit::azi_106_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_106_0_ele_75_0_wav};
  irMap[106][90] = {HRIR_48K_24bit::azi_106_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_106_0_ele_90_0_wav};
  irMap[106][-15] = {HRIR_48K_24bit::azi_106_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_106_0_ele_neg15_0_wav};
  irMap[106][-25] = {HRIR_48K_24bit::azi_106_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_106_0_ele_neg25_0_wav};
  irMap[106][-30] = {HRIR_48K_24bit::azi_106_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_106_0_ele_neg30_0_wav};
  irMap[106][-45] = {HRIR_48K_24bit::azi_106_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_106_0_ele_neg45_0_wav};
  irMap[106][-54] = {HRIR_48K_24bit::azi_106_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_106_0_ele_neg54_0_wav};
  irMap[106][-60] = {HRIR_48K_24bit::azi_106_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_106_0_ele_neg60_0_wav};
  irMap[106][-75] = {HRIR_48K_24bit::azi_106_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_106_0_ele_neg75_0_wav};
  irMap[106][-81] = {HRIR_48K_24bit::azi_106_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_106_0_ele_neg81_0_wav};
  irMap[107][0] = {HRIR_48K_24bit::azi_107_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_107_0_ele_0_0_wav};
  irMap[107][15] = {HRIR_48K_24bit::azi_107_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_107_0_ele_15_0_wav};
  irMap[107][25] = {HRIR_48K_24bit::azi_107_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_107_0_ele_25_0_wav};
  irMap[107][30] = {HRIR_48K_24bit::azi_107_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_107_0_ele_30_0_wav};
  irMap[107][45] = {HRIR_48K_24bit::azi_107_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_107_0_ele_45_0_wav};
  irMap[107][54] = {HRIR_48K_24bit::azi_107_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_107_0_ele_54_0_wav};
  irMap[107][60] = {HRIR_48K_24bit::azi_107_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_107_0_ele_60_0_wav};
  irMap[107][75] = {HRIR_48K_24bit::azi_107_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_107_0_ele_75_0_wav};
  irMap[107][90] = {HRIR_48K_24bit::azi_107_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_107_0_ele_90_0_wav};
  irMap[107][-15] = {HRIR_48K_24bit::azi_107_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_107_0_ele_neg15_0_wav};
  irMap[107][-25] = {HRIR_48K_24bit::azi_107_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_107_0_ele_neg25_0_wav};
  irMap[107][-30] = {HRIR_48K_24bit::azi_107_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_107_0_ele_neg30_0_wav};
  irMap[107][-45] = {HRIR_48K_24bit::azi_107_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_107_0_ele_neg45_0_wav};
  irMap[107][-54] = {HRIR_48K_24bit::azi_107_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_107_0_ele_neg54_0_wav};
  irMap[107][-60] = {HRIR_48K_24bit::azi_107_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_107_0_ele_neg60_0_wav};
  irMap[107][-75] = {HRIR_48K_24bit::azi_107_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_107_0_ele_neg75_0_wav};
  irMap[107][-81] = {HRIR_48K_24bit::azi_107_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_107_0_ele_neg81_0_wav};
  irMap[108][0] = {HRIR_48K_24bit::azi_108_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_108_0_ele_0_0_wav};
  irMap[108][15] = {HRIR_48K_24bit::azi_108_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_108_0_ele_15_0_wav};
  irMap[108][25] = {HRIR_48K_24bit::azi_108_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_108_0_ele_25_0_wav};
  irMap[108][30] = {HRIR_48K_24bit::azi_108_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_108_0_ele_30_0_wav};
  irMap[108][45] = {HRIR_48K_24bit::azi_108_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_108_0_ele_45_0_wav};
  irMap[108][54] = {HRIR_48K_24bit::azi_108_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_108_0_ele_54_0_wav};
  irMap[108][60] = {HRIR_48K_24bit::azi_108_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_108_0_ele_60_0_wav};
  irMap[108][75] = {HRIR_48K_24bit::azi_108_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_108_0_ele_75_0_wav};
  irMap[108][90] = {HRIR_48K_24bit::azi_108_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_108_0_ele_90_0_wav};
  irMap[108][-15] = {HRIR_48K_24bit::azi_108_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_108_0_ele_neg15_0_wav};
  irMap[108][-25] = {HRIR_48K_24bit::azi_108_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_108_0_ele_neg25_0_wav};
  irMap[108][-30] = {HRIR_48K_24bit::azi_108_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_108_0_ele_neg30_0_wav};
  irMap[108][-45] = {HRIR_48K_24bit::azi_108_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_108_0_ele_neg45_0_wav};
  irMap[108][-54] = {HRIR_48K_24bit::azi_108_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_108_0_ele_neg54_0_wav};
  irMap[108][-60] = {HRIR_48K_24bit::azi_108_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_108_0_ele_neg60_0_wav};
  irMap[108][-75] = {HRIR_48K_24bit::azi_108_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_108_0_ele_neg75_0_wav};
  irMap[108][-81] = {HRIR_48K_24bit::azi_108_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_108_0_ele_neg81_0_wav};
  irMap[109][0] = {HRIR_48K_24bit::azi_109_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_109_0_ele_0_0_wav};
  irMap[109][15] = {HRIR_48K_24bit::azi_109_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_109_0_ele_15_0_wav};
  irMap[109][25] = {HRIR_48K_24bit::azi_109_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_109_0_ele_25_0_wav};
  irMap[109][30] = {HRIR_48K_24bit::azi_109_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_109_0_ele_30_0_wav};
  irMap[109][45] = {HRIR_48K_24bit::azi_109_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_109_0_ele_45_0_wav};
  irMap[109][54] = {HRIR_48K_24bit::azi_109_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_109_0_ele_54_0_wav};
  irMap[109][60] = {HRIR_48K_24bit::azi_109_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_109_0_ele_60_0_wav};
  irMap[109][75] = {HRIR_48K_24bit::azi_109_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_109_0_ele_75_0_wav};
  irMap[109][90] = {HRIR_48K_24bit::azi_109_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_109_0_ele_90_0_wav};
  irMap[109][-15] = {HRIR_48K_24bit::azi_109_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_109_0_ele_neg15_0_wav};
  irMap[109][-25] = {HRIR_48K_24bit::azi_109_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_109_0_ele_neg25_0_wav};
  irMap[109][-30] = {HRIR_48K_24bit::azi_109_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_109_0_ele_neg30_0_wav};
  irMap[109][-45] = {HRIR_48K_24bit::azi_109_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_109_0_ele_neg45_0_wav};
  irMap[109][-54] = {HRIR_48K_24bit::azi_109_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_109_0_ele_neg54_0_wav};
  irMap[109][-60] = {HRIR_48K_24bit::azi_109_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_109_0_ele_neg60_0_wav};
  irMap[109][-75] = {HRIR_48K_24bit::azi_109_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_109_0_ele_neg75_0_wav};
  irMap[109][-81] = {HRIR_48K_24bit::azi_109_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_109_0_ele_neg81_0_wav};
  irMap[110][0] = {HRIR_48K_24bit::azi_110_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_110_0_ele_0_0_wav};
  irMap[110][15] = {HRIR_48K_24bit::azi_110_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_110_0_ele_15_0_wav};
  irMap[110][25] = {HRIR_48K_24bit::azi_110_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_110_0_ele_25_0_wav};
  irMap[110][30] = {HRIR_48K_24bit::azi_110_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_110_0_ele_30_0_wav};
  irMap[110][45] = {HRIR_48K_24bit::azi_110_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_110_0_ele_45_0_wav};
  irMap[110][54] = {HRIR_48K_24bit::azi_110_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_110_0_ele_54_0_wav};
  irMap[110][60] = {HRIR_48K_24bit::azi_110_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_110_0_ele_60_0_wav};
  irMap[110][75] = {HRIR_48K_24bit::azi_110_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_110_0_ele_75_0_wav};
  irMap[110][90] = {HRIR_48K_24bit::azi_110_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_110_0_ele_90_0_wav};
  irMap[110][-15] = {HRIR_48K_24bit::azi_110_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_110_0_ele_neg15_0_wav};
  irMap[110][-25] = {HRIR_48K_24bit::azi_110_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_110_0_ele_neg25_0_wav};
  irMap[110][-30] = {HRIR_48K_24bit::azi_110_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_110_0_ele_neg30_0_wav};
  irMap[110][-45] = {HRIR_48K_24bit::azi_110_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_110_0_ele_neg45_0_wav};
  irMap[110][-54] = {HRIR_48K_24bit::azi_110_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_110_0_ele_neg54_0_wav};
  irMap[110][-60] = {HRIR_48K_24bit::azi_110_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_110_0_ele_neg60_0_wav};
  irMap[110][-75] = {HRIR_48K_24bit::azi_110_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_110_0_ele_neg75_0_wav};
  irMap[110][-81] = {HRIR_48K_24bit::azi_110_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_110_0_ele_neg81_0_wav};
  irMap[111][0] = {HRIR_48K_24bit::azi_111_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_111_0_ele_0_0_wav};
  irMap[111][15] = {HRIR_48K_24bit::azi_111_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_111_0_ele_15_0_wav};
  irMap[111][25] = {HRIR_48K_24bit::azi_111_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_111_0_ele_25_0_wav};
  irMap[111][30] = {HRIR_48K_24bit::azi_111_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_111_0_ele_30_0_wav};
  irMap[111][45] = {HRIR_48K_24bit::azi_111_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_111_0_ele_45_0_wav};
  irMap[111][54] = {HRIR_48K_24bit::azi_111_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_111_0_ele_54_0_wav};
  irMap[111][60] = {HRIR_48K_24bit::azi_111_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_111_0_ele_60_0_wav};
  irMap[111][75] = {HRIR_48K_24bit::azi_111_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_111_0_ele_75_0_wav};
  irMap[111][90] = {HRIR_48K_24bit::azi_111_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_111_0_ele_90_0_wav};
  irMap[111][-15] = {HRIR_48K_24bit::azi_111_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_111_0_ele_neg15_0_wav};
  irMap[111][-25] = {HRIR_48K_24bit::azi_111_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_111_0_ele_neg25_0_wav};
  irMap[111][-30] = {HRIR_48K_24bit::azi_111_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_111_0_ele_neg30_0_wav};
  irMap[111][-45] = {HRIR_48K_24bit::azi_111_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_111_0_ele_neg45_0_wav};
  irMap[111][-54] = {HRIR_48K_24bit::azi_111_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_111_0_ele_neg54_0_wav};
  irMap[111][-60] = {HRIR_48K_24bit::azi_111_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_111_0_ele_neg60_0_wav};
  irMap[111][-75] = {HRIR_48K_24bit::azi_111_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_111_0_ele_neg75_0_wav};
  irMap[111][-81] = {HRIR_48K_24bit::azi_111_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_111_0_ele_neg81_0_wav};
  irMap[112][0] = {HRIR_48K_24bit::azi_112_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_112_0_ele_0_0_wav};
  irMap[112][15] = {HRIR_48K_24bit::azi_112_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_112_0_ele_15_0_wav};
  irMap[112][25] = {HRIR_48K_24bit::azi_112_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_112_0_ele_25_0_wav};
  irMap[112][30] = {HRIR_48K_24bit::azi_112_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_112_0_ele_30_0_wav};
  irMap[112][45] = {HRIR_48K_24bit::azi_112_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_112_0_ele_45_0_wav};
  irMap[112][54] = {HRIR_48K_24bit::azi_112_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_112_0_ele_54_0_wav};
  irMap[112][60] = {HRIR_48K_24bit::azi_112_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_112_0_ele_60_0_wav};
  irMap[112][75] = {HRIR_48K_24bit::azi_112_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_112_0_ele_75_0_wav};
  irMap[112][90] = {HRIR_48K_24bit::azi_112_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_112_0_ele_90_0_wav};
  irMap[112][-15] = {HRIR_48K_24bit::azi_112_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_112_0_ele_neg15_0_wav};
  irMap[112][-25] = {HRIR_48K_24bit::azi_112_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_112_0_ele_neg25_0_wav};
  irMap[112][-30] = {HRIR_48K_24bit::azi_112_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_112_0_ele_neg30_0_wav};
  irMap[112][-45] = {HRIR_48K_24bit::azi_112_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_112_0_ele_neg45_0_wav};
  irMap[112][-54] = {HRIR_48K_24bit::azi_112_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_112_0_ele_neg54_0_wav};
  irMap[112][-60] = {HRIR_48K_24bit::azi_112_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_112_0_ele_neg60_0_wav};
  irMap[112][-75] = {HRIR_48K_24bit::azi_112_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_112_0_ele_neg75_0_wav};
  irMap[112][-81] = {HRIR_48K_24bit::azi_112_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_112_0_ele_neg81_0_wav};
  irMap[113][0] = {HRIR_48K_24bit::azi_113_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_113_0_ele_0_0_wav};
  irMap[113][15] = {HRIR_48K_24bit::azi_113_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_113_0_ele_15_0_wav};
  irMap[113][25] = {HRIR_48K_24bit::azi_113_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_113_0_ele_25_0_wav};
  irMap[113][30] = {HRIR_48K_24bit::azi_113_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_113_0_ele_30_0_wav};
  irMap[113][45] = {HRIR_48K_24bit::azi_113_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_113_0_ele_45_0_wav};
  irMap[113][54] = {HRIR_48K_24bit::azi_113_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_113_0_ele_54_0_wav};
  irMap[113][60] = {HRIR_48K_24bit::azi_113_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_113_0_ele_60_0_wav};
  irMap[113][75] = {HRIR_48K_24bit::azi_113_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_113_0_ele_75_0_wav};
  irMap[113][90] = {HRIR_48K_24bit::azi_113_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_113_0_ele_90_0_wav};
  irMap[113][-15] = {HRIR_48K_24bit::azi_113_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_113_0_ele_neg15_0_wav};
  irMap[113][-25] = {HRIR_48K_24bit::azi_113_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_113_0_ele_neg25_0_wav};
  irMap[113][-30] = {HRIR_48K_24bit::azi_113_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_113_0_ele_neg30_0_wav};
  irMap[113][-45] = {HRIR_48K_24bit::azi_113_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_113_0_ele_neg45_0_wav};
  irMap[113][-54] = {HRIR_48K_24bit::azi_113_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_113_0_ele_neg54_0_wav};
  irMap[113][-60] = {HRIR_48K_24bit::azi_113_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_113_0_ele_neg60_0_wav};
  irMap[113][-75] = {HRIR_48K_24bit::azi_113_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_113_0_ele_neg75_0_wav};
  irMap[113][-81] = {HRIR_48K_24bit::azi_113_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_113_0_ele_neg81_0_wav};
  irMap[114][0] = {HRIR_48K_24bit::azi_114_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_114_0_ele_0_0_wav};
  irMap[114][15] = {HRIR_48K_24bit::azi_114_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_114_0_ele_15_0_wav};
  irMap[114][25] = {HRIR_48K_24bit::azi_114_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_114_0_ele_25_0_wav};
  irMap[114][30] = {HRIR_48K_24bit::azi_114_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_114_0_ele_30_0_wav};
  irMap[114][45] = {HRIR_48K_24bit::azi_114_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_114_0_ele_45_0_wav};
  irMap[114][54] = {HRIR_48K_24bit::azi_114_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_114_0_ele_54_0_wav};
  irMap[114][60] = {HRIR_48K_24bit::azi_114_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_114_0_ele_60_0_wav};
  irMap[114][75] = {HRIR_48K_24bit::azi_114_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_114_0_ele_75_0_wav};
  irMap[114][90] = {HRIR_48K_24bit::azi_114_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_114_0_ele_90_0_wav};
  irMap[114][-15] = {HRIR_48K_24bit::azi_114_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_114_0_ele_neg15_0_wav};
  irMap[114][-25] = {HRIR_48K_24bit::azi_114_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_114_0_ele_neg25_0_wav};
  irMap[114][-30] = {HRIR_48K_24bit::azi_114_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_114_0_ele_neg30_0_wav};
  irMap[114][-45] = {HRIR_48K_24bit::azi_114_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_114_0_ele_neg45_0_wav};
  irMap[114][-54] = {HRIR_48K_24bit::azi_114_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_114_0_ele_neg54_0_wav};
  irMap[114][-60] = {HRIR_48K_24bit::azi_114_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_114_0_ele_neg60_0_wav};
  irMap[114][-75] = {HRIR_48K_24bit::azi_114_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_114_0_ele_neg75_0_wav};
  irMap[114][-81] = {HRIR_48K_24bit::azi_114_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_114_0_ele_neg81_0_wav};
  irMap[115][0] = {HRIR_48K_24bit::azi_115_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_115_0_ele_0_0_wav};
  irMap[115][15] = {HRIR_48K_24bit::azi_115_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_115_0_ele_15_0_wav};
  irMap[115][25] = {HRIR_48K_24bit::azi_115_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_115_0_ele_25_0_wav};
  irMap[115][30] = {HRIR_48K_24bit::azi_115_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_115_0_ele_30_0_wav};
  irMap[115][45] = {HRIR_48K_24bit::azi_115_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_115_0_ele_45_0_wav};
  irMap[115][54] = {HRIR_48K_24bit::azi_115_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_115_0_ele_54_0_wav};
  irMap[115][60] = {HRIR_48K_24bit::azi_115_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_115_0_ele_60_0_wav};
  irMap[115][75] = {HRIR_48K_24bit::azi_115_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_115_0_ele_75_0_wav};
  irMap[115][90] = {HRIR_48K_24bit::azi_115_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_115_0_ele_90_0_wav};
  irMap[115][-15] = {HRIR_48K_24bit::azi_115_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_115_0_ele_neg15_0_wav};
  irMap[115][-25] = {HRIR_48K_24bit::azi_115_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_115_0_ele_neg25_0_wav};
  irMap[115][-30] = {HRIR_48K_24bit::azi_115_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_115_0_ele_neg30_0_wav};
  irMap[115][-45] = {HRIR_48K_24bit::azi_115_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_115_0_ele_neg45_0_wav};
  irMap[115][-54] = {HRIR_48K_24bit::azi_115_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_115_0_ele_neg54_0_wav};
  irMap[115][-60] = {HRIR_48K_24bit::azi_115_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_115_0_ele_neg60_0_wav};
  irMap[115][-75] = {HRIR_48K_24bit::azi_115_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_115_0_ele_neg75_0_wav};
  irMap[115][-81] = {HRIR_48K_24bit::azi_115_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_115_0_ele_neg81_0_wav};
  irMap[116][0] = {HRIR_48K_24bit::azi_116_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_116_0_ele_0_0_wav};
  irMap[116][15] = {HRIR_48K_24bit::azi_116_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_116_0_ele_15_0_wav};
  irMap[116][25] = {HRIR_48K_24bit::azi_116_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_116_0_ele_25_0_wav};
  irMap[116][30] = {HRIR_48K_24bit::azi_116_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_116_0_ele_30_0_wav};
  irMap[116][45] = {HRIR_48K_24bit::azi_116_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_116_0_ele_45_0_wav};
  irMap[116][54] = {HRIR_48K_24bit::azi_116_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_116_0_ele_54_0_wav};
  irMap[116][60] = {HRIR_48K_24bit::azi_116_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_116_0_ele_60_0_wav};
  irMap[116][75] = {HRIR_48K_24bit::azi_116_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_116_0_ele_75_0_wav};
  irMap[116][90] = {HRIR_48K_24bit::azi_116_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_116_0_ele_90_0_wav};
  irMap[116][-15] = {HRIR_48K_24bit::azi_116_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_116_0_ele_neg15_0_wav};
  irMap[116][-25] = {HRIR_48K_24bit::azi_116_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_116_0_ele_neg25_0_wav};
  irMap[116][-30] = {HRIR_48K_24bit::azi_116_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_116_0_ele_neg30_0_wav};
  irMap[116][-45] = {HRIR_48K_24bit::azi_116_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_116_0_ele_neg45_0_wav};
  irMap[116][-54] = {HRIR_48K_24bit::azi_116_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_116_0_ele_neg54_0_wav};
  irMap[116][-60] = {HRIR_48K_24bit::azi_116_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_116_0_ele_neg60_0_wav};
  irMap[116][-75] = {HRIR_48K_24bit::azi_116_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_116_0_ele_neg75_0_wav};
  irMap[116][-81] = {HRIR_48K_24bit::azi_116_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_116_0_ele_neg81_0_wav};
  irMap[117][0] = {HRIR_48K_24bit::azi_117_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_117_0_ele_0_0_wav};
  irMap[117][15] = {HRIR_48K_24bit::azi_117_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_117_0_ele_15_0_wav};
  irMap[117][25] = {HRIR_48K_24bit::azi_117_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_117_0_ele_25_0_wav};
  irMap[117][30] = {HRIR_48K_24bit::azi_117_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_117_0_ele_30_0_wav};
  irMap[117][45] = {HRIR_48K_24bit::azi_117_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_117_0_ele_45_0_wav};
  irMap[117][54] = {HRIR_48K_24bit::azi_117_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_117_0_ele_54_0_wav};
  irMap[117][60] = {HRIR_48K_24bit::azi_117_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_117_0_ele_60_0_wav};
  irMap[117][75] = {HRIR_48K_24bit::azi_117_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_117_0_ele_75_0_wav};
  irMap[117][90] = {HRIR_48K_24bit::azi_117_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_117_0_ele_90_0_wav};
  irMap[117][-15] = {HRIR_48K_24bit::azi_117_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_117_0_ele_neg15_0_wav};
  irMap[117][-25] = {HRIR_48K_24bit::azi_117_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_117_0_ele_neg25_0_wav};
  irMap[117][-30] = {HRIR_48K_24bit::azi_117_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_117_0_ele_neg30_0_wav};
  irMap[117][-45] = {HRIR_48K_24bit::azi_117_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_117_0_ele_neg45_0_wav};
  irMap[117][-54] = {HRIR_48K_24bit::azi_117_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_117_0_ele_neg54_0_wav};
  irMap[117][-60] = {HRIR_48K_24bit::azi_117_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_117_0_ele_neg60_0_wav};
  irMap[117][-75] = {HRIR_48K_24bit::azi_117_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_117_0_ele_neg75_0_wav};
  irMap[117][-81] = {HRIR_48K_24bit::azi_117_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_117_0_ele_neg81_0_wav};
  irMap[118][0] = {HRIR_48K_24bit::azi_118_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_118_0_ele_0_0_wav};
  irMap[118][15] = {HRIR_48K_24bit::azi_118_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_118_0_ele_15_0_wav};
  irMap[118][25] = {HRIR_48K_24bit::azi_118_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_118_0_ele_25_0_wav};
  irMap[118][30] = {HRIR_48K_24bit::azi_118_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_118_0_ele_30_0_wav};
  irMap[118][45] = {HRIR_48K_24bit::azi_118_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_118_0_ele_45_0_wav};
  irMap[118][54] = {HRIR_48K_24bit::azi_118_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_118_0_ele_54_0_wav};
  irMap[118][60] = {HRIR_48K_24bit::azi_118_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_118_0_ele_60_0_wav};
  irMap[118][75] = {HRIR_48K_24bit::azi_118_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_118_0_ele_75_0_wav};
  irMap[118][90] = {HRIR_48K_24bit::azi_118_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_118_0_ele_90_0_wav};
  irMap[118][-15] = {HRIR_48K_24bit::azi_118_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_118_0_ele_neg15_0_wav};
  irMap[118][-25] = {HRIR_48K_24bit::azi_118_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_118_0_ele_neg25_0_wav};
  irMap[118][-30] = {HRIR_48K_24bit::azi_118_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_118_0_ele_neg30_0_wav};
  irMap[118][-45] = {HRIR_48K_24bit::azi_118_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_118_0_ele_neg45_0_wav};
  irMap[118][-54] = {HRIR_48K_24bit::azi_118_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_118_0_ele_neg54_0_wav};
  irMap[118][-60] = {HRIR_48K_24bit::azi_118_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_118_0_ele_neg60_0_wav};
  irMap[118][-75] = {HRIR_48K_24bit::azi_118_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_118_0_ele_neg75_0_wav};
  irMap[118][-81] = {HRIR_48K_24bit::azi_118_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_118_0_ele_neg81_0_wav};
  irMap[119][0] = {HRIR_48K_24bit::azi_119_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_119_0_ele_0_0_wav};
  irMap[119][15] = {HRIR_48K_24bit::azi_119_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_119_0_ele_15_0_wav};
  irMap[119][25] = {HRIR_48K_24bit::azi_119_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_119_0_ele_25_0_wav};
  irMap[119][30] = {HRIR_48K_24bit::azi_119_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_119_0_ele_30_0_wav};
  irMap[119][45] = {HRIR_48K_24bit::azi_119_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_119_0_ele_45_0_wav};
  irMap[119][54] = {HRIR_48K_24bit::azi_119_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_119_0_ele_54_0_wav};
  irMap[119][60] = {HRIR_48K_24bit::azi_119_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_119_0_ele_60_0_wav};
  irMap[119][75] = {HRIR_48K_24bit::azi_119_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_119_0_ele_75_0_wav};
  irMap[119][90] = {HRIR_48K_24bit::azi_119_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_119_0_ele_90_0_wav};
  irMap[119][-15] = {HRIR_48K_24bit::azi_119_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_119_0_ele_neg15_0_wav};
  irMap[119][-25] = {HRIR_48K_24bit::azi_119_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_119_0_ele_neg25_0_wav};
  irMap[119][-30] = {HRIR_48K_24bit::azi_119_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_119_0_ele_neg30_0_wav};
  irMap[119][-45] = {HRIR_48K_24bit::azi_119_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_119_0_ele_neg45_0_wav};
  irMap[119][-54] = {HRIR_48K_24bit::azi_119_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_119_0_ele_neg54_0_wav};
  irMap[119][-60] = {HRIR_48K_24bit::azi_119_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_119_0_ele_neg60_0_wav};
  irMap[119][-75] = {HRIR_48K_24bit::azi_119_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_119_0_ele_neg75_0_wav};
  irMap[119][-81] = {HRIR_48K_24bit::azi_119_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_119_0_ele_neg81_0_wav};
  irMap[120][0] = {HRIR_48K_24bit::azi_120_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_120_0_ele_0_0_wav};
  irMap[120][15] = {HRIR_48K_24bit::azi_120_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_120_0_ele_15_0_wav};
  irMap[120][25] = {HRIR_48K_24bit::azi_120_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_120_0_ele_25_0_wav};
  irMap[120][30] = {HRIR_48K_24bit::azi_120_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_120_0_ele_30_0_wav};
  irMap[120][45] = {HRIR_48K_24bit::azi_120_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_120_0_ele_45_0_wav};
  irMap[120][54] = {HRIR_48K_24bit::azi_120_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_120_0_ele_54_0_wav};
  irMap[120][60] = {HRIR_48K_24bit::azi_120_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_120_0_ele_60_0_wav};
  irMap[120][75] = {HRIR_48K_24bit::azi_120_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_120_0_ele_75_0_wav};
  irMap[120][90] = {HRIR_48K_24bit::azi_120_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_120_0_ele_90_0_wav};
  irMap[120][-15] = {HRIR_48K_24bit::azi_120_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_120_0_ele_neg15_0_wav};
  irMap[120][-25] = {HRIR_48K_24bit::azi_120_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_120_0_ele_neg25_0_wav};
  irMap[120][-30] = {HRIR_48K_24bit::azi_120_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_120_0_ele_neg30_0_wav};
  irMap[120][-45] = {HRIR_48K_24bit::azi_120_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_120_0_ele_neg45_0_wav};
  irMap[120][-54] = {HRIR_48K_24bit::azi_120_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_120_0_ele_neg54_0_wav};
  irMap[120][-60] = {HRIR_48K_24bit::azi_120_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_120_0_ele_neg60_0_wav};
  irMap[120][-75] = {HRIR_48K_24bit::azi_120_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_120_0_ele_neg75_0_wav};
  irMap[120][-81] = {HRIR_48K_24bit::azi_120_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_120_0_ele_neg81_0_wav};
  irMap[121][0] = {HRIR_48K_24bit::azi_121_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_121_0_ele_0_0_wav};
  irMap[121][15] = {HRIR_48K_24bit::azi_121_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_121_0_ele_15_0_wav};
  irMap[121][25] = {HRIR_48K_24bit::azi_121_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_121_0_ele_25_0_wav};
  irMap[121][30] = {HRIR_48K_24bit::azi_121_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_121_0_ele_30_0_wav};
  irMap[121][45] = {HRIR_48K_24bit::azi_121_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_121_0_ele_45_0_wav};
  irMap[121][54] = {HRIR_48K_24bit::azi_121_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_121_0_ele_54_0_wav};
  irMap[121][60] = {HRIR_48K_24bit::azi_121_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_121_0_ele_60_0_wav};
  irMap[121][75] = {HRIR_48K_24bit::azi_121_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_121_0_ele_75_0_wav};
  irMap[121][90] = {HRIR_48K_24bit::azi_121_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_121_0_ele_90_0_wav};
  irMap[121][-15] = {HRIR_48K_24bit::azi_121_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_121_0_ele_neg15_0_wav};
  irMap[121][-25] = {HRIR_48K_24bit::azi_121_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_121_0_ele_neg25_0_wav};
  irMap[121][-30] = {HRIR_48K_24bit::azi_121_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_121_0_ele_neg30_0_wav};
  irMap[121][-45] = {HRIR_48K_24bit::azi_121_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_121_0_ele_neg45_0_wav};
  irMap[121][-54] = {HRIR_48K_24bit::azi_121_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_121_0_ele_neg54_0_wav};
  irMap[121][-60] = {HRIR_48K_24bit::azi_121_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_121_0_ele_neg60_0_wav};
  irMap[121][-75] = {HRIR_48K_24bit::azi_121_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_121_0_ele_neg75_0_wav};
  irMap[121][-81] = {HRIR_48K_24bit::azi_121_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_121_0_ele_neg81_0_wav};
  irMap[122][0] = {HRIR_48K_24bit::azi_122_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_122_0_ele_0_0_wav};
  irMap[122][15] = {HRIR_48K_24bit::azi_122_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_122_0_ele_15_0_wav};
  irMap[122][25] = {HRIR_48K_24bit::azi_122_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_122_0_ele_25_0_wav};
  irMap[122][30] = {HRIR_48K_24bit::azi_122_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_122_0_ele_30_0_wav};
  irMap[122][45] = {HRIR_48K_24bit::azi_122_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_122_0_ele_45_0_wav};
  irMap[122][54] = {HRIR_48K_24bit::azi_122_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_122_0_ele_54_0_wav};
  irMap[122][60] = {HRIR_48K_24bit::azi_122_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_122_0_ele_60_0_wav};
  irMap[122][75] = {HRIR_48K_24bit::azi_122_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_122_0_ele_75_0_wav};
  irMap[122][90] = {HRIR_48K_24bit::azi_122_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_122_0_ele_90_0_wav};
  irMap[122][-15] = {HRIR_48K_24bit::azi_122_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_122_0_ele_neg15_0_wav};
  irMap[122][-25] = {HRIR_48K_24bit::azi_122_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_122_0_ele_neg25_0_wav};
  irMap[122][-30] = {HRIR_48K_24bit::azi_122_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_122_0_ele_neg30_0_wav};
  irMap[122][-45] = {HRIR_48K_24bit::azi_122_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_122_0_ele_neg45_0_wav};
  irMap[122][-54] = {HRIR_48K_24bit::azi_122_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_122_0_ele_neg54_0_wav};
  irMap[122][-60] = {HRIR_48K_24bit::azi_122_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_122_0_ele_neg60_0_wav};
  irMap[122][-75] = {HRIR_48K_24bit::azi_122_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_122_0_ele_neg75_0_wav};
  irMap[122][-81] = {HRIR_48K_24bit::azi_122_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_122_0_ele_neg81_0_wav};
  irMap[123][0] = {HRIR_48K_24bit::azi_123_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_123_0_ele_0_0_wav};
  irMap[123][15] = {HRIR_48K_24bit::azi_123_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_123_0_ele_15_0_wav};
  irMap[123][25] = {HRIR_48K_24bit::azi_123_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_123_0_ele_25_0_wav};
  irMap[123][30] = {HRIR_48K_24bit::azi_123_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_123_0_ele_30_0_wav};
  irMap[123][45] = {HRIR_48K_24bit::azi_123_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_123_0_ele_45_0_wav};
  irMap[123][54] = {HRIR_48K_24bit::azi_123_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_123_0_ele_54_0_wav};
  irMap[123][60] = {HRIR_48K_24bit::azi_123_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_123_0_ele_60_0_wav};
  irMap[123][75] = {HRIR_48K_24bit::azi_123_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_123_0_ele_75_0_wav};
  irMap[123][90] = {HRIR_48K_24bit::azi_123_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_123_0_ele_90_0_wav};
  irMap[123][-15] = {HRIR_48K_24bit::azi_123_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_123_0_ele_neg15_0_wav};
  irMap[123][-25] = {HRIR_48K_24bit::azi_123_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_123_0_ele_neg25_0_wav};
  irMap[123][-30] = {HRIR_48K_24bit::azi_123_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_123_0_ele_neg30_0_wav};
  irMap[123][-45] = {HRIR_48K_24bit::azi_123_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_123_0_ele_neg45_0_wav};
  irMap[123][-54] = {HRIR_48K_24bit::azi_123_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_123_0_ele_neg54_0_wav};
  irMap[123][-60] = {HRIR_48K_24bit::azi_123_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_123_0_ele_neg60_0_wav};
  irMap[123][-75] = {HRIR_48K_24bit::azi_123_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_123_0_ele_neg75_0_wav};
  irMap[123][-81] = {HRIR_48K_24bit::azi_123_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_123_0_ele_neg81_0_wav};
  irMap[124][0] = {HRIR_48K_24bit::azi_124_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_124_0_ele_0_0_wav};
  irMap[124][15] = {HRIR_48K_24bit::azi_124_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_124_0_ele_15_0_wav};
  irMap[124][25] = {HRIR_48K_24bit::azi_124_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_124_0_ele_25_0_wav};
  irMap[124][30] = {HRIR_48K_24bit::azi_124_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_124_0_ele_30_0_wav};
  irMap[124][45] = {HRIR_48K_24bit::azi_124_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_124_0_ele_45_0_wav};
  irMap[124][54] = {HRIR_48K_24bit::azi_124_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_124_0_ele_54_0_wav};
  irMap[124][60] = {HRIR_48K_24bit::azi_124_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_124_0_ele_60_0_wav};
  irMap[124][75] = {HRIR_48K_24bit::azi_124_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_124_0_ele_75_0_wav};
  irMap[124][90] = {HRIR_48K_24bit::azi_124_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_124_0_ele_90_0_wav};
  irMap[124][-15] = {HRIR_48K_24bit::azi_124_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_124_0_ele_neg15_0_wav};
  irMap[124][-25] = {HRIR_48K_24bit::azi_124_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_124_0_ele_neg25_0_wav};
  irMap[124][-30] = {HRIR_48K_24bit::azi_124_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_124_0_ele_neg30_0_wav};
  irMap[124][-45] = {HRIR_48K_24bit::azi_124_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_124_0_ele_neg45_0_wav};
  irMap[124][-54] = {HRIR_48K_24bit::azi_124_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_124_0_ele_neg54_0_wav};
  irMap[124][-60] = {HRIR_48K_24bit::azi_124_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_124_0_ele_neg60_0_wav};
  irMap[124][-75] = {HRIR_48K_24bit::azi_124_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_124_0_ele_neg75_0_wav};
  irMap[124][-81] = {HRIR_48K_24bit::azi_124_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_124_0_ele_neg81_0_wav};
  irMap[125][0] = {HRIR_48K_24bit::azi_125_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_125_0_ele_0_0_wav};
  irMap[125][15] = {HRIR_48K_24bit::azi_125_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_125_0_ele_15_0_wav};
  irMap[125][25] = {HRIR_48K_24bit::azi_125_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_125_0_ele_25_0_wav};
  irMap[125][30] = {HRIR_48K_24bit::azi_125_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_125_0_ele_30_0_wav};
  irMap[125][45] = {HRIR_48K_24bit::azi_125_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_125_0_ele_45_0_wav};
  irMap[125][54] = {HRIR_48K_24bit::azi_125_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_125_0_ele_54_0_wav};
  irMap[125][60] = {HRIR_48K_24bit::azi_125_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_125_0_ele_60_0_wav};
  irMap[125][75] = {HRIR_48K_24bit::azi_125_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_125_0_ele_75_0_wav};
  irMap[125][90] = {HRIR_48K_24bit::azi_125_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_125_0_ele_90_0_wav};
  irMap[125][-15] = {HRIR_48K_24bit::azi_125_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_125_0_ele_neg15_0_wav};
  irMap[125][-25] = {HRIR_48K_24bit::azi_125_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_125_0_ele_neg25_0_wav};
  irMap[125][-30] = {HRIR_48K_24bit::azi_125_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_125_0_ele_neg30_0_wav};
  irMap[125][-45] = {HRIR_48K_24bit::azi_125_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_125_0_ele_neg45_0_wav};
  irMap[125][-54] = {HRIR_48K_24bit::azi_125_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_125_0_ele_neg54_0_wav};
  irMap[125][-60] = {HRIR_48K_24bit::azi_125_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_125_0_ele_neg60_0_wav};
  irMap[125][-75] = {HRIR_48K_24bit::azi_125_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_125_0_ele_neg75_0_wav};
  irMap[125][-81] = {HRIR_48K_24bit::azi_125_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_125_0_ele_neg81_0_wav};
  irMap[126][0] = {HRIR_48K_24bit::azi_126_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_126_0_ele_0_0_wav};
  irMap[126][15] = {HRIR_48K_24bit::azi_126_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_126_0_ele_15_0_wav};
  irMap[126][25] = {HRIR_48K_24bit::azi_126_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_126_0_ele_25_0_wav};
  irMap[126][30] = {HRIR_48K_24bit::azi_126_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_126_0_ele_30_0_wav};
  irMap[126][45] = {HRIR_48K_24bit::azi_126_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_126_0_ele_45_0_wav};
  irMap[126][54] = {HRIR_48K_24bit::azi_126_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_126_0_ele_54_0_wav};
  irMap[126][60] = {HRIR_48K_24bit::azi_126_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_126_0_ele_60_0_wav};
  irMap[126][75] = {HRIR_48K_24bit::azi_126_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_126_0_ele_75_0_wav};
  irMap[126][90] = {HRIR_48K_24bit::azi_126_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_126_0_ele_90_0_wav};
  irMap[126][-15] = {HRIR_48K_24bit::azi_126_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_126_0_ele_neg15_0_wav};
  irMap[126][-25] = {HRIR_48K_24bit::azi_126_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_126_0_ele_neg25_0_wav};
  irMap[126][-30] = {HRIR_48K_24bit::azi_126_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_126_0_ele_neg30_0_wav};
  irMap[126][-45] = {HRIR_48K_24bit::azi_126_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_126_0_ele_neg45_0_wav};
  irMap[126][-54] = {HRIR_48K_24bit::azi_126_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_126_0_ele_neg54_0_wav};
  irMap[126][-60] = {HRIR_48K_24bit::azi_126_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_126_0_ele_neg60_0_wav};
  irMap[126][-75] = {HRIR_48K_24bit::azi_126_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_126_0_ele_neg75_0_wav};
  irMap[126][-81] = {HRIR_48K_24bit::azi_126_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_126_0_ele_neg81_0_wav};
  irMap[127][0] = {HRIR_48K_24bit::azi_127_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_127_0_ele_0_0_wav};
  irMap[127][15] = {HRIR_48K_24bit::azi_127_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_127_0_ele_15_0_wav};
  irMap[127][25] = {HRIR_48K_24bit::azi_127_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_127_0_ele_25_0_wav};
  irMap[127][30] = {HRIR_48K_24bit::azi_127_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_127_0_ele_30_0_wav};
  irMap[127][45] = {HRIR_48K_24bit::azi_127_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_127_0_ele_45_0_wav};
  irMap[127][54] = {HRIR_48K_24bit::azi_127_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_127_0_ele_54_0_wav};
  irMap[127][60] = {HRIR_48K_24bit::azi_127_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_127_0_ele_60_0_wav};
  irMap[127][75] = {HRIR_48K_24bit::azi_127_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_127_0_ele_75_0_wav};
  irMap[127][90] = {HRIR_48K_24bit::azi_127_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_127_0_ele_90_0_wav};
  irMap[127][-15] = {HRIR_48K_24bit::azi_127_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_127_0_ele_neg15_0_wav};
  irMap[127][-25] = {HRIR_48K_24bit::azi_127_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_127_0_ele_neg25_0_wav};
  irMap[127][-30] = {HRIR_48K_24bit::azi_127_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_127_0_ele_neg30_0_wav};
  irMap[127][-45] = {HRIR_48K_24bit::azi_127_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_127_0_ele_neg45_0_wav};
  irMap[127][-54] = {HRIR_48K_24bit::azi_127_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_127_0_ele_neg54_0_wav};
  irMap[127][-60] = {HRIR_48K_24bit::azi_127_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_127_0_ele_neg60_0_wav};
  irMap[127][-75] = {HRIR_48K_24bit::azi_127_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_127_0_ele_neg75_0_wav};
  irMap[127][-81] = {HRIR_48K_24bit::azi_127_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_127_0_ele_neg81_0_wav};
  irMap[128][0] = {HRIR_48K_24bit::azi_128_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_128_0_ele_0_0_wav};
  irMap[128][15] = {HRIR_48K_24bit::azi_128_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_128_0_ele_15_0_wav};
  irMap[128][25] = {HRIR_48K_24bit::azi_128_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_128_0_ele_25_0_wav};
  irMap[128][30] = {HRIR_48K_24bit::azi_128_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_128_0_ele_30_0_wav};
  irMap[128][45] = {HRIR_48K_24bit::azi_128_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_128_0_ele_45_0_wav};
  irMap[128][54] = {HRIR_48K_24bit::azi_128_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_128_0_ele_54_0_wav};
  irMap[128][60] = {HRIR_48K_24bit::azi_128_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_128_0_ele_60_0_wav};
  irMap[128][75] = {HRIR_48K_24bit::azi_128_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_128_0_ele_75_0_wav};
  irMap[128][90] = {HRIR_48K_24bit::azi_128_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_128_0_ele_90_0_wav};
  irMap[128][-15] = {HRIR_48K_24bit::azi_128_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_128_0_ele_neg15_0_wav};
  irMap[128][-25] = {HRIR_48K_24bit::azi_128_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_128_0_ele_neg25_0_wav};
  irMap[128][-30] = {HRIR_48K_24bit::azi_128_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_128_0_ele_neg30_0_wav};
  irMap[128][-45] = {HRIR_48K_24bit::azi_128_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_128_0_ele_neg45_0_wav};
  irMap[128][-54] = {HRIR_48K_24bit::azi_128_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_128_0_ele_neg54_0_wav};
  irMap[128][-60] = {HRIR_48K_24bit::azi_128_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_128_0_ele_neg60_0_wav};
  irMap[128][-75] = {HRIR_48K_24bit::azi_128_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_128_0_ele_neg75_0_wav};
  irMap[128][-81] = {HRIR_48K_24bit::azi_128_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_128_0_ele_neg81_0_wav};
  irMap[129][0] = {HRIR_48K_24bit::azi_129_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_129_0_ele_0_0_wav};
  irMap[129][15] = {HRIR_48K_24bit::azi_129_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_129_0_ele_15_0_wav};
  irMap[129][25] = {HRIR_48K_24bit::azi_129_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_129_0_ele_25_0_wav};
  irMap[129][30] = {HRIR_48K_24bit::azi_129_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_129_0_ele_30_0_wav};
  irMap[129][45] = {HRIR_48K_24bit::azi_129_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_129_0_ele_45_0_wav};
  irMap[129][54] = {HRIR_48K_24bit::azi_129_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_129_0_ele_54_0_wav};
  irMap[129][60] = {HRIR_48K_24bit::azi_129_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_129_0_ele_60_0_wav};
  irMap[129][75] = {HRIR_48K_24bit::azi_129_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_129_0_ele_75_0_wav};
  irMap[129][90] = {HRIR_48K_24bit::azi_129_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_129_0_ele_90_0_wav};
  irMap[129][-15] = {HRIR_48K_24bit::azi_129_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_129_0_ele_neg15_0_wav};
  irMap[129][-25] = {HRIR_48K_24bit::azi_129_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_129_0_ele_neg25_0_wav};
  irMap[129][-30] = {HRIR_48K_24bit::azi_129_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_129_0_ele_neg30_0_wav};
  irMap[129][-45] = {HRIR_48K_24bit::azi_129_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_129_0_ele_neg45_0_wav};
  irMap[129][-54] = {HRIR_48K_24bit::azi_129_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_129_0_ele_neg54_0_wav};
  irMap[129][-60] = {HRIR_48K_24bit::azi_129_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_129_0_ele_neg60_0_wav};
  irMap[129][-75] = {HRIR_48K_24bit::azi_129_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_129_0_ele_neg75_0_wav};
  irMap[129][-81] = {HRIR_48K_24bit::azi_129_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_129_0_ele_neg81_0_wav};
  irMap[130][0] = {HRIR_48K_24bit::azi_130_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_130_0_ele_0_0_wav};
  irMap[130][15] = {HRIR_48K_24bit::azi_130_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_130_0_ele_15_0_wav};
  irMap[130][25] = {HRIR_48K_24bit::azi_130_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_130_0_ele_25_0_wav};
  irMap[130][30] = {HRIR_48K_24bit::azi_130_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_130_0_ele_30_0_wav};
  irMap[130][45] = {HRIR_48K_24bit::azi_130_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_130_0_ele_45_0_wav};
  irMap[130][54] = {HRIR_48K_24bit::azi_130_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_130_0_ele_54_0_wav};
  irMap[130][60] = {HRIR_48K_24bit::azi_130_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_130_0_ele_60_0_wav};
  irMap[130][75] = {HRIR_48K_24bit::azi_130_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_130_0_ele_75_0_wav};
  irMap[130][90] = {HRIR_48K_24bit::azi_130_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_130_0_ele_90_0_wav};
  irMap[130][-15] = {HRIR_48K_24bit::azi_130_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_130_0_ele_neg15_0_wav};
  irMap[130][-25] = {HRIR_48K_24bit::azi_130_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_130_0_ele_neg25_0_wav};
  irMap[130][-30] = {HRIR_48K_24bit::azi_130_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_130_0_ele_neg30_0_wav};
  irMap[130][-45] = {HRIR_48K_24bit::azi_130_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_130_0_ele_neg45_0_wav};
  irMap[130][-54] = {HRIR_48K_24bit::azi_130_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_130_0_ele_neg54_0_wav};
  irMap[130][-60] = {HRIR_48K_24bit::azi_130_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_130_0_ele_neg60_0_wav};
  irMap[130][-75] = {HRIR_48K_24bit::azi_130_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_130_0_ele_neg75_0_wav};
  irMap[130][-81] = {HRIR_48K_24bit::azi_130_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_130_0_ele_neg81_0_wav};
  irMap[131][0] = {HRIR_48K_24bit::azi_131_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_131_0_ele_0_0_wav};
  irMap[131][15] = {HRIR_48K_24bit::azi_131_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_131_0_ele_15_0_wav};
  irMap[131][25] = {HRIR_48K_24bit::azi_131_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_131_0_ele_25_0_wav};
  irMap[131][30] = {HRIR_48K_24bit::azi_131_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_131_0_ele_30_0_wav};
  irMap[131][45] = {HRIR_48K_24bit::azi_131_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_131_0_ele_45_0_wav};
  irMap[131][54] = {HRIR_48K_24bit::azi_131_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_131_0_ele_54_0_wav};
  irMap[131][60] = {HRIR_48K_24bit::azi_131_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_131_0_ele_60_0_wav};
  irMap[131][75] = {HRIR_48K_24bit::azi_131_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_131_0_ele_75_0_wav};
  irMap[131][90] = {HRIR_48K_24bit::azi_131_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_131_0_ele_90_0_wav};
  irMap[131][-15] = {HRIR_48K_24bit::azi_131_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_131_0_ele_neg15_0_wav};
  irMap[131][-25] = {HRIR_48K_24bit::azi_131_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_131_0_ele_neg25_0_wav};
  irMap[131][-30] = {HRIR_48K_24bit::azi_131_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_131_0_ele_neg30_0_wav};
  irMap[131][-45] = {HRIR_48K_24bit::azi_131_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_131_0_ele_neg45_0_wav};
  irMap[131][-54] = {HRIR_48K_24bit::azi_131_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_131_0_ele_neg54_0_wav};
  irMap[131][-60] = {HRIR_48K_24bit::azi_131_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_131_0_ele_neg60_0_wav};
  irMap[131][-75] = {HRIR_48K_24bit::azi_131_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_131_0_ele_neg75_0_wav};
  irMap[131][-81] = {HRIR_48K_24bit::azi_131_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_131_0_ele_neg81_0_wav};
  irMap[132][0] = {HRIR_48K_24bit::azi_132_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_132_0_ele_0_0_wav};
  irMap[132][15] = {HRIR_48K_24bit::azi_132_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_132_0_ele_15_0_wav};
  irMap[132][25] = {HRIR_48K_24bit::azi_132_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_132_0_ele_25_0_wav};
  irMap[132][30] = {HRIR_48K_24bit::azi_132_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_132_0_ele_30_0_wav};
  irMap[132][45] = {HRIR_48K_24bit::azi_132_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_132_0_ele_45_0_wav};
  irMap[132][54] = {HRIR_48K_24bit::azi_132_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_132_0_ele_54_0_wav};
  irMap[132][60] = {HRIR_48K_24bit::azi_132_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_132_0_ele_60_0_wav};
  irMap[132][75] = {HRIR_48K_24bit::azi_132_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_132_0_ele_75_0_wav};
  irMap[132][90] = {HRIR_48K_24bit::azi_132_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_132_0_ele_90_0_wav};
  irMap[132][-15] = {HRIR_48K_24bit::azi_132_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_132_0_ele_neg15_0_wav};
  irMap[132][-25] = {HRIR_48K_24bit::azi_132_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_132_0_ele_neg25_0_wav};
  irMap[132][-30] = {HRIR_48K_24bit::azi_132_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_132_0_ele_neg30_0_wav};
  irMap[132][-45] = {HRIR_48K_24bit::azi_132_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_132_0_ele_neg45_0_wav};
  irMap[132][-54] = {HRIR_48K_24bit::azi_132_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_132_0_ele_neg54_0_wav};
  irMap[132][-60] = {HRIR_48K_24bit::azi_132_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_132_0_ele_neg60_0_wav};
  irMap[132][-75] = {HRIR_48K_24bit::azi_132_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_132_0_ele_neg75_0_wav};
  irMap[132][-81] = {HRIR_48K_24bit::azi_132_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_132_0_ele_neg81_0_wav};
  irMap[133][0] = {HRIR_48K_24bit::azi_133_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_133_0_ele_0_0_wav};
  irMap[133][15] = {HRIR_48K_24bit::azi_133_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_133_0_ele_15_0_wav};
  irMap[133][25] = {HRIR_48K_24bit::azi_133_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_133_0_ele_25_0_wav};
  irMap[133][30] = {HRIR_48K_24bit::azi_133_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_133_0_ele_30_0_wav};
  irMap[133][45] = {HRIR_48K_24bit::azi_133_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_133_0_ele_45_0_wav};
  irMap[133][54] = {HRIR_48K_24bit::azi_133_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_133_0_ele_54_0_wav};
  irMap[133][60] = {HRIR_48K_24bit::azi_133_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_133_0_ele_60_0_wav};
  irMap[133][75] = {HRIR_48K_24bit::azi_133_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_133_0_ele_75_0_wav};
  irMap[133][90] = {HRIR_48K_24bit::azi_133_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_133_0_ele_90_0_wav};
  irMap[133][-15] = {HRIR_48K_24bit::azi_133_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_133_0_ele_neg15_0_wav};
  irMap[133][-25] = {HRIR_48K_24bit::azi_133_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_133_0_ele_neg25_0_wav};
  irMap[133][-30] = {HRIR_48K_24bit::azi_133_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_133_0_ele_neg30_0_wav};
  irMap[133][-45] = {HRIR_48K_24bit::azi_133_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_133_0_ele_neg45_0_wav};
  irMap[133][-54] = {HRIR_48K_24bit::azi_133_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_133_0_ele_neg54_0_wav};
  irMap[133][-60] = {HRIR_48K_24bit::azi_133_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_133_0_ele_neg60_0_wav};
  irMap[133][-75] = {HRIR_48K_24bit::azi_133_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_133_0_ele_neg75_0_wav};
  irMap[133][-81] = {HRIR_48K_24bit::azi_133_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_133_0_ele_neg81_0_wav};
  irMap[134][0] = {HRIR_48K_24bit::azi_134_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_134_0_ele_0_0_wav};
  irMap[134][15] = {HRIR_48K_24bit::azi_134_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_134_0_ele_15_0_wav};
  irMap[134][25] = {HRIR_48K_24bit::azi_134_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_134_0_ele_25_0_wav};
  irMap[134][30] = {HRIR_48K_24bit::azi_134_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_134_0_ele_30_0_wav};
  irMap[134][45] = {HRIR_48K_24bit::azi_134_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_134_0_ele_45_0_wav};
  irMap[134][54] = {HRIR_48K_24bit::azi_134_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_134_0_ele_54_0_wav};
  irMap[134][60] = {HRIR_48K_24bit::azi_134_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_134_0_ele_60_0_wav};
  irMap[134][75] = {HRIR_48K_24bit::azi_134_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_134_0_ele_75_0_wav};
  irMap[134][90] = {HRIR_48K_24bit::azi_134_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_134_0_ele_90_0_wav};
  irMap[134][-15] = {HRIR_48K_24bit::azi_134_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_134_0_ele_neg15_0_wav};
  irMap[134][-25] = {HRIR_48K_24bit::azi_134_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_134_0_ele_neg25_0_wav};
  irMap[134][-30] = {HRIR_48K_24bit::azi_134_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_134_0_ele_neg30_0_wav};
  irMap[134][-45] = {HRIR_48K_24bit::azi_134_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_134_0_ele_neg45_0_wav};
  irMap[134][-54] = {HRIR_48K_24bit::azi_134_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_134_0_ele_neg54_0_wav};
  irMap[134][-60] = {HRIR_48K_24bit::azi_134_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_134_0_ele_neg60_0_wav};
  irMap[134][-75] = {HRIR_48K_24bit::azi_134_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_134_0_ele_neg75_0_wav};
  irMap[134][-81] = {HRIR_48K_24bit::azi_134_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_134_0_ele_neg81_0_wav};
  irMap[135][0] = {HRIR_48K_24bit::azi_135_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_135_0_ele_0_0_wav};
  irMap[135][15] = {HRIR_48K_24bit::azi_135_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_135_0_ele_15_0_wav};
  irMap[135][25] = {HRIR_48K_24bit::azi_135_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_135_0_ele_25_0_wav};
  irMap[135][30] = {HRIR_48K_24bit::azi_135_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_135_0_ele_30_0_wav};
  irMap[135][45] = {HRIR_48K_24bit::azi_135_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_135_0_ele_45_0_wav};
  irMap[135][54] = {HRIR_48K_24bit::azi_135_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_135_0_ele_54_0_wav};
  irMap[135][60] = {HRIR_48K_24bit::azi_135_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_135_0_ele_60_0_wav};
  irMap[135][75] = {HRIR_48K_24bit::azi_135_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_135_0_ele_75_0_wav};
  irMap[135][90] = {HRIR_48K_24bit::azi_135_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_135_0_ele_90_0_wav};
  irMap[135][-15] = {HRIR_48K_24bit::azi_135_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_135_0_ele_neg15_0_wav};
  irMap[135][-25] = {HRIR_48K_24bit::azi_135_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_135_0_ele_neg25_0_wav};
  irMap[135][-30] = {HRIR_48K_24bit::azi_135_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_135_0_ele_neg30_0_wav};
  irMap[135][-45] = {HRIR_48K_24bit::azi_135_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_135_0_ele_neg45_0_wav};
  irMap[135][-54] = {HRIR_48K_24bit::azi_135_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_135_0_ele_neg54_0_wav};
  irMap[135][-60] = {HRIR_48K_24bit::azi_135_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_135_0_ele_neg60_0_wav};
  irMap[135][-75] = {HRIR_48K_24bit::azi_135_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_135_0_ele_neg75_0_wav};
  irMap[135][-81] = {HRIR_48K_24bit::azi_135_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_135_0_ele_neg81_0_wav};
  irMap[136][0] = {HRIR_48K_24bit::azi_136_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_136_0_ele_0_0_wav};
  irMap[136][15] = {HRIR_48K_24bit::azi_136_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_136_0_ele_15_0_wav};
  irMap[136][25] = {HRIR_48K_24bit::azi_136_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_136_0_ele_25_0_wav};
  irMap[136][30] = {HRIR_48K_24bit::azi_136_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_136_0_ele_30_0_wav};
  irMap[136][45] = {HRIR_48K_24bit::azi_136_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_136_0_ele_45_0_wav};
  irMap[136][54] = {HRIR_48K_24bit::azi_136_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_136_0_ele_54_0_wav};
  irMap[136][60] = {HRIR_48K_24bit::azi_136_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_136_0_ele_60_0_wav};
  irMap[136][75] = {HRIR_48K_24bit::azi_136_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_136_0_ele_75_0_wav};
  irMap[136][90] = {HRIR_48K_24bit::azi_136_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_136_0_ele_90_0_wav};
  irMap[136][-15] = {HRIR_48K_24bit::azi_136_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_136_0_ele_neg15_0_wav};
  irMap[136][-25] = {HRIR_48K_24bit::azi_136_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_136_0_ele_neg25_0_wav};
  irMap[136][-30] = {HRIR_48K_24bit::azi_136_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_136_0_ele_neg30_0_wav};
  irMap[136][-45] = {HRIR_48K_24bit::azi_136_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_136_0_ele_neg45_0_wav};
  irMap[136][-54] = {HRIR_48K_24bit::azi_136_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_136_0_ele_neg54_0_wav};
  irMap[136][-60] = {HRIR_48K_24bit::azi_136_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_136_0_ele_neg60_0_wav};
  irMap[136][-75] = {HRIR_48K_24bit::azi_136_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_136_0_ele_neg75_0_wav};
  irMap[136][-81] = {HRIR_48K_24bit::azi_136_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_136_0_ele_neg81_0_wav};
  irMap[137][0] = {HRIR_48K_24bit::azi_137_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_137_0_ele_0_0_wav};
  irMap[137][15] = {HRIR_48K_24bit::azi_137_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_137_0_ele_15_0_wav};
  irMap[137][25] = {HRIR_48K_24bit::azi_137_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_137_0_ele_25_0_wav};
  irMap[137][30] = {HRIR_48K_24bit::azi_137_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_137_0_ele_30_0_wav};
  irMap[137][45] = {HRIR_48K_24bit::azi_137_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_137_0_ele_45_0_wav};
  irMap[137][54] = {HRIR_48K_24bit::azi_137_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_137_0_ele_54_0_wav};
  irMap[137][60] = {HRIR_48K_24bit::azi_137_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_137_0_ele_60_0_wav};
  irMap[137][75] = {HRIR_48K_24bit::azi_137_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_137_0_ele_75_0_wav};
  irMap[137][90] = {HRIR_48K_24bit::azi_137_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_137_0_ele_90_0_wav};
  irMap[137][-15] = {HRIR_48K_24bit::azi_137_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_137_0_ele_neg15_0_wav};
  irMap[137][-25] = {HRIR_48K_24bit::azi_137_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_137_0_ele_neg25_0_wav};
  irMap[137][-30] = {HRIR_48K_24bit::azi_137_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_137_0_ele_neg30_0_wav};
  irMap[137][-45] = {HRIR_48K_24bit::azi_137_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_137_0_ele_neg45_0_wav};
  irMap[137][-54] = {HRIR_48K_24bit::azi_137_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_137_0_ele_neg54_0_wav};
  irMap[137][-60] = {HRIR_48K_24bit::azi_137_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_137_0_ele_neg60_0_wav};
  irMap[137][-75] = {HRIR_48K_24bit::azi_137_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_137_0_ele_neg75_0_wav};
  irMap[137][-81] = {HRIR_48K_24bit::azi_137_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_137_0_ele_neg81_0_wav};
  irMap[138][0] = {HRIR_48K_24bit::azi_138_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_138_0_ele_0_0_wav};
  irMap[138][15] = {HRIR_48K_24bit::azi_138_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_138_0_ele_15_0_wav};
  irMap[138][25] = {HRIR_48K_24bit::azi_138_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_138_0_ele_25_0_wav};
  irMap[138][30] = {HRIR_48K_24bit::azi_138_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_138_0_ele_30_0_wav};
  irMap[138][45] = {HRIR_48K_24bit::azi_138_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_138_0_ele_45_0_wav};
  irMap[138][54] = {HRIR_48K_24bit::azi_138_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_138_0_ele_54_0_wav};
  irMap[138][60] = {HRIR_48K_24bit::azi_138_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_138_0_ele_60_0_wav};
  irMap[138][75] = {HRIR_48K_24bit::azi_138_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_138_0_ele_75_0_wav};
  irMap[138][90] = {HRIR_48K_24bit::azi_138_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_138_0_ele_90_0_wav};
  irMap[138][-15] = {HRIR_48K_24bit::azi_138_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_138_0_ele_neg15_0_wav};
  irMap[138][-25] = {HRIR_48K_24bit::azi_138_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_138_0_ele_neg25_0_wav};
  irMap[138][-30] = {HRIR_48K_24bit::azi_138_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_138_0_ele_neg30_0_wav};
  irMap[138][-45] = {HRIR_48K_24bit::azi_138_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_138_0_ele_neg45_0_wav};
  irMap[138][-54] = {HRIR_48K_24bit::azi_138_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_138_0_ele_neg54_0_wav};
  irMap[138][-60] = {HRIR_48K_24bit::azi_138_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_138_0_ele_neg60_0_wav};
  irMap[138][-75] = {HRIR_48K_24bit::azi_138_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_138_0_ele_neg75_0_wav};
  irMap[138][-81] = {HRIR_48K_24bit::azi_138_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_138_0_ele_neg81_0_wav};
  irMap[139][0] = {HRIR_48K_24bit::azi_139_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_139_0_ele_0_0_wav};
  irMap[139][15] = {HRIR_48K_24bit::azi_139_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_139_0_ele_15_0_wav};
  irMap[139][25] = {HRIR_48K_24bit::azi_139_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_139_0_ele_25_0_wav};
  irMap[139][30] = {HRIR_48K_24bit::azi_139_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_139_0_ele_30_0_wav};
  irMap[139][45] = {HRIR_48K_24bit::azi_139_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_139_0_ele_45_0_wav};
  irMap[139][54] = {HRIR_48K_24bit::azi_139_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_139_0_ele_54_0_wav};
  irMap[139][60] = {HRIR_48K_24bit::azi_139_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_139_0_ele_60_0_wav};
  irMap[139][75] = {HRIR_48K_24bit::azi_139_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_139_0_ele_75_0_wav};
  irMap[139][90] = {HRIR_48K_24bit::azi_139_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_139_0_ele_90_0_wav};
  irMap[139][-15] = {HRIR_48K_24bit::azi_139_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_139_0_ele_neg15_0_wav};
  irMap[139][-25] = {HRIR_48K_24bit::azi_139_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_139_0_ele_neg25_0_wav};
  irMap[139][-30] = {HRIR_48K_24bit::azi_139_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_139_0_ele_neg30_0_wav};
  irMap[139][-45] = {HRIR_48K_24bit::azi_139_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_139_0_ele_neg45_0_wav};
  irMap[139][-54] = {HRIR_48K_24bit::azi_139_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_139_0_ele_neg54_0_wav};
  irMap[139][-60] = {HRIR_48K_24bit::azi_139_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_139_0_ele_neg60_0_wav};
  irMap[139][-75] = {HRIR_48K_24bit::azi_139_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_139_0_ele_neg75_0_wav};
  irMap[139][-81] = {HRIR_48K_24bit::azi_139_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_139_0_ele_neg81_0_wav};
  irMap[140][0] = {HRIR_48K_24bit::azi_140_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_140_0_ele_0_0_wav};
  irMap[140][15] = {HRIR_48K_24bit::azi_140_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_140_0_ele_15_0_wav};
  irMap[140][25] = {HRIR_48K_24bit::azi_140_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_140_0_ele_25_0_wav};
  irMap[140][30] = {HRIR_48K_24bit::azi_140_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_140_0_ele_30_0_wav};
  irMap[140][45] = {HRIR_48K_24bit::azi_140_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_140_0_ele_45_0_wav};
  irMap[140][54] = {HRIR_48K_24bit::azi_140_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_140_0_ele_54_0_wav};
  irMap[140][60] = {HRIR_48K_24bit::azi_140_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_140_0_ele_60_0_wav};
  irMap[140][75] = {HRIR_48K_24bit::azi_140_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_140_0_ele_75_0_wav};
  irMap[140][90] = {HRIR_48K_24bit::azi_140_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_140_0_ele_90_0_wav};
  irMap[140][-15] = {HRIR_48K_24bit::azi_140_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_140_0_ele_neg15_0_wav};
  irMap[140][-25] = {HRIR_48K_24bit::azi_140_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_140_0_ele_neg25_0_wav};
  irMap[140][-30] = {HRIR_48K_24bit::azi_140_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_140_0_ele_neg30_0_wav};
  irMap[140][-45] = {HRIR_48K_24bit::azi_140_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_140_0_ele_neg45_0_wav};
  irMap[140][-54] = {HRIR_48K_24bit::azi_140_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_140_0_ele_neg54_0_wav};
  irMap[140][-60] = {HRIR_48K_24bit::azi_140_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_140_0_ele_neg60_0_wav};
  irMap[140][-75] = {HRIR_48K_24bit::azi_140_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_140_0_ele_neg75_0_wav};
  irMap[140][-81] = {HRIR_48K_24bit::azi_140_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_140_0_ele_neg81_0_wav};
  irMap[141][0] = {HRIR_48K_24bit::azi_141_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_141_0_ele_0_0_wav};
  irMap[141][15] = {HRIR_48K_24bit::azi_141_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_141_0_ele_15_0_wav};
  irMap[141][25] = {HRIR_48K_24bit::azi_141_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_141_0_ele_25_0_wav};
  irMap[141][30] = {HRIR_48K_24bit::azi_141_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_141_0_ele_30_0_wav};
  irMap[141][45] = {HRIR_48K_24bit::azi_141_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_141_0_ele_45_0_wav};
  irMap[141][54] = {HRIR_48K_24bit::azi_141_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_141_0_ele_54_0_wav};
  irMap[141][60] = {HRIR_48K_24bit::azi_141_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_141_0_ele_60_0_wav};
  irMap[141][75] = {HRIR_48K_24bit::azi_141_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_141_0_ele_75_0_wav};
  irMap[141][90] = {HRIR_48K_24bit::azi_141_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_141_0_ele_90_0_wav};
  irMap[141][-15] = {HRIR_48K_24bit::azi_141_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_141_0_ele_neg15_0_wav};
  irMap[141][-25] = {HRIR_48K_24bit::azi_141_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_141_0_ele_neg25_0_wav};
  irMap[141][-30] = {HRIR_48K_24bit::azi_141_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_141_0_ele_neg30_0_wav};
  irMap[141][-45] = {HRIR_48K_24bit::azi_141_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_141_0_ele_neg45_0_wav};
  irMap[141][-54] = {HRIR_48K_24bit::azi_141_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_141_0_ele_neg54_0_wav};
  irMap[141][-60] = {HRIR_48K_24bit::azi_141_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_141_0_ele_neg60_0_wav};
  irMap[141][-75] = {HRIR_48K_24bit::azi_141_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_141_0_ele_neg75_0_wav};
  irMap[141][-81] = {HRIR_48K_24bit::azi_141_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_141_0_ele_neg81_0_wav};
  irMap[142][0] = {HRIR_48K_24bit::azi_142_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_142_0_ele_0_0_wav};
  irMap[142][15] = {HRIR_48K_24bit::azi_142_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_142_0_ele_15_0_wav};
  irMap[142][25] = {HRIR_48K_24bit::azi_142_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_142_0_ele_25_0_wav};
  irMap[142][30] = {HRIR_48K_24bit::azi_142_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_142_0_ele_30_0_wav};
  irMap[142][45] = {HRIR_48K_24bit::azi_142_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_142_0_ele_45_0_wav};
  irMap[142][54] = {HRIR_48K_24bit::azi_142_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_142_0_ele_54_0_wav};
  irMap[142][60] = {HRIR_48K_24bit::azi_142_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_142_0_ele_60_0_wav};
  irMap[142][75] = {HRIR_48K_24bit::azi_142_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_142_0_ele_75_0_wav};
  irMap[142][90] = {HRIR_48K_24bit::azi_142_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_142_0_ele_90_0_wav};
  irMap[142][-15] = {HRIR_48K_24bit::azi_142_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_142_0_ele_neg15_0_wav};
  irMap[142][-25] = {HRIR_48K_24bit::azi_142_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_142_0_ele_neg25_0_wav};
  irMap[142][-30] = {HRIR_48K_24bit::azi_142_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_142_0_ele_neg30_0_wav};
  irMap[142][-45] = {HRIR_48K_24bit::azi_142_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_142_0_ele_neg45_0_wav};
  irMap[142][-54] = {HRIR_48K_24bit::azi_142_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_142_0_ele_neg54_0_wav};
  irMap[142][-60] = {HRIR_48K_24bit::azi_142_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_142_0_ele_neg60_0_wav};
  irMap[142][-75] = {HRIR_48K_24bit::azi_142_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_142_0_ele_neg75_0_wav};
  irMap[142][-81] = {HRIR_48K_24bit::azi_142_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_142_0_ele_neg81_0_wav};
  irMap[143][0] = {HRIR_48K_24bit::azi_143_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_143_0_ele_0_0_wav};
  irMap[143][15] = {HRIR_48K_24bit::azi_143_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_143_0_ele_15_0_wav};
  irMap[143][25] = {HRIR_48K_24bit::azi_143_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_143_0_ele_25_0_wav};
  irMap[143][30] = {HRIR_48K_24bit::azi_143_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_143_0_ele_30_0_wav};
  irMap[143][45] = {HRIR_48K_24bit::azi_143_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_143_0_ele_45_0_wav};
  irMap[143][54] = {HRIR_48K_24bit::azi_143_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_143_0_ele_54_0_wav};
  irMap[143][60] = {HRIR_48K_24bit::azi_143_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_143_0_ele_60_0_wav};
  irMap[143][75] = {HRIR_48K_24bit::azi_143_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_143_0_ele_75_0_wav};
  irMap[143][90] = {HRIR_48K_24bit::azi_143_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_143_0_ele_90_0_wav};
  irMap[143][-15] = {HRIR_48K_24bit::azi_143_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_143_0_ele_neg15_0_wav};
  irMap[143][-25] = {HRIR_48K_24bit::azi_143_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_143_0_ele_neg25_0_wav};
  irMap[143][-30] = {HRIR_48K_24bit::azi_143_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_143_0_ele_neg30_0_wav};
  irMap[143][-45] = {HRIR_48K_24bit::azi_143_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_143_0_ele_neg45_0_wav};
  irMap[143][-54] = {HRIR_48K_24bit::azi_143_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_143_0_ele_neg54_0_wav};
  irMap[143][-60] = {HRIR_48K_24bit::azi_143_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_143_0_ele_neg60_0_wav};
  irMap[143][-75] = {HRIR_48K_24bit::azi_143_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_143_0_ele_neg75_0_wav};
  irMap[143][-81] = {HRIR_48K_24bit::azi_143_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_143_0_ele_neg81_0_wav};
  irMap[144][0] = {HRIR_48K_24bit::azi_144_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_144_0_ele_0_0_wav};
  irMap[144][15] = {HRIR_48K_24bit::azi_144_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_144_0_ele_15_0_wav};
  irMap[144][25] = {HRIR_48K_24bit::azi_144_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_144_0_ele_25_0_wav};
  irMap[144][30] = {HRIR_48K_24bit::azi_144_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_144_0_ele_30_0_wav};
  irMap[144][45] = {HRIR_48K_24bit::azi_144_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_144_0_ele_45_0_wav};
  irMap[144][54] = {HRIR_48K_24bit::azi_144_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_144_0_ele_54_0_wav};
  irMap[144][60] = {HRIR_48K_24bit::azi_144_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_144_0_ele_60_0_wav};
  irMap[144][75] = {HRIR_48K_24bit::azi_144_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_144_0_ele_75_0_wav};
  irMap[144][90] = {HRIR_48K_24bit::azi_144_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_144_0_ele_90_0_wav};
  irMap[144][-15] = {HRIR_48K_24bit::azi_144_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_144_0_ele_neg15_0_wav};
  irMap[144][-25] = {HRIR_48K_24bit::azi_144_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_144_0_ele_neg25_0_wav};
  irMap[144][-30] = {HRIR_48K_24bit::azi_144_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_144_0_ele_neg30_0_wav};
  irMap[144][-45] = {HRIR_48K_24bit::azi_144_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_144_0_ele_neg45_0_wav};
  irMap[144][-54] = {HRIR_48K_24bit::azi_144_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_144_0_ele_neg54_0_wav};
  irMap[144][-60] = {HRIR_48K_24bit::azi_144_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_144_0_ele_neg60_0_wav};
  irMap[144][-75] = {HRIR_48K_24bit::azi_144_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_144_0_ele_neg75_0_wav};
  irMap[144][-81] = {HRIR_48K_24bit::azi_144_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_144_0_ele_neg81_0_wav};
  irMap[145][0] = {HRIR_48K_24bit::azi_145_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_145_0_ele_0_0_wav};
  irMap[145][15] = {HRIR_48K_24bit::azi_145_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_145_0_ele_15_0_wav};
  irMap[145][25] = {HRIR_48K_24bit::azi_145_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_145_0_ele_25_0_wav};
  irMap[145][30] = {HRIR_48K_24bit::azi_145_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_145_0_ele_30_0_wav};
  irMap[145][45] = {HRIR_48K_24bit::azi_145_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_145_0_ele_45_0_wav};
  irMap[145][54] = {HRIR_48K_24bit::azi_145_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_145_0_ele_54_0_wav};
  irMap[145][60] = {HRIR_48K_24bit::azi_145_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_145_0_ele_60_0_wav};
  irMap[145][75] = {HRIR_48K_24bit::azi_145_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_145_0_ele_75_0_wav};
  irMap[145][90] = {HRIR_48K_24bit::azi_145_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_145_0_ele_90_0_wav};
  irMap[145][-15] = {HRIR_48K_24bit::azi_145_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_145_0_ele_neg15_0_wav};
  irMap[145][-25] = {HRIR_48K_24bit::azi_145_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_145_0_ele_neg25_0_wav};
  irMap[145][-30] = {HRIR_48K_24bit::azi_145_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_145_0_ele_neg30_0_wav};
  irMap[145][-45] = {HRIR_48K_24bit::azi_145_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_145_0_ele_neg45_0_wav};
  irMap[145][-54] = {HRIR_48K_24bit::azi_145_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_145_0_ele_neg54_0_wav};
  irMap[145][-60] = {HRIR_48K_24bit::azi_145_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_145_0_ele_neg60_0_wav};
  irMap[145][-75] = {HRIR_48K_24bit::azi_145_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_145_0_ele_neg75_0_wav};
  irMap[145][-81] = {HRIR_48K_24bit::azi_145_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_145_0_ele_neg81_0_wav};
  irMap[146][0] = {HRIR_48K_24bit::azi_146_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_146_0_ele_0_0_wav};
  irMap[146][15] = {HRIR_48K_24bit::azi_146_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_146_0_ele_15_0_wav};
  irMap[146][25] = {HRIR_48K_24bit::azi_146_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_146_0_ele_25_0_wav};
  irMap[146][30] = {HRIR_48K_24bit::azi_146_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_146_0_ele_30_0_wav};
  irMap[146][45] = {HRIR_48K_24bit::azi_146_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_146_0_ele_45_0_wav};
  irMap[146][54] = {HRIR_48K_24bit::azi_146_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_146_0_ele_54_0_wav};
  irMap[146][60] = {HRIR_48K_24bit::azi_146_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_146_0_ele_60_0_wav};
  irMap[146][75] = {HRIR_48K_24bit::azi_146_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_146_0_ele_75_0_wav};
  irMap[146][90] = {HRIR_48K_24bit::azi_146_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_146_0_ele_90_0_wav};
  irMap[146][-15] = {HRIR_48K_24bit::azi_146_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_146_0_ele_neg15_0_wav};
  irMap[146][-25] = {HRIR_48K_24bit::azi_146_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_146_0_ele_neg25_0_wav};
  irMap[146][-30] = {HRIR_48K_24bit::azi_146_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_146_0_ele_neg30_0_wav};
  irMap[146][-45] = {HRIR_48K_24bit::azi_146_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_146_0_ele_neg45_0_wav};
  irMap[146][-54] = {HRIR_48K_24bit::azi_146_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_146_0_ele_neg54_0_wav};
  irMap[146][-60] = {HRIR_48K_24bit::azi_146_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_146_0_ele_neg60_0_wav};
  irMap[146][-75] = {HRIR_48K_24bit::azi_146_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_146_0_ele_neg75_0_wav};
  irMap[146][-81] = {HRIR_48K_24bit::azi_146_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_146_0_ele_neg81_0_wav};
  irMap[147][0] = {HRIR_48K_24bit::azi_147_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_147_0_ele_0_0_wav};
  irMap[147][15] = {HRIR_48K_24bit::azi_147_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_147_0_ele_15_0_wav};
  irMap[147][25] = {HRIR_48K_24bit::azi_147_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_147_0_ele_25_0_wav};
  irMap[147][30] = {HRIR_48K_24bit::azi_147_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_147_0_ele_30_0_wav};
  irMap[147][45] = {HRIR_48K_24bit::azi_147_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_147_0_ele_45_0_wav};
  irMap[147][54] = {HRIR_48K_24bit::azi_147_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_147_0_ele_54_0_wav};
  irMap[147][60] = {HRIR_48K_24bit::azi_147_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_147_0_ele_60_0_wav};
  irMap[147][75] = {HRIR_48K_24bit::azi_147_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_147_0_ele_75_0_wav};
  irMap[147][90] = {HRIR_48K_24bit::azi_147_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_147_0_ele_90_0_wav};
  irMap[147][-15] = {HRIR_48K_24bit::azi_147_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_147_0_ele_neg15_0_wav};
  irMap[147][-25] = {HRIR_48K_24bit::azi_147_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_147_0_ele_neg25_0_wav};
  irMap[147][-30] = {HRIR_48K_24bit::azi_147_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_147_0_ele_neg30_0_wav};
  irMap[147][-45] = {HRIR_48K_24bit::azi_147_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_147_0_ele_neg45_0_wav};
  irMap[147][-54] = {HRIR_48K_24bit::azi_147_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_147_0_ele_neg54_0_wav};
  irMap[147][-60] = {HRIR_48K_24bit::azi_147_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_147_0_ele_neg60_0_wav};
  irMap[147][-75] = {HRIR_48K_24bit::azi_147_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_147_0_ele_neg75_0_wav};
  irMap[147][-81] = {HRIR_48K_24bit::azi_147_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_147_0_ele_neg81_0_wav};
  irMap[148][0] = {HRIR_48K_24bit::azi_148_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_148_0_ele_0_0_wav};
  irMap[148][15] = {HRIR_48K_24bit::azi_148_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_148_0_ele_15_0_wav};
  irMap[148][25] = {HRIR_48K_24bit::azi_148_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_148_0_ele_25_0_wav};
  irMap[148][30] = {HRIR_48K_24bit::azi_148_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_148_0_ele_30_0_wav};
  irMap[148][45] = {HRIR_48K_24bit::azi_148_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_148_0_ele_45_0_wav};
  irMap[148][54] = {HRIR_48K_24bit::azi_148_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_148_0_ele_54_0_wav};
  irMap[148][60] = {HRIR_48K_24bit::azi_148_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_148_0_ele_60_0_wav};
  irMap[148][75] = {HRIR_48K_24bit::azi_148_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_148_0_ele_75_0_wav};
  irMap[148][90] = {HRIR_48K_24bit::azi_148_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_148_0_ele_90_0_wav};
  irMap[148][-15] = {HRIR_48K_24bit::azi_148_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_148_0_ele_neg15_0_wav};
  irMap[148][-25] = {HRIR_48K_24bit::azi_148_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_148_0_ele_neg25_0_wav};
  irMap[148][-30] = {HRIR_48K_24bit::azi_148_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_148_0_ele_neg30_0_wav};
  irMap[148][-45] = {HRIR_48K_24bit::azi_148_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_148_0_ele_neg45_0_wav};
  irMap[148][-54] = {HRIR_48K_24bit::azi_148_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_148_0_ele_neg54_0_wav};
  irMap[148][-60] = {HRIR_48K_24bit::azi_148_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_148_0_ele_neg60_0_wav};
  irMap[148][-75] = {HRIR_48K_24bit::azi_148_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_148_0_ele_neg75_0_wav};
  irMap[148][-81] = {HRIR_48K_24bit::azi_148_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_148_0_ele_neg81_0_wav};
  irMap[149][0] = {HRIR_48K_24bit::azi_149_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_149_0_ele_0_0_wav};
  irMap[149][15] = {HRIR_48K_24bit::azi_149_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_149_0_ele_15_0_wav};
  irMap[149][25] = {HRIR_48K_24bit::azi_149_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_149_0_ele_25_0_wav};
  irMap[149][30] = {HRIR_48K_24bit::azi_149_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_149_0_ele_30_0_wav};
  irMap[149][45] = {HRIR_48K_24bit::azi_149_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_149_0_ele_45_0_wav};
  irMap[149][54] = {HRIR_48K_24bit::azi_149_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_149_0_ele_54_0_wav};
  irMap[149][60] = {HRIR_48K_24bit::azi_149_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_149_0_ele_60_0_wav};
  irMap[149][75] = {HRIR_48K_24bit::azi_149_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_149_0_ele_75_0_wav};
  irMap[149][90] = {HRIR_48K_24bit::azi_149_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_149_0_ele_90_0_wav};
  irMap[149][-15] = {HRIR_48K_24bit::azi_149_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_149_0_ele_neg15_0_wav};
  irMap[149][-25] = {HRIR_48K_24bit::azi_149_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_149_0_ele_neg25_0_wav};
  irMap[149][-30] = {HRIR_48K_24bit::azi_149_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_149_0_ele_neg30_0_wav};
  irMap[149][-45] = {HRIR_48K_24bit::azi_149_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_149_0_ele_neg45_0_wav};
  irMap[149][-54] = {HRIR_48K_24bit::azi_149_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_149_0_ele_neg54_0_wav};
  irMap[149][-60] = {HRIR_48K_24bit::azi_149_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_149_0_ele_neg60_0_wav};
  irMap[149][-75] = {HRIR_48K_24bit::azi_149_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_149_0_ele_neg75_0_wav};
  irMap[149][-81] = {HRIR_48K_24bit::azi_149_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_149_0_ele_neg81_0_wav};
  irMap[150][0] = {HRIR_48K_24bit::azi_150_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_150_0_ele_0_0_wav};
  irMap[150][15] = {HRIR_48K_24bit::azi_150_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_150_0_ele_15_0_wav};
  irMap[150][25] = {HRIR_48K_24bit::azi_150_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_150_0_ele_25_0_wav};
  irMap[150][30] = {HRIR_48K_24bit::azi_150_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_150_0_ele_30_0_wav};
  irMap[150][45] = {HRIR_48K_24bit::azi_150_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_150_0_ele_45_0_wav};
  irMap[150][54] = {HRIR_48K_24bit::azi_150_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_150_0_ele_54_0_wav};
  irMap[150][60] = {HRIR_48K_24bit::azi_150_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_150_0_ele_60_0_wav};
  irMap[150][75] = {HRIR_48K_24bit::azi_150_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_150_0_ele_75_0_wav};
  irMap[150][90] = {HRIR_48K_24bit::azi_150_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_150_0_ele_90_0_wav};
  irMap[150][-15] = {HRIR_48K_24bit::azi_150_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_150_0_ele_neg15_0_wav};
  irMap[150][-25] = {HRIR_48K_24bit::azi_150_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_150_0_ele_neg25_0_wav};
  irMap[150][-30] = {HRIR_48K_24bit::azi_150_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_150_0_ele_neg30_0_wav};
  irMap[150][-45] = {HRIR_48K_24bit::azi_150_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_150_0_ele_neg45_0_wav};
  irMap[150][-54] = {HRIR_48K_24bit::azi_150_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_150_0_ele_neg54_0_wav};
  irMap[150][-60] = {HRIR_48K_24bit::azi_150_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_150_0_ele_neg60_0_wav};
  irMap[150][-75] = {HRIR_48K_24bit::azi_150_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_150_0_ele_neg75_0_wav};
  irMap[150][-81] = {HRIR_48K_24bit::azi_150_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_150_0_ele_neg81_0_wav};
  irMap[151][0] = {HRIR_48K_24bit::azi_151_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_151_0_ele_0_0_wav};
  irMap[151][15] = {HRIR_48K_24bit::azi_151_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_151_0_ele_15_0_wav};
  irMap[151][25] = {HRIR_48K_24bit::azi_151_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_151_0_ele_25_0_wav};
  irMap[151][30] = {HRIR_48K_24bit::azi_151_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_151_0_ele_30_0_wav};
  irMap[151][45] = {HRIR_48K_24bit::azi_151_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_151_0_ele_45_0_wav};
  irMap[151][54] = {HRIR_48K_24bit::azi_151_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_151_0_ele_54_0_wav};
  irMap[151][60] = {HRIR_48K_24bit::azi_151_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_151_0_ele_60_0_wav};
  irMap[151][75] = {HRIR_48K_24bit::azi_151_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_151_0_ele_75_0_wav};
  irMap[151][90] = {HRIR_48K_24bit::azi_151_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_151_0_ele_90_0_wav};
  irMap[151][-15] = {HRIR_48K_24bit::azi_151_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_151_0_ele_neg15_0_wav};
  irMap[151][-25] = {HRIR_48K_24bit::azi_151_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_151_0_ele_neg25_0_wav};
  irMap[151][-30] = {HRIR_48K_24bit::azi_151_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_151_0_ele_neg30_0_wav};
  irMap[151][-45] = {HRIR_48K_24bit::azi_151_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_151_0_ele_neg45_0_wav};
  irMap[151][-54] = {HRIR_48K_24bit::azi_151_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_151_0_ele_neg54_0_wav};
  irMap[151][-60] = {HRIR_48K_24bit::azi_151_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_151_0_ele_neg60_0_wav};
  irMap[151][-75] = {HRIR_48K_24bit::azi_151_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_151_0_ele_neg75_0_wav};
  irMap[151][-81] = {HRIR_48K_24bit::azi_151_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_151_0_ele_neg81_0_wav};
  irMap[152][0] = {HRIR_48K_24bit::azi_152_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_152_0_ele_0_0_wav};
  irMap[152][15] = {HRIR_48K_24bit::azi_152_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_152_0_ele_15_0_wav};
  irMap[152][25] = {HRIR_48K_24bit::azi_152_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_152_0_ele_25_0_wav};
  irMap[152][30] = {HRIR_48K_24bit::azi_152_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_152_0_ele_30_0_wav};
  irMap[152][45] = {HRIR_48K_24bit::azi_152_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_152_0_ele_45_0_wav};
  irMap[152][54] = {HRIR_48K_24bit::azi_152_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_152_0_ele_54_0_wav};
  irMap[152][60] = {HRIR_48K_24bit::azi_152_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_152_0_ele_60_0_wav};
  irMap[152][75] = {HRIR_48K_24bit::azi_152_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_152_0_ele_75_0_wav};
  irMap[152][90] = {HRIR_48K_24bit::azi_152_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_152_0_ele_90_0_wav};
  irMap[152][-15] = {HRIR_48K_24bit::azi_152_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_152_0_ele_neg15_0_wav};
  irMap[152][-25] = {HRIR_48K_24bit::azi_152_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_152_0_ele_neg25_0_wav};
  irMap[152][-30] = {HRIR_48K_24bit::azi_152_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_152_0_ele_neg30_0_wav};
  irMap[152][-45] = {HRIR_48K_24bit::azi_152_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_152_0_ele_neg45_0_wav};
  irMap[152][-54] = {HRIR_48K_24bit::azi_152_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_152_0_ele_neg54_0_wav};
  irMap[152][-60] = {HRIR_48K_24bit::azi_152_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_152_0_ele_neg60_0_wav};
  irMap[152][-75] = {HRIR_48K_24bit::azi_152_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_152_0_ele_neg75_0_wav};
  irMap[152][-81] = {HRIR_48K_24bit::azi_152_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_152_0_ele_neg81_0_wav};
  irMap[153][0] = {HRIR_48K_24bit::azi_153_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_153_0_ele_0_0_wav};
  irMap[153][15] = {HRIR_48K_24bit::azi_153_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_153_0_ele_15_0_wav};
  irMap[153][25] = {HRIR_48K_24bit::azi_153_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_153_0_ele_25_0_wav};
  irMap[153][30] = {HRIR_48K_24bit::azi_153_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_153_0_ele_30_0_wav};
  irMap[153][45] = {HRIR_48K_24bit::azi_153_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_153_0_ele_45_0_wav};
  irMap[153][54] = {HRIR_48K_24bit::azi_153_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_153_0_ele_54_0_wav};
  irMap[153][60] = {HRIR_48K_24bit::azi_153_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_153_0_ele_60_0_wav};
  irMap[153][75] = {HRIR_48K_24bit::azi_153_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_153_0_ele_75_0_wav};
  irMap[153][90] = {HRIR_48K_24bit::azi_153_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_153_0_ele_90_0_wav};
  irMap[153][-15] = {HRIR_48K_24bit::azi_153_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_153_0_ele_neg15_0_wav};
  irMap[153][-25] = {HRIR_48K_24bit::azi_153_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_153_0_ele_neg25_0_wav};
  irMap[153][-30] = {HRIR_48K_24bit::azi_153_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_153_0_ele_neg30_0_wav};
  irMap[153][-45] = {HRIR_48K_24bit::azi_153_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_153_0_ele_neg45_0_wav};
  irMap[153][-54] = {HRIR_48K_24bit::azi_153_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_153_0_ele_neg54_0_wav};
  irMap[153][-60] = {HRIR_48K_24bit::azi_153_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_153_0_ele_neg60_0_wav};
  irMap[153][-75] = {HRIR_48K_24bit::azi_153_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_153_0_ele_neg75_0_wav};
  irMap[153][-81] = {HRIR_48K_24bit::azi_153_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_153_0_ele_neg81_0_wav};
  irMap[154][0] = {HRIR_48K_24bit::azi_154_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_154_0_ele_0_0_wav};
  irMap[154][15] = {HRIR_48K_24bit::azi_154_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_154_0_ele_15_0_wav};
  irMap[154][25] = {HRIR_48K_24bit::azi_154_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_154_0_ele_25_0_wav};
  irMap[154][30] = {HRIR_48K_24bit::azi_154_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_154_0_ele_30_0_wav};
  irMap[154][45] = {HRIR_48K_24bit::azi_154_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_154_0_ele_45_0_wav};
  irMap[154][54] = {HRIR_48K_24bit::azi_154_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_154_0_ele_54_0_wav};
  irMap[154][60] = {HRIR_48K_24bit::azi_154_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_154_0_ele_60_0_wav};
  irMap[154][75] = {HRIR_48K_24bit::azi_154_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_154_0_ele_75_0_wav};
  irMap[154][90] = {HRIR_48K_24bit::azi_154_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_154_0_ele_90_0_wav};
  irMap[154][-15] = {HRIR_48K_24bit::azi_154_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_154_0_ele_neg15_0_wav};
  irMap[154][-25] = {HRIR_48K_24bit::azi_154_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_154_0_ele_neg25_0_wav};
  irMap[154][-30] = {HRIR_48K_24bit::azi_154_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_154_0_ele_neg30_0_wav};
  irMap[154][-45] = {HRIR_48K_24bit::azi_154_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_154_0_ele_neg45_0_wav};
  irMap[154][-54] = {HRIR_48K_24bit::azi_154_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_154_0_ele_neg54_0_wav};
  irMap[154][-60] = {HRIR_48K_24bit::azi_154_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_154_0_ele_neg60_0_wav};
  irMap[154][-75] = {HRIR_48K_24bit::azi_154_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_154_0_ele_neg75_0_wav};
  irMap[154][-81] = {HRIR_48K_24bit::azi_154_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_154_0_ele_neg81_0_wav};
  irMap[155][0] = {HRIR_48K_24bit::azi_155_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_155_0_ele_0_0_wav};
  irMap[155][15] = {HRIR_48K_24bit::azi_155_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_155_0_ele_15_0_wav};
  irMap[155][25] = {HRIR_48K_24bit::azi_155_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_155_0_ele_25_0_wav};
  irMap[155][30] = {HRIR_48K_24bit::azi_155_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_155_0_ele_30_0_wav};
  irMap[155][45] = {HRIR_48K_24bit::azi_155_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_155_0_ele_45_0_wav};
  irMap[155][54] = {HRIR_48K_24bit::azi_155_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_155_0_ele_54_0_wav};
  irMap[155][60] = {HRIR_48K_24bit::azi_155_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_155_0_ele_60_0_wav};
  irMap[155][75] = {HRIR_48K_24bit::azi_155_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_155_0_ele_75_0_wav};
  irMap[155][90] = {HRIR_48K_24bit::azi_155_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_155_0_ele_90_0_wav};
  irMap[155][-15] = {HRIR_48K_24bit::azi_155_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_155_0_ele_neg15_0_wav};
  irMap[155][-25] = {HRIR_48K_24bit::azi_155_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_155_0_ele_neg25_0_wav};
  irMap[155][-30] = {HRIR_48K_24bit::azi_155_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_155_0_ele_neg30_0_wav};
  irMap[155][-45] = {HRIR_48K_24bit::azi_155_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_155_0_ele_neg45_0_wav};
  irMap[155][-54] = {HRIR_48K_24bit::azi_155_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_155_0_ele_neg54_0_wav};
  irMap[155][-60] = {HRIR_48K_24bit::azi_155_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_155_0_ele_neg60_0_wav};
  irMap[155][-75] = {HRIR_48K_24bit::azi_155_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_155_0_ele_neg75_0_wav};
  irMap[155][-81] = {HRIR_48K_24bit::azi_155_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_155_0_ele_neg81_0_wav};
  irMap[156][0] = {HRIR_48K_24bit::azi_156_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_156_0_ele_0_0_wav};
  irMap[156][15] = {HRIR_48K_24bit::azi_156_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_156_0_ele_15_0_wav};
  irMap[156][25] = {HRIR_48K_24bit::azi_156_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_156_0_ele_25_0_wav};
  irMap[156][30] = {HRIR_48K_24bit::azi_156_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_156_0_ele_30_0_wav};
  irMap[156][45] = {HRIR_48K_24bit::azi_156_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_156_0_ele_45_0_wav};
  irMap[156][54] = {HRIR_48K_24bit::azi_156_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_156_0_ele_54_0_wav};
  irMap[156][60] = {HRIR_48K_24bit::azi_156_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_156_0_ele_60_0_wav};
  irMap[156][75] = {HRIR_48K_24bit::azi_156_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_156_0_ele_75_0_wav};
  irMap[156][90] = {HRIR_48K_24bit::azi_156_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_156_0_ele_90_0_wav};
  irMap[156][-15] = {HRIR_48K_24bit::azi_156_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_156_0_ele_neg15_0_wav};
  irMap[156][-25] = {HRIR_48K_24bit::azi_156_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_156_0_ele_neg25_0_wav};
  irMap[156][-30] = {HRIR_48K_24bit::azi_156_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_156_0_ele_neg30_0_wav};
  irMap[156][-45] = {HRIR_48K_24bit::azi_156_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_156_0_ele_neg45_0_wav};
  irMap[156][-54] = {HRIR_48K_24bit::azi_156_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_156_0_ele_neg54_0_wav};
  irMap[156][-60] = {HRIR_48K_24bit::azi_156_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_156_0_ele_neg60_0_wav};
  irMap[156][-75] = {HRIR_48K_24bit::azi_156_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_156_0_ele_neg75_0_wav};
  irMap[156][-81] = {HRIR_48K_24bit::azi_156_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_156_0_ele_neg81_0_wav};
  irMap[157][0] = {HRIR_48K_24bit::azi_157_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_157_0_ele_0_0_wav};
  irMap[157][15] = {HRIR_48K_24bit::azi_157_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_157_0_ele_15_0_wav};
  irMap[157][25] = {HRIR_48K_24bit::azi_157_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_157_0_ele_25_0_wav};
  irMap[157][30] = {HRIR_48K_24bit::azi_157_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_157_0_ele_30_0_wav};
  irMap[157][45] = {HRIR_48K_24bit::azi_157_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_157_0_ele_45_0_wav};
  irMap[157][54] = {HRIR_48K_24bit::azi_157_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_157_0_ele_54_0_wav};
  irMap[157][60] = {HRIR_48K_24bit::azi_157_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_157_0_ele_60_0_wav};
  irMap[157][75] = {HRIR_48K_24bit::azi_157_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_157_0_ele_75_0_wav};
  irMap[157][90] = {HRIR_48K_24bit::azi_157_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_157_0_ele_90_0_wav};
  irMap[157][-15] = {HRIR_48K_24bit::azi_157_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_157_0_ele_neg15_0_wav};
  irMap[157][-25] = {HRIR_48K_24bit::azi_157_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_157_0_ele_neg25_0_wav};
  irMap[157][-30] = {HRIR_48K_24bit::azi_157_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_157_0_ele_neg30_0_wav};
  irMap[157][-45] = {HRIR_48K_24bit::azi_157_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_157_0_ele_neg45_0_wav};
  irMap[157][-54] = {HRIR_48K_24bit::azi_157_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_157_0_ele_neg54_0_wav};
  irMap[157][-60] = {HRIR_48K_24bit::azi_157_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_157_0_ele_neg60_0_wav};
  irMap[157][-75] = {HRIR_48K_24bit::azi_157_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_157_0_ele_neg75_0_wav};
  irMap[157][-81] = {HRIR_48K_24bit::azi_157_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_157_0_ele_neg81_0_wav};
  irMap[158][0] = {HRIR_48K_24bit::azi_158_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_158_0_ele_0_0_wav};
  irMap[158][15] = {HRIR_48K_24bit::azi_158_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_158_0_ele_15_0_wav};
  irMap[158][25] = {HRIR_48K_24bit::azi_158_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_158_0_ele_25_0_wav};
  irMap[158][30] = {HRIR_48K_24bit::azi_158_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_158_0_ele_30_0_wav};
  irMap[158][45] = {HRIR_48K_24bit::azi_158_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_158_0_ele_45_0_wav};
  irMap[158][54] = {HRIR_48K_24bit::azi_158_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_158_0_ele_54_0_wav};
  irMap[158][60] = {HRIR_48K_24bit::azi_158_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_158_0_ele_60_0_wav};
  irMap[158][75] = {HRIR_48K_24bit::azi_158_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_158_0_ele_75_0_wav};
  irMap[158][90] = {HRIR_48K_24bit::azi_158_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_158_0_ele_90_0_wav};
  irMap[158][-15] = {HRIR_48K_24bit::azi_158_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_158_0_ele_neg15_0_wav};
  irMap[158][-25] = {HRIR_48K_24bit::azi_158_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_158_0_ele_neg25_0_wav};
  irMap[158][-30] = {HRIR_48K_24bit::azi_158_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_158_0_ele_neg30_0_wav};
  irMap[158][-45] = {HRIR_48K_24bit::azi_158_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_158_0_ele_neg45_0_wav};
  irMap[158][-54] = {HRIR_48K_24bit::azi_158_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_158_0_ele_neg54_0_wav};
  irMap[158][-60] = {HRIR_48K_24bit::azi_158_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_158_0_ele_neg60_0_wav};
  irMap[158][-75] = {HRIR_48K_24bit::azi_158_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_158_0_ele_neg75_0_wav};
  irMap[158][-81] = {HRIR_48K_24bit::azi_158_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_158_0_ele_neg81_0_wav};
  irMap[159][0] = {HRIR_48K_24bit::azi_159_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_159_0_ele_0_0_wav};
  irMap[159][15] = {HRIR_48K_24bit::azi_159_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_159_0_ele_15_0_wav};
  irMap[159][25] = {HRIR_48K_24bit::azi_159_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_159_0_ele_25_0_wav};
  irMap[159][30] = {HRIR_48K_24bit::azi_159_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_159_0_ele_30_0_wav};
  irMap[159][45] = {HRIR_48K_24bit::azi_159_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_159_0_ele_45_0_wav};
  irMap[159][54] = {HRIR_48K_24bit::azi_159_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_159_0_ele_54_0_wav};
  irMap[159][60] = {HRIR_48K_24bit::azi_159_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_159_0_ele_60_0_wav};
  irMap[159][75] = {HRIR_48K_24bit::azi_159_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_159_0_ele_75_0_wav};
  irMap[159][90] = {HRIR_48K_24bit::azi_159_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_159_0_ele_90_0_wav};
  irMap[159][-15] = {HRIR_48K_24bit::azi_159_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_159_0_ele_neg15_0_wav};
  irMap[159][-25] = {HRIR_48K_24bit::azi_159_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_159_0_ele_neg25_0_wav};
  irMap[159][-30] = {HRIR_48K_24bit::azi_159_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_159_0_ele_neg30_0_wav};
  irMap[159][-45] = {HRIR_48K_24bit::azi_159_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_159_0_ele_neg45_0_wav};
  irMap[159][-54] = {HRIR_48K_24bit::azi_159_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_159_0_ele_neg54_0_wav};
  irMap[159][-60] = {HRIR_48K_24bit::azi_159_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_159_0_ele_neg60_0_wav};
  irMap[159][-75] = {HRIR_48K_24bit::azi_159_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_159_0_ele_neg75_0_wav};
  irMap[159][-81] = {HRIR_48K_24bit::azi_159_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_159_0_ele_neg81_0_wav};
  irMap[160][0] = {HRIR_48K_24bit::azi_160_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_160_0_ele_0_0_wav};
  irMap[160][15] = {HRIR_48K_24bit::azi_160_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_160_0_ele_15_0_wav};
  irMap[160][25] = {HRIR_48K_24bit::azi_160_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_160_0_ele_25_0_wav};
  irMap[160][30] = {HRIR_48K_24bit::azi_160_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_160_0_ele_30_0_wav};
  irMap[160][45] = {HRIR_48K_24bit::azi_160_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_160_0_ele_45_0_wav};
  irMap[160][54] = {HRIR_48K_24bit::azi_160_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_160_0_ele_54_0_wav};
  irMap[160][60] = {HRIR_48K_24bit::azi_160_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_160_0_ele_60_0_wav};
  irMap[160][75] = {HRIR_48K_24bit::azi_160_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_160_0_ele_75_0_wav};
  irMap[160][90] = {HRIR_48K_24bit::azi_160_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_160_0_ele_90_0_wav};
  irMap[160][-15] = {HRIR_48K_24bit::azi_160_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_160_0_ele_neg15_0_wav};
  irMap[160][-25] = {HRIR_48K_24bit::azi_160_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_160_0_ele_neg25_0_wav};
  irMap[160][-30] = {HRIR_48K_24bit::azi_160_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_160_0_ele_neg30_0_wav};
  irMap[160][-45] = {HRIR_48K_24bit::azi_160_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_160_0_ele_neg45_0_wav};
  irMap[160][-54] = {HRIR_48K_24bit::azi_160_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_160_0_ele_neg54_0_wav};
  irMap[160][-60] = {HRIR_48K_24bit::azi_160_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_160_0_ele_neg60_0_wav};
  irMap[160][-75] = {HRIR_48K_24bit::azi_160_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_160_0_ele_neg75_0_wav};
  irMap[160][-81] = {HRIR_48K_24bit::azi_160_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_160_0_ele_neg81_0_wav};
  irMap[161][0] = {HRIR_48K_24bit::azi_161_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_161_0_ele_0_0_wav};
  irMap[161][15] = {HRIR_48K_24bit::azi_161_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_161_0_ele_15_0_wav};
  irMap[161][25] = {HRIR_48K_24bit::azi_161_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_161_0_ele_25_0_wav};
  irMap[161][30] = {HRIR_48K_24bit::azi_161_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_161_0_ele_30_0_wav};
  irMap[161][45] = {HRIR_48K_24bit::azi_161_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_161_0_ele_45_0_wav};
  irMap[161][54] = {HRIR_48K_24bit::azi_161_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_161_0_ele_54_0_wav};
  irMap[161][60] = {HRIR_48K_24bit::azi_161_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_161_0_ele_60_0_wav};
  irMap[161][75] = {HRIR_48K_24bit::azi_161_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_161_0_ele_75_0_wav};
  irMap[161][90] = {HRIR_48K_24bit::azi_161_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_161_0_ele_90_0_wav};
  irMap[161][-15] = {HRIR_48K_24bit::azi_161_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_161_0_ele_neg15_0_wav};
  irMap[161][-25] = {HRIR_48K_24bit::azi_161_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_161_0_ele_neg25_0_wav};
  irMap[161][-30] = {HRIR_48K_24bit::azi_161_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_161_0_ele_neg30_0_wav};
  irMap[161][-45] = {HRIR_48K_24bit::azi_161_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_161_0_ele_neg45_0_wav};
  irMap[161][-54] = {HRIR_48K_24bit::azi_161_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_161_0_ele_neg54_0_wav};
  irMap[161][-60] = {HRIR_48K_24bit::azi_161_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_161_0_ele_neg60_0_wav};
  irMap[161][-75] = {HRIR_48K_24bit::azi_161_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_161_0_ele_neg75_0_wav};
  irMap[161][-81] = {HRIR_48K_24bit::azi_161_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_161_0_ele_neg81_0_wav};
  irMap[162][0] = {HRIR_48K_24bit::azi_162_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_162_0_ele_0_0_wav};
  irMap[162][15] = {HRIR_48K_24bit::azi_162_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_162_0_ele_15_0_wav};
  irMap[162][25] = {HRIR_48K_24bit::azi_162_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_162_0_ele_25_0_wav};
  irMap[162][30] = {HRIR_48K_24bit::azi_162_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_162_0_ele_30_0_wav};
  irMap[162][45] = {HRIR_48K_24bit::azi_162_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_162_0_ele_45_0_wav};
  irMap[162][54] = {HRIR_48K_24bit::azi_162_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_162_0_ele_54_0_wav};
  irMap[162][60] = {HRIR_48K_24bit::azi_162_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_162_0_ele_60_0_wav};
  irMap[162][75] = {HRIR_48K_24bit::azi_162_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_162_0_ele_75_0_wav};
  irMap[162][90] = {HRIR_48K_24bit::azi_162_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_162_0_ele_90_0_wav};
  irMap[162][-15] = {HRIR_48K_24bit::azi_162_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_162_0_ele_neg15_0_wav};
  irMap[162][-25] = {HRIR_48K_24bit::azi_162_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_162_0_ele_neg25_0_wav};
  irMap[162][-30] = {HRIR_48K_24bit::azi_162_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_162_0_ele_neg30_0_wav};
  irMap[162][-45] = {HRIR_48K_24bit::azi_162_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_162_0_ele_neg45_0_wav};
  irMap[162][-54] = {HRIR_48K_24bit::azi_162_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_162_0_ele_neg54_0_wav};
  irMap[162][-60] = {HRIR_48K_24bit::azi_162_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_162_0_ele_neg60_0_wav};
  irMap[162][-75] = {HRIR_48K_24bit::azi_162_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_162_0_ele_neg75_0_wav};
  irMap[162][-81] = {HRIR_48K_24bit::azi_162_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_162_0_ele_neg81_0_wav};
  irMap[163][0] = {HRIR_48K_24bit::azi_163_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_163_0_ele_0_0_wav};
  irMap[163][15] = {HRIR_48K_24bit::azi_163_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_163_0_ele_15_0_wav};
  irMap[163][25] = {HRIR_48K_24bit::azi_163_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_163_0_ele_25_0_wav};
  irMap[163][30] = {HRIR_48K_24bit::azi_163_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_163_0_ele_30_0_wav};
  irMap[163][45] = {HRIR_48K_24bit::azi_163_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_163_0_ele_45_0_wav};
  irMap[163][54] = {HRIR_48K_24bit::azi_163_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_163_0_ele_54_0_wav};
  irMap[163][60] = {HRIR_48K_24bit::azi_163_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_163_0_ele_60_0_wav};
  irMap[163][75] = {HRIR_48K_24bit::azi_163_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_163_0_ele_75_0_wav};
  irMap[163][90] = {HRIR_48K_24bit::azi_163_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_163_0_ele_90_0_wav};
  irMap[163][-15] = {HRIR_48K_24bit::azi_163_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_163_0_ele_neg15_0_wav};
  irMap[163][-25] = {HRIR_48K_24bit::azi_163_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_163_0_ele_neg25_0_wav};
  irMap[163][-30] = {HRIR_48K_24bit::azi_163_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_163_0_ele_neg30_0_wav};
  irMap[163][-45] = {HRIR_48K_24bit::azi_163_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_163_0_ele_neg45_0_wav};
  irMap[163][-54] = {HRIR_48K_24bit::azi_163_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_163_0_ele_neg54_0_wav};
  irMap[163][-60] = {HRIR_48K_24bit::azi_163_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_163_0_ele_neg60_0_wav};
  irMap[163][-75] = {HRIR_48K_24bit::azi_163_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_163_0_ele_neg75_0_wav};
  irMap[163][-81] = {HRIR_48K_24bit::azi_163_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_163_0_ele_neg81_0_wav};
  irMap[164][0] = {HRIR_48K_24bit::azi_164_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_164_0_ele_0_0_wav};
  irMap[164][15] = {HRIR_48K_24bit::azi_164_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_164_0_ele_15_0_wav};
  irMap[164][25] = {HRIR_48K_24bit::azi_164_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_164_0_ele_25_0_wav};
  irMap[164][30] = {HRIR_48K_24bit::azi_164_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_164_0_ele_30_0_wav};
  irMap[164][45] = {HRIR_48K_24bit::azi_164_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_164_0_ele_45_0_wav};
  irMap[164][54] = {HRIR_48K_24bit::azi_164_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_164_0_ele_54_0_wav};
  irMap[164][60] = {HRIR_48K_24bit::azi_164_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_164_0_ele_60_0_wav};
  irMap[164][75] = {HRIR_48K_24bit::azi_164_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_164_0_ele_75_0_wav};
  irMap[164][90] = {HRIR_48K_24bit::azi_164_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_164_0_ele_90_0_wav};
  irMap[164][-15] = {HRIR_48K_24bit::azi_164_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_164_0_ele_neg15_0_wav};
  irMap[164][-25] = {HRIR_48K_24bit::azi_164_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_164_0_ele_neg25_0_wav};
  irMap[164][-30] = {HRIR_48K_24bit::azi_164_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_164_0_ele_neg30_0_wav};
  irMap[164][-45] = {HRIR_48K_24bit::azi_164_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_164_0_ele_neg45_0_wav};
  irMap[164][-54] = {HRIR_48K_24bit::azi_164_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_164_0_ele_neg54_0_wav};
  irMap[164][-60] = {HRIR_48K_24bit::azi_164_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_164_0_ele_neg60_0_wav};
  irMap[164][-75] = {HRIR_48K_24bit::azi_164_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_164_0_ele_neg75_0_wav};
  irMap[164][-81] = {HRIR_48K_24bit::azi_164_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_164_0_ele_neg81_0_wav};
  irMap[165][0] = {HRIR_48K_24bit::azi_165_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_165_0_ele_0_0_wav};
  irMap[165][15] = {HRIR_48K_24bit::azi_165_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_165_0_ele_15_0_wav};
  irMap[165][25] = {HRIR_48K_24bit::azi_165_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_165_0_ele_25_0_wav};
  irMap[165][30] = {HRIR_48K_24bit::azi_165_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_165_0_ele_30_0_wav};
  irMap[165][45] = {HRIR_48K_24bit::azi_165_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_165_0_ele_45_0_wav};
  irMap[165][54] = {HRIR_48K_24bit::azi_165_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_165_0_ele_54_0_wav};
  irMap[165][60] = {HRIR_48K_24bit::azi_165_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_165_0_ele_60_0_wav};
  irMap[165][75] = {HRIR_48K_24bit::azi_165_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_165_0_ele_75_0_wav};
  irMap[165][90] = {HRIR_48K_24bit::azi_165_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_165_0_ele_90_0_wav};
  irMap[165][-15] = {HRIR_48K_24bit::azi_165_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_165_0_ele_neg15_0_wav};
  irMap[165][-25] = {HRIR_48K_24bit::azi_165_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_165_0_ele_neg25_0_wav};
  irMap[165][-30] = {HRIR_48K_24bit::azi_165_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_165_0_ele_neg30_0_wav};
  irMap[165][-45] = {HRIR_48K_24bit::azi_165_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_165_0_ele_neg45_0_wav};
  irMap[165][-54] = {HRIR_48K_24bit::azi_165_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_165_0_ele_neg54_0_wav};
  irMap[165][-60] = {HRIR_48K_24bit::azi_165_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_165_0_ele_neg60_0_wav};
  irMap[165][-75] = {HRIR_48K_24bit::azi_165_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_165_0_ele_neg75_0_wav};
  irMap[165][-81] = {HRIR_48K_24bit::azi_165_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_165_0_ele_neg81_0_wav};
  irMap[166][0] = {HRIR_48K_24bit::azi_166_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_166_0_ele_0_0_wav};
  irMap[166][15] = {HRIR_48K_24bit::azi_166_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_166_0_ele_15_0_wav};
  irMap[166][25] = {HRIR_48K_24bit::azi_166_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_166_0_ele_25_0_wav};
  irMap[166][30] = {HRIR_48K_24bit::azi_166_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_166_0_ele_30_0_wav};
  irMap[166][45] = {HRIR_48K_24bit::azi_166_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_166_0_ele_45_0_wav};
  irMap[166][54] = {HRIR_48K_24bit::azi_166_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_166_0_ele_54_0_wav};
  irMap[166][60] = {HRIR_48K_24bit::azi_166_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_166_0_ele_60_0_wav};
  irMap[166][75] = {HRIR_48K_24bit::azi_166_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_166_0_ele_75_0_wav};
  irMap[166][90] = {HRIR_48K_24bit::azi_166_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_166_0_ele_90_0_wav};
  irMap[166][-15] = {HRIR_48K_24bit::azi_166_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_166_0_ele_neg15_0_wav};
  irMap[166][-25] = {HRIR_48K_24bit::azi_166_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_166_0_ele_neg25_0_wav};
  irMap[166][-30] = {HRIR_48K_24bit::azi_166_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_166_0_ele_neg30_0_wav};
  irMap[166][-45] = {HRIR_48K_24bit::azi_166_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_166_0_ele_neg45_0_wav};
  irMap[166][-54] = {HRIR_48K_24bit::azi_166_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_166_0_ele_neg54_0_wav};
  irMap[166][-60] = {HRIR_48K_24bit::azi_166_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_166_0_ele_neg60_0_wav};
  irMap[166][-75] = {HRIR_48K_24bit::azi_166_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_166_0_ele_neg75_0_wav};
  irMap[166][-81] = {HRIR_48K_24bit::azi_166_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_166_0_ele_neg81_0_wav};
  irMap[167][0] = {HRIR_48K_24bit::azi_167_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_167_0_ele_0_0_wav};
  irMap[167][15] = {HRIR_48K_24bit::azi_167_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_167_0_ele_15_0_wav};
  irMap[167][25] = {HRIR_48K_24bit::azi_167_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_167_0_ele_25_0_wav};
  irMap[167][30] = {HRIR_48K_24bit::azi_167_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_167_0_ele_30_0_wav};
  irMap[167][45] = {HRIR_48K_24bit::azi_167_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_167_0_ele_45_0_wav};
  irMap[167][54] = {HRIR_48K_24bit::azi_167_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_167_0_ele_54_0_wav};
  irMap[167][60] = {HRIR_48K_24bit::azi_167_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_167_0_ele_60_0_wav};
  irMap[167][75] = {HRIR_48K_24bit::azi_167_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_167_0_ele_75_0_wav};
  irMap[167][90] = {HRIR_48K_24bit::azi_167_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_167_0_ele_90_0_wav};
  irMap[167][-15] = {HRIR_48K_24bit::azi_167_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_167_0_ele_neg15_0_wav};
  irMap[167][-25] = {HRIR_48K_24bit::azi_167_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_167_0_ele_neg25_0_wav};
  irMap[167][-30] = {HRIR_48K_24bit::azi_167_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_167_0_ele_neg30_0_wav};
  irMap[167][-45] = {HRIR_48K_24bit::azi_167_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_167_0_ele_neg45_0_wav};
  irMap[167][-54] = {HRIR_48K_24bit::azi_167_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_167_0_ele_neg54_0_wav};
  irMap[167][-60] = {HRIR_48K_24bit::azi_167_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_167_0_ele_neg60_0_wav};
  irMap[167][-75] = {HRIR_48K_24bit::azi_167_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_167_0_ele_neg75_0_wav};
  irMap[167][-81] = {HRIR_48K_24bit::azi_167_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_167_0_ele_neg81_0_wav};
  irMap[168][0] = {HRIR_48K_24bit::azi_168_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_168_0_ele_0_0_wav};
  irMap[168][15] = {HRIR_48K_24bit::azi_168_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_168_0_ele_15_0_wav};
  irMap[168][25] = {HRIR_48K_24bit::azi_168_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_168_0_ele_25_0_wav};
  irMap[168][30] = {HRIR_48K_24bit::azi_168_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_168_0_ele_30_0_wav};
  irMap[168][45] = {HRIR_48K_24bit::azi_168_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_168_0_ele_45_0_wav};
  irMap[168][54] = {HRIR_48K_24bit::azi_168_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_168_0_ele_54_0_wav};
  irMap[168][60] = {HRIR_48K_24bit::azi_168_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_168_0_ele_60_0_wav};
  irMap[168][75] = {HRIR_48K_24bit::azi_168_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_168_0_ele_75_0_wav};
  irMap[168][90] = {HRIR_48K_24bit::azi_168_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_168_0_ele_90_0_wav};
  irMap[168][-15] = {HRIR_48K_24bit::azi_168_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_168_0_ele_neg15_0_wav};
  irMap[168][-25] = {HRIR_48K_24bit::azi_168_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_168_0_ele_neg25_0_wav};
  irMap[168][-30] = {HRIR_48K_24bit::azi_168_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_168_0_ele_neg30_0_wav};
  irMap[168][-45] = {HRIR_48K_24bit::azi_168_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_168_0_ele_neg45_0_wav};
  irMap[168][-54] = {HRIR_48K_24bit::azi_168_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_168_0_ele_neg54_0_wav};
  irMap[168][-60] = {HRIR_48K_24bit::azi_168_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_168_0_ele_neg60_0_wav};
  irMap[168][-75] = {HRIR_48K_24bit::azi_168_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_168_0_ele_neg75_0_wav};
  irMap[168][-81] = {HRIR_48K_24bit::azi_168_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_168_0_ele_neg81_0_wav};
  irMap[169][0] = {HRIR_48K_24bit::azi_169_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_169_0_ele_0_0_wav};
  irMap[169][15] = {HRIR_48K_24bit::azi_169_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_169_0_ele_15_0_wav};
  irMap[169][25] = {HRIR_48K_24bit::azi_169_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_169_0_ele_25_0_wav};
  irMap[169][30] = {HRIR_48K_24bit::azi_169_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_169_0_ele_30_0_wav};
  irMap[169][45] = {HRIR_48K_24bit::azi_169_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_169_0_ele_45_0_wav};
  irMap[169][54] = {HRIR_48K_24bit::azi_169_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_169_0_ele_54_0_wav};
  irMap[169][60] = {HRIR_48K_24bit::azi_169_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_169_0_ele_60_0_wav};
  irMap[169][75] = {HRIR_48K_24bit::azi_169_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_169_0_ele_75_0_wav};
  irMap[169][90] = {HRIR_48K_24bit::azi_169_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_169_0_ele_90_0_wav};
  irMap[169][-15] = {HRIR_48K_24bit::azi_169_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_169_0_ele_neg15_0_wav};
  irMap[169][-25] = {HRIR_48K_24bit::azi_169_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_169_0_ele_neg25_0_wav};
  irMap[169][-30] = {HRIR_48K_24bit::azi_169_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_169_0_ele_neg30_0_wav};
  irMap[169][-45] = {HRIR_48K_24bit::azi_169_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_169_0_ele_neg45_0_wav};
  irMap[169][-54] = {HRIR_48K_24bit::azi_169_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_169_0_ele_neg54_0_wav};
  irMap[169][-60] = {HRIR_48K_24bit::azi_169_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_169_0_ele_neg60_0_wav};
  irMap[169][-75] = {HRIR_48K_24bit::azi_169_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_169_0_ele_neg75_0_wav};
  irMap[169][-81] = {HRIR_48K_24bit::azi_169_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_169_0_ele_neg81_0_wav};
  irMap[170][0] = {HRIR_48K_24bit::azi_170_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_170_0_ele_0_0_wav};
  irMap[170][15] = {HRIR_48K_24bit::azi_170_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_170_0_ele_15_0_wav};
  irMap[170][25] = {HRIR_48K_24bit::azi_170_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_170_0_ele_25_0_wav};
  irMap[170][30] = {HRIR_48K_24bit::azi_170_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_170_0_ele_30_0_wav};
  irMap[170][45] = {HRIR_48K_24bit::azi_170_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_170_0_ele_45_0_wav};
  irMap[170][54] = {HRIR_48K_24bit::azi_170_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_170_0_ele_54_0_wav};
  irMap[170][60] = {HRIR_48K_24bit::azi_170_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_170_0_ele_60_0_wav};
  irMap[170][75] = {HRIR_48K_24bit::azi_170_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_170_0_ele_75_0_wav};
  irMap[170][90] = {HRIR_48K_24bit::azi_170_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_170_0_ele_90_0_wav};
  irMap[170][-15] = {HRIR_48K_24bit::azi_170_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_170_0_ele_neg15_0_wav};
  irMap[170][-25] = {HRIR_48K_24bit::azi_170_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_170_0_ele_neg25_0_wav};
  irMap[170][-30] = {HRIR_48K_24bit::azi_170_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_170_0_ele_neg30_0_wav};
  irMap[170][-45] = {HRIR_48K_24bit::azi_170_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_170_0_ele_neg45_0_wav};
  irMap[170][-54] = {HRIR_48K_24bit::azi_170_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_170_0_ele_neg54_0_wav};
  irMap[170][-60] = {HRIR_48K_24bit::azi_170_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_170_0_ele_neg60_0_wav};
  irMap[170][-75] = {HRIR_48K_24bit::azi_170_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_170_0_ele_neg75_0_wav};
  irMap[170][-81] = {HRIR_48K_24bit::azi_170_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_170_0_ele_neg81_0_wav};
  irMap[171][0] = {HRIR_48K_24bit::azi_171_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_171_0_ele_0_0_wav};
  irMap[171][15] = {HRIR_48K_24bit::azi_171_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_171_0_ele_15_0_wav};
  irMap[171][25] = {HRIR_48K_24bit::azi_171_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_171_0_ele_25_0_wav};
  irMap[171][30] = {HRIR_48K_24bit::azi_171_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_171_0_ele_30_0_wav};
  irMap[171][45] = {HRIR_48K_24bit::azi_171_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_171_0_ele_45_0_wav};
  irMap[171][54] = {HRIR_48K_24bit::azi_171_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_171_0_ele_54_0_wav};
  irMap[171][60] = {HRIR_48K_24bit::azi_171_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_171_0_ele_60_0_wav};
  irMap[171][75] = {HRIR_48K_24bit::azi_171_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_171_0_ele_75_0_wav};
  irMap[171][90] = {HRIR_48K_24bit::azi_171_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_171_0_ele_90_0_wav};
  irMap[171][-15] = {HRIR_48K_24bit::azi_171_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_171_0_ele_neg15_0_wav};
  irMap[171][-25] = {HRIR_48K_24bit::azi_171_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_171_0_ele_neg25_0_wav};
  irMap[171][-30] = {HRIR_48K_24bit::azi_171_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_171_0_ele_neg30_0_wav};
  irMap[171][-45] = {HRIR_48K_24bit::azi_171_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_171_0_ele_neg45_0_wav};
  irMap[171][-54] = {HRIR_48K_24bit::azi_171_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_171_0_ele_neg54_0_wav};
  irMap[171][-60] = {HRIR_48K_24bit::azi_171_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_171_0_ele_neg60_0_wav};
  irMap[171][-75] = {HRIR_48K_24bit::azi_171_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_171_0_ele_neg75_0_wav};
  irMap[171][-81] = {HRIR_48K_24bit::azi_171_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_171_0_ele_neg81_0_wav};
  irMap[172][0] = {HRIR_48K_24bit::azi_172_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_172_0_ele_0_0_wav};
  irMap[172][15] = {HRIR_48K_24bit::azi_172_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_172_0_ele_15_0_wav};
  irMap[172][25] = {HRIR_48K_24bit::azi_172_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_172_0_ele_25_0_wav};
  irMap[172][30] = {HRIR_48K_24bit::azi_172_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_172_0_ele_30_0_wav};
  irMap[172][45] = {HRIR_48K_24bit::azi_172_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_172_0_ele_45_0_wav};
  irMap[172][54] = {HRIR_48K_24bit::azi_172_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_172_0_ele_54_0_wav};
  irMap[172][60] = {HRIR_48K_24bit::azi_172_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_172_0_ele_60_0_wav};
  irMap[172][75] = {HRIR_48K_24bit::azi_172_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_172_0_ele_75_0_wav};
  irMap[172][90] = {HRIR_48K_24bit::azi_172_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_172_0_ele_90_0_wav};
  irMap[172][-15] = {HRIR_48K_24bit::azi_172_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_172_0_ele_neg15_0_wav};
  irMap[172][-25] = {HRIR_48K_24bit::azi_172_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_172_0_ele_neg25_0_wav};
  irMap[172][-30] = {HRIR_48K_24bit::azi_172_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_172_0_ele_neg30_0_wav};
  irMap[172][-45] = {HRIR_48K_24bit::azi_172_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_172_0_ele_neg45_0_wav};
  irMap[172][-54] = {HRIR_48K_24bit::azi_172_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_172_0_ele_neg54_0_wav};
  irMap[172][-60] = {HRIR_48K_24bit::azi_172_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_172_0_ele_neg60_0_wav};
  irMap[172][-75] = {HRIR_48K_24bit::azi_172_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_172_0_ele_neg75_0_wav};
  irMap[172][-81] = {HRIR_48K_24bit::azi_172_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_172_0_ele_neg81_0_wav};
  irMap[173][0] = {HRIR_48K_24bit::azi_173_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_173_0_ele_0_0_wav};
  irMap[173][15] = {HRIR_48K_24bit::azi_173_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_173_0_ele_15_0_wav};
  irMap[173][25] = {HRIR_48K_24bit::azi_173_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_173_0_ele_25_0_wav};
  irMap[173][30] = {HRIR_48K_24bit::azi_173_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_173_0_ele_30_0_wav};
  irMap[173][45] = {HRIR_48K_24bit::azi_173_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_173_0_ele_45_0_wav};
  irMap[173][54] = {HRIR_48K_24bit::azi_173_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_173_0_ele_54_0_wav};
  irMap[173][60] = {HRIR_48K_24bit::azi_173_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_173_0_ele_60_0_wav};
  irMap[173][75] = {HRIR_48K_24bit::azi_173_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_173_0_ele_75_0_wav};
  irMap[173][90] = {HRIR_48K_24bit::azi_173_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_173_0_ele_90_0_wav};
  irMap[173][-15] = {HRIR_48K_24bit::azi_173_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_173_0_ele_neg15_0_wav};
  irMap[173][-25] = {HRIR_48K_24bit::azi_173_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_173_0_ele_neg25_0_wav};
  irMap[173][-30] = {HRIR_48K_24bit::azi_173_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_173_0_ele_neg30_0_wav};
  irMap[173][-45] = {HRIR_48K_24bit::azi_173_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_173_0_ele_neg45_0_wav};
  irMap[173][-54] = {HRIR_48K_24bit::azi_173_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_173_0_ele_neg54_0_wav};
  irMap[173][-60] = {HRIR_48K_24bit::azi_173_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_173_0_ele_neg60_0_wav};
  irMap[173][-75] = {HRIR_48K_24bit::azi_173_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_173_0_ele_neg75_0_wav};
  irMap[173][-81] = {HRIR_48K_24bit::azi_173_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_173_0_ele_neg81_0_wav};
  irMap[174][0] = {HRIR_48K_24bit::azi_174_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_174_0_ele_0_0_wav};
  irMap[174][15] = {HRIR_48K_24bit::azi_174_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_174_0_ele_15_0_wav};
  irMap[174][25] = {HRIR_48K_24bit::azi_174_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_174_0_ele_25_0_wav};
  irMap[174][30] = {HRIR_48K_24bit::azi_174_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_174_0_ele_30_0_wav};
  irMap[174][45] = {HRIR_48K_24bit::azi_174_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_174_0_ele_45_0_wav};
  irMap[174][54] = {HRIR_48K_24bit::azi_174_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_174_0_ele_54_0_wav};
  irMap[174][60] = {HRIR_48K_24bit::azi_174_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_174_0_ele_60_0_wav};
  irMap[174][75] = {HRIR_48K_24bit::azi_174_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_174_0_ele_75_0_wav};
  irMap[174][90] = {HRIR_48K_24bit::azi_174_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_174_0_ele_90_0_wav};
  irMap[174][-15] = {HRIR_48K_24bit::azi_174_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_174_0_ele_neg15_0_wav};
  irMap[174][-25] = {HRIR_48K_24bit::azi_174_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_174_0_ele_neg25_0_wav};
  irMap[174][-30] = {HRIR_48K_24bit::azi_174_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_174_0_ele_neg30_0_wav};
  irMap[174][-45] = {HRIR_48K_24bit::azi_174_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_174_0_ele_neg45_0_wav};
  irMap[174][-54] = {HRIR_48K_24bit::azi_174_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_174_0_ele_neg54_0_wav};
  irMap[174][-60] = {HRIR_48K_24bit::azi_174_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_174_0_ele_neg60_0_wav};
  irMap[174][-75] = {HRIR_48K_24bit::azi_174_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_174_0_ele_neg75_0_wav};
  irMap[174][-81] = {HRIR_48K_24bit::azi_174_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_174_0_ele_neg81_0_wav};
  irMap[175][0] = {HRIR_48K_24bit::azi_175_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_175_0_ele_0_0_wav};
  irMap[175][15] = {HRIR_48K_24bit::azi_175_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_175_0_ele_15_0_wav};
  irMap[175][25] = {HRIR_48K_24bit::azi_175_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_175_0_ele_25_0_wav};
  irMap[175][30] = {HRIR_48K_24bit::azi_175_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_175_0_ele_30_0_wav};
  irMap[175][45] = {HRIR_48K_24bit::azi_175_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_175_0_ele_45_0_wav};
  irMap[175][54] = {HRIR_48K_24bit::azi_175_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_175_0_ele_54_0_wav};
  irMap[175][60] = {HRIR_48K_24bit::azi_175_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_175_0_ele_60_0_wav};
  irMap[175][75] = {HRIR_48K_24bit::azi_175_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_175_0_ele_75_0_wav};
  irMap[175][90] = {HRIR_48K_24bit::azi_175_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_175_0_ele_90_0_wav};
  irMap[175][-15] = {HRIR_48K_24bit::azi_175_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_175_0_ele_neg15_0_wav};
  irMap[175][-25] = {HRIR_48K_24bit::azi_175_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_175_0_ele_neg25_0_wav};
  irMap[175][-30] = {HRIR_48K_24bit::azi_175_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_175_0_ele_neg30_0_wav};
  irMap[175][-45] = {HRIR_48K_24bit::azi_175_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_175_0_ele_neg45_0_wav};
  irMap[175][-54] = {HRIR_48K_24bit::azi_175_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_175_0_ele_neg54_0_wav};
  irMap[175][-60] = {HRIR_48K_24bit::azi_175_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_175_0_ele_neg60_0_wav};
  irMap[175][-75] = {HRIR_48K_24bit::azi_175_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_175_0_ele_neg75_0_wav};
  irMap[175][-81] = {HRIR_48K_24bit::azi_175_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_175_0_ele_neg81_0_wav};
  irMap[176][0] = {HRIR_48K_24bit::azi_176_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_176_0_ele_0_0_wav};
  irMap[176][15] = {HRIR_48K_24bit::azi_176_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_176_0_ele_15_0_wav};
  irMap[176][25] = {HRIR_48K_24bit::azi_176_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_176_0_ele_25_0_wav};
  irMap[176][30] = {HRIR_48K_24bit::azi_176_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_176_0_ele_30_0_wav};
  irMap[176][45] = {HRIR_48K_24bit::azi_176_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_176_0_ele_45_0_wav};
  irMap[176][54] = {HRIR_48K_24bit::azi_176_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_176_0_ele_54_0_wav};
  irMap[176][60] = {HRIR_48K_24bit::azi_176_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_176_0_ele_60_0_wav};
  irMap[176][75] = {HRIR_48K_24bit::azi_176_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_176_0_ele_75_0_wav};
  irMap[176][90] = {HRIR_48K_24bit::azi_176_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_176_0_ele_90_0_wav};
  irMap[176][-15] = {HRIR_48K_24bit::azi_176_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_176_0_ele_neg15_0_wav};
  irMap[176][-25] = {HRIR_48K_24bit::azi_176_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_176_0_ele_neg25_0_wav};
  irMap[176][-30] = {HRIR_48K_24bit::azi_176_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_176_0_ele_neg30_0_wav};
  irMap[176][-45] = {HRIR_48K_24bit::azi_176_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_176_0_ele_neg45_0_wav};
  irMap[176][-54] = {HRIR_48K_24bit::azi_176_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_176_0_ele_neg54_0_wav};
  irMap[176][-60] = {HRIR_48K_24bit::azi_176_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_176_0_ele_neg60_0_wav};
  irMap[176][-75] = {HRIR_48K_24bit::azi_176_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_176_0_ele_neg75_0_wav};
  irMap[176][-81] = {HRIR_48K_24bit::azi_176_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_176_0_ele_neg81_0_wav};
  irMap[177][0] = {HRIR_48K_24bit::azi_177_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_177_0_ele_0_0_wav};
  irMap[177][15] = {HRIR_48K_24bit::azi_177_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_177_0_ele_15_0_wav};
  irMap[177][25] = {HRIR_48K_24bit::azi_177_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_177_0_ele_25_0_wav};
  irMap[177][30] = {HRIR_48K_24bit::azi_177_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_177_0_ele_30_0_wav};
  irMap[177][45] = {HRIR_48K_24bit::azi_177_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_177_0_ele_45_0_wav};
  irMap[177][54] = {HRIR_48K_24bit::azi_177_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_177_0_ele_54_0_wav};
  irMap[177][60] = {HRIR_48K_24bit::azi_177_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_177_0_ele_60_0_wav};
  irMap[177][75] = {HRIR_48K_24bit::azi_177_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_177_0_ele_75_0_wav};
  irMap[177][90] = {HRIR_48K_24bit::azi_177_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_177_0_ele_90_0_wav};
  irMap[177][-15] = {HRIR_48K_24bit::azi_177_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_177_0_ele_neg15_0_wav};
  irMap[177][-25] = {HRIR_48K_24bit::azi_177_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_177_0_ele_neg25_0_wav};
  irMap[177][-30] = {HRIR_48K_24bit::azi_177_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_177_0_ele_neg30_0_wav};
  irMap[177][-45] = {HRIR_48K_24bit::azi_177_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_177_0_ele_neg45_0_wav};
  irMap[177][-54] = {HRIR_48K_24bit::azi_177_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_177_0_ele_neg54_0_wav};
  irMap[177][-60] = {HRIR_48K_24bit::azi_177_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_177_0_ele_neg60_0_wav};
  irMap[177][-75] = {HRIR_48K_24bit::azi_177_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_177_0_ele_neg75_0_wav};
  irMap[177][-81] = {HRIR_48K_24bit::azi_177_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_177_0_ele_neg81_0_wav};
  irMap[178][0] = {HRIR_48K_24bit::azi_178_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_178_0_ele_0_0_wav};
  irMap[178][15] = {HRIR_48K_24bit::azi_178_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_178_0_ele_15_0_wav};
  irMap[178][25] = {HRIR_48K_24bit::azi_178_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_178_0_ele_25_0_wav};
  irMap[178][30] = {HRIR_48K_24bit::azi_178_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_178_0_ele_30_0_wav};
  irMap[178][45] = {HRIR_48K_24bit::azi_178_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_178_0_ele_45_0_wav};
  irMap[178][54] = {HRIR_48K_24bit::azi_178_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_178_0_ele_54_0_wav};
  irMap[178][60] = {HRIR_48K_24bit::azi_178_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_178_0_ele_60_0_wav};
  irMap[178][75] = {HRIR_48K_24bit::azi_178_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_178_0_ele_75_0_wav};
  irMap[178][90] = {HRIR_48K_24bit::azi_178_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_178_0_ele_90_0_wav};
  irMap[178][-15] = {HRIR_48K_24bit::azi_178_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_178_0_ele_neg15_0_wav};
  irMap[178][-25] = {HRIR_48K_24bit::azi_178_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_178_0_ele_neg25_0_wav};
  irMap[178][-30] = {HRIR_48K_24bit::azi_178_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_178_0_ele_neg30_0_wav};
  irMap[178][-45] = {HRIR_48K_24bit::azi_178_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_178_0_ele_neg45_0_wav};
  irMap[178][-54] = {HRIR_48K_24bit::azi_178_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_178_0_ele_neg54_0_wav};
  irMap[178][-60] = {HRIR_48K_24bit::azi_178_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_178_0_ele_neg60_0_wav};
  irMap[178][-75] = {HRIR_48K_24bit::azi_178_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_178_0_ele_neg75_0_wav};
  irMap[178][-81] = {HRIR_48K_24bit::azi_178_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_178_0_ele_neg81_0_wav};
  irMap[179][0] = {HRIR_48K_24bit::azi_179_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_179_0_ele_0_0_wav};
  irMap[179][15] = {HRIR_48K_24bit::azi_179_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_179_0_ele_15_0_wav};
  irMap[179][25] = {HRIR_48K_24bit::azi_179_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_179_0_ele_25_0_wav};
  irMap[179][30] = {HRIR_48K_24bit::azi_179_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_179_0_ele_30_0_wav};
  irMap[179][45] = {HRIR_48K_24bit::azi_179_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_179_0_ele_45_0_wav};
  irMap[179][54] = {HRIR_48K_24bit::azi_179_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_179_0_ele_54_0_wav};
  irMap[179][60] = {HRIR_48K_24bit::azi_179_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_179_0_ele_60_0_wav};
  irMap[179][75] = {HRIR_48K_24bit::azi_179_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_179_0_ele_75_0_wav};
  irMap[179][90] = {HRIR_48K_24bit::azi_179_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_179_0_ele_90_0_wav};
  irMap[179][-15] = {HRIR_48K_24bit::azi_179_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_179_0_ele_neg15_0_wav};
  irMap[179][-25] = {HRIR_48K_24bit::azi_179_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_179_0_ele_neg25_0_wav};
  irMap[179][-30] = {HRIR_48K_24bit::azi_179_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_179_0_ele_neg30_0_wav};
  irMap[179][-45] = {HRIR_48K_24bit::azi_179_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_179_0_ele_neg45_0_wav};
  irMap[179][-54] = {HRIR_48K_24bit::azi_179_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_179_0_ele_neg54_0_wav};
  irMap[179][-60] = {HRIR_48K_24bit::azi_179_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_179_0_ele_neg60_0_wav};
  irMap[179][-75] = {HRIR_48K_24bit::azi_179_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_179_0_ele_neg75_0_wav};
  irMap[179][-81] = {HRIR_48K_24bit::azi_179_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_179_0_ele_neg81_0_wav};
  irMap[180][0] = {HRIR_48K_24bit::azi_180_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_180_0_ele_0_0_wav};
  irMap[180][15] = {HRIR_48K_24bit::azi_180_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_180_0_ele_15_0_wav};
  irMap[180][25] = {HRIR_48K_24bit::azi_180_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_180_0_ele_25_0_wav};
  irMap[180][30] = {HRIR_48K_24bit::azi_180_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_180_0_ele_30_0_wav};
  irMap[180][45] = {HRIR_48K_24bit::azi_180_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_180_0_ele_45_0_wav};
  irMap[180][54] = {HRIR_48K_24bit::azi_180_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_180_0_ele_54_0_wav};
  irMap[180][60] = {HRIR_48K_24bit::azi_180_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_180_0_ele_60_0_wav};
  irMap[180][75] = {HRIR_48K_24bit::azi_180_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_180_0_ele_75_0_wav};
  irMap[180][90] = {HRIR_48K_24bit::azi_180_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_180_0_ele_90_0_wav};
  irMap[180][-15] = {HRIR_48K_24bit::azi_180_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_180_0_ele_neg15_0_wav};
  irMap[180][-25] = {HRIR_48K_24bit::azi_180_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_180_0_ele_neg25_0_wav};
  irMap[180][-30] = {HRIR_48K_24bit::azi_180_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_180_0_ele_neg30_0_wav};
  irMap[180][-45] = {HRIR_48K_24bit::azi_180_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_180_0_ele_neg45_0_wav};
  irMap[180][-54] = {HRIR_48K_24bit::azi_180_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_180_0_ele_neg54_0_wav};
  irMap[180][-60] = {HRIR_48K_24bit::azi_180_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_180_0_ele_neg60_0_wav};
  irMap[180][-75] = {HRIR_48K_24bit::azi_180_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_180_0_ele_neg75_0_wav};
  irMap[180][-81] = {HRIR_48K_24bit::azi_180_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_180_0_ele_neg81_0_wav};
  irMap[181][0] = {HRIR_48K_24bit::azi_181_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_181_0_ele_0_0_wav};
  irMap[181][15] = {HRIR_48K_24bit::azi_181_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_181_0_ele_15_0_wav};
  irMap[181][25] = {HRIR_48K_24bit::azi_181_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_181_0_ele_25_0_wav};
  irMap[181][30] = {HRIR_48K_24bit::azi_181_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_181_0_ele_30_0_wav};
  irMap[181][45] = {HRIR_48K_24bit::azi_181_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_181_0_ele_45_0_wav};
  irMap[181][54] = {HRIR_48K_24bit::azi_181_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_181_0_ele_54_0_wav};
  irMap[181][60] = {HRIR_48K_24bit::azi_181_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_181_0_ele_60_0_wav};
  irMap[181][75] = {HRIR_48K_24bit::azi_181_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_181_0_ele_75_0_wav};
  irMap[181][90] = {HRIR_48K_24bit::azi_181_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_181_0_ele_90_0_wav};
  irMap[181][-15] = {HRIR_48K_24bit::azi_181_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_181_0_ele_neg15_0_wav};
  irMap[181][-25] = {HRIR_48K_24bit::azi_181_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_181_0_ele_neg25_0_wav};
  irMap[181][-30] = {HRIR_48K_24bit::azi_181_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_181_0_ele_neg30_0_wav};
  irMap[181][-45] = {HRIR_48K_24bit::azi_181_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_181_0_ele_neg45_0_wav};
  irMap[181][-54] = {HRIR_48K_24bit::azi_181_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_181_0_ele_neg54_0_wav};
  irMap[181][-60] = {HRIR_48K_24bit::azi_181_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_181_0_ele_neg60_0_wav};
  irMap[181][-75] = {HRIR_48K_24bit::azi_181_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_181_0_ele_neg75_0_wav};
  irMap[181][-81] = {HRIR_48K_24bit::azi_181_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_181_0_ele_neg81_0_wav};
  irMap[182][0] = {HRIR_48K_24bit::azi_182_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_182_0_ele_0_0_wav};
  irMap[182][15] = {HRIR_48K_24bit::azi_182_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_182_0_ele_15_0_wav};
  irMap[182][25] = {HRIR_48K_24bit::azi_182_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_182_0_ele_25_0_wav};
  irMap[182][30] = {HRIR_48K_24bit::azi_182_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_182_0_ele_30_0_wav};
  irMap[182][45] = {HRIR_48K_24bit::azi_182_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_182_0_ele_45_0_wav};
  irMap[182][54] = {HRIR_48K_24bit::azi_182_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_182_0_ele_54_0_wav};
  irMap[182][60] = {HRIR_48K_24bit::azi_182_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_182_0_ele_60_0_wav};
  irMap[182][75] = {HRIR_48K_24bit::azi_182_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_182_0_ele_75_0_wav};
  irMap[182][90] = {HRIR_48K_24bit::azi_182_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_182_0_ele_90_0_wav};
  irMap[182][-15] = {HRIR_48K_24bit::azi_182_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_182_0_ele_neg15_0_wav};
  irMap[182][-25] = {HRIR_48K_24bit::azi_182_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_182_0_ele_neg25_0_wav};
  irMap[182][-30] = {HRIR_48K_24bit::azi_182_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_182_0_ele_neg30_0_wav};
  irMap[182][-45] = {HRIR_48K_24bit::azi_182_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_182_0_ele_neg45_0_wav};
  irMap[182][-54] = {HRIR_48K_24bit::azi_182_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_182_0_ele_neg54_0_wav};
  irMap[182][-60] = {HRIR_48K_24bit::azi_182_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_182_0_ele_neg60_0_wav};
  irMap[182][-75] = {HRIR_48K_24bit::azi_182_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_182_0_ele_neg75_0_wav};
  irMap[182][-81] = {HRIR_48K_24bit::azi_182_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_182_0_ele_neg81_0_wav};
  irMap[183][0] = {HRIR_48K_24bit::azi_183_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_183_0_ele_0_0_wav};
  irMap[183][15] = {HRIR_48K_24bit::azi_183_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_183_0_ele_15_0_wav};
  irMap[183][25] = {HRIR_48K_24bit::azi_183_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_183_0_ele_25_0_wav};
  irMap[183][30] = {HRIR_48K_24bit::azi_183_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_183_0_ele_30_0_wav};
  irMap[183][45] = {HRIR_48K_24bit::azi_183_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_183_0_ele_45_0_wav};
  irMap[183][54] = {HRIR_48K_24bit::azi_183_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_183_0_ele_54_0_wav};
  irMap[183][60] = {HRIR_48K_24bit::azi_183_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_183_0_ele_60_0_wav};
  irMap[183][75] = {HRIR_48K_24bit::azi_183_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_183_0_ele_75_0_wav};
  irMap[183][90] = {HRIR_48K_24bit::azi_183_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_183_0_ele_90_0_wav};
  irMap[183][-15] = {HRIR_48K_24bit::azi_183_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_183_0_ele_neg15_0_wav};
  irMap[183][-25] = {HRIR_48K_24bit::azi_183_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_183_0_ele_neg25_0_wav};
  irMap[183][-30] = {HRIR_48K_24bit::azi_183_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_183_0_ele_neg30_0_wav};
  irMap[183][-45] = {HRIR_48K_24bit::azi_183_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_183_0_ele_neg45_0_wav};
  irMap[183][-54] = {HRIR_48K_24bit::azi_183_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_183_0_ele_neg54_0_wav};
  irMap[183][-60] = {HRIR_48K_24bit::azi_183_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_183_0_ele_neg60_0_wav};
  irMap[183][-75] = {HRIR_48K_24bit::azi_183_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_183_0_ele_neg75_0_wav};
  irMap[183][-81] = {HRIR_48K_24bit::azi_183_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_183_0_ele_neg81_0_wav};
  irMap[184][0] = {HRIR_48K_24bit::azi_184_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_184_0_ele_0_0_wav};
  irMap[184][15] = {HRIR_48K_24bit::azi_184_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_184_0_ele_15_0_wav};
  irMap[184][25] = {HRIR_48K_24bit::azi_184_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_184_0_ele_25_0_wav};
  irMap[184][30] = {HRIR_48K_24bit::azi_184_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_184_0_ele_30_0_wav};
  irMap[184][45] = {HRIR_48K_24bit::azi_184_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_184_0_ele_45_0_wav};
  irMap[184][54] = {HRIR_48K_24bit::azi_184_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_184_0_ele_54_0_wav};
  irMap[184][60] = {HRIR_48K_24bit::azi_184_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_184_0_ele_60_0_wav};
  irMap[184][75] = {HRIR_48K_24bit::azi_184_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_184_0_ele_75_0_wav};
  irMap[184][90] = {HRIR_48K_24bit::azi_184_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_184_0_ele_90_0_wav};
  irMap[184][-15] = {HRIR_48K_24bit::azi_184_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_184_0_ele_neg15_0_wav};
  irMap[184][-25] = {HRIR_48K_24bit::azi_184_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_184_0_ele_neg25_0_wav};
  irMap[184][-30] = {HRIR_48K_24bit::azi_184_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_184_0_ele_neg30_0_wav};
  irMap[184][-45] = {HRIR_48K_24bit::azi_184_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_184_0_ele_neg45_0_wav};
  irMap[184][-54] = {HRIR_48K_24bit::azi_184_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_184_0_ele_neg54_0_wav};
  irMap[184][-60] = {HRIR_48K_24bit::azi_184_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_184_0_ele_neg60_0_wav};
  irMap[184][-75] = {HRIR_48K_24bit::azi_184_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_184_0_ele_neg75_0_wav};
  irMap[184][-81] = {HRIR_48K_24bit::azi_184_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_184_0_ele_neg81_0_wav};
  irMap[185][0] = {HRIR_48K_24bit::azi_185_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_185_0_ele_0_0_wav};
  irMap[185][15] = {HRIR_48K_24bit::azi_185_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_185_0_ele_15_0_wav};
  irMap[185][25] = {HRIR_48K_24bit::azi_185_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_185_0_ele_25_0_wav};
  irMap[185][30] = {HRIR_48K_24bit::azi_185_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_185_0_ele_30_0_wav};
  irMap[185][45] = {HRIR_48K_24bit::azi_185_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_185_0_ele_45_0_wav};
  irMap[185][54] = {HRIR_48K_24bit::azi_185_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_185_0_ele_54_0_wav};
  irMap[185][60] = {HRIR_48K_24bit::azi_185_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_185_0_ele_60_0_wav};
  irMap[185][75] = {HRIR_48K_24bit::azi_185_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_185_0_ele_75_0_wav};
  irMap[185][90] = {HRIR_48K_24bit::azi_185_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_185_0_ele_90_0_wav};
  irMap[185][-15] = {HRIR_48K_24bit::azi_185_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_185_0_ele_neg15_0_wav};
  irMap[185][-25] = {HRIR_48K_24bit::azi_185_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_185_0_ele_neg25_0_wav};
  irMap[185][-30] = {HRIR_48K_24bit::azi_185_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_185_0_ele_neg30_0_wav};
  irMap[185][-45] = {HRIR_48K_24bit::azi_185_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_185_0_ele_neg45_0_wav};
  irMap[185][-54] = {HRIR_48K_24bit::azi_185_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_185_0_ele_neg54_0_wav};
  irMap[185][-60] = {HRIR_48K_24bit::azi_185_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_185_0_ele_neg60_0_wav};
  irMap[185][-75] = {HRIR_48K_24bit::azi_185_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_185_0_ele_neg75_0_wav};
  irMap[185][-81] = {HRIR_48K_24bit::azi_185_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_185_0_ele_neg81_0_wav};
  irMap[186][0] = {HRIR_48K_24bit::azi_186_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_186_0_ele_0_0_wav};
  irMap[186][15] = {HRIR_48K_24bit::azi_186_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_186_0_ele_15_0_wav};
  irMap[186][25] = {HRIR_48K_24bit::azi_186_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_186_0_ele_25_0_wav};
  irMap[186][30] = {HRIR_48K_24bit::azi_186_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_186_0_ele_30_0_wav};
  irMap[186][45] = {HRIR_48K_24bit::azi_186_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_186_0_ele_45_0_wav};
  irMap[186][54] = {HRIR_48K_24bit::azi_186_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_186_0_ele_54_0_wav};
  irMap[186][60] = {HRIR_48K_24bit::azi_186_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_186_0_ele_60_0_wav};
  irMap[186][75] = {HRIR_48K_24bit::azi_186_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_186_0_ele_75_0_wav};
  irMap[186][90] = {HRIR_48K_24bit::azi_186_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_186_0_ele_90_0_wav};
  irMap[186][-15] = {HRIR_48K_24bit::azi_186_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_186_0_ele_neg15_0_wav};
  irMap[186][-25] = {HRIR_48K_24bit::azi_186_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_186_0_ele_neg25_0_wav};
  irMap[186][-30] = {HRIR_48K_24bit::azi_186_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_186_0_ele_neg30_0_wav};
  irMap[186][-45] = {HRIR_48K_24bit::azi_186_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_186_0_ele_neg45_0_wav};
  irMap[186][-54] = {HRIR_48K_24bit::azi_186_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_186_0_ele_neg54_0_wav};
  irMap[186][-60] = {HRIR_48K_24bit::azi_186_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_186_0_ele_neg60_0_wav};
  irMap[186][-75] = {HRIR_48K_24bit::azi_186_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_186_0_ele_neg75_0_wav};
  irMap[186][-81] = {HRIR_48K_24bit::azi_186_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_186_0_ele_neg81_0_wav};
  irMap[187][0] = {HRIR_48K_24bit::azi_187_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_187_0_ele_0_0_wav};
  irMap[187][15] = {HRIR_48K_24bit::azi_187_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_187_0_ele_15_0_wav};
  irMap[187][25] = {HRIR_48K_24bit::azi_187_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_187_0_ele_25_0_wav};
  irMap[187][30] = {HRIR_48K_24bit::azi_187_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_187_0_ele_30_0_wav};
  irMap[187][45] = {HRIR_48K_24bit::azi_187_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_187_0_ele_45_0_wav};
  irMap[187][54] = {HRIR_48K_24bit::azi_187_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_187_0_ele_54_0_wav};
  irMap[187][60] = {HRIR_48K_24bit::azi_187_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_187_0_ele_60_0_wav};
  irMap[187][75] = {HRIR_48K_24bit::azi_187_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_187_0_ele_75_0_wav};
  irMap[187][90] = {HRIR_48K_24bit::azi_187_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_187_0_ele_90_0_wav};
  irMap[187][-15] = {HRIR_48K_24bit::azi_187_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_187_0_ele_neg15_0_wav};
  irMap[187][-25] = {HRIR_48K_24bit::azi_187_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_187_0_ele_neg25_0_wav};
  irMap[187][-30] = {HRIR_48K_24bit::azi_187_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_187_0_ele_neg30_0_wav};
  irMap[187][-45] = {HRIR_48K_24bit::azi_187_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_187_0_ele_neg45_0_wav};
  irMap[187][-54] = {HRIR_48K_24bit::azi_187_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_187_0_ele_neg54_0_wav};
  irMap[187][-60] = {HRIR_48K_24bit::azi_187_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_187_0_ele_neg60_0_wav};
  irMap[187][-75] = {HRIR_48K_24bit::azi_187_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_187_0_ele_neg75_0_wav};
  irMap[187][-81] = {HRIR_48K_24bit::azi_187_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_187_0_ele_neg81_0_wav};
  irMap[188][0] = {HRIR_48K_24bit::azi_188_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_188_0_ele_0_0_wav};
  irMap[188][15] = {HRIR_48K_24bit::azi_188_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_188_0_ele_15_0_wav};
  irMap[188][25] = {HRIR_48K_24bit::azi_188_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_188_0_ele_25_0_wav};
  irMap[188][30] = {HRIR_48K_24bit::azi_188_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_188_0_ele_30_0_wav};
  irMap[188][45] = {HRIR_48K_24bit::azi_188_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_188_0_ele_45_0_wav};
  irMap[188][54] = {HRIR_48K_24bit::azi_188_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_188_0_ele_54_0_wav};
  irMap[188][60] = {HRIR_48K_24bit::azi_188_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_188_0_ele_60_0_wav};
  irMap[188][75] = {HRIR_48K_24bit::azi_188_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_188_0_ele_75_0_wav};
  irMap[188][90] = {HRIR_48K_24bit::azi_188_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_188_0_ele_90_0_wav};
  irMap[188][-15] = {HRIR_48K_24bit::azi_188_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_188_0_ele_neg15_0_wav};
  irMap[188][-25] = {HRIR_48K_24bit::azi_188_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_188_0_ele_neg25_0_wav};
  irMap[188][-30] = {HRIR_48K_24bit::azi_188_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_188_0_ele_neg30_0_wav};
  irMap[188][-45] = {HRIR_48K_24bit::azi_188_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_188_0_ele_neg45_0_wav};
  irMap[188][-54] = {HRIR_48K_24bit::azi_188_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_188_0_ele_neg54_0_wav};
  irMap[188][-60] = {HRIR_48K_24bit::azi_188_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_188_0_ele_neg60_0_wav};
  irMap[188][-75] = {HRIR_48K_24bit::azi_188_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_188_0_ele_neg75_0_wav};
  irMap[188][-81] = {HRIR_48K_24bit::azi_188_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_188_0_ele_neg81_0_wav};
  irMap[189][0] = {HRIR_48K_24bit::azi_189_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_189_0_ele_0_0_wav};
  irMap[189][15] = {HRIR_48K_24bit::azi_189_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_189_0_ele_15_0_wav};
  irMap[189][25] = {HRIR_48K_24bit::azi_189_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_189_0_ele_25_0_wav};
  irMap[189][30] = {HRIR_48K_24bit::azi_189_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_189_0_ele_30_0_wav};
  irMap[189][45] = {HRIR_48K_24bit::azi_189_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_189_0_ele_45_0_wav};
  irMap[189][54] = {HRIR_48K_24bit::azi_189_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_189_0_ele_54_0_wav};
  irMap[189][60] = {HRIR_48K_24bit::azi_189_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_189_0_ele_60_0_wav};
  irMap[189][75] = {HRIR_48K_24bit::azi_189_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_189_0_ele_75_0_wav};
  irMap[189][90] = {HRIR_48K_24bit::azi_189_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_189_0_ele_90_0_wav};
  irMap[189][-15] = {HRIR_48K_24bit::azi_189_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_189_0_ele_neg15_0_wav};
  irMap[189][-25] = {HRIR_48K_24bit::azi_189_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_189_0_ele_neg25_0_wav};
  irMap[189][-30] = {HRIR_48K_24bit::azi_189_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_189_0_ele_neg30_0_wav};
  irMap[189][-45] = {HRIR_48K_24bit::azi_189_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_189_0_ele_neg45_0_wav};
  irMap[189][-54] = {HRIR_48K_24bit::azi_189_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_189_0_ele_neg54_0_wav};
  irMap[189][-60] = {HRIR_48K_24bit::azi_189_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_189_0_ele_neg60_0_wav};
  irMap[189][-75] = {HRIR_48K_24bit::azi_189_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_189_0_ele_neg75_0_wav};
  irMap[189][-81] = {HRIR_48K_24bit::azi_189_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_189_0_ele_neg81_0_wav};
  irMap[190][0] = {HRIR_48K_24bit::azi_190_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_190_0_ele_0_0_wav};
  irMap[190][15] = {HRIR_48K_24bit::azi_190_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_190_0_ele_15_0_wav};
  irMap[190][25] = {HRIR_48K_24bit::azi_190_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_190_0_ele_25_0_wav};
  irMap[190][30] = {HRIR_48K_24bit::azi_190_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_190_0_ele_30_0_wav};
  irMap[190][45] = {HRIR_48K_24bit::azi_190_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_190_0_ele_45_0_wav};
  irMap[190][54] = {HRIR_48K_24bit::azi_190_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_190_0_ele_54_0_wav};
  irMap[190][60] = {HRIR_48K_24bit::azi_190_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_190_0_ele_60_0_wav};
  irMap[190][75] = {HRIR_48K_24bit::azi_190_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_190_0_ele_75_0_wav};
  irMap[190][90] = {HRIR_48K_24bit::azi_190_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_190_0_ele_90_0_wav};
  irMap[190][-15] = {HRIR_48K_24bit::azi_190_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_190_0_ele_neg15_0_wav};
  irMap[190][-25] = {HRIR_48K_24bit::azi_190_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_190_0_ele_neg25_0_wav};
  irMap[190][-30] = {HRIR_48K_24bit::azi_190_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_190_0_ele_neg30_0_wav};
  irMap[190][-45] = {HRIR_48K_24bit::azi_190_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_190_0_ele_neg45_0_wav};
  irMap[190][-54] = {HRIR_48K_24bit::azi_190_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_190_0_ele_neg54_0_wav};
  irMap[190][-60] = {HRIR_48K_24bit::azi_190_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_190_0_ele_neg60_0_wav};
  irMap[190][-75] = {HRIR_48K_24bit::azi_190_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_190_0_ele_neg75_0_wav};
  irMap[190][-81] = {HRIR_48K_24bit::azi_190_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_190_0_ele_neg81_0_wav};
  irMap[191][0] = {HRIR_48K_24bit::azi_191_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_191_0_ele_0_0_wav};
  irMap[191][15] = {HRIR_48K_24bit::azi_191_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_191_0_ele_15_0_wav};
  irMap[191][25] = {HRIR_48K_24bit::azi_191_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_191_0_ele_25_0_wav};
  irMap[191][30] = {HRIR_48K_24bit::azi_191_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_191_0_ele_30_0_wav};
  irMap[191][45] = {HRIR_48K_24bit::azi_191_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_191_0_ele_45_0_wav};
  irMap[191][54] = {HRIR_48K_24bit::azi_191_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_191_0_ele_54_0_wav};
  irMap[191][60] = {HRIR_48K_24bit::azi_191_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_191_0_ele_60_0_wav};
  irMap[191][75] = {HRIR_48K_24bit::azi_191_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_191_0_ele_75_0_wav};
  irMap[191][90] = {HRIR_48K_24bit::azi_191_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_191_0_ele_90_0_wav};
  irMap[191][-15] = {HRIR_48K_24bit::azi_191_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_191_0_ele_neg15_0_wav};
  irMap[191][-25] = {HRIR_48K_24bit::azi_191_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_191_0_ele_neg25_0_wav};
  irMap[191][-30] = {HRIR_48K_24bit::azi_191_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_191_0_ele_neg30_0_wav};
  irMap[191][-45] = {HRIR_48K_24bit::azi_191_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_191_0_ele_neg45_0_wav};
  irMap[191][-54] = {HRIR_48K_24bit::azi_191_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_191_0_ele_neg54_0_wav};
  irMap[191][-60] = {HRIR_48K_24bit::azi_191_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_191_0_ele_neg60_0_wav};
  irMap[191][-75] = {HRIR_48K_24bit::azi_191_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_191_0_ele_neg75_0_wav};
  irMap[191][-81] = {HRIR_48K_24bit::azi_191_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_191_0_ele_neg81_0_wav};
  irMap[192][0] = {HRIR_48K_24bit::azi_192_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_192_0_ele_0_0_wav};
  irMap[192][15] = {HRIR_48K_24bit::azi_192_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_192_0_ele_15_0_wav};
  irMap[192][25] = {HRIR_48K_24bit::azi_192_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_192_0_ele_25_0_wav};
  irMap[192][30] = {HRIR_48K_24bit::azi_192_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_192_0_ele_30_0_wav};
  irMap[192][45] = {HRIR_48K_24bit::azi_192_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_192_0_ele_45_0_wav};
  irMap[192][54] = {HRIR_48K_24bit::azi_192_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_192_0_ele_54_0_wav};
  irMap[192][60] = {HRIR_48K_24bit::azi_192_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_192_0_ele_60_0_wav};
  irMap[192][75] = {HRIR_48K_24bit::azi_192_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_192_0_ele_75_0_wav};
  irMap[192][90] = {HRIR_48K_24bit::azi_192_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_192_0_ele_90_0_wav};
  irMap[192][-15] = {HRIR_48K_24bit::azi_192_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_192_0_ele_neg15_0_wav};
  irMap[192][-25] = {HRIR_48K_24bit::azi_192_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_192_0_ele_neg25_0_wav};
  irMap[192][-30] = {HRIR_48K_24bit::azi_192_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_192_0_ele_neg30_0_wav};
  irMap[192][-45] = {HRIR_48K_24bit::azi_192_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_192_0_ele_neg45_0_wav};
  irMap[192][-54] = {HRIR_48K_24bit::azi_192_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_192_0_ele_neg54_0_wav};
  irMap[192][-60] = {HRIR_48K_24bit::azi_192_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_192_0_ele_neg60_0_wav};
  irMap[192][-75] = {HRIR_48K_24bit::azi_192_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_192_0_ele_neg75_0_wav};
  irMap[192][-81] = {HRIR_48K_24bit::azi_192_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_192_0_ele_neg81_0_wav};
  irMap[193][0] = {HRIR_48K_24bit::azi_193_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_193_0_ele_0_0_wav};
  irMap[193][15] = {HRIR_48K_24bit::azi_193_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_193_0_ele_15_0_wav};
  irMap[193][25] = {HRIR_48K_24bit::azi_193_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_193_0_ele_25_0_wav};
  irMap[193][30] = {HRIR_48K_24bit::azi_193_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_193_0_ele_30_0_wav};
  irMap[193][45] = {HRIR_48K_24bit::azi_193_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_193_0_ele_45_0_wav};
  irMap[193][54] = {HRIR_48K_24bit::azi_193_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_193_0_ele_54_0_wav};
  irMap[193][60] = {HRIR_48K_24bit::azi_193_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_193_0_ele_60_0_wav};
  irMap[193][75] = {HRIR_48K_24bit::azi_193_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_193_0_ele_75_0_wav};
  irMap[193][90] = {HRIR_48K_24bit::azi_193_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_193_0_ele_90_0_wav};
  irMap[193][-15] = {HRIR_48K_24bit::azi_193_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_193_0_ele_neg15_0_wav};
  irMap[193][-25] = {HRIR_48K_24bit::azi_193_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_193_0_ele_neg25_0_wav};
  irMap[193][-30] = {HRIR_48K_24bit::azi_193_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_193_0_ele_neg30_0_wav};
  irMap[193][-45] = {HRIR_48K_24bit::azi_193_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_193_0_ele_neg45_0_wav};
  irMap[193][-54] = {HRIR_48K_24bit::azi_193_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_193_0_ele_neg54_0_wav};
  irMap[193][-60] = {HRIR_48K_24bit::azi_193_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_193_0_ele_neg60_0_wav};
  irMap[193][-75] = {HRIR_48K_24bit::azi_193_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_193_0_ele_neg75_0_wav};
  irMap[193][-81] = {HRIR_48K_24bit::azi_193_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_193_0_ele_neg81_0_wav};
  irMap[194][0] = {HRIR_48K_24bit::azi_194_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_194_0_ele_0_0_wav};
  irMap[194][15] = {HRIR_48K_24bit::azi_194_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_194_0_ele_15_0_wav};
  irMap[194][25] = {HRIR_48K_24bit::azi_194_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_194_0_ele_25_0_wav};
  irMap[194][30] = {HRIR_48K_24bit::azi_194_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_194_0_ele_30_0_wav};
  irMap[194][45] = {HRIR_48K_24bit::azi_194_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_194_0_ele_45_0_wav};
  irMap[194][54] = {HRIR_48K_24bit::azi_194_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_194_0_ele_54_0_wav};
  irMap[194][60] = {HRIR_48K_24bit::azi_194_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_194_0_ele_60_0_wav};
  irMap[194][75] = {HRIR_48K_24bit::azi_194_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_194_0_ele_75_0_wav};
  irMap[194][90] = {HRIR_48K_24bit::azi_194_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_194_0_ele_90_0_wav};
  irMap[194][-15] = {HRIR_48K_24bit::azi_194_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_194_0_ele_neg15_0_wav};
  irMap[194][-25] = {HRIR_48K_24bit::azi_194_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_194_0_ele_neg25_0_wav};
  irMap[194][-30] = {HRIR_48K_24bit::azi_194_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_194_0_ele_neg30_0_wav};
  irMap[194][-45] = {HRIR_48K_24bit::azi_194_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_194_0_ele_neg45_0_wav};
  irMap[194][-54] = {HRIR_48K_24bit::azi_194_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_194_0_ele_neg54_0_wav};
  irMap[194][-60] = {HRIR_48K_24bit::azi_194_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_194_0_ele_neg60_0_wav};
  irMap[194][-75] = {HRIR_48K_24bit::azi_194_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_194_0_ele_neg75_0_wav};
  irMap[194][-81] = {HRIR_48K_24bit::azi_194_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_194_0_ele_neg81_0_wav};
  irMap[195][0] = {HRIR_48K_24bit::azi_195_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_195_0_ele_0_0_wav};
  irMap[195][15] = {HRIR_48K_24bit::azi_195_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_195_0_ele_15_0_wav};
  irMap[195][25] = {HRIR_48K_24bit::azi_195_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_195_0_ele_25_0_wav};
  irMap[195][30] = {HRIR_48K_24bit::azi_195_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_195_0_ele_30_0_wav};
  irMap[195][45] = {HRIR_48K_24bit::azi_195_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_195_0_ele_45_0_wav};
  irMap[195][54] = {HRIR_48K_24bit::azi_195_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_195_0_ele_54_0_wav};
  irMap[195][60] = {HRIR_48K_24bit::azi_195_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_195_0_ele_60_0_wav};
  irMap[195][75] = {HRIR_48K_24bit::azi_195_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_195_0_ele_75_0_wav};
  irMap[195][90] = {HRIR_48K_24bit::azi_195_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_195_0_ele_90_0_wav};
  irMap[195][-15] = {HRIR_48K_24bit::azi_195_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_195_0_ele_neg15_0_wav};
  irMap[195][-25] = {HRIR_48K_24bit::azi_195_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_195_0_ele_neg25_0_wav};
  irMap[195][-30] = {HRIR_48K_24bit::azi_195_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_195_0_ele_neg30_0_wav};
  irMap[195][-45] = {HRIR_48K_24bit::azi_195_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_195_0_ele_neg45_0_wav};
  irMap[195][-54] = {HRIR_48K_24bit::azi_195_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_195_0_ele_neg54_0_wav};
  irMap[195][-60] = {HRIR_48K_24bit::azi_195_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_195_0_ele_neg60_0_wav};
  irMap[195][-75] = {HRIR_48K_24bit::azi_195_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_195_0_ele_neg75_0_wav};
  irMap[195][-81] = {HRIR_48K_24bit::azi_195_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_195_0_ele_neg81_0_wav};
  irMap[196][0] = {HRIR_48K_24bit::azi_196_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_196_0_ele_0_0_wav};
  irMap[196][15] = {HRIR_48K_24bit::azi_196_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_196_0_ele_15_0_wav};
  irMap[196][25] = {HRIR_48K_24bit::azi_196_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_196_0_ele_25_0_wav};
  irMap[196][30] = {HRIR_48K_24bit::azi_196_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_196_0_ele_30_0_wav};
  irMap[196][45] = {HRIR_48K_24bit::azi_196_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_196_0_ele_45_0_wav};
  irMap[196][54] = {HRIR_48K_24bit::azi_196_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_196_0_ele_54_0_wav};
  irMap[196][60] = {HRIR_48K_24bit::azi_196_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_196_0_ele_60_0_wav};
  irMap[196][75] = {HRIR_48K_24bit::azi_196_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_196_0_ele_75_0_wav};
  irMap[196][90] = {HRIR_48K_24bit::azi_196_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_196_0_ele_90_0_wav};
  irMap[196][-15] = {HRIR_48K_24bit::azi_196_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_196_0_ele_neg15_0_wav};
  irMap[196][-25] = {HRIR_48K_24bit::azi_196_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_196_0_ele_neg25_0_wav};
  irMap[196][-30] = {HRIR_48K_24bit::azi_196_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_196_0_ele_neg30_0_wav};
  irMap[196][-45] = {HRIR_48K_24bit::azi_196_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_196_0_ele_neg45_0_wav};
  irMap[196][-54] = {HRIR_48K_24bit::azi_196_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_196_0_ele_neg54_0_wav};
  irMap[196][-60] = {HRIR_48K_24bit::azi_196_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_196_0_ele_neg60_0_wav};
  irMap[196][-75] = {HRIR_48K_24bit::azi_196_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_196_0_ele_neg75_0_wav};
  irMap[196][-81] = {HRIR_48K_24bit::azi_196_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_196_0_ele_neg81_0_wav};
  irMap[197][0] = {HRIR_48K_24bit::azi_197_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_197_0_ele_0_0_wav};
  irMap[197][15] = {HRIR_48K_24bit::azi_197_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_197_0_ele_15_0_wav};
  irMap[197][25] = {HRIR_48K_24bit::azi_197_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_197_0_ele_25_0_wav};
  irMap[197][30] = {HRIR_48K_24bit::azi_197_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_197_0_ele_30_0_wav};
  irMap[197][45] = {HRIR_48K_24bit::azi_197_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_197_0_ele_45_0_wav};
  irMap[197][54] = {HRIR_48K_24bit::azi_197_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_197_0_ele_54_0_wav};
  irMap[197][60] = {HRIR_48K_24bit::azi_197_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_197_0_ele_60_0_wav};
  irMap[197][75] = {HRIR_48K_24bit::azi_197_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_197_0_ele_75_0_wav};
  irMap[197][90] = {HRIR_48K_24bit::azi_197_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_197_0_ele_90_0_wav};
  irMap[197][-15] = {HRIR_48K_24bit::azi_197_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_197_0_ele_neg15_0_wav};
  irMap[197][-25] = {HRIR_48K_24bit::azi_197_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_197_0_ele_neg25_0_wav};
  irMap[197][-30] = {HRIR_48K_24bit::azi_197_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_197_0_ele_neg30_0_wav};
  irMap[197][-45] = {HRIR_48K_24bit::azi_197_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_197_0_ele_neg45_0_wav};
  irMap[197][-54] = {HRIR_48K_24bit::azi_197_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_197_0_ele_neg54_0_wav};
  irMap[197][-60] = {HRIR_48K_24bit::azi_197_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_197_0_ele_neg60_0_wav};
  irMap[197][-75] = {HRIR_48K_24bit::azi_197_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_197_0_ele_neg75_0_wav};
  irMap[197][-81] = {HRIR_48K_24bit::azi_197_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_197_0_ele_neg81_0_wav};
  irMap[198][0] = {HRIR_48K_24bit::azi_198_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_198_0_ele_0_0_wav};
  irMap[198][15] = {HRIR_48K_24bit::azi_198_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_198_0_ele_15_0_wav};
  irMap[198][25] = {HRIR_48K_24bit::azi_198_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_198_0_ele_25_0_wav};
  irMap[198][30] = {HRIR_48K_24bit::azi_198_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_198_0_ele_30_0_wav};
  irMap[198][45] = {HRIR_48K_24bit::azi_198_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_198_0_ele_45_0_wav};
  irMap[198][54] = {HRIR_48K_24bit::azi_198_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_198_0_ele_54_0_wav};
  irMap[198][60] = {HRIR_48K_24bit::azi_198_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_198_0_ele_60_0_wav};
  irMap[198][75] = {HRIR_48K_24bit::azi_198_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_198_0_ele_75_0_wav};
  irMap[198][90] = {HRIR_48K_24bit::azi_198_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_198_0_ele_90_0_wav};
  irMap[198][-15] = {HRIR_48K_24bit::azi_198_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_198_0_ele_neg15_0_wav};
  irMap[198][-25] = {HRIR_48K_24bit::azi_198_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_198_0_ele_neg25_0_wav};
  irMap[198][-30] = {HRIR_48K_24bit::azi_198_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_198_0_ele_neg30_0_wav};
  irMap[198][-45] = {HRIR_48K_24bit::azi_198_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_198_0_ele_neg45_0_wav};
  irMap[198][-54] = {HRIR_48K_24bit::azi_198_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_198_0_ele_neg54_0_wav};
  irMap[198][-60] = {HRIR_48K_24bit::azi_198_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_198_0_ele_neg60_0_wav};
  irMap[198][-75] = {HRIR_48K_24bit::azi_198_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_198_0_ele_neg75_0_wav};
  irMap[198][-81] = {HRIR_48K_24bit::azi_198_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_198_0_ele_neg81_0_wav};
  irMap[199][0] = {HRIR_48K_24bit::azi_199_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_199_0_ele_0_0_wav};
  irMap[199][15] = {HRIR_48K_24bit::azi_199_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_199_0_ele_15_0_wav};
  irMap[199][25] = {HRIR_48K_24bit::azi_199_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_199_0_ele_25_0_wav};
  irMap[199][30] = {HRIR_48K_24bit::azi_199_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_199_0_ele_30_0_wav};
  irMap[199][45] = {HRIR_48K_24bit::azi_199_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_199_0_ele_45_0_wav};
  irMap[199][54] = {HRIR_48K_24bit::azi_199_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_199_0_ele_54_0_wav};
  irMap[199][60] = {HRIR_48K_24bit::azi_199_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_199_0_ele_60_0_wav};
  irMap[199][75] = {HRIR_48K_24bit::azi_199_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_199_0_ele_75_0_wav};
  irMap[199][90] = {HRIR_48K_24bit::azi_199_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_199_0_ele_90_0_wav};
  irMap[199][-15] = {HRIR_48K_24bit::azi_199_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_199_0_ele_neg15_0_wav};
  irMap[199][-25] = {HRIR_48K_24bit::azi_199_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_199_0_ele_neg25_0_wav};
  irMap[199][-30] = {HRIR_48K_24bit::azi_199_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_199_0_ele_neg30_0_wav};
  irMap[199][-45] = {HRIR_48K_24bit::azi_199_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_199_0_ele_neg45_0_wav};
  irMap[199][-54] = {HRIR_48K_24bit::azi_199_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_199_0_ele_neg54_0_wav};
  irMap[199][-60] = {HRIR_48K_24bit::azi_199_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_199_0_ele_neg60_0_wav};
  irMap[199][-75] = {HRIR_48K_24bit::azi_199_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_199_0_ele_neg75_0_wav};
  irMap[199][-81] = {HRIR_48K_24bit::azi_199_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_199_0_ele_neg81_0_wav};
  irMap[200][0] = {HRIR_48K_24bit::azi_200_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_200_0_ele_0_0_wav};
  irMap[200][15] = {HRIR_48K_24bit::azi_200_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_200_0_ele_15_0_wav};
  irMap[200][25] = {HRIR_48K_24bit::azi_200_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_200_0_ele_25_0_wav};
  irMap[200][30] = {HRIR_48K_24bit::azi_200_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_200_0_ele_30_0_wav};
  irMap[200][45] = {HRIR_48K_24bit::azi_200_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_200_0_ele_45_0_wav};
  irMap[200][54] = {HRIR_48K_24bit::azi_200_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_200_0_ele_54_0_wav};
  irMap[200][60] = {HRIR_48K_24bit::azi_200_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_200_0_ele_60_0_wav};
  irMap[200][75] = {HRIR_48K_24bit::azi_200_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_200_0_ele_75_0_wav};
  irMap[200][90] = {HRIR_48K_24bit::azi_200_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_200_0_ele_90_0_wav};
  irMap[200][-15] = {HRIR_48K_24bit::azi_200_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_200_0_ele_neg15_0_wav};
  irMap[200][-25] = {HRIR_48K_24bit::azi_200_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_200_0_ele_neg25_0_wav};
  irMap[200][-30] = {HRIR_48K_24bit::azi_200_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_200_0_ele_neg30_0_wav};
  irMap[200][-45] = {HRIR_48K_24bit::azi_200_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_200_0_ele_neg45_0_wav};
  irMap[200][-54] = {HRIR_48K_24bit::azi_200_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_200_0_ele_neg54_0_wav};
  irMap[200][-60] = {HRIR_48K_24bit::azi_200_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_200_0_ele_neg60_0_wav};
  irMap[200][-75] = {HRIR_48K_24bit::azi_200_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_200_0_ele_neg75_0_wav};
  irMap[200][-81] = {HRIR_48K_24bit::azi_200_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_200_0_ele_neg81_0_wav};
  irMap[201][0] = {HRIR_48K_24bit::azi_201_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_201_0_ele_0_0_wav};
  irMap[201][15] = {HRIR_48K_24bit::azi_201_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_201_0_ele_15_0_wav};
  irMap[201][25] = {HRIR_48K_24bit::azi_201_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_201_0_ele_25_0_wav};
  irMap[201][30] = {HRIR_48K_24bit::azi_201_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_201_0_ele_30_0_wav};
  irMap[201][45] = {HRIR_48K_24bit::azi_201_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_201_0_ele_45_0_wav};
  irMap[201][54] = {HRIR_48K_24bit::azi_201_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_201_0_ele_54_0_wav};
  irMap[201][60] = {HRIR_48K_24bit::azi_201_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_201_0_ele_60_0_wav};
  irMap[201][75] = {HRIR_48K_24bit::azi_201_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_201_0_ele_75_0_wav};
  irMap[201][90] = {HRIR_48K_24bit::azi_201_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_201_0_ele_90_0_wav};
  irMap[201][-15] = {HRIR_48K_24bit::azi_201_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_201_0_ele_neg15_0_wav};
  irMap[201][-25] = {HRIR_48K_24bit::azi_201_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_201_0_ele_neg25_0_wav};
  irMap[201][-30] = {HRIR_48K_24bit::azi_201_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_201_0_ele_neg30_0_wav};
  irMap[201][-45] = {HRIR_48K_24bit::azi_201_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_201_0_ele_neg45_0_wav};
  irMap[201][-54] = {HRIR_48K_24bit::azi_201_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_201_0_ele_neg54_0_wav};
  irMap[201][-60] = {HRIR_48K_24bit::azi_201_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_201_0_ele_neg60_0_wav};
  irMap[201][-75] = {HRIR_48K_24bit::azi_201_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_201_0_ele_neg75_0_wav};
  irMap[201][-81] = {HRIR_48K_24bit::azi_201_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_201_0_ele_neg81_0_wav};
  irMap[202][0] = {HRIR_48K_24bit::azi_202_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_202_0_ele_0_0_wav};
  irMap[202][15] = {HRIR_48K_24bit::azi_202_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_202_0_ele_15_0_wav};
  irMap[202][25] = {HRIR_48K_24bit::azi_202_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_202_0_ele_25_0_wav};
  irMap[202][30] = {HRIR_48K_24bit::azi_202_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_202_0_ele_30_0_wav};
  irMap[202][45] = {HRIR_48K_24bit::azi_202_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_202_0_ele_45_0_wav};
  irMap[202][54] = {HRIR_48K_24bit::azi_202_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_202_0_ele_54_0_wav};
  irMap[202][60] = {HRIR_48K_24bit::azi_202_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_202_0_ele_60_0_wav};
  irMap[202][75] = {HRIR_48K_24bit::azi_202_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_202_0_ele_75_0_wav};
  irMap[202][90] = {HRIR_48K_24bit::azi_202_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_202_0_ele_90_0_wav};
  irMap[202][-15] = {HRIR_48K_24bit::azi_202_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_202_0_ele_neg15_0_wav};
  irMap[202][-25] = {HRIR_48K_24bit::azi_202_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_202_0_ele_neg25_0_wav};
  irMap[202][-30] = {HRIR_48K_24bit::azi_202_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_202_0_ele_neg30_0_wav};
  irMap[202][-45] = {HRIR_48K_24bit::azi_202_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_202_0_ele_neg45_0_wav};
  irMap[202][-54] = {HRIR_48K_24bit::azi_202_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_202_0_ele_neg54_0_wav};
  irMap[202][-60] = {HRIR_48K_24bit::azi_202_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_202_0_ele_neg60_0_wav};
  irMap[202][-75] = {HRIR_48K_24bit::azi_202_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_202_0_ele_neg75_0_wav};
  irMap[202][-81] = {HRIR_48K_24bit::azi_202_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_202_0_ele_neg81_0_wav};
  irMap[203][0] = {HRIR_48K_24bit::azi_203_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_203_0_ele_0_0_wav};
  irMap[203][15] = {HRIR_48K_24bit::azi_203_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_203_0_ele_15_0_wav};
  irMap[203][25] = {HRIR_48K_24bit::azi_203_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_203_0_ele_25_0_wav};
  irMap[203][30] = {HRIR_48K_24bit::azi_203_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_203_0_ele_30_0_wav};
  irMap[203][45] = {HRIR_48K_24bit::azi_203_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_203_0_ele_45_0_wav};
  irMap[203][54] = {HRIR_48K_24bit::azi_203_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_203_0_ele_54_0_wav};
  irMap[203][60] = {HRIR_48K_24bit::azi_203_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_203_0_ele_60_0_wav};
  irMap[203][75] = {HRIR_48K_24bit::azi_203_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_203_0_ele_75_0_wav};
  irMap[203][90] = {HRIR_48K_24bit::azi_203_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_203_0_ele_90_0_wav};
  irMap[203][-15] = {HRIR_48K_24bit::azi_203_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_203_0_ele_neg15_0_wav};
  irMap[203][-25] = {HRIR_48K_24bit::azi_203_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_203_0_ele_neg25_0_wav};
  irMap[203][-30] = {HRIR_48K_24bit::azi_203_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_203_0_ele_neg30_0_wav};
  irMap[203][-45] = {HRIR_48K_24bit::azi_203_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_203_0_ele_neg45_0_wav};
  irMap[203][-54] = {HRIR_48K_24bit::azi_203_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_203_0_ele_neg54_0_wav};
  irMap[203][-60] = {HRIR_48K_24bit::azi_203_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_203_0_ele_neg60_0_wav};
  irMap[203][-75] = {HRIR_48K_24bit::azi_203_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_203_0_ele_neg75_0_wav};
  irMap[203][-81] = {HRIR_48K_24bit::azi_203_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_203_0_ele_neg81_0_wav};
  irMap[204][0] = {HRIR_48K_24bit::azi_204_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_204_0_ele_0_0_wav};
  irMap[204][15] = {HRIR_48K_24bit::azi_204_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_204_0_ele_15_0_wav};
  irMap[204][25] = {HRIR_48K_24bit::azi_204_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_204_0_ele_25_0_wav};
  irMap[204][30] = {HRIR_48K_24bit::azi_204_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_204_0_ele_30_0_wav};
  irMap[204][45] = {HRIR_48K_24bit::azi_204_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_204_0_ele_45_0_wav};
  irMap[204][54] = {HRIR_48K_24bit::azi_204_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_204_0_ele_54_0_wav};
  irMap[204][60] = {HRIR_48K_24bit::azi_204_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_204_0_ele_60_0_wav};
  irMap[204][75] = {HRIR_48K_24bit::azi_204_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_204_0_ele_75_0_wav};
  irMap[204][90] = {HRIR_48K_24bit::azi_204_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_204_0_ele_90_0_wav};
  irMap[204][-15] = {HRIR_48K_24bit::azi_204_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_204_0_ele_neg15_0_wav};
  irMap[204][-25] = {HRIR_48K_24bit::azi_204_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_204_0_ele_neg25_0_wav};
  irMap[204][-30] = {HRIR_48K_24bit::azi_204_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_204_0_ele_neg30_0_wav};
  irMap[204][-45] = {HRIR_48K_24bit::azi_204_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_204_0_ele_neg45_0_wav};
  irMap[204][-54] = {HRIR_48K_24bit::azi_204_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_204_0_ele_neg54_0_wav};
  irMap[204][-60] = {HRIR_48K_24bit::azi_204_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_204_0_ele_neg60_0_wav};
  irMap[204][-75] = {HRIR_48K_24bit::azi_204_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_204_0_ele_neg75_0_wav};
  irMap[204][-81] = {HRIR_48K_24bit::azi_204_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_204_0_ele_neg81_0_wav};
  irMap[205][0] = {HRIR_48K_24bit::azi_205_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_205_0_ele_0_0_wav};
  irMap[205][15] = {HRIR_48K_24bit::azi_205_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_205_0_ele_15_0_wav};
  irMap[205][25] = {HRIR_48K_24bit::azi_205_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_205_0_ele_25_0_wav};
  irMap[205][30] = {HRIR_48K_24bit::azi_205_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_205_0_ele_30_0_wav};
  irMap[205][45] = {HRIR_48K_24bit::azi_205_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_205_0_ele_45_0_wav};
  irMap[205][54] = {HRIR_48K_24bit::azi_205_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_205_0_ele_54_0_wav};
  irMap[205][60] = {HRIR_48K_24bit::azi_205_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_205_0_ele_60_0_wav};
  irMap[205][75] = {HRIR_48K_24bit::azi_205_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_205_0_ele_75_0_wav};
  irMap[205][90] = {HRIR_48K_24bit::azi_205_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_205_0_ele_90_0_wav};
  irMap[205][-15] = {HRIR_48K_24bit::azi_205_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_205_0_ele_neg15_0_wav};
  irMap[205][-25] = {HRIR_48K_24bit::azi_205_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_205_0_ele_neg25_0_wav};
  irMap[205][-30] = {HRIR_48K_24bit::azi_205_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_205_0_ele_neg30_0_wav};
  irMap[205][-45] = {HRIR_48K_24bit::azi_205_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_205_0_ele_neg45_0_wav};
  irMap[205][-54] = {HRIR_48K_24bit::azi_205_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_205_0_ele_neg54_0_wav};
  irMap[205][-60] = {HRIR_48K_24bit::azi_205_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_205_0_ele_neg60_0_wav};
  irMap[205][-75] = {HRIR_48K_24bit::azi_205_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_205_0_ele_neg75_0_wav};
  irMap[205][-81] = {HRIR_48K_24bit::azi_205_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_205_0_ele_neg81_0_wav};
  irMap[206][0] = {HRIR_48K_24bit::azi_206_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_206_0_ele_0_0_wav};
  irMap[206][15] = {HRIR_48K_24bit::azi_206_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_206_0_ele_15_0_wav};
  irMap[206][25] = {HRIR_48K_24bit::azi_206_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_206_0_ele_25_0_wav};
  irMap[206][30] = {HRIR_48K_24bit::azi_206_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_206_0_ele_30_0_wav};
  irMap[206][45] = {HRIR_48K_24bit::azi_206_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_206_0_ele_45_0_wav};
  irMap[206][54] = {HRIR_48K_24bit::azi_206_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_206_0_ele_54_0_wav};
  irMap[206][60] = {HRIR_48K_24bit::azi_206_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_206_0_ele_60_0_wav};
  irMap[206][75] = {HRIR_48K_24bit::azi_206_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_206_0_ele_75_0_wav};
  irMap[206][90] = {HRIR_48K_24bit::azi_206_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_206_0_ele_90_0_wav};
  irMap[206][-15] = {HRIR_48K_24bit::azi_206_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_206_0_ele_neg15_0_wav};
  irMap[206][-25] = {HRIR_48K_24bit::azi_206_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_206_0_ele_neg25_0_wav};
  irMap[206][-30] = {HRIR_48K_24bit::azi_206_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_206_0_ele_neg30_0_wav};
  irMap[206][-45] = {HRIR_48K_24bit::azi_206_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_206_0_ele_neg45_0_wav};
  irMap[206][-54] = {HRIR_48K_24bit::azi_206_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_206_0_ele_neg54_0_wav};
  irMap[206][-60] = {HRIR_48K_24bit::azi_206_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_206_0_ele_neg60_0_wav};
  irMap[206][-75] = {HRIR_48K_24bit::azi_206_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_206_0_ele_neg75_0_wav};
  irMap[206][-81] = {HRIR_48K_24bit::azi_206_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_206_0_ele_neg81_0_wav};
  irMap[207][0] = {HRIR_48K_24bit::azi_207_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_207_0_ele_0_0_wav};
  irMap[207][15] = {HRIR_48K_24bit::azi_207_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_207_0_ele_15_0_wav};
  irMap[207][25] = {HRIR_48K_24bit::azi_207_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_207_0_ele_25_0_wav};
  irMap[207][30] = {HRIR_48K_24bit::azi_207_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_207_0_ele_30_0_wav};
  irMap[207][45] = {HRIR_48K_24bit::azi_207_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_207_0_ele_45_0_wav};
  irMap[207][54] = {HRIR_48K_24bit::azi_207_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_207_0_ele_54_0_wav};
  irMap[207][60] = {HRIR_48K_24bit::azi_207_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_207_0_ele_60_0_wav};
  irMap[207][75] = {HRIR_48K_24bit::azi_207_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_207_0_ele_75_0_wav};
  irMap[207][90] = {HRIR_48K_24bit::azi_207_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_207_0_ele_90_0_wav};
  irMap[207][-15] = {HRIR_48K_24bit::azi_207_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_207_0_ele_neg15_0_wav};
  irMap[207][-25] = {HRIR_48K_24bit::azi_207_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_207_0_ele_neg25_0_wav};
  irMap[207][-30] = {HRIR_48K_24bit::azi_207_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_207_0_ele_neg30_0_wav};
  irMap[207][-45] = {HRIR_48K_24bit::azi_207_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_207_0_ele_neg45_0_wav};
  irMap[207][-54] = {HRIR_48K_24bit::azi_207_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_207_0_ele_neg54_0_wav};
  irMap[207][-60] = {HRIR_48K_24bit::azi_207_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_207_0_ele_neg60_0_wav};
  irMap[207][-75] = {HRIR_48K_24bit::azi_207_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_207_0_ele_neg75_0_wav};
  irMap[207][-81] = {HRIR_48K_24bit::azi_207_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_207_0_ele_neg81_0_wav};
  irMap[208][0] = {HRIR_48K_24bit::azi_208_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_208_0_ele_0_0_wav};
  irMap[208][15] = {HRIR_48K_24bit::azi_208_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_208_0_ele_15_0_wav};
  irMap[208][25] = {HRIR_48K_24bit::azi_208_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_208_0_ele_25_0_wav};
  irMap[208][30] = {HRIR_48K_24bit::azi_208_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_208_0_ele_30_0_wav};
  irMap[208][45] = {HRIR_48K_24bit::azi_208_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_208_0_ele_45_0_wav};
  irMap[208][54] = {HRIR_48K_24bit::azi_208_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_208_0_ele_54_0_wav};
  irMap[208][60] = {HRIR_48K_24bit::azi_208_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_208_0_ele_60_0_wav};
  irMap[208][75] = {HRIR_48K_24bit::azi_208_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_208_0_ele_75_0_wav};
  irMap[208][90] = {HRIR_48K_24bit::azi_208_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_208_0_ele_90_0_wav};
  irMap[208][-15] = {HRIR_48K_24bit::azi_208_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_208_0_ele_neg15_0_wav};
  irMap[208][-25] = {HRIR_48K_24bit::azi_208_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_208_0_ele_neg25_0_wav};
  irMap[208][-30] = {HRIR_48K_24bit::azi_208_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_208_0_ele_neg30_0_wav};
  irMap[208][-45] = {HRIR_48K_24bit::azi_208_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_208_0_ele_neg45_0_wav};
  irMap[208][-54] = {HRIR_48K_24bit::azi_208_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_208_0_ele_neg54_0_wav};
  irMap[208][-60] = {HRIR_48K_24bit::azi_208_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_208_0_ele_neg60_0_wav};
  irMap[208][-75] = {HRIR_48K_24bit::azi_208_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_208_0_ele_neg75_0_wav};
  irMap[208][-81] = {HRIR_48K_24bit::azi_208_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_208_0_ele_neg81_0_wav};
  irMap[209][0] = {HRIR_48K_24bit::azi_209_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_209_0_ele_0_0_wav};
  irMap[209][15] = {HRIR_48K_24bit::azi_209_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_209_0_ele_15_0_wav};
  irMap[209][25] = {HRIR_48K_24bit::azi_209_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_209_0_ele_25_0_wav};
  irMap[209][30] = {HRIR_48K_24bit::azi_209_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_209_0_ele_30_0_wav};
  irMap[209][45] = {HRIR_48K_24bit::azi_209_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_209_0_ele_45_0_wav};
  irMap[209][54] = {HRIR_48K_24bit::azi_209_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_209_0_ele_54_0_wav};
  irMap[209][60] = {HRIR_48K_24bit::azi_209_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_209_0_ele_60_0_wav};
  irMap[209][75] = {HRIR_48K_24bit::azi_209_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_209_0_ele_75_0_wav};
  irMap[209][90] = {HRIR_48K_24bit::azi_209_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_209_0_ele_90_0_wav};
  irMap[209][-15] = {HRIR_48K_24bit::azi_209_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_209_0_ele_neg15_0_wav};
  irMap[209][-25] = {HRIR_48K_24bit::azi_209_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_209_0_ele_neg25_0_wav};
  irMap[209][-30] = {HRIR_48K_24bit::azi_209_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_209_0_ele_neg30_0_wav};
  irMap[209][-45] = {HRIR_48K_24bit::azi_209_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_209_0_ele_neg45_0_wav};
  irMap[209][-54] = {HRIR_48K_24bit::azi_209_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_209_0_ele_neg54_0_wav};
  irMap[209][-60] = {HRIR_48K_24bit::azi_209_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_209_0_ele_neg60_0_wav};
  irMap[209][-75] = {HRIR_48K_24bit::azi_209_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_209_0_ele_neg75_0_wav};
  irMap[209][-81] = {HRIR_48K_24bit::azi_209_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_209_0_ele_neg81_0_wav};
  irMap[210][0] = {HRIR_48K_24bit::azi_210_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_210_0_ele_0_0_wav};
  irMap[210][15] = {HRIR_48K_24bit::azi_210_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_210_0_ele_15_0_wav};
  irMap[210][25] = {HRIR_48K_24bit::azi_210_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_210_0_ele_25_0_wav};
  irMap[210][30] = {HRIR_48K_24bit::azi_210_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_210_0_ele_30_0_wav};
  irMap[210][45] = {HRIR_48K_24bit::azi_210_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_210_0_ele_45_0_wav};
  irMap[210][54] = {HRIR_48K_24bit::azi_210_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_210_0_ele_54_0_wav};
  irMap[210][60] = {HRIR_48K_24bit::azi_210_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_210_0_ele_60_0_wav};
  irMap[210][75] = {HRIR_48K_24bit::azi_210_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_210_0_ele_75_0_wav};
  irMap[210][90] = {HRIR_48K_24bit::azi_210_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_210_0_ele_90_0_wav};
  irMap[210][-15] = {HRIR_48K_24bit::azi_210_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_210_0_ele_neg15_0_wav};
  irMap[210][-25] = {HRIR_48K_24bit::azi_210_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_210_0_ele_neg25_0_wav};
  irMap[210][-30] = {HRIR_48K_24bit::azi_210_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_210_0_ele_neg30_0_wav};
  irMap[210][-45] = {HRIR_48K_24bit::azi_210_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_210_0_ele_neg45_0_wav};
  irMap[210][-54] = {HRIR_48K_24bit::azi_210_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_210_0_ele_neg54_0_wav};
  irMap[210][-60] = {HRIR_48K_24bit::azi_210_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_210_0_ele_neg60_0_wav};
  irMap[210][-75] = {HRIR_48K_24bit::azi_210_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_210_0_ele_neg75_0_wav};
  irMap[210][-81] = {HRIR_48K_24bit::azi_210_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_210_0_ele_neg81_0_wav};
  irMap[211][0] = {HRIR_48K_24bit::azi_211_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_211_0_ele_0_0_wav};
  irMap[211][15] = {HRIR_48K_24bit::azi_211_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_211_0_ele_15_0_wav};
  irMap[211][25] = {HRIR_48K_24bit::azi_211_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_211_0_ele_25_0_wav};
  irMap[211][30] = {HRIR_48K_24bit::azi_211_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_211_0_ele_30_0_wav};
  irMap[211][45] = {HRIR_48K_24bit::azi_211_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_211_0_ele_45_0_wav};
  irMap[211][54] = {HRIR_48K_24bit::azi_211_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_211_0_ele_54_0_wav};
  irMap[211][60] = {HRIR_48K_24bit::azi_211_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_211_0_ele_60_0_wav};
  irMap[211][75] = {HRIR_48K_24bit::azi_211_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_211_0_ele_75_0_wav};
  irMap[211][90] = {HRIR_48K_24bit::azi_211_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_211_0_ele_90_0_wav};
  irMap[211][-15] = {HRIR_48K_24bit::azi_211_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_211_0_ele_neg15_0_wav};
  irMap[211][-25] = {HRIR_48K_24bit::azi_211_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_211_0_ele_neg25_0_wav};
  irMap[211][-30] = {HRIR_48K_24bit::azi_211_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_211_0_ele_neg30_0_wav};
  irMap[211][-45] = {HRIR_48K_24bit::azi_211_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_211_0_ele_neg45_0_wav};
  irMap[211][-54] = {HRIR_48K_24bit::azi_211_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_211_0_ele_neg54_0_wav};
  irMap[211][-60] = {HRIR_48K_24bit::azi_211_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_211_0_ele_neg60_0_wav};
  irMap[211][-75] = {HRIR_48K_24bit::azi_211_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_211_0_ele_neg75_0_wav};
  irMap[211][-81] = {HRIR_48K_24bit::azi_211_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_211_0_ele_neg81_0_wav};
  irMap[212][0] = {HRIR_48K_24bit::azi_212_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_212_0_ele_0_0_wav};
  irMap[212][15] = {HRIR_48K_24bit::azi_212_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_212_0_ele_15_0_wav};
  irMap[212][25] = {HRIR_48K_24bit::azi_212_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_212_0_ele_25_0_wav};
  irMap[212][30] = {HRIR_48K_24bit::azi_212_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_212_0_ele_30_0_wav};
  irMap[212][45] = {HRIR_48K_24bit::azi_212_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_212_0_ele_45_0_wav};
  irMap[212][54] = {HRIR_48K_24bit::azi_212_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_212_0_ele_54_0_wav};
  irMap[212][60] = {HRIR_48K_24bit::azi_212_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_212_0_ele_60_0_wav};
  irMap[212][75] = {HRIR_48K_24bit::azi_212_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_212_0_ele_75_0_wav};
  irMap[212][90] = {HRIR_48K_24bit::azi_212_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_212_0_ele_90_0_wav};
  irMap[212][-15] = {HRIR_48K_24bit::azi_212_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_212_0_ele_neg15_0_wav};
  irMap[212][-25] = {HRIR_48K_24bit::azi_212_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_212_0_ele_neg25_0_wav};
  irMap[212][-30] = {HRIR_48K_24bit::azi_212_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_212_0_ele_neg30_0_wav};
  irMap[212][-45] = {HRIR_48K_24bit::azi_212_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_212_0_ele_neg45_0_wav};
  irMap[212][-54] = {HRIR_48K_24bit::azi_212_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_212_0_ele_neg54_0_wav};
  irMap[212][-60] = {HRIR_48K_24bit::azi_212_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_212_0_ele_neg60_0_wav};
  irMap[212][-75] = {HRIR_48K_24bit::azi_212_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_212_0_ele_neg75_0_wav};
  irMap[212][-81] = {HRIR_48K_24bit::azi_212_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_212_0_ele_neg81_0_wav};
  irMap[213][0] = {HRIR_48K_24bit::azi_213_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_213_0_ele_0_0_wav};
  irMap[213][15] = {HRIR_48K_24bit::azi_213_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_213_0_ele_15_0_wav};
  irMap[213][25] = {HRIR_48K_24bit::azi_213_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_213_0_ele_25_0_wav};
  irMap[213][30] = {HRIR_48K_24bit::azi_213_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_213_0_ele_30_0_wav};
  irMap[213][45] = {HRIR_48K_24bit::azi_213_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_213_0_ele_45_0_wav};
  irMap[213][54] = {HRIR_48K_24bit::azi_213_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_213_0_ele_54_0_wav};
  irMap[213][60] = {HRIR_48K_24bit::azi_213_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_213_0_ele_60_0_wav};
  irMap[213][75] = {HRIR_48K_24bit::azi_213_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_213_0_ele_75_0_wav};
  irMap[213][90] = {HRIR_48K_24bit::azi_213_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_213_0_ele_90_0_wav};
  irMap[213][-15] = {HRIR_48K_24bit::azi_213_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_213_0_ele_neg15_0_wav};
  irMap[213][-25] = {HRIR_48K_24bit::azi_213_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_213_0_ele_neg25_0_wav};
  irMap[213][-30] = {HRIR_48K_24bit::azi_213_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_213_0_ele_neg30_0_wav};
  irMap[213][-45] = {HRIR_48K_24bit::azi_213_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_213_0_ele_neg45_0_wav};
  irMap[213][-54] = {HRIR_48K_24bit::azi_213_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_213_0_ele_neg54_0_wav};
  irMap[213][-60] = {HRIR_48K_24bit::azi_213_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_213_0_ele_neg60_0_wav};
  irMap[213][-75] = {HRIR_48K_24bit::azi_213_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_213_0_ele_neg75_0_wav};
  irMap[213][-81] = {HRIR_48K_24bit::azi_213_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_213_0_ele_neg81_0_wav};
  irMap[214][0] = {HRIR_48K_24bit::azi_214_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_214_0_ele_0_0_wav};
  irMap[214][15] = {HRIR_48K_24bit::azi_214_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_214_0_ele_15_0_wav};
  irMap[214][25] = {HRIR_48K_24bit::azi_214_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_214_0_ele_25_0_wav};
  irMap[214][30] = {HRIR_48K_24bit::azi_214_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_214_0_ele_30_0_wav};
  irMap[214][45] = {HRIR_48K_24bit::azi_214_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_214_0_ele_45_0_wav};
  irMap[214][54] = {HRIR_48K_24bit::azi_214_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_214_0_ele_54_0_wav};
  irMap[214][60] = {HRIR_48K_24bit::azi_214_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_214_0_ele_60_0_wav};
  irMap[214][75] = {HRIR_48K_24bit::azi_214_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_214_0_ele_75_0_wav};
  irMap[214][90] = {HRIR_48K_24bit::azi_214_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_214_0_ele_90_0_wav};
  irMap[214][-15] = {HRIR_48K_24bit::azi_214_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_214_0_ele_neg15_0_wav};
  irMap[214][-25] = {HRIR_48K_24bit::azi_214_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_214_0_ele_neg25_0_wav};
  irMap[214][-30] = {HRIR_48K_24bit::azi_214_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_214_0_ele_neg30_0_wav};
  irMap[214][-45] = {HRIR_48K_24bit::azi_214_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_214_0_ele_neg45_0_wav};
  irMap[214][-54] = {HRIR_48K_24bit::azi_214_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_214_0_ele_neg54_0_wav};
  irMap[214][-60] = {HRIR_48K_24bit::azi_214_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_214_0_ele_neg60_0_wav};
  irMap[214][-75] = {HRIR_48K_24bit::azi_214_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_214_0_ele_neg75_0_wav};
  irMap[214][-81] = {HRIR_48K_24bit::azi_214_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_214_0_ele_neg81_0_wav};
  irMap[215][0] = {HRIR_48K_24bit::azi_215_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_215_0_ele_0_0_wav};
  irMap[215][15] = {HRIR_48K_24bit::azi_215_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_215_0_ele_15_0_wav};
  irMap[215][25] = {HRIR_48K_24bit::azi_215_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_215_0_ele_25_0_wav};
  irMap[215][30] = {HRIR_48K_24bit::azi_215_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_215_0_ele_30_0_wav};
  irMap[215][45] = {HRIR_48K_24bit::azi_215_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_215_0_ele_45_0_wav};
  irMap[215][54] = {HRIR_48K_24bit::azi_215_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_215_0_ele_54_0_wav};
  irMap[215][60] = {HRIR_48K_24bit::azi_215_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_215_0_ele_60_0_wav};
  irMap[215][75] = {HRIR_48K_24bit::azi_215_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_215_0_ele_75_0_wav};
  irMap[215][90] = {HRIR_48K_24bit::azi_215_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_215_0_ele_90_0_wav};
  irMap[215][-15] = {HRIR_48K_24bit::azi_215_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_215_0_ele_neg15_0_wav};
  irMap[215][-25] = {HRIR_48K_24bit::azi_215_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_215_0_ele_neg25_0_wav};
  irMap[215][-30] = {HRIR_48K_24bit::azi_215_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_215_0_ele_neg30_0_wav};
  irMap[215][-45] = {HRIR_48K_24bit::azi_215_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_215_0_ele_neg45_0_wav};
  irMap[215][-54] = {HRIR_48K_24bit::azi_215_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_215_0_ele_neg54_0_wav};
  irMap[215][-60] = {HRIR_48K_24bit::azi_215_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_215_0_ele_neg60_0_wav};
  irMap[215][-75] = {HRIR_48K_24bit::azi_215_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_215_0_ele_neg75_0_wav};
  irMap[215][-81] = {HRIR_48K_24bit::azi_215_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_215_0_ele_neg81_0_wav};
  irMap[216][0] = {HRIR_48K_24bit::azi_216_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_216_0_ele_0_0_wav};
  irMap[216][15] = {HRIR_48K_24bit::azi_216_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_216_0_ele_15_0_wav};
  irMap[216][25] = {HRIR_48K_24bit::azi_216_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_216_0_ele_25_0_wav};
  irMap[216][30] = {HRIR_48K_24bit::azi_216_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_216_0_ele_30_0_wav};
  irMap[216][45] = {HRIR_48K_24bit::azi_216_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_216_0_ele_45_0_wav};
  irMap[216][54] = {HRIR_48K_24bit::azi_216_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_216_0_ele_54_0_wav};
  irMap[216][60] = {HRIR_48K_24bit::azi_216_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_216_0_ele_60_0_wav};
  irMap[216][75] = {HRIR_48K_24bit::azi_216_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_216_0_ele_75_0_wav};
  irMap[216][90] = {HRIR_48K_24bit::azi_216_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_216_0_ele_90_0_wav};
  irMap[216][-15] = {HRIR_48K_24bit::azi_216_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_216_0_ele_neg15_0_wav};
  irMap[216][-25] = {HRIR_48K_24bit::azi_216_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_216_0_ele_neg25_0_wav};
  irMap[216][-30] = {HRIR_48K_24bit::azi_216_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_216_0_ele_neg30_0_wav};
  irMap[216][-45] = {HRIR_48K_24bit::azi_216_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_216_0_ele_neg45_0_wav};
  irMap[216][-54] = {HRIR_48K_24bit::azi_216_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_216_0_ele_neg54_0_wav};
  irMap[216][-60] = {HRIR_48K_24bit::azi_216_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_216_0_ele_neg60_0_wav};
  irMap[216][-75] = {HRIR_48K_24bit::azi_216_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_216_0_ele_neg75_0_wav};
  irMap[216][-81] = {HRIR_48K_24bit::azi_216_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_216_0_ele_neg81_0_wav};
  irMap[217][0] = {HRIR_48K_24bit::azi_217_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_217_0_ele_0_0_wav};
  irMap[217][15] = {HRIR_48K_24bit::azi_217_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_217_0_ele_15_0_wav};
  irMap[217][25] = {HRIR_48K_24bit::azi_217_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_217_0_ele_25_0_wav};
  irMap[217][30] = {HRIR_48K_24bit::azi_217_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_217_0_ele_30_0_wav};
  irMap[217][45] = {HRIR_48K_24bit::azi_217_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_217_0_ele_45_0_wav};
  irMap[217][54] = {HRIR_48K_24bit::azi_217_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_217_0_ele_54_0_wav};
  irMap[217][60] = {HRIR_48K_24bit::azi_217_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_217_0_ele_60_0_wav};
  irMap[217][75] = {HRIR_48K_24bit::azi_217_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_217_0_ele_75_0_wav};
  irMap[217][90] = {HRIR_48K_24bit::azi_217_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_217_0_ele_90_0_wav};
  irMap[217][-15] = {HRIR_48K_24bit::azi_217_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_217_0_ele_neg15_0_wav};
  irMap[217][-25] = {HRIR_48K_24bit::azi_217_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_217_0_ele_neg25_0_wav};
  irMap[217][-30] = {HRIR_48K_24bit::azi_217_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_217_0_ele_neg30_0_wav};
  irMap[217][-45] = {HRIR_48K_24bit::azi_217_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_217_0_ele_neg45_0_wav};
  irMap[217][-54] = {HRIR_48K_24bit::azi_217_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_217_0_ele_neg54_0_wav};
  irMap[217][-60] = {HRIR_48K_24bit::azi_217_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_217_0_ele_neg60_0_wav};
  irMap[217][-75] = {HRIR_48K_24bit::azi_217_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_217_0_ele_neg75_0_wav};
  irMap[217][-81] = {HRIR_48K_24bit::azi_217_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_217_0_ele_neg81_0_wav};
  irMap[218][0] = {HRIR_48K_24bit::azi_218_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_218_0_ele_0_0_wav};
  irMap[218][15] = {HRIR_48K_24bit::azi_218_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_218_0_ele_15_0_wav};
  irMap[218][25] = {HRIR_48K_24bit::azi_218_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_218_0_ele_25_0_wav};
  irMap[218][30] = {HRIR_48K_24bit::azi_218_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_218_0_ele_30_0_wav};
  irMap[218][45] = {HRIR_48K_24bit::azi_218_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_218_0_ele_45_0_wav};
  irMap[218][54] = {HRIR_48K_24bit::azi_218_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_218_0_ele_54_0_wav};
  irMap[218][60] = {HRIR_48K_24bit::azi_218_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_218_0_ele_60_0_wav};
  irMap[218][75] = {HRIR_48K_24bit::azi_218_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_218_0_ele_75_0_wav};
  irMap[218][90] = {HRIR_48K_24bit::azi_218_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_218_0_ele_90_0_wav};
  irMap[218][-15] = {HRIR_48K_24bit::azi_218_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_218_0_ele_neg15_0_wav};
  irMap[218][-25] = {HRIR_48K_24bit::azi_218_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_218_0_ele_neg25_0_wav};
  irMap[218][-30] = {HRIR_48K_24bit::azi_218_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_218_0_ele_neg30_0_wav};
  irMap[218][-45] = {HRIR_48K_24bit::azi_218_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_218_0_ele_neg45_0_wav};
  irMap[218][-54] = {HRIR_48K_24bit::azi_218_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_218_0_ele_neg54_0_wav};
  irMap[218][-60] = {HRIR_48K_24bit::azi_218_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_218_0_ele_neg60_0_wav};
  irMap[218][-75] = {HRIR_48K_24bit::azi_218_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_218_0_ele_neg75_0_wav};
  irMap[218][-81] = {HRIR_48K_24bit::azi_218_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_218_0_ele_neg81_0_wav};
  irMap[219][0] = {HRIR_48K_24bit::azi_219_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_219_0_ele_0_0_wav};
  irMap[219][15] = {HRIR_48K_24bit::azi_219_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_219_0_ele_15_0_wav};
  irMap[219][25] = {HRIR_48K_24bit::azi_219_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_219_0_ele_25_0_wav};
  irMap[219][30] = {HRIR_48K_24bit::azi_219_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_219_0_ele_30_0_wav};
  irMap[219][45] = {HRIR_48K_24bit::azi_219_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_219_0_ele_45_0_wav};
  irMap[219][54] = {HRIR_48K_24bit::azi_219_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_219_0_ele_54_0_wav};
  irMap[219][60] = {HRIR_48K_24bit::azi_219_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_219_0_ele_60_0_wav};
  irMap[219][75] = {HRIR_48K_24bit::azi_219_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_219_0_ele_75_0_wav};
  irMap[219][90] = {HRIR_48K_24bit::azi_219_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_219_0_ele_90_0_wav};
  irMap[219][-15] = {HRIR_48K_24bit::azi_219_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_219_0_ele_neg15_0_wav};
  irMap[219][-25] = {HRIR_48K_24bit::azi_219_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_219_0_ele_neg25_0_wav};
  irMap[219][-30] = {HRIR_48K_24bit::azi_219_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_219_0_ele_neg30_0_wav};
  irMap[219][-45] = {HRIR_48K_24bit::azi_219_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_219_0_ele_neg45_0_wav};
  irMap[219][-54] = {HRIR_48K_24bit::azi_219_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_219_0_ele_neg54_0_wav};
  irMap[219][-60] = {HRIR_48K_24bit::azi_219_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_219_0_ele_neg60_0_wav};
  irMap[219][-75] = {HRIR_48K_24bit::azi_219_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_219_0_ele_neg75_0_wav};
  irMap[219][-81] = {HRIR_48K_24bit::azi_219_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_219_0_ele_neg81_0_wav};
  irMap[220][0] = {HRIR_48K_24bit::azi_220_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_220_0_ele_0_0_wav};
  irMap[220][15] = {HRIR_48K_24bit::azi_220_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_220_0_ele_15_0_wav};
  irMap[220][25] = {HRIR_48K_24bit::azi_220_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_220_0_ele_25_0_wav};
  irMap[220][30] = {HRIR_48K_24bit::azi_220_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_220_0_ele_30_0_wav};
  irMap[220][45] = {HRIR_48K_24bit::azi_220_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_220_0_ele_45_0_wav};
  irMap[220][54] = {HRIR_48K_24bit::azi_220_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_220_0_ele_54_0_wav};
  irMap[220][60] = {HRIR_48K_24bit::azi_220_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_220_0_ele_60_0_wav};
  irMap[220][75] = {HRIR_48K_24bit::azi_220_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_220_0_ele_75_0_wav};
  irMap[220][90] = {HRIR_48K_24bit::azi_220_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_220_0_ele_90_0_wav};
  irMap[220][-15] = {HRIR_48K_24bit::azi_220_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_220_0_ele_neg15_0_wav};
  irMap[220][-25] = {HRIR_48K_24bit::azi_220_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_220_0_ele_neg25_0_wav};
  irMap[220][-30] = {HRIR_48K_24bit::azi_220_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_220_0_ele_neg30_0_wav};
  irMap[220][-45] = {HRIR_48K_24bit::azi_220_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_220_0_ele_neg45_0_wav};
  irMap[220][-54] = {HRIR_48K_24bit::azi_220_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_220_0_ele_neg54_0_wav};
  irMap[220][-60] = {HRIR_48K_24bit::azi_220_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_220_0_ele_neg60_0_wav};
  irMap[220][-75] = {HRIR_48K_24bit::azi_220_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_220_0_ele_neg75_0_wav};
  irMap[220][-81] = {HRIR_48K_24bit::azi_220_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_220_0_ele_neg81_0_wav};
  irMap[221][0] = {HRIR_48K_24bit::azi_221_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_221_0_ele_0_0_wav};
  irMap[221][15] = {HRIR_48K_24bit::azi_221_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_221_0_ele_15_0_wav};
  irMap[221][25] = {HRIR_48K_24bit::azi_221_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_221_0_ele_25_0_wav};
  irMap[221][30] = {HRIR_48K_24bit::azi_221_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_221_0_ele_30_0_wav};
  irMap[221][45] = {HRIR_48K_24bit::azi_221_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_221_0_ele_45_0_wav};
  irMap[221][54] = {HRIR_48K_24bit::azi_221_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_221_0_ele_54_0_wav};
  irMap[221][60] = {HRIR_48K_24bit::azi_221_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_221_0_ele_60_0_wav};
  irMap[221][75] = {HRIR_48K_24bit::azi_221_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_221_0_ele_75_0_wav};
  irMap[221][90] = {HRIR_48K_24bit::azi_221_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_221_0_ele_90_0_wav};
  irMap[221][-15] = {HRIR_48K_24bit::azi_221_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_221_0_ele_neg15_0_wav};
  irMap[221][-25] = {HRIR_48K_24bit::azi_221_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_221_0_ele_neg25_0_wav};
  irMap[221][-30] = {HRIR_48K_24bit::azi_221_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_221_0_ele_neg30_0_wav};
  irMap[221][-45] = {HRIR_48K_24bit::azi_221_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_221_0_ele_neg45_0_wav};
  irMap[221][-54] = {HRIR_48K_24bit::azi_221_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_221_0_ele_neg54_0_wav};
  irMap[221][-60] = {HRIR_48K_24bit::azi_221_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_221_0_ele_neg60_0_wav};
  irMap[221][-75] = {HRIR_48K_24bit::azi_221_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_221_0_ele_neg75_0_wav};
  irMap[221][-81] = {HRIR_48K_24bit::azi_221_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_221_0_ele_neg81_0_wav};
  irMap[222][0] = {HRIR_48K_24bit::azi_222_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_222_0_ele_0_0_wav};
  irMap[222][15] = {HRIR_48K_24bit::azi_222_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_222_0_ele_15_0_wav};
  irMap[222][25] = {HRIR_48K_24bit::azi_222_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_222_0_ele_25_0_wav};
  irMap[222][30] = {HRIR_48K_24bit::azi_222_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_222_0_ele_30_0_wav};
  irMap[222][45] = {HRIR_48K_24bit::azi_222_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_222_0_ele_45_0_wav};
  irMap[222][54] = {HRIR_48K_24bit::azi_222_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_222_0_ele_54_0_wav};
  irMap[222][60] = {HRIR_48K_24bit::azi_222_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_222_0_ele_60_0_wav};
  irMap[222][75] = {HRIR_48K_24bit::azi_222_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_222_0_ele_75_0_wav};
  irMap[222][90] = {HRIR_48K_24bit::azi_222_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_222_0_ele_90_0_wav};
  irMap[222][-15] = {HRIR_48K_24bit::azi_222_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_222_0_ele_neg15_0_wav};
  irMap[222][-25] = {HRIR_48K_24bit::azi_222_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_222_0_ele_neg25_0_wav};
  irMap[222][-30] = {HRIR_48K_24bit::azi_222_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_222_0_ele_neg30_0_wav};
  irMap[222][-45] = {HRIR_48K_24bit::azi_222_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_222_0_ele_neg45_0_wav};
  irMap[222][-54] = {HRIR_48K_24bit::azi_222_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_222_0_ele_neg54_0_wav};
  irMap[222][-60] = {HRIR_48K_24bit::azi_222_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_222_0_ele_neg60_0_wav};
  irMap[222][-75] = {HRIR_48K_24bit::azi_222_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_222_0_ele_neg75_0_wav};
  irMap[222][-81] = {HRIR_48K_24bit::azi_222_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_222_0_ele_neg81_0_wav};
  irMap[223][0] = {HRIR_48K_24bit::azi_223_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_223_0_ele_0_0_wav};
  irMap[223][15] = {HRIR_48K_24bit::azi_223_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_223_0_ele_15_0_wav};
  irMap[223][25] = {HRIR_48K_24bit::azi_223_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_223_0_ele_25_0_wav};
  irMap[223][30] = {HRIR_48K_24bit::azi_223_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_223_0_ele_30_0_wav};
  irMap[223][45] = {HRIR_48K_24bit::azi_223_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_223_0_ele_45_0_wav};
  irMap[223][54] = {HRIR_48K_24bit::azi_223_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_223_0_ele_54_0_wav};
  irMap[223][60] = {HRIR_48K_24bit::azi_223_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_223_0_ele_60_0_wav};
  irMap[223][75] = {HRIR_48K_24bit::azi_223_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_223_0_ele_75_0_wav};
  irMap[223][90] = {HRIR_48K_24bit::azi_223_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_223_0_ele_90_0_wav};
  irMap[223][-15] = {HRIR_48K_24bit::azi_223_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_223_0_ele_neg15_0_wav};
  irMap[223][-25] = {HRIR_48K_24bit::azi_223_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_223_0_ele_neg25_0_wav};
  irMap[223][-30] = {HRIR_48K_24bit::azi_223_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_223_0_ele_neg30_0_wav};
  irMap[223][-45] = {HRIR_48K_24bit::azi_223_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_223_0_ele_neg45_0_wav};
  irMap[223][-54] = {HRIR_48K_24bit::azi_223_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_223_0_ele_neg54_0_wav};
  irMap[223][-60] = {HRIR_48K_24bit::azi_223_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_223_0_ele_neg60_0_wav};
  irMap[223][-75] = {HRIR_48K_24bit::azi_223_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_223_0_ele_neg75_0_wav};
  irMap[223][-81] = {HRIR_48K_24bit::azi_223_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_223_0_ele_neg81_0_wav};
  irMap[224][0] = {HRIR_48K_24bit::azi_224_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_224_0_ele_0_0_wav};
  irMap[224][15] = {HRIR_48K_24bit::azi_224_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_224_0_ele_15_0_wav};
  irMap[224][25] = {HRIR_48K_24bit::azi_224_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_224_0_ele_25_0_wav};
  irMap[224][30] = {HRIR_48K_24bit::azi_224_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_224_0_ele_30_0_wav};
  irMap[224][45] = {HRIR_48K_24bit::azi_224_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_224_0_ele_45_0_wav};
  irMap[224][54] = {HRIR_48K_24bit::azi_224_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_224_0_ele_54_0_wav};
  irMap[224][60] = {HRIR_48K_24bit::azi_224_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_224_0_ele_60_0_wav};
  irMap[224][75] = {HRIR_48K_24bit::azi_224_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_224_0_ele_75_0_wav};
  irMap[224][90] = {HRIR_48K_24bit::azi_224_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_224_0_ele_90_0_wav};
  irMap[224][-15] = {HRIR_48K_24bit::azi_224_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_224_0_ele_neg15_0_wav};
  irMap[224][-25] = {HRIR_48K_24bit::azi_224_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_224_0_ele_neg25_0_wav};
  irMap[224][-30] = {HRIR_48K_24bit::azi_224_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_224_0_ele_neg30_0_wav};
  irMap[224][-45] = {HRIR_48K_24bit::azi_224_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_224_0_ele_neg45_0_wav};
  irMap[224][-54] = {HRIR_48K_24bit::azi_224_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_224_0_ele_neg54_0_wav};
  irMap[224][-60] = {HRIR_48K_24bit::azi_224_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_224_0_ele_neg60_0_wav};
  irMap[224][-75] = {HRIR_48K_24bit::azi_224_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_224_0_ele_neg75_0_wav};
  irMap[224][-81] = {HRIR_48K_24bit::azi_224_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_224_0_ele_neg81_0_wav};
  irMap[225][0] = {HRIR_48K_24bit::azi_225_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_225_0_ele_0_0_wav};
  irMap[225][15] = {HRIR_48K_24bit::azi_225_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_225_0_ele_15_0_wav};
  irMap[225][25] = {HRIR_48K_24bit::azi_225_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_225_0_ele_25_0_wav};
  irMap[225][30] = {HRIR_48K_24bit::azi_225_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_225_0_ele_30_0_wav};
  irMap[225][45] = {HRIR_48K_24bit::azi_225_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_225_0_ele_45_0_wav};
  irMap[225][54] = {HRIR_48K_24bit::azi_225_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_225_0_ele_54_0_wav};
  irMap[225][60] = {HRIR_48K_24bit::azi_225_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_225_0_ele_60_0_wav};
  irMap[225][75] = {HRIR_48K_24bit::azi_225_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_225_0_ele_75_0_wav};
  irMap[225][90] = {HRIR_48K_24bit::azi_225_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_225_0_ele_90_0_wav};
  irMap[225][-15] = {HRIR_48K_24bit::azi_225_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_225_0_ele_neg15_0_wav};
  irMap[225][-25] = {HRIR_48K_24bit::azi_225_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_225_0_ele_neg25_0_wav};
  irMap[225][-30] = {HRIR_48K_24bit::azi_225_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_225_0_ele_neg30_0_wav};
  irMap[225][-45] = {HRIR_48K_24bit::azi_225_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_225_0_ele_neg45_0_wav};
  irMap[225][-54] = {HRIR_48K_24bit::azi_225_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_225_0_ele_neg54_0_wav};
  irMap[225][-60] = {HRIR_48K_24bit::azi_225_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_225_0_ele_neg60_0_wav};
  irMap[225][-75] = {HRIR_48K_24bit::azi_225_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_225_0_ele_neg75_0_wav};
  irMap[225][-81] = {HRIR_48K_24bit::azi_225_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_225_0_ele_neg81_0_wav};
  irMap[226][0] = {HRIR_48K_24bit::azi_226_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_226_0_ele_0_0_wav};
  irMap[226][15] = {HRIR_48K_24bit::azi_226_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_226_0_ele_15_0_wav};
  irMap[226][25] = {HRIR_48K_24bit::azi_226_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_226_0_ele_25_0_wav};
  irMap[226][30] = {HRIR_48K_24bit::azi_226_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_226_0_ele_30_0_wav};
  irMap[226][45] = {HRIR_48K_24bit::azi_226_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_226_0_ele_45_0_wav};
  irMap[226][54] = {HRIR_48K_24bit::azi_226_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_226_0_ele_54_0_wav};
  irMap[226][60] = {HRIR_48K_24bit::azi_226_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_226_0_ele_60_0_wav};
  irMap[226][75] = {HRIR_48K_24bit::azi_226_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_226_0_ele_75_0_wav};
  irMap[226][90] = {HRIR_48K_24bit::azi_226_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_226_0_ele_90_0_wav};
  irMap[226][-15] = {HRIR_48K_24bit::azi_226_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_226_0_ele_neg15_0_wav};
  irMap[226][-25] = {HRIR_48K_24bit::azi_226_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_226_0_ele_neg25_0_wav};
  irMap[226][-30] = {HRIR_48K_24bit::azi_226_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_226_0_ele_neg30_0_wav};
  irMap[226][-45] = {HRIR_48K_24bit::azi_226_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_226_0_ele_neg45_0_wav};
  irMap[226][-54] = {HRIR_48K_24bit::azi_226_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_226_0_ele_neg54_0_wav};
  irMap[226][-60] = {HRIR_48K_24bit::azi_226_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_226_0_ele_neg60_0_wav};
  irMap[226][-75] = {HRIR_48K_24bit::azi_226_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_226_0_ele_neg75_0_wav};
  irMap[226][-81] = {HRIR_48K_24bit::azi_226_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_226_0_ele_neg81_0_wav};
  irMap[227][0] = {HRIR_48K_24bit::azi_227_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_227_0_ele_0_0_wav};
  irMap[227][15] = {HRIR_48K_24bit::azi_227_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_227_0_ele_15_0_wav};
  irMap[227][25] = {HRIR_48K_24bit::azi_227_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_227_0_ele_25_0_wav};
  irMap[227][30] = {HRIR_48K_24bit::azi_227_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_227_0_ele_30_0_wav};
  irMap[227][45] = {HRIR_48K_24bit::azi_227_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_227_0_ele_45_0_wav};
  irMap[227][54] = {HRIR_48K_24bit::azi_227_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_227_0_ele_54_0_wav};
  irMap[227][60] = {HRIR_48K_24bit::azi_227_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_227_0_ele_60_0_wav};
  irMap[227][75] = {HRIR_48K_24bit::azi_227_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_227_0_ele_75_0_wav};
  irMap[227][90] = {HRIR_48K_24bit::azi_227_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_227_0_ele_90_0_wav};
  irMap[227][-15] = {HRIR_48K_24bit::azi_227_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_227_0_ele_neg15_0_wav};
  irMap[227][-25] = {HRIR_48K_24bit::azi_227_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_227_0_ele_neg25_0_wav};
  irMap[227][-30] = {HRIR_48K_24bit::azi_227_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_227_0_ele_neg30_0_wav};
  irMap[227][-45] = {HRIR_48K_24bit::azi_227_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_227_0_ele_neg45_0_wav};
  irMap[227][-54] = {HRIR_48K_24bit::azi_227_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_227_0_ele_neg54_0_wav};
  irMap[227][-60] = {HRIR_48K_24bit::azi_227_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_227_0_ele_neg60_0_wav};
  irMap[227][-75] = {HRIR_48K_24bit::azi_227_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_227_0_ele_neg75_0_wav};
  irMap[227][-81] = {HRIR_48K_24bit::azi_227_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_227_0_ele_neg81_0_wav};
  irMap[228][0] = {HRIR_48K_24bit::azi_228_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_228_0_ele_0_0_wav};
  irMap[228][15] = {HRIR_48K_24bit::azi_228_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_228_0_ele_15_0_wav};
  irMap[228][25] = {HRIR_48K_24bit::azi_228_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_228_0_ele_25_0_wav};
  irMap[228][30] = {HRIR_48K_24bit::azi_228_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_228_0_ele_30_0_wav};
  irMap[228][45] = {HRIR_48K_24bit::azi_228_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_228_0_ele_45_0_wav};
  irMap[228][54] = {HRIR_48K_24bit::azi_228_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_228_0_ele_54_0_wav};
  irMap[228][60] = {HRIR_48K_24bit::azi_228_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_228_0_ele_60_0_wav};
  irMap[228][75] = {HRIR_48K_24bit::azi_228_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_228_0_ele_75_0_wav};
  irMap[228][90] = {HRIR_48K_24bit::azi_228_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_228_0_ele_90_0_wav};
  irMap[228][-15] = {HRIR_48K_24bit::azi_228_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_228_0_ele_neg15_0_wav};
  irMap[228][-25] = {HRIR_48K_24bit::azi_228_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_228_0_ele_neg25_0_wav};
  irMap[228][-30] = {HRIR_48K_24bit::azi_228_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_228_0_ele_neg30_0_wav};
  irMap[228][-45] = {HRIR_48K_24bit::azi_228_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_228_0_ele_neg45_0_wav};
  irMap[228][-54] = {HRIR_48K_24bit::azi_228_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_228_0_ele_neg54_0_wav};
  irMap[228][-60] = {HRIR_48K_24bit::azi_228_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_228_0_ele_neg60_0_wav};
  irMap[228][-75] = {HRIR_48K_24bit::azi_228_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_228_0_ele_neg75_0_wav};
  irMap[228][-81] = {HRIR_48K_24bit::azi_228_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_228_0_ele_neg81_0_wav};
  irMap[229][0] = {HRIR_48K_24bit::azi_229_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_229_0_ele_0_0_wav};
  irMap[229][15] = {HRIR_48K_24bit::azi_229_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_229_0_ele_15_0_wav};
  irMap[229][25] = {HRIR_48K_24bit::azi_229_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_229_0_ele_25_0_wav};
  irMap[229][30] = {HRIR_48K_24bit::azi_229_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_229_0_ele_30_0_wav};
  irMap[229][45] = {HRIR_48K_24bit::azi_229_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_229_0_ele_45_0_wav};
  irMap[229][54] = {HRIR_48K_24bit::azi_229_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_229_0_ele_54_0_wav};
  irMap[229][60] = {HRIR_48K_24bit::azi_229_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_229_0_ele_60_0_wav};
  irMap[229][75] = {HRIR_48K_24bit::azi_229_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_229_0_ele_75_0_wav};
  irMap[229][90] = {HRIR_48K_24bit::azi_229_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_229_0_ele_90_0_wav};
  irMap[229][-15] = {HRIR_48K_24bit::azi_229_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_229_0_ele_neg15_0_wav};
  irMap[229][-25] = {HRIR_48K_24bit::azi_229_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_229_0_ele_neg25_0_wav};
  irMap[229][-30] = {HRIR_48K_24bit::azi_229_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_229_0_ele_neg30_0_wav};
  irMap[229][-45] = {HRIR_48K_24bit::azi_229_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_229_0_ele_neg45_0_wav};
  irMap[229][-54] = {HRIR_48K_24bit::azi_229_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_229_0_ele_neg54_0_wav};
  irMap[229][-60] = {HRIR_48K_24bit::azi_229_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_229_0_ele_neg60_0_wav};
  irMap[229][-75] = {HRIR_48K_24bit::azi_229_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_229_0_ele_neg75_0_wav};
  irMap[229][-81] = {HRIR_48K_24bit::azi_229_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_229_0_ele_neg81_0_wav};
  irMap[230][0] = {HRIR_48K_24bit::azi_230_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_230_0_ele_0_0_wav};
  irMap[230][15] = {HRIR_48K_24bit::azi_230_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_230_0_ele_15_0_wav};
  irMap[230][25] = {HRIR_48K_24bit::azi_230_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_230_0_ele_25_0_wav};
  irMap[230][30] = {HRIR_48K_24bit::azi_230_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_230_0_ele_30_0_wav};
  irMap[230][45] = {HRIR_48K_24bit::azi_230_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_230_0_ele_45_0_wav};
  irMap[230][54] = {HRIR_48K_24bit::azi_230_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_230_0_ele_54_0_wav};
  irMap[230][60] = {HRIR_48K_24bit::azi_230_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_230_0_ele_60_0_wav};
  irMap[230][75] = {HRIR_48K_24bit::azi_230_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_230_0_ele_75_0_wav};
  irMap[230][90] = {HRIR_48K_24bit::azi_230_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_230_0_ele_90_0_wav};
  irMap[230][-15] = {HRIR_48K_24bit::azi_230_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_230_0_ele_neg15_0_wav};
  irMap[230][-25] = {HRIR_48K_24bit::azi_230_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_230_0_ele_neg25_0_wav};
  irMap[230][-30] = {HRIR_48K_24bit::azi_230_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_230_0_ele_neg30_0_wav};
  irMap[230][-45] = {HRIR_48K_24bit::azi_230_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_230_0_ele_neg45_0_wav};
  irMap[230][-54] = {HRIR_48K_24bit::azi_230_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_230_0_ele_neg54_0_wav};
  irMap[230][-60] = {HRIR_48K_24bit::azi_230_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_230_0_ele_neg60_0_wav};
  irMap[230][-75] = {HRIR_48K_24bit::azi_230_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_230_0_ele_neg75_0_wav};
  irMap[230][-81] = {HRIR_48K_24bit::azi_230_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_230_0_ele_neg81_0_wav};
  irMap[231][0] = {HRIR_48K_24bit::azi_231_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_231_0_ele_0_0_wav};
  irMap[231][15] = {HRIR_48K_24bit::azi_231_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_231_0_ele_15_0_wav};
  irMap[231][25] = {HRIR_48K_24bit::azi_231_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_231_0_ele_25_0_wav};
  irMap[231][30] = {HRIR_48K_24bit::azi_231_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_231_0_ele_30_0_wav};
  irMap[231][45] = {HRIR_48K_24bit::azi_231_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_231_0_ele_45_0_wav};
  irMap[231][54] = {HRIR_48K_24bit::azi_231_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_231_0_ele_54_0_wav};
  irMap[231][60] = {HRIR_48K_24bit::azi_231_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_231_0_ele_60_0_wav};
  irMap[231][75] = {HRIR_48K_24bit::azi_231_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_231_0_ele_75_0_wav};
  irMap[231][90] = {HRIR_48K_24bit::azi_231_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_231_0_ele_90_0_wav};
  irMap[231][-15] = {HRIR_48K_24bit::azi_231_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_231_0_ele_neg15_0_wav};
  irMap[231][-25] = {HRIR_48K_24bit::azi_231_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_231_0_ele_neg25_0_wav};
  irMap[231][-30] = {HRIR_48K_24bit::azi_231_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_231_0_ele_neg30_0_wav};
  irMap[231][-45] = {HRIR_48K_24bit::azi_231_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_231_0_ele_neg45_0_wav};
  irMap[231][-54] = {HRIR_48K_24bit::azi_231_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_231_0_ele_neg54_0_wav};
  irMap[231][-60] = {HRIR_48K_24bit::azi_231_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_231_0_ele_neg60_0_wav};
  irMap[231][-75] = {HRIR_48K_24bit::azi_231_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_231_0_ele_neg75_0_wav};
  irMap[231][-81] = {HRIR_48K_24bit::azi_231_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_231_0_ele_neg81_0_wav};
  irMap[232][0] = {HRIR_48K_24bit::azi_232_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_232_0_ele_0_0_wav};
  irMap[232][15] = {HRIR_48K_24bit::azi_232_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_232_0_ele_15_0_wav};
  irMap[232][25] = {HRIR_48K_24bit::azi_232_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_232_0_ele_25_0_wav};
  irMap[232][30] = {HRIR_48K_24bit::azi_232_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_232_0_ele_30_0_wav};
  irMap[232][45] = {HRIR_48K_24bit::azi_232_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_232_0_ele_45_0_wav};
  irMap[232][54] = {HRIR_48K_24bit::azi_232_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_232_0_ele_54_0_wav};
  irMap[232][60] = {HRIR_48K_24bit::azi_232_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_232_0_ele_60_0_wav};
  irMap[232][75] = {HRIR_48K_24bit::azi_232_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_232_0_ele_75_0_wav};
  irMap[232][90] = {HRIR_48K_24bit::azi_232_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_232_0_ele_90_0_wav};
  irMap[232][-15] = {HRIR_48K_24bit::azi_232_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_232_0_ele_neg15_0_wav};
  irMap[232][-25] = {HRIR_48K_24bit::azi_232_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_232_0_ele_neg25_0_wav};
  irMap[232][-30] = {HRIR_48K_24bit::azi_232_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_232_0_ele_neg30_0_wav};
  irMap[232][-45] = {HRIR_48K_24bit::azi_232_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_232_0_ele_neg45_0_wav};
  irMap[232][-54] = {HRIR_48K_24bit::azi_232_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_232_0_ele_neg54_0_wav};
  irMap[232][-60] = {HRIR_48K_24bit::azi_232_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_232_0_ele_neg60_0_wav};
  irMap[232][-75] = {HRIR_48K_24bit::azi_232_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_232_0_ele_neg75_0_wav};
  irMap[232][-81] = {HRIR_48K_24bit::azi_232_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_232_0_ele_neg81_0_wav};
  irMap[233][0] = {HRIR_48K_24bit::azi_233_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_233_0_ele_0_0_wav};
  irMap[233][15] = {HRIR_48K_24bit::azi_233_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_233_0_ele_15_0_wav};
  irMap[233][25] = {HRIR_48K_24bit::azi_233_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_233_0_ele_25_0_wav};
  irMap[233][30] = {HRIR_48K_24bit::azi_233_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_233_0_ele_30_0_wav};
  irMap[233][45] = {HRIR_48K_24bit::azi_233_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_233_0_ele_45_0_wav};
  irMap[233][54] = {HRIR_48K_24bit::azi_233_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_233_0_ele_54_0_wav};
  irMap[233][60] = {HRIR_48K_24bit::azi_233_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_233_0_ele_60_0_wav};
  irMap[233][75] = {HRIR_48K_24bit::azi_233_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_233_0_ele_75_0_wav};
  irMap[233][90] = {HRIR_48K_24bit::azi_233_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_233_0_ele_90_0_wav};
  irMap[233][-15] = {HRIR_48K_24bit::azi_233_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_233_0_ele_neg15_0_wav};
  irMap[233][-25] = {HRIR_48K_24bit::azi_233_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_233_0_ele_neg25_0_wav};
  irMap[233][-30] = {HRIR_48K_24bit::azi_233_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_233_0_ele_neg30_0_wav};
  irMap[233][-45] = {HRIR_48K_24bit::azi_233_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_233_0_ele_neg45_0_wav};
  irMap[233][-54] = {HRIR_48K_24bit::azi_233_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_233_0_ele_neg54_0_wav};
  irMap[233][-60] = {HRIR_48K_24bit::azi_233_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_233_0_ele_neg60_0_wav};
  irMap[233][-75] = {HRIR_48K_24bit::azi_233_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_233_0_ele_neg75_0_wav};
  irMap[233][-81] = {HRIR_48K_24bit::azi_233_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_233_0_ele_neg81_0_wav};
  irMap[234][0] = {HRIR_48K_24bit::azi_234_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_234_0_ele_0_0_wav};
  irMap[234][15] = {HRIR_48K_24bit::azi_234_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_234_0_ele_15_0_wav};
  irMap[234][25] = {HRIR_48K_24bit::azi_234_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_234_0_ele_25_0_wav};
  irMap[234][30] = {HRIR_48K_24bit::azi_234_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_234_0_ele_30_0_wav};
  irMap[234][45] = {HRIR_48K_24bit::azi_234_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_234_0_ele_45_0_wav};
  irMap[234][54] = {HRIR_48K_24bit::azi_234_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_234_0_ele_54_0_wav};
  irMap[234][60] = {HRIR_48K_24bit::azi_234_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_234_0_ele_60_0_wav};
  irMap[234][75] = {HRIR_48K_24bit::azi_234_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_234_0_ele_75_0_wav};
  irMap[234][90] = {HRIR_48K_24bit::azi_234_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_234_0_ele_90_0_wav};
  irMap[234][-15] = {HRIR_48K_24bit::azi_234_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_234_0_ele_neg15_0_wav};
  irMap[234][-25] = {HRIR_48K_24bit::azi_234_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_234_0_ele_neg25_0_wav};
  irMap[234][-30] = {HRIR_48K_24bit::azi_234_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_234_0_ele_neg30_0_wav};
  irMap[234][-45] = {HRIR_48K_24bit::azi_234_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_234_0_ele_neg45_0_wav};
  irMap[234][-54] = {HRIR_48K_24bit::azi_234_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_234_0_ele_neg54_0_wav};
  irMap[234][-60] = {HRIR_48K_24bit::azi_234_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_234_0_ele_neg60_0_wav};
  irMap[234][-75] = {HRIR_48K_24bit::azi_234_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_234_0_ele_neg75_0_wav};
  irMap[234][-81] = {HRIR_48K_24bit::azi_234_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_234_0_ele_neg81_0_wav};
  irMap[235][0] = {HRIR_48K_24bit::azi_235_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_235_0_ele_0_0_wav};
  irMap[235][15] = {HRIR_48K_24bit::azi_235_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_235_0_ele_15_0_wav};
  irMap[235][25] = {HRIR_48K_24bit::azi_235_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_235_0_ele_25_0_wav};
  irMap[235][30] = {HRIR_48K_24bit::azi_235_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_235_0_ele_30_0_wav};
  irMap[235][45] = {HRIR_48K_24bit::azi_235_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_235_0_ele_45_0_wav};
  irMap[235][54] = {HRIR_48K_24bit::azi_235_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_235_0_ele_54_0_wav};
  irMap[235][60] = {HRIR_48K_24bit::azi_235_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_235_0_ele_60_0_wav};
  irMap[235][75] = {HRIR_48K_24bit::azi_235_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_235_0_ele_75_0_wav};
  irMap[235][90] = {HRIR_48K_24bit::azi_235_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_235_0_ele_90_0_wav};
  irMap[235][-15] = {HRIR_48K_24bit::azi_235_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_235_0_ele_neg15_0_wav};
  irMap[235][-25] = {HRIR_48K_24bit::azi_235_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_235_0_ele_neg25_0_wav};
  irMap[235][-30] = {HRIR_48K_24bit::azi_235_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_235_0_ele_neg30_0_wav};
  irMap[235][-45] = {HRIR_48K_24bit::azi_235_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_235_0_ele_neg45_0_wav};
  irMap[235][-54] = {HRIR_48K_24bit::azi_235_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_235_0_ele_neg54_0_wav};
  irMap[235][-60] = {HRIR_48K_24bit::azi_235_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_235_0_ele_neg60_0_wav};
  irMap[235][-75] = {HRIR_48K_24bit::azi_235_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_235_0_ele_neg75_0_wav};
  irMap[235][-81] = {HRIR_48K_24bit::azi_235_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_235_0_ele_neg81_0_wav};
  irMap[236][0] = {HRIR_48K_24bit::azi_236_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_236_0_ele_0_0_wav};
  irMap[236][15] = {HRIR_48K_24bit::azi_236_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_236_0_ele_15_0_wav};
  irMap[236][25] = {HRIR_48K_24bit::azi_236_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_236_0_ele_25_0_wav};
  irMap[236][30] = {HRIR_48K_24bit::azi_236_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_236_0_ele_30_0_wav};
  irMap[236][45] = {HRIR_48K_24bit::azi_236_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_236_0_ele_45_0_wav};
  irMap[236][54] = {HRIR_48K_24bit::azi_236_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_236_0_ele_54_0_wav};
  irMap[236][60] = {HRIR_48K_24bit::azi_236_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_236_0_ele_60_0_wav};
  irMap[236][75] = {HRIR_48K_24bit::azi_236_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_236_0_ele_75_0_wav};
  irMap[236][90] = {HRIR_48K_24bit::azi_236_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_236_0_ele_90_0_wav};
  irMap[236][-15] = {HRIR_48K_24bit::azi_236_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_236_0_ele_neg15_0_wav};
  irMap[236][-25] = {HRIR_48K_24bit::azi_236_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_236_0_ele_neg25_0_wav};
  irMap[236][-30] = {HRIR_48K_24bit::azi_236_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_236_0_ele_neg30_0_wav};
  irMap[236][-45] = {HRIR_48K_24bit::azi_236_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_236_0_ele_neg45_0_wav};
  irMap[236][-54] = {HRIR_48K_24bit::azi_236_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_236_0_ele_neg54_0_wav};
  irMap[236][-60] = {HRIR_48K_24bit::azi_236_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_236_0_ele_neg60_0_wav};
  irMap[236][-75] = {HRIR_48K_24bit::azi_236_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_236_0_ele_neg75_0_wav};
  irMap[236][-81] = {HRIR_48K_24bit::azi_236_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_236_0_ele_neg81_0_wav};
  irMap[237][0] = {HRIR_48K_24bit::azi_237_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_237_0_ele_0_0_wav};
  irMap[237][15] = {HRIR_48K_24bit::azi_237_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_237_0_ele_15_0_wav};
  irMap[237][25] = {HRIR_48K_24bit::azi_237_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_237_0_ele_25_0_wav};
  irMap[237][30] = {HRIR_48K_24bit::azi_237_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_237_0_ele_30_0_wav};
  irMap[237][45] = {HRIR_48K_24bit::azi_237_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_237_0_ele_45_0_wav};
  irMap[237][54] = {HRIR_48K_24bit::azi_237_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_237_0_ele_54_0_wav};
  irMap[237][60] = {HRIR_48K_24bit::azi_237_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_237_0_ele_60_0_wav};
  irMap[237][75] = {HRIR_48K_24bit::azi_237_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_237_0_ele_75_0_wav};
  irMap[237][90] = {HRIR_48K_24bit::azi_237_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_237_0_ele_90_0_wav};
  irMap[237][-15] = {HRIR_48K_24bit::azi_237_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_237_0_ele_neg15_0_wav};
  irMap[237][-25] = {HRIR_48K_24bit::azi_237_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_237_0_ele_neg25_0_wav};
  irMap[237][-30] = {HRIR_48K_24bit::azi_237_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_237_0_ele_neg30_0_wav};
  irMap[237][-45] = {HRIR_48K_24bit::azi_237_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_237_0_ele_neg45_0_wav};
  irMap[237][-54] = {HRIR_48K_24bit::azi_237_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_237_0_ele_neg54_0_wav};
  irMap[237][-60] = {HRIR_48K_24bit::azi_237_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_237_0_ele_neg60_0_wav};
  irMap[237][-75] = {HRIR_48K_24bit::azi_237_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_237_0_ele_neg75_0_wav};
  irMap[237][-81] = {HRIR_48K_24bit::azi_237_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_237_0_ele_neg81_0_wav};
  irMap[238][0] = {HRIR_48K_24bit::azi_238_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_238_0_ele_0_0_wav};
  irMap[238][15] = {HRIR_48K_24bit::azi_238_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_238_0_ele_15_0_wav};
  irMap[238][25] = {HRIR_48K_24bit::azi_238_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_238_0_ele_25_0_wav};
  irMap[238][30] = {HRIR_48K_24bit::azi_238_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_238_0_ele_30_0_wav};
  irMap[238][45] = {HRIR_48K_24bit::azi_238_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_238_0_ele_45_0_wav};
  irMap[238][54] = {HRIR_48K_24bit::azi_238_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_238_0_ele_54_0_wav};
  irMap[238][60] = {HRIR_48K_24bit::azi_238_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_238_0_ele_60_0_wav};
  irMap[238][75] = {HRIR_48K_24bit::azi_238_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_238_0_ele_75_0_wav};
  irMap[238][90] = {HRIR_48K_24bit::azi_238_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_238_0_ele_90_0_wav};
  irMap[238][-15] = {HRIR_48K_24bit::azi_238_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_238_0_ele_neg15_0_wav};
  irMap[238][-25] = {HRIR_48K_24bit::azi_238_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_238_0_ele_neg25_0_wav};
  irMap[238][-30] = {HRIR_48K_24bit::azi_238_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_238_0_ele_neg30_0_wav};
  irMap[238][-45] = {HRIR_48K_24bit::azi_238_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_238_0_ele_neg45_0_wav};
  irMap[238][-54] = {HRIR_48K_24bit::azi_238_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_238_0_ele_neg54_0_wav};
  irMap[238][-60] = {HRIR_48K_24bit::azi_238_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_238_0_ele_neg60_0_wav};
  irMap[238][-75] = {HRIR_48K_24bit::azi_238_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_238_0_ele_neg75_0_wav};
  irMap[238][-81] = {HRIR_48K_24bit::azi_238_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_238_0_ele_neg81_0_wav};
  irMap[239][0] = {HRIR_48K_24bit::azi_239_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_239_0_ele_0_0_wav};
  irMap[239][15] = {HRIR_48K_24bit::azi_239_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_239_0_ele_15_0_wav};
  irMap[239][25] = {HRIR_48K_24bit::azi_239_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_239_0_ele_25_0_wav};
  irMap[239][30] = {HRIR_48K_24bit::azi_239_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_239_0_ele_30_0_wav};
  irMap[239][45] = {HRIR_48K_24bit::azi_239_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_239_0_ele_45_0_wav};
  irMap[239][54] = {HRIR_48K_24bit::azi_239_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_239_0_ele_54_0_wav};
  irMap[239][60] = {HRIR_48K_24bit::azi_239_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_239_0_ele_60_0_wav};
  irMap[239][75] = {HRIR_48K_24bit::azi_239_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_239_0_ele_75_0_wav};
  irMap[239][90] = {HRIR_48K_24bit::azi_239_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_239_0_ele_90_0_wav};
  irMap[239][-15] = {HRIR_48K_24bit::azi_239_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_239_0_ele_neg15_0_wav};
  irMap[239][-25] = {HRIR_48K_24bit::azi_239_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_239_0_ele_neg25_0_wav};
  irMap[239][-30] = {HRIR_48K_24bit::azi_239_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_239_0_ele_neg30_0_wav};
  irMap[239][-45] = {HRIR_48K_24bit::azi_239_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_239_0_ele_neg45_0_wav};
  irMap[239][-54] = {HRIR_48K_24bit::azi_239_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_239_0_ele_neg54_0_wav};
  irMap[239][-60] = {HRIR_48K_24bit::azi_239_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_239_0_ele_neg60_0_wav};
  irMap[239][-75] = {HRIR_48K_24bit::azi_239_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_239_0_ele_neg75_0_wav};
  irMap[239][-81] = {HRIR_48K_24bit::azi_239_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_239_0_ele_neg81_0_wav};
  irMap[240][0] = {HRIR_48K_24bit::azi_240_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_240_0_ele_0_0_wav};
  irMap[240][15] = {HRIR_48K_24bit::azi_240_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_240_0_ele_15_0_wav};
  irMap[240][25] = {HRIR_48K_24bit::azi_240_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_240_0_ele_25_0_wav};
  irMap[240][30] = {HRIR_48K_24bit::azi_240_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_240_0_ele_30_0_wav};
  irMap[240][45] = {HRIR_48K_24bit::azi_240_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_240_0_ele_45_0_wav};
  irMap[240][54] = {HRIR_48K_24bit::azi_240_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_240_0_ele_54_0_wav};
  irMap[240][60] = {HRIR_48K_24bit::azi_240_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_240_0_ele_60_0_wav};
  irMap[240][75] = {HRIR_48K_24bit::azi_240_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_240_0_ele_75_0_wav};
  irMap[240][90] = {HRIR_48K_24bit::azi_240_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_240_0_ele_90_0_wav};
  irMap[240][-15] = {HRIR_48K_24bit::azi_240_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_240_0_ele_neg15_0_wav};
  irMap[240][-25] = {HRIR_48K_24bit::azi_240_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_240_0_ele_neg25_0_wav};
  irMap[240][-30] = {HRIR_48K_24bit::azi_240_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_240_0_ele_neg30_0_wav};
  irMap[240][-45] = {HRIR_48K_24bit::azi_240_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_240_0_ele_neg45_0_wav};
  irMap[240][-54] = {HRIR_48K_24bit::azi_240_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_240_0_ele_neg54_0_wav};
  irMap[240][-60] = {HRIR_48K_24bit::azi_240_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_240_0_ele_neg60_0_wav};
  irMap[240][-75] = {HRIR_48K_24bit::azi_240_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_240_0_ele_neg75_0_wav};
  irMap[240][-81] = {HRIR_48K_24bit::azi_240_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_240_0_ele_neg81_0_wav};
  irMap[241][0] = {HRIR_48K_24bit::azi_241_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_241_0_ele_0_0_wav};
  irMap[241][15] = {HRIR_48K_24bit::azi_241_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_241_0_ele_15_0_wav};
  irMap[241][25] = {HRIR_48K_24bit::azi_241_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_241_0_ele_25_0_wav};
  irMap[241][30] = {HRIR_48K_24bit::azi_241_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_241_0_ele_30_0_wav};
  irMap[241][45] = {HRIR_48K_24bit::azi_241_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_241_0_ele_45_0_wav};
  irMap[241][54] = {HRIR_48K_24bit::azi_241_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_241_0_ele_54_0_wav};
  irMap[241][60] = {HRIR_48K_24bit::azi_241_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_241_0_ele_60_0_wav};
  irMap[241][75] = {HRIR_48K_24bit::azi_241_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_241_0_ele_75_0_wav};
  irMap[241][90] = {HRIR_48K_24bit::azi_241_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_241_0_ele_90_0_wav};
  irMap[241][-15] = {HRIR_48K_24bit::azi_241_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_241_0_ele_neg15_0_wav};
  irMap[241][-25] = {HRIR_48K_24bit::azi_241_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_241_0_ele_neg25_0_wav};
  irMap[241][-30] = {HRIR_48K_24bit::azi_241_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_241_0_ele_neg30_0_wav};
  irMap[241][-45] = {HRIR_48K_24bit::azi_241_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_241_0_ele_neg45_0_wav};
  irMap[241][-54] = {HRIR_48K_24bit::azi_241_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_241_0_ele_neg54_0_wav};
  irMap[241][-60] = {HRIR_48K_24bit::azi_241_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_241_0_ele_neg60_0_wav};
  irMap[241][-75] = {HRIR_48K_24bit::azi_241_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_241_0_ele_neg75_0_wav};
  irMap[241][-81] = {HRIR_48K_24bit::azi_241_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_241_0_ele_neg81_0_wav};
  irMap[242][0] = {HRIR_48K_24bit::azi_242_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_242_0_ele_0_0_wav};
  irMap[242][15] = {HRIR_48K_24bit::azi_242_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_242_0_ele_15_0_wav};
  irMap[242][25] = {HRIR_48K_24bit::azi_242_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_242_0_ele_25_0_wav};
  irMap[242][30] = {HRIR_48K_24bit::azi_242_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_242_0_ele_30_0_wav};
  irMap[242][45] = {HRIR_48K_24bit::azi_242_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_242_0_ele_45_0_wav};
  irMap[242][54] = {HRIR_48K_24bit::azi_242_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_242_0_ele_54_0_wav};
  irMap[242][60] = {HRIR_48K_24bit::azi_242_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_242_0_ele_60_0_wav};
  irMap[242][75] = {HRIR_48K_24bit::azi_242_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_242_0_ele_75_0_wav};
  irMap[242][90] = {HRIR_48K_24bit::azi_242_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_242_0_ele_90_0_wav};
  irMap[242][-15] = {HRIR_48K_24bit::azi_242_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_242_0_ele_neg15_0_wav};
  irMap[242][-25] = {HRIR_48K_24bit::azi_242_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_242_0_ele_neg25_0_wav};
  irMap[242][-30] = {HRIR_48K_24bit::azi_242_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_242_0_ele_neg30_0_wav};
  irMap[242][-45] = {HRIR_48K_24bit::azi_242_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_242_0_ele_neg45_0_wav};
  irMap[242][-54] = {HRIR_48K_24bit::azi_242_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_242_0_ele_neg54_0_wav};
  irMap[242][-60] = {HRIR_48K_24bit::azi_242_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_242_0_ele_neg60_0_wav};
  irMap[242][-75] = {HRIR_48K_24bit::azi_242_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_242_0_ele_neg75_0_wav};
  irMap[242][-81] = {HRIR_48K_24bit::azi_242_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_242_0_ele_neg81_0_wav};
  irMap[243][0] = {HRIR_48K_24bit::azi_243_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_243_0_ele_0_0_wav};
  irMap[243][15] = {HRIR_48K_24bit::azi_243_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_243_0_ele_15_0_wav};
  irMap[243][25] = {HRIR_48K_24bit::azi_243_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_243_0_ele_25_0_wav};
  irMap[243][30] = {HRIR_48K_24bit::azi_243_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_243_0_ele_30_0_wav};
  irMap[243][45] = {HRIR_48K_24bit::azi_243_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_243_0_ele_45_0_wav};
  irMap[243][54] = {HRIR_48K_24bit::azi_243_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_243_0_ele_54_0_wav};
  irMap[243][60] = {HRIR_48K_24bit::azi_243_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_243_0_ele_60_0_wav};
  irMap[243][75] = {HRIR_48K_24bit::azi_243_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_243_0_ele_75_0_wav};
  irMap[243][90] = {HRIR_48K_24bit::azi_243_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_243_0_ele_90_0_wav};
  irMap[243][-15] = {HRIR_48K_24bit::azi_243_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_243_0_ele_neg15_0_wav};
  irMap[243][-25] = {HRIR_48K_24bit::azi_243_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_243_0_ele_neg25_0_wav};
  irMap[243][-30] = {HRIR_48K_24bit::azi_243_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_243_0_ele_neg30_0_wav};
  irMap[243][-45] = {HRIR_48K_24bit::azi_243_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_243_0_ele_neg45_0_wav};
  irMap[243][-54] = {HRIR_48K_24bit::azi_243_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_243_0_ele_neg54_0_wav};
  irMap[243][-60] = {HRIR_48K_24bit::azi_243_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_243_0_ele_neg60_0_wav};
  irMap[243][-75] = {HRIR_48K_24bit::azi_243_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_243_0_ele_neg75_0_wav};
  irMap[243][-81] = {HRIR_48K_24bit::azi_243_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_243_0_ele_neg81_0_wav};
  irMap[244][0] = {HRIR_48K_24bit::azi_244_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_244_0_ele_0_0_wav};
  irMap[244][15] = {HRIR_48K_24bit::azi_244_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_244_0_ele_15_0_wav};
  irMap[244][25] = {HRIR_48K_24bit::azi_244_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_244_0_ele_25_0_wav};
  irMap[244][30] = {HRIR_48K_24bit::azi_244_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_244_0_ele_30_0_wav};
  irMap[244][45] = {HRIR_48K_24bit::azi_244_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_244_0_ele_45_0_wav};
  irMap[244][54] = {HRIR_48K_24bit::azi_244_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_244_0_ele_54_0_wav};
  irMap[244][60] = {HRIR_48K_24bit::azi_244_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_244_0_ele_60_0_wav};
  irMap[244][75] = {HRIR_48K_24bit::azi_244_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_244_0_ele_75_0_wav};
  irMap[244][90] = {HRIR_48K_24bit::azi_244_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_244_0_ele_90_0_wav};
  irMap[244][-15] = {HRIR_48K_24bit::azi_244_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_244_0_ele_neg15_0_wav};
  irMap[244][-25] = {HRIR_48K_24bit::azi_244_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_244_0_ele_neg25_0_wav};
  irMap[244][-30] = {HRIR_48K_24bit::azi_244_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_244_0_ele_neg30_0_wav};
  irMap[244][-45] = {HRIR_48K_24bit::azi_244_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_244_0_ele_neg45_0_wav};
  irMap[244][-54] = {HRIR_48K_24bit::azi_244_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_244_0_ele_neg54_0_wav};
  irMap[244][-60] = {HRIR_48K_24bit::azi_244_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_244_0_ele_neg60_0_wav};
  irMap[244][-75] = {HRIR_48K_24bit::azi_244_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_244_0_ele_neg75_0_wav};
  irMap[244][-81] = {HRIR_48K_24bit::azi_244_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_244_0_ele_neg81_0_wav};
  irMap[245][0] = {HRIR_48K_24bit::azi_245_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_245_0_ele_0_0_wav};
  irMap[245][15] = {HRIR_48K_24bit::azi_245_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_245_0_ele_15_0_wav};
  irMap[245][25] = {HRIR_48K_24bit::azi_245_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_245_0_ele_25_0_wav};
  irMap[245][30] = {HRIR_48K_24bit::azi_245_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_245_0_ele_30_0_wav};
  irMap[245][45] = {HRIR_48K_24bit::azi_245_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_245_0_ele_45_0_wav};
  irMap[245][54] = {HRIR_48K_24bit::azi_245_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_245_0_ele_54_0_wav};
  irMap[245][60] = {HRIR_48K_24bit::azi_245_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_245_0_ele_60_0_wav};
  irMap[245][75] = {HRIR_48K_24bit::azi_245_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_245_0_ele_75_0_wav};
  irMap[245][90] = {HRIR_48K_24bit::azi_245_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_245_0_ele_90_0_wav};
  irMap[245][-15] = {HRIR_48K_24bit::azi_245_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_245_0_ele_neg15_0_wav};
  irMap[245][-25] = {HRIR_48K_24bit::azi_245_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_245_0_ele_neg25_0_wav};
  irMap[245][-30] = {HRIR_48K_24bit::azi_245_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_245_0_ele_neg30_0_wav};
  irMap[245][-45] = {HRIR_48K_24bit::azi_245_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_245_0_ele_neg45_0_wav};
  irMap[245][-54] = {HRIR_48K_24bit::azi_245_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_245_0_ele_neg54_0_wav};
  irMap[245][-60] = {HRIR_48K_24bit::azi_245_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_245_0_ele_neg60_0_wav};
  irMap[245][-75] = {HRIR_48K_24bit::azi_245_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_245_0_ele_neg75_0_wav};
  irMap[245][-81] = {HRIR_48K_24bit::azi_245_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_245_0_ele_neg81_0_wav};
  irMap[246][0] = {HRIR_48K_24bit::azi_246_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_246_0_ele_0_0_wav};
  irMap[246][15] = {HRIR_48K_24bit::azi_246_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_246_0_ele_15_0_wav};
  irMap[246][25] = {HRIR_48K_24bit::azi_246_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_246_0_ele_25_0_wav};
  irMap[246][30] = {HRIR_48K_24bit::azi_246_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_246_0_ele_30_0_wav};
  irMap[246][45] = {HRIR_48K_24bit::azi_246_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_246_0_ele_45_0_wav};
  irMap[246][54] = {HRIR_48K_24bit::azi_246_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_246_0_ele_54_0_wav};
  irMap[246][60] = {HRIR_48K_24bit::azi_246_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_246_0_ele_60_0_wav};
  irMap[246][75] = {HRIR_48K_24bit::azi_246_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_246_0_ele_75_0_wav};
  irMap[246][90] = {HRIR_48K_24bit::azi_246_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_246_0_ele_90_0_wav};
  irMap[246][-15] = {HRIR_48K_24bit::azi_246_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_246_0_ele_neg15_0_wav};
  irMap[246][-25] = {HRIR_48K_24bit::azi_246_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_246_0_ele_neg25_0_wav};
  irMap[246][-30] = {HRIR_48K_24bit::azi_246_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_246_0_ele_neg30_0_wav};
  irMap[246][-45] = {HRIR_48K_24bit::azi_246_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_246_0_ele_neg45_0_wav};
  irMap[246][-54] = {HRIR_48K_24bit::azi_246_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_246_0_ele_neg54_0_wav};
  irMap[246][-60] = {HRIR_48K_24bit::azi_246_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_246_0_ele_neg60_0_wav};
  irMap[246][-75] = {HRIR_48K_24bit::azi_246_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_246_0_ele_neg75_0_wav};
  irMap[246][-81] = {HRIR_48K_24bit::azi_246_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_246_0_ele_neg81_0_wav};
  irMap[247][0] = {HRIR_48K_24bit::azi_247_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_247_0_ele_0_0_wav};
  irMap[247][15] = {HRIR_48K_24bit::azi_247_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_247_0_ele_15_0_wav};
  irMap[247][25] = {HRIR_48K_24bit::azi_247_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_247_0_ele_25_0_wav};
  irMap[247][30] = {HRIR_48K_24bit::azi_247_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_247_0_ele_30_0_wav};
  irMap[247][45] = {HRIR_48K_24bit::azi_247_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_247_0_ele_45_0_wav};
  irMap[247][54] = {HRIR_48K_24bit::azi_247_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_247_0_ele_54_0_wav};
  irMap[247][60] = {HRIR_48K_24bit::azi_247_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_247_0_ele_60_0_wav};
  irMap[247][75] = {HRIR_48K_24bit::azi_247_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_247_0_ele_75_0_wav};
  irMap[247][90] = {HRIR_48K_24bit::azi_247_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_247_0_ele_90_0_wav};
  irMap[247][-15] = {HRIR_48K_24bit::azi_247_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_247_0_ele_neg15_0_wav};
  irMap[247][-25] = {HRIR_48K_24bit::azi_247_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_247_0_ele_neg25_0_wav};
  irMap[247][-30] = {HRIR_48K_24bit::azi_247_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_247_0_ele_neg30_0_wav};
  irMap[247][-45] = {HRIR_48K_24bit::azi_247_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_247_0_ele_neg45_0_wav};
  irMap[247][-54] = {HRIR_48K_24bit::azi_247_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_247_0_ele_neg54_0_wav};
  irMap[247][-60] = {HRIR_48K_24bit::azi_247_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_247_0_ele_neg60_0_wav};
  irMap[247][-75] = {HRIR_48K_24bit::azi_247_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_247_0_ele_neg75_0_wav};
  irMap[247][-81] = {HRIR_48K_24bit::azi_247_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_247_0_ele_neg81_0_wav};
  irMap[248][0] = {HRIR_48K_24bit::azi_248_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_248_0_ele_0_0_wav};
  irMap[248][15] = {HRIR_48K_24bit::azi_248_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_248_0_ele_15_0_wav};
  irMap[248][25] = {HRIR_48K_24bit::azi_248_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_248_0_ele_25_0_wav};
  irMap[248][30] = {HRIR_48K_24bit::azi_248_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_248_0_ele_30_0_wav};
  irMap[248][45] = {HRIR_48K_24bit::azi_248_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_248_0_ele_45_0_wav};
  irMap[248][54] = {HRIR_48K_24bit::azi_248_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_248_0_ele_54_0_wav};
  irMap[248][60] = {HRIR_48K_24bit::azi_248_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_248_0_ele_60_0_wav};
  irMap[248][75] = {HRIR_48K_24bit::azi_248_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_248_0_ele_75_0_wav};
  irMap[248][90] = {HRIR_48K_24bit::azi_248_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_248_0_ele_90_0_wav};
  irMap[248][-15] = {HRIR_48K_24bit::azi_248_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_248_0_ele_neg15_0_wav};
  irMap[248][-25] = {HRIR_48K_24bit::azi_248_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_248_0_ele_neg25_0_wav};
  irMap[248][-30] = {HRIR_48K_24bit::azi_248_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_248_0_ele_neg30_0_wav};
  irMap[248][-45] = {HRIR_48K_24bit::azi_248_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_248_0_ele_neg45_0_wav};
  irMap[248][-54] = {HRIR_48K_24bit::azi_248_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_248_0_ele_neg54_0_wav};
  irMap[248][-60] = {HRIR_48K_24bit::azi_248_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_248_0_ele_neg60_0_wav};
  irMap[248][-75] = {HRIR_48K_24bit::azi_248_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_248_0_ele_neg75_0_wav};
  irMap[248][-81] = {HRIR_48K_24bit::azi_248_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_248_0_ele_neg81_0_wav};
  irMap[249][0] = {HRIR_48K_24bit::azi_249_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_249_0_ele_0_0_wav};
  irMap[249][15] = {HRIR_48K_24bit::azi_249_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_249_0_ele_15_0_wav};
  irMap[249][25] = {HRIR_48K_24bit::azi_249_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_249_0_ele_25_0_wav};
  irMap[249][30] = {HRIR_48K_24bit::azi_249_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_249_0_ele_30_0_wav};
  irMap[249][45] = {HRIR_48K_24bit::azi_249_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_249_0_ele_45_0_wav};
  irMap[249][54] = {HRIR_48K_24bit::azi_249_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_249_0_ele_54_0_wav};
  irMap[249][60] = {HRIR_48K_24bit::azi_249_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_249_0_ele_60_0_wav};
  irMap[249][75] = {HRIR_48K_24bit::azi_249_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_249_0_ele_75_0_wav};
  irMap[249][90] = {HRIR_48K_24bit::azi_249_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_249_0_ele_90_0_wav};
  irMap[249][-15] = {HRIR_48K_24bit::azi_249_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_249_0_ele_neg15_0_wav};
  irMap[249][-25] = {HRIR_48K_24bit::azi_249_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_249_0_ele_neg25_0_wav};
  irMap[249][-30] = {HRIR_48K_24bit::azi_249_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_249_0_ele_neg30_0_wav};
  irMap[249][-45] = {HRIR_48K_24bit::azi_249_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_249_0_ele_neg45_0_wav};
  irMap[249][-54] = {HRIR_48K_24bit::azi_249_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_249_0_ele_neg54_0_wav};
  irMap[249][-60] = {HRIR_48K_24bit::azi_249_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_249_0_ele_neg60_0_wav};
  irMap[249][-75] = {HRIR_48K_24bit::azi_249_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_249_0_ele_neg75_0_wav};
  irMap[249][-81] = {HRIR_48K_24bit::azi_249_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_249_0_ele_neg81_0_wav};
  irMap[250][0] = {HRIR_48K_24bit::azi_250_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_250_0_ele_0_0_wav};
  irMap[250][15] = {HRIR_48K_24bit::azi_250_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_250_0_ele_15_0_wav};
  irMap[250][25] = {HRIR_48K_24bit::azi_250_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_250_0_ele_25_0_wav};
  irMap[250][30] = {HRIR_48K_24bit::azi_250_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_250_0_ele_30_0_wav};
  irMap[250][45] = {HRIR_48K_24bit::azi_250_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_250_0_ele_45_0_wav};
  irMap[250][54] = {HRIR_48K_24bit::azi_250_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_250_0_ele_54_0_wav};
  irMap[250][60] = {HRIR_48K_24bit::azi_250_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_250_0_ele_60_0_wav};
  irMap[250][75] = {HRIR_48K_24bit::azi_250_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_250_0_ele_75_0_wav};
  irMap[250][90] = {HRIR_48K_24bit::azi_250_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_250_0_ele_90_0_wav};
  irMap[250][-15] = {HRIR_48K_24bit::azi_250_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_250_0_ele_neg15_0_wav};
  irMap[250][-25] = {HRIR_48K_24bit::azi_250_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_250_0_ele_neg25_0_wav};
  irMap[250][-30] = {HRIR_48K_24bit::azi_250_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_250_0_ele_neg30_0_wav};
  irMap[250][-45] = {HRIR_48K_24bit::azi_250_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_250_0_ele_neg45_0_wav};
  irMap[250][-54] = {HRIR_48K_24bit::azi_250_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_250_0_ele_neg54_0_wav};
  irMap[250][-60] = {HRIR_48K_24bit::azi_250_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_250_0_ele_neg60_0_wav};
  irMap[250][-75] = {HRIR_48K_24bit::azi_250_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_250_0_ele_neg75_0_wav};
  irMap[250][-81] = {HRIR_48K_24bit::azi_250_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_250_0_ele_neg81_0_wav};
  irMap[251][0] = {HRIR_48K_24bit::azi_251_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_251_0_ele_0_0_wav};
  irMap[251][15] = {HRIR_48K_24bit::azi_251_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_251_0_ele_15_0_wav};
  irMap[251][25] = {HRIR_48K_24bit::azi_251_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_251_0_ele_25_0_wav};
  irMap[251][30] = {HRIR_48K_24bit::azi_251_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_251_0_ele_30_0_wav};
  irMap[251][45] = {HRIR_48K_24bit::azi_251_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_251_0_ele_45_0_wav};
  irMap[251][54] = {HRIR_48K_24bit::azi_251_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_251_0_ele_54_0_wav};
  irMap[251][60] = {HRIR_48K_24bit::azi_251_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_251_0_ele_60_0_wav};
  irMap[251][75] = {HRIR_48K_24bit::azi_251_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_251_0_ele_75_0_wav};
  irMap[251][90] = {HRIR_48K_24bit::azi_251_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_251_0_ele_90_0_wav};
  irMap[251][-15] = {HRIR_48K_24bit::azi_251_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_251_0_ele_neg15_0_wav};
  irMap[251][-25] = {HRIR_48K_24bit::azi_251_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_251_0_ele_neg25_0_wav};
  irMap[251][-30] = {HRIR_48K_24bit::azi_251_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_251_0_ele_neg30_0_wav};
  irMap[251][-45] = {HRIR_48K_24bit::azi_251_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_251_0_ele_neg45_0_wav};
  irMap[251][-54] = {HRIR_48K_24bit::azi_251_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_251_0_ele_neg54_0_wav};
  irMap[251][-60] = {HRIR_48K_24bit::azi_251_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_251_0_ele_neg60_0_wav};
  irMap[251][-75] = {HRIR_48K_24bit::azi_251_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_251_0_ele_neg75_0_wav};
  irMap[251][-81] = {HRIR_48K_24bit::azi_251_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_251_0_ele_neg81_0_wav};
  irMap[252][0] = {HRIR_48K_24bit::azi_252_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_252_0_ele_0_0_wav};
  irMap[252][15] = {HRIR_48K_24bit::azi_252_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_252_0_ele_15_0_wav};
  irMap[252][25] = {HRIR_48K_24bit::azi_252_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_252_0_ele_25_0_wav};
  irMap[252][30] = {HRIR_48K_24bit::azi_252_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_252_0_ele_30_0_wav};
  irMap[252][45] = {HRIR_48K_24bit::azi_252_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_252_0_ele_45_0_wav};
  irMap[252][54] = {HRIR_48K_24bit::azi_252_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_252_0_ele_54_0_wav};
  irMap[252][60] = {HRIR_48K_24bit::azi_252_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_252_0_ele_60_0_wav};
  irMap[252][75] = {HRIR_48K_24bit::azi_252_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_252_0_ele_75_0_wav};
  irMap[252][90] = {HRIR_48K_24bit::azi_252_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_252_0_ele_90_0_wav};
  irMap[252][-15] = {HRIR_48K_24bit::azi_252_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_252_0_ele_neg15_0_wav};
  irMap[252][-25] = {HRIR_48K_24bit::azi_252_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_252_0_ele_neg25_0_wav};
  irMap[252][-30] = {HRIR_48K_24bit::azi_252_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_252_0_ele_neg30_0_wav};
  irMap[252][-45] = {HRIR_48K_24bit::azi_252_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_252_0_ele_neg45_0_wav};
  irMap[252][-54] = {HRIR_48K_24bit::azi_252_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_252_0_ele_neg54_0_wav};
  irMap[252][-60] = {HRIR_48K_24bit::azi_252_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_252_0_ele_neg60_0_wav};
  irMap[252][-75] = {HRIR_48K_24bit::azi_252_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_252_0_ele_neg75_0_wav};
  irMap[252][-81] = {HRIR_48K_24bit::azi_252_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_252_0_ele_neg81_0_wav};
  irMap[253][0] = {HRIR_48K_24bit::azi_253_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_253_0_ele_0_0_wav};
  irMap[253][15] = {HRIR_48K_24bit::azi_253_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_253_0_ele_15_0_wav};
  irMap[253][25] = {HRIR_48K_24bit::azi_253_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_253_0_ele_25_0_wav};
  irMap[253][30] = {HRIR_48K_24bit::azi_253_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_253_0_ele_30_0_wav};
  irMap[253][45] = {HRIR_48K_24bit::azi_253_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_253_0_ele_45_0_wav};
  irMap[253][54] = {HRIR_48K_24bit::azi_253_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_253_0_ele_54_0_wav};
  irMap[253][60] = {HRIR_48K_24bit::azi_253_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_253_0_ele_60_0_wav};
  irMap[253][75] = {HRIR_48K_24bit::azi_253_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_253_0_ele_75_0_wav};
  irMap[253][90] = {HRIR_48K_24bit::azi_253_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_253_0_ele_90_0_wav};
  irMap[253][-15] = {HRIR_48K_24bit::azi_253_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_253_0_ele_neg15_0_wav};
  irMap[253][-25] = {HRIR_48K_24bit::azi_253_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_253_0_ele_neg25_0_wav};
  irMap[253][-30] = {HRIR_48K_24bit::azi_253_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_253_0_ele_neg30_0_wav};
  irMap[253][-45] = {HRIR_48K_24bit::azi_253_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_253_0_ele_neg45_0_wav};
  irMap[253][-54] = {HRIR_48K_24bit::azi_253_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_253_0_ele_neg54_0_wav};
  irMap[253][-60] = {HRIR_48K_24bit::azi_253_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_253_0_ele_neg60_0_wav};
  irMap[253][-75] = {HRIR_48K_24bit::azi_253_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_253_0_ele_neg75_0_wav};
  irMap[253][-81] = {HRIR_48K_24bit::azi_253_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_253_0_ele_neg81_0_wav};
  irMap[254][0] = {HRIR_48K_24bit::azi_254_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_254_0_ele_0_0_wav};
  irMap[254][15] = {HRIR_48K_24bit::azi_254_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_254_0_ele_15_0_wav};
  irMap[254][25] = {HRIR_48K_24bit::azi_254_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_254_0_ele_25_0_wav};
  irMap[254][30] = {HRIR_48K_24bit::azi_254_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_254_0_ele_30_0_wav};
  irMap[254][45] = {HRIR_48K_24bit::azi_254_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_254_0_ele_45_0_wav};
  irMap[254][54] = {HRIR_48K_24bit::azi_254_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_254_0_ele_54_0_wav};
  irMap[254][60] = {HRIR_48K_24bit::azi_254_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_254_0_ele_60_0_wav};
  irMap[254][75] = {HRIR_48K_24bit::azi_254_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_254_0_ele_75_0_wav};
  irMap[254][90] = {HRIR_48K_24bit::azi_254_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_254_0_ele_90_0_wav};
  irMap[254][-15] = {HRIR_48K_24bit::azi_254_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_254_0_ele_neg15_0_wav};
  irMap[254][-25] = {HRIR_48K_24bit::azi_254_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_254_0_ele_neg25_0_wav};
  irMap[254][-30] = {HRIR_48K_24bit::azi_254_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_254_0_ele_neg30_0_wav};
  irMap[254][-45] = {HRIR_48K_24bit::azi_254_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_254_0_ele_neg45_0_wav};
  irMap[254][-54] = {HRIR_48K_24bit::azi_254_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_254_0_ele_neg54_0_wav};
  irMap[254][-60] = {HRIR_48K_24bit::azi_254_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_254_0_ele_neg60_0_wav};
  irMap[254][-75] = {HRIR_48K_24bit::azi_254_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_254_0_ele_neg75_0_wav};
  irMap[254][-81] = {HRIR_48K_24bit::azi_254_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_254_0_ele_neg81_0_wav};
  irMap[255][0] = {HRIR_48K_24bit::azi_255_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_255_0_ele_0_0_wav};
  irMap[255][15] = {HRIR_48K_24bit::azi_255_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_255_0_ele_15_0_wav};
  irMap[255][25] = {HRIR_48K_24bit::azi_255_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_255_0_ele_25_0_wav};
  irMap[255][30] = {HRIR_48K_24bit::azi_255_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_255_0_ele_30_0_wav};
  irMap[255][45] = {HRIR_48K_24bit::azi_255_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_255_0_ele_45_0_wav};
  irMap[255][54] = {HRIR_48K_24bit::azi_255_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_255_0_ele_54_0_wav};
  irMap[255][60] = {HRIR_48K_24bit::azi_255_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_255_0_ele_60_0_wav};
  irMap[255][75] = {HRIR_48K_24bit::azi_255_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_255_0_ele_75_0_wav};
  irMap[255][90] = {HRIR_48K_24bit::azi_255_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_255_0_ele_90_0_wav};
  irMap[255][-15] = {HRIR_48K_24bit::azi_255_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_255_0_ele_neg15_0_wav};
  irMap[255][-25] = {HRIR_48K_24bit::azi_255_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_255_0_ele_neg25_0_wav};
  irMap[255][-30] = {HRIR_48K_24bit::azi_255_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_255_0_ele_neg30_0_wav};
  irMap[255][-45] = {HRIR_48K_24bit::azi_255_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_255_0_ele_neg45_0_wav};
  irMap[255][-54] = {HRIR_48K_24bit::azi_255_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_255_0_ele_neg54_0_wav};
  irMap[255][-60] = {HRIR_48K_24bit::azi_255_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_255_0_ele_neg60_0_wav};
  irMap[255][-75] = {HRIR_48K_24bit::azi_255_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_255_0_ele_neg75_0_wav};
  irMap[255][-81] = {HRIR_48K_24bit::azi_255_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_255_0_ele_neg81_0_wav};
  irMap[256][0] = {HRIR_48K_24bit::azi_256_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_256_0_ele_0_0_wav};
  irMap[256][15] = {HRIR_48K_24bit::azi_256_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_256_0_ele_15_0_wav};
  irMap[256][25] = {HRIR_48K_24bit::azi_256_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_256_0_ele_25_0_wav};
  irMap[256][30] = {HRIR_48K_24bit::azi_256_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_256_0_ele_30_0_wav};
  irMap[256][45] = {HRIR_48K_24bit::azi_256_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_256_0_ele_45_0_wav};
  irMap[256][54] = {HRIR_48K_24bit::azi_256_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_256_0_ele_54_0_wav};
  irMap[256][60] = {HRIR_48K_24bit::azi_256_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_256_0_ele_60_0_wav};
  irMap[256][75] = {HRIR_48K_24bit::azi_256_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_256_0_ele_75_0_wav};
  irMap[256][90] = {HRIR_48K_24bit::azi_256_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_256_0_ele_90_0_wav};
  irMap[256][-15] = {HRIR_48K_24bit::azi_256_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_256_0_ele_neg15_0_wav};
  irMap[256][-25] = {HRIR_48K_24bit::azi_256_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_256_0_ele_neg25_0_wav};
  irMap[256][-30] = {HRIR_48K_24bit::azi_256_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_256_0_ele_neg30_0_wav};
  irMap[256][-45] = {HRIR_48K_24bit::azi_256_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_256_0_ele_neg45_0_wav};
  irMap[256][-54] = {HRIR_48K_24bit::azi_256_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_256_0_ele_neg54_0_wav};
  irMap[256][-60] = {HRIR_48K_24bit::azi_256_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_256_0_ele_neg60_0_wav};
  irMap[256][-75] = {HRIR_48K_24bit::azi_256_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_256_0_ele_neg75_0_wav};
  irMap[256][-81] = {HRIR_48K_24bit::azi_256_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_256_0_ele_neg81_0_wav};
  irMap[257][0] = {HRIR_48K_24bit::azi_257_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_257_0_ele_0_0_wav};
  irMap[257][15] = {HRIR_48K_24bit::azi_257_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_257_0_ele_15_0_wav};
  irMap[257][25] = {HRIR_48K_24bit::azi_257_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_257_0_ele_25_0_wav};
  irMap[257][30] = {HRIR_48K_24bit::azi_257_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_257_0_ele_30_0_wav};
  irMap[257][45] = {HRIR_48K_24bit::azi_257_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_257_0_ele_45_0_wav};
  irMap[257][54] = {HRIR_48K_24bit::azi_257_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_257_0_ele_54_0_wav};
  irMap[257][60] = {HRIR_48K_24bit::azi_257_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_257_0_ele_60_0_wav};
  irMap[257][75] = {HRIR_48K_24bit::azi_257_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_257_0_ele_75_0_wav};
  irMap[257][90] = {HRIR_48K_24bit::azi_257_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_257_0_ele_90_0_wav};
  irMap[257][-15] = {HRIR_48K_24bit::azi_257_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_257_0_ele_neg15_0_wav};
  irMap[257][-25] = {HRIR_48K_24bit::azi_257_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_257_0_ele_neg25_0_wav};
  irMap[257][-30] = {HRIR_48K_24bit::azi_257_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_257_0_ele_neg30_0_wav};
  irMap[257][-45] = {HRIR_48K_24bit::azi_257_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_257_0_ele_neg45_0_wav};
  irMap[257][-54] = {HRIR_48K_24bit::azi_257_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_257_0_ele_neg54_0_wav};
  irMap[257][-60] = {HRIR_48K_24bit::azi_257_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_257_0_ele_neg60_0_wav};
  irMap[257][-75] = {HRIR_48K_24bit::azi_257_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_257_0_ele_neg75_0_wav};
  irMap[257][-81] = {HRIR_48K_24bit::azi_257_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_257_0_ele_neg81_0_wav};
  irMap[258][0] = {HRIR_48K_24bit::azi_258_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_258_0_ele_0_0_wav};
  irMap[258][15] = {HRIR_48K_24bit::azi_258_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_258_0_ele_15_0_wav};
  irMap[258][25] = {HRIR_48K_24bit::azi_258_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_258_0_ele_25_0_wav};
  irMap[258][30] = {HRIR_48K_24bit::azi_258_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_258_0_ele_30_0_wav};
  irMap[258][45] = {HRIR_48K_24bit::azi_258_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_258_0_ele_45_0_wav};
  irMap[258][54] = {HRIR_48K_24bit::azi_258_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_258_0_ele_54_0_wav};
  irMap[258][60] = {HRIR_48K_24bit::azi_258_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_258_0_ele_60_0_wav};
  irMap[258][75] = {HRIR_48K_24bit::azi_258_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_258_0_ele_75_0_wav};
  irMap[258][90] = {HRIR_48K_24bit::azi_258_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_258_0_ele_90_0_wav};
  irMap[258][-15] = {HRIR_48K_24bit::azi_258_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_258_0_ele_neg15_0_wav};
  irMap[258][-25] = {HRIR_48K_24bit::azi_258_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_258_0_ele_neg25_0_wav};
  irMap[258][-30] = {HRIR_48K_24bit::azi_258_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_258_0_ele_neg30_0_wav};
  irMap[258][-45] = {HRIR_48K_24bit::azi_258_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_258_0_ele_neg45_0_wav};
  irMap[258][-54] = {HRIR_48K_24bit::azi_258_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_258_0_ele_neg54_0_wav};
  irMap[258][-60] = {HRIR_48K_24bit::azi_258_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_258_0_ele_neg60_0_wav};
  irMap[258][-75] = {HRIR_48K_24bit::azi_258_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_258_0_ele_neg75_0_wav};
  irMap[258][-81] = {HRIR_48K_24bit::azi_258_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_258_0_ele_neg81_0_wav};
  irMap[259][0] = {HRIR_48K_24bit::azi_259_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_259_0_ele_0_0_wav};
  irMap[259][15] = {HRIR_48K_24bit::azi_259_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_259_0_ele_15_0_wav};
  irMap[259][25] = {HRIR_48K_24bit::azi_259_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_259_0_ele_25_0_wav};
  irMap[259][30] = {HRIR_48K_24bit::azi_259_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_259_0_ele_30_0_wav};
  irMap[259][45] = {HRIR_48K_24bit::azi_259_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_259_0_ele_45_0_wav};
  irMap[259][54] = {HRIR_48K_24bit::azi_259_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_259_0_ele_54_0_wav};
  irMap[259][60] = {HRIR_48K_24bit::azi_259_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_259_0_ele_60_0_wav};
  irMap[259][75] = {HRIR_48K_24bit::azi_259_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_259_0_ele_75_0_wav};
  irMap[259][90] = {HRIR_48K_24bit::azi_259_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_259_0_ele_90_0_wav};
  irMap[259][-15] = {HRIR_48K_24bit::azi_259_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_259_0_ele_neg15_0_wav};
  irMap[259][-25] = {HRIR_48K_24bit::azi_259_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_259_0_ele_neg25_0_wav};
  irMap[259][-30] = {HRIR_48K_24bit::azi_259_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_259_0_ele_neg30_0_wav};
  irMap[259][-45] = {HRIR_48K_24bit::azi_259_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_259_0_ele_neg45_0_wav};
  irMap[259][-54] = {HRIR_48K_24bit::azi_259_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_259_0_ele_neg54_0_wav};
  irMap[259][-60] = {HRIR_48K_24bit::azi_259_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_259_0_ele_neg60_0_wav};
  irMap[259][-75] = {HRIR_48K_24bit::azi_259_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_259_0_ele_neg75_0_wav};
  irMap[259][-81] = {HRIR_48K_24bit::azi_259_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_259_0_ele_neg81_0_wav};
  irMap[260][0] = {HRIR_48K_24bit::azi_260_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_260_0_ele_0_0_wav};
  irMap[260][15] = {HRIR_48K_24bit::azi_260_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_260_0_ele_15_0_wav};
  irMap[260][25] = {HRIR_48K_24bit::azi_260_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_260_0_ele_25_0_wav};
  irMap[260][30] = {HRIR_48K_24bit::azi_260_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_260_0_ele_30_0_wav};
  irMap[260][45] = {HRIR_48K_24bit::azi_260_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_260_0_ele_45_0_wav};
  irMap[260][54] = {HRIR_48K_24bit::azi_260_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_260_0_ele_54_0_wav};
  irMap[260][60] = {HRIR_48K_24bit::azi_260_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_260_0_ele_60_0_wav};
  irMap[260][75] = {HRIR_48K_24bit::azi_260_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_260_0_ele_75_0_wav};
  irMap[260][90] = {HRIR_48K_24bit::azi_260_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_260_0_ele_90_0_wav};
  irMap[260][-15] = {HRIR_48K_24bit::azi_260_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_260_0_ele_neg15_0_wav};
  irMap[260][-25] = {HRIR_48K_24bit::azi_260_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_260_0_ele_neg25_0_wav};
  irMap[260][-30] = {HRIR_48K_24bit::azi_260_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_260_0_ele_neg30_0_wav};
  irMap[260][-45] = {HRIR_48K_24bit::azi_260_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_260_0_ele_neg45_0_wav};
  irMap[260][-54] = {HRIR_48K_24bit::azi_260_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_260_0_ele_neg54_0_wav};
  irMap[260][-60] = {HRIR_48K_24bit::azi_260_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_260_0_ele_neg60_0_wav};
  irMap[260][-75] = {HRIR_48K_24bit::azi_260_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_260_0_ele_neg75_0_wav};
  irMap[260][-81] = {HRIR_48K_24bit::azi_260_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_260_0_ele_neg81_0_wav};
  irMap[261][0] = {HRIR_48K_24bit::azi_261_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_261_0_ele_0_0_wav};
  irMap[261][15] = {HRIR_48K_24bit::azi_261_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_261_0_ele_15_0_wav};
  irMap[261][25] = {HRIR_48K_24bit::azi_261_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_261_0_ele_25_0_wav};
  irMap[261][30] = {HRIR_48K_24bit::azi_261_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_261_0_ele_30_0_wav};
  irMap[261][45] = {HRIR_48K_24bit::azi_261_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_261_0_ele_45_0_wav};
  irMap[261][54] = {HRIR_48K_24bit::azi_261_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_261_0_ele_54_0_wav};
  irMap[261][60] = {HRIR_48K_24bit::azi_261_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_261_0_ele_60_0_wav};
  irMap[261][75] = {HRIR_48K_24bit::azi_261_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_261_0_ele_75_0_wav};
  irMap[261][90] = {HRIR_48K_24bit::azi_261_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_261_0_ele_90_0_wav};
  irMap[261][-15] = {HRIR_48K_24bit::azi_261_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_261_0_ele_neg15_0_wav};
  irMap[261][-25] = {HRIR_48K_24bit::azi_261_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_261_0_ele_neg25_0_wav};
  irMap[261][-30] = {HRIR_48K_24bit::azi_261_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_261_0_ele_neg30_0_wav};
  irMap[261][-45] = {HRIR_48K_24bit::azi_261_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_261_0_ele_neg45_0_wav};
  irMap[261][-54] = {HRIR_48K_24bit::azi_261_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_261_0_ele_neg54_0_wav};
  irMap[261][-60] = {HRIR_48K_24bit::azi_261_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_261_0_ele_neg60_0_wav};
  irMap[261][-75] = {HRIR_48K_24bit::azi_261_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_261_0_ele_neg75_0_wav};
  irMap[261][-81] = {HRIR_48K_24bit::azi_261_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_261_0_ele_neg81_0_wav};
  irMap[262][0] = {HRIR_48K_24bit::azi_262_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_262_0_ele_0_0_wav};
  irMap[262][15] = {HRIR_48K_24bit::azi_262_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_262_0_ele_15_0_wav};
  irMap[262][25] = {HRIR_48K_24bit::azi_262_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_262_0_ele_25_0_wav};
  irMap[262][30] = {HRIR_48K_24bit::azi_262_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_262_0_ele_30_0_wav};
  irMap[262][45] = {HRIR_48K_24bit::azi_262_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_262_0_ele_45_0_wav};
  irMap[262][54] = {HRIR_48K_24bit::azi_262_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_262_0_ele_54_0_wav};
  irMap[262][60] = {HRIR_48K_24bit::azi_262_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_262_0_ele_60_0_wav};
  irMap[262][75] = {HRIR_48K_24bit::azi_262_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_262_0_ele_75_0_wav};
  irMap[262][90] = {HRIR_48K_24bit::azi_262_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_262_0_ele_90_0_wav};
  irMap[262][-15] = {HRIR_48K_24bit::azi_262_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_262_0_ele_neg15_0_wav};
  irMap[262][-25] = {HRIR_48K_24bit::azi_262_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_262_0_ele_neg25_0_wav};
  irMap[262][-30] = {HRIR_48K_24bit::azi_262_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_262_0_ele_neg30_0_wav};
  irMap[262][-45] = {HRIR_48K_24bit::azi_262_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_262_0_ele_neg45_0_wav};
  irMap[262][-54] = {HRIR_48K_24bit::azi_262_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_262_0_ele_neg54_0_wav};
  irMap[262][-60] = {HRIR_48K_24bit::azi_262_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_262_0_ele_neg60_0_wav};
  irMap[262][-75] = {HRIR_48K_24bit::azi_262_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_262_0_ele_neg75_0_wav};
  irMap[262][-81] = {HRIR_48K_24bit::azi_262_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_262_0_ele_neg81_0_wav};
  irMap[263][0] = {HRIR_48K_24bit::azi_263_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_263_0_ele_0_0_wav};
  irMap[263][15] = {HRIR_48K_24bit::azi_263_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_263_0_ele_15_0_wav};
  irMap[263][25] = {HRIR_48K_24bit::azi_263_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_263_0_ele_25_0_wav};
  irMap[263][30] = {HRIR_48K_24bit::azi_263_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_263_0_ele_30_0_wav};
  irMap[263][45] = {HRIR_48K_24bit::azi_263_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_263_0_ele_45_0_wav};
  irMap[263][54] = {HRIR_48K_24bit::azi_263_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_263_0_ele_54_0_wav};
  irMap[263][60] = {HRIR_48K_24bit::azi_263_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_263_0_ele_60_0_wav};
  irMap[263][75] = {HRIR_48K_24bit::azi_263_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_263_0_ele_75_0_wav};
  irMap[263][90] = {HRIR_48K_24bit::azi_263_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_263_0_ele_90_0_wav};
  irMap[263][-15] = {HRIR_48K_24bit::azi_263_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_263_0_ele_neg15_0_wav};
  irMap[263][-25] = {HRIR_48K_24bit::azi_263_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_263_0_ele_neg25_0_wav};
  irMap[263][-30] = {HRIR_48K_24bit::azi_263_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_263_0_ele_neg30_0_wav};
  irMap[263][-45] = {HRIR_48K_24bit::azi_263_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_263_0_ele_neg45_0_wav};
  irMap[263][-54] = {HRIR_48K_24bit::azi_263_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_263_0_ele_neg54_0_wav};
  irMap[263][-60] = {HRIR_48K_24bit::azi_263_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_263_0_ele_neg60_0_wav};
  irMap[263][-75] = {HRIR_48K_24bit::azi_263_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_263_0_ele_neg75_0_wav};
  irMap[263][-81] = {HRIR_48K_24bit::azi_263_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_263_0_ele_neg81_0_wav};
  irMap[264][0] = {HRIR_48K_24bit::azi_264_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_264_0_ele_0_0_wav};
  irMap[264][15] = {HRIR_48K_24bit::azi_264_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_264_0_ele_15_0_wav};
  irMap[264][25] = {HRIR_48K_24bit::azi_264_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_264_0_ele_25_0_wav};
  irMap[264][30] = {HRIR_48K_24bit::azi_264_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_264_0_ele_30_0_wav};
  irMap[264][45] = {HRIR_48K_24bit::azi_264_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_264_0_ele_45_0_wav};
  irMap[264][54] = {HRIR_48K_24bit::azi_264_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_264_0_ele_54_0_wav};
  irMap[264][60] = {HRIR_48K_24bit::azi_264_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_264_0_ele_60_0_wav};
  irMap[264][75] = {HRIR_48K_24bit::azi_264_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_264_0_ele_75_0_wav};
  irMap[264][90] = {HRIR_48K_24bit::azi_264_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_264_0_ele_90_0_wav};
  irMap[264][-15] = {HRIR_48K_24bit::azi_264_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_264_0_ele_neg15_0_wav};
  irMap[264][-25] = {HRIR_48K_24bit::azi_264_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_264_0_ele_neg25_0_wav};
  irMap[264][-30] = {HRIR_48K_24bit::azi_264_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_264_0_ele_neg30_0_wav};
  irMap[264][-45] = {HRIR_48K_24bit::azi_264_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_264_0_ele_neg45_0_wav};
  irMap[264][-54] = {HRIR_48K_24bit::azi_264_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_264_0_ele_neg54_0_wav};
  irMap[264][-60] = {HRIR_48K_24bit::azi_264_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_264_0_ele_neg60_0_wav};
  irMap[264][-75] = {HRIR_48K_24bit::azi_264_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_264_0_ele_neg75_0_wav};
  irMap[264][-81] = {HRIR_48K_24bit::azi_264_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_264_0_ele_neg81_0_wav};
  irMap[265][0] = {HRIR_48K_24bit::azi_265_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_265_0_ele_0_0_wav};
  irMap[265][15] = {HRIR_48K_24bit::azi_265_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_265_0_ele_15_0_wav};
  irMap[265][25] = {HRIR_48K_24bit::azi_265_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_265_0_ele_25_0_wav};
  irMap[265][30] = {HRIR_48K_24bit::azi_265_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_265_0_ele_30_0_wav};
  irMap[265][45] = {HRIR_48K_24bit::azi_265_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_265_0_ele_45_0_wav};
  irMap[265][54] = {HRIR_48K_24bit::azi_265_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_265_0_ele_54_0_wav};
  irMap[265][60] = {HRIR_48K_24bit::azi_265_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_265_0_ele_60_0_wav};
  irMap[265][75] = {HRIR_48K_24bit::azi_265_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_265_0_ele_75_0_wav};
  irMap[265][90] = {HRIR_48K_24bit::azi_265_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_265_0_ele_90_0_wav};
  irMap[265][-15] = {HRIR_48K_24bit::azi_265_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_265_0_ele_neg15_0_wav};
  irMap[265][-25] = {HRIR_48K_24bit::azi_265_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_265_0_ele_neg25_0_wav};
  irMap[265][-30] = {HRIR_48K_24bit::azi_265_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_265_0_ele_neg30_0_wav};
  irMap[265][-45] = {HRIR_48K_24bit::azi_265_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_265_0_ele_neg45_0_wav};
  irMap[265][-54] = {HRIR_48K_24bit::azi_265_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_265_0_ele_neg54_0_wav};
  irMap[265][-60] = {HRIR_48K_24bit::azi_265_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_265_0_ele_neg60_0_wav};
  irMap[265][-75] = {HRIR_48K_24bit::azi_265_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_265_0_ele_neg75_0_wav};
  irMap[265][-81] = {HRIR_48K_24bit::azi_265_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_265_0_ele_neg81_0_wav};
  irMap[266][0] = {HRIR_48K_24bit::azi_266_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_266_0_ele_0_0_wav};
  irMap[266][15] = {HRIR_48K_24bit::azi_266_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_266_0_ele_15_0_wav};
  irMap[266][25] = {HRIR_48K_24bit::azi_266_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_266_0_ele_25_0_wav};
  irMap[266][30] = {HRIR_48K_24bit::azi_266_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_266_0_ele_30_0_wav};
  irMap[266][45] = {HRIR_48K_24bit::azi_266_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_266_0_ele_45_0_wav};
  irMap[266][54] = {HRIR_48K_24bit::azi_266_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_266_0_ele_54_0_wav};
  irMap[266][60] = {HRIR_48K_24bit::azi_266_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_266_0_ele_60_0_wav};
  irMap[266][75] = {HRIR_48K_24bit::azi_266_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_266_0_ele_75_0_wav};
  irMap[266][90] = {HRIR_48K_24bit::azi_266_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_266_0_ele_90_0_wav};
  irMap[266][-15] = {HRIR_48K_24bit::azi_266_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_266_0_ele_neg15_0_wav};
  irMap[266][-25] = {HRIR_48K_24bit::azi_266_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_266_0_ele_neg25_0_wav};
  irMap[266][-30] = {HRIR_48K_24bit::azi_266_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_266_0_ele_neg30_0_wav};
  irMap[266][-45] = {HRIR_48K_24bit::azi_266_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_266_0_ele_neg45_0_wav};
  irMap[266][-54] = {HRIR_48K_24bit::azi_266_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_266_0_ele_neg54_0_wav};
  irMap[266][-60] = {HRIR_48K_24bit::azi_266_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_266_0_ele_neg60_0_wav};
  irMap[266][-75] = {HRIR_48K_24bit::azi_266_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_266_0_ele_neg75_0_wav};
  irMap[266][-81] = {HRIR_48K_24bit::azi_266_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_266_0_ele_neg81_0_wav};
  irMap[267][0] = {HRIR_48K_24bit::azi_267_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_267_0_ele_0_0_wav};
  irMap[267][15] = {HRIR_48K_24bit::azi_267_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_267_0_ele_15_0_wav};
  irMap[267][25] = {HRIR_48K_24bit::azi_267_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_267_0_ele_25_0_wav};
  irMap[267][30] = {HRIR_48K_24bit::azi_267_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_267_0_ele_30_0_wav};
  irMap[267][45] = {HRIR_48K_24bit::azi_267_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_267_0_ele_45_0_wav};
  irMap[267][54] = {HRIR_48K_24bit::azi_267_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_267_0_ele_54_0_wav};
  irMap[267][60] = {HRIR_48K_24bit::azi_267_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_267_0_ele_60_0_wav};
  irMap[267][75] = {HRIR_48K_24bit::azi_267_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_267_0_ele_75_0_wav};
  irMap[267][90] = {HRIR_48K_24bit::azi_267_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_267_0_ele_90_0_wav};
  irMap[267][-15] = {HRIR_48K_24bit::azi_267_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_267_0_ele_neg15_0_wav};
  irMap[267][-25] = {HRIR_48K_24bit::azi_267_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_267_0_ele_neg25_0_wav};
  irMap[267][-30] = {HRIR_48K_24bit::azi_267_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_267_0_ele_neg30_0_wav};
  irMap[267][-45] = {HRIR_48K_24bit::azi_267_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_267_0_ele_neg45_0_wav};
  irMap[267][-54] = {HRIR_48K_24bit::azi_267_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_267_0_ele_neg54_0_wav};
  irMap[267][-60] = {HRIR_48K_24bit::azi_267_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_267_0_ele_neg60_0_wav};
  irMap[267][-75] = {HRIR_48K_24bit::azi_267_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_267_0_ele_neg75_0_wav};
  irMap[267][-81] = {HRIR_48K_24bit::azi_267_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_267_0_ele_neg81_0_wav};
  irMap[268][0] = {HRIR_48K_24bit::azi_268_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_268_0_ele_0_0_wav};
  irMap[268][15] = {HRIR_48K_24bit::azi_268_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_268_0_ele_15_0_wav};
  irMap[268][25] = {HRIR_48K_24bit::azi_268_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_268_0_ele_25_0_wav};
  irMap[268][30] = {HRIR_48K_24bit::azi_268_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_268_0_ele_30_0_wav};
  irMap[268][45] = {HRIR_48K_24bit::azi_268_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_268_0_ele_45_0_wav};
  irMap[268][54] = {HRIR_48K_24bit::azi_268_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_268_0_ele_54_0_wav};
  irMap[268][60] = {HRIR_48K_24bit::azi_268_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_268_0_ele_60_0_wav};
  irMap[268][75] = {HRIR_48K_24bit::azi_268_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_268_0_ele_75_0_wav};
  irMap[268][90] = {HRIR_48K_24bit::azi_268_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_268_0_ele_90_0_wav};
  irMap[268][-15] = {HRIR_48K_24bit::azi_268_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_268_0_ele_neg15_0_wav};
  irMap[268][-25] = {HRIR_48K_24bit::azi_268_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_268_0_ele_neg25_0_wav};
  irMap[268][-30] = {HRIR_48K_24bit::azi_268_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_268_0_ele_neg30_0_wav};
  irMap[268][-45] = {HRIR_48K_24bit::azi_268_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_268_0_ele_neg45_0_wav};
  irMap[268][-54] = {HRIR_48K_24bit::azi_268_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_268_0_ele_neg54_0_wav};
  irMap[268][-60] = {HRIR_48K_24bit::azi_268_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_268_0_ele_neg60_0_wav};
  irMap[268][-75] = {HRIR_48K_24bit::azi_268_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_268_0_ele_neg75_0_wav};
  irMap[268][-81] = {HRIR_48K_24bit::azi_268_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_268_0_ele_neg81_0_wav};
  irMap[269][0] = {HRIR_48K_24bit::azi_269_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_269_0_ele_0_0_wav};
  irMap[269][15] = {HRIR_48K_24bit::azi_269_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_269_0_ele_15_0_wav};
  irMap[269][25] = {HRIR_48K_24bit::azi_269_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_269_0_ele_25_0_wav};
  irMap[269][30] = {HRIR_48K_24bit::azi_269_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_269_0_ele_30_0_wav};
  irMap[269][45] = {HRIR_48K_24bit::azi_269_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_269_0_ele_45_0_wav};
  irMap[269][54] = {HRIR_48K_24bit::azi_269_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_269_0_ele_54_0_wav};
  irMap[269][60] = {HRIR_48K_24bit::azi_269_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_269_0_ele_60_0_wav};
  irMap[269][75] = {HRIR_48K_24bit::azi_269_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_269_0_ele_75_0_wav};
  irMap[269][90] = {HRIR_48K_24bit::azi_269_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_269_0_ele_90_0_wav};
  irMap[269][-15] = {HRIR_48K_24bit::azi_269_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_269_0_ele_neg15_0_wav};
  irMap[269][-25] = {HRIR_48K_24bit::azi_269_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_269_0_ele_neg25_0_wav};
  irMap[269][-30] = {HRIR_48K_24bit::azi_269_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_269_0_ele_neg30_0_wav};
  irMap[269][-45] = {HRIR_48K_24bit::azi_269_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_269_0_ele_neg45_0_wav};
  irMap[269][-54] = {HRIR_48K_24bit::azi_269_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_269_0_ele_neg54_0_wav};
  irMap[269][-60] = {HRIR_48K_24bit::azi_269_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_269_0_ele_neg60_0_wav};
  irMap[269][-75] = {HRIR_48K_24bit::azi_269_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_269_0_ele_neg75_0_wav};
  irMap[269][-81] = {HRIR_48K_24bit::azi_269_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_269_0_ele_neg81_0_wav};
  irMap[270][0] = {HRIR_48K_24bit::azi_270_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_270_0_ele_0_0_wav};
  irMap[270][15] = {HRIR_48K_24bit::azi_270_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_270_0_ele_15_0_wav};
  irMap[270][25] = {HRIR_48K_24bit::azi_270_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_270_0_ele_25_0_wav};
  irMap[270][30] = {HRIR_48K_24bit::azi_270_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_270_0_ele_30_0_wav};
  irMap[270][45] = {HRIR_48K_24bit::azi_270_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_270_0_ele_45_0_wav};
  irMap[270][54] = {HRIR_48K_24bit::azi_270_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_270_0_ele_54_0_wav};
  irMap[270][60] = {HRIR_48K_24bit::azi_270_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_270_0_ele_60_0_wav};
  irMap[270][75] = {HRIR_48K_24bit::azi_270_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_270_0_ele_75_0_wav};
  irMap[270][90] = {HRIR_48K_24bit::azi_270_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_270_0_ele_90_0_wav};
  irMap[270][-15] = {HRIR_48K_24bit::azi_270_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_270_0_ele_neg15_0_wav};
  irMap[270][-25] = {HRIR_48K_24bit::azi_270_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_270_0_ele_neg25_0_wav};
  irMap[270][-30] = {HRIR_48K_24bit::azi_270_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_270_0_ele_neg30_0_wav};
  irMap[270][-45] = {HRIR_48K_24bit::azi_270_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_270_0_ele_neg45_0_wav};
  irMap[270][-54] = {HRIR_48K_24bit::azi_270_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_270_0_ele_neg54_0_wav};
  irMap[270][-60] = {HRIR_48K_24bit::azi_270_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_270_0_ele_neg60_0_wav};
  irMap[270][-75] = {HRIR_48K_24bit::azi_270_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_270_0_ele_neg75_0_wav};
  irMap[270][-81] = {HRIR_48K_24bit::azi_270_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_270_0_ele_neg81_0_wav};
  irMap[271][0] = {HRIR_48K_24bit::azi_271_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_271_0_ele_0_0_wav};
  irMap[271][15] = {HRIR_48K_24bit::azi_271_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_271_0_ele_15_0_wav};
  irMap[271][25] = {HRIR_48K_24bit::azi_271_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_271_0_ele_25_0_wav};
  irMap[271][30] = {HRIR_48K_24bit::azi_271_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_271_0_ele_30_0_wav};
  irMap[271][45] = {HRIR_48K_24bit::azi_271_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_271_0_ele_45_0_wav};
  irMap[271][54] = {HRIR_48K_24bit::azi_271_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_271_0_ele_54_0_wav};
  irMap[271][60] = {HRIR_48K_24bit::azi_271_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_271_0_ele_60_0_wav};
  irMap[271][75] = {HRIR_48K_24bit::azi_271_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_271_0_ele_75_0_wav};
  irMap[271][90] = {HRIR_48K_24bit::azi_271_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_271_0_ele_90_0_wav};
  irMap[271][-15] = {HRIR_48K_24bit::azi_271_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_271_0_ele_neg15_0_wav};
  irMap[271][-25] = {HRIR_48K_24bit::azi_271_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_271_0_ele_neg25_0_wav};
  irMap[271][-30] = {HRIR_48K_24bit::azi_271_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_271_0_ele_neg30_0_wav};
  irMap[271][-45] = {HRIR_48K_24bit::azi_271_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_271_0_ele_neg45_0_wav};
  irMap[271][-54] = {HRIR_48K_24bit::azi_271_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_271_0_ele_neg54_0_wav};
  irMap[271][-60] = {HRIR_48K_24bit::azi_271_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_271_0_ele_neg60_0_wav};
  irMap[271][-75] = {HRIR_48K_24bit::azi_271_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_271_0_ele_neg75_0_wav};
  irMap[271][-81] = {HRIR_48K_24bit::azi_271_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_271_0_ele_neg81_0_wav};
  irMap[272][0] = {HRIR_48K_24bit::azi_272_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_272_0_ele_0_0_wav};
  irMap[272][15] = {HRIR_48K_24bit::azi_272_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_272_0_ele_15_0_wav};
  irMap[272][25] = {HRIR_48K_24bit::azi_272_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_272_0_ele_25_0_wav};
  irMap[272][30] = {HRIR_48K_24bit::azi_272_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_272_0_ele_30_0_wav};
  irMap[272][45] = {HRIR_48K_24bit::azi_272_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_272_0_ele_45_0_wav};
  irMap[272][54] = {HRIR_48K_24bit::azi_272_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_272_0_ele_54_0_wav};
  irMap[272][60] = {HRIR_48K_24bit::azi_272_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_272_0_ele_60_0_wav};
  irMap[272][75] = {HRIR_48K_24bit::azi_272_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_272_0_ele_75_0_wav};
  irMap[272][90] = {HRIR_48K_24bit::azi_272_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_272_0_ele_90_0_wav};
  irMap[272][-15] = {HRIR_48K_24bit::azi_272_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_272_0_ele_neg15_0_wav};
  irMap[272][-25] = {HRIR_48K_24bit::azi_272_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_272_0_ele_neg25_0_wav};
  irMap[272][-30] = {HRIR_48K_24bit::azi_272_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_272_0_ele_neg30_0_wav};
  irMap[272][-45] = {HRIR_48K_24bit::azi_272_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_272_0_ele_neg45_0_wav};
  irMap[272][-54] = {HRIR_48K_24bit::azi_272_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_272_0_ele_neg54_0_wav};
  irMap[272][-60] = {HRIR_48K_24bit::azi_272_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_272_0_ele_neg60_0_wav};
  irMap[272][-75] = {HRIR_48K_24bit::azi_272_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_272_0_ele_neg75_0_wav};
  irMap[272][-81] = {HRIR_48K_24bit::azi_272_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_272_0_ele_neg81_0_wav};
  irMap[273][0] = {HRIR_48K_24bit::azi_273_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_273_0_ele_0_0_wav};
  irMap[273][15] = {HRIR_48K_24bit::azi_273_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_273_0_ele_15_0_wav};
  irMap[273][25] = {HRIR_48K_24bit::azi_273_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_273_0_ele_25_0_wav};
  irMap[273][30] = {HRIR_48K_24bit::azi_273_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_273_0_ele_30_0_wav};
  irMap[273][45] = {HRIR_48K_24bit::azi_273_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_273_0_ele_45_0_wav};
  irMap[273][54] = {HRIR_48K_24bit::azi_273_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_273_0_ele_54_0_wav};
  irMap[273][60] = {HRIR_48K_24bit::azi_273_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_273_0_ele_60_0_wav};
  irMap[273][75] = {HRIR_48K_24bit::azi_273_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_273_0_ele_75_0_wav};
  irMap[273][90] = {HRIR_48K_24bit::azi_273_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_273_0_ele_90_0_wav};
  irMap[273][-15] = {HRIR_48K_24bit::azi_273_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_273_0_ele_neg15_0_wav};
  irMap[273][-25] = {HRIR_48K_24bit::azi_273_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_273_0_ele_neg25_0_wav};
  irMap[273][-30] = {HRIR_48K_24bit::azi_273_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_273_0_ele_neg30_0_wav};
  irMap[273][-45] = {HRIR_48K_24bit::azi_273_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_273_0_ele_neg45_0_wav};
  irMap[273][-54] = {HRIR_48K_24bit::azi_273_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_273_0_ele_neg54_0_wav};
  irMap[273][-60] = {HRIR_48K_24bit::azi_273_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_273_0_ele_neg60_0_wav};
  irMap[273][-75] = {HRIR_48K_24bit::azi_273_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_273_0_ele_neg75_0_wav};
  irMap[273][-81] = {HRIR_48K_24bit::azi_273_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_273_0_ele_neg81_0_wav};
  irMap[274][0] = {HRIR_48K_24bit::azi_274_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_274_0_ele_0_0_wav};
  irMap[274][15] = {HRIR_48K_24bit::azi_274_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_274_0_ele_15_0_wav};
  irMap[274][25] = {HRIR_48K_24bit::azi_274_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_274_0_ele_25_0_wav};
  irMap[274][30] = {HRIR_48K_24bit::azi_274_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_274_0_ele_30_0_wav};
  irMap[274][45] = {HRIR_48K_24bit::azi_274_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_274_0_ele_45_0_wav};
  irMap[274][54] = {HRIR_48K_24bit::azi_274_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_274_0_ele_54_0_wav};
  irMap[274][60] = {HRIR_48K_24bit::azi_274_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_274_0_ele_60_0_wav};
  irMap[274][75] = {HRIR_48K_24bit::azi_274_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_274_0_ele_75_0_wav};
  irMap[274][90] = {HRIR_48K_24bit::azi_274_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_274_0_ele_90_0_wav};
  irMap[274][-15] = {HRIR_48K_24bit::azi_274_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_274_0_ele_neg15_0_wav};
  irMap[274][-25] = {HRIR_48K_24bit::azi_274_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_274_0_ele_neg25_0_wav};
  irMap[274][-30] = {HRIR_48K_24bit::azi_274_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_274_0_ele_neg30_0_wav};
  irMap[274][-45] = {HRIR_48K_24bit::azi_274_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_274_0_ele_neg45_0_wav};
  irMap[274][-54] = {HRIR_48K_24bit::azi_274_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_274_0_ele_neg54_0_wav};
  irMap[274][-60] = {HRIR_48K_24bit::azi_274_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_274_0_ele_neg60_0_wav};
  irMap[274][-75] = {HRIR_48K_24bit::azi_274_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_274_0_ele_neg75_0_wav};
  irMap[274][-81] = {HRIR_48K_24bit::azi_274_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_274_0_ele_neg81_0_wav};
  irMap[275][0] = {HRIR_48K_24bit::azi_275_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_275_0_ele_0_0_wav};
  irMap[275][15] = {HRIR_48K_24bit::azi_275_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_275_0_ele_15_0_wav};
  irMap[275][25] = {HRIR_48K_24bit::azi_275_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_275_0_ele_25_0_wav};
  irMap[275][30] = {HRIR_48K_24bit::azi_275_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_275_0_ele_30_0_wav};
  irMap[275][45] = {HRIR_48K_24bit::azi_275_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_275_0_ele_45_0_wav};
  irMap[275][54] = {HRIR_48K_24bit::azi_275_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_275_0_ele_54_0_wav};
  irMap[275][60] = {HRIR_48K_24bit::azi_275_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_275_0_ele_60_0_wav};
  irMap[275][75] = {HRIR_48K_24bit::azi_275_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_275_0_ele_75_0_wav};
  irMap[275][90] = {HRIR_48K_24bit::azi_275_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_275_0_ele_90_0_wav};
  irMap[275][-15] = {HRIR_48K_24bit::azi_275_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_275_0_ele_neg15_0_wav};
  irMap[275][-25] = {HRIR_48K_24bit::azi_275_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_275_0_ele_neg25_0_wav};
  irMap[275][-30] = {HRIR_48K_24bit::azi_275_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_275_0_ele_neg30_0_wav};
  irMap[275][-45] = {HRIR_48K_24bit::azi_275_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_275_0_ele_neg45_0_wav};
  irMap[275][-54] = {HRIR_48K_24bit::azi_275_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_275_0_ele_neg54_0_wav};
  irMap[275][-60] = {HRIR_48K_24bit::azi_275_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_275_0_ele_neg60_0_wav};
  irMap[275][-75] = {HRIR_48K_24bit::azi_275_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_275_0_ele_neg75_0_wav};
  irMap[275][-81] = {HRIR_48K_24bit::azi_275_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_275_0_ele_neg81_0_wav};
  irMap[276][0] = {HRIR_48K_24bit::azi_276_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_276_0_ele_0_0_wav};
  irMap[276][15] = {HRIR_48K_24bit::azi_276_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_276_0_ele_15_0_wav};
  irMap[276][25] = {HRIR_48K_24bit::azi_276_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_276_0_ele_25_0_wav};
  irMap[276][30] = {HRIR_48K_24bit::azi_276_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_276_0_ele_30_0_wav};
  irMap[276][45] = {HRIR_48K_24bit::azi_276_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_276_0_ele_45_0_wav};
  irMap[276][54] = {HRIR_48K_24bit::azi_276_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_276_0_ele_54_0_wav};
  irMap[276][60] = {HRIR_48K_24bit::azi_276_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_276_0_ele_60_0_wav};
  irMap[276][75] = {HRIR_48K_24bit::azi_276_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_276_0_ele_75_0_wav};
  irMap[276][90] = {HRIR_48K_24bit::azi_276_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_276_0_ele_90_0_wav};
  irMap[276][-15] = {HRIR_48K_24bit::azi_276_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_276_0_ele_neg15_0_wav};
  irMap[276][-25] = {HRIR_48K_24bit::azi_276_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_276_0_ele_neg25_0_wav};
  irMap[276][-30] = {HRIR_48K_24bit::azi_276_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_276_0_ele_neg30_0_wav};
  irMap[276][-45] = {HRIR_48K_24bit::azi_276_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_276_0_ele_neg45_0_wav};
  irMap[276][-54] = {HRIR_48K_24bit::azi_276_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_276_0_ele_neg54_0_wav};
  irMap[276][-60] = {HRIR_48K_24bit::azi_276_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_276_0_ele_neg60_0_wav};
  irMap[276][-75] = {HRIR_48K_24bit::azi_276_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_276_0_ele_neg75_0_wav};
  irMap[276][-81] = {HRIR_48K_24bit::azi_276_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_276_0_ele_neg81_0_wav};
  irMap[277][0] = {HRIR_48K_24bit::azi_277_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_277_0_ele_0_0_wav};
  irMap[277][15] = {HRIR_48K_24bit::azi_277_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_277_0_ele_15_0_wav};
  irMap[277][25] = {HRIR_48K_24bit::azi_277_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_277_0_ele_25_0_wav};
  irMap[277][30] = {HRIR_48K_24bit::azi_277_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_277_0_ele_30_0_wav};
  irMap[277][45] = {HRIR_48K_24bit::azi_277_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_277_0_ele_45_0_wav};
  irMap[277][54] = {HRIR_48K_24bit::azi_277_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_277_0_ele_54_0_wav};
  irMap[277][60] = {HRIR_48K_24bit::azi_277_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_277_0_ele_60_0_wav};
  irMap[277][75] = {HRIR_48K_24bit::azi_277_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_277_0_ele_75_0_wav};
  irMap[277][90] = {HRIR_48K_24bit::azi_277_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_277_0_ele_90_0_wav};
  irMap[277][-15] = {HRIR_48K_24bit::azi_277_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_277_0_ele_neg15_0_wav};
  irMap[277][-25] = {HRIR_48K_24bit::azi_277_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_277_0_ele_neg25_0_wav};
  irMap[277][-30] = {HRIR_48K_24bit::azi_277_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_277_0_ele_neg30_0_wav};
  irMap[277][-45] = {HRIR_48K_24bit::azi_277_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_277_0_ele_neg45_0_wav};
  irMap[277][-54] = {HRIR_48K_24bit::azi_277_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_277_0_ele_neg54_0_wav};
  irMap[277][-60] = {HRIR_48K_24bit::azi_277_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_277_0_ele_neg60_0_wav};
  irMap[277][-75] = {HRIR_48K_24bit::azi_277_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_277_0_ele_neg75_0_wav};
  irMap[277][-81] = {HRIR_48K_24bit::azi_277_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_277_0_ele_neg81_0_wav};
  irMap[278][0] = {HRIR_48K_24bit::azi_278_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_278_0_ele_0_0_wav};
  irMap[278][15] = {HRIR_48K_24bit::azi_278_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_278_0_ele_15_0_wav};
  irMap[278][25] = {HRIR_48K_24bit::azi_278_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_278_0_ele_25_0_wav};
  irMap[278][30] = {HRIR_48K_24bit::azi_278_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_278_0_ele_30_0_wav};
  irMap[278][45] = {HRIR_48K_24bit::azi_278_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_278_0_ele_45_0_wav};
  irMap[278][54] = {HRIR_48K_24bit::azi_278_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_278_0_ele_54_0_wav};
  irMap[278][60] = {HRIR_48K_24bit::azi_278_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_278_0_ele_60_0_wav};
  irMap[278][75] = {HRIR_48K_24bit::azi_278_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_278_0_ele_75_0_wav};
  irMap[278][90] = {HRIR_48K_24bit::azi_278_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_278_0_ele_90_0_wav};
  irMap[278][-15] = {HRIR_48K_24bit::azi_278_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_278_0_ele_neg15_0_wav};
  irMap[278][-25] = {HRIR_48K_24bit::azi_278_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_278_0_ele_neg25_0_wav};
  irMap[278][-30] = {HRIR_48K_24bit::azi_278_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_278_0_ele_neg30_0_wav};
  irMap[278][-45] = {HRIR_48K_24bit::azi_278_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_278_0_ele_neg45_0_wav};
  irMap[278][-54] = {HRIR_48K_24bit::azi_278_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_278_0_ele_neg54_0_wav};
  irMap[278][-60] = {HRIR_48K_24bit::azi_278_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_278_0_ele_neg60_0_wav};
  irMap[278][-75] = {HRIR_48K_24bit::azi_278_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_278_0_ele_neg75_0_wav};
  irMap[278][-81] = {HRIR_48K_24bit::azi_278_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_278_0_ele_neg81_0_wav};
  irMap[279][0] = {HRIR_48K_24bit::azi_279_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_279_0_ele_0_0_wav};
  irMap[279][15] = {HRIR_48K_24bit::azi_279_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_279_0_ele_15_0_wav};
  irMap[279][25] = {HRIR_48K_24bit::azi_279_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_279_0_ele_25_0_wav};
  irMap[279][30] = {HRIR_48K_24bit::azi_279_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_279_0_ele_30_0_wav};
  irMap[279][45] = {HRIR_48K_24bit::azi_279_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_279_0_ele_45_0_wav};
  irMap[279][54] = {HRIR_48K_24bit::azi_279_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_279_0_ele_54_0_wav};
  irMap[279][60] = {HRIR_48K_24bit::azi_279_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_279_0_ele_60_0_wav};
  irMap[279][75] = {HRIR_48K_24bit::azi_279_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_279_0_ele_75_0_wav};
  irMap[279][90] = {HRIR_48K_24bit::azi_279_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_279_0_ele_90_0_wav};
  irMap[279][-15] = {HRIR_48K_24bit::azi_279_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_279_0_ele_neg15_0_wav};
  irMap[279][-25] = {HRIR_48K_24bit::azi_279_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_279_0_ele_neg25_0_wav};
  irMap[279][-30] = {HRIR_48K_24bit::azi_279_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_279_0_ele_neg30_0_wav};
  irMap[279][-45] = {HRIR_48K_24bit::azi_279_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_279_0_ele_neg45_0_wav};
  irMap[279][-54] = {HRIR_48K_24bit::azi_279_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_279_0_ele_neg54_0_wav};
  irMap[279][-60] = {HRIR_48K_24bit::azi_279_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_279_0_ele_neg60_0_wav};
  irMap[279][-75] = {HRIR_48K_24bit::azi_279_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_279_0_ele_neg75_0_wav};
  irMap[279][-81] = {HRIR_48K_24bit::azi_279_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_279_0_ele_neg81_0_wav};
  irMap[280][0] = {HRIR_48K_24bit::azi_280_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_280_0_ele_0_0_wav};
  irMap[280][15] = {HRIR_48K_24bit::azi_280_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_280_0_ele_15_0_wav};
  irMap[280][25] = {HRIR_48K_24bit::azi_280_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_280_0_ele_25_0_wav};
  irMap[280][30] = {HRIR_48K_24bit::azi_280_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_280_0_ele_30_0_wav};
  irMap[280][45] = {HRIR_48K_24bit::azi_280_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_280_0_ele_45_0_wav};
  irMap[280][54] = {HRIR_48K_24bit::azi_280_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_280_0_ele_54_0_wav};
  irMap[280][60] = {HRIR_48K_24bit::azi_280_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_280_0_ele_60_0_wav};
  irMap[280][75] = {HRIR_48K_24bit::azi_280_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_280_0_ele_75_0_wav};
  irMap[280][90] = {HRIR_48K_24bit::azi_280_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_280_0_ele_90_0_wav};
  irMap[280][-15] = {HRIR_48K_24bit::azi_280_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_280_0_ele_neg15_0_wav};
  irMap[280][-25] = {HRIR_48K_24bit::azi_280_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_280_0_ele_neg25_0_wav};
  irMap[280][-30] = {HRIR_48K_24bit::azi_280_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_280_0_ele_neg30_0_wav};
  irMap[280][-45] = {HRIR_48K_24bit::azi_280_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_280_0_ele_neg45_0_wav};
  irMap[280][-54] = {HRIR_48K_24bit::azi_280_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_280_0_ele_neg54_0_wav};
  irMap[280][-60] = {HRIR_48K_24bit::azi_280_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_280_0_ele_neg60_0_wav};
  irMap[280][-75] = {HRIR_48K_24bit::azi_280_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_280_0_ele_neg75_0_wav};
  irMap[280][-81] = {HRIR_48K_24bit::azi_280_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_280_0_ele_neg81_0_wav};
  irMap[281][0] = {HRIR_48K_24bit::azi_281_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_281_0_ele_0_0_wav};
  irMap[281][15] = {HRIR_48K_24bit::azi_281_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_281_0_ele_15_0_wav};
  irMap[281][25] = {HRIR_48K_24bit::azi_281_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_281_0_ele_25_0_wav};
  irMap[281][30] = {HRIR_48K_24bit::azi_281_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_281_0_ele_30_0_wav};
  irMap[281][45] = {HRIR_48K_24bit::azi_281_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_281_0_ele_45_0_wav};
  irMap[281][54] = {HRIR_48K_24bit::azi_281_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_281_0_ele_54_0_wav};
  irMap[281][60] = {HRIR_48K_24bit::azi_281_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_281_0_ele_60_0_wav};
  irMap[281][75] = {HRIR_48K_24bit::azi_281_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_281_0_ele_75_0_wav};
  irMap[281][90] = {HRIR_48K_24bit::azi_281_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_281_0_ele_90_0_wav};
  irMap[281][-15] = {HRIR_48K_24bit::azi_281_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_281_0_ele_neg15_0_wav};
  irMap[281][-25] = {HRIR_48K_24bit::azi_281_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_281_0_ele_neg25_0_wav};
  irMap[281][-30] = {HRIR_48K_24bit::azi_281_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_281_0_ele_neg30_0_wav};
  irMap[281][-45] = {HRIR_48K_24bit::azi_281_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_281_0_ele_neg45_0_wav};
  irMap[281][-54] = {HRIR_48K_24bit::azi_281_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_281_0_ele_neg54_0_wav};
  irMap[281][-60] = {HRIR_48K_24bit::azi_281_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_281_0_ele_neg60_0_wav};
  irMap[281][-75] = {HRIR_48K_24bit::azi_281_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_281_0_ele_neg75_0_wav};
  irMap[281][-81] = {HRIR_48K_24bit::azi_281_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_281_0_ele_neg81_0_wav};
  irMap[282][0] = {HRIR_48K_24bit::azi_282_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_282_0_ele_0_0_wav};
  irMap[282][15] = {HRIR_48K_24bit::azi_282_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_282_0_ele_15_0_wav};
  irMap[282][25] = {HRIR_48K_24bit::azi_282_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_282_0_ele_25_0_wav};
  irMap[282][30] = {HRIR_48K_24bit::azi_282_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_282_0_ele_30_0_wav};
  irMap[282][45] = {HRIR_48K_24bit::azi_282_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_282_0_ele_45_0_wav};
  irMap[282][54] = {HRIR_48K_24bit::azi_282_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_282_0_ele_54_0_wav};
  irMap[282][60] = {HRIR_48K_24bit::azi_282_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_282_0_ele_60_0_wav};
  irMap[282][75] = {HRIR_48K_24bit::azi_282_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_282_0_ele_75_0_wav};
  irMap[282][90] = {HRIR_48K_24bit::azi_282_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_282_0_ele_90_0_wav};
  irMap[282][-15] = {HRIR_48K_24bit::azi_282_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_282_0_ele_neg15_0_wav};
  irMap[282][-25] = {HRIR_48K_24bit::azi_282_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_282_0_ele_neg25_0_wav};
  irMap[282][-30] = {HRIR_48K_24bit::azi_282_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_282_0_ele_neg30_0_wav};
  irMap[282][-45] = {HRIR_48K_24bit::azi_282_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_282_0_ele_neg45_0_wav};
  irMap[282][-54] = {HRIR_48K_24bit::azi_282_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_282_0_ele_neg54_0_wav};
  irMap[282][-60] = {HRIR_48K_24bit::azi_282_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_282_0_ele_neg60_0_wav};
  irMap[282][-75] = {HRIR_48K_24bit::azi_282_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_282_0_ele_neg75_0_wav};
  irMap[282][-81] = {HRIR_48K_24bit::azi_282_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_282_0_ele_neg81_0_wav};
  irMap[283][0] = {HRIR_48K_24bit::azi_283_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_283_0_ele_0_0_wav};
  irMap[283][15] = {HRIR_48K_24bit::azi_283_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_283_0_ele_15_0_wav};
  irMap[283][25] = {HRIR_48K_24bit::azi_283_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_283_0_ele_25_0_wav};
  irMap[283][30] = {HRIR_48K_24bit::azi_283_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_283_0_ele_30_0_wav};
  irMap[283][45] = {HRIR_48K_24bit::azi_283_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_283_0_ele_45_0_wav};
  irMap[283][54] = {HRIR_48K_24bit::azi_283_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_283_0_ele_54_0_wav};
  irMap[283][60] = {HRIR_48K_24bit::azi_283_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_283_0_ele_60_0_wav};
  irMap[283][75] = {HRIR_48K_24bit::azi_283_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_283_0_ele_75_0_wav};
  irMap[283][90] = {HRIR_48K_24bit::azi_283_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_283_0_ele_90_0_wav};
  irMap[283][-15] = {HRIR_48K_24bit::azi_283_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_283_0_ele_neg15_0_wav};
  irMap[283][-25] = {HRIR_48K_24bit::azi_283_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_283_0_ele_neg25_0_wav};
  irMap[283][-30] = {HRIR_48K_24bit::azi_283_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_283_0_ele_neg30_0_wav};
  irMap[283][-45] = {HRIR_48K_24bit::azi_283_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_283_0_ele_neg45_0_wav};
  irMap[283][-54] = {HRIR_48K_24bit::azi_283_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_283_0_ele_neg54_0_wav};
  irMap[283][-60] = {HRIR_48K_24bit::azi_283_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_283_0_ele_neg60_0_wav};
  irMap[283][-75] = {HRIR_48K_24bit::azi_283_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_283_0_ele_neg75_0_wav};
  irMap[283][-81] = {HRIR_48K_24bit::azi_283_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_283_0_ele_neg81_0_wav};
  irMap[284][0] = {HRIR_48K_24bit::azi_284_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_284_0_ele_0_0_wav};
  irMap[284][15] = {HRIR_48K_24bit::azi_284_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_284_0_ele_15_0_wav};
  irMap[284][25] = {HRIR_48K_24bit::azi_284_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_284_0_ele_25_0_wav};
  irMap[284][30] = {HRIR_48K_24bit::azi_284_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_284_0_ele_30_0_wav};
  irMap[284][45] = {HRIR_48K_24bit::azi_284_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_284_0_ele_45_0_wav};
  irMap[284][54] = {HRIR_48K_24bit::azi_284_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_284_0_ele_54_0_wav};
  irMap[284][60] = {HRIR_48K_24bit::azi_284_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_284_0_ele_60_0_wav};
  irMap[284][75] = {HRIR_48K_24bit::azi_284_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_284_0_ele_75_0_wav};
  irMap[284][90] = {HRIR_48K_24bit::azi_284_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_284_0_ele_90_0_wav};
  irMap[284][-15] = {HRIR_48K_24bit::azi_284_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_284_0_ele_neg15_0_wav};
  irMap[284][-25] = {HRIR_48K_24bit::azi_284_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_284_0_ele_neg25_0_wav};
  irMap[284][-30] = {HRIR_48K_24bit::azi_284_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_284_0_ele_neg30_0_wav};
  irMap[284][-45] = {HRIR_48K_24bit::azi_284_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_284_0_ele_neg45_0_wav};
  irMap[284][-54] = {HRIR_48K_24bit::azi_284_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_284_0_ele_neg54_0_wav};
  irMap[284][-60] = {HRIR_48K_24bit::azi_284_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_284_0_ele_neg60_0_wav};
  irMap[284][-75] = {HRIR_48K_24bit::azi_284_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_284_0_ele_neg75_0_wav};
  irMap[284][-81] = {HRIR_48K_24bit::azi_284_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_284_0_ele_neg81_0_wav};
  irMap[285][0] = {HRIR_48K_24bit::azi_285_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_285_0_ele_0_0_wav};
  irMap[285][15] = {HRIR_48K_24bit::azi_285_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_285_0_ele_15_0_wav};
  irMap[285][25] = {HRIR_48K_24bit::azi_285_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_285_0_ele_25_0_wav};
  irMap[285][30] = {HRIR_48K_24bit::azi_285_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_285_0_ele_30_0_wav};
  irMap[285][45] = {HRIR_48K_24bit::azi_285_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_285_0_ele_45_0_wav};
  irMap[285][54] = {HRIR_48K_24bit::azi_285_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_285_0_ele_54_0_wav};
  irMap[285][60] = {HRIR_48K_24bit::azi_285_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_285_0_ele_60_0_wav};
  irMap[285][75] = {HRIR_48K_24bit::azi_285_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_285_0_ele_75_0_wav};
  irMap[285][90] = {HRIR_48K_24bit::azi_285_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_285_0_ele_90_0_wav};
  irMap[285][-15] = {HRIR_48K_24bit::azi_285_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_285_0_ele_neg15_0_wav};
  irMap[285][-25] = {HRIR_48K_24bit::azi_285_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_285_0_ele_neg25_0_wav};
  irMap[285][-30] = {HRIR_48K_24bit::azi_285_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_285_0_ele_neg30_0_wav};
  irMap[285][-45] = {HRIR_48K_24bit::azi_285_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_285_0_ele_neg45_0_wav};
  irMap[285][-54] = {HRIR_48K_24bit::azi_285_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_285_0_ele_neg54_0_wav};
  irMap[285][-60] = {HRIR_48K_24bit::azi_285_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_285_0_ele_neg60_0_wav};
  irMap[285][-75] = {HRIR_48K_24bit::azi_285_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_285_0_ele_neg75_0_wav};
  irMap[285][-81] = {HRIR_48K_24bit::azi_285_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_285_0_ele_neg81_0_wav};
  irMap[286][0] = {HRIR_48K_24bit::azi_286_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_286_0_ele_0_0_wav};
  irMap[286][15] = {HRIR_48K_24bit::azi_286_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_286_0_ele_15_0_wav};
  irMap[286][25] = {HRIR_48K_24bit::azi_286_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_286_0_ele_25_0_wav};
  irMap[286][30] = {HRIR_48K_24bit::azi_286_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_286_0_ele_30_0_wav};
  irMap[286][45] = {HRIR_48K_24bit::azi_286_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_286_0_ele_45_0_wav};
  irMap[286][54] = {HRIR_48K_24bit::azi_286_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_286_0_ele_54_0_wav};
  irMap[286][60] = {HRIR_48K_24bit::azi_286_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_286_0_ele_60_0_wav};
  irMap[286][75] = {HRIR_48K_24bit::azi_286_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_286_0_ele_75_0_wav};
  irMap[286][90] = {HRIR_48K_24bit::azi_286_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_286_0_ele_90_0_wav};
  irMap[286][-15] = {HRIR_48K_24bit::azi_286_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_286_0_ele_neg15_0_wav};
  irMap[286][-25] = {HRIR_48K_24bit::azi_286_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_286_0_ele_neg25_0_wav};
  irMap[286][-30] = {HRIR_48K_24bit::azi_286_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_286_0_ele_neg30_0_wav};
  irMap[286][-45] = {HRIR_48K_24bit::azi_286_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_286_0_ele_neg45_0_wav};
  irMap[286][-54] = {HRIR_48K_24bit::azi_286_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_286_0_ele_neg54_0_wav};
  irMap[286][-60] = {HRIR_48K_24bit::azi_286_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_286_0_ele_neg60_0_wav};
  irMap[286][-75] = {HRIR_48K_24bit::azi_286_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_286_0_ele_neg75_0_wav};
  irMap[286][-81] = {HRIR_48K_24bit::azi_286_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_286_0_ele_neg81_0_wav};
  irMap[287][0] = {HRIR_48K_24bit::azi_287_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_287_0_ele_0_0_wav};
  irMap[287][15] = {HRIR_48K_24bit::azi_287_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_287_0_ele_15_0_wav};
  irMap[287][25] = {HRIR_48K_24bit::azi_287_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_287_0_ele_25_0_wav};
  irMap[287][30] = {HRIR_48K_24bit::azi_287_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_287_0_ele_30_0_wav};
  irMap[287][45] = {HRIR_48K_24bit::azi_287_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_287_0_ele_45_0_wav};
  irMap[287][54] = {HRIR_48K_24bit::azi_287_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_287_0_ele_54_0_wav};
  irMap[287][60] = {HRIR_48K_24bit::azi_287_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_287_0_ele_60_0_wav};
  irMap[287][75] = {HRIR_48K_24bit::azi_287_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_287_0_ele_75_0_wav};
  irMap[287][90] = {HRIR_48K_24bit::azi_287_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_287_0_ele_90_0_wav};
  irMap[287][-15] = {HRIR_48K_24bit::azi_287_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_287_0_ele_neg15_0_wav};
  irMap[287][-25] = {HRIR_48K_24bit::azi_287_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_287_0_ele_neg25_0_wav};
  irMap[287][-30] = {HRIR_48K_24bit::azi_287_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_287_0_ele_neg30_0_wav};
  irMap[287][-45] = {HRIR_48K_24bit::azi_287_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_287_0_ele_neg45_0_wav};
  irMap[287][-54] = {HRIR_48K_24bit::azi_287_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_287_0_ele_neg54_0_wav};
  irMap[287][-60] = {HRIR_48K_24bit::azi_287_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_287_0_ele_neg60_0_wav};
  irMap[287][-75] = {HRIR_48K_24bit::azi_287_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_287_0_ele_neg75_0_wav};
  irMap[287][-81] = {HRIR_48K_24bit::azi_287_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_287_0_ele_neg81_0_wav};
  irMap[288][0] = {HRIR_48K_24bit::azi_288_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_288_0_ele_0_0_wav};
  irMap[288][15] = {HRIR_48K_24bit::azi_288_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_288_0_ele_15_0_wav};
  irMap[288][25] = {HRIR_48K_24bit::azi_288_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_288_0_ele_25_0_wav};
  irMap[288][30] = {HRIR_48K_24bit::azi_288_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_288_0_ele_30_0_wav};
  irMap[288][45] = {HRIR_48K_24bit::azi_288_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_288_0_ele_45_0_wav};
  irMap[288][54] = {HRIR_48K_24bit::azi_288_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_288_0_ele_54_0_wav};
  irMap[288][60] = {HRIR_48K_24bit::azi_288_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_288_0_ele_60_0_wav};
  irMap[288][75] = {HRIR_48K_24bit::azi_288_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_288_0_ele_75_0_wav};
  irMap[288][90] = {HRIR_48K_24bit::azi_288_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_288_0_ele_90_0_wav};
  irMap[288][-15] = {HRIR_48K_24bit::azi_288_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_288_0_ele_neg15_0_wav};
  irMap[288][-25] = {HRIR_48K_24bit::azi_288_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_288_0_ele_neg25_0_wav};
  irMap[288][-30] = {HRIR_48K_24bit::azi_288_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_288_0_ele_neg30_0_wav};
  irMap[288][-45] = {HRIR_48K_24bit::azi_288_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_288_0_ele_neg45_0_wav};
  irMap[288][-54] = {HRIR_48K_24bit::azi_288_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_288_0_ele_neg54_0_wav};
  irMap[288][-60] = {HRIR_48K_24bit::azi_288_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_288_0_ele_neg60_0_wav};
  irMap[288][-75] = {HRIR_48K_24bit::azi_288_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_288_0_ele_neg75_0_wav};
  irMap[288][-81] = {HRIR_48K_24bit::azi_288_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_288_0_ele_neg81_0_wav};
  irMap[289][0] = {HRIR_48K_24bit::azi_289_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_289_0_ele_0_0_wav};
  irMap[289][15] = {HRIR_48K_24bit::azi_289_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_289_0_ele_15_0_wav};
  irMap[289][25] = {HRIR_48K_24bit::azi_289_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_289_0_ele_25_0_wav};
  irMap[289][30] = {HRIR_48K_24bit::azi_289_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_289_0_ele_30_0_wav};
  irMap[289][45] = {HRIR_48K_24bit::azi_289_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_289_0_ele_45_0_wav};
  irMap[289][54] = {HRIR_48K_24bit::azi_289_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_289_0_ele_54_0_wav};
  irMap[289][60] = {HRIR_48K_24bit::azi_289_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_289_0_ele_60_0_wav};
  irMap[289][75] = {HRIR_48K_24bit::azi_289_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_289_0_ele_75_0_wav};
  irMap[289][90] = {HRIR_48K_24bit::azi_289_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_289_0_ele_90_0_wav};
  irMap[289][-15] = {HRIR_48K_24bit::azi_289_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_289_0_ele_neg15_0_wav};
  irMap[289][-25] = {HRIR_48K_24bit::azi_289_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_289_0_ele_neg25_0_wav};
  irMap[289][-30] = {HRIR_48K_24bit::azi_289_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_289_0_ele_neg30_0_wav};
  irMap[289][-45] = {HRIR_48K_24bit::azi_289_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_289_0_ele_neg45_0_wav};
  irMap[289][-54] = {HRIR_48K_24bit::azi_289_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_289_0_ele_neg54_0_wav};
  irMap[289][-60] = {HRIR_48K_24bit::azi_289_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_289_0_ele_neg60_0_wav};
  irMap[289][-75] = {HRIR_48K_24bit::azi_289_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_289_0_ele_neg75_0_wav};
  irMap[289][-81] = {HRIR_48K_24bit::azi_289_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_289_0_ele_neg81_0_wav};
  irMap[290][0] = {HRIR_48K_24bit::azi_290_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_290_0_ele_0_0_wav};
  irMap[290][15] = {HRIR_48K_24bit::azi_290_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_290_0_ele_15_0_wav};
  irMap[290][25] = {HRIR_48K_24bit::azi_290_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_290_0_ele_25_0_wav};
  irMap[290][30] = {HRIR_48K_24bit::azi_290_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_290_0_ele_30_0_wav};
  irMap[290][45] = {HRIR_48K_24bit::azi_290_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_290_0_ele_45_0_wav};
  irMap[290][54] = {HRIR_48K_24bit::azi_290_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_290_0_ele_54_0_wav};
  irMap[290][60] = {HRIR_48K_24bit::azi_290_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_290_0_ele_60_0_wav};
  irMap[290][75] = {HRIR_48K_24bit::azi_290_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_290_0_ele_75_0_wav};
  irMap[290][90] = {HRIR_48K_24bit::azi_290_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_290_0_ele_90_0_wav};
  irMap[290][-15] = {HRIR_48K_24bit::azi_290_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_290_0_ele_neg15_0_wav};
  irMap[290][-25] = {HRIR_48K_24bit::azi_290_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_290_0_ele_neg25_0_wav};
  irMap[290][-30] = {HRIR_48K_24bit::azi_290_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_290_0_ele_neg30_0_wav};
  irMap[290][-45] = {HRIR_48K_24bit::azi_290_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_290_0_ele_neg45_0_wav};
  irMap[290][-54] = {HRIR_48K_24bit::azi_290_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_290_0_ele_neg54_0_wav};
  irMap[290][-60] = {HRIR_48K_24bit::azi_290_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_290_0_ele_neg60_0_wav};
  irMap[290][-75] = {HRIR_48K_24bit::azi_290_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_290_0_ele_neg75_0_wav};
  irMap[290][-81] = {HRIR_48K_24bit::azi_290_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_290_0_ele_neg81_0_wav};
  irMap[291][0] = {HRIR_48K_24bit::azi_291_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_291_0_ele_0_0_wav};
  irMap[291][15] = {HRIR_48K_24bit::azi_291_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_291_0_ele_15_0_wav};
  irMap[291][25] = {HRIR_48K_24bit::azi_291_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_291_0_ele_25_0_wav};
  irMap[291][30] = {HRIR_48K_24bit::azi_291_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_291_0_ele_30_0_wav};
  irMap[291][45] = {HRIR_48K_24bit::azi_291_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_291_0_ele_45_0_wav};
  irMap[291][54] = {HRIR_48K_24bit::azi_291_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_291_0_ele_54_0_wav};
  irMap[291][60] = {HRIR_48K_24bit::azi_291_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_291_0_ele_60_0_wav};
  irMap[291][75] = {HRIR_48K_24bit::azi_291_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_291_0_ele_75_0_wav};
  irMap[291][90] = {HRIR_48K_24bit::azi_291_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_291_0_ele_90_0_wav};
  irMap[291][-15] = {HRIR_48K_24bit::azi_291_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_291_0_ele_neg15_0_wav};
  irMap[291][-25] = {HRIR_48K_24bit::azi_291_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_291_0_ele_neg25_0_wav};
  irMap[291][-30] = {HRIR_48K_24bit::azi_291_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_291_0_ele_neg30_0_wav};
  irMap[291][-45] = {HRIR_48K_24bit::azi_291_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_291_0_ele_neg45_0_wav};
  irMap[291][-54] = {HRIR_48K_24bit::azi_291_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_291_0_ele_neg54_0_wav};
  irMap[291][-60] = {HRIR_48K_24bit::azi_291_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_291_0_ele_neg60_0_wav};
  irMap[291][-75] = {HRIR_48K_24bit::azi_291_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_291_0_ele_neg75_0_wav};
  irMap[291][-81] = {HRIR_48K_24bit::azi_291_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_291_0_ele_neg81_0_wav};
  irMap[292][0] = {HRIR_48K_24bit::azi_292_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_292_0_ele_0_0_wav};
  irMap[292][15] = {HRIR_48K_24bit::azi_292_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_292_0_ele_15_0_wav};
  irMap[292][25] = {HRIR_48K_24bit::azi_292_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_292_0_ele_25_0_wav};
  irMap[292][30] = {HRIR_48K_24bit::azi_292_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_292_0_ele_30_0_wav};
  irMap[292][45] = {HRIR_48K_24bit::azi_292_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_292_0_ele_45_0_wav};
  irMap[292][54] = {HRIR_48K_24bit::azi_292_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_292_0_ele_54_0_wav};
  irMap[292][60] = {HRIR_48K_24bit::azi_292_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_292_0_ele_60_0_wav};
  irMap[292][75] = {HRIR_48K_24bit::azi_292_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_292_0_ele_75_0_wav};
  irMap[292][90] = {HRIR_48K_24bit::azi_292_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_292_0_ele_90_0_wav};
  irMap[292][-15] = {HRIR_48K_24bit::azi_292_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_292_0_ele_neg15_0_wav};
  irMap[292][-25] = {HRIR_48K_24bit::azi_292_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_292_0_ele_neg25_0_wav};
  irMap[292][-30] = {HRIR_48K_24bit::azi_292_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_292_0_ele_neg30_0_wav};
  irMap[292][-45] = {HRIR_48K_24bit::azi_292_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_292_0_ele_neg45_0_wav};
  irMap[292][-54] = {HRIR_48K_24bit::azi_292_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_292_0_ele_neg54_0_wav};
  irMap[292][-60] = {HRIR_48K_24bit::azi_292_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_292_0_ele_neg60_0_wav};
  irMap[292][-75] = {HRIR_48K_24bit::azi_292_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_292_0_ele_neg75_0_wav};
  irMap[292][-81] = {HRIR_48K_24bit::azi_292_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_292_0_ele_neg81_0_wav};
  irMap[293][0] = {HRIR_48K_24bit::azi_293_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_293_0_ele_0_0_wav};
  irMap[293][15] = {HRIR_48K_24bit::azi_293_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_293_0_ele_15_0_wav};
  irMap[293][25] = {HRIR_48K_24bit::azi_293_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_293_0_ele_25_0_wav};
  irMap[293][30] = {HRIR_48K_24bit::azi_293_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_293_0_ele_30_0_wav};
  irMap[293][45] = {HRIR_48K_24bit::azi_293_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_293_0_ele_45_0_wav};
  irMap[293][54] = {HRIR_48K_24bit::azi_293_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_293_0_ele_54_0_wav};
  irMap[293][60] = {HRIR_48K_24bit::azi_293_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_293_0_ele_60_0_wav};
  irMap[293][75] = {HRIR_48K_24bit::azi_293_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_293_0_ele_75_0_wav};
  irMap[293][90] = {HRIR_48K_24bit::azi_293_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_293_0_ele_90_0_wav};
  irMap[293][-15] = {HRIR_48K_24bit::azi_293_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_293_0_ele_neg15_0_wav};
  irMap[293][-25] = {HRIR_48K_24bit::azi_293_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_293_0_ele_neg25_0_wav};
  irMap[293][-30] = {HRIR_48K_24bit::azi_293_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_293_0_ele_neg30_0_wav};
  irMap[293][-45] = {HRIR_48K_24bit::azi_293_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_293_0_ele_neg45_0_wav};
  irMap[293][-54] = {HRIR_48K_24bit::azi_293_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_293_0_ele_neg54_0_wav};
  irMap[293][-60] = {HRIR_48K_24bit::azi_293_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_293_0_ele_neg60_0_wav};
  irMap[293][-75] = {HRIR_48K_24bit::azi_293_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_293_0_ele_neg75_0_wav};
  irMap[293][-81] = {HRIR_48K_24bit::azi_293_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_293_0_ele_neg81_0_wav};
  irMap[294][0] = {HRIR_48K_24bit::azi_294_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_294_0_ele_0_0_wav};
  irMap[294][15] = {HRIR_48K_24bit::azi_294_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_294_0_ele_15_0_wav};
  irMap[294][25] = {HRIR_48K_24bit::azi_294_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_294_0_ele_25_0_wav};
  irMap[294][30] = {HRIR_48K_24bit::azi_294_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_294_0_ele_30_0_wav};
  irMap[294][45] = {HRIR_48K_24bit::azi_294_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_294_0_ele_45_0_wav};
  irMap[294][54] = {HRIR_48K_24bit::azi_294_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_294_0_ele_54_0_wav};
  irMap[294][60] = {HRIR_48K_24bit::azi_294_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_294_0_ele_60_0_wav};
  irMap[294][75] = {HRIR_48K_24bit::azi_294_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_294_0_ele_75_0_wav};
  irMap[294][90] = {HRIR_48K_24bit::azi_294_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_294_0_ele_90_0_wav};
  irMap[294][-15] = {HRIR_48K_24bit::azi_294_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_294_0_ele_neg15_0_wav};
  irMap[294][-25] = {HRIR_48K_24bit::azi_294_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_294_0_ele_neg25_0_wav};
  irMap[294][-30] = {HRIR_48K_24bit::azi_294_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_294_0_ele_neg30_0_wav};
  irMap[294][-45] = {HRIR_48K_24bit::azi_294_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_294_0_ele_neg45_0_wav};
  irMap[294][-54] = {HRIR_48K_24bit::azi_294_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_294_0_ele_neg54_0_wav};
  irMap[294][-60] = {HRIR_48K_24bit::azi_294_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_294_0_ele_neg60_0_wav};
  irMap[294][-75] = {HRIR_48K_24bit::azi_294_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_294_0_ele_neg75_0_wav};
  irMap[294][-81] = {HRIR_48K_24bit::azi_294_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_294_0_ele_neg81_0_wav};
  irMap[295][0] = {HRIR_48K_24bit::azi_295_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_295_0_ele_0_0_wav};
  irMap[295][15] = {HRIR_48K_24bit::azi_295_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_295_0_ele_15_0_wav};
  irMap[295][25] = {HRIR_48K_24bit::azi_295_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_295_0_ele_25_0_wav};
  irMap[295][30] = {HRIR_48K_24bit::azi_295_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_295_0_ele_30_0_wav};
  irMap[295][45] = {HRIR_48K_24bit::azi_295_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_295_0_ele_45_0_wav};
  irMap[295][54] = {HRIR_48K_24bit::azi_295_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_295_0_ele_54_0_wav};
  irMap[295][60] = {HRIR_48K_24bit::azi_295_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_295_0_ele_60_0_wav};
  irMap[295][75] = {HRIR_48K_24bit::azi_295_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_295_0_ele_75_0_wav};
  irMap[295][90] = {HRIR_48K_24bit::azi_295_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_295_0_ele_90_0_wav};
  irMap[295][-15] = {HRIR_48K_24bit::azi_295_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_295_0_ele_neg15_0_wav};
  irMap[295][-25] = {HRIR_48K_24bit::azi_295_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_295_0_ele_neg25_0_wav};
  irMap[295][-30] = {HRIR_48K_24bit::azi_295_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_295_0_ele_neg30_0_wav};
  irMap[295][-45] = {HRIR_48K_24bit::azi_295_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_295_0_ele_neg45_0_wav};
  irMap[295][-54] = {HRIR_48K_24bit::azi_295_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_295_0_ele_neg54_0_wav};
  irMap[295][-60] = {HRIR_48K_24bit::azi_295_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_295_0_ele_neg60_0_wav};
  irMap[295][-75] = {HRIR_48K_24bit::azi_295_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_295_0_ele_neg75_0_wav};
  irMap[295][-81] = {HRIR_48K_24bit::azi_295_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_295_0_ele_neg81_0_wav};
  irMap[296][0] = {HRIR_48K_24bit::azi_296_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_296_0_ele_0_0_wav};
  irMap[296][15] = {HRIR_48K_24bit::azi_296_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_296_0_ele_15_0_wav};
  irMap[296][25] = {HRIR_48K_24bit::azi_296_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_296_0_ele_25_0_wav};
  irMap[296][30] = {HRIR_48K_24bit::azi_296_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_296_0_ele_30_0_wav};
  irMap[296][45] = {HRIR_48K_24bit::azi_296_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_296_0_ele_45_0_wav};
  irMap[296][54] = {HRIR_48K_24bit::azi_296_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_296_0_ele_54_0_wav};
  irMap[296][60] = {HRIR_48K_24bit::azi_296_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_296_0_ele_60_0_wav};
  irMap[296][75] = {HRIR_48K_24bit::azi_296_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_296_0_ele_75_0_wav};
  irMap[296][90] = {HRIR_48K_24bit::azi_296_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_296_0_ele_90_0_wav};
  irMap[296][-15] = {HRIR_48K_24bit::azi_296_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_296_0_ele_neg15_0_wav};
  irMap[296][-25] = {HRIR_48K_24bit::azi_296_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_296_0_ele_neg25_0_wav};
  irMap[296][-30] = {HRIR_48K_24bit::azi_296_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_296_0_ele_neg30_0_wav};
  irMap[296][-45] = {HRIR_48K_24bit::azi_296_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_296_0_ele_neg45_0_wav};
  irMap[296][-54] = {HRIR_48K_24bit::azi_296_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_296_0_ele_neg54_0_wav};
  irMap[296][-60] = {HRIR_48K_24bit::azi_296_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_296_0_ele_neg60_0_wav};
  irMap[296][-75] = {HRIR_48K_24bit::azi_296_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_296_0_ele_neg75_0_wav};
  irMap[296][-81] = {HRIR_48K_24bit::azi_296_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_296_0_ele_neg81_0_wav};
  irMap[297][0] = {HRIR_48K_24bit::azi_297_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_297_0_ele_0_0_wav};
  irMap[297][15] = {HRIR_48K_24bit::azi_297_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_297_0_ele_15_0_wav};
  irMap[297][25] = {HRIR_48K_24bit::azi_297_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_297_0_ele_25_0_wav};
  irMap[297][30] = {HRIR_48K_24bit::azi_297_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_297_0_ele_30_0_wav};
  irMap[297][45] = {HRIR_48K_24bit::azi_297_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_297_0_ele_45_0_wav};
  irMap[297][54] = {HRIR_48K_24bit::azi_297_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_297_0_ele_54_0_wav};
  irMap[297][60] = {HRIR_48K_24bit::azi_297_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_297_0_ele_60_0_wav};
  irMap[297][75] = {HRIR_48K_24bit::azi_297_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_297_0_ele_75_0_wav};
  irMap[297][90] = {HRIR_48K_24bit::azi_297_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_297_0_ele_90_0_wav};
  irMap[297][-15] = {HRIR_48K_24bit::azi_297_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_297_0_ele_neg15_0_wav};
  irMap[297][-25] = {HRIR_48K_24bit::azi_297_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_297_0_ele_neg25_0_wav};
  irMap[297][-30] = {HRIR_48K_24bit::azi_297_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_297_0_ele_neg30_0_wav};
  irMap[297][-45] = {HRIR_48K_24bit::azi_297_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_297_0_ele_neg45_0_wav};
  irMap[297][-54] = {HRIR_48K_24bit::azi_297_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_297_0_ele_neg54_0_wav};
  irMap[297][-60] = {HRIR_48K_24bit::azi_297_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_297_0_ele_neg60_0_wav};
  irMap[297][-75] = {HRIR_48K_24bit::azi_297_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_297_0_ele_neg75_0_wav};
  irMap[297][-81] = {HRIR_48K_24bit::azi_297_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_297_0_ele_neg81_0_wav};
  irMap[298][0] = {HRIR_48K_24bit::azi_298_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_298_0_ele_0_0_wav};
  irMap[298][15] = {HRIR_48K_24bit::azi_298_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_298_0_ele_15_0_wav};
  irMap[298][25] = {HRIR_48K_24bit::azi_298_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_298_0_ele_25_0_wav};
  irMap[298][30] = {HRIR_48K_24bit::azi_298_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_298_0_ele_30_0_wav};
  irMap[298][45] = {HRIR_48K_24bit::azi_298_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_298_0_ele_45_0_wav};
  irMap[298][54] = {HRIR_48K_24bit::azi_298_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_298_0_ele_54_0_wav};
  irMap[298][60] = {HRIR_48K_24bit::azi_298_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_298_0_ele_60_0_wav};
  irMap[298][75] = {HRIR_48K_24bit::azi_298_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_298_0_ele_75_0_wav};
  irMap[298][90] = {HRIR_48K_24bit::azi_298_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_298_0_ele_90_0_wav};
  irMap[298][-15] = {HRIR_48K_24bit::azi_298_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_298_0_ele_neg15_0_wav};
  irMap[298][-25] = {HRIR_48K_24bit::azi_298_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_298_0_ele_neg25_0_wav};
  irMap[298][-30] = {HRIR_48K_24bit::azi_298_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_298_0_ele_neg30_0_wav};
  irMap[298][-45] = {HRIR_48K_24bit::azi_298_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_298_0_ele_neg45_0_wav};
  irMap[298][-54] = {HRIR_48K_24bit::azi_298_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_298_0_ele_neg54_0_wav};
  irMap[298][-60] = {HRIR_48K_24bit::azi_298_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_298_0_ele_neg60_0_wav};
  irMap[298][-75] = {HRIR_48K_24bit::azi_298_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_298_0_ele_neg75_0_wav};
  irMap[298][-81] = {HRIR_48K_24bit::azi_298_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_298_0_ele_neg81_0_wav};
  irMap[299][0] = {HRIR_48K_24bit::azi_299_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_299_0_ele_0_0_wav};
  irMap[299][15] = {HRIR_48K_24bit::azi_299_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_299_0_ele_15_0_wav};
  irMap[299][25] = {HRIR_48K_24bit::azi_299_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_299_0_ele_25_0_wav};
  irMap[299][30] = {HRIR_48K_24bit::azi_299_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_299_0_ele_30_0_wav};
  irMap[299][45] = {HRIR_48K_24bit::azi_299_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_299_0_ele_45_0_wav};
  irMap[299][54] = {HRIR_48K_24bit::azi_299_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_299_0_ele_54_0_wav};
  irMap[299][60] = {HRIR_48K_24bit::azi_299_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_299_0_ele_60_0_wav};
  irMap[299][75] = {HRIR_48K_24bit::azi_299_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_299_0_ele_75_0_wav};
  irMap[299][90] = {HRIR_48K_24bit::azi_299_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_299_0_ele_90_0_wav};
  irMap[299][-15] = {HRIR_48K_24bit::azi_299_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_299_0_ele_neg15_0_wav};
  irMap[299][-25] = {HRIR_48K_24bit::azi_299_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_299_0_ele_neg25_0_wav};
  irMap[299][-30] = {HRIR_48K_24bit::azi_299_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_299_0_ele_neg30_0_wav};
  irMap[299][-45] = {HRIR_48K_24bit::azi_299_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_299_0_ele_neg45_0_wav};
  irMap[299][-54] = {HRIR_48K_24bit::azi_299_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_299_0_ele_neg54_0_wav};
  irMap[299][-60] = {HRIR_48K_24bit::azi_299_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_299_0_ele_neg60_0_wav};
  irMap[299][-75] = {HRIR_48K_24bit::azi_299_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_299_0_ele_neg75_0_wav};
  irMap[299][-81] = {HRIR_48K_24bit::azi_299_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_299_0_ele_neg81_0_wav};
  irMap[300][0] = {HRIR_48K_24bit::azi_300_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_300_0_ele_0_0_wav};
  irMap[300][15] = {HRIR_48K_24bit::azi_300_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_300_0_ele_15_0_wav};
  irMap[300][25] = {HRIR_48K_24bit::azi_300_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_300_0_ele_25_0_wav};
  irMap[300][30] = {HRIR_48K_24bit::azi_300_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_300_0_ele_30_0_wav};
  irMap[300][45] = {HRIR_48K_24bit::azi_300_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_300_0_ele_45_0_wav};
  irMap[300][54] = {HRIR_48K_24bit::azi_300_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_300_0_ele_54_0_wav};
  irMap[300][60] = {HRIR_48K_24bit::azi_300_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_300_0_ele_60_0_wav};
  irMap[300][75] = {HRIR_48K_24bit::azi_300_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_300_0_ele_75_0_wav};
  irMap[300][90] = {HRIR_48K_24bit::azi_300_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_300_0_ele_90_0_wav};
  irMap[300][-15] = {HRIR_48K_24bit::azi_300_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_300_0_ele_neg15_0_wav};
  irMap[300][-25] = {HRIR_48K_24bit::azi_300_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_300_0_ele_neg25_0_wav};
  irMap[300][-30] = {HRIR_48K_24bit::azi_300_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_300_0_ele_neg30_0_wav};
  irMap[300][-45] = {HRIR_48K_24bit::azi_300_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_300_0_ele_neg45_0_wav};
  irMap[300][-54] = {HRIR_48K_24bit::azi_300_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_300_0_ele_neg54_0_wav};
  irMap[300][-60] = {HRIR_48K_24bit::azi_300_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_300_0_ele_neg60_0_wav};
  irMap[300][-75] = {HRIR_48K_24bit::azi_300_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_300_0_ele_neg75_0_wav};
  irMap[300][-81] = {HRIR_48K_24bit::azi_300_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_300_0_ele_neg81_0_wav};
  irMap[301][0] = {HRIR_48K_24bit::azi_301_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_301_0_ele_0_0_wav};
  irMap[301][15] = {HRIR_48K_24bit::azi_301_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_301_0_ele_15_0_wav};
  irMap[301][25] = {HRIR_48K_24bit::azi_301_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_301_0_ele_25_0_wav};
  irMap[301][30] = {HRIR_48K_24bit::azi_301_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_301_0_ele_30_0_wav};
  irMap[301][45] = {HRIR_48K_24bit::azi_301_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_301_0_ele_45_0_wav};
  irMap[301][54] = {HRIR_48K_24bit::azi_301_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_301_0_ele_54_0_wav};
  irMap[301][60] = {HRIR_48K_24bit::azi_301_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_301_0_ele_60_0_wav};
  irMap[301][75] = {HRIR_48K_24bit::azi_301_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_301_0_ele_75_0_wav};
  irMap[301][90] = {HRIR_48K_24bit::azi_301_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_301_0_ele_90_0_wav};
  irMap[301][-15] = {HRIR_48K_24bit::azi_301_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_301_0_ele_neg15_0_wav};
  irMap[301][-25] = {HRIR_48K_24bit::azi_301_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_301_0_ele_neg25_0_wav};
  irMap[301][-30] = {HRIR_48K_24bit::azi_301_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_301_0_ele_neg30_0_wav};
  irMap[301][-45] = {HRIR_48K_24bit::azi_301_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_301_0_ele_neg45_0_wav};
  irMap[301][-54] = {HRIR_48K_24bit::azi_301_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_301_0_ele_neg54_0_wav};
  irMap[301][-60] = {HRIR_48K_24bit::azi_301_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_301_0_ele_neg60_0_wav};
  irMap[301][-75] = {HRIR_48K_24bit::azi_301_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_301_0_ele_neg75_0_wav};
  irMap[301][-81] = {HRIR_48K_24bit::azi_301_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_301_0_ele_neg81_0_wav};
  irMap[302][0] = {HRIR_48K_24bit::azi_302_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_302_0_ele_0_0_wav};
  irMap[302][15] = {HRIR_48K_24bit::azi_302_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_302_0_ele_15_0_wav};
  irMap[302][25] = {HRIR_48K_24bit::azi_302_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_302_0_ele_25_0_wav};
  irMap[302][30] = {HRIR_48K_24bit::azi_302_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_302_0_ele_30_0_wav};
  irMap[302][45] = {HRIR_48K_24bit::azi_302_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_302_0_ele_45_0_wav};
  irMap[302][54] = {HRIR_48K_24bit::azi_302_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_302_0_ele_54_0_wav};
  irMap[302][60] = {HRIR_48K_24bit::azi_302_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_302_0_ele_60_0_wav};
  irMap[302][75] = {HRIR_48K_24bit::azi_302_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_302_0_ele_75_0_wav};
  irMap[302][90] = {HRIR_48K_24bit::azi_302_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_302_0_ele_90_0_wav};
  irMap[302][-15] = {HRIR_48K_24bit::azi_302_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_302_0_ele_neg15_0_wav};
  irMap[302][-25] = {HRIR_48K_24bit::azi_302_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_302_0_ele_neg25_0_wav};
  irMap[302][-30] = {HRIR_48K_24bit::azi_302_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_302_0_ele_neg30_0_wav};
  irMap[302][-45] = {HRIR_48K_24bit::azi_302_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_302_0_ele_neg45_0_wav};
  irMap[302][-54] = {HRIR_48K_24bit::azi_302_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_302_0_ele_neg54_0_wav};
  irMap[302][-60] = {HRIR_48K_24bit::azi_302_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_302_0_ele_neg60_0_wav};
  irMap[302][-75] = {HRIR_48K_24bit::azi_302_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_302_0_ele_neg75_0_wav};
  irMap[302][-81] = {HRIR_48K_24bit::azi_302_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_302_0_ele_neg81_0_wav};
  irMap[303][0] = {HRIR_48K_24bit::azi_303_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_303_0_ele_0_0_wav};
  irMap[303][15] = {HRIR_48K_24bit::azi_303_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_303_0_ele_15_0_wav};
  irMap[303][25] = {HRIR_48K_24bit::azi_303_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_303_0_ele_25_0_wav};
  irMap[303][30] = {HRIR_48K_24bit::azi_303_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_303_0_ele_30_0_wav};
  irMap[303][45] = {HRIR_48K_24bit::azi_303_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_303_0_ele_45_0_wav};
  irMap[303][54] = {HRIR_48K_24bit::azi_303_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_303_0_ele_54_0_wav};
  irMap[303][60] = {HRIR_48K_24bit::azi_303_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_303_0_ele_60_0_wav};
  irMap[303][75] = {HRIR_48K_24bit::azi_303_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_303_0_ele_75_0_wav};
  irMap[303][90] = {HRIR_48K_24bit::azi_303_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_303_0_ele_90_0_wav};
  irMap[303][-15] = {HRIR_48K_24bit::azi_303_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_303_0_ele_neg15_0_wav};
  irMap[303][-25] = {HRIR_48K_24bit::azi_303_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_303_0_ele_neg25_0_wav};
  irMap[303][-30] = {HRIR_48K_24bit::azi_303_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_303_0_ele_neg30_0_wav};
  irMap[303][-45] = {HRIR_48K_24bit::azi_303_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_303_0_ele_neg45_0_wav};
  irMap[303][-54] = {HRIR_48K_24bit::azi_303_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_303_0_ele_neg54_0_wav};
  irMap[303][-60] = {HRIR_48K_24bit::azi_303_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_303_0_ele_neg60_0_wav};
  irMap[303][-75] = {HRIR_48K_24bit::azi_303_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_303_0_ele_neg75_0_wav};
  irMap[303][-81] = {HRIR_48K_24bit::azi_303_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_303_0_ele_neg81_0_wav};
  irMap[304][0] = {HRIR_48K_24bit::azi_304_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_304_0_ele_0_0_wav};
  irMap[304][15] = {HRIR_48K_24bit::azi_304_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_304_0_ele_15_0_wav};
  irMap[304][25] = {HRIR_48K_24bit::azi_304_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_304_0_ele_25_0_wav};
  irMap[304][30] = {HRIR_48K_24bit::azi_304_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_304_0_ele_30_0_wav};
  irMap[304][45] = {HRIR_48K_24bit::azi_304_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_304_0_ele_45_0_wav};
  irMap[304][54] = {HRIR_48K_24bit::azi_304_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_304_0_ele_54_0_wav};
  irMap[304][60] = {HRIR_48K_24bit::azi_304_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_304_0_ele_60_0_wav};
  irMap[304][75] = {HRIR_48K_24bit::azi_304_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_304_0_ele_75_0_wav};
  irMap[304][90] = {HRIR_48K_24bit::azi_304_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_304_0_ele_90_0_wav};
  irMap[304][-15] = {HRIR_48K_24bit::azi_304_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_304_0_ele_neg15_0_wav};
  irMap[304][-25] = {HRIR_48K_24bit::azi_304_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_304_0_ele_neg25_0_wav};
  irMap[304][-30] = {HRIR_48K_24bit::azi_304_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_304_0_ele_neg30_0_wav};
  irMap[304][-45] = {HRIR_48K_24bit::azi_304_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_304_0_ele_neg45_0_wav};
  irMap[304][-54] = {HRIR_48K_24bit::azi_304_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_304_0_ele_neg54_0_wav};
  irMap[304][-60] = {HRIR_48K_24bit::azi_304_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_304_0_ele_neg60_0_wav};
  irMap[304][-75] = {HRIR_48K_24bit::azi_304_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_304_0_ele_neg75_0_wav};
  irMap[304][-81] = {HRIR_48K_24bit::azi_304_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_304_0_ele_neg81_0_wav};
  irMap[305][0] = {HRIR_48K_24bit::azi_305_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_305_0_ele_0_0_wav};
  irMap[305][15] = {HRIR_48K_24bit::azi_305_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_305_0_ele_15_0_wav};
  irMap[305][25] = {HRIR_48K_24bit::azi_305_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_305_0_ele_25_0_wav};
  irMap[305][30] = {HRIR_48K_24bit::azi_305_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_305_0_ele_30_0_wav};
  irMap[305][45] = {HRIR_48K_24bit::azi_305_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_305_0_ele_45_0_wav};
  irMap[305][54] = {HRIR_48K_24bit::azi_305_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_305_0_ele_54_0_wav};
  irMap[305][60] = {HRIR_48K_24bit::azi_305_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_305_0_ele_60_0_wav};
  irMap[305][75] = {HRIR_48K_24bit::azi_305_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_305_0_ele_75_0_wav};
  irMap[305][90] = {HRIR_48K_24bit::azi_305_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_305_0_ele_90_0_wav};
  irMap[305][-15] = {HRIR_48K_24bit::azi_305_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_305_0_ele_neg15_0_wav};
  irMap[305][-25] = {HRIR_48K_24bit::azi_305_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_305_0_ele_neg25_0_wav};
  irMap[305][-30] = {HRIR_48K_24bit::azi_305_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_305_0_ele_neg30_0_wav};
  irMap[305][-45] = {HRIR_48K_24bit::azi_305_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_305_0_ele_neg45_0_wav};
  irMap[305][-54] = {HRIR_48K_24bit::azi_305_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_305_0_ele_neg54_0_wav};
  irMap[305][-60] = {HRIR_48K_24bit::azi_305_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_305_0_ele_neg60_0_wav};
  irMap[305][-75] = {HRIR_48K_24bit::azi_305_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_305_0_ele_neg75_0_wav};
  irMap[305][-81] = {HRIR_48K_24bit::azi_305_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_305_0_ele_neg81_0_wav};
  irMap[306][0] = {HRIR_48K_24bit::azi_306_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_306_0_ele_0_0_wav};
  irMap[306][15] = {HRIR_48K_24bit::azi_306_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_306_0_ele_15_0_wav};
  irMap[306][25] = {HRIR_48K_24bit::azi_306_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_306_0_ele_25_0_wav};
  irMap[306][30] = {HRIR_48K_24bit::azi_306_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_306_0_ele_30_0_wav};
  irMap[306][45] = {HRIR_48K_24bit::azi_306_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_306_0_ele_45_0_wav};
  irMap[306][54] = {HRIR_48K_24bit::azi_306_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_306_0_ele_54_0_wav};
  irMap[306][60] = {HRIR_48K_24bit::azi_306_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_306_0_ele_60_0_wav};
  irMap[306][75] = {HRIR_48K_24bit::azi_306_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_306_0_ele_75_0_wav};
  irMap[306][90] = {HRIR_48K_24bit::azi_306_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_306_0_ele_90_0_wav};
  irMap[306][-15] = {HRIR_48K_24bit::azi_306_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_306_0_ele_neg15_0_wav};
  irMap[306][-25] = {HRIR_48K_24bit::azi_306_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_306_0_ele_neg25_0_wav};
  irMap[306][-30] = {HRIR_48K_24bit::azi_306_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_306_0_ele_neg30_0_wav};
  irMap[306][-45] = {HRIR_48K_24bit::azi_306_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_306_0_ele_neg45_0_wav};
  irMap[306][-54] = {HRIR_48K_24bit::azi_306_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_306_0_ele_neg54_0_wav};
  irMap[306][-60] = {HRIR_48K_24bit::azi_306_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_306_0_ele_neg60_0_wav};
  irMap[306][-75] = {HRIR_48K_24bit::azi_306_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_306_0_ele_neg75_0_wav};
  irMap[306][-81] = {HRIR_48K_24bit::azi_306_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_306_0_ele_neg81_0_wav};
  irMap[307][0] = {HRIR_48K_24bit::azi_307_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_307_0_ele_0_0_wav};
  irMap[307][15] = {HRIR_48K_24bit::azi_307_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_307_0_ele_15_0_wav};
  irMap[307][25] = {HRIR_48K_24bit::azi_307_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_307_0_ele_25_0_wav};
  irMap[307][30] = {HRIR_48K_24bit::azi_307_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_307_0_ele_30_0_wav};
  irMap[307][45] = {HRIR_48K_24bit::azi_307_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_307_0_ele_45_0_wav};
  irMap[307][54] = {HRIR_48K_24bit::azi_307_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_307_0_ele_54_0_wav};
  irMap[307][60] = {HRIR_48K_24bit::azi_307_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_307_0_ele_60_0_wav};
  irMap[307][75] = {HRIR_48K_24bit::azi_307_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_307_0_ele_75_0_wav};
  irMap[307][90] = {HRIR_48K_24bit::azi_307_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_307_0_ele_90_0_wav};
  irMap[307][-15] = {HRIR_48K_24bit::azi_307_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_307_0_ele_neg15_0_wav};
  irMap[307][-25] = {HRIR_48K_24bit::azi_307_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_307_0_ele_neg25_0_wav};
  irMap[307][-30] = {HRIR_48K_24bit::azi_307_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_307_0_ele_neg30_0_wav};
  irMap[307][-45] = {HRIR_48K_24bit::azi_307_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_307_0_ele_neg45_0_wav};
  irMap[307][-54] = {HRIR_48K_24bit::azi_307_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_307_0_ele_neg54_0_wav};
  irMap[307][-60] = {HRIR_48K_24bit::azi_307_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_307_0_ele_neg60_0_wav};
  irMap[307][-75] = {HRIR_48K_24bit::azi_307_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_307_0_ele_neg75_0_wav};
  irMap[307][-81] = {HRIR_48K_24bit::azi_307_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_307_0_ele_neg81_0_wav};
  irMap[308][0] = {HRIR_48K_24bit::azi_308_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_308_0_ele_0_0_wav};
  irMap[308][15] = {HRIR_48K_24bit::azi_308_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_308_0_ele_15_0_wav};
  irMap[308][25] = {HRIR_48K_24bit::azi_308_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_308_0_ele_25_0_wav};
  irMap[308][30] = {HRIR_48K_24bit::azi_308_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_308_0_ele_30_0_wav};
  irMap[308][45] = {HRIR_48K_24bit::azi_308_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_308_0_ele_45_0_wav};
  irMap[308][54] = {HRIR_48K_24bit::azi_308_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_308_0_ele_54_0_wav};
  irMap[308][60] = {HRIR_48K_24bit::azi_308_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_308_0_ele_60_0_wav};
  irMap[308][75] = {HRIR_48K_24bit::azi_308_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_308_0_ele_75_0_wav};
  irMap[308][90] = {HRIR_48K_24bit::azi_308_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_308_0_ele_90_0_wav};
  irMap[308][-15] = {HRIR_48K_24bit::azi_308_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_308_0_ele_neg15_0_wav};
  irMap[308][-25] = {HRIR_48K_24bit::azi_308_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_308_0_ele_neg25_0_wav};
  irMap[308][-30] = {HRIR_48K_24bit::azi_308_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_308_0_ele_neg30_0_wav};
  irMap[308][-45] = {HRIR_48K_24bit::azi_308_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_308_0_ele_neg45_0_wav};
  irMap[308][-54] = {HRIR_48K_24bit::azi_308_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_308_0_ele_neg54_0_wav};
  irMap[308][-60] = {HRIR_48K_24bit::azi_308_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_308_0_ele_neg60_0_wav};
  irMap[308][-75] = {HRIR_48K_24bit::azi_308_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_308_0_ele_neg75_0_wav};
  irMap[308][-81] = {HRIR_48K_24bit::azi_308_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_308_0_ele_neg81_0_wav};
  irMap[309][0] = {HRIR_48K_24bit::azi_309_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_309_0_ele_0_0_wav};
  irMap[309][15] = {HRIR_48K_24bit::azi_309_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_309_0_ele_15_0_wav};
  irMap[309][25] = {HRIR_48K_24bit::azi_309_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_309_0_ele_25_0_wav};
  irMap[309][30] = {HRIR_48K_24bit::azi_309_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_309_0_ele_30_0_wav};
  irMap[309][45] = {HRIR_48K_24bit::azi_309_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_309_0_ele_45_0_wav};
  irMap[309][54] = {HRIR_48K_24bit::azi_309_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_309_0_ele_54_0_wav};
  irMap[309][60] = {HRIR_48K_24bit::azi_309_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_309_0_ele_60_0_wav};
  irMap[309][75] = {HRIR_48K_24bit::azi_309_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_309_0_ele_75_0_wav};
  irMap[309][90] = {HRIR_48K_24bit::azi_309_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_309_0_ele_90_0_wav};
  irMap[309][-15] = {HRIR_48K_24bit::azi_309_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_309_0_ele_neg15_0_wav};
  irMap[309][-25] = {HRIR_48K_24bit::azi_309_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_309_0_ele_neg25_0_wav};
  irMap[309][-30] = {HRIR_48K_24bit::azi_309_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_309_0_ele_neg30_0_wav};
  irMap[309][-45] = {HRIR_48K_24bit::azi_309_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_309_0_ele_neg45_0_wav};
  irMap[309][-54] = {HRIR_48K_24bit::azi_309_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_309_0_ele_neg54_0_wav};
  irMap[309][-60] = {HRIR_48K_24bit::azi_309_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_309_0_ele_neg60_0_wav};
  irMap[309][-75] = {HRIR_48K_24bit::azi_309_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_309_0_ele_neg75_0_wav};
  irMap[309][-81] = {HRIR_48K_24bit::azi_309_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_309_0_ele_neg81_0_wav};
  irMap[310][0] = {HRIR_48K_24bit::azi_310_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_310_0_ele_0_0_wav};
  irMap[310][15] = {HRIR_48K_24bit::azi_310_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_310_0_ele_15_0_wav};
  irMap[310][25] = {HRIR_48K_24bit::azi_310_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_310_0_ele_25_0_wav};
  irMap[310][30] = {HRIR_48K_24bit::azi_310_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_310_0_ele_30_0_wav};
  irMap[310][45] = {HRIR_48K_24bit::azi_310_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_310_0_ele_45_0_wav};
  irMap[310][54] = {HRIR_48K_24bit::azi_310_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_310_0_ele_54_0_wav};
  irMap[310][60] = {HRIR_48K_24bit::azi_310_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_310_0_ele_60_0_wav};
  irMap[310][75] = {HRIR_48K_24bit::azi_310_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_310_0_ele_75_0_wav};
  irMap[310][90] = {HRIR_48K_24bit::azi_310_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_310_0_ele_90_0_wav};
  irMap[310][-15] = {HRIR_48K_24bit::azi_310_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_310_0_ele_neg15_0_wav};
  irMap[310][-25] = {HRIR_48K_24bit::azi_310_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_310_0_ele_neg25_0_wav};
  irMap[310][-30] = {HRIR_48K_24bit::azi_310_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_310_0_ele_neg30_0_wav};
  irMap[310][-45] = {HRIR_48K_24bit::azi_310_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_310_0_ele_neg45_0_wav};
  irMap[310][-54] = {HRIR_48K_24bit::azi_310_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_310_0_ele_neg54_0_wav};
  irMap[310][-60] = {HRIR_48K_24bit::azi_310_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_310_0_ele_neg60_0_wav};
  irMap[310][-75] = {HRIR_48K_24bit::azi_310_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_310_0_ele_neg75_0_wav};
  irMap[310][-81] = {HRIR_48K_24bit::azi_310_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_310_0_ele_neg81_0_wav};
  irMap[311][0] = {HRIR_48K_24bit::azi_311_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_311_0_ele_0_0_wav};
  irMap[311][15] = {HRIR_48K_24bit::azi_311_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_311_0_ele_15_0_wav};
  irMap[311][25] = {HRIR_48K_24bit::azi_311_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_311_0_ele_25_0_wav};
  irMap[311][30] = {HRIR_48K_24bit::azi_311_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_311_0_ele_30_0_wav};
  irMap[311][45] = {HRIR_48K_24bit::azi_311_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_311_0_ele_45_0_wav};
  irMap[311][54] = {HRIR_48K_24bit::azi_311_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_311_0_ele_54_0_wav};
  irMap[311][60] = {HRIR_48K_24bit::azi_311_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_311_0_ele_60_0_wav};
  irMap[311][75] = {HRIR_48K_24bit::azi_311_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_311_0_ele_75_0_wav};
  irMap[311][90] = {HRIR_48K_24bit::azi_311_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_311_0_ele_90_0_wav};
  irMap[311][-15] = {HRIR_48K_24bit::azi_311_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_311_0_ele_neg15_0_wav};
  irMap[311][-25] = {HRIR_48K_24bit::azi_311_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_311_0_ele_neg25_0_wav};
  irMap[311][-30] = {HRIR_48K_24bit::azi_311_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_311_0_ele_neg30_0_wav};
  irMap[311][-45] = {HRIR_48K_24bit::azi_311_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_311_0_ele_neg45_0_wav};
  irMap[311][-54] = {HRIR_48K_24bit::azi_311_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_311_0_ele_neg54_0_wav};
  irMap[311][-60] = {HRIR_48K_24bit::azi_311_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_311_0_ele_neg60_0_wav};
  irMap[311][-75] = {HRIR_48K_24bit::azi_311_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_311_0_ele_neg75_0_wav};
  irMap[311][-81] = {HRIR_48K_24bit::azi_311_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_311_0_ele_neg81_0_wav};
  irMap[312][0] = {HRIR_48K_24bit::azi_312_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_312_0_ele_0_0_wav};
  irMap[312][15] = {HRIR_48K_24bit::azi_312_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_312_0_ele_15_0_wav};
  irMap[312][25] = {HRIR_48K_24bit::azi_312_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_312_0_ele_25_0_wav};
  irMap[312][30] = {HRIR_48K_24bit::azi_312_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_312_0_ele_30_0_wav};
  irMap[312][45] = {HRIR_48K_24bit::azi_312_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_312_0_ele_45_0_wav};
  irMap[312][54] = {HRIR_48K_24bit::azi_312_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_312_0_ele_54_0_wav};
  irMap[312][60] = {HRIR_48K_24bit::azi_312_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_312_0_ele_60_0_wav};
  irMap[312][75] = {HRIR_48K_24bit::azi_312_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_312_0_ele_75_0_wav};
  irMap[312][90] = {HRIR_48K_24bit::azi_312_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_312_0_ele_90_0_wav};
  irMap[312][-15] = {HRIR_48K_24bit::azi_312_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_312_0_ele_neg15_0_wav};
  irMap[312][-25] = {HRIR_48K_24bit::azi_312_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_312_0_ele_neg25_0_wav};
  irMap[312][-30] = {HRIR_48K_24bit::azi_312_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_312_0_ele_neg30_0_wav};
  irMap[312][-45] = {HRIR_48K_24bit::azi_312_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_312_0_ele_neg45_0_wav};
  irMap[312][-54] = {HRIR_48K_24bit::azi_312_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_312_0_ele_neg54_0_wav};
  irMap[312][-60] = {HRIR_48K_24bit::azi_312_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_312_0_ele_neg60_0_wav};
  irMap[312][-75] = {HRIR_48K_24bit::azi_312_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_312_0_ele_neg75_0_wav};
  irMap[312][-81] = {HRIR_48K_24bit::azi_312_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_312_0_ele_neg81_0_wav};
  irMap[313][0] = {HRIR_48K_24bit::azi_313_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_313_0_ele_0_0_wav};
  irMap[313][15] = {HRIR_48K_24bit::azi_313_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_313_0_ele_15_0_wav};
  irMap[313][25] = {HRIR_48K_24bit::azi_313_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_313_0_ele_25_0_wav};
  irMap[313][30] = {HRIR_48K_24bit::azi_313_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_313_0_ele_30_0_wav};
  irMap[313][45] = {HRIR_48K_24bit::azi_313_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_313_0_ele_45_0_wav};
  irMap[313][54] = {HRIR_48K_24bit::azi_313_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_313_0_ele_54_0_wav};
  irMap[313][60] = {HRIR_48K_24bit::azi_313_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_313_0_ele_60_0_wav};
  irMap[313][75] = {HRIR_48K_24bit::azi_313_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_313_0_ele_75_0_wav};
  irMap[313][90] = {HRIR_48K_24bit::azi_313_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_313_0_ele_90_0_wav};
  irMap[313][-15] = {HRIR_48K_24bit::azi_313_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_313_0_ele_neg15_0_wav};
  irMap[313][-25] = {HRIR_48K_24bit::azi_313_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_313_0_ele_neg25_0_wav};
  irMap[313][-30] = {HRIR_48K_24bit::azi_313_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_313_0_ele_neg30_0_wav};
  irMap[313][-45] = {HRIR_48K_24bit::azi_313_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_313_0_ele_neg45_0_wav};
  irMap[313][-54] = {HRIR_48K_24bit::azi_313_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_313_0_ele_neg54_0_wav};
  irMap[313][-60] = {HRIR_48K_24bit::azi_313_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_313_0_ele_neg60_0_wav};
  irMap[313][-75] = {HRIR_48K_24bit::azi_313_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_313_0_ele_neg75_0_wav};
  irMap[313][-81] = {HRIR_48K_24bit::azi_313_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_313_0_ele_neg81_0_wav};
  irMap[314][0] = {HRIR_48K_24bit::azi_314_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_314_0_ele_0_0_wav};
  irMap[314][15] = {HRIR_48K_24bit::azi_314_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_314_0_ele_15_0_wav};
  irMap[314][25] = {HRIR_48K_24bit::azi_314_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_314_0_ele_25_0_wav};
  irMap[314][30] = {HRIR_48K_24bit::azi_314_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_314_0_ele_30_0_wav};
  irMap[314][45] = {HRIR_48K_24bit::azi_314_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_314_0_ele_45_0_wav};
  irMap[314][54] = {HRIR_48K_24bit::azi_314_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_314_0_ele_54_0_wav};
  irMap[314][60] = {HRIR_48K_24bit::azi_314_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_314_0_ele_60_0_wav};
  irMap[314][75] = {HRIR_48K_24bit::azi_314_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_314_0_ele_75_0_wav};
  irMap[314][90] = {HRIR_48K_24bit::azi_314_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_314_0_ele_90_0_wav};
  irMap[314][-15] = {HRIR_48K_24bit::azi_314_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_314_0_ele_neg15_0_wav};
  irMap[314][-25] = {HRIR_48K_24bit::azi_314_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_314_0_ele_neg25_0_wav};
  irMap[314][-30] = {HRIR_48K_24bit::azi_314_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_314_0_ele_neg30_0_wav};
  irMap[314][-45] = {HRIR_48K_24bit::azi_314_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_314_0_ele_neg45_0_wav};
  irMap[314][-54] = {HRIR_48K_24bit::azi_314_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_314_0_ele_neg54_0_wav};
  irMap[314][-60] = {HRIR_48K_24bit::azi_314_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_314_0_ele_neg60_0_wav};
  irMap[314][-75] = {HRIR_48K_24bit::azi_314_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_314_0_ele_neg75_0_wav};
  irMap[314][-81] = {HRIR_48K_24bit::azi_314_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_314_0_ele_neg81_0_wav};
  irMap[315][0] = {HRIR_48K_24bit::azi_315_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_315_0_ele_0_0_wav};
  irMap[315][15] = {HRIR_48K_24bit::azi_315_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_315_0_ele_15_0_wav};
  irMap[315][25] = {HRIR_48K_24bit::azi_315_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_315_0_ele_25_0_wav};
  irMap[315][30] = {HRIR_48K_24bit::azi_315_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_315_0_ele_30_0_wav};
  irMap[315][45] = {HRIR_48K_24bit::azi_315_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_315_0_ele_45_0_wav};
  irMap[315][54] = {HRIR_48K_24bit::azi_315_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_315_0_ele_54_0_wav};
  irMap[315][60] = {HRIR_48K_24bit::azi_315_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_315_0_ele_60_0_wav};
  irMap[315][75] = {HRIR_48K_24bit::azi_315_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_315_0_ele_75_0_wav};
  irMap[315][90] = {HRIR_48K_24bit::azi_315_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_315_0_ele_90_0_wav};
  irMap[315][-15] = {HRIR_48K_24bit::azi_315_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_315_0_ele_neg15_0_wav};
  irMap[315][-25] = {HRIR_48K_24bit::azi_315_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_315_0_ele_neg25_0_wav};
  irMap[315][-30] = {HRIR_48K_24bit::azi_315_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_315_0_ele_neg30_0_wav};
  irMap[315][-45] = {HRIR_48K_24bit::azi_315_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_315_0_ele_neg45_0_wav};
  irMap[315][-54] = {HRIR_48K_24bit::azi_315_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_315_0_ele_neg54_0_wav};
  irMap[315][-60] = {HRIR_48K_24bit::azi_315_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_315_0_ele_neg60_0_wav};
  irMap[315][-75] = {HRIR_48K_24bit::azi_315_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_315_0_ele_neg75_0_wav};
  irMap[315][-81] = {HRIR_48K_24bit::azi_315_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_315_0_ele_neg81_0_wav};
  irMap[316][0] = {HRIR_48K_24bit::azi_316_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_316_0_ele_0_0_wav};
  irMap[316][15] = {HRIR_48K_24bit::azi_316_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_316_0_ele_15_0_wav};
  irMap[316][25] = {HRIR_48K_24bit::azi_316_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_316_0_ele_25_0_wav};
  irMap[316][30] = {HRIR_48K_24bit::azi_316_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_316_0_ele_30_0_wav};
  irMap[316][45] = {HRIR_48K_24bit::azi_316_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_316_0_ele_45_0_wav};
  irMap[316][54] = {HRIR_48K_24bit::azi_316_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_316_0_ele_54_0_wav};
  irMap[316][60] = {HRIR_48K_24bit::azi_316_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_316_0_ele_60_0_wav};
  irMap[316][75] = {HRIR_48K_24bit::azi_316_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_316_0_ele_75_0_wav};
  irMap[316][90] = {HRIR_48K_24bit::azi_316_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_316_0_ele_90_0_wav};
  irMap[316][-15] = {HRIR_48K_24bit::azi_316_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_316_0_ele_neg15_0_wav};
  irMap[316][-25] = {HRIR_48K_24bit::azi_316_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_316_0_ele_neg25_0_wav};
  irMap[316][-30] = {HRIR_48K_24bit::azi_316_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_316_0_ele_neg30_0_wav};
  irMap[316][-45] = {HRIR_48K_24bit::azi_316_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_316_0_ele_neg45_0_wav};
  irMap[316][-54] = {HRIR_48K_24bit::azi_316_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_316_0_ele_neg54_0_wav};
  irMap[316][-60] = {HRIR_48K_24bit::azi_316_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_316_0_ele_neg60_0_wav};
  irMap[316][-75] = {HRIR_48K_24bit::azi_316_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_316_0_ele_neg75_0_wav};
  irMap[316][-81] = {HRIR_48K_24bit::azi_316_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_316_0_ele_neg81_0_wav};
  irMap[317][0] = {HRIR_48K_24bit::azi_317_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_317_0_ele_0_0_wav};
  irMap[317][15] = {HRIR_48K_24bit::azi_317_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_317_0_ele_15_0_wav};
  irMap[317][25] = {HRIR_48K_24bit::azi_317_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_317_0_ele_25_0_wav};
  irMap[317][30] = {HRIR_48K_24bit::azi_317_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_317_0_ele_30_0_wav};
  irMap[317][45] = {HRIR_48K_24bit::azi_317_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_317_0_ele_45_0_wav};
  irMap[317][54] = {HRIR_48K_24bit::azi_317_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_317_0_ele_54_0_wav};
  irMap[317][60] = {HRIR_48K_24bit::azi_317_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_317_0_ele_60_0_wav};
  irMap[317][75] = {HRIR_48K_24bit::azi_317_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_317_0_ele_75_0_wav};
  irMap[317][90] = {HRIR_48K_24bit::azi_317_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_317_0_ele_90_0_wav};
  irMap[317][-15] = {HRIR_48K_24bit::azi_317_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_317_0_ele_neg15_0_wav};
  irMap[317][-25] = {HRIR_48K_24bit::azi_317_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_317_0_ele_neg25_0_wav};
  irMap[317][-30] = {HRIR_48K_24bit::azi_317_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_317_0_ele_neg30_0_wav};
  irMap[317][-45] = {HRIR_48K_24bit::azi_317_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_317_0_ele_neg45_0_wav};
  irMap[317][-54] = {HRIR_48K_24bit::azi_317_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_317_0_ele_neg54_0_wav};
  irMap[317][-60] = {HRIR_48K_24bit::azi_317_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_317_0_ele_neg60_0_wav};
  irMap[317][-75] = {HRIR_48K_24bit::azi_317_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_317_0_ele_neg75_0_wav};
  irMap[317][-81] = {HRIR_48K_24bit::azi_317_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_317_0_ele_neg81_0_wav};
  irMap[318][0] = {HRIR_48K_24bit::azi_318_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_318_0_ele_0_0_wav};
  irMap[318][15] = {HRIR_48K_24bit::azi_318_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_318_0_ele_15_0_wav};
  irMap[318][25] = {HRIR_48K_24bit::azi_318_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_318_0_ele_25_0_wav};
  irMap[318][30] = {HRIR_48K_24bit::azi_318_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_318_0_ele_30_0_wav};
  irMap[318][45] = {HRIR_48K_24bit::azi_318_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_318_0_ele_45_0_wav};
  irMap[318][54] = {HRIR_48K_24bit::azi_318_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_318_0_ele_54_0_wav};
  irMap[318][60] = {HRIR_48K_24bit::azi_318_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_318_0_ele_60_0_wav};
  irMap[318][75] = {HRIR_48K_24bit::azi_318_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_318_0_ele_75_0_wav};
  irMap[318][90] = {HRIR_48K_24bit::azi_318_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_318_0_ele_90_0_wav};
  irMap[318][-15] = {HRIR_48K_24bit::azi_318_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_318_0_ele_neg15_0_wav};
  irMap[318][-25] = {HRIR_48K_24bit::azi_318_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_318_0_ele_neg25_0_wav};
  irMap[318][-30] = {HRIR_48K_24bit::azi_318_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_318_0_ele_neg30_0_wav};
  irMap[318][-45] = {HRIR_48K_24bit::azi_318_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_318_0_ele_neg45_0_wav};
  irMap[318][-54] = {HRIR_48K_24bit::azi_318_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_318_0_ele_neg54_0_wav};
  irMap[318][-60] = {HRIR_48K_24bit::azi_318_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_318_0_ele_neg60_0_wav};
  irMap[318][-75] = {HRIR_48K_24bit::azi_318_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_318_0_ele_neg75_0_wav};
  irMap[318][-81] = {HRIR_48K_24bit::azi_318_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_318_0_ele_neg81_0_wav};
  irMap[319][0] = {HRIR_48K_24bit::azi_319_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_319_0_ele_0_0_wav};
  irMap[319][15] = {HRIR_48K_24bit::azi_319_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_319_0_ele_15_0_wav};
  irMap[319][25] = {HRIR_48K_24bit::azi_319_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_319_0_ele_25_0_wav};
  irMap[319][30] = {HRIR_48K_24bit::azi_319_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_319_0_ele_30_0_wav};
  irMap[319][45] = {HRIR_48K_24bit::azi_319_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_319_0_ele_45_0_wav};
  irMap[319][54] = {HRIR_48K_24bit::azi_319_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_319_0_ele_54_0_wav};
  irMap[319][60] = {HRIR_48K_24bit::azi_319_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_319_0_ele_60_0_wav};
  irMap[319][75] = {HRIR_48K_24bit::azi_319_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_319_0_ele_75_0_wav};
  irMap[319][90] = {HRIR_48K_24bit::azi_319_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_319_0_ele_90_0_wav};
  irMap[319][-15] = {HRIR_48K_24bit::azi_319_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_319_0_ele_neg15_0_wav};
  irMap[319][-25] = {HRIR_48K_24bit::azi_319_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_319_0_ele_neg25_0_wav};
  irMap[319][-30] = {HRIR_48K_24bit::azi_319_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_319_0_ele_neg30_0_wav};
  irMap[319][-45] = {HRIR_48K_24bit::azi_319_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_319_0_ele_neg45_0_wav};
  irMap[319][-54] = {HRIR_48K_24bit::azi_319_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_319_0_ele_neg54_0_wav};
  irMap[319][-60] = {HRIR_48K_24bit::azi_319_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_319_0_ele_neg60_0_wav};
  irMap[319][-75] = {HRIR_48K_24bit::azi_319_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_319_0_ele_neg75_0_wav};
  irMap[319][-81] = {HRIR_48K_24bit::azi_319_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_319_0_ele_neg81_0_wav};
  irMap[320][0] = {HRIR_48K_24bit::azi_320_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_320_0_ele_0_0_wav};
  irMap[320][15] = {HRIR_48K_24bit::azi_320_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_320_0_ele_15_0_wav};
  irMap[320][25] = {HRIR_48K_24bit::azi_320_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_320_0_ele_25_0_wav};
  irMap[320][30] = {HRIR_48K_24bit::azi_320_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_320_0_ele_30_0_wav};
  irMap[320][45] = {HRIR_48K_24bit::azi_320_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_320_0_ele_45_0_wav};
  irMap[320][54] = {HRIR_48K_24bit::azi_320_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_320_0_ele_54_0_wav};
  irMap[320][60] = {HRIR_48K_24bit::azi_320_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_320_0_ele_60_0_wav};
  irMap[320][75] = {HRIR_48K_24bit::azi_320_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_320_0_ele_75_0_wav};
  irMap[320][90] = {HRIR_48K_24bit::azi_320_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_320_0_ele_90_0_wav};
  irMap[320][-15] = {HRIR_48K_24bit::azi_320_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_320_0_ele_neg15_0_wav};
  irMap[320][-25] = {HRIR_48K_24bit::azi_320_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_320_0_ele_neg25_0_wav};
  irMap[320][-30] = {HRIR_48K_24bit::azi_320_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_320_0_ele_neg30_0_wav};
  irMap[320][-45] = {HRIR_48K_24bit::azi_320_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_320_0_ele_neg45_0_wav};
  irMap[320][-54] = {HRIR_48K_24bit::azi_320_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_320_0_ele_neg54_0_wav};
  irMap[320][-60] = {HRIR_48K_24bit::azi_320_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_320_0_ele_neg60_0_wav};
  irMap[320][-75] = {HRIR_48K_24bit::azi_320_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_320_0_ele_neg75_0_wav};
  irMap[320][-81] = {HRIR_48K_24bit::azi_320_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_320_0_ele_neg81_0_wav};
  irMap[321][0] = {HRIR_48K_24bit::azi_321_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_321_0_ele_0_0_wav};
  irMap[321][15] = {HRIR_48K_24bit::azi_321_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_321_0_ele_15_0_wav};
  irMap[321][25] = {HRIR_48K_24bit::azi_321_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_321_0_ele_25_0_wav};
  irMap[321][30] = {HRIR_48K_24bit::azi_321_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_321_0_ele_30_0_wav};
  irMap[321][45] = {HRIR_48K_24bit::azi_321_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_321_0_ele_45_0_wav};
  irMap[321][54] = {HRIR_48K_24bit::azi_321_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_321_0_ele_54_0_wav};
  irMap[321][60] = {HRIR_48K_24bit::azi_321_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_321_0_ele_60_0_wav};
  irMap[321][75] = {HRIR_48K_24bit::azi_321_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_321_0_ele_75_0_wav};
  irMap[321][90] = {HRIR_48K_24bit::azi_321_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_321_0_ele_90_0_wav};
  irMap[321][-15] = {HRIR_48K_24bit::azi_321_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_321_0_ele_neg15_0_wav};
  irMap[321][-25] = {HRIR_48K_24bit::azi_321_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_321_0_ele_neg25_0_wav};
  irMap[321][-30] = {HRIR_48K_24bit::azi_321_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_321_0_ele_neg30_0_wav};
  irMap[321][-45] = {HRIR_48K_24bit::azi_321_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_321_0_ele_neg45_0_wav};
  irMap[321][-54] = {HRIR_48K_24bit::azi_321_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_321_0_ele_neg54_0_wav};
  irMap[321][-60] = {HRIR_48K_24bit::azi_321_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_321_0_ele_neg60_0_wav};
  irMap[321][-75] = {HRIR_48K_24bit::azi_321_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_321_0_ele_neg75_0_wav};
  irMap[321][-81] = {HRIR_48K_24bit::azi_321_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_321_0_ele_neg81_0_wav};
  irMap[322][0] = {HRIR_48K_24bit::azi_322_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_322_0_ele_0_0_wav};
  irMap[322][15] = {HRIR_48K_24bit::azi_322_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_322_0_ele_15_0_wav};
  irMap[322][25] = {HRIR_48K_24bit::azi_322_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_322_0_ele_25_0_wav};
  irMap[322][30] = {HRIR_48K_24bit::azi_322_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_322_0_ele_30_0_wav};
  irMap[322][45] = {HRIR_48K_24bit::azi_322_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_322_0_ele_45_0_wav};
  irMap[322][54] = {HRIR_48K_24bit::azi_322_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_322_0_ele_54_0_wav};
  irMap[322][60] = {HRIR_48K_24bit::azi_322_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_322_0_ele_60_0_wav};
  irMap[322][75] = {HRIR_48K_24bit::azi_322_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_322_0_ele_75_0_wav};
  irMap[322][90] = {HRIR_48K_24bit::azi_322_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_322_0_ele_90_0_wav};
  irMap[322][-15] = {HRIR_48K_24bit::azi_322_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_322_0_ele_neg15_0_wav};
  irMap[322][-25] = {HRIR_48K_24bit::azi_322_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_322_0_ele_neg25_0_wav};
  irMap[322][-30] = {HRIR_48K_24bit::azi_322_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_322_0_ele_neg30_0_wav};
  irMap[322][-45] = {HRIR_48K_24bit::azi_322_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_322_0_ele_neg45_0_wav};
  irMap[322][-54] = {HRIR_48K_24bit::azi_322_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_322_0_ele_neg54_0_wav};
  irMap[322][-60] = {HRIR_48K_24bit::azi_322_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_322_0_ele_neg60_0_wav};
  irMap[322][-75] = {HRIR_48K_24bit::azi_322_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_322_0_ele_neg75_0_wav};
  irMap[322][-81] = {HRIR_48K_24bit::azi_322_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_322_0_ele_neg81_0_wav};
  irMap[323][0] = {HRIR_48K_24bit::azi_323_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_323_0_ele_0_0_wav};
  irMap[323][15] = {HRIR_48K_24bit::azi_323_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_323_0_ele_15_0_wav};
  irMap[323][25] = {HRIR_48K_24bit::azi_323_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_323_0_ele_25_0_wav};
  irMap[323][30] = {HRIR_48K_24bit::azi_323_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_323_0_ele_30_0_wav};
  irMap[323][45] = {HRIR_48K_24bit::azi_323_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_323_0_ele_45_0_wav};
  irMap[323][54] = {HRIR_48K_24bit::azi_323_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_323_0_ele_54_0_wav};
  irMap[323][60] = {HRIR_48K_24bit::azi_323_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_323_0_ele_60_0_wav};
  irMap[323][75] = {HRIR_48K_24bit::azi_323_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_323_0_ele_75_0_wav};
  irMap[323][90] = {HRIR_48K_24bit::azi_323_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_323_0_ele_90_0_wav};
  irMap[323][-15] = {HRIR_48K_24bit::azi_323_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_323_0_ele_neg15_0_wav};
  irMap[323][-25] = {HRIR_48K_24bit::azi_323_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_323_0_ele_neg25_0_wav};
  irMap[323][-30] = {HRIR_48K_24bit::azi_323_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_323_0_ele_neg30_0_wav};
  irMap[323][-45] = {HRIR_48K_24bit::azi_323_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_323_0_ele_neg45_0_wav};
  irMap[323][-54] = {HRIR_48K_24bit::azi_323_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_323_0_ele_neg54_0_wav};
  irMap[323][-60] = {HRIR_48K_24bit::azi_323_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_323_0_ele_neg60_0_wav};
  irMap[323][-75] = {HRIR_48K_24bit::azi_323_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_323_0_ele_neg75_0_wav};
  irMap[323][-81] = {HRIR_48K_24bit::azi_323_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_323_0_ele_neg81_0_wav};
  irMap[324][0] = {HRIR_48K_24bit::azi_324_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_324_0_ele_0_0_wav};
  irMap[324][15] = {HRIR_48K_24bit::azi_324_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_324_0_ele_15_0_wav};
  irMap[324][25] = {HRIR_48K_24bit::azi_324_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_324_0_ele_25_0_wav};
  irMap[324][30] = {HRIR_48K_24bit::azi_324_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_324_0_ele_30_0_wav};
  irMap[324][45] = {HRIR_48K_24bit::azi_324_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_324_0_ele_45_0_wav};
  irMap[324][54] = {HRIR_48K_24bit::azi_324_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_324_0_ele_54_0_wav};
  irMap[324][60] = {HRIR_48K_24bit::azi_324_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_324_0_ele_60_0_wav};
  irMap[324][75] = {HRIR_48K_24bit::azi_324_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_324_0_ele_75_0_wav};
  irMap[324][90] = {HRIR_48K_24bit::azi_324_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_324_0_ele_90_0_wav};
  irMap[324][-15] = {HRIR_48K_24bit::azi_324_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_324_0_ele_neg15_0_wav};
  irMap[324][-25] = {HRIR_48K_24bit::azi_324_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_324_0_ele_neg25_0_wav};
  irMap[324][-30] = {HRIR_48K_24bit::azi_324_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_324_0_ele_neg30_0_wav};
  irMap[324][-45] = {HRIR_48K_24bit::azi_324_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_324_0_ele_neg45_0_wav};
  irMap[324][-54] = {HRIR_48K_24bit::azi_324_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_324_0_ele_neg54_0_wav};
  irMap[324][-60] = {HRIR_48K_24bit::azi_324_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_324_0_ele_neg60_0_wav};
  irMap[324][-75] = {HRIR_48K_24bit::azi_324_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_324_0_ele_neg75_0_wav};
  irMap[324][-81] = {HRIR_48K_24bit::azi_324_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_324_0_ele_neg81_0_wav};
  irMap[325][0] = {HRIR_48K_24bit::azi_325_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_325_0_ele_0_0_wav};
  irMap[325][15] = {HRIR_48K_24bit::azi_325_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_325_0_ele_15_0_wav};
  irMap[325][25] = {HRIR_48K_24bit::azi_325_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_325_0_ele_25_0_wav};
  irMap[325][30] = {HRIR_48K_24bit::azi_325_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_325_0_ele_30_0_wav};
  irMap[325][45] = {HRIR_48K_24bit::azi_325_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_325_0_ele_45_0_wav};
  irMap[325][54] = {HRIR_48K_24bit::azi_325_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_325_0_ele_54_0_wav};
  irMap[325][60] = {HRIR_48K_24bit::azi_325_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_325_0_ele_60_0_wav};
  irMap[325][75] = {HRIR_48K_24bit::azi_325_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_325_0_ele_75_0_wav};
  irMap[325][90] = {HRIR_48K_24bit::azi_325_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_325_0_ele_90_0_wav};
  irMap[325][-15] = {HRIR_48K_24bit::azi_325_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_325_0_ele_neg15_0_wav};
  irMap[325][-25] = {HRIR_48K_24bit::azi_325_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_325_0_ele_neg25_0_wav};
  irMap[325][-30] = {HRIR_48K_24bit::azi_325_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_325_0_ele_neg30_0_wav};
  irMap[325][-45] = {HRIR_48K_24bit::azi_325_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_325_0_ele_neg45_0_wav};
  irMap[325][-54] = {HRIR_48K_24bit::azi_325_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_325_0_ele_neg54_0_wav};
  irMap[325][-60] = {HRIR_48K_24bit::azi_325_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_325_0_ele_neg60_0_wav};
  irMap[325][-75] = {HRIR_48K_24bit::azi_325_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_325_0_ele_neg75_0_wav};
  irMap[325][-81] = {HRIR_48K_24bit::azi_325_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_325_0_ele_neg81_0_wav};
  irMap[326][0] = {HRIR_48K_24bit::azi_326_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_326_0_ele_0_0_wav};
  irMap[326][15] = {HRIR_48K_24bit::azi_326_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_326_0_ele_15_0_wav};
  irMap[326][25] = {HRIR_48K_24bit::azi_326_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_326_0_ele_25_0_wav};
  irMap[326][30] = {HRIR_48K_24bit::azi_326_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_326_0_ele_30_0_wav};
  irMap[326][45] = {HRIR_48K_24bit::azi_326_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_326_0_ele_45_0_wav};
  irMap[326][54] = {HRIR_48K_24bit::azi_326_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_326_0_ele_54_0_wav};
  irMap[326][60] = {HRIR_48K_24bit::azi_326_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_326_0_ele_60_0_wav};
  irMap[326][75] = {HRIR_48K_24bit::azi_326_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_326_0_ele_75_0_wav};
  irMap[326][90] = {HRIR_48K_24bit::azi_326_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_326_0_ele_90_0_wav};
  irMap[326][-15] = {HRIR_48K_24bit::azi_326_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_326_0_ele_neg15_0_wav};
  irMap[326][-25] = {HRIR_48K_24bit::azi_326_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_326_0_ele_neg25_0_wav};
  irMap[326][-30] = {HRIR_48K_24bit::azi_326_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_326_0_ele_neg30_0_wav};
  irMap[326][-45] = {HRIR_48K_24bit::azi_326_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_326_0_ele_neg45_0_wav};
  irMap[326][-54] = {HRIR_48K_24bit::azi_326_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_326_0_ele_neg54_0_wav};
  irMap[326][-60] = {HRIR_48K_24bit::azi_326_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_326_0_ele_neg60_0_wav};
  irMap[326][-75] = {HRIR_48K_24bit::azi_326_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_326_0_ele_neg75_0_wav};
  irMap[326][-81] = {HRIR_48K_24bit::azi_326_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_326_0_ele_neg81_0_wav};
  irMap[327][0] = {HRIR_48K_24bit::azi_327_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_327_0_ele_0_0_wav};
  irMap[327][15] = {HRIR_48K_24bit::azi_327_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_327_0_ele_15_0_wav};
  irMap[327][25] = {HRIR_48K_24bit::azi_327_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_327_0_ele_25_0_wav};
  irMap[327][30] = {HRIR_48K_24bit::azi_327_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_327_0_ele_30_0_wav};
  irMap[327][45] = {HRIR_48K_24bit::azi_327_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_327_0_ele_45_0_wav};
  irMap[327][54] = {HRIR_48K_24bit::azi_327_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_327_0_ele_54_0_wav};
  irMap[327][60] = {HRIR_48K_24bit::azi_327_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_327_0_ele_60_0_wav};
  irMap[327][75] = {HRIR_48K_24bit::azi_327_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_327_0_ele_75_0_wav};
  irMap[327][90] = {HRIR_48K_24bit::azi_327_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_327_0_ele_90_0_wav};
  irMap[327][-15] = {HRIR_48K_24bit::azi_327_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_327_0_ele_neg15_0_wav};
  irMap[327][-25] = {HRIR_48K_24bit::azi_327_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_327_0_ele_neg25_0_wav};
  irMap[327][-30] = {HRIR_48K_24bit::azi_327_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_327_0_ele_neg30_0_wav};
  irMap[327][-45] = {HRIR_48K_24bit::azi_327_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_327_0_ele_neg45_0_wav};
  irMap[327][-54] = {HRIR_48K_24bit::azi_327_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_327_0_ele_neg54_0_wav};
  irMap[327][-60] = {HRIR_48K_24bit::azi_327_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_327_0_ele_neg60_0_wav};
  irMap[327][-75] = {HRIR_48K_24bit::azi_327_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_327_0_ele_neg75_0_wav};
  irMap[327][-81] = {HRIR_48K_24bit::azi_327_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_327_0_ele_neg81_0_wav};
  irMap[328][0] = {HRIR_48K_24bit::azi_328_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_328_0_ele_0_0_wav};
  irMap[328][15] = {HRIR_48K_24bit::azi_328_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_328_0_ele_15_0_wav};
  irMap[328][25] = {HRIR_48K_24bit::azi_328_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_328_0_ele_25_0_wav};
  irMap[328][30] = {HRIR_48K_24bit::azi_328_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_328_0_ele_30_0_wav};
  irMap[328][45] = {HRIR_48K_24bit::azi_328_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_328_0_ele_45_0_wav};
  irMap[328][54] = {HRIR_48K_24bit::azi_328_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_328_0_ele_54_0_wav};
  irMap[328][60] = {HRIR_48K_24bit::azi_328_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_328_0_ele_60_0_wav};
  irMap[328][75] = {HRIR_48K_24bit::azi_328_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_328_0_ele_75_0_wav};
  irMap[328][90] = {HRIR_48K_24bit::azi_328_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_328_0_ele_90_0_wav};
  irMap[328][-15] = {HRIR_48K_24bit::azi_328_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_328_0_ele_neg15_0_wav};
  irMap[328][-25] = {HRIR_48K_24bit::azi_328_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_328_0_ele_neg25_0_wav};
  irMap[328][-30] = {HRIR_48K_24bit::azi_328_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_328_0_ele_neg30_0_wav};
  irMap[328][-45] = {HRIR_48K_24bit::azi_328_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_328_0_ele_neg45_0_wav};
  irMap[328][-54] = {HRIR_48K_24bit::azi_328_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_328_0_ele_neg54_0_wav};
  irMap[328][-60] = {HRIR_48K_24bit::azi_328_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_328_0_ele_neg60_0_wav};
  irMap[328][-75] = {HRIR_48K_24bit::azi_328_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_328_0_ele_neg75_0_wav};
  irMap[328][-81] = {HRIR_48K_24bit::azi_328_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_328_0_ele_neg81_0_wav};
  irMap[329][0] = {HRIR_48K_24bit::azi_329_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_329_0_ele_0_0_wav};
  irMap[329][15] = {HRIR_48K_24bit::azi_329_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_329_0_ele_15_0_wav};
  irMap[329][25] = {HRIR_48K_24bit::azi_329_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_329_0_ele_25_0_wav};
  irMap[329][30] = {HRIR_48K_24bit::azi_329_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_329_0_ele_30_0_wav};
  irMap[329][45] = {HRIR_48K_24bit::azi_329_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_329_0_ele_45_0_wav};
  irMap[329][54] = {HRIR_48K_24bit::azi_329_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_329_0_ele_54_0_wav};
  irMap[329][60] = {HRIR_48K_24bit::azi_329_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_329_0_ele_60_0_wav};
  irMap[329][75] = {HRIR_48K_24bit::azi_329_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_329_0_ele_75_0_wav};
  irMap[329][90] = {HRIR_48K_24bit::azi_329_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_329_0_ele_90_0_wav};
  irMap[329][-15] = {HRIR_48K_24bit::azi_329_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_329_0_ele_neg15_0_wav};
  irMap[329][-25] = {HRIR_48K_24bit::azi_329_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_329_0_ele_neg25_0_wav};
  irMap[329][-30] = {HRIR_48K_24bit::azi_329_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_329_0_ele_neg30_0_wav};
  irMap[329][-45] = {HRIR_48K_24bit::azi_329_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_329_0_ele_neg45_0_wav};
  irMap[329][-54] = {HRIR_48K_24bit::azi_329_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_329_0_ele_neg54_0_wav};
  irMap[329][-60] = {HRIR_48K_24bit::azi_329_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_329_0_ele_neg60_0_wav};
  irMap[329][-75] = {HRIR_48K_24bit::azi_329_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_329_0_ele_neg75_0_wav};
  irMap[329][-81] = {HRIR_48K_24bit::azi_329_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_329_0_ele_neg81_0_wav};
  irMap[330][0] = {HRIR_48K_24bit::azi_330_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_330_0_ele_0_0_wav};
  irMap[330][15] = {HRIR_48K_24bit::azi_330_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_330_0_ele_15_0_wav};
  irMap[330][25] = {HRIR_48K_24bit::azi_330_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_330_0_ele_25_0_wav};
  irMap[330][30] = {HRIR_48K_24bit::azi_330_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_330_0_ele_30_0_wav};
  irMap[330][45] = {HRIR_48K_24bit::azi_330_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_330_0_ele_45_0_wav};
  irMap[330][54] = {HRIR_48K_24bit::azi_330_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_330_0_ele_54_0_wav};
  irMap[330][60] = {HRIR_48K_24bit::azi_330_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_330_0_ele_60_0_wav};
  irMap[330][75] = {HRIR_48K_24bit::azi_330_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_330_0_ele_75_0_wav};
  irMap[330][90] = {HRIR_48K_24bit::azi_330_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_330_0_ele_90_0_wav};
  irMap[330][-15] = {HRIR_48K_24bit::azi_330_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_330_0_ele_neg15_0_wav};
  irMap[330][-25] = {HRIR_48K_24bit::azi_330_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_330_0_ele_neg25_0_wav};
  irMap[330][-30] = {HRIR_48K_24bit::azi_330_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_330_0_ele_neg30_0_wav};
  irMap[330][-45] = {HRIR_48K_24bit::azi_330_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_330_0_ele_neg45_0_wav};
  irMap[330][-54] = {HRIR_48K_24bit::azi_330_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_330_0_ele_neg54_0_wav};
  irMap[330][-60] = {HRIR_48K_24bit::azi_330_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_330_0_ele_neg60_0_wav};
  irMap[330][-75] = {HRIR_48K_24bit::azi_330_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_330_0_ele_neg75_0_wav};
  irMap[330][-81] = {HRIR_48K_24bit::azi_330_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_330_0_ele_neg81_0_wav};
  irMap[331][0] = {HRIR_48K_24bit::azi_331_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_331_0_ele_0_0_wav};
  irMap[331][15] = {HRIR_48K_24bit::azi_331_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_331_0_ele_15_0_wav};
  irMap[331][25] = {HRIR_48K_24bit::azi_331_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_331_0_ele_25_0_wav};
  irMap[331][30] = {HRIR_48K_24bit::azi_331_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_331_0_ele_30_0_wav};
  irMap[331][45] = {HRIR_48K_24bit::azi_331_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_331_0_ele_45_0_wav};
  irMap[331][54] = {HRIR_48K_24bit::azi_331_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_331_0_ele_54_0_wav};
  irMap[331][60] = {HRIR_48K_24bit::azi_331_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_331_0_ele_60_0_wav};
  irMap[331][75] = {HRIR_48K_24bit::azi_331_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_331_0_ele_75_0_wav};
  irMap[331][90] = {HRIR_48K_24bit::azi_331_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_331_0_ele_90_0_wav};
  irMap[331][-15] = {HRIR_48K_24bit::azi_331_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_331_0_ele_neg15_0_wav};
  irMap[331][-25] = {HRIR_48K_24bit::azi_331_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_331_0_ele_neg25_0_wav};
  irMap[331][-30] = {HRIR_48K_24bit::azi_331_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_331_0_ele_neg30_0_wav};
  irMap[331][-45] = {HRIR_48K_24bit::azi_331_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_331_0_ele_neg45_0_wav};
  irMap[331][-54] = {HRIR_48K_24bit::azi_331_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_331_0_ele_neg54_0_wav};
  irMap[331][-60] = {HRIR_48K_24bit::azi_331_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_331_0_ele_neg60_0_wav};
  irMap[331][-75] = {HRIR_48K_24bit::azi_331_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_331_0_ele_neg75_0_wav};
  irMap[331][-81] = {HRIR_48K_24bit::azi_331_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_331_0_ele_neg81_0_wav};
  irMap[332][0] = {HRIR_48K_24bit::azi_332_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_332_0_ele_0_0_wav};
  irMap[332][15] = {HRIR_48K_24bit::azi_332_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_332_0_ele_15_0_wav};
  irMap[332][25] = {HRIR_48K_24bit::azi_332_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_332_0_ele_25_0_wav};
  irMap[332][30] = {HRIR_48K_24bit::azi_332_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_332_0_ele_30_0_wav};
  irMap[332][45] = {HRIR_48K_24bit::azi_332_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_332_0_ele_45_0_wav};
  irMap[332][54] = {HRIR_48K_24bit::azi_332_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_332_0_ele_54_0_wav};
  irMap[332][60] = {HRIR_48K_24bit::azi_332_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_332_0_ele_60_0_wav};
  irMap[332][75] = {HRIR_48K_24bit::azi_332_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_332_0_ele_75_0_wav};
  irMap[332][90] = {HRIR_48K_24bit::azi_332_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_332_0_ele_90_0_wav};
  irMap[332][-15] = {HRIR_48K_24bit::azi_332_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_332_0_ele_neg15_0_wav};
  irMap[332][-25] = {HRIR_48K_24bit::azi_332_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_332_0_ele_neg25_0_wav};
  irMap[332][-30] = {HRIR_48K_24bit::azi_332_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_332_0_ele_neg30_0_wav};
  irMap[332][-45] = {HRIR_48K_24bit::azi_332_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_332_0_ele_neg45_0_wav};
  irMap[332][-54] = {HRIR_48K_24bit::azi_332_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_332_0_ele_neg54_0_wav};
  irMap[332][-60] = {HRIR_48K_24bit::azi_332_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_332_0_ele_neg60_0_wav};
  irMap[332][-75] = {HRIR_48K_24bit::azi_332_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_332_0_ele_neg75_0_wav};
  irMap[332][-81] = {HRIR_48K_24bit::azi_332_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_332_0_ele_neg81_0_wav};
  irMap[333][0] = {HRIR_48K_24bit::azi_333_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_333_0_ele_0_0_wav};
  irMap[333][15] = {HRIR_48K_24bit::azi_333_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_333_0_ele_15_0_wav};
  irMap[333][25] = {HRIR_48K_24bit::azi_333_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_333_0_ele_25_0_wav};
  irMap[333][30] = {HRIR_48K_24bit::azi_333_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_333_0_ele_30_0_wav};
  irMap[333][45] = {HRIR_48K_24bit::azi_333_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_333_0_ele_45_0_wav};
  irMap[333][54] = {HRIR_48K_24bit::azi_333_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_333_0_ele_54_0_wav};
  irMap[333][60] = {HRIR_48K_24bit::azi_333_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_333_0_ele_60_0_wav};
  irMap[333][75] = {HRIR_48K_24bit::azi_333_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_333_0_ele_75_0_wav};
  irMap[333][90] = {HRIR_48K_24bit::azi_333_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_333_0_ele_90_0_wav};
  irMap[333][-15] = {HRIR_48K_24bit::azi_333_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_333_0_ele_neg15_0_wav};
  irMap[333][-25] = {HRIR_48K_24bit::azi_333_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_333_0_ele_neg25_0_wav};
  irMap[333][-30] = {HRIR_48K_24bit::azi_333_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_333_0_ele_neg30_0_wav};
  irMap[333][-45] = {HRIR_48K_24bit::azi_333_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_333_0_ele_neg45_0_wav};
  irMap[333][-54] = {HRIR_48K_24bit::azi_333_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_333_0_ele_neg54_0_wav};
  irMap[333][-60] = {HRIR_48K_24bit::azi_333_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_333_0_ele_neg60_0_wav};
  irMap[333][-75] = {HRIR_48K_24bit::azi_333_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_333_0_ele_neg75_0_wav};
  irMap[333][-81] = {HRIR_48K_24bit::azi_333_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_333_0_ele_neg81_0_wav};
  irMap[334][0] = {HRIR_48K_24bit::azi_334_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_334_0_ele_0_0_wav};
  irMap[334][15] = {HRIR_48K_24bit::azi_334_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_334_0_ele_15_0_wav};
  irMap[334][25] = {HRIR_48K_24bit::azi_334_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_334_0_ele_25_0_wav};
  irMap[334][30] = {HRIR_48K_24bit::azi_334_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_334_0_ele_30_0_wav};
  irMap[334][45] = {HRIR_48K_24bit::azi_334_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_334_0_ele_45_0_wav};
  irMap[334][54] = {HRIR_48K_24bit::azi_334_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_334_0_ele_54_0_wav};
  irMap[334][60] = {HRIR_48K_24bit::azi_334_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_334_0_ele_60_0_wav};
  irMap[334][75] = {HRIR_48K_24bit::azi_334_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_334_0_ele_75_0_wav};
  irMap[334][90] = {HRIR_48K_24bit::azi_334_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_334_0_ele_90_0_wav};
  irMap[334][-15] = {HRIR_48K_24bit::azi_334_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_334_0_ele_neg15_0_wav};
  irMap[334][-25] = {HRIR_48K_24bit::azi_334_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_334_0_ele_neg25_0_wav};
  irMap[334][-30] = {HRIR_48K_24bit::azi_334_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_334_0_ele_neg30_0_wav};
  irMap[334][-45] = {HRIR_48K_24bit::azi_334_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_334_0_ele_neg45_0_wav};
  irMap[334][-54] = {HRIR_48K_24bit::azi_334_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_334_0_ele_neg54_0_wav};
  irMap[334][-60] = {HRIR_48K_24bit::azi_334_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_334_0_ele_neg60_0_wav};
  irMap[334][-75] = {HRIR_48K_24bit::azi_334_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_334_0_ele_neg75_0_wav};
  irMap[334][-81] = {HRIR_48K_24bit::azi_334_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_334_0_ele_neg81_0_wav};
  irMap[335][0] = {HRIR_48K_24bit::azi_335_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_335_0_ele_0_0_wav};
  irMap[335][15] = {HRIR_48K_24bit::azi_335_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_335_0_ele_15_0_wav};
  irMap[335][25] = {HRIR_48K_24bit::azi_335_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_335_0_ele_25_0_wav};
  irMap[335][30] = {HRIR_48K_24bit::azi_335_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_335_0_ele_30_0_wav};
  irMap[335][45] = {HRIR_48K_24bit::azi_335_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_335_0_ele_45_0_wav};
  irMap[335][54] = {HRIR_48K_24bit::azi_335_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_335_0_ele_54_0_wav};
  irMap[335][60] = {HRIR_48K_24bit::azi_335_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_335_0_ele_60_0_wav};
  irMap[335][75] = {HRIR_48K_24bit::azi_335_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_335_0_ele_75_0_wav};
  irMap[335][90] = {HRIR_48K_24bit::azi_335_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_335_0_ele_90_0_wav};
  irMap[335][-15] = {HRIR_48K_24bit::azi_335_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_335_0_ele_neg15_0_wav};
  irMap[335][-25] = {HRIR_48K_24bit::azi_335_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_335_0_ele_neg25_0_wav};
  irMap[335][-30] = {HRIR_48K_24bit::azi_335_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_335_0_ele_neg30_0_wav};
  irMap[335][-45] = {HRIR_48K_24bit::azi_335_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_335_0_ele_neg45_0_wav};
  irMap[335][-54] = {HRIR_48K_24bit::azi_335_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_335_0_ele_neg54_0_wav};
  irMap[335][-60] = {HRIR_48K_24bit::azi_335_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_335_0_ele_neg60_0_wav};
  irMap[335][-75] = {HRIR_48K_24bit::azi_335_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_335_0_ele_neg75_0_wav};
  irMap[335][-81] = {HRIR_48K_24bit::azi_335_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_335_0_ele_neg81_0_wav};
  irMap[336][0] = {HRIR_48K_24bit::azi_336_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_336_0_ele_0_0_wav};
  irMap[336][15] = {HRIR_48K_24bit::azi_336_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_336_0_ele_15_0_wav};
  irMap[336][25] = {HRIR_48K_24bit::azi_336_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_336_0_ele_25_0_wav};
  irMap[336][30] = {HRIR_48K_24bit::azi_336_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_336_0_ele_30_0_wav};
  irMap[336][45] = {HRIR_48K_24bit::azi_336_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_336_0_ele_45_0_wav};
  irMap[336][54] = {HRIR_48K_24bit::azi_336_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_336_0_ele_54_0_wav};
  irMap[336][60] = {HRIR_48K_24bit::azi_336_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_336_0_ele_60_0_wav};
  irMap[336][75] = {HRIR_48K_24bit::azi_336_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_336_0_ele_75_0_wav};
  irMap[336][90] = {HRIR_48K_24bit::azi_336_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_336_0_ele_90_0_wav};
  irMap[336][-15] = {HRIR_48K_24bit::azi_336_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_336_0_ele_neg15_0_wav};
  irMap[336][-25] = {HRIR_48K_24bit::azi_336_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_336_0_ele_neg25_0_wav};
  irMap[336][-30] = {HRIR_48K_24bit::azi_336_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_336_0_ele_neg30_0_wav};
  irMap[336][-45] = {HRIR_48K_24bit::azi_336_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_336_0_ele_neg45_0_wav};
  irMap[336][-54] = {HRIR_48K_24bit::azi_336_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_336_0_ele_neg54_0_wav};
  irMap[336][-60] = {HRIR_48K_24bit::azi_336_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_336_0_ele_neg60_0_wav};
  irMap[336][-75] = {HRIR_48K_24bit::azi_336_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_336_0_ele_neg75_0_wav};
  irMap[336][-81] = {HRIR_48K_24bit::azi_336_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_336_0_ele_neg81_0_wav};
  irMap[337][0] = {HRIR_48K_24bit::azi_337_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_337_0_ele_0_0_wav};
  irMap[337][15] = {HRIR_48K_24bit::azi_337_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_337_0_ele_15_0_wav};
  irMap[337][25] = {HRIR_48K_24bit::azi_337_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_337_0_ele_25_0_wav};
  irMap[337][30] = {HRIR_48K_24bit::azi_337_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_337_0_ele_30_0_wav};
  irMap[337][45] = {HRIR_48K_24bit::azi_337_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_337_0_ele_45_0_wav};
  irMap[337][54] = {HRIR_48K_24bit::azi_337_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_337_0_ele_54_0_wav};
  irMap[337][60] = {HRIR_48K_24bit::azi_337_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_337_0_ele_60_0_wav};
  irMap[337][75] = {HRIR_48K_24bit::azi_337_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_337_0_ele_75_0_wav};
  irMap[337][90] = {HRIR_48K_24bit::azi_337_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_337_0_ele_90_0_wav};
  irMap[337][-15] = {HRIR_48K_24bit::azi_337_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_337_0_ele_neg15_0_wav};
  irMap[337][-25] = {HRIR_48K_24bit::azi_337_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_337_0_ele_neg25_0_wav};
  irMap[337][-30] = {HRIR_48K_24bit::azi_337_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_337_0_ele_neg30_0_wav};
  irMap[337][-45] = {HRIR_48K_24bit::azi_337_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_337_0_ele_neg45_0_wav};
  irMap[337][-54] = {HRIR_48K_24bit::azi_337_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_337_0_ele_neg54_0_wav};
  irMap[337][-60] = {HRIR_48K_24bit::azi_337_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_337_0_ele_neg60_0_wav};
  irMap[337][-75] = {HRIR_48K_24bit::azi_337_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_337_0_ele_neg75_0_wav};
  irMap[337][-81] = {HRIR_48K_24bit::azi_337_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_337_0_ele_neg81_0_wav};
  irMap[338][0] = {HRIR_48K_24bit::azi_338_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_338_0_ele_0_0_wav};
  irMap[338][15] = {HRIR_48K_24bit::azi_338_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_338_0_ele_15_0_wav};
  irMap[338][25] = {HRIR_48K_24bit::azi_338_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_338_0_ele_25_0_wav};
  irMap[338][30] = {HRIR_48K_24bit::azi_338_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_338_0_ele_30_0_wav};
  irMap[338][45] = {HRIR_48K_24bit::azi_338_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_338_0_ele_45_0_wav};
  irMap[338][54] = {HRIR_48K_24bit::azi_338_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_338_0_ele_54_0_wav};
  irMap[338][60] = {HRIR_48K_24bit::azi_338_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_338_0_ele_60_0_wav};
  irMap[338][75] = {HRIR_48K_24bit::azi_338_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_338_0_ele_75_0_wav};
  irMap[338][90] = {HRIR_48K_24bit::azi_338_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_338_0_ele_90_0_wav};
  irMap[338][-15] = {HRIR_48K_24bit::azi_338_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_338_0_ele_neg15_0_wav};
  irMap[338][-25] = {HRIR_48K_24bit::azi_338_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_338_0_ele_neg25_0_wav};
  irMap[338][-30] = {HRIR_48K_24bit::azi_338_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_338_0_ele_neg30_0_wav};
  irMap[338][-45] = {HRIR_48K_24bit::azi_338_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_338_0_ele_neg45_0_wav};
  irMap[338][-54] = {HRIR_48K_24bit::azi_338_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_338_0_ele_neg54_0_wav};
  irMap[338][-60] = {HRIR_48K_24bit::azi_338_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_338_0_ele_neg60_0_wav};
  irMap[338][-75] = {HRIR_48K_24bit::azi_338_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_338_0_ele_neg75_0_wav};
  irMap[338][-81] = {HRIR_48K_24bit::azi_338_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_338_0_ele_neg81_0_wav};
  irMap[339][0] = {HRIR_48K_24bit::azi_339_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_339_0_ele_0_0_wav};
  irMap[339][15] = {HRIR_48K_24bit::azi_339_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_339_0_ele_15_0_wav};
  irMap[339][25] = {HRIR_48K_24bit::azi_339_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_339_0_ele_25_0_wav};
  irMap[339][30] = {HRIR_48K_24bit::azi_339_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_339_0_ele_30_0_wav};
  irMap[339][45] = {HRIR_48K_24bit::azi_339_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_339_0_ele_45_0_wav};
  irMap[339][54] = {HRIR_48K_24bit::azi_339_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_339_0_ele_54_0_wav};
  irMap[339][60] = {HRIR_48K_24bit::azi_339_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_339_0_ele_60_0_wav};
  irMap[339][75] = {HRIR_48K_24bit::azi_339_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_339_0_ele_75_0_wav};
  irMap[339][90] = {HRIR_48K_24bit::azi_339_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_339_0_ele_90_0_wav};
  irMap[339][-15] = {HRIR_48K_24bit::azi_339_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_339_0_ele_neg15_0_wav};
  irMap[339][-25] = {HRIR_48K_24bit::azi_339_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_339_0_ele_neg25_0_wav};
  irMap[339][-30] = {HRIR_48K_24bit::azi_339_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_339_0_ele_neg30_0_wav};
  irMap[339][-45] = {HRIR_48K_24bit::azi_339_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_339_0_ele_neg45_0_wav};
  irMap[339][-54] = {HRIR_48K_24bit::azi_339_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_339_0_ele_neg54_0_wav};
  irMap[339][-60] = {HRIR_48K_24bit::azi_339_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_339_0_ele_neg60_0_wav};
  irMap[339][-75] = {HRIR_48K_24bit::azi_339_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_339_0_ele_neg75_0_wav};
  irMap[339][-81] = {HRIR_48K_24bit::azi_339_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_339_0_ele_neg81_0_wav};
  irMap[340][0] = {HRIR_48K_24bit::azi_340_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_340_0_ele_0_0_wav};
  irMap[340][15] = {HRIR_48K_24bit::azi_340_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_340_0_ele_15_0_wav};
  irMap[340][25] = {HRIR_48K_24bit::azi_340_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_340_0_ele_25_0_wav};
  irMap[340][30] = {HRIR_48K_24bit::azi_340_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_340_0_ele_30_0_wav};
  irMap[340][45] = {HRIR_48K_24bit::azi_340_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_340_0_ele_45_0_wav};
  irMap[340][54] = {HRIR_48K_24bit::azi_340_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_340_0_ele_54_0_wav};
  irMap[340][60] = {HRIR_48K_24bit::azi_340_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_340_0_ele_60_0_wav};
  irMap[340][75] = {HRIR_48K_24bit::azi_340_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_340_0_ele_75_0_wav};
  irMap[340][90] = {HRIR_48K_24bit::azi_340_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_340_0_ele_90_0_wav};
  irMap[340][-15] = {HRIR_48K_24bit::azi_340_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_340_0_ele_neg15_0_wav};
  irMap[340][-25] = {HRIR_48K_24bit::azi_340_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_340_0_ele_neg25_0_wav};
  irMap[340][-30] = {HRIR_48K_24bit::azi_340_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_340_0_ele_neg30_0_wav};
  irMap[340][-45] = {HRIR_48K_24bit::azi_340_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_340_0_ele_neg45_0_wav};
  irMap[340][-54] = {HRIR_48K_24bit::azi_340_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_340_0_ele_neg54_0_wav};
  irMap[340][-60] = {HRIR_48K_24bit::azi_340_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_340_0_ele_neg60_0_wav};
  irMap[340][-75] = {HRIR_48K_24bit::azi_340_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_340_0_ele_neg75_0_wav};
  irMap[340][-81] = {HRIR_48K_24bit::azi_340_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_340_0_ele_neg81_0_wav};
  irMap[341][0] = {HRIR_48K_24bit::azi_341_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_341_0_ele_0_0_wav};
  irMap[341][15] = {HRIR_48K_24bit::azi_341_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_341_0_ele_15_0_wav};
  irMap[341][25] = {HRIR_48K_24bit::azi_341_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_341_0_ele_25_0_wav};
  irMap[341][30] = {HRIR_48K_24bit::azi_341_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_341_0_ele_30_0_wav};
  irMap[341][45] = {HRIR_48K_24bit::azi_341_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_341_0_ele_45_0_wav};
  irMap[341][54] = {HRIR_48K_24bit::azi_341_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_341_0_ele_54_0_wav};
  irMap[341][60] = {HRIR_48K_24bit::azi_341_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_341_0_ele_60_0_wav};
  irMap[341][75] = {HRIR_48K_24bit::azi_341_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_341_0_ele_75_0_wav};
  irMap[341][90] = {HRIR_48K_24bit::azi_341_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_341_0_ele_90_0_wav};
  irMap[341][-15] = {HRIR_48K_24bit::azi_341_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_341_0_ele_neg15_0_wav};
  irMap[341][-25] = {HRIR_48K_24bit::azi_341_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_341_0_ele_neg25_0_wav};
  irMap[341][-30] = {HRIR_48K_24bit::azi_341_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_341_0_ele_neg30_0_wav};
  irMap[341][-45] = {HRIR_48K_24bit::azi_341_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_341_0_ele_neg45_0_wav};
  irMap[341][-54] = {HRIR_48K_24bit::azi_341_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_341_0_ele_neg54_0_wav};
  irMap[341][-60] = {HRIR_48K_24bit::azi_341_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_341_0_ele_neg60_0_wav};
  irMap[341][-75] = {HRIR_48K_24bit::azi_341_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_341_0_ele_neg75_0_wav};
  irMap[341][-81] = {HRIR_48K_24bit::azi_341_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_341_0_ele_neg81_0_wav};
  irMap[342][0] = {HRIR_48K_24bit::azi_342_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_342_0_ele_0_0_wav};
  irMap[342][15] = {HRIR_48K_24bit::azi_342_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_342_0_ele_15_0_wav};
  irMap[342][25] = {HRIR_48K_24bit::azi_342_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_342_0_ele_25_0_wav};
  irMap[342][30] = {HRIR_48K_24bit::azi_342_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_342_0_ele_30_0_wav};
  irMap[342][45] = {HRIR_48K_24bit::azi_342_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_342_0_ele_45_0_wav};
  irMap[342][54] = {HRIR_48K_24bit::azi_342_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_342_0_ele_54_0_wav};
  irMap[342][60] = {HRIR_48K_24bit::azi_342_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_342_0_ele_60_0_wav};
  irMap[342][75] = {HRIR_48K_24bit::azi_342_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_342_0_ele_75_0_wav};
  irMap[342][90] = {HRIR_48K_24bit::azi_342_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_342_0_ele_90_0_wav};
  irMap[342][-15] = {HRIR_48K_24bit::azi_342_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_342_0_ele_neg15_0_wav};
  irMap[342][-25] = {HRIR_48K_24bit::azi_342_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_342_0_ele_neg25_0_wav};
  irMap[342][-30] = {HRIR_48K_24bit::azi_342_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_342_0_ele_neg30_0_wav};
  irMap[342][-45] = {HRIR_48K_24bit::azi_342_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_342_0_ele_neg45_0_wav};
  irMap[342][-54] = {HRIR_48K_24bit::azi_342_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_342_0_ele_neg54_0_wav};
  irMap[342][-60] = {HRIR_48K_24bit::azi_342_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_342_0_ele_neg60_0_wav};
  irMap[342][-75] = {HRIR_48K_24bit::azi_342_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_342_0_ele_neg75_0_wav};
  irMap[342][-81] = {HRIR_48K_24bit::azi_342_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_342_0_ele_neg81_0_wav};
  irMap[343][0] = {HRIR_48K_24bit::azi_343_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_343_0_ele_0_0_wav};
  irMap[343][15] = {HRIR_48K_24bit::azi_343_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_343_0_ele_15_0_wav};
  irMap[343][25] = {HRIR_48K_24bit::azi_343_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_343_0_ele_25_0_wav};
  irMap[343][30] = {HRIR_48K_24bit::azi_343_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_343_0_ele_30_0_wav};
  irMap[343][45] = {HRIR_48K_24bit::azi_343_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_343_0_ele_45_0_wav};
  irMap[343][54] = {HRIR_48K_24bit::azi_343_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_343_0_ele_54_0_wav};
  irMap[343][60] = {HRIR_48K_24bit::azi_343_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_343_0_ele_60_0_wav};
  irMap[343][75] = {HRIR_48K_24bit::azi_343_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_343_0_ele_75_0_wav};
  irMap[343][90] = {HRIR_48K_24bit::azi_343_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_343_0_ele_90_0_wav};
  irMap[343][-15] = {HRIR_48K_24bit::azi_343_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_343_0_ele_neg15_0_wav};
  irMap[343][-25] = {HRIR_48K_24bit::azi_343_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_343_0_ele_neg25_0_wav};
  irMap[343][-30] = {HRIR_48K_24bit::azi_343_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_343_0_ele_neg30_0_wav};
  irMap[343][-45] = {HRIR_48K_24bit::azi_343_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_343_0_ele_neg45_0_wav};
  irMap[343][-54] = {HRIR_48K_24bit::azi_343_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_343_0_ele_neg54_0_wav};
  irMap[343][-60] = {HRIR_48K_24bit::azi_343_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_343_0_ele_neg60_0_wav};
  irMap[343][-75] = {HRIR_48K_24bit::azi_343_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_343_0_ele_neg75_0_wav};
  irMap[343][-81] = {HRIR_48K_24bit::azi_343_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_343_0_ele_neg81_0_wav};
  irMap[344][0] = {HRIR_48K_24bit::azi_344_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_344_0_ele_0_0_wav};
  irMap[344][15] = {HRIR_48K_24bit::azi_344_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_344_0_ele_15_0_wav};
  irMap[344][25] = {HRIR_48K_24bit::azi_344_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_344_0_ele_25_0_wav};
  irMap[344][30] = {HRIR_48K_24bit::azi_344_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_344_0_ele_30_0_wav};
  irMap[344][45] = {HRIR_48K_24bit::azi_344_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_344_0_ele_45_0_wav};
  irMap[344][54] = {HRIR_48K_24bit::azi_344_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_344_0_ele_54_0_wav};
  irMap[344][60] = {HRIR_48K_24bit::azi_344_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_344_0_ele_60_0_wav};
  irMap[344][75] = {HRIR_48K_24bit::azi_344_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_344_0_ele_75_0_wav};
  irMap[344][90] = {HRIR_48K_24bit::azi_344_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_344_0_ele_90_0_wav};
  irMap[344][-15] = {HRIR_48K_24bit::azi_344_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_344_0_ele_neg15_0_wav};
  irMap[344][-25] = {HRIR_48K_24bit::azi_344_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_344_0_ele_neg25_0_wav};
  irMap[344][-30] = {HRIR_48K_24bit::azi_344_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_344_0_ele_neg30_0_wav};
  irMap[344][-45] = {HRIR_48K_24bit::azi_344_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_344_0_ele_neg45_0_wav};
  irMap[344][-54] = {HRIR_48K_24bit::azi_344_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_344_0_ele_neg54_0_wav};
  irMap[344][-60] = {HRIR_48K_24bit::azi_344_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_344_0_ele_neg60_0_wav};
  irMap[344][-75] = {HRIR_48K_24bit::azi_344_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_344_0_ele_neg75_0_wav};
  irMap[344][-81] = {HRIR_48K_24bit::azi_344_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_344_0_ele_neg81_0_wav};
  irMap[345][0] = {HRIR_48K_24bit::azi_345_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_345_0_ele_0_0_wav};
  irMap[345][15] = {HRIR_48K_24bit::azi_345_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_345_0_ele_15_0_wav};
  irMap[345][25] = {HRIR_48K_24bit::azi_345_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_345_0_ele_25_0_wav};
  irMap[345][30] = {HRIR_48K_24bit::azi_345_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_345_0_ele_30_0_wav};
  irMap[345][45] = {HRIR_48K_24bit::azi_345_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_345_0_ele_45_0_wav};
  irMap[345][54] = {HRIR_48K_24bit::azi_345_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_345_0_ele_54_0_wav};
  irMap[345][60] = {HRIR_48K_24bit::azi_345_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_345_0_ele_60_0_wav};
  irMap[345][75] = {HRIR_48K_24bit::azi_345_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_345_0_ele_75_0_wav};
  irMap[345][90] = {HRIR_48K_24bit::azi_345_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_345_0_ele_90_0_wav};
  irMap[345][-15] = {HRIR_48K_24bit::azi_345_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_345_0_ele_neg15_0_wav};
  irMap[345][-25] = {HRIR_48K_24bit::azi_345_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_345_0_ele_neg25_0_wav};
  irMap[345][-30] = {HRIR_48K_24bit::azi_345_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_345_0_ele_neg30_0_wav};
  irMap[345][-45] = {HRIR_48K_24bit::azi_345_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_345_0_ele_neg45_0_wav};
  irMap[345][-54] = {HRIR_48K_24bit::azi_345_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_345_0_ele_neg54_0_wav};
  irMap[345][-60] = {HRIR_48K_24bit::azi_345_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_345_0_ele_neg60_0_wav};
  irMap[345][-75] = {HRIR_48K_24bit::azi_345_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_345_0_ele_neg75_0_wav};
  irMap[345][-81] = {HRIR_48K_24bit::azi_345_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_345_0_ele_neg81_0_wav};
  irMap[346][0] = {HRIR_48K_24bit::azi_346_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_346_0_ele_0_0_wav};
  irMap[346][15] = {HRIR_48K_24bit::azi_346_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_346_0_ele_15_0_wav};
  irMap[346][25] = {HRIR_48K_24bit::azi_346_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_346_0_ele_25_0_wav};
  irMap[346][30] = {HRIR_48K_24bit::azi_346_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_346_0_ele_30_0_wav};
  irMap[346][45] = {HRIR_48K_24bit::azi_346_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_346_0_ele_45_0_wav};
  irMap[346][54] = {HRIR_48K_24bit::azi_346_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_346_0_ele_54_0_wav};
  irMap[346][60] = {HRIR_48K_24bit::azi_346_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_346_0_ele_60_0_wav};
  irMap[346][75] = {HRIR_48K_24bit::azi_346_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_346_0_ele_75_0_wav};
  irMap[346][90] = {HRIR_48K_24bit::azi_346_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_346_0_ele_90_0_wav};
  irMap[346][-15] = {HRIR_48K_24bit::azi_346_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_346_0_ele_neg15_0_wav};
  irMap[346][-25] = {HRIR_48K_24bit::azi_346_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_346_0_ele_neg25_0_wav};
  irMap[346][-30] = {HRIR_48K_24bit::azi_346_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_346_0_ele_neg30_0_wav};
  irMap[346][-45] = {HRIR_48K_24bit::azi_346_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_346_0_ele_neg45_0_wav};
  irMap[346][-54] = {HRIR_48K_24bit::azi_346_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_346_0_ele_neg54_0_wav};
  irMap[346][-60] = {HRIR_48K_24bit::azi_346_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_346_0_ele_neg60_0_wav};
  irMap[346][-75] = {HRIR_48K_24bit::azi_346_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_346_0_ele_neg75_0_wav};
  irMap[346][-81] = {HRIR_48K_24bit::azi_346_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_346_0_ele_neg81_0_wav};
  irMap[347][0] = {HRIR_48K_24bit::azi_347_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_347_0_ele_0_0_wav};
  irMap[347][15] = {HRIR_48K_24bit::azi_347_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_347_0_ele_15_0_wav};
  irMap[347][25] = {HRIR_48K_24bit::azi_347_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_347_0_ele_25_0_wav};
  irMap[347][30] = {HRIR_48K_24bit::azi_347_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_347_0_ele_30_0_wav};
  irMap[347][45] = {HRIR_48K_24bit::azi_347_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_347_0_ele_45_0_wav};
  irMap[347][54] = {HRIR_48K_24bit::azi_347_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_347_0_ele_54_0_wav};
  irMap[347][60] = {HRIR_48K_24bit::azi_347_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_347_0_ele_60_0_wav};
  irMap[347][75] = {HRIR_48K_24bit::azi_347_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_347_0_ele_75_0_wav};
  irMap[347][90] = {HRIR_48K_24bit::azi_347_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_347_0_ele_90_0_wav};
  irMap[347][-15] = {HRIR_48K_24bit::azi_347_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_347_0_ele_neg15_0_wav};
  irMap[347][-25] = {HRIR_48K_24bit::azi_347_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_347_0_ele_neg25_0_wav};
  irMap[347][-30] = {HRIR_48K_24bit::azi_347_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_347_0_ele_neg30_0_wav};
  irMap[347][-45] = {HRIR_48K_24bit::azi_347_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_347_0_ele_neg45_0_wav};
  irMap[347][-54] = {HRIR_48K_24bit::azi_347_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_347_0_ele_neg54_0_wav};
  irMap[347][-60] = {HRIR_48K_24bit::azi_347_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_347_0_ele_neg60_0_wav};
  irMap[347][-75] = {HRIR_48K_24bit::azi_347_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_347_0_ele_neg75_0_wav};
  irMap[347][-81] = {HRIR_48K_24bit::azi_347_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_347_0_ele_neg81_0_wav};
  irMap[348][0] = {HRIR_48K_24bit::azi_348_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_348_0_ele_0_0_wav};
  irMap[348][15] = {HRIR_48K_24bit::azi_348_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_348_0_ele_15_0_wav};
  irMap[348][25] = {HRIR_48K_24bit::azi_348_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_348_0_ele_25_0_wav};
  irMap[348][30] = {HRIR_48K_24bit::azi_348_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_348_0_ele_30_0_wav};
  irMap[348][45] = {HRIR_48K_24bit::azi_348_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_348_0_ele_45_0_wav};
  irMap[348][54] = {HRIR_48K_24bit::azi_348_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_348_0_ele_54_0_wav};
  irMap[348][60] = {HRIR_48K_24bit::azi_348_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_348_0_ele_60_0_wav};
  irMap[348][75] = {HRIR_48K_24bit::azi_348_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_348_0_ele_75_0_wav};
  irMap[348][90] = {HRIR_48K_24bit::azi_348_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_348_0_ele_90_0_wav};
  irMap[348][-15] = {HRIR_48K_24bit::azi_348_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_348_0_ele_neg15_0_wav};
  irMap[348][-25] = {HRIR_48K_24bit::azi_348_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_348_0_ele_neg25_0_wav};
  irMap[348][-30] = {HRIR_48K_24bit::azi_348_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_348_0_ele_neg30_0_wav};
  irMap[348][-45] = {HRIR_48K_24bit::azi_348_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_348_0_ele_neg45_0_wav};
  irMap[348][-54] = {HRIR_48K_24bit::azi_348_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_348_0_ele_neg54_0_wav};
  irMap[348][-60] = {HRIR_48K_24bit::azi_348_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_348_0_ele_neg60_0_wav};
  irMap[348][-75] = {HRIR_48K_24bit::azi_348_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_348_0_ele_neg75_0_wav};
  irMap[348][-81] = {HRIR_48K_24bit::azi_348_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_348_0_ele_neg81_0_wav};
  irMap[349][0] = {HRIR_48K_24bit::azi_349_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_349_0_ele_0_0_wav};
  irMap[349][15] = {HRIR_48K_24bit::azi_349_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_349_0_ele_15_0_wav};
  irMap[349][25] = {HRIR_48K_24bit::azi_349_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_349_0_ele_25_0_wav};
  irMap[349][30] = {HRIR_48K_24bit::azi_349_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_349_0_ele_30_0_wav};
  irMap[349][45] = {HRIR_48K_24bit::azi_349_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_349_0_ele_45_0_wav};
  irMap[349][54] = {HRIR_48K_24bit::azi_349_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_349_0_ele_54_0_wav};
  irMap[349][60] = {HRIR_48K_24bit::azi_349_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_349_0_ele_60_0_wav};
  irMap[349][75] = {HRIR_48K_24bit::azi_349_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_349_0_ele_75_0_wav};
  irMap[349][90] = {HRIR_48K_24bit::azi_349_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_349_0_ele_90_0_wav};
  irMap[349][-15] = {HRIR_48K_24bit::azi_349_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_349_0_ele_neg15_0_wav};
  irMap[349][-25] = {HRIR_48K_24bit::azi_349_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_349_0_ele_neg25_0_wav};
  irMap[349][-30] = {HRIR_48K_24bit::azi_349_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_349_0_ele_neg30_0_wav};
  irMap[349][-45] = {HRIR_48K_24bit::azi_349_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_349_0_ele_neg45_0_wav};
  irMap[349][-54] = {HRIR_48K_24bit::azi_349_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_349_0_ele_neg54_0_wav};
  irMap[349][-60] = {HRIR_48K_24bit::azi_349_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_349_0_ele_neg60_0_wav};
  irMap[349][-75] = {HRIR_48K_24bit::azi_349_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_349_0_ele_neg75_0_wav};
  irMap[349][-81] = {HRIR_48K_24bit::azi_349_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_349_0_ele_neg81_0_wav};
  irMap[350][0] = {HRIR_48K_24bit::azi_350_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_350_0_ele_0_0_wav};
  irMap[350][15] = {HRIR_48K_24bit::azi_350_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_350_0_ele_15_0_wav};
  irMap[350][25] = {HRIR_48K_24bit::azi_350_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_350_0_ele_25_0_wav};
  irMap[350][30] = {HRIR_48K_24bit::azi_350_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_350_0_ele_30_0_wav};
  irMap[350][45] = {HRIR_48K_24bit::azi_350_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_350_0_ele_45_0_wav};
  irMap[350][54] = {HRIR_48K_24bit::azi_350_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_350_0_ele_54_0_wav};
  irMap[350][60] = {HRIR_48K_24bit::azi_350_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_350_0_ele_60_0_wav};
  irMap[350][75] = {HRIR_48K_24bit::azi_350_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_350_0_ele_75_0_wav};
  irMap[350][90] = {HRIR_48K_24bit::azi_350_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_350_0_ele_90_0_wav};
  irMap[350][-15] = {HRIR_48K_24bit::azi_350_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_350_0_ele_neg15_0_wav};
  irMap[350][-25] = {HRIR_48K_24bit::azi_350_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_350_0_ele_neg25_0_wav};
  irMap[350][-30] = {HRIR_48K_24bit::azi_350_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_350_0_ele_neg30_0_wav};
  irMap[350][-45] = {HRIR_48K_24bit::azi_350_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_350_0_ele_neg45_0_wav};
  irMap[350][-54] = {HRIR_48K_24bit::azi_350_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_350_0_ele_neg54_0_wav};
  irMap[350][-60] = {HRIR_48K_24bit::azi_350_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_350_0_ele_neg60_0_wav};
  irMap[350][-75] = {HRIR_48K_24bit::azi_350_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_350_0_ele_neg75_0_wav};
  irMap[350][-81] = {HRIR_48K_24bit::azi_350_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_350_0_ele_neg81_0_wav};
  irMap[351][0] = {HRIR_48K_24bit::azi_351_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_351_0_ele_0_0_wav};
  irMap[351][15] = {HRIR_48K_24bit::azi_351_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_351_0_ele_15_0_wav};
  irMap[351][25] = {HRIR_48K_24bit::azi_351_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_351_0_ele_25_0_wav};
  irMap[351][30] = {HRIR_48K_24bit::azi_351_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_351_0_ele_30_0_wav};
  irMap[351][45] = {HRIR_48K_24bit::azi_351_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_351_0_ele_45_0_wav};
  irMap[351][54] = {HRIR_48K_24bit::azi_351_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_351_0_ele_54_0_wav};
  irMap[351][60] = {HRIR_48K_24bit::azi_351_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_351_0_ele_60_0_wav};
  irMap[351][75] = {HRIR_48K_24bit::azi_351_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_351_0_ele_75_0_wav};
  irMap[351][90] = {HRIR_48K_24bit::azi_351_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_351_0_ele_90_0_wav};
  irMap[351][-15] = {HRIR_48K_24bit::azi_351_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_351_0_ele_neg15_0_wav};
  irMap[351][-25] = {HRIR_48K_24bit::azi_351_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_351_0_ele_neg25_0_wav};
  irMap[351][-30] = {HRIR_48K_24bit::azi_351_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_351_0_ele_neg30_0_wav};
  irMap[351][-45] = {HRIR_48K_24bit::azi_351_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_351_0_ele_neg45_0_wav};
  irMap[351][-54] = {HRIR_48K_24bit::azi_351_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_351_0_ele_neg54_0_wav};
  irMap[351][-60] = {HRIR_48K_24bit::azi_351_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_351_0_ele_neg60_0_wav};
  irMap[351][-75] = {HRIR_48K_24bit::azi_351_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_351_0_ele_neg75_0_wav};
  irMap[351][-81] = {HRIR_48K_24bit::azi_351_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_351_0_ele_neg81_0_wav};
  irMap[352][0] = {HRIR_48K_24bit::azi_352_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_352_0_ele_0_0_wav};
  irMap[352][15] = {HRIR_48K_24bit::azi_352_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_352_0_ele_15_0_wav};
  irMap[352][25] = {HRIR_48K_24bit::azi_352_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_352_0_ele_25_0_wav};
  irMap[352][30] = {HRIR_48K_24bit::azi_352_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_352_0_ele_30_0_wav};
  irMap[352][45] = {HRIR_48K_24bit::azi_352_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_352_0_ele_45_0_wav};
  irMap[352][54] = {HRIR_48K_24bit::azi_352_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_352_0_ele_54_0_wav};
  irMap[352][60] = {HRIR_48K_24bit::azi_352_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_352_0_ele_60_0_wav};
  irMap[352][75] = {HRIR_48K_24bit::azi_352_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_352_0_ele_75_0_wav};
  irMap[352][90] = {HRIR_48K_24bit::azi_352_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_352_0_ele_90_0_wav};
  irMap[352][-15] = {HRIR_48K_24bit::azi_352_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_352_0_ele_neg15_0_wav};
  irMap[352][-25] = {HRIR_48K_24bit::azi_352_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_352_0_ele_neg25_0_wav};
  irMap[352][-30] = {HRIR_48K_24bit::azi_352_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_352_0_ele_neg30_0_wav};
  irMap[352][-45] = {HRIR_48K_24bit::azi_352_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_352_0_ele_neg45_0_wav};
  irMap[352][-54] = {HRIR_48K_24bit::azi_352_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_352_0_ele_neg54_0_wav};
  irMap[352][-60] = {HRIR_48K_24bit::azi_352_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_352_0_ele_neg60_0_wav};
  irMap[352][-75] = {HRIR_48K_24bit::azi_352_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_352_0_ele_neg75_0_wav};
  irMap[352][-81] = {HRIR_48K_24bit::azi_352_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_352_0_ele_neg81_0_wav};
  irMap[353][0] = {HRIR_48K_24bit::azi_353_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_353_0_ele_0_0_wav};
  irMap[353][15] = {HRIR_48K_24bit::azi_353_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_353_0_ele_15_0_wav};
  irMap[353][25] = {HRIR_48K_24bit::azi_353_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_353_0_ele_25_0_wav};
  irMap[353][30] = {HRIR_48K_24bit::azi_353_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_353_0_ele_30_0_wav};
  irMap[353][45] = {HRIR_48K_24bit::azi_353_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_353_0_ele_45_0_wav};
  irMap[353][54] = {HRIR_48K_24bit::azi_353_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_353_0_ele_54_0_wav};
  irMap[353][60] = {HRIR_48K_24bit::azi_353_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_353_0_ele_60_0_wav};
  irMap[353][75] = {HRIR_48K_24bit::azi_353_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_353_0_ele_75_0_wav};
  irMap[353][90] = {HRIR_48K_24bit::azi_353_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_353_0_ele_90_0_wav};
  irMap[353][-15] = {HRIR_48K_24bit::azi_353_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_353_0_ele_neg15_0_wav};
  irMap[353][-25] = {HRIR_48K_24bit::azi_353_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_353_0_ele_neg25_0_wav};
  irMap[353][-30] = {HRIR_48K_24bit::azi_353_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_353_0_ele_neg30_0_wav};
  irMap[353][-45] = {HRIR_48K_24bit::azi_353_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_353_0_ele_neg45_0_wav};
  irMap[353][-54] = {HRIR_48K_24bit::azi_353_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_353_0_ele_neg54_0_wav};
  irMap[353][-60] = {HRIR_48K_24bit::azi_353_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_353_0_ele_neg60_0_wav};
  irMap[353][-75] = {HRIR_48K_24bit::azi_353_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_353_0_ele_neg75_0_wav};
  irMap[353][-81] = {HRIR_48K_24bit::azi_353_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_353_0_ele_neg81_0_wav};
  irMap[354][0] = {HRIR_48K_24bit::azi_354_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_354_0_ele_0_0_wav};
  irMap[354][15] = {HRIR_48K_24bit::azi_354_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_354_0_ele_15_0_wav};
  irMap[354][25] = {HRIR_48K_24bit::azi_354_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_354_0_ele_25_0_wav};
  irMap[354][30] = {HRIR_48K_24bit::azi_354_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_354_0_ele_30_0_wav};
  irMap[354][45] = {HRIR_48K_24bit::azi_354_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_354_0_ele_45_0_wav};
  irMap[354][54] = {HRIR_48K_24bit::azi_354_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_354_0_ele_54_0_wav};
  irMap[354][60] = {HRIR_48K_24bit::azi_354_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_354_0_ele_60_0_wav};
  irMap[354][75] = {HRIR_48K_24bit::azi_354_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_354_0_ele_75_0_wav};
  irMap[354][90] = {HRIR_48K_24bit::azi_354_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_354_0_ele_90_0_wav};
  irMap[354][-15] = {HRIR_48K_24bit::azi_354_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_354_0_ele_neg15_0_wav};
  irMap[354][-25] = {HRIR_48K_24bit::azi_354_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_354_0_ele_neg25_0_wav};
  irMap[354][-30] = {HRIR_48K_24bit::azi_354_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_354_0_ele_neg30_0_wav};
  irMap[354][-45] = {HRIR_48K_24bit::azi_354_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_354_0_ele_neg45_0_wav};
  irMap[354][-54] = {HRIR_48K_24bit::azi_354_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_354_0_ele_neg54_0_wav};
  irMap[354][-60] = {HRIR_48K_24bit::azi_354_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_354_0_ele_neg60_0_wav};
  irMap[354][-75] = {HRIR_48K_24bit::azi_354_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_354_0_ele_neg75_0_wav};
  irMap[354][-81] = {HRIR_48K_24bit::azi_354_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_354_0_ele_neg81_0_wav};
  irMap[355][0] = {HRIR_48K_24bit::azi_355_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_355_0_ele_0_0_wav};
  irMap[355][15] = {HRIR_48K_24bit::azi_355_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_355_0_ele_15_0_wav};
  irMap[355][25] = {HRIR_48K_24bit::azi_355_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_355_0_ele_25_0_wav};
  irMap[355][30] = {HRIR_48K_24bit::azi_355_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_355_0_ele_30_0_wav};
  irMap[355][45] = {HRIR_48K_24bit::azi_355_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_355_0_ele_45_0_wav};
  irMap[355][54] = {HRIR_48K_24bit::azi_355_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_355_0_ele_54_0_wav};
  irMap[355][60] = {HRIR_48K_24bit::azi_355_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_355_0_ele_60_0_wav};
  irMap[355][75] = {HRIR_48K_24bit::azi_355_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_355_0_ele_75_0_wav};
  irMap[355][90] = {HRIR_48K_24bit::azi_355_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_355_0_ele_90_0_wav};
  irMap[355][-15] = {HRIR_48K_24bit::azi_355_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_355_0_ele_neg15_0_wav};
  irMap[355][-25] = {HRIR_48K_24bit::azi_355_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_355_0_ele_neg25_0_wav};
  irMap[355][-30] = {HRIR_48K_24bit::azi_355_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_355_0_ele_neg30_0_wav};
  irMap[355][-45] = {HRIR_48K_24bit::azi_355_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_355_0_ele_neg45_0_wav};
  irMap[355][-54] = {HRIR_48K_24bit::azi_355_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_355_0_ele_neg54_0_wav};
  irMap[355][-60] = {HRIR_48K_24bit::azi_355_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_355_0_ele_neg60_0_wav};
  irMap[355][-75] = {HRIR_48K_24bit::azi_355_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_355_0_ele_neg75_0_wav};
  irMap[355][-81] = {HRIR_48K_24bit::azi_355_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_355_0_ele_neg81_0_wav};
  irMap[356][0] = {HRIR_48K_24bit::azi_356_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_356_0_ele_0_0_wav};
  irMap[356][15] = {HRIR_48K_24bit::azi_356_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_356_0_ele_15_0_wav};
  irMap[356][25] = {HRIR_48K_24bit::azi_356_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_356_0_ele_25_0_wav};
  irMap[356][30] = {HRIR_48K_24bit::azi_356_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_356_0_ele_30_0_wav};
  irMap[356][45] = {HRIR_48K_24bit::azi_356_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_356_0_ele_45_0_wav};
  irMap[356][54] = {HRIR_48K_24bit::azi_356_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_356_0_ele_54_0_wav};
  irMap[356][60] = {HRIR_48K_24bit::azi_356_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_356_0_ele_60_0_wav};
  irMap[356][75] = {HRIR_48K_24bit::azi_356_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_356_0_ele_75_0_wav};
  irMap[356][90] = {HRIR_48K_24bit::azi_356_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_356_0_ele_90_0_wav};
  irMap[356][-15] = {HRIR_48K_24bit::azi_356_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_356_0_ele_neg15_0_wav};
  irMap[356][-25] = {HRIR_48K_24bit::azi_356_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_356_0_ele_neg25_0_wav};
  irMap[356][-30] = {HRIR_48K_24bit::azi_356_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_356_0_ele_neg30_0_wav};
  irMap[356][-45] = {HRIR_48K_24bit::azi_356_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_356_0_ele_neg45_0_wav};
  irMap[356][-54] = {HRIR_48K_24bit::azi_356_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_356_0_ele_neg54_0_wav};
  irMap[356][-60] = {HRIR_48K_24bit::azi_356_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_356_0_ele_neg60_0_wav};
  irMap[356][-75] = {HRIR_48K_24bit::azi_356_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_356_0_ele_neg75_0_wav};
  irMap[356][-81] = {HRIR_48K_24bit::azi_356_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_356_0_ele_neg81_0_wav};
  irMap[357][0] = {HRIR_48K_24bit::azi_357_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_357_0_ele_0_0_wav};
  irMap[357][15] = {HRIR_48K_24bit::azi_357_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_357_0_ele_15_0_wav};
  irMap[357][25] = {HRIR_48K_24bit::azi_357_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_357_0_ele_25_0_wav};
  irMap[357][30] = {HRIR_48K_24bit::azi_357_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_357_0_ele_30_0_wav};
  irMap[357][45] = {HRIR_48K_24bit::azi_357_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_357_0_ele_45_0_wav};
  irMap[357][54] = {HRIR_48K_24bit::azi_357_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_357_0_ele_54_0_wav};
  irMap[357][60] = {HRIR_48K_24bit::azi_357_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_357_0_ele_60_0_wav};
  irMap[357][75] = {HRIR_48K_24bit::azi_357_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_357_0_ele_75_0_wav};
  irMap[357][90] = {HRIR_48K_24bit::azi_357_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_357_0_ele_90_0_wav};
  irMap[357][-15] = {HRIR_48K_24bit::azi_357_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_357_0_ele_neg15_0_wav};
  irMap[357][-25] = {HRIR_48K_24bit::azi_357_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_357_0_ele_neg25_0_wav};
  irMap[357][-30] = {HRIR_48K_24bit::azi_357_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_357_0_ele_neg30_0_wav};
  irMap[357][-45] = {HRIR_48K_24bit::azi_357_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_357_0_ele_neg45_0_wav};
  irMap[357][-54] = {HRIR_48K_24bit::azi_357_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_357_0_ele_neg54_0_wav};
  irMap[357][-60] = {HRIR_48K_24bit::azi_357_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_357_0_ele_neg60_0_wav};
  irMap[357][-75] = {HRIR_48K_24bit::azi_357_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_357_0_ele_neg75_0_wav};
  irMap[357][-81] = {HRIR_48K_24bit::azi_357_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_357_0_ele_neg81_0_wav};
  irMap[358][0] = {HRIR_48K_24bit::azi_358_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_358_0_ele_0_0_wav};
  irMap[358][15] = {HRIR_48K_24bit::azi_358_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_358_0_ele_15_0_wav};
  irMap[358][25] = {HRIR_48K_24bit::azi_358_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_358_0_ele_25_0_wav};
  irMap[358][30] = {HRIR_48K_24bit::azi_358_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_358_0_ele_30_0_wav};
  irMap[358][45] = {HRIR_48K_24bit::azi_358_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_358_0_ele_45_0_wav};
  irMap[358][54] = {HRIR_48K_24bit::azi_358_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_358_0_ele_54_0_wav};
  irMap[358][60] = {HRIR_48K_24bit::azi_358_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_358_0_ele_60_0_wav};
  irMap[358][75] = {HRIR_48K_24bit::azi_358_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_358_0_ele_75_0_wav};
  irMap[358][90] = {HRIR_48K_24bit::azi_358_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_358_0_ele_90_0_wav};
  irMap[358][-15] = {HRIR_48K_24bit::azi_358_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_358_0_ele_neg15_0_wav};
  irMap[358][-25] = {HRIR_48K_24bit::azi_358_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_358_0_ele_neg25_0_wav};
  irMap[358][-30] = {HRIR_48K_24bit::azi_358_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_358_0_ele_neg30_0_wav};
  irMap[358][-45] = {HRIR_48K_24bit::azi_358_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_358_0_ele_neg45_0_wav};
  irMap[358][-54] = {HRIR_48K_24bit::azi_358_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_358_0_ele_neg54_0_wav};
  irMap[358][-60] = {HRIR_48K_24bit::azi_358_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_358_0_ele_neg60_0_wav};
  irMap[358][-75] = {HRIR_48K_24bit::azi_358_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_358_0_ele_neg75_0_wav};
  irMap[358][-81] = {HRIR_48K_24bit::azi_358_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_358_0_ele_neg81_0_wav};
  irMap[359][0] = {HRIR_48K_24bit::azi_359_0_ele_0_0_wavSize,
                   HRIR_48K_24bit::azi_359_0_ele_0_0_wav};
  irMap[359][15] = {HRIR_48K_24bit::azi_359_0_ele_15_0_wavSize,
                    HRIR_48K_24bit::azi_359_0_ele_15_0_wav};
  irMap[359][25] = {HRIR_48K_24bit::azi_359_0_ele_25_0_wavSize,
                    HRIR_48K_24bit::azi_359_0_ele_25_0_wav};
  irMap[359][30] = {HRIR_48K_24bit::azi_359_0_ele_30_0_wavSize,
                    HRIR_48K_24bit::azi_359_0_ele_30_0_wav};
  irMap[359][45] = {HRIR_48K_24bit::azi_359_0_ele_45_0_wavSize,
                    HRIR_48K_24bit::azi_359_0_ele_45_0_wav};
  irMap[359][54] = {HRIR_48K_24bit::azi_359_0_ele_54_0_wavSize,
                    HRIR_48K_24bit::azi_359_0_ele_54_0_wav};
  irMap[359][60] = {HRIR_48K_24bit::azi_359_0_ele_60_0_wavSize,
                    HRIR_48K_24bit::azi_359_0_ele_60_0_wav};
  irMap[359][75] = {HRIR_48K_24bit::azi_359_0_ele_75_0_wavSize,
                    HRIR_48K_24bit::azi_359_0_ele_75_0_wav};
  irMap[359][90] = {HRIR_48K_24bit::azi_359_0_ele_90_0_wavSize,
                    HRIR_48K_24bit::azi_359_0_ele_90_0_wav};
  irMap[359][-15] = {HRIR_48K_24bit::azi_359_0_ele_neg15_0_wavSize,
                     HRIR_48K_24bit::azi_359_0_ele_neg15_0_wav};
  irMap[359][-25] = {HRIR_48K_24bit::azi_359_0_ele_neg25_0_wavSize,
                     HRIR_48K_24bit::azi_359_0_ele_neg25_0_wav};
  irMap[359][-30] = {HRIR_48K_24bit::azi_359_0_ele_neg30_0_wavSize,
                     HRIR_48K_24bit::azi_359_0_ele_neg30_0_wav};
  irMap[359][-45] = {HRIR_48K_24bit::azi_359_0_ele_neg45_0_wavSize,
                     HRIR_48K_24bit::azi_359_0_ele_neg45_0_wav};
  irMap[359][-54] = {HRIR_48K_24bit::azi_359_0_ele_neg54_0_wavSize,
                     HRIR_48K_24bit::azi_359_0_ele_neg54_0_wav};
  irMap[359][-60] = {HRIR_48K_24bit::azi_359_0_ele_neg60_0_wavSize,
                     HRIR_48K_24bit::azi_359_0_ele_neg60_0_wav};
  irMap[359][-75] = {HRIR_48K_24bit::azi_359_0_ele_neg75_0_wavSize,
                     HRIR_48K_24bit::azi_359_0_ele_neg75_0_wav};
  irMap[359][-81] = {HRIR_48K_24bit::azi_359_0_ele_neg81_0_wavSize,
                     HRIR_48K_24bit::azi_359_0_ele_neg81_0_wav};

}

void SpatialAudioPluginAudioProcessor::loadIR(int azi, int ele) {
  
  // Find the closest valid elevation value
  int closestElevation = 0;
  float smallestElevationDiff = 180.0f;
  for (int i = 0; i < 17; i++) {
    float elDiff = std::abs((ele-90) - elevationValues[i]);
    if (elDiff < smallestElevationDiff) {
      smallestElevationDiff = elDiff;
      closestElevation = elevationValues[i];
    }
  }

  if (azi == lastAzi && closestElevation == lastEle) {
    return;
  }
  
  // Load as binary data
  conv.loadImpulseResponse(irMap[azi][closestElevation].ir, 
                           irMap[azi][closestElevation].size,
                           juce::dsp::Convolution::Stereo::yes,
                           juce::dsp::Convolution::Trim::yes, 0,
                           juce::dsp::Convolution::Normalise::yes);
  lastAzi = azi;
  lastEle = closestElevation;
}

const juce::String SpatialAudioPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SpatialAudioPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SpatialAudioPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SpatialAudioPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SpatialAudioPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SpatialAudioPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SpatialAudioPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SpatialAudioPluginAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SpatialAudioPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void SpatialAudioPluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SpatialAudioPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

    params.gainSmoother.reset(sampleRate, 0.02);
    params.gainSmoother.setCurrentAndTargetValue(juce::Decibels::decibelsToGain(params.gainParam->get()));

    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();

    // Set up convolution reverb:
    conv.reset();
    conv.prepare(spec);
}

void SpatialAudioPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SpatialAudioPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}
#endif

void SpatialAudioPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, [[maybe_unused]]juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    const int elev = params.elevationParam->get();
    const int azi = params.azimuthParam->get();

    loadIR(azi, elev);

    // Turn JUCE buffer into an AudioBlock
    juce::dsp::AudioBlock<float> block{ buffer };

    //Pass the new AudioBlock to the conv.process call
    conv.process(juce::dsp::ProcessContextReplacing<float>(block));

    float* channelDataL = buffer.getWritePointer(0);
    float* channelDataR = buffer.getWritePointer(1);

    auto& smoother = params.gainSmoother;
    smoother.setTargetValue(juce::Decibels::decibelsToGain(params.gainParam->get()));

    for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
        const auto gain = smoother.getNextValue();
        channelDataL[sample] = channelDataL[sample] * gain;
        channelDataR[sample] = channelDataR[sample] * gain;
    }
}

//==============================================================================
bool SpatialAudioPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

// The PluginProcessor creates an instance of the Editor here
juce::AudioProcessorEditor* SpatialAudioPluginAudioProcessor::createEditor()
{
    return new SpatialAudioPluginAudioProcessorEditor (*this);
}

//==============================================================================
void SpatialAudioPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    copyXmlToBinary(*apvts.copyState().createXml(), destData);
}

void SpatialAudioPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<juce::XmlElement> xml(getXmlFromBinary(data, sizeInBytes));
    if (xml.get() != nullptr && xml->hasTagName(apvts.state.getType())) {
        apvts.replaceState(juce::ValueTree::fromXml(*xml));
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SpatialAudioPluginAudioProcessor();
}
