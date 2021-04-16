#pragma once
#include "LinkedList.h"
using namespace std;

class AdjacencyListGraph
{
private:
	LinkedList** adjacencyListArray;
	int numVertices;
public:
	AdjacencyListGraph(int n);
	~AdjacencyListGraph();
	void MakeEmptyGraph(int n);
	void addEdge(int u, int v, int weight);
	bool isAdjacent(int u, int v);
	void removeEdge(int u, int v);
	LinkedList getAdjList(int u);
};