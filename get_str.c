#include <stdio.h>

int main(void) {
    // char *s; // Segmentation fault (core dumped)
    
    char s[4];
    printf("s: "); 
    scanf("%s: ", s); // s: HI! else *** stack smashing detected ***: terminated
    printf("s: %s\n", s);
}