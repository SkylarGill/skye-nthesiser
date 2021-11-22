#pragma once

#include "../modulation/Modulatable.h"

class Synth : public Modulatable {
    virtual void Init(float sampleRate) = 0;
    virtual void SetGate(bool state) = 0;
    virtual float Process() = 0;
};