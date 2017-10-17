#include <stdio.h>
#include <string.h>
#include <inttypes.h>

//TODO: write a function which returns 485 as unsigned integer value
//put your return value in an integer variable in which you should have 229, and print it out
//try to figure out which type casting you should use
int func() {
	uint16_t f = 485;
	return f;
}

int main()
{
	int num = 229;

	num = func();

	printf("Value: %d.\n", num);

    return 0;
}
