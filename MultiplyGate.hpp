#pragma once
#include "Gate.hpp"

class MultiplyGate : public Gate
{
  public:
    inline MultiplyGate() {}; // Default ctor
    inline ~MultiplyGate() {}; // Default dtor

    void backward();
    float forward(float a, float b);

  private:

};
