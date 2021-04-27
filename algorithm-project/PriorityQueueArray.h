#pragma once

class PriorityQueueArray
{
private:
	float* arr;
	int* flagsArr; 
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