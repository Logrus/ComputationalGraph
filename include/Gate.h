/*
 * MIT License
 * Copyright (c) 2016 Vladislav Tananaev
 */
#pragma once
#include <memory>

/**
 * @brief Base Class Gate
 */
class Gate
{
public:
    typedef std::shared_ptr<Gate> Ptr;
    // A helper class that hides raw pointer access
    class placeholder {
        float* conn;
    public:
        void connect(float* f) { conn = f; }
        placeholder(){}
        ~placeholder(){}
        placeholder(const placeholder& p) { conn = p.conn; }
        placeholder(placeholder&& p) noexcept { conn = p.conn; p.conn = nullptr; }
        placeholder& operator=(const placeholder& p) { conn = p.conn; return *this;}
        placeholder& operator=(placeholder&& p) { conn = p.conn; p.conn = nullptr; return *this;}
        placeholder& operator=(float* f) { conn = f; return *this;}
        float operator+(const placeholder& p) { return *conn + *p.conn; }
        float operator-(const placeholder& p) { return *conn - *p.conn; }
        float operator*(const placeholder& p) { return *conn * *p.conn; }
        float operator/(const placeholder& p) { return *conn / *p.conn; }
        bool operator>(const placeholder& p)  { return *conn > *p.conn; }
        bool operator>=(const placeholder& p) { return *conn >= *p.conn; }
        bool operator<=(const placeholder& p) { return *conn <= *p.conn; }
        bool operator<(const placeholder& p)  { return *conn < *p.conn; }
        bool operator==(const placeholder& p) { return *conn == *p.conn; }
        operator float() const { return *(conn); }
    };

    Gate(bool u) : unary(u) {}
    Gate(const Gate& g) = delete;
    Gate(Gate&& g) noexcept : 
        unary(g.unary), 
        output(g.output),
        gradout_a(g.gradout_a),
        gradout_b(g.gradout_b) {
            input_a = g.input_a;
            g.input_a = nullptr;
            input_b = g.input_b;
            g.input_b = nullptr;
            grad_input = g.grad_input;
            g.grad_input = nullptr;
        }
    
    Gate& operator=(const Gate& ) = delete;
    Gate& operator=(Gate&& g) = delete;

    virtual void forward() = 0;
    virtual void backward() = 0;
    virtual ~Gate() {};

    const bool unary;

    // Variables for forward pass
    placeholder input_a, input_b; // Connect to the input variables
    float output;             // Output is computed in forward

    // Variables for output pass
    placeholder grad_input;          // Connect to the input gradient
    float gradout_a, gradout_b; // Output gradients
};
