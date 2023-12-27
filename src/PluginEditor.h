#pragma once

#include "PluginProcessor.h"

#include "gui/DecibelSlider.h"

class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    AudioPluginAudioProcessor& processorRef;

    juce::Slider m_frequency;
    DecibelSlider m_volume;

    void frequencyChanged(juce::Slider* slider);
    void volumeChanged(juce::Slider* slider);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
