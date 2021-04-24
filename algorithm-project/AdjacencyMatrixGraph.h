#pragma once

#include <iostream>
#include "LinkedList.h"
#include "Graph.h"
#include <fstream>

using namespace std;

class AdjacencyMatrixGraph : public Graph
{
private:
    int** adjMatrix;
public:
    AdjacencyMatrixGraph(int n);
    bool isAdjacent(int u, int v);
    void makeEmptyGraph();
    void load(istream& in);
    void addEdge(int u, int v, float weight);
    void removeEdge(int i, int j);
    void toString();
    LinkedList* getAdjList(int u);
    ~AdjacencyMatrixGraph();
};
