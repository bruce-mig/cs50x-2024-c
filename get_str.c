#include <stdio.h>
#include <string.h>

int main(void) {
    char s[4];

    printf("s: ");
    if (fgets(s, sizeof(s), stdin) != NULL) {
        // Remove the newline character if present
        size_t len = strlen(s);
        if (len > 0 && s[len - 1] == '\n') {
            s[len - 1] = '\0';
        }
        printf("s: %s\n", s);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}