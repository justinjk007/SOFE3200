#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "generator.h"

int main(char argv[], int args) 
{
	// Create/open file with pointer
	FILE *f = fopen("spam.txt", "w");
	// Start clock
	clock_t begin = clock();
	// Call generate function
	generate(f);
	// Start another clock to use for difference
	clock_t end = clock();
	printf("%f", (double)((end - begin) / CLOCKS_PER_SEC));
	// Close file to prevent memory leaks
	fclose(f);
	// Exit 
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
