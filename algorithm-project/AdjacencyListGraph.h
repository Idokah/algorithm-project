#pragma once
#include <fstream>
#include <iostream>
#include "LinkedList.h"
#include "Graph.h"
using namespace std;

class AdjacencyListGraph : public Graph
{
private:
	LinkedList** adjacencyListArray;
	void MakeEmptyGraph();
public:
	AdjacencyListGraph(int n);
	~AdjacencyListGraph();
	void addEdge(int u, int v, float weight);
	bool isAdjacent(int u, int v);
	void removeEdge(int u, int v);
	LinkedList* getAdjList(int u);
	void load(istream& in);
	void toString();
};