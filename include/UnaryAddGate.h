/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include "Gate.h"

class UnaryAddGate : public Gate
{
public:

    UnaryAddGate(float addition);

    float add;

    void forward();
    void backward();

    // Local gradients
    float dinput_a;
};
