#pragma once

#include <JuceHeader.h>
#include "../synth/SynthEngine.h"

class LabelledRotaryControl : public juce::Component{
public:
    LabelledRotaryControl(SynthEngine::Parameter sliderParameter, float minValue, float maxValue, float interval, float initialValue, juce::String valueSuffix, juce::String labelText, SynthEngine& synthEngine)
    : synthEngineRef(synthEngine)
    {
        parameter = sliderParameter;

        addAndMakeVisible(slider);
        addAndMakeVisible(label);

        slider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
        slider.setRange(minValue, maxValue, interval);
        slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 130, 25);
        slider.setValue(initialValue);
        slider.setTextValueSuffix(valueSuffix);

        label.setText(labelText, NotificationType::dontSendNotification);
        label.setJustificationType(Justification(Justification::Flags::centred));

        slider.onValueChange = [this] {synthEngineRef.SetParameter(parameter, slider.getValue());};
    }

    void resized() override;

private:
    juce::Slider slider;
    juce::Label label;
    SynthEngine& synthEngineRef;

    SynthEngine::Parameter parameter;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LabelledRotaryControl)
};

