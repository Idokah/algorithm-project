#pragma once

#include <iostream>
#include "LinkedList.h"
#include "Graph.h"
#include <fstream>

using namespace std;

class AdjacencyMatrixGraph : public Graph
{
private:
    float** adjMatrix;
public:
    explicit AdjacencyMatrixGraph(int n);
    bool isAdjacent(int u, int v) override;
    void makeEmptyGraph();
    void load(istream& in) override;
    void addEdge(int u, int v, float weight) override;
    void removeEdge(int i, int j) override;
    void toString() override;
    LinkedList* getAdjList(int u) override;
    const string getType() override;
    ~AdjacencyMatrixGraph();
    bool loadEdge(istream &in, int &i, int &j, float &weight);
};
