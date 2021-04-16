#ifndef ALGORITHM_PROJECT_PRIORITYQUEUEHEAP_H
#define ALGORITHM_PROJECT_PRIORITYQUEUEHEAP_H

#include <iostream>

using namespace std;

struct VertexItem {
    int vertex;
    int distance;
};

class PriorityQueueHeap {
private:
    VertexItem **data;
    int maxSize;
    int heapSize;
    int allocated;
    int left(int node);
    int right(int node);
    int parent(int node);
    void fixHeap(int node);
    void swap(int item1, int item2);
public:
    PriorityQueueHeap(int max);
    PriorityQueueHeap(VertexItem** arr, int n);
    void build(int n);
    ~PriorityQueueHeap();
    VertexItem *min();
    VertexItem *deleteMin();
    void insert(VertexItem *item);
    bool isEmpty();
    void makeEmpty();
    int getHeapSize();
    void decreaseKey(int place, int newKey);
};

#endif //ALGORITHM_PROJECT_PRIORITYQUEUEHEAP_H
