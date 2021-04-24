#include "AdjacencyMatrixGraph.h"

int NO_EDGE = -1; // We are assuming all the weight in the graph is not negative


// Initialize the matrix to zero
AdjacencyMatrixGraph::AdjacencyMatrixGraph(int n) : Graph(n)
{
    adjMatrix = new int* [this->n];
    for (int i = 0; i < this->n; i++)
        adjMatrix[i] = new int[this->n];
    makeEmptyGraph();
}

void AdjacencyMatrixGraph::makeEmptyGraph()
{
    for (int i = 0; i < this->n; i++)
        for (int j = 0; j < this->n; j++)
            adjMatrix[i][j] = NO_EDGE;
}

bool AdjacencyMatrixGraph::isAdjacent(int u, int v)
{
    return (this->adjMatrix[u-1][v-1] != NO_EDGE);
}

// Read edges from file
// validate no negative and negative edges
void AdjacencyMatrixGraph::load(istream& in)
{
    string line;
    int i, j, weight;
    while (!in.eof( ))
    {
         in >> i >> j >> weight;
        if (weight < 0 || isAdjacent(i,j))
        {
            throw invalid_argument("One of the edges in the file is invalid");
        }
        this->addEdge(i, j, weight);
    }
}

// Add edges
void AdjacencyMatrixGraph::addEdge(int u, int v, float weight)
{
    adjMatrix[u-1][v-1] = weight;
}

// Remove edges
void AdjacencyMatrixGraph::removeEdge(int i, int j)
{
    adjMatrix[i-1][j-1] = NO_EDGE;
}

// Print the martix
void AdjacencyMatrixGraph::toString()
{
    for (int i = 0; i < this->n; i++)
    {
        cout << i + 1 << " : ";
        for (int j = 0; j < this->n; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

LinkedList* AdjacencyMatrixGraph::getAdjList(int u)
{
    LinkedList* lst = new LinkedList;
    for (int i = 1; i <= this->n; i++) {
        if (this->isAdjacent(u, i))
            lst->addNode(i, adjMatrix[u-1][i-1]);
    }
    return lst;
}

AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
{
    for (int i = 0; i < this->n; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}
