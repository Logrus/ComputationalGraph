#pragma once

class Gate
{
  public:
    virtual float forward(float, float) = 0;
    virtual void backward() = 0;
    virtual ~Gate() {};

  private:

};
