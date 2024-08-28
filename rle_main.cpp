#include "archieve.h"
#include "unarchieve.h"

static const char *INPUT_FILE = "input_file.txt";
static const char *INTERMEDIATE_FILE = "intermediate_file.txt";
static const char *OUTPUT_FILE = "output_file.txt";

int main() {
    int difference = archive(INPUT_FILE, INTERMEDIATE_FILE);

    if (difference >= 0) printf(GREEN("Succeeded save %d symbols!\n"), difference);
    else printf(RED("There are %d more symbols!"), -difference);

    unarchive(INTERMEDIATE_FILE, OUTPUT_FILE);

    return 0;
}
