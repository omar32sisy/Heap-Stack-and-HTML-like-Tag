#include <stdio.h>
#include <stdlib.h>

// Function prototypes for heap management
void addHeap(int thing2add);
int heapSize();
int *getHeap();
void maxHeapify(int *heap, int i);
int heapDelete();

// Function prototypes for stack management
void push(int value);
int pop();
int isEmpty();
void printHeap(int *heap, int root, int size);

int main(int argc, char *argv[]) {
    int value;

    // Read integers from stdin and add them to the heap
    while (scanf("%d", &value) != EOF) {
        addHeap(value);
    }

    // Get the size of the heap
    int size = heapSize();

    // Print the heap tree structure as XML
    printHeap(getHeap(), 1, size);
    printf("\n");

    // Delete items one-by-one from the heap, print each, and push onto the stack
    for (int i = 0; i < size; i++) {
        int deleted = heapDelete();
        printf("%d\n", deleted);
        push(deleted);
    }

    // Pop the stack and print each item
    while (!isEmpty()) {
        int popped = pop();
        printf("%d\n", popped);
    }

    return 0;
}

void printHeap(int *heap, int root, int size) {
    if (root <= size) {
        // Print the start tag with the current node value
        printf("<node id=\"%d\">", heap[root - 1]);

        // Recursively print the left and right children
        printHeap(heap, 2 * root, size);
        printHeap(heap, 2 * root + 1, size);

        // Print the end tag
        printf("</node>");
    }
}



