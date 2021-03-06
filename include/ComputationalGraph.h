/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include <iostream> // cin, cout
#include "Gate.h"
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>

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
    void add(std::string name, Gate::Ptr g, float &input_a, float &input_b);

    /**
     * @brief This method add a new gate to the computational graph
     * @param name - of the gate which can be referred later
     * @param g - pointer to the gate object
     * @param input_a - name of the pevious gate
     * @param input_b - input value (float)
     */
    void add(std::string name, Gate::Ptr g, std::string input_a, float &input_b);

    /**
     * @brief This method add a new gate to the computational graph
     * @param name - of the gate which can be referred later
     * @param g - pointer to the gate object
     * @param input_a - input value (float)
     * @param input_b - name of the pevious gate
     */
    void add(std::string name, Gate::Ptr g, float &input_a, std::string input_b);

    /**
     * @brief This method add a new gate to the computational graph
     * @param name - of the gate which can be referred later
     * @param g - pointer to the gate object
     * @param input_a - name of the pevious gate
     * @param input_b - name of the pevious gate
     */
    void add(std::string name, Gate::Ptr g, std::string input_a, std::string input_b);

    /**
     * @brief This method add a new unary gate to the computational graph
     * @param name - of the gate which can be referred later
     * @param g - pointer to the gate object
     * @param input_a - input value (float)
     */
    void add(std::string name, Gate::Ptr g, float &input_a);

    /**
     * @brief This method add a new unary gate to the computational graph
     * @param name - of the gate which can be referred later
     * @param g - pointer to the gate object
     * @param input_a - name of the pevious gate
     */
    void add(std::string name, Gate::Ptr g, std::string input_a);

    // Forward/backward API
    void forward();
    void backward();

    // Internal data
    std::unordered_map<std::string, Gate::Ptr> gates;
    std::vector<std::string> order;
    float grad_input_last_gate;
};
