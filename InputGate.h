#ifndef INPUTGATE_H
#define INPUTGATE_H
#include "Gate.h"
#include <vector>

using std::vector;

class InputGate : public Gate
{
public:
    InputGate(vector<float> input);
};

#endif // INPUTGATE_H
