/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#include "UnaryXInverseGate.h"


void UnaryXInverseGate::forward(){

    // Compute local gradient
    dinput_a = -1.f/((*input_a)*(*input_a));
    // Compute forward pass
    output = 1.f/(*input_a);
}

void UnaryXInverseGate::backward(){

    // Chain rule
    gradout_a = (*grad_input) * dinput_a;
}
