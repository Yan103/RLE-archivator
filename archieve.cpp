#include "archieve.h"

int archive(const char *file_input, const char *file_output) {
    FILE *input_file = fopen(file_input, "r");

    if (!input_file) {
        printf(RED("File error!\n"));

        return 1;
    }

    FILE *output_file = fopen(file_output, "w");

    int count = 1;
    char pred = 0, curr = fgetc(input_file);

    int count_input = 0, count_output = 0;
    while (!feof(input_file)) {
        count_input++;
        pred = curr;
        curr = fgetc(input_file);

        if (pred == curr) count++;
        else {
            fputc(count + '0', output_file);
            fputc(pred, output_file);
            count = 1;
            count_output += 2;
        }
    }

    fclose(input_file);
    fclose(output_file);

    return count_input - count_output;
}
