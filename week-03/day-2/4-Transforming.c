#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	float val;
	char str[5];
	strcpy(str, "3.14");

	//TODO: print out the value of pi, first as a string, then a float value.
	printf("The value of Pi (as string): %s\n.", str);

	printf("The value of Pi (as float): %f\n.", atof(str));

	return(0);
}