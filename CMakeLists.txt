cmake_minimum_required(VERSION 3.15)
project(algorithm-project)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithm-project
        algorithm-project/LinkedList.cpp
        algorithm-project/LinkedList.h
        algorithm-project/AdjacencyListGraph.cpp
        algorithm-project/AdjacencyListGraph.h
        algorithm-project/AdjacencyMatrixGraph.cpp
        algorithm-project/AdjacencyMatrixGraph.h
        algorithm-project/main.cpp)
