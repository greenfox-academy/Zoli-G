/*
 * Create a text file with You favourite poem in it. If You don't have one, just take one.
 *
 * Read the poem from the file and print it on the console.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned int c;
	FILE *file;

	file = fopen("fileIO_00-szondi.txt", "r");

	if (file) {
    	while (c = fgetc(file), c != EOF) {
        	putchar(c);
    	}
    fclose(file);
	}

	return 0;
}
