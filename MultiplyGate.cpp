#include "MultiplyGate.h"

float MultiplyGate::forward(float a, float b)
{
    // Compute local gradient
    da = b;
    db = a;
    // Compute forward pass
    return a * b;
}

pair<float, float> MultiplyGate::backward(float grad) {
    return { grad*da, grad*db };
}
