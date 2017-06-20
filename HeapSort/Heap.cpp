#include "Heap.h";
#include <vector>;
#include <limits>;
#include <string>;



Heap::Heap() {}


Heap::Heap(std::vector<int> &seed)
{
	// Build heap from an array.
	this->heap = &seed;
	for (int i = calculateParent(size() - 1) ; i >= 0; i--) {
		// Begin from parent of the last leaf.
		siftDown(i);
	}
}


void Heap::insert(int input) {
	// Push element to the back of the vector to preserve completeness of the tree.
	this->heap->push_back(input);
	int index = size() -1;
	siftUp(index);
}


void Heap::remove(int index) {
	// Set item to be removed to max then extract it from the tree.
	int max = std::numeric_limits<int>::max();
	this->heap->at(index) = max;
	siftUp(index);
	extractMax();
}


int Heap::getMax() {
	// Since this is a Binary-Max heap first element will always be the max.
	return this->heap->at(0);
}


int Heap::extractMax() {
	// Swap last leaf with the first and pop the last item(max). Then sift down the first item.
	int temp = this->heap->at(0);
	this->heap->at(0) = this->heap->at(size() -1);
	this->heap->pop_back();
	siftDown(0);
	return temp;
}


void Heap::changePriority(int index, int newValue) {
	// Change priority and adjuct accordingly.
	this->heap->at(index) = newValue;
	siftDown(index);
	siftUp(index);
}


int Heap::size() {
	return this->heap->size();
}


void Heap::siftUp(int index) {
	// Compare child with parent if parent is smaller swap with child.
	if (index == 0 || size() == 0 || index > size()) return;

	int temp = this->heap->at(index);
	while (this->heap[calculateParent(index)] < this->heap[index]) {
		this->heap[index] = this->heap[calculateParent(index)];
		this->heap->at(calculateParent(index)) = temp;
		index = calculateParent(index);
	}
}


void Heap::siftDown(int index) {
	// Compare with children if smaller then any swap with the biggest child all the way to the bottom.
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
	// Same function with a custom upperbound.
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
	return (int) (index - 1) / 2; // Parent = Lower(index/2) for 1-based index.
}


int Heap::calculateLeftChild(int index) {
	return 2 * index + 1; // 2i for 1-based index.
}


int Heap::calculateRightChild(int index) {
	return 2 * index + 2; // 2i + 1 for 1-based index.
}
