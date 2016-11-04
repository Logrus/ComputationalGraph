/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#include "UnaryExponentGate.h"

void UnaryExponentGate::forward(){

    // Compute local gradient
    dinput_a = exp((*input_a));
    // Compute forward pass
    output = exp((*input_a));
}

void UnaryExponentGate::backward(){

    // Chain rule
    gradout_a = (*grad_input) * dinput_a;
}
