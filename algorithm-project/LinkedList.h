#pragma once
using namespace std;

struct Edge
{
    int srcVertex;
    int dstVertex;
    float weight;
    Edge* next;
};

class LinkedList
{
private:
    Edge* head, *tail;
public:
    LinkedList();
    ~LinkedList();
    void operator=(const LinkedList& other);
    void addNode(float weight, int dstVertex, int srcVertex);
    void addNode(Edge *newNode);
    bool isEmpty();
    Edge* getHead();
    Edge* getTail();
    void deleteNode(int vertex);
    bool isVertexExist(int vertex);
    void toString();
    void setTail(Edge* newTail);
};