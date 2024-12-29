// Implements custom cp command to copy files

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *dst = fopen(argv[2], "wb");
    if (dst == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return 1;
    }

    BYTE buffer[4096];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(BYTE), sizeof(buffer), src)) > 0) {
        size_t bytesWritten = fwrite(buffer, sizeof(BYTE), bytesRead, dst);
        if (bytesWritten < bytesRead) {
            perror("Error writing to destination file");
            fclose(src);
            fclose(dst);
            return 1;
        }
    }

    if (ferror(src)) {
        perror("Error reading from source file");
    }

    fclose(dst);
    fclose(src);

    return 0;
}

// ./cp <src>.jpg <dst>.jpg