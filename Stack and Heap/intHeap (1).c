#include <stdio.h>

static int size = 0;  // Current number of elements in the heap
static int heap[100]; // Array to store the heap elements (fixed size of 100)

/**
 * Adds an element to the heap and maintains the max-heap property.
 * @param thing2add The element to be added to the heap.
 */
void addHeap(int thing2add) {
    if (size >= 100) {
        printf("Heap is full.\n");
        return;
    }
    
    heap[size] = thing2add; // Add the new element at the end of the heap
    size++; // Increment the size of the heap
    
    // Restore the max-heap property
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, i + 1); // Note: Using 1-based index for maxHeapify
    }
}

/**
 * Returns the current number of elements in the heap.
 * @return The size of the heap.
 */
int heapSize() {
    return size;
}

/**
 * Returns a pointer to the heap array.
 * @return Pointer to the heap array.
 */
int *getHeap() {
    return heap;
}

/**
 * Maintains the max-heap property starting from index i.
 * @param heap Pointer to the heap array.
 * @param i Index to start heapifying from (1-based index).
 */
void maxHeapify(int *heap, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i; // Left child index (1-based)
    int right = 2 * i + 1; // Right child index (1-based)

    // Check if left child is larger than root
    if (left <= size && heap[left - 1] > heap[largest - 1]) {
        largest = left;
    }

    // Check if right child is larger than largest so far
    if (right <= size && heap[right - 1] > heap[largest - 1]) {
        largest = right;
    }

    // Swap and continue heapifying if root is not the largest
    if (largest != i) {
        int temp = heap[i - 1];
        heap[i - 1] = heap[largest - 1];
        heap[largest - 1] = temp;
        maxHeapify(heap, largest); // Recursively heapify the affected sub-tree
    }
}

/**
 * Removes and returns the maximum element from the heap.
 * @return The maximum element from the heap, or -1 if the heap is empty.
 */
int heapDelete() {
    if (size == 0) {
        return -1; // Heap is empty
    }

    int biggest = heap[0]; // Get the maximum element
    heap[0] = heap[size - 1]; // Replace the root with the last element
    size--; // Decrease the size of the heap

    // Restore the max-heap property
    if (size > 0) {
        maxHeapify(heap, 1); // Note: Using 1-based index for maxHeapify
    }

    return biggest;
}
