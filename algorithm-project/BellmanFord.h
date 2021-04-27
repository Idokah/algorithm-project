#pragma once
#include "PriorityQueueHeap.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"

static class BellmanFord
{
public:
	static float bellmanFord(Graph* G, int s, int t);
private:
	static bool isImprovingEdge(int u, int v, float weight, float* d);
	static void init(int s, float* d, int* p, int n);
	
};