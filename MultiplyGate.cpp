#include "MultiplyGate.hpp"

float MultiplyGate::forward(float a, float b)
{
  return a * b; // cool stuff!
}

void MultiplyGate::backward() {}