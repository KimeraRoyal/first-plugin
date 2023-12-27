//
// Created by Kimera Royal on 27/12/2023.
//

#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

class DecibelSlider final : public juce::Slider
{
public:
	~DecibelSlider() override = default;

	double getValueFromText(const juce::String& _text) override;

	juce::String getTextFromValue(double _value) override;
};
