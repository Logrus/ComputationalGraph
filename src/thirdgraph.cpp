/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#include <iostream> // cout, endl
#include <cstdlib>  // EXIT_SUCCESS
#include "ComputationalGraph.h"
#include "Gate.h"
#include "AddGate.h"
#include "MultiplyGate.h"
#include "MaxGate.h"
#include "UnaryMultiplyGate.h"
#include "UnaryAddGate.h"
#include "UnaryExponentGate.h"
#include "UnaryXInverseGate.h"
#include "SigmoidGate.h"

using std::cout;
using std::endl;
using std::make_shared;

int main(int argc, char* argv[])
{

  float w0 =  2, x0 = -1;
  float w1 = -3, x1 = -2;
  float w2 = -3;

  ComputationalGraph graph;

  graph.add("mul1_1", make_shared<MultiplyGate>(), w0, x0);
  graph.add("mul1_2", make_shared<MultiplyGate>(), w1, x1);

  graph.add("sum2", make_shared<AddGate>(), "mul1_1", "mul1_2");

  graph.add("sum3", make_shared<AddGate>(), "sum2", w2);

  // Sigmoid gate can substitute all consecutive gates
  graph.add("sigm", make_shared<SigmoidGate>(), "sum3");

  // Or can be done one operation at a time
  //graph.add("umul", make_shared<UnaryMultiplyGate>(-1), "sum3");
  //graph.add("uexp", make_shared<UnaryExponentGate>(), "umul");
  //graph.add("uadd", make_shared<UnaryAddGate>(+1), "uexp");
  //graph.add("uinv", make_shared<UnaryXInverseGate>(), "uadd");

  graph.forward();
  graph.backward();

  cout << "Interpretation:" << endl;
  cout << " dw0 " << graph.gates["mul1_1"]->gradout_a << endl;
  cout << " dx0 " << graph.gates["mul1_1"]->gradout_b << endl;
  cout << " dw1 " << graph.gates["mul1_2"]->gradout_a << endl;
  cout << " dx1 " << graph.gates["mul1_2"]->gradout_b << endl;
  cout << " dw2 " << graph.gates["sum2"]->gradout_b << endl;

  return EXIT_SUCCESS;
}
