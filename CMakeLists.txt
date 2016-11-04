cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(main)

add_definitions(-std=c++11)

set  (project_SOURCES ComputationalGraph.cpp
                      MultiplyGate.cpp
                      AddGate.cpp
                      MaxGate.cpp
                      UnaryMultiplyGate.cpp
                      )

set  (project_HEADERS ComputationalGraph.h
                      Gate.h
                      MultiplyGate.h
                      AddGate.h
                      MaxGate.h
                      UnaryMultiplyGate.h
                      )

add_executable(main main.cpp ${project_SOURCES} ${project_HEADERS})

add_executable(secondgraph secondgraph.cpp ${project_SOURCES} ${project_HEADERS})
