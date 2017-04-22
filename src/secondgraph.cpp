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

using std::cout;
using std::endl;
using std::make_shared;

int main(int argc, char* argv[])
{

  float x = 3, y = -4, z = 2, w = -1;

  ComputationalGraph graph;

  graph.add("mul1", make_shared<MultiplyGate>(), x, y);
  graph.add("max1", make_shared<MaxGate>(),      z, w);

  graph.add("sum(mul1,max1)", make_shared<AddGate>(), "mul1", "max1");
  graph.add("umul", make_shared<UnaryMultiplyGate>(2), "sum(mul1,max1)");

  graph.forward();
  graph.backward();

  cout << "Interpretation:" << endl;
  cout << " dx " << graph.gates["mul1"]->gradout_a << endl;
  cout << " dy " << graph.gates["mul1"]->gradout_b << endl;
  cout << " dz " << graph.gates["max1"]->gradout_a << endl;
  cout << " dw " << graph.gates["max1"]->gradout_b << endl;

  return EXIT_SUCCESS;
}
