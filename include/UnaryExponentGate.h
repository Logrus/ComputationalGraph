/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include "Gate.h"
#include <math.h>

class UnaryExponentGate : public Gate
{
public:

    void forward();
    void backward();

    // Local gradient
    float dinput_a;
    float dinput_b;
};

