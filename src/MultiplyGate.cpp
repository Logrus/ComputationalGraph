/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#include "MultiplyGate.h"

void MultiplyGate::forward()
{
    // Compute local gradient
    dinput_a = input_b;
    dinput_b = input_a;
    // Compute forward pass
    output = input_a * input_b;
}

void MultiplyGate::backward()
{
    // Chain rule
    gradout_a = grad_input * dinput_a;
    gradout_b = grad_input * dinput_b;
}
