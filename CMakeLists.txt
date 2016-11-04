cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(tinynet)
set(TINYNNET_VERSION 0.1)

add_definitions(-std=c++11)

set  (project_SOURCES main.cpp MultiplyGate.cpp AddGate.cpp)
set  (project_HEADERS Gate.h MultiplyGate.h AddGate.h)

add_executable(tinynet ${project_SOURCES} ${project_HEADERS})
