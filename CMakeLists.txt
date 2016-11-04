cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(main)

add_definitions(-std=c++11)

set  (project_SOURCES main.cpp MultiplyGate.cpp AddGate.cpp ComputationalGraph.cpp)
set  (project_HEADERS Gate.h MultiplyGate.h AddGate.h ComputationalGraph.h)

add_executable(main ${project_SOURCES} ${project_HEADERS})
