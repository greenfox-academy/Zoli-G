/*
 * Take an array of characters, for example this: "In the year 2525, If man is still alive... In the Year 3535, In the Year 4545"
 * Create a function that takes an array of characters as an input, and a single character.
 * It should return the first index when this character appears.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchChar(char string[], char c);

int main() {

	char text[] = "In the year 2525, If man is still alive... In the Year 3535, In the Year 4545";

	char c = 'y';

	printf("First occurrance of letter %c is at position %d.", c, searchChar(text, c));
}

int searchChar(char string[], char c) {
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == c) {
			return i;
		}
	}
}