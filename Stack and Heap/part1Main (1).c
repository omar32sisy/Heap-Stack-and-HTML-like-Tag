#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function declarations from stringStack.c
char *pop();
void push(const char *thing2push);
int isEmpty();

int main(int argc, char *argv[]) {
    int ch;
    char temp[100];
    int i;

    while ((ch = getchar()) != EOF) {
        if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
            continue;
        else if (ch == '<') {
            ch = getchar();
            if (ch == '/') {
                ch = getchar();
                i = 0; // Reset index for new end tag
                while (ch != '>') {
                    temp[i++] = ch;
                    ch = getchar();
                }
                temp[i] = '\0'; // Null-terminate the string

                char *topTag = pop(); // Get the most recent start tag from the stack
                if (topTag == NULL || strcmp(topTag, temp) != 0) {
                    printf("Invalid\n");
                    // Free remaining stack items to avoid memory leaks
                    while (!isEmpty()) {
                        char *tag = pop(); // Pop the top item from the stack
                        free(tag);        // Free the memory allocated for the tag
                    }
                    free(topTag); // Free the mismatched tag
                    exit(1);
                }
                free(topTag); // Free memory allocated by pop
            } else if (isalpha(ch)) {
                i = 0; // Reset index for new start tag
                while (ch != '>') {
                    temp[i++] = ch;
                    ch = getchar();
                }
                temp[i] = '\0'; // Null-terminate the string
                push(temp); // Push the start tag onto the stack
            }
        }
    }

    if (isEmpty()) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    // Free remaining stack items to avoid memory leaks
    while (!isEmpty()) {
        char *tag = pop(); // Pop the top item from the stack
        free(tag);        // Free the memory allocated for the tag
    }

    return 0;
}

