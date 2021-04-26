#include "PriorityQueueHeap.h"

bool isInfinity(float distance) { return (distance == -1); };

bool isNodeBigger(float nodeDistance, float otherDistance)
{
    if (isInfinity(otherDistance)) return false;
    // The other is not infinity
    if (isInfinity(nodeDistance)) return true;
    // The other and me are not infinity
    return (otherDistance < nodeDistance);
}


PriorityQueueHeap::PriorityQueueHeap(int n, float* d)
{
    this->data = new VertexItem *[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new VertexItem;
        data[i]->distance = d[i];
        data[i]->vertex = i;
    }
    this->heapSize = n;
    this->build();
}

void PriorityQueueHeap::build() {
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        this->fixHeap(i);
}

PriorityQueueHeap::~PriorityQueueHeap() {
    for (int i = 0; i < this->heapSize; ++i)
        delete data[i];
    delete[] this->data;
}

int PriorityQueueHeap::left(int node) {
    return (2*node+1);
}

int PriorityQueueHeap::right(int node) {
    return (2*node+2);
}

int PriorityQueueHeap::parent(int node) {
    return (node-1)/2;
}

int PriorityQueueHeap::getHeapSize() {
    return this->heapSize;
}

void PriorityQueueHeap::fixHeap(int node) {
    int min;
    int left = this->left(node);
    int right = this->right(node); 
    if ((left < heapSize) && isNodeBigger(this->data[node]->distance,this->data[left]->distance))
        min = left;
    else min = node;
    if ((right < heapSize) && isNodeBigger(this->data[node]->distance, this->data[right]->distance))
        min = right;
    if (min != node){
        this->swap(node, min);
        this->fixHeap(min);
    }
}

void PriorityQueueHeap::swap(int item1, int item2) {
    VertexItem* temp = this->data[item2];
    this->data[item2] =  this->data[item1];
    this->data[item1] = temp;
}

int PriorityQueueHeap::deleteMin() {
    if (heapSize < 1) {
        cout << "there is no node to delete";
        exit(1);
    }
    VertexItem* min = data[0];
    int minVertex = min->vertex;
    //delete min; // TODO check if needed
    heapSize--;
    data[0] = data[heapSize];
    this->fixHeap(0);
    return minVertex;
}

VertexItem* PriorityQueueHeap::min() {
    return this->data[0];
}

void PriorityQueueHeap::insert(VertexItem* item) {
    if (heapSize + 1 == maxSize) {
        cout << "error";
        exit(1);
    }
    int i = this->heapSize;
    this->heapSize++;
    while ((i > 0) && (this->data[parent(i)]->distance > item->distance)) {
        this->data[i] = this->data[parent(i)];
        i = parent(i);
    }
    data[i] = item;
}

bool PriorityQueueHeap::isEmpty()
{
    return (this->heapSize == 0);
}

void PriorityQueueHeap::makeEmpty() {
    this->heapSize = 0;
}


void PriorityQueueHeap::decreaseKey(int place, int newKey){
    int index = place;
    this->data[place]->distance = newKey;
    while ((index > 0) && isNodeBigger(this->data[parent(index)]->distance,this->data[index]->distance))
    {
        this->swap(parent(index), index);
        index = parent(index);
    }
}
