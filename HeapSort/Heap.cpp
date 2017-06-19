#include "Heap.h";
#include <vector>;
#include <limits>;
#include <string>;



Heap::Heap() {}


Heap::Heap(std::vector<int> &seed)
{
	this->heap = &seed;
	for (int i = calculateParent(size() - 1) ; i >= 0; i--) {
		siftDown(i);
	}
}


void Heap::insert(int input) {
	this->heap->push_back(input);
	int index = size() -1;
	siftUp(index);
}


void Heap::remove(int index) {
	int max = std::numeric_limits<int>::max();
	this->heap->at(index) = max;
	siftUp(index);
	extractMax();
}


int Heap::getMax() {
	return this->heap->at(0);
}


int Heap::extractMax() {
	int temp = this->heap->at(0);
	this->heap->at(0) = this->heap->at(size() -1);
	this->heap->pop_back();
	siftDown(0);
	return temp;
}


void Heap::changePriority(int index, int newValue) {
	this->heap->at(index) = newValue;
	siftDown(index);
	siftUp(index);
}


int Heap::size() {
	return this->heap->size();
}


void Heap::siftUp(int index) {
	if (index == 0 || size() == 0 || index > size()) return;

	int temp = this->heap->at(index);
	while (this->heap[calculateParent(index)] < this->heap[index]) {
		this->heap[index] = this->heap[calculateParent(index)];
		this->heap->at(calculateParent(index)) = temp;
		index = calculateParent(index);
	}
}


void Heap::siftDown(int index) {
	if (size() == 0 || index > size()) return;

	int temp = this->heap->at(index);
	int leftChild = calculateLeftChild(index);
	int rightChild = calculateRightChild(index);

	while (leftChild < size()) {
		if (rightChild < size() && this->heap->at(rightChild) > this->heap->at(leftChild) && 
			this->heap->at(rightChild) > temp) {

			this->heap->at(index) = this->heap->at(rightChild);
			this->heap->at(rightChild) = temp;
			index = rightChild;
		}
		else if (this->heap->at(leftChild) > temp){
			this->heap->at(index) = this->heap->at(leftChild);
			this->heap->at(leftChild) = temp;
			index = leftChild;
		}
		else {
			break;
		}

		leftChild = calculateLeftChild(index);
		rightChild = calculateRightChild(index);
	}
}


void Heap::siftDown(int index, int maxIndex) {
	if (maxIndex == 0 || index > maxIndex || maxIndex > size() -1) return;

	int temp = this->heap->at(index);
	int leftChild = calculateLeftChild(index);
	int rightChild = calculateRightChild(index);

	while (leftChild < maxIndex) {
		if (rightChild < maxIndex && this->heap->at(rightChild) > this->heap->at(leftChild) &&
			this->heap->at(rightChild) > temp) {

			this->heap->at(index) = this->heap->at(rightChild);
			this->heap->at(rightChild) = temp;
			index = rightChild;
		}
		else if (this->heap->at(leftChild) > temp) {
			this->heap->at(index) = this->heap->at(leftChild);
			this->heap->at(leftChild) = temp;
			index = leftChild;
		}
		else {
			break;
		}

		leftChild = calculateLeftChild(index);
		rightChild = calculateRightChild(index);
	}
}

int Heap::calculateParent(int index) {
	return index == 0 ? 0 : (int)((index + 1) / 2) - 1; // Since our array is 0-based, handle it like 1-based then convert it. Parent = Lower(index/2)
}


int Heap::calculateLeftChild(int index) {
	return ((index + 1) * 2) - 1; // 2i for 1-based index.
}


int Heap::calculateRightChild(int index) {
	return ((index + 1) * 2); // 2i + 1 for 1-based index.
}
