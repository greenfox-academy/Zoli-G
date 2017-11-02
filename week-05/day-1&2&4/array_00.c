#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 * Create an array of 5 integers.
 * Fill it with random integer numbers.
 * Print out the array elements in one line, divided by " | ".
 * Reverse the order of the numbers _in_the_array_ an print them out again.
 */

int main() {
  
	//Creating array
	int array[5], temp = 0;

	//Called once for random generation
	srand(time(NULL));
 
 	//Filling out array with random numbers and printing out them wit pipes
	for (int i = 0; i < 5; i++) {
		array[i] = rand() % 101;
		printf("%d", array[i]);
		if (i != 4) printf("|");
	}

	//Reversing array using a temp var.
	for (int i = 0; i <= 1; i++) {
		temp = array[i];
		array[i] = array[4 - i];
		array[4 - i] = temp;
	}

	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("%d", array[i]);
		if (i != 4) printf("|");
	}


	return 0;
}