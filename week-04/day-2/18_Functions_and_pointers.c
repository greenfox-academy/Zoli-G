#include <stdio.h>

int first_word(char *string, char *first);

int main()
{
    //TODO: write a function, which extracts the first word of a given string.
    //return with the word's length

    char str[] = "Extracting the first word.";
    char first[50];

    int length = 0;
    length = first_word(str, first);

    printf("The first word is '%s' and its length is %d.\n", first, length);

    return 0;
}

int first_word(char *string, char *first) {
	strcpy(first, strtok(string, " "));
	
	return strlen(first);
}