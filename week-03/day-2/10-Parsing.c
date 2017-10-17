#include <stdio.h>
#include <string.h>

int main()
{
	char string[256];
    char *token;

    printf("Type in a sentence:\n\n");
    gets(string);

    //TODO: write a c program which, splits a string to words by space
	//solve the problem with the proper string.h function
	//first token
   	token = strtok(string, " ");

    while (token != NULL) {
    	printf("%s\n", token);
    	//subsequent tokens gets NULL parameter to continue serch where it left off
    	token = strtok(NULL, " ");
    	
  	}


    return(0);
}