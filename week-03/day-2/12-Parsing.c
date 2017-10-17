#include <stdio.h>
#include <string.h>
int main ()
{
	char string[55] ="This is a string for testing";
	char *p;

	//TODO: write a program, which lists all position where character 'i' is found
	printf("Positions of 'i' in string '%s': ", string);
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == 'i') {
			printf("%d ", i);
		}
	}
	return 0;
}
