#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 * Create an array of 12 integers. Fill it with random numbers.
 * Sort them in ascending order using bubble sort. -- Google it if You don't know it. (It's easy)
 * Print out the numbers before and after the sorting.
 */

 int main() {
  
	//Creating array
	int array[12], temp = 0;

	//Called once for random generation
	srand(time(NULL));
 
 	//Filling out array with random numbers and printing out
 	printf("Original 12 member array: ");
	for (int i = 0; i < 12; i++) {
		array[i] = rand() % 101;
		printf("%d ", array[i]);
	}

	printf("\n");

	//Bubble sort array and print out
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10 - i; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	//Printing out sorted array
 	printf("Bubblesorted 12 member array: ");
	for (int i = 0; i < 12; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}