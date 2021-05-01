#pragma once
#include "PriorityQueueHeap.h"
#include "PriorityQueueArray.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"



static class Dijkstra
{
public:
	static float dijkstraWithHeap(Graph* G, int s, int t);
	static float dijkstraWithArray(Graph* G, int s, int t);
private:
	static void init(int s, float* d, int* p, int n);
    static bool isImprovingEdge(int u, int v, float weight, float* d);
};

//TODO- delete when finish
template <class T>
void printArr(T* arr, int size)
{
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
