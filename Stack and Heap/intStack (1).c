#include <stdio.h>
#include <stdlib.h>

static int top = 0;       // Index of the top element in the stack (0 means stack is empty)
static int stack[100];    // Array to store stack elements with a maximum size of 100

/**
 * Pushes a value onto the stack.
 * @param value The value to be pushed onto the stack.
 */
void push(int value) {
    if (top < 100) {          // Check if there is space available in the stack
        stack[top++] = value; // Add value to the stack and increment top
    } else {
        fprintf(stderr, "Stack overflow\n"); // Print error message if stack is full
    }
}

/**
 * Pops a value from the stack.
 * @return The value at the top of the stack, or -1 if the stack is empty.
 */
int pop() {
    if (top > 0) {             // Check if the stack is not empty
        return stack[--top];  // Decrement top and return the value at the top of the stack
    } else {
        fprintf(stderr, "Stack underflow\n"); // Print error message if stack is empty
        return -1; // Return -1 to indicate an empty stack
    }
}

/**
 * Checks if the stack is empty.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty() {
    return top == 0; // Return 1 if top is 0 (stack is empty), otherwise return 0
}
