#include <stdio.h>

int my_strlen(char *string);

int main()
{
	char my_string[50] = "Hello world!";

	//TODO: implement your own strlen function.
	int length;

	length = my_strlen(my_string);

	printf("String length from custom function: %d.\n", length);

	return 0;
}

int my_strlen(char *string) {
	int counter = 0;

	while (*(string + counter) != NULL) {
		counter++;
	}

	return counter;
}