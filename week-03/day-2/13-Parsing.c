#include <stdio.h>
#include <string.h>

int main ()
{
	char str[] = "This is a sample string";
    char *first, *last;

	//TODO: write a program which prints out the distance between the first and last occurance of character 's'

  	first = strchr(str,'s');
  	int f = first - str + 1;

  	last = strrchr(str, 's');
  	int l = last - str + 1;

	printf("The distance between the first and last letter 's' in string '%s' is %d.", str, l - f);

    return 0;
}
