#include "Dijkstra.h"
#define INFINITY -1
float Dijkstra::dijkstraWithHeap(Graph* G, int s, int t)
{
	int u, v;
	Edge* vNode;
	LinkedList* adjList;
	int n = G->getNumOfVertex();
	float* d = new float[n];
	int* p = new int[n];
	init(s, d, p, n);
	PriorityQueueHeap queue(n, d);

	while (!queue.isEmpty())
	{
		u = queue.deleteMin();
        // if d[u] is (infinity) its mean that all the rest of the vertices are infinity.
        // so they cant improve anyone.
		if (d[u] == INFINITY) break;
		adjList = G->getAdjList(u + 1);
		vNode = adjList->getHead();
		while (vNode != nullptr)
		{
			v = vNode->dstVertex - 1;
			if (isImprovingEdge(u, v, vNode->weight, d))
			{
				d[v] = d[u] + vNode->weight;
				p[v] = u;
				queue.decreaseKey(vNode->dstVertex - 1, d[vNode->dstVertex - 1]);
			}
			vNode = vNode->next;
		}
		delete adjList;
	}
	float distanceToT = d[t - 1];
	delete[] d;
	delete[] p;
	return distanceToT;
}

float Dijkstra::dijkstraWithArray(Graph* G, int s, int t)
{
	int u, v;
	Edge* vNode;
	LinkedList* adjList;
	int n = G->getNumOfVertex();
	float* d = new float[n];
	int* p = new int[n];
	init(s, d, p, n);
	PriorityQueueArray queue(d, n);

	while (!queue.isEmpty())
	{
		u = queue.deleteMin();
		adjList = G->getAdjList(u + 1);
		vNode = adjList->getHead();
		while (vNode != nullptr)
		{
			v = vNode->dstVertex - 1;
			if (isImprovingEdge(u, v, vNode->weight, d))
                {
				d[v] = d[u] + vNode->weight;
				p[v] = u;
				queue.decreaseKey(vNode->dstVertex - 1, d[vNode->dstVertex - 1]);
			}
			vNode = vNode->next;
		}
		delete adjList;
	}
	float distanceToT = d[t - 1];
	delete[] d;
	delete[] p;
	return distanceToT;
}

void Dijkstra::init(int s, float* d, int* p, int n)
{
	for (int i = 0; i < n; ++i)
	{
		d[i] = -1;
		p[i] = -1;
	}
	d[s - 1] = 0;
}

bool Dijkstra::isImprovingEdge(int u, int v, float weight, float* d)
{
    return ((d[v] == INFINITY && d[u] != INFINITY) || (d[u] != INFINITY && d[v] > d[u] + weight));
}