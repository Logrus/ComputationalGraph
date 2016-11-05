/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include "Gate.h"

class AddGate : public Gate
{
public:

    inline AddGate() : Gate(false) {}

    void forward();
    void backward();

    // Local gradient
    float dinput_a;
    float dinput_b;
};
