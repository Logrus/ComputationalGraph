/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include "Gate.h"


class MaxGate : public Gate
{
public:

    inline MaxGate() : Gate(false) {}

    void forward();
    void backward();

    // Local gradients
    float dinput_a;
    float dinput_b;

};
