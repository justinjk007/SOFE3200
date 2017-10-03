#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Add function protypes here
int readData(FILE* fpt, char first[][30], char last[][30]);
void capFix(char word[30]);

int main(int argc, char* argv[])
{
    FILE* fpt;
    char first[20][30], last[20][30];
    char* last_ptr  = &last[0];
    char* first_ptr = &first[0];
    int i, j, total = 0;

    if (argc != 2) {
        printf("Usage: CAPFIX [filename]\n");
        exit(0);
    }

    if ((fpt = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        exit(0);
    }

    total = readData(fpt, first_ptr, last_ptr);


    for (int i = 0; i < total; i++) {
	capFix(&first[i]);
    }

    for (int i = 0; i < total; i++) {
	capFix(&last[i]);
    }

    for (i = 0; i < total; i++) printf("%s %s\n", first[i], last[i]);

    fclose(fpt);
}

int readData(FILE* fpt, char first[][30], char last[][30])
{
    /*
     * Reads data from file
     */
    int total = 0;

    while (1) {
        if (fscanf(fpt, "%s %s", last[total], first[total]) != 2) break;
        total++;
    }

    return total;
}

void capFix(char word[30])  // Maximum length of the word is 30 letters
{
    /*
     * Format letters neatly
     */
    int len = strlen(word); // Get the length of the word
    if (word[0] >= 'a' && word[0] <= 'z')  // Upcase the first letter of the word
    {
        word[0] = word[0] - 'a' + 'A';
    }

    for (int i = 1; i < len; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z')  // Downcase rest of the letters in the word
        {
            word[i] = word[i] - 'A' + 'a';
        }
    }
}