/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#include "UnaryMultiplyGate.h"

UnaryMultiplyGate::UnaryMultiplyGate(float multiplier) : mult(multiplier), Gate(true)
{
}

void UnaryMultiplyGate::forward(){

    // Compute local gradient
    dinput_a = mult;
    // Compute forward pass
    output = input_a * mult;
}

void UnaryMultiplyGate::backward(){

    // Chain rule
    gradout_a = grad_input * dinput_a;
}
