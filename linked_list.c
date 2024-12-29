// Implements a list of numbers using a linked list.
// Each number is added to the end of the list, preserving the input order.

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

        // If list is empty
        if (list == NULL) {
            // This node is the whole list
            list = n;
        }
        // If list has numbers already
        else {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
                // If at end of list
                if (ptr->next == NULL) {
                    // Append node
                    ptr->next = n;
                    break;
                }
            }
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