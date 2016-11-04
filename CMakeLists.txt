cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(main)

add_definitions(-std=c++11)

include_directories(include)

set  (project_SOURCES src/ComputationalGraph.cpp
                      src/MultiplyGate.cpp
                      src/AddGate.cpp
                      src/MaxGate.cpp
                      src/UnaryMultiplyGate.cpp
                      src/UnaryAddGate.cpp
                      src/UnaryExponentGate.cpp
                      src/UnaryXInverseGate.cpp
                      src/SigmoidGate.cpp
                      )

# Includes are added to the target for qt creator
set  (project_HEADERS include/ComputationalGraph.h
                      include/Gate.h
                      include/MultiplyGate.h
                      include/AddGate.h
                      include/MaxGate.h
                      include/UnaryMultiplyGate.h
                      include/UnaryAddGate.h
                      include/UnaryExponentGate.h
                      include/UnaryXInverseGate.h
                      include/SigmoidGate.h
                      )

add_executable(main src/main.cpp ${project_SOURCES} ${project_HEADERS})

add_executable(secondgraph src/secondgraph.cpp ${project_SOURCES} ${project_HEADERS})

add_executable(thirdgraph src/thirdgraph.cpp ${project_SOURCES} ${project_HEADERS})
