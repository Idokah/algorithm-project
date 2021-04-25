#pragma once

class PriorityQueueArray
{
private:
	float* arr;
	int* flagsArr; //flagsArr[i] is 1 if arr[1] is in the queue
	int deleted;
	int size;
	int minIndex;
	void updateMinIndex();
public:
	PriorityQueueArray(float * arr,int n);
	~PriorityQueueArray();
	void Build(float * arr);
	int deleteMin();
	bool isEmpty();
	void decreaseKey(int place, float newKey);
	int getSize();
	
};