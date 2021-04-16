#pragma once
using namespace std;

struct Node
{
    int vertex;
    int weight;
    Node* next;
};

class LinkedList
{
private:
    Node* head, * tail;
public:
    LinkedList();
    void addNode(int edge, int weight);
    void deleteNode(int vertex);
    bool isVertexExist(int vertex);
};