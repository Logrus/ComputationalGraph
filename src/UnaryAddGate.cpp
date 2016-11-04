/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#include "UnaryAddGate.h"

UnaryAddGate::UnaryAddGate(float addition) : add(addition)
{
}


void UnaryAddGate::forward(){

    // Compute local gradient
    dinput_a = 1;
    // Compute forward pass
    output = (*input_a) + add;
}

void UnaryAddGate::backward(){

    // Chain rule
    gradout_a = (*grad_input) * dinput_a;
}
