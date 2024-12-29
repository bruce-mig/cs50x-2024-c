// Each new number is inserted at the beginning of the list, so the list ends up in reverse order of the input arguments.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[]) {
    node *list = NULL;

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL) {
            // Free memory thus far
            return 1;
        }

        n->number = number;
        n->next = list;
        list = n;
    }

    // Print whole list
    node *ptr = list;
    while (ptr != NULL) {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    // Free the list
    while (list != NULL) {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

    return 0;
}
