#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    FILE *fptr, *fpt, *file;
 
    char a, b, c, d, e;
 
    // Open file
    fptr = fopen("Input.txt", "r"); 

    printf ("The contents of Input.txt is: \n\n");
 
    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
  	c = fgetc(fptr);
    }

    a = 'a';
    b = 'b';

    fpt = fopen("Input.txt", "r+");
    file = fopen("Heaven.txt", "w");

    printf ("\nThe contents of Input.txt after changing a's with b's is: \n\n");

    d = fgetc(fpt);
    e = fgetc(file);

    while (d  != EOF)
    {
        if (d == a) {
            d = b;
        }
    
    printf ("%c", d);
    fprintf (file, "%c", d);
   
    e = fgetc(file);
    d = fgetc(fpt);
    }

    fclose(file); 
    fclose(fptr);
    fclose(fpt);

    return 0;
}

