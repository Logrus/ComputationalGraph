# ComputationalGraph
A simple implementation of scalar valued computational graph developed for understanding.

It is based on Stanford's cs231n (http://cs231n.github.io/optimization-2/).

# Build

    make buid
    cd build
    cmake ..
    make
  
# Running

The graph in the example is from cs231n.

<img src="https://github.com/Logrus/ComputationalGraph/blob/master/img/graph.png" width="350"/ alt="computational graph">

[Image source: http://cs231n.stanford.edu/]

Default code:

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

   
