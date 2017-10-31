/*
 * Create 9 arrays of characters, each should contain a word.
 * Let it be this: The Quick brown Dog jumps over the Lazy Fox.
 * Create an array of 9 pointers of chractrer type.
 * Make it so, that each pointer points to one of the words. Meaning to one of the original arrays You just created.
 * So You'll have a pointer pointing to each of these original arrays in an array of pointers.
 * Print them out, each in a new line using this array of pointers.
 * Now make it so, that the Fox is Green and he jumps over the lazy dog.
 * Use the existing arrays to achive this.
 * Print it out again.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char string0[] = "The";
	char string1[] = "Quick";
	char string2[] = "brown";
	char string3[] = "Dog";
	char string4[] = "jumps";
	char string5[] = "over";
	char string6[] = "the";
	char string7[] = "Lazy";
	char string8[] = "Fox";

	char *p[9];

	p[0] = string0;
	p[1] = string1;
	p[2] = string2;
	p[3] = string3;
	p[4] = string4;
	p[5] = string5;
	p[6] = string6;
	p[7] = string7;
	p[8] = string8;

	for (int i = 0; i < 9; i++) {
		printf("%s\n", p[i]);
	}

	printf("\n");

	strcpy(p[2], "Green");
	strcpy(p[3], "Fox");
	strcpy(p[8], "Dog");

	for (int i = 0; i < 9; i++) {
		printf("%s\n", p[i]);
	}

	return 0;
}