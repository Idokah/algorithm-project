#include "LinkedList.h"
#include <iostream>
#include <string>
#include "ValidateVertex.h"

#pragma once
class Graph
{
private:
public:
	int getNumOfVertex();
	virtual void addEdge(int u, int v, float weight) = 0 ;
	virtual bool isAdjacent(int u, int v) = 0;
	virtual void removeEdge(int u, int v) = 0;
	virtual LinkedList* getAdjList(int u) = 0;
	virtual void load(istream& in) = 0;
	virtual void toString() = 0;
	virtual LinkedList* getAllEdges();
	virtual const string getType() = 0;
protected:
	Graph(int n);
	int n;
};