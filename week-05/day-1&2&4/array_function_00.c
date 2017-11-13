/*
 * Create a function that takes an array of integers as an argument (a pointer) and it's length as an unsigned integer.
 * The function should sort the elements of the array in ascending order.
 *
 * Print it out before and after to be able to check whether it works as supposed.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortarray(int *p, unsigned int length);

int main() {

	//Creating array
	int array[12];

	int *p;
	p = array;

	//Called once for random generation
	srand(time(NULL));

 	//Filling out array with random numbers and printing out
 	printf("Original array: ");
	for (int i = 0; i < 12; i++) {
		array[i] = rand() % 101;
		printf("%d ", array[i]);
	}

	printf("\n");

	sortarray(p, 12);

	//printf("%d\n", *(p + 1));

	return 0;
}

void sortarray(int *p, unsigned int length) {
	int temp = 0;
	//Bubble sort array and print out
	for (int i = 0; i < length - 2; i++) {
		for (int j = 0; j <= length - 2 - i; j++) {
			if (*(p + j) > *(p + j + 1)) {
				temp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = temp;
			}
		}
	}

	//Printing out sorted array
 	printf("Bubblesorted array: ");
	for (int i = 0; i < length; i++) {
		printf("%d ", *(p + i));
	}
}
