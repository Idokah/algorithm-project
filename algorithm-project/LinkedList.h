#pragma once
using namespace std;

struct Node
{
    int vertex;
    float weight;
    Node* next;
};

class LinkedList
{
private:
    Node* head, * tail;
public:
    LinkedList();
    ~LinkedList();
    void operator=(const LinkedList& other);
    void addNode(int edge, float weight);
    Node* getHead();
    void deleteNode(int vertex);
    bool isVertexExist(int vertex);
    void toString();
};