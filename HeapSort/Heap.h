#pragma once
#include <vector>;
#include <string>;
#include <iostream>;


class Heap
{
public:
	Heap();
	Heap(std::vector<int> &seed);

	void insert(int input);
	void remove(int index);
	void changePriority(int index, int newValue);

	void siftDown(int child);
	void siftDown(int child, int maxIndex);
	void siftUp(int child);

	int extractMax();
	int getMax();
	int size();

	int& operator[] (int x) {
		return this->heap->at(x);
	}

private:
	int calculateParent(int index);
	int calculateLeftChild(int index);
	int calculateRightChild(int index);

	std::vector<int> * heap;
	int maxIndex;

};

