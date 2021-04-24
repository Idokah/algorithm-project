#pragma once
#include "PriorityQueueHeap.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"

static class Dijkstra
{
public:
	static int dijkstraWithHeap(Graph* G, int s ,int t)
	{
		int u;
		Node* v;
		LinkedList* adjList;
		int n = G->getNumOfVertex();
		float *d = new float[n];
		int *p = new int[n];
		init(s, d, p, n);
		PriorityQueueHeap queue(n, d);

		while (!queue.isEmpty())
		{
			u = queue.deleteMin();
			adjList = G->getAdjList(u+1);
			v = adjList->getHead();
			while (v != nullptr)
			{
				if (d[v->vertex-1] == -1 || d[v->vertex-1] > d[u] + v->weight)
				{
					d[v->vertex-1] = d[u] + v->weight;
					p[v->vertex-1] = u;
					queue.decreaseKey(v->vertex-1, d[v->vertex-1]);
				}
				v = v->next;
			}
		}
		return d[t-1];
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