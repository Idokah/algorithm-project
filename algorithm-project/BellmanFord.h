#pragma once
#include "PriorityQueueHeap.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"

static class BellmanFord
{
public:
	static int bellmanFord(Graph* G, int s ,int t)
	{
        int u, v;
        Edge* vNode;
        LinkedList* adjList;
        int n = G->getNumOfVertex();
        float *d = new float[n];
        int *p = new int[n];
        init(s, d, p, n);
        for (int i = 0; i < n - 1; ++i)
        {
            // running over all the edges
            for (int u = 0; u < n ; ++i) {
                adjList = G->getAdjList(u);
                vNode = adjList->getHead();
                while (vNode != nullptr)
                {
                    v = vNode->dstVertex - 1;
                    if (d[v] == -1 || (d[v] > d[u] + vNode->weight))
                    {
                        d[v] = d[u] + vNode->weight;
                        p[v] = u;
                    }
                    vNode = vNode->next;
                }
            }
        }


        int distanceToT = d[t-1];
        delete[] d;
        delete[] p;
        return distanceToT;
	}
private:
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