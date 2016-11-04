#include <iostream>
#include <cstdlib>
#include <utility>
#include "Gate.h"
#include "InputGate.h"
#include "AddGate.h"
#include "MultiplyGate.h"
using std::pair;

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
  AddGate add;
  MultiplyGate mul;

  cout << "We have f(x,y,z) = (x+y)*z" << endl;
  float x = -2, y = 5, z = -4;
  cout << "x= " << x << " y= " << y << " z= " << z << endl;

  // Doing forward pass
  float q = add.forward(x, y);
  cout << "q=(x+y)= " << q << endl;

  float f = mul.forward(q, z);
  cout << "f=(q*z)= " << f << endl;

  // Doing backward pass
  auto grad = mul.backward(1);
  float dq = grad.first;
  float dz = grad.second;

  grad = add.backward(dq);
  float dx = grad.first;
  float dy = grad.second;

  cout << "dx= " << dx << " dy= " << dy << " dz= " << dz << endl;

  return EXIT_SUCCESS;
}
