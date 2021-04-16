#include "AdjacencyListGraph.h"

AdjacencyListGraph::AdjacencyListGraph(int n) : numVertices(n)
{
	MakeEmptyGraph(n);
}

AdjacencyListGraph::~AdjacencyListGraph()
{
	for (int i = 0; i < this->numVertices; ++i)
	{
		delete (this->adjacencyListArray[i]);
	}
}

void AdjacencyListGraph::MakeEmptyGraph(int n)
{
	this->adjacencyListArray = new LinkedList* [n];
	for (int i = 0; i < i < n; ++i)
	{
		this->adjacencyListArray[i] = new LinkedList;
	}
}

void AdjacencyListGraph::addEdge(int u, int v, int weight)
{
	this->adjacencyListArray[u]->addNode(v, weight);
}

bool AdjacencyListGraph::isAdjacent(int u, int v)
{
	return adjacencyListArray[u]->isVertexExist(v);
}

void AdjacencyListGraph::removeEdge(int u, int v)
{
	adjacencyListArray[u]->deleteNode(v);
}

LinkedList AdjacencyListGraph::getAdjList(int u)
{
	return *adjacencyListArray[u];
}


