#ifndef ADDGATE_H
#define ADDGATE_H
#include "Gate.h"
#include <utility>
using std::pair;

class AddGate : public Gate
{
public:
    AddGate();

    float forward(float, float);
    pair<float, float> backward(float grad);

protected:
    float da;
    float db;
};

#endif // ADDGATE_H
