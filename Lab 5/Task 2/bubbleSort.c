#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int myint, temp, unsorted = 0;
    int numbers[5];

    for (int i = 0; i < 5; i++) {
        printf("\ninput number %i :", i);
        scanf_s("%i", &myint);
        numbers[i] = myint;
    }
    printf("%i\n", myint);

    printf("\n current unsorted array is:\n");
    for (int i = 0; i < 5; i++) {
        printf("%i\n", numbers[i]);
    }

    do {
        unsorted = 0;
        for (int i = 0; i < 4; i++) {
            if (numbers[i] > numbers[i + 1]) {  // if i+1 is smaller than i
                temp           = numbers[i];    // swap index i and i+1
                numbers[i]     = numbers[i + 1];
                numbers[i + 1] = temp;
                unsorted++;  // send flag that it is not sorted yet
            }
        }
    } while (unsorted);

    printf("\n array sorted in ascending order is:\n");
    for (int i = 0; i < 5; i++) {
        printf("%i\n", numbers[i]);
    }

    printf("\n\n\n\nenter an integer when you are done\n");
    scanf_s("%i", &myint);

    return 0;
}
