#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Create an array of 5 integers, fill it with random numbers.
 * Create an other of 7 integers.
 * Copy the contents of the first array into the second one in a way,
 * that the first and the last numbers of the second array are both 42,
 * and it contains all the elements of the first array.
 */

int main() {
  
	//Creating array of 5 ints
	int array5[5];

	//Called once for random generation
	srand(time(NULL));
 
 	//Filling out array with random numbers 0-100
 	printf("Original 5 member array: ");
	for (int i = 0; i < 5; i++) {
		array5[i] = rand() % 101;
		printf("%d ", array5[i]);
	}

	printf("\n");

	//Creating another array of 7 ints
	int array7[7];

	//Copying smaller array into the larger one + 2*42
	printf("Copied array with 7 members: ");
	for (int i = 0; i < 7; i++) {
		if (i == 0 || i == 6)
			array7[i] = 42;
		else
			array7[i] = array5[i - 1];
	}

	//Printing out to verify
	for (int i = 0; i < 7; i++) {
		printf("%d ", array7[i]);
	}

	return 0;
}