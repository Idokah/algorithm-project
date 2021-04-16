#include "AdjacencyMatrixGraph.h"
#include <fstream>

int NO_EDGE = -1; // We are assumming all the weight in the graph is not negative

class AdjacencyMatrixGraph 
{
private:
    int** adjMatrix;
    int numVertices;

public:
    // Initialize the matrix to zero
    AdjacencyMatrixGraph(int numVertices) 
    {
        makeEmptyGraph(numVertices);
    }

    void makeEmptyGraph(int numVertices)
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

    bool isAdjacent(int u, int v)
    {
        return (adjMatrix[u][v] != NO_EDGE);
    }


    void load(istream& in) 
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
    void addEdge(int i, int j, int c) 
    {
        adjMatrix[i][j] = c;
    }

    // Remove edges
    void removeEdge(int i, int j) 
    {
        adjMatrix[i][j] = NO_EDGE;
    }

    // Print the martix
    void toString() 
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    ~AdjacencyMatrixGraph() 
    {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};