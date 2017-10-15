#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr, *fpt, *out_file;
    char a, b, c, d, e;

    // Open file
    fptr = fopen("Input.txt", "r");
    printf("The contents of Input.txt is: \n\n");
    // Read contents from file
    c = fgetc(fptr);
    // Display contents of the file
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }

    a        = 'a';  // I don't know what to say here
    b        = 'b';
    fpt      = fopen("Input.txt", "r+");  // Open file for reading and more
    out_file = fopen("Heaven.txt", "w");  // Open file for writing
    printf("\nThe contents of Input.txt after changing a's with b's is: \n\n");
    d = fgetc(fpt);
    e = fgetc(out_file);

    while (d != EOF) {
        if (d == a) {
            d = b;
        }
        printf("%c", d);
        fprintf(out_file, "%c", d);
        e = fgetc(out_file);
        d = fgetc(fpt);
    }
    // Close every file opened
    fclose(out_file);
    fclose(fptr);
    fclose(fpt);

    return 0;  // We are safe
}
