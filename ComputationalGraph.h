/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include <iostream> // cin, cout
#include "Gate.h"
#include <map>
#include <string>

using std::map;
using std::string;

class ComputationalGraph
{
public:
    ComputationalGraph();
    ~ComputationalGraph();

    /**
     * @brief This method add a new gate to the computational graph
     * @param name - of the gate which can be referred later
     * @param g - pointer to the gate object
     * @param input_a - input value (float)
     * @param input_b - input value (float)
     */
    void add(string name, Gate *g, float &input_a, float &input_b);

    /**
     * @brief This method add a new gate to the computational graph
     * @param name - of the gate which can be referred later
     * @param g - pointer to the gate object
     * @param input_a - name of the pevious gate
     * @param input_b - input value (float)
     */
    void add(string name, Gate *g, string input_a, float &input_b);

    /**
     * @brief This method add a new gate to the computational graph
     * @param name - of the gate which can be referred later
     * @param g - pointer to the gate object
     * @param input_a - input value (float)
     * @param input_b - name of the pevious gate
     */
    void add(string name, Gate *g, float &input_a, string input_b);

    /**
     * @brief This method add a new gate to the computational graph
     * @param name - of the gate which can be referred later
     * @param g - pointer to the gate object
     * @param input_a - input value (float)
     * @param input_b - name of the pevious gate
     */
    void add(string name, Gate *g, string input_a, string input_b);

    // Forward/backward API
    void forward();
    void backward();

    // Internal data
    map< string, Gate *> gates;
    float grad_input_last_gate;
};
