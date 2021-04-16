#include "AdjacencyMatrixGraph.h"

int NO_EDGE = -1; // We are assuming all the weight in the graph is not negative


// Initialize the matrix to zero
AdjacencyMatrixGraph::AdjacencyMatrixGraph(int numVertices)
{
    makeEmptyGraph(numVertices);
}

void AdjacencyMatrixGraph::makeEmptyGraph(int numVertices)
{
    this->numVertices = numVertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = NO_EDGE;
    }
}

bool AdjacencyMatrixGraph::isAdjacent(int u, int v)
{
    return (adjMatrix[u][v] != NO_EDGE);
}

// Read edges from file
void AdjacencyMatrixGraph::load(istream& in)
{
    string line;
    int i, j, weight;
    while (!in.eof( ))
    {
        in >> i >> j >> weight;
        addEdge(i, j, weight);
    }
}

// Add edges
void AdjacencyMatrixGraph::addEdge(int i, int j, int c)
{
    adjMatrix[i][j] = c;
}

// Remove edges
void AdjacencyMatrixGraph::removeEdge(int i, int j)
{
    adjMatrix[i][j] = NO_EDGE;
}

// Print the martix
void AdjacencyMatrixGraph::toString()
{
    for (int i = 0; i < numVertices; i++)
    {
        cout << i << " : ";
        for (int j = 0; j < numVertices; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

LinkedList AdjacencyMatrixGraph::getAdjList(int u)
{
    LinkedList lst;
    for (int i = 0; i < numVertices; i++) {
        if (isAdjacent(u, i))
            lst.addNode(i, adjMatrix[u][i]);
    }
    return lst;
}

AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
{
    for (int i = 0; i < numVertices; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}
