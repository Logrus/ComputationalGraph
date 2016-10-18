#include <iostream>
#include <cstdlib>
#include "Gate.hpp"
#include "MultiplyGate.hpp"


int main(int argc, char* argv[])
{
  Gate* p = new MultiplyGate();
  std::cout << p->forward(-2,3) << std::endl;
  
  delete p;
  return EXIT_SUCCESS;
}
