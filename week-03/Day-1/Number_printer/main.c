#include <stdio.h>
#include <stdint.h>

//used uint32_t instead of int
//used %zu print format instead of %d

void printf_numbers(uint32_t from, uint32_t to)
{
	for (uint32_t i = from; i < to; i++)
		printf("%zu,", i);
}

int main()
{
	printf_numbers(2147483600, 2147484600);
	return 0;
}
