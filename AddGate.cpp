#include "AddGate.h"

AddGate::AddGate()
{

}

float AddGate::forward(float a, float b)
{
    da = 1;
    db = 1;
    return a+b;
}

pair<float, float> AddGate::backward(float grad)
{
    return { grad*da, grad*db };
}
