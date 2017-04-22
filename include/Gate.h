/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include <memory>

/**
 * @brief Base Class Gate
 */
class Gate
{
public:
    typedef std::unique_ptr<Gate> Ptr;

    inline Gate(bool u) : unary(u) {}

    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual ~Gate() {};

    const bool unary;

    // Variables for forward pass
    float *input_a, *input_b; // Connect to the input variables
    float output;             // Output is computed in forward

    // Variables for output pass
    float *grad_input;          // Connect to the input gradient
    float gradout_a, gradout_b; // Output gradients
};
