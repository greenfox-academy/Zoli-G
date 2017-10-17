#include <stdio.h>
#include <conio.h>

main()
{
	int  i = 2;
	float f = 13.5, result;

	//TODO: print out the f/i quotient
	result = f / i;
	printf("%f\n", result);

	//QUESTION: do you need explicit conversion?
	//No, because f was already float.

	return 0;
}
