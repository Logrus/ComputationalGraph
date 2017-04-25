/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#include "ComputationalGraph.h"
using std::string;

ComputationalGraph::ComputationalGraph()
{
    grad_input_last_gate = 1; // This is gradient input for the last gate
}

void ComputationalGraph::add(string name, Gate::Ptr g, float &input_a, float &input_b){

    // Connect inputs
    g->input_a.connect( &input_a );
    g->input_b.connect( &input_b );

    // Default gradient input for this gate
    g->grad_input.connect( &grad_input_last_gate );

    gates.emplace({name, g});
    order.emplace_back(name);
}

void ComputationalGraph::add(string name, Gate::Ptr g, string input_a, float &input_b){

    // Find previous gate with name input_a
    // Note: throwS if element isn't found
    auto prev_g = gates.at(input_a);

    // Connect inputs
    g->input_a.connect( &(prev_g->output) );
    g->input_b.connect( &input_b );

    // Default gradient input for this gate
    g->grad_input.connect( &grad_input_last_gate );

    // Connect gradients for previous gate
    prev_g->grad_input.connect( &(g->gradout_a) );

    gates.emplace({name, g});
    order.emplace_back(name);
}

void ComputationalGraph::add(string name, Gate::Ptr g, float &input_a, string input_b){

    // Find previous gate with name input_b
    // Note: throws if element isn't found
    auto prev_g = gates.at(input_b);

    // Connect inputs
    g->input_a.connect( &input_a );
    g->input_b.connect( &(prev_g->output) );

    // Default gradient input for this gate
    g->grad_input.connect( &grad_input_last_gate );

    // Connect gradients for previous gate
    prev_g->grad_input.connect( &(g->gradout_b) );

    gates.emplace({name, g});
    order.emplace_back(name);
}

void ComputationalGraph::add(string name, Gate::Ptr g, string input_a, string input_b){

    // Find previous gate with name input_a
    // Note: throws if element isn't found
    auto prev_g_a = gates.at(input_a);
    // Find previous gate with name input_b
    auto prev_g_b = gates.at(input_b);

    // Connect inputs
    g->input_a.connect( &(prev_g_a->output) );
    g->input_b.connect( &(prev_g_b->output) );

    // Default gradient input for this gate
    g->grad_input.connect( &grad_input_last_gate );

    // Connect gradients for previous gates
    prev_g_a->grad_input.connect( &(g->gradout_a) );
    prev_g_b->grad_input.connect( &(g->gradout_b) );

    gates.emplace({name, g});
    order.emplace_back(name);
}

void ComputationalGraph::add(string name, Gate::Ptr g, string input_a){

    // Find previous gate with name input_a
    // Note: throws if element isn't found
    auto prev_g_a = gates.at(input_a);

    // Connect inputs
    g->input_a.connect( &(prev_g_a->output) );

    // Default gradient input for this gate
    g->grad_input.connect( &grad_input_last_gate );

    // Connect gradients for previous gates
    prev_g_a->grad_input.connect( &(g->gradout_a) );

    gates.emplace({name, g});
    order.emplace_back(name);
}

void ComputationalGraph::add(string name, Gate::Ptr g, float &input_a){

    // Connect inputs
    g->input_a.connect( &input_a );

    // Default gradient input for this gate
    g->grad_input.connect( &grad_input_last_gate );

    gates.emplace({name, g});
    order.emplace_back(name);
}


void ComputationalGraph::forward(){
    // Call gates in topological order
    for (auto it = order.begin(); it!=order.end(); ++it){
        auto g = gates.at(*it);
        g->forward();
        std::cout << "[forward] Gate " << *it << " output is " << g->output << std::endl;
    }
}

void ComputationalGraph::backward(){
    // Call gates in reverse topological order
    for (auto it = order.rbegin(); it!=order.rend(); ++it){
        auto g = gates.at(*it);
        g->backward();

        std::cout << "[backward] Gate " << *it << " gradoutput_a is " << g->gradout_a;
        if(!g->unary){
            std::cout << " gradoutput_b is " << g->gradout_b;
        }
        std::cout << std::endl;

    }
}

ComputationalGraph::~ComputationalGraph(){}
