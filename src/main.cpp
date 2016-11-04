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

int main(int argc, char* argv[])
{

  float x = -2, y = 5, z = -4;

  ComputationalGraph graph;

  graph.add("sum1", new AddGate(), x, y);
  graph.add("mul1", new MultiplyGate(), "sum1", z);

  graph.forward();
  graph.backward();

  cout << "Interpretation:" << endl;
  cout << " dx " << graph.gates["sum1"]->gradout_a << endl;
  cout << " dy " << graph.gates["sum1"]->gradout_b << endl;
  cout << " dz " << graph.gates["mul1"]->gradout_b << endl;

  return EXIT_SUCCESS;
}
