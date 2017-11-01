/*
 * Read the file You created in the first exercise.
 * Reverse the order of the verses.
 * Write it out in a new file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char buffer[10][160] = {"\0"}, stanza_line[45] = "\0", stanza[160] = "\0";
	unsigned int counter = 0;
	char *p_fgetc;
	FILE *file;

	file = fopen("fileIO_00-szondi.txt", "r");

	if (file == 0) {printf("File open error!\n");}

	while (p_fgetc != NULL) {
		//Fill a temp line buffer from file line-by-line until the empty line of file end and joins them in a stanza string
    	while (p_fgetc = fgets(stanza_line, 45, file), stanza_line[0] != 10 && p_fgetc != NULL) {
    		strcat(stanza, stanza_line);
    		//puts(stanza_line);
    	}

    	//Copy whole stanza to the array buffer
    	strcpy(buffer[counter], stanza);
    	//Make stanza look like empty string for next cycle strcat
    	stanza[0] = '\0';
    	//Point the counter on the next empty buffer, next stanza
    	counter++;
	}
	counter--;

	//Delete new line code at the end of the first stanza (this will be the last stanza and generates an empty line at the file end) (10)
	buffer[0][strlen(buffer[0]) - 1] = 0;
	//Add new line at the end of the last stanza (this'll be the first stanza when reversed)
	buffer[counter][strlen(buffer[counter]) - 1] = 10;

    fclose(file);

    //Saving to file
    file = fopen("fileIO_03-szondi-rev-by-stanza.txt", "w");

    //Run through the buffer array backwards, put the elements in the file, put a newline char between stanzas (except last)
	for (int i = counter; i >= 0; i--) {
		fputs(buffer[i], file);
		if (i != 0) fputc(10, file);
	}

	fclose(file);

    printf("Successfully saved poem stanzas backwards.");

	return 0;
}
