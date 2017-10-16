#include <stdio.h>
#include <math.h>

// This program should work correctly with the following input: 20, 400

int main()
{
	double number, result;
	printf("Please enter a number: ");
	fflush(stdin);
	scanf("%f", &number);

	printf("Please enter the square of that number: ");
	fflush(stdin);
	scanf("%f", &result);

	double p = pow(result, 2);
	//printf("%f", p);

	if ((int)pow(result, 2) == (int)number)
		printf(":)\n");
	else
		printf(":(\n");

	return 0;
}

//used double instead of float because of pow function
//switched number <-> result values in "if" line
