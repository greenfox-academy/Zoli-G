#include <stdio.h>
#include <limits.h>

int main()
{
	int number_array[8] = {48, 59, 2, -8, 55, 56, 78, 12};

	//TODO:
	// Write a C program to find the two largest element in an array using only 1 for loop
	int i, max1, max2;

    for (i = 0; i < sizeof(number_array) / sizeof(int); i++) {
        printf("%d ", number_array[i]);
    }

    // From <limits.h> use INT_MIN: this is the least integer
    max1 = INT_MIN;
	max2 = INT_MIN;

	printf("\n\n");
    for (i = 0; i < sizeof(number_array) / sizeof(int); i++) {
        if (number_array[i] > max1) {
            max2 = max1;
            max1 = number_array[i];
            printf("max1=%d\n", max1);
        }
        else if (number_array[i] > max2) {
            max2 = number_array[i];
            printf("max2=%d\n", max2);
        }
    }

    printf("\n\nThe two largest numbers are %d and %d.", max1, max2);

	return 0;
}
