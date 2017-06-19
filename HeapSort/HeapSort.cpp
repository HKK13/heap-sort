#include "HeapSort.h"
#include "Heap.h"
#include <iostream>


void HeapSort::sort(std::vector<int>& unorderedArr)
{
	// In memory heap sort.
	Heap heap = Heap(unorderedArr);

	int temp;
	int size = heap.size() - 1;
	for (int i = 0; i < heap.size(); i++) {
		// Swap max with the last item and decrement size by 1, finally sift down the first item in heap.
		temp = heap[0];
		heap[0] = heap[size];
		heap[size] = temp;
		size--;
		heap.siftDown(0, size);
	}
}
