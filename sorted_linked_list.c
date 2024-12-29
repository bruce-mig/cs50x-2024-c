// Implements a list of numbers using a linked list
// The list will be sorted in ascending order as you insert each number

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[]) {
    // Memory for numbers
    node *list = NULL;

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return 1;
        }

        n->number = number;
        n->next = NULL;

        // If list is empty or new node should be first
        if (list == NULL || list->number >= number) {
            n->next = list;
            list = n;
        } else {
            // Find the correct position to insert the new node
            node *current = list;
            while (current->next != NULL && current->next->number < number) {
                current = current->next;
            }
            n->next = current->next;
            current->next = n;
        }
    }

    // Print the list
    for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
        printf("%d\n", ptr->number);
    }

    // Free the list
    while (list != NULL) {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

    return 0;
}