#ifndef ALGORITHM_PROJECT_ADJACENCYMATRIXGRAPH_H
#define ALGORITHM_PROJECT_ADJACENCYMATRIXGRAPH_H

#include <iostream>
#include "LinkedList.h"
#include <fstream>

using namespace std;

class AdjacencyMatrixGraph
{
private:
    int** adjMatrix;
    int numVertices;

public:
    AdjacencyMatrixGraph(int numVertices);
    void makeEmptyGraph(int numVertices);
    bool isAdjacent(int u, int v);
    void load(istream& in);
    void addEdge(int i, int j, int c);
    void removeEdge(int i, int j);
    void toString();
    LinkedList getAdjList(int u);
    ~AdjacencyMatrixGraph();
};

#endif //ALGORITHM_PROJECT_ADJACENCYMATRIXGRAPH_H
