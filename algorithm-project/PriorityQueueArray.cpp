#include "PriorityQueueArray.h"


void PriorityQueueArray::updateMinIndex()
{
	bool firstFound = false;
	for (int i = 0; i < this->size; ++i)
	{
			if (this->flagsArr[i]) //is in the array
			{
				if ((this->arr[i] != -1) && (!firstFound || arr[this->minIndex] > this->arr[i]))
				{
					firstFound = true;
					this->minIndex = i;
				}
			}
	}
}

PriorityQueueArray::PriorityQueueArray(float * arr,int n) : size(n) , deleted(0)
{
	this->flagsArr = new int[n];
	for (int i = 0; i < this->size; ++i) this->flagsArr[i] = 1;
	Build(arr);
}

PriorityQueueArray::~PriorityQueueArray() {
	delete[] this->flagsArr;
}

void PriorityQueueArray::Build(float * arr)
{
	this->arr = arr;
	this->updateMinIndex();
}

int PriorityQueueArray::deleteMin()
{
	int minIndex= this->minIndex;
	this->flagsArr[this->minIndex] = 0; //delete the min 
	this->deleted++;
	this->updateMinIndex(); //update the new one (why this is intersting at all??)
	return minIndex;
}

bool PriorityQueueArray::isEmpty()
{
	return this->deleted == size;
	/*for (int i = 0; this->size; ++i)
	{
		if (this->arr[i] != -1) return false;
	}
	return true;*/
}

void PriorityQueueArray::decreaseKey(int place, float newKey)
{
	this->arr[place] = newKey;
	updateMinIndex();
}

int PriorityQueueArray::getSize()
{
	return size;
}
