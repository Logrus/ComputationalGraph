/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include "Gate.h"
#include <cmath>

class SigmoidGate : public Gate
{
public:

    inline SigmoidGate() : Gate(true) {}

    float add;

    void forward();
    void backward();

    // Local gradients
    float dinput_a;
};
