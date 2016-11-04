# ComputationalGraph

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A simple implementation of a scalar valued computational graph developed for understanding.

It is based on Stanford's cs231n (http://cs231n.github.io/optimization-2/).

# Build

    mkdir buid
    cd build
    cmake ..
    make
  
# Running Example 1

The graph in the example is from cs231n.

<img src="https://github.com/Logrus/ComputationalGraph/blob/master/img/graph.png" width="350"/ alt="computational graph">

[Image source: http://cs231n.stanford.edu/]

Code (src/main.cpp):

```C++
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
```

Example run:

     ./main
     [forward] Gate sum1 output is 3
     [forward] Gate mul1 output is -12
     [backward] Gate mul1 gradoutput_a is -4 gradoutput_b is 3
     [backward] Gate sum1 gradoutput_a is -4 gradoutput_b is -4
     Interpretation:
      dx -4
      dy -4
      dz 3

# Running Example 2
   
<img src="https://github.com/Logrus/ComputationalGraph/blob/master/img/graph2.png" width="350"/ alt="computational graph 2">

[Image source: http://cs231n.stanford.edu/]

Code (src/secondgraph.cpp):

```C++
  float x = 3, y = -4, z = 2, w = -1;

  ComputationalGraph graph;

  graph.add("mul1", new MultiplyGate(), x, y);
  graph.add("max1", new MaxGate(),      z, w);

  graph.add("sum(mul1,max1)", new AddGate(), "mul1", "max1");
  graph.add("umul", new UnaryMultiplyGate(), "sum(mul1,max1)");

  graph.forward();
  graph.backward();

  cout << "Interpretation:" << endl;
  cout << " dx " << graph.gates["mul1"]->gradout_a << endl;
  cout << " dy " << graph.gates["mul1"]->gradout_b << endl;
  cout << " dz " << graph.gates["max1"]->gradout_a << endl;
  cout << " dw " << graph.gates["max1"]->gradout_b << endl;
```


Example run:

     ./secondgraph
    [forward] Gate mul1 output is -12
    [forward] Gate max1 output is 2
    [forward] Gate sum(mul1,max1) output is -10
    [forward] Gate umul output is -20
    [backward] Gate umul gradoutput_a is 2 gradoutput_b is 0
    [backward] Gate sum(mul1,max1) gradoutput_a is 2 gradoutput_b is 2
    [backward] Gate max1 gradoutput_a is 2 gradoutput_b is 0
    [backward] Gate mul1 gradoutput_a is -8 gradoutput_b is 6
    Interpretation:
     dx -8
     dy 6
     dz 2
     dw 0


# Running Example 3
   
<img src="https://github.com/Logrus/ComputationalGraph/blob/master/img/graph3.png" width="350"/ alt="computational graph 3">

[Image source: http://cs231n.stanford.edu/]

Code (src/thirdgraph.cpp):

```C++
  float w0 =  2, x0 = -1;
  float w1 = -3, x1 = -2;
  float w2 = -3;

  ComputationalGraph graph;

  graph.add("mul1_1", new MultiplyGate(), w0, x0);
  graph.add("mul1_2", new MultiplyGate(), w1, x1);

  graph.add("sum2", new AddGate(), "mul1_1", "mul1_2");

  graph.add("sum3", new AddGate(), "sum2", w2);

  // Sigmoid gate can substitute all consecutive gates
  //graph.add("sigm", new SigmoidGate(), "sum3");

  // Or can be done one operation at a time
  graph.add("umul", new UnaryMultiplyGate(-1), "sum3");
  graph.add("uexp", new UnaryExponentGate(), "umul");
  graph.add("uadd", new UnaryAddGate(+1), "uexp");
  graph.add("uinv", new UnaryXInverseGate(), "uadd");

  graph.forward();
  graph.backward();

  cout << "Interpretation:" << endl;
  cout << " dw0 " << graph.gates["mul1_1"]->gradout_a << endl;
  cout << " dx0 " << graph.gates["mul1_1"]->gradout_b << endl;
  cout << " dw1 " << graph.gates["mul1_2"]->gradout_a << endl;
  cout << " dx1 " << graph.gates["mul1_2"]->gradout_b << endl;
  cout << " dw2 " << graph.gates["sum2"]->gradout_b << endl;
```


Example run:

    [forward] Gate mul1_1 output is -2
    [forward] Gate mul1_2 output is 6
    [forward] Gate sum2 output is 4
    [forward] Gate sum3 output is 1
    [forward] Gate sigm output is 0.731059
    [backward] Gate sigm gradoutput_a is 0.196612 gradoutput_b is 0
    [backward] Gate sum3 gradoutput_a is 0.196612 gradoutput_b is 0.196612
    [backward] Gate sum2 gradoutput_a is 0.196612 gradoutput_b is 0.196612
    [backward] Gate mul1_2 gradoutput_a is -0.393224 gradoutput_b is -0.589836
    [backward] Gate mul1_1 gradoutput_a is -0.196612 gradoutput_b is 0.393224
    Interpretation:
     dw0 -0.196612
     dx0 0.393224
     dw1 -0.393224
     dx1 -0.589836
     dw2 0.196612
