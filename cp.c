// Implements custom cp command to copy files

#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[]) {
    FILE *src = fopen(argv[1], "rb");
    if (src == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    FILE *dst = fopen(argv[2], "wb");
     if (src == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);
}

// ./cp <src>.jpg <dst>.jpg