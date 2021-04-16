#include "PriorityQueueArray.h"

int PriorityQueueArray::updateMinIndex()
{
	bool firstFound = false;
	this->minIndex = 0;
	for (int i = 0; i < this->size; ++i)
	{
		if ((this->arr[i] != -1) && (!firstFound || arr[this->minIndex] > this->arr[i]))
		{
			firstFound = true;
			this->minIndex = i;
		}
	}
}

PriorityQueueArray::PriorityQueueArray(int* arr,int n) : size(n)
{
	Build(arr);
}

void PriorityQueueArray::Build(int* arr)
{
	this->arr = arr;
	this->updateMinIndex();
}

int PriorityQueueArray::deleteMin()
{
	int min= arr[this->minIndex];
	arr[this->minIndex] = -1;
	this->updateMinIndex();
	return min;
}

bool PriorityQueueArray::isEmpty()
{
	for (int i = 0; this->size; ++i)
	{
		if (this->arr[i] != -1) return false;
	}
	return true;
}

void PriorityQueueArray::decreaseKey(int place, int newKey)
{
	this->arr[place] = newKey;
	if (place == this->minIndex) updateMinIndex();
}

int PriorityQueueArray::getSize()
{
	return size;
}
