#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *file =  fopen("phonebook.csv", "a+"); // Open file for reading and appending
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Check if file is empty
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    if (fileSize == 0) {
        // Write the header if file is empty
        fprintf(file, "NAME,NUMBER\n");
    }
    rewind(file);

    char name[20];
    char number[20];

    printf("Name: ");
    scanf("%19s", name); // Read up to 19 characters to avoid buffer overflow
    printf("Number: ");
    scanf("%19s", number); // Read up to 19 characters to avoid buffer overflow


    fprintf(file, "%s,%s\n", name, number);
    fclose(file);

    return 0;
}