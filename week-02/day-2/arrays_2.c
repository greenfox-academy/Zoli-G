#include <stdio.h>

int main() {
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

	//TODO:
    // Print out the two arrays character-by-character
    printf("Printing first array:\n");
    int i;
    for (i = 0; i < sizeof(char_array); i++) {
        printf("%c\n", char_array[i]);
    }
    printf("Size of the array if the array defined by elements: %d", sizeof(char_array));

    printf("\n\nPrinting second array:\n");
    int j;
    for (j = 0; j < sizeof(char_array_the_same) - 1; j++) {
        printf("%c\n", char_array_the_same[j]);
    }
    printf("Size of the array if the array defined by string: %d\n", sizeof(char_array_the_same));

	//TODO:
    // What is the difference between the arrays?
    printf("\nThe size of a char array is 1 byte larger if defined by string.\n");

    return 0;
}
