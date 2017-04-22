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
    typedef std::shared_ptr<Gate> Ptr;

    Gate(bool u) : unary(u) {}
    Gate(const Gate& g) = delete;
    Gate(Gate&& g) noexcept : 
        unary(g.unary), 
        output(g.output),
        gradout_a(g.gradout_a),
        gradout_b(g.gradout_b) {
            input_a = g.input_a;
            g.input_a = nullptr;
            input_b = g.input_b;
            g.input_b = nullptr;
            grad_input = g.grad_input;
            g.grad_input = nullptr;
        }
    
    Gate& operator=(const Gate& ) = delete;
    Gate& operator=(Gate&& g) = delete;

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
