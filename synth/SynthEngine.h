#pragma once

#include "Synth.h"
#include "daisysp.h"

using namespace daisysp;

class SynthEngine : public Synth {
public:
    enum Parameter{
        NoteValue,
        Volume,
        Osc1Waveform,
        Osc2Waveform,
        Osc2PitchSemitones,
        Osc2PitchFine,
        Osc1Level,
        Osc2Level,
        NoiseLevel,
        AmpAttack,
        AmpDecay,
        AmpSustain,
        AmpRelease,
        FilterFreq,
        FilterRes,
        FilterEnvAmount,
        FilterAttack,
        FilterDecay,
        FilterSustain,
        FilterRelease,
    };

    enum Waveform {
        Sin,
        Triangle,
        Saw,
        Square,
    };

    void Init(float sampleRate) override;
    void SetGate(bool state) override;
    void SetParameter(int parameterId, float value) override;
    float Process() override;

private:
    WhiteNoise noise{};
    Oscillator oscillator1{};
    Oscillator oscillator2{};
    Adsr ampEnvelope{};
    Adsr filterEnvelope{};
    MoogLadder filter{};

    bool gateOpen{};
    float audioSampleRate{};
    float volume{};

    float filterEnvelopeAmount{};
    float filterFreq{};
    float osc2PitchSemitones{};
    float osc2PitchFine{};

    float osc1Level{};
    float osc2Level{};
    float noiseLevel{};
};
