#pragma once

#include "PluginProcessor.h"
#include "interface/LabelledRotaryControl.h"
#include "interface/WaveformSelector.h"

//==============================================================================
class AudioPluginAudioProcessorEditor  :    public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;

    WaveformSelector osc1WaveformSelector{SynthEngine::Parameter::Osc1Waveform, processorRef.synthEngine, "Osc1 Waveform"};
    WaveformSelector osc2WaveformSelector{SynthEngine::Parameter::Osc2Waveform, processorRef.synthEngine, "Osc2 Waveform"};

    LabelledRotaryControl osc2PitchSemitonesControl{SynthEngine::Parameter::Osc2PitchSemitones, -24, 24, 1, -12, " Semitones", "Osc2 Semitones", processorRef.synthEngine};
    LabelledRotaryControl osc2PitchFineControl{SynthEngine::Parameter::Osc2PitchFine, -50, 50, 0.1, 0, " Cents", "Osc2 Finetune", processorRef.synthEngine};

    LabelledRotaryControl osc1LevelControl{SynthEngine::Parameter::Osc1Level, 0, 100, 0.1, 100, "%", "Osc1 Level", processorRef.synthEngine};
    LabelledRotaryControl osc2LevelControl{SynthEngine::Parameter::Osc2Level, 0, 100, 0.1, 100, "%", "Osc2 Level", processorRef.synthEngine};
    LabelledRotaryControl noiseLevelControl{SynthEngine::Parameter::NoiseLevel, 0, 100, 0.1, 0, "%", "Noise Level", processorRef.synthEngine};

    LabelledRotaryControl ampAttackControl{SynthEngine::Parameter::AmpAttack, 0.01, 1.5, 0.01, 0, " S", "Amp Env Attack", processorRef.synthEngine};
    LabelledRotaryControl ampDecayControl{SynthEngine::Parameter::AmpDecay, 0, 1.5, 0.01, 1, " S", "Amp Env Decay", processorRef.synthEngine};
    LabelledRotaryControl ampSustainControl{SynthEngine::Parameter::AmpSustain, 0, 1, 0.01, 0, "", "Amp Env Sustain", processorRef.synthEngine};
    LabelledRotaryControl ampReleaseControl{SynthEngine::Parameter::AmpRelease, 0, 1.5, 0.01, 0.4, " S", "Amp Env Release", processorRef.synthEngine};

    LabelledRotaryControl filterFrequencyControl{SynthEngine::Parameter::FilterFreq, 10, 20000, 0.1, 20000, " HZ", "Filter Frequency", processorRef.synthEngine};
    LabelledRotaryControl filterResonanceControl{SynthEngine::Parameter::FilterRes, 0, 1, 0.001, 0.2, "", "Filter Resonance", processorRef.synthEngine};
    LabelledRotaryControl filterEnvelopeAmountControl{SynthEngine::Parameter::FilterEnvAmount, 0, 20000, 0.1, 0.2, "", "Filter Env Amount", processorRef.synthEngine};

    LabelledRotaryControl filterAttackControl{SynthEngine::Parameter::FilterAttack, 0.01, 1.5, 0.01, 0, " S", "Filter Env Attack", processorRef.synthEngine};
    LabelledRotaryControl filterDecayControl{SynthEngine::Parameter::FilterDecay, 0, 1.5, 0.01, 1, " S", "Filter Env Decay", processorRef.synthEngine};
    LabelledRotaryControl filterSustainControl{SynthEngine::Parameter::FilterSustain, 0, 1, 0.01, 0, "", "Filter Env Sustain", processorRef.synthEngine};
    LabelledRotaryControl filterReleaseControl{SynthEngine::Parameter::FilterRelease, 0, 1.5, 0.01, 0.4, " S", "Filter Env Release", processorRef.synthEngine};

    LabelledRotaryControl volumeControl{SynthEngine::Parameter::Volume, 0, 100, 0.01, 80, "%", "Volume", processorRef.synthEngine};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
