#pragma once

#include "../synth/SynthEngine.h"
#include <JuceHeader.h>

class WaveformSelector : public juce::Component{
public:
    WaveformSelector(SynthEngine::Parameter oscillatorWaveformParameter, SynthEngine& synthEngine, juce::String name)
    : synthEngineRef(synthEngine)
    {
        waveSelectorParameter = oscillatorWaveformParameter;

        addAndMakeVisible(label);
        addAndMakeVisible(squareButton);
        addAndMakeVisible(sawButton);
        addAndMakeVisible(sinButton);
        addAndMakeVisible(triangleButton);

        squareButton.onClick = [this]{ synthEngineRef.SetParameter(waveSelectorParameter, SynthEngine::Waveform::Square); };
        squareButton.setButtonText("Square");

        sawButton.onClick = [this]{ synthEngineRef.SetParameter(waveSelectorParameter, SynthEngine::Waveform::Saw); };
        sawButton.setButtonText("Saw");

        sinButton.onClick = [this]{ synthEngineRef.SetParameter(waveSelectorParameter, SynthEngine::Waveform::Sin); };
        sinButton.setButtonText("Sin");

        triangleButton.onClick = [this]{ synthEngineRef.SetParameter(waveSelectorParameter, SynthEngine::Waveform::Triangle); };
        triangleButton.setButtonText("Triangle");

        label.setText(name, NotificationType::dontSendNotification);
        label.setJustificationType(Justification(Justification::Flags::centred));
    }

    void resized() override;

private:
    SynthEngine::Parameter waveSelectorParameter{};
    SynthEngine& synthEngineRef;

    Label label;
    TextButton squareButton;
    TextButton sawButton;
    TextButton sinButton;
    TextButton triangleButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformSelector)
};

