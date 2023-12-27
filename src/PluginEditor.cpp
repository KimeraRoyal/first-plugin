#include "PluginProcessor.h"
#include "PluginEditor.h"

AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused(processorRef);

    setSize(600, 300);

    m_frequency.setRange(50.0, 5000.0);
    m_frequency.setSkewFactorFromMidPoint(500.0);
    m_frequency.setValue(500.0, juce::dontSendNotification);
    m_frequency.onValueChange = [this] { frequencyChanged(&m_frequency); };
    addAndMakeVisible(m_frequency);

    m_volume.setSliderStyle(juce::Slider::LinearBarVertical);
    m_volume.setRange(-100.0, 10.0, 0.1);
    m_volume.setValue(juce::Decibels::gainToDecibels(0.125), juce::dontSendNotification);
    m_volume.onValueChange = [this] { volumeChanged(&m_volume); };
    addAndMakeVisible(m_volume);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{

}

void AudioPluginAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void AudioPluginAudioProcessorEditor::resized()
{
    m_frequency.setBounds(40, 30, 300, 20);
    m_volume.setBounds(40, 60, 20, 200);
}

void AudioPluginAudioProcessorEditor::frequencyChanged(juce::Slider* slider)
{
    processorRef.setFrequency(m_frequency.getValue());
}

void AudioPluginAudioProcessorEditor::volumeChanged(juce::Slider* slider)
{
    processorRef.setVolume(juce::Decibels::decibelsToGain(m_volume.getValue()));
}
