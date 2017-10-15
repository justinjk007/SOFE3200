#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr, *out_file;
    char a, b, c, d;

    // Open file to read contents
    fptr = fopen("Input.txt", "r");
    c = fgetc(fptr);
    // Display contents of the file
    printf("The contents of Input.txt is: \n\n");
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }
    rewind(fptr); // Reset pointer to the beginning of the file

    a        = 'a';  // I don't know what to say here
    b        = 'b';
    out_file = fopen("Heaven.txt", "w");  // Open file for writing
    printf("\nThe contents of Input.txt after changing a's with b's is: \n\n");
    d = fgetc(fptr);

    // Display contents of the file after editing
    while (d != EOF) {
        if (d == a) {
            d = b;
        }
        printf("%c", d); // Print file after editing
        fprintf(out_file, "%c", d); // Save edited contents into new file
        d = fgetc(fptr);
    }

    // Close both opened files
    fclose(out_file);
    fclose(fptr);
    return 0;  // We are safe

}
