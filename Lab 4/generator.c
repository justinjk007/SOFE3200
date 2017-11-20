#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "generator.h"

int main()
{
	// Create a file with a pointer.
	FILE *f = fopen("Spam.txt", "w");
	// Call generate function using file.
	generate(f);
	// Successfully exit.
	return 0;
}

int generate(FILE *f)
{
	// Check for null pointer (i.e. file doesnt exist)
	if (f == NULL) 
	{
		return -1;
	}

	// Gives random function a new seed
	srand(time(NULL));
	for (int i = 0; i < 100000; i++) 
	{
		for (int j = 0; j < 1000; j++) 
		{
			// Print to file a random character
			fprintf(f,"%c", rand() % 26 + 97);
		}
		// Print to file a blank line
		fprintf(f,"\n");
	}
	return 1;
}
