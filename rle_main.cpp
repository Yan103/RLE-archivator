#include <stdio.h>
#include <ctype.h>

#include "color_printf.h"

static const char *INPUT_FILE = "input_file.txt";
static const char *INTERMEDIATE_FILE = "intermediate_file.txt";
static const char *OUTPUT_FILE = "output_file.txt";

static int archive(const char *file_input, const char *file_output);
static int unarchive(const char *file_read, const char *file_output);

static int archive(const char *file_input, const char *file_output) {
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

static int unarchive(const char *file_read, const char *file_output) {
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

int main() {
    int difference = archive(INPUT_FILE, INTERMEDIATE_FILE);

    if (difference >= 0) printf(GREEN("Succeeded save %d symbols!\n"), difference);
    else printf(RED("There are %d more symbols!"), -difference);

    unarchive(INTERMEDIATE_FILE, OUTPUT_FILE);

    return 0;
}
/* if (count > 1) fprintf(output_file, "%d%c", count, pred);
            else fprintf(output_file, "%c", pred); */