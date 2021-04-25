#pragma once
#include "PriorityQueueHeap.h"
#include "PriorityQueueArray.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"



template <class T>
void printArr(T* arr, int size)
{
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


static class Dijkstra
{
public:
	static int dijkstraWithHeap(Graph* G, int s ,int t)
	{
		int u,v;
		Edge* vNode;
		LinkedList* adjList;
		int n = G->getNumOfVertex();
		float *d = new float[n];
		int *p = new int[n];
		init(s, d, p, n);
		PriorityQueueHeap queue(n, d);

		while (!queue.isEmpty())
		{
			u = queue.deleteMin();
			//printArr(d, n);
			cout << u << " ";
			adjList = G->getAdjList(u+1);
            vNode = adjList->getHead();
			while (vNode != nullptr)
			{
			    v = vNode->dstVertex - 1;
				if (d[v] == -1 || d[v] > d[u] + vNode->weight)
				{
					d[v] = d[u] + vNode->weight;
					p[v] = u;
					queue.decreaseKey(vNode->dstVertex - 1, d[vNode->dstVertex - 1]);
				}
                vNode = vNode->next;
			}
		}
		int distanceToT = d[t-1];
		delete[] d;
		delete[] p;
		return distanceToT;
	}

	static int dijkstraWithArray(Graph* G, int s, int t)
	{
		int u, v;
		Edge* vNode;
		LinkedList* adjList;
		int n = G->getNumOfVertex();
		float* d = new float[n];
		int* p = new int[n];
		init(s, d, p, n);
		PriorityQueueArray queue(d, n);
		//PriorityQueueHeap queue(n, d);

		while (!queue.isEmpty())
		{
			u = queue.deleteMin();
			//printArr(d,n);
			//cout << u << " ";
			adjList = G->getAdjList(u + 1);
			vNode = adjList->getHead();
			while (vNode != nullptr)
			{
				v = vNode->dstVertex - 1;
				if (d[v] == -1 || d[v] > d[u] + vNode->weight)
				{
					d[v] = d[u] + vNode->weight;
					p[v] = u;
					queue.decreaseKey(vNode->dstVertex - 1, d[vNode->dstVertex - 1]);
				}
				vNode = vNode->next;
			}
		}
		int distanceToT = d[t - 1];
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

