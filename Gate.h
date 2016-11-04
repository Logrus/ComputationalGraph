#pragma once
#include <utility>
using std::pair;

/**
 * @brief Abstract Base Class (ABS) Gate
 */
class Gate
{
public:
    virtual float forward(float, float) = 0;
    virtual pair<float, float> backward(float) = 0;
    virtual ~Gate() {};

private:

};
