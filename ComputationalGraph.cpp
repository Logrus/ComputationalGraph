/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#include "ComputationalGraph.h"

ComputationalGraph::ComputationalGraph()
{
    grad_input_last_gate = 1; // This is gradient input for the last gate
}

void ComputationalGraph::add(string name, Gate *g, float &input_a, float &input_b){

    // Connect inputs
    g->input_a = &input_a;
    g->input_b = &input_b;

    // Default gradient input for this gate
    g->grad_input = &grad_input_last_gate;

    gates.insert({name, g});
}

void ComputationalGraph::add(string name, Gate *g, string input_a, float &input_b){

    // Find previous gate with name input_a
    // Note: throws by design if element isn't found
    Gate* prev_g = gates.at(input_a);

    // Connect inputs
    g->input_a = &(prev_g->output);
    g->input_b = &input_b;

    // Default gradient input for this gate
    g->grad_input = &grad_input_last_gate;

    // Connect gradients for previous gate
    prev_g->grad_input = &(g->gradout_a);

    gates.insert({name, g});
}

void ComputationalGraph::add(string name, Gate *g, float &input_a, string input_b){

    // Find previous gate with name input_b
    // Note: throws by design if element isn't found
    Gate* prev_g = gates.at(input_b);

    // Connect inputs
    g->input_a = &input_a;
    g->input_b = &(prev_g->output);

    // Default gradient input for this gate
    g->grad_input = &grad_input_last_gate;

    // Connect gradients for previous gate
    prev_g->grad_input = &(g->gradout_b);

    gates.insert({name, g});
}

void ComputationalGraph::add(string name, Gate *g, string input_a, string input_b){

    // Find previous gate with name input_a
    // Note: throws by design if element isn't found
    Gate* prev_g_a = gates.at(input_a);
    // Find previous gate with name input_b
    Gate* prev_g_b = gates.at(input_b);

    // Connect inputs
    g->input_a = &(prev_g_a->output);
    g->input_b = &(prev_g_b->output);

    // Default gradient input for this gate
    g->grad_input = &grad_input_last_gate;

    // Connect gradients for previous gates
    prev_g_a->grad_input = &(g->gradout_a);
    prev_g_b->grad_input = &(g->gradout_b);

    gates.insert({name, g});
}

void ComputationalGraph::forward(){
    // Call gates in topological order
    for (auto it = gates.rbegin(); it!=gates.rend(); ++it){
        it->second->forward();
        std::cout << "[forward] Gate " << it->first << " output is " << it->second->output << std::endl;
    }
}

void ComputationalGraph::backward(){
    // Call gates in reverse topological order
    for (auto it = gates.begin(); it!=gates.end(); ++it){
        it->second->backward();
        std::cout << "[backward] Gate " << it->first << " gradoutput_a is " << it->second->gradout_a << " gradoutput_b is " << it->second->gradout_b << std::endl;
    }
}

ComputationalGraph::~ComputationalGraph(){
    // Cleanup all gates
    for(auto gate: gates){
        delete gate.second;
    }
}
