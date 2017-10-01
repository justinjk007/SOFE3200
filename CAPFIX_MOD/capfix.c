#include <stdio.h>
#include <stdlib.h>

// Add function protypes here
int ReadData(FILE* fpt, char* first[][30], char* last[][30]);
void CapFix(char word[30]);

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

    total = ReadData(fpt, first_ptr, last_ptr); /* TODO: Fix this later */

    while (1) {
        if (fscanf(fpt, "%s %s", last[total], first[total]) != 2) break;
        total++;
    }

    for (i = 0; i < total; i++) {
        if (first[i][0] >= 'a' && first[i][0] <= 'z') first[i][0] = first[i][0] - 'a' + 'A';

        for (j = 1; j < strlen(first[i]); j++)
            if (first[i][j] >= 'A' && first[i][j] <= 'Z') first[i][j] = first[i][j] - 'A' + 'a';
    }

    for (i = 0; i < total; i++) {
        if (last[i][0] >= 'a' && last[i][0] <= 'z') last[i][0] = last[i][0] - 'a' + 'A';

        for (j = 1; j < strlen(last[i]); j++)
            if (last[i][j] >= 'A' && last[i][j] <= 'Z') last[i][j] = last[i][j] - 'A' + 'a';
    }

    for (i = 0; i < total; i++) printf("%s %s\n", first[i], last[i]);

    fclose(fpt);
}

int ReadData(FILE* fpt, char* first[][30], char* last[][30])
{
    /*
     * Reads data from file
     */
    int total = 0;

    /* TODO: Copy and paste the read file bit later */

    return total;
}

void CapFix(char word[30])
{
    /*
     * Format letters neatly
     */
}
