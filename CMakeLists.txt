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
        algorithm-project/Dijkstra.h
        algorithm-project/Dijkstra.cpp
        algorithm-project/Graph.cpp
        algorithm-project/Graph.h
        algorithm-project/main.cpp
        algorithm-project/PriorityQueueHeap.cpp
        algorithm-project/PriorityQueueHeap.h
        algorithm-project/PriorityQueueArray.cpp
        algorithm-project/PriorityQueueArray.h
        algorithm-project/BellmanFord.h
        algorithm-project/BellmanFord.cpp
        algorithm-project/validate_vertex.cpp
        algorithm-project/validate_vertex.h)
