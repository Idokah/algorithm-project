#pragma once
#include "PriorityQueueHeap.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"

static class BellmanFord
{
public:
	static int bellmanFord(Graph* G, int s ,int t) {
        int u, v;
        Edge *edge;
        LinkedList *adjList = G->getAllEdges();
        int n = G->getNumOfVertex();
        float *d = new float[n];
        int *p = new int[n];
        init(s, d, p, n);
        for (int i = 0; i < n - 1; ++i) {
            edge = adjList->getHead();
            while (edge != nullptr) {
                v = edge->dstVertex - 1;
                u = edge->srcVertex - 1;
                if (isImprovingEdge(u, v, edge->weight, d)) {
                    d[v] = d[u] + edge->weight;
                    p[v] = u;
                }
                edge = edge->next;
            }
        }

        edge = adjList->getHead();
        while (edge != nullptr)
        {
            v = edge->dstVertex - 1;
            u = edge->srcVertex - 1;
            if (isImprovingEdge(u, v, edge->weight, d))
                throw invalid_argument("Negative Cycle");
            edge = edge->next;
        }

        int distanceToT = d[t-1];
        delete[] d;
        delete[] p;
        delete adjList;
        return distanceToT;
	}
private:
    static bool isImprovingEdge(int u, int v, float weight, float* d){
	    return (d[v] == -1 || (d[v] > d[u] + weight));
	}
	static void init(int s, float* d, int* p, int n) 
	{
		for (int i = 0; i < n; ++i) 
		{
			d[i] = -1;
			p[i] = -1;
		}
		d[s-1] = 0;
	}
};