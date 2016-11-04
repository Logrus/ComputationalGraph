/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#include "AddGate.h"

void AddGate::forward()
{
    // Compute local gradient
    dinput_a = 1;
    dinput_b = 1;
    // Compute forward pass
    output = (*input_a) + (*input_b);
}

void AddGate::backward()
{
    // Chain rule
    gradout_a = (*grad_input) * dinput_a;
    gradout_b = (*grad_input) * dinput_b;
}
