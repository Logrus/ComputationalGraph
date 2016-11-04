/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include "Gate.h"

class MultiplyGate : public Gate
{
public:

    void forward();
    void backward();

    // Local gradients
    float dinput_a;
    float dinput_b;
};
