/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#include "MaxGate.h"

void MaxGate::forward()
{
    if((*input_a) >= (*input_b)){
        // Compute local gradient
        dinput_a = 1;
        dinput_b = 0;
        // Compute forward pass
        output = (*input_a);
    } else {
        // Compute local gradient
        dinput_a = 0;
        dinput_b = 1;
        // Compute forward pass
        output = (*input_b);
    }

}

void MaxGate::backward()
{
    // Chain rule
    gradout_a = (*grad_input) * dinput_a;
    gradout_b = (*grad_input) * dinput_b;
}
