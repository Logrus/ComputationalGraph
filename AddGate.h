/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include "Gate.h"

class AddGate : public Gate
{
public:

    void forward();
    void backward();

    // Local gradient
    float dinput_a;
    float dinput_b;
};
