#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a = 54325;
    char buffer[20];

    //TODO: make an integer to string conversion with itoa(), first in binary, then decimal format
    // Store the string in buffer
    printf("The %d number converted to binary and than string is: %s\n", a, itoa(a, buffer, 2));
    printf("The %d number converted to string is: %s\n", a, itoa(a, buffer, 10));

    return 0;
}