#include "AdjacencyListGraph.h"

AdjacencyListGraph::AdjacencyListGraph(int n) : Graph(n)
{
	MakeEmptyGraph();
}

AdjacencyListGraph::~AdjacencyListGraph()
{
	for (int i = 0; i < this->n; ++i)
		delete (this->adjacencyListArray[i]);
	delete[] this->adjacencyListArray;
}

void AdjacencyListGraph::MakeEmptyGraph()
{
	// TODO - maybe check if already allocated and free if so 
	this->adjacencyListArray = new LinkedList* [this->n];
	for (int i = 0; i < this->n; ++i)
	{
		this->adjacencyListArray[i] = new LinkedList();
	}
}

void AdjacencyListGraph::addEdge(int u, int v, float weight)
{
    this->adjacencyListArray[u - 1]->addNode(weight, v, u);
}

bool AdjacencyListGraph::isAdjacent(int u, int v)
{
	return adjacencyListArray[u-1]->isVertexExist(v);
}

void AdjacencyListGraph::removeEdge(int u, int v)
{
	adjacencyListArray[u-1]->deleteNode(v);
}

LinkedList* AdjacencyListGraph::getAdjList(int u)
{
    LinkedList *adjLst = new LinkedList(adjacencyListArray[u-1]);
    return adjLst;
}

void AdjacencyListGraph::load(istream& in)
{
	string line;
	int i, j;
	float weight;
	while (in >> i >> j >> weight)
	{
        if (weight < 0 || isAdjacent(i,j)){
            throw invalid_argument("One of the edges in the file is invalid");
        }
        this->addEdge(i, j, weight);
	}
}

void AdjacencyListGraph::toString()
{
	for (int i = 0; i < this->n; ++i)
	{
		cout << i + 1 << " :";
		this->adjacencyListArray[i]->toString();
		cout << endl;
	}
}