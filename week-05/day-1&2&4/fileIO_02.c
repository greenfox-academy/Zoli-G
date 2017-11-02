/*
 * Read the file You created fo the first exercise again.
 * Reverse the order of lines and write it out in a new file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char buffer[100][64];
	unsigned int c, counter = 0;
	FILE *file;

	file = fopen("fileIO_00-szondi.txt", "r");

	if (file) {
    	while (fgets(buffer[counter], 64, file) != NULL) {
    		puts(buffer[counter]);
        	counter++;
    	}
    fclose(file);
	}

	//Delete new line code from the first line (this will be the last line and generates an empty line at the file end) (10)
	buffer[0][strlen(buffer[0]) - 1] = 0;
	//Add new line at the last line (this'll be the first line when reversed)
	//Last line is at counter - 1, at counter there is an end-of-text character (ASCII-3)
	buffer[counter - 1][strlen(buffer[counter - 1]) - 1] = 10;
	//for (int i=0;i<strlen(buffer[counter-1]);i++) {printf("%c(%d)\n", buffer[counter-1][i], buffer[counter-1][i]);}

	file = fopen("fileIO_02-szondi-rev.txt", "w");

	for (; counter > 0; counter--) {
		fputs(buffer[counter], file);
	}
	fputs(buffer[0], file);

	fclose(file);

	return 0;
}
