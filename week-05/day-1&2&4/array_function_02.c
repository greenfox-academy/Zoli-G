/*
 * Create a function that takes two arrays of characters and a number.
 * It should replace the contents of the first array from the given index
 * with the contents of the second array.
 * The function should return a number which tells whether it was successful:
 *    * If all is right it should return 0.
 *    * If the index is out of bounds it should return -1.
 *    * If the inserted content would be longer than the receiving array it should return 1 and leave the array as it is.
 * IMPORTANT: Think about what kind of arguments You need to make this happen and craft the function accordingly.
 *
 * Write code in the main function to test all scenarios and write out the result You need to check whether this works.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strcopy(char dest[], char source[], int index);

int main() {

	char c1[] = "Hello ez nem jatek!"; //19
	char c2[] = "semmi!"; //6
	int index = 13;

	strcopy(c1, c2, index);

	return 0;
}

int strcopy(char dest[], char source[], int index) {

	if (strlen(dest) < index) {
		return -1;
	}

	if (strlen(dest) < strlen(source) + index) {
		return 1;
	}

	char *p = dest;
	char *p_copy = source;

	for (int i = 0; i < strlen(source); i++) {
        *(p + index + i) = *(p_copy + i);
	}

	return 0;
}
