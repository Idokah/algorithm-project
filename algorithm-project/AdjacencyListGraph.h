#pragma once
#include <fstream>
#include <iostream>
#include "LinkedList.h"
#include "Graph.h"
#include "ValidateVertex.h"

using namespace std;

class AdjacencyListGraph : public Graph
{
private:
	LinkedList** adjacencyListArray;
public:
	explicit AdjacencyListGraph(int n);
	~AdjacencyListGraph();
	void addEdge(int u, int v, float weight) override;
	bool isAdjacent(int u, int v) override;
	void removeEdge(int u, int v) override;
    LinkedList* getAdjList(int u) override;
	void load(istream& in) override;
	const string getType() override;
	void toString() override;
    void makeEmptyGraph();
};