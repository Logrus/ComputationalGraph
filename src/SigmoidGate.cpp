/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#include "SigmoidGate.h"

void SigmoidGate::forward(){

    // Sigmoid function
    float sigm = 1.f/(1.f+exp(-input_a));

    // Compute local gradient
    dinput_a = sigm*(1-sigm);
    // Compute forward pass
    output = sigm;
}

void SigmoidGate::backward(){

    // Chain rule
    gradout_a = grad_input * dinput_a;
}
