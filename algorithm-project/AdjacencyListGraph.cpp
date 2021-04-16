#include "AdjacencyListGraph.h"

AdjacencyListGraph::AdjacencyListGraph(int n)
{
	MakeEmptyGraph(n);
}

AdjacencyListGraph::~AdjacencyListGraph()
{
	for (int i = 0; i < this->numVertices; ++i)
	{

	}
}

void AdjacencyListGraph::MakeEmptyGraph(int n)
{
	this->adjacencyListArray = new LinkedList[n];
}

void AdjacencyListGraph::addEdge(int u, int v, int weight)
{
	this->adjacencyListArray[u].addNode(v, weight);
}

bool AdjacencyListGraph::isAdjacent(int u, int v)
{
	adjacencyListArray[u].isVertexExist(v);
}

void AdjacencyListGraph::removeEdge(int u, int v)
{
	adjacencyListArray[u].deleteNode(v);
}

LinkedList AdjacencyListGraph::getAdjList(int u)
{
	return adjacencyListArray[u];
}


