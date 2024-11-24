/**
 *  The functions in this module implement a Stack data structure
 *  of char pointers (aka "strings").
 *
 *  NOTE: the stack is implemented as a fixed size array (size = 100).
 *  Consequently, no more than 100 strings can be pushed onto
 *  the Stack at any given time.
 */

// Implementation hints:
//   The 3 functions--push, pop and isEmpty--share information
//   about the array used to implement the stack and the index
//   of the "top" of the stack.
//
//   You may want to make these variables global...
//   ...but that would
//   be a mistake (because anyone using the module would have
//   to ensure that they did not use global variables with the
//   same names).
//
//   An alternative in C is a "static global".
//   If a global variable is qualified as "static", it is global only
//   within the source code file where it is declared.
//   In parituclar, it cannot conflict with any other global variable.
//
//  RECOMMENDATION:
//   Uncomment the following 2 lines and use these static globals!
// static int top = 0;
// static char * stack[100];

/**
 * pop() removes the top string on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value NULL ((char *) 0) is returned.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack variables
static int top = 0;
static char *stack[100]; // Stack to hold up to 100 pointers

char *pop() {
    if (top == 0) {
        fprintf(stderr, "Stack underflow\n");
        return NULL;
    }
    char *item = stack[--top]; // Pop the top pointer
    return item;
}

void push(const char *thing2push) {
    if (top >= 100) {
        fprintf(stderr, "Stack overflow\n");
        return;
    }
    stack[top++] = strdup(thing2push); // Duplicate string and push onto stack
}

int isEmpty() {
    return top == 0; // Return 1 if stack is empty, otherwise return 0
}

