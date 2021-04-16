cmake_minimum_required(VERSION 3.15)
project(algorithm-project)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithm-project
        algorithm-project/AdjacencyMatrixGraph.cpp
        algorithm-project/AdjacencyMatrixGraph.h
        algorithm-project/main.cpp)
