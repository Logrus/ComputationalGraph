/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include "Gate.h"
#include <cmath>

class UnaryExponentGate : public Gate
{
public:

    inline UnaryExponentGate() : Gate(true) {}

    void forward();
    void backward();

    // Local gradient
    float dinput_a;
    float dinput_b;
};

