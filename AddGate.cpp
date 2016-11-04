#include "AddGate.h"

float AddGate::forward(float a, float b)
{
    // Compute local gradient
    da = 1;
    db = 1;
    // Compute forward pass
    return a+b;
}

pair<float, float> AddGate::backward(float grad)
{
    return { grad*da, grad*db };
}
