#include "Graph.h"

Graph::Graph(int n) :n(n) {}

int Graph::getNumOfVertex()
{
	return this->n;
}

LinkedList *Graph::getAllEdges() {
    LinkedList* allEdgesList = new LinkedList;
    LinkedList* currLst;
    for (int i = 1; i <= this->n; i++) {
        currLst = getAdjList(i);
        if (allEdgesList->isEmpty()) allEdgesList = currLst;
        else if (!currLst->isEmpty()){
            allEdgesList->addNode(currLst->getHead());
            allEdgesList->setTail(currLst->getTail());
        }
    }
    return allEdgesList;
}

