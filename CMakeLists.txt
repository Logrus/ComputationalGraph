cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(tinynet)
set(TINYNNET_VERSION 0.1)

add_definitions(-std=c++11)

add_executable(tinynet main.cpp Gate.cpp MultiplyGate.cpp)
