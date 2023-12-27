//
// Created by Kimera Royal on 27/12/2023.
//

#include "DecibelSlider.h"

#include <juce_audio_basics/juce_audio_basics.h>

double DecibelSlider::getValueFromText(const juce::String& _text)
{
	constexpr auto minusInfinitydB = -100.0;
	const auto decibelText = _text.upToFirstOccurrenceOf("dB", false, false).trim();
	return decibelText.equalsIgnoreCase("-INF") ? minusInfinitydB : decibelText.getDoubleValue();
}

juce::String DecibelSlider::getTextFromValue(const double _value)
{
	return juce::Decibels::toString(_value);
}
