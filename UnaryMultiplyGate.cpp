/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#include "UnaryMultiplyGate.h"

void UnaryMultiplyGate::forward()
{
    // Compute local gradient
    dinput_a = 2;
    // Compute forward pass
    output = (*input_a) * 2;
}

void UnaryMultiplyGate::backward()
{
    // Chain rule
    gradout_a = (*grad_input) * dinput_a;
}
