/*
 * Take an array of characters, for example this: "In the year 2525, If man is still alive... In the Year 3535, In the Year 4545"
 * Create a function that takes an array of characters as an input, and a single character.
 * It should return all the indexes when teh character appears in an array of integers. Where the first number of the array
 * is how many occurrences of the character there are.
 *
 * Example: for the input ("Where is my cat? He?", 'e') the output should be: {3,2,4,18}
 *
 * Create a main function where You can test this function.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *searchAllChar(char string[], char c);

int main() {

	char text[] = "In the year 2525, If man is still alive... In the Year 3535, In the Year 4545";
	char c = 't';
	int *p;

	p = searchAllChar(text, c);

	for (int i = 0; i < *p + 1; i++) {
		printf("%d ", *(p + i));
	}
}

int *searchAllChar(char string[], char c) {
	int counter = 0;
	int *result;

	//Create a string sized array, that's too big
	result = malloc(strlen(string)* sizeof(int));

	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == c) {
			*(result + 1 + counter) = i;
			counter++;
		}
	}

	//First element is the no of occurrances
	*result = counter;

	//Reallocate the array to the found items
	result = realloc(result, (counter + 1) * sizeof(int));

	return result;
}
