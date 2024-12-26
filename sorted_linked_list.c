// Implements a list of numbers using a linked list

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
        if (list = NULL) {
            // This node is the whole list
            list = n;
        }
        // If number belongs at the beginning of list
        else if (n->number < list->number){
            n->next = list;
            list = n;

        }
        // If number belongs later in list
        else {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
                // If at end of list
                if (ptr->next == NULL) {
                    // Append node
                    ptr->next = n;
                    break;
                }

                // If in middle of list
                if (n->number < ptr->next->number) {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }
}