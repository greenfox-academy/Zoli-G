/*
 * Create a function that takes an array of array of characters and returns an array of integers each representing the
 * lenght of the given character array in the first array.
 * Say your input is this: {"Good", "Morning", "Vietnam"}
 * Your output should be this: {4, 7, 7}.
 * HINT: strings are terminated with a special character: '\0'.
 * So, "Good" as an array of characters would look like this: {'G', 'o', 'o', 'd', '\0'}.
 *
 * In the main function create code that demonstrates that Your function works approrpiately.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *stringlengthtoarray(int n, int m, char stringarray[n][m]);

int main() {
	int *p;

	char string[5][11] = {"Good", "Bad", "Ice", "CodeBlocks", "C"};

	p = stringlengthtoarray(5,11,string);

	for (int i = 0; i < 5; i++) {
		printf("%d \n", *(p + i));
	}

	return 0;
}

int *stringlengthtoarray(int n, int m, char stringarray[n][m]) {
	int *result;

	result = malloc(n * m * sizeof(int));

	for (int i = 0; i < n; i++) {
		*(result + i) = strlen(stringarray[i]);
	}
	return result;
}
