#pragma once

class PriorityQueueArray
{
private:
	int* arr;
	int size;
	int minIndex;
	int updateMinIndex();
public:
	PriorityQueueArray(int* arr,int n);
	void Build(int* arr);
	int deleteMin();
	bool isEmpty();
	void decreaseKey(int place, int newKey);
	int getSize();
};