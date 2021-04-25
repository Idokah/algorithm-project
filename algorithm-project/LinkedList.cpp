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
    Edge* curr = head;
    while (curr) {
        Edge* next = curr->next;
        delete curr;
        curr = next;
    }
}

void LinkedList::operator=(const LinkedList& other)
{
    this->head = other.head;
    this->tail = other.tail;
}

void LinkedList::addNode(float weight, int dstVertex, int srcVertex)
{
    Edge* newNode = new Edge;
    newNode->weight = weight;
    newNode->dstVertex = dstVertex;
    newNode->srcVertex = srcVertex;
    newNode->next = nullptr;
    this->addNode(newNode);
}

void LinkedList::addNode(Edge *newNode) {
    if (this->head == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->next = newNode;
        this->tail = tail->next;
    }
}

Edge* LinkedList::getHead()
{
    return this->head;
}
void LinkedList::deleteNode(int dstVertex)
{

    Edge* temp = this->head;
    Edge* prev = nullptr;

    // If head node itself holds the edge to be deleted
    if (temp != nullptr && temp->dstVertex == dstVertex)
    {
        this->head = temp->next; // Changed head
        delete temp;        // free old head
        return;
    }

    // Else Search for the edge to be deleted,
    else
    {
        while (temp != nullptr && temp->dstVertex != dstVertex)
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
bool LinkedList::isVertexExist(int dstVertex)
{
    Edge* temp = this->head;
    while (temp != nullptr && temp->dstVertex != dstVertex)
    {
        temp = temp->next;
    }
    return (temp ? true : false);
}

void LinkedList::toString()
{
    Edge* curr = this->head;
    while (curr != nullptr)
    {
        cout << curr->dstVertex << "(" << curr->weight << ")  ";
        curr = curr->next;
    }
}

bool LinkedList::isEmpty() {
    return (this->getHead() == nullptr);
}

Edge *LinkedList::getTail() {
    return this->tail;
}

void LinkedList::setTail(Edge* newTail) {
    this->tail = newTail;
}
