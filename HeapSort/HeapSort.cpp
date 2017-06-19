#include "HeapSort.h"
#include "Heap.h"
#include <iostream>


void HeapSort::sort(std::vector<int>& unorderedArr)
{
	Heap heap = Heap(unorderedArr);

	int temp;
	int size = heap.size() - 1;
	for (int i = 0; i < heap.size(); i++) {
		temp = heap[0];
		heap[0] = heap[size];
		heap[size] = temp;
		size--;
		heap.siftDown(0, size);
	}
}
