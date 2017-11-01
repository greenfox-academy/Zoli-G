/*
 * Take the file You created in the previous exercise.
 * Read it again and write some statistics about it:
 *    * How many lines
 *    * How many characters (with and without spaces)
 *    * How many verses does it have
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned int c,
				newline_found_at = 0,
				Newlines = 0,
				Stanzas = 0,
				Chars_without_space = 0,
				Chars_with_space = 0;

	FILE *file;

	file = fopen("fileIO_00-szondi.txt", "r");

	if (file) {
    	while (c = getc(file), c != EOF) {
            if (c < 32) printf("(%d)", c);
        	putchar(c);
        	if (c > 31) {Chars_with_space++;}
        	if (c == 10) {
        		Newlines++;
        		if (Chars_with_space == newline_found_at) {Stanzas++; newline_found_at = 0;}
        		else {newline_found_at = Chars_with_space;}
        	}
        	if (c > 32) {Chars_without_space++;}
    	}
    fclose(file);
	}

	printf("\nLines: %d\n", Newlines + 1);
	printf("\nCharacters included spaces: %d\n", Chars_with_space);
	printf("\nCharacters excluded spaces: %d\n", Chars_without_space);
	printf("\nStanzas: %d\n", Stanzas + 1);

	return 0;
}
