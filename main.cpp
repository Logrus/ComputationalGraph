#include <iostream>
#include <cstdlib>
#include <utility>
#include <tuple>
#include "Gate.h"
#include "AddGate.h"
#include "MultiplyGate.h"

using std::tie; // Unpacks std::pair to values
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[])
{
  AddGate add;
  MultiplyGate mul;

  float x = -2, y = 5, z = -4;

  bool manual;
  cout << "Do you want manual input? (1/0)" << endl;
  cin >> manual;
  if (manual){
      cout << "Input x, y, z separated by spaces" << endl;
      cin >> x >> y >> z;
  }

  cout << "We have f(x,y,z) = (x+y)*z" << endl;
  cout << "x= " << x << " y= " << y << " z= " << z << endl;

  // Doing forward pass
  float q = add.forward(x, y);
  cout << "q=(x+y)= " << q << endl;

  float f = mul.forward(q, z);
  cout << "f=(q*z)= " << f << endl;

  // Doing backward pass
  float dq, dz;
  tie(dq,dz) = mul.backward(1);

  float dx, dy;
  tie(dx,dy) = add.backward(dq);

  cout << "dx= " << dx << " dy= " << dy << " dz= " << dz << endl;

  return EXIT_SUCCESS;
}
