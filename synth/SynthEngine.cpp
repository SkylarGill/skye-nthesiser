#include "SynthEngine.h"

void SynthEngine::Init(float sampleRate) {
    gateOpen = false;
    audioSampleRate = sampleRate;
    volume = 1;

    oscillator1.Init(audioSampleRate);
    oscillator1.SetWaveform(Oscillator::WAVE_SQUARE);

    oscillator2.Init(audioSampleRate);
    oscillator2.SetWaveform(Oscillator::WAVE_SQUARE);

    noise.Init();

    ampEnvelope.Init(audioSampleRate, 4);
    ampEnvelope.SetAttackTime(0.01);
    ampEnvelope.SetDecayTime(1);
    ampEnvelope.SetSustainLevel(0);
    ampEnvelope.SetReleaseTime(0.4);

    filter.Init(audioSampleRate);
    filter.SetRes(0.2);

    filterEnvelope.Init(audioSampleRate, 4);
    filterEnvelope.SetAttackTime(0.01);
    filterEnvelope.SetDecayTime(1);
    filterEnvelope.SetSustainLevel(0);
    filterEnvelope.SetReleaseTime(0.4);

    filterFreq = 20000;
    osc2PitchSemitones = -12;
    osc2PitchFine = 0;

    osc1Level = 1;
    osc2Level = 1;
    noiseLevel = 0;
}

float SynthEngine::Process() {
    //Get sample for each sound source and scale them to their current level
    float oscillator1Value = oscillator1.Process() * osc1Level;
    float oscillator2Value = oscillator2.Process() * osc2Level;
    float noiseValue = noise.Process() * noiseLevel;

    //Sum the sound source samples to get a mixed signal. Dividing by the number of sources then compensates the level
    float out = (oscillator1Value + oscillator2Value + noiseValue) / 3;

    //Get the level of the filter envelope for the current sample. The frequency of the filter is then calculated from this and the main filter frequency control
    float filterEnvValue = filterEnvelope.Process(gateOpen) * filterEnvelopeAmount;
    filter.SetFreq(filterFreq + filterEnvValue);
    out = filter.Process(out);

    //Change the amplitude of the sound based on the amp envelope
    float ampEnvValue = ampEnvelope.Process(gateOpen);
    out = out * ampEnvValue;

    //Apply amplitude scaling based on the volume control
    out = out * volume;

    return out;
}

void SynthEngine::SetGate(bool state) {
    gateOpen = state;
}

void SynthEngine::SetParameter(int parameterId, float value) {
    auto parameter = (Parameter) parameterId;

    switch (parameter) {
        case Parameter::NoteValue:{
            float osc1Frequency = mtof(value);
            oscillator1.SetFreq(osc1Frequency);
            float osc2Frequency = mtof(value + osc2PitchSemitones + osc2PitchFine / 100);
            oscillator2.SetFreq(osc2Frequency);
            break;
        }

        case Parameter::Volume:{
            volume = value / 100;
            break;
        }

        case Parameter::Osc1Waveform:{
            if ((Waveform)value == Waveform::Square){
                oscillator1.SetWaveform(Oscillator::WAVE_SQUARE);
            }
            if ((Waveform)value == Waveform::Saw){
                oscillator1.SetWaveform(Oscillator::WAVE_SAW);
            }
            if ((Waveform)value == Waveform::Sin){
                oscillator1.SetWaveform(Oscillator::WAVE_SIN);
            }
            if ((Waveform)value == Waveform::Triangle){
                oscillator1.SetWaveform(Oscillator::WAVE_TRI);
            }

            break;
        }

        case Parameter::Osc2Waveform:{
            if ((Waveform)value == Waveform::Square){
                oscillator2.SetWaveform(Oscillator::WAVE_SQUARE);
            }
            if ((Waveform)value == Waveform::Saw){
                oscillator2.SetWaveform(Oscillator::WAVE_SAW);
            }
            if ((Waveform)value == Waveform::Sin){
                oscillator2.SetWaveform(Oscillator::WAVE_SIN);
            }
            if ((Waveform)value == Waveform::Triangle){
                oscillator2.SetWaveform(Oscillator::WAVE_TRI);
            }

            break;
        }

        case Parameter::Osc2PitchSemitones:{
            osc2PitchSemitones = value;
            break;
        }

        case Parameter::Osc2PitchFine:{
            osc2PitchFine = value;
            break;
        }

        case Parameter::Osc1Level:{
            osc1Level = value / 100;
            break;
        }

        case Parameter::Osc2Level:{
            osc2Level = value / 100;
            break;
        }

        case Parameter::NoiseLevel:{
            noiseLevel = value / 100;
            break;
        }

        case Parameter::AmpAttack:{
            ampEnvelope.SetAttackTime(value);
            break;
        }

        case Parameter::AmpDecay:{
            ampEnvelope.SetDecayTime(value);
            break;
        }

        case Parameter::AmpSustain:{
            ampEnvelope.SetSustainLevel(value);
            break;
        }

        case Parameter::AmpRelease:{
            ampEnvelope.SetReleaseTime(value);
            break;
        }

        case Parameter::FilterFreq:{
            filterFreq = value;
            break;
        }

        case Parameter::FilterRes:{
            filter.SetRes(value);
            break;
        }

        case Parameter::FilterEnvAmount:{
            filterEnvelopeAmount = value;
            break;
        }

        case Parameter::FilterAttack:{
            filterEnvelope.SetAttackTime(value);
            break;
        }

        case Parameter::FilterDecay:{
            filterEnvelope.SetDecayTime(value);
            break;
        }

        case Parameter::FilterSustain:{
            filterEnvelope.SetSustainLevel(value);
            break;
        }

        case Parameter::FilterRelease:{
            filterEnvelope.SetReleaseTime(value);
            break;
        }
    }
}