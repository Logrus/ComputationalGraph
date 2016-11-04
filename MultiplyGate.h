#pragma once
#include "Gate.h"
#include <utility>
using std::pair;

class MultiplyGate : public Gate
{
public:

    float forward(float a, float b);
    pair<float, float> backward(float grad);

protected:
    float da;
    float db;
};
