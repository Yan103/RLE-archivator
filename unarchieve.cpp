#include "unarchieve.h"

int unarchive(const char *file_read, const char *file_output) {
    FILE *read_file = fopen(file_read, "r");

    if (!read_file) {
        printf(RED("File error!\n"));

        return 1;
    }

    FILE *output_file = fopen(file_output, "w");

    char curr = 0;
    int count = 0;

    while (!feof(read_file)) {
        count = fgetc(read_file) - '0';
        curr = fgetc(read_file);
        while (count-- > 0) {
            fputc(curr, output_file);
        }
    }

    fclose(read_file);
    fclose(output_file);

    return 0;
}