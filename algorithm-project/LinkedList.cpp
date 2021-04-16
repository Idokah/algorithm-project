#include <iostream>
#include "LinkedList.h"

using namespace std;


LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList()
{
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}

void LinkedList::addNode(int vertex,int weight)
{
    Node* tmp = new Node;
    tmp->weight = weight;
    tmp->vertex = vertex;
    tmp->next = nullptr;

    if (head == nullptr)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}
void LinkedList::deleteNode(int vertex)
{

    Node* temp = this->head;
    Node* prev = nullptr;

    // If head node itself holds the edge to be deleted
    if (temp != nullptr && temp->vertex == vertex)
    {
        this->head = temp->next; // Changed head
        delete temp;        // free old head
        return;
    }

    // Else Search for the edge to be deleted,
    else
    {
        while (temp != nullptr && temp->vertex != vertex)
        {
            prev = temp;
            temp = temp->next;
        }

        // edge not found
        if (temp == nullptr)
            return;

        prev->next = temp->next;
        delete temp;
    }
}
bool LinkedList::isVertexExist(int vertex)
{
    Node* temp = this->head;
    while (temp != nullptr && temp->vertex != vertex)
    {
        temp = temp->next;
    }
    return (temp ? true : false);
}
