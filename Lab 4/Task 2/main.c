#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Check for argument count, first argument is the name of the executable
    int count = 0; // number of charecters in the file
    if (argc != 3) {
	printf("Incorrect number of arguments!\n");
	printf("Usage: ./main <sourcefile> <charcter to be changed>\n");
	exit(EXIT_FAILURE);
    }
    if (strlen(argv[2]) != 1) {
	printf("Incorrect TYPE of arguments!\n");
	printf("Usage: ./main <sourcefile> <charcter to be changed>\n");
        exit(EXIT_FAILURE);
    }

    char check = *argv[2];
    FILE *fptr;
    char foo;

    // Open file to read contents
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        // Handle file reading errors safely
        printf("Opening input file failed\n");
        exit(1);
    }
    rewind(fptr);

    // Service each char in the file
    while (foo != EOF) {
	if (check == foo)
	    count++;
	    foo = fgetc(fptr);
    }

    printf("Total number of charecters in the file: %d\n",count);
    // Close both opened files
    fclose(fptr);
    return 0;  // We are safe
}
