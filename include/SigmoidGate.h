/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include "Gate.h"
#include <math.h>

class SigmoidGate : public Gate
{
public:

    float add;

    void forward();
    void backward();

    // Local gradients
    float dinput_a;
};
