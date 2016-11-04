/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once

/**
 * @brief Base Class Gate
 */
class Gate
{
public:

    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual ~Gate() {};

    // Variables for forward pass
    float *input_a, *input_b; // Connect to the input variables
    float output;             // Output is computed in forward

    // Variables for output pass
    float *grad_input;          // Connect to the input gradient
    float gradout_a, gradout_b; // Output gradients
};
