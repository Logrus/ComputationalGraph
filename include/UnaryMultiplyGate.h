/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include "Gate.h"

class UnaryMultiplyGate : public Gate
{
public:

    UnaryMultiplyGate(float multiplier);

    float mult;

    void forward();
    void backward();

    // Local gradients
    float dinput_a;

};
