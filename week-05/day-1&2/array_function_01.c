/*
 * Create a function that takes an array as argument and it's length. Determine the right data types to do this.
 * This function should order the arguments in ascending order and return this in a new sorted array.
 *
 * Create a second function that takes 3 arguments. An array, it's length and a number it is searching for.
 * The function should return the index of the number when found or -1 if it's not part of the array.
 * IMPORTANT: this function expects a sorted array and uses the strategy we used when we play guess the number.
 * 
 *
 * In the main function create an unsorted array filled with random numbers, Make it 50 long.
 * Try 2 scenarios:
 *    * In the first: You pick a random element in the unosrted array and check at which index it is after the array is sorted.
 *    * In the second: You pick a number You are sure is not in the array. Check whether the search function returns the right number.
 * Print out what You need to check these.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short **SortArray(short *array[], unsigned char length);
void PrintArray(short *array[], unsigned char length);
signed char ArraySearch(short *array[], unsigned char length, short num_to_search);

int main() {

	//Defining array
	short numbers[50];

	//Pointer array to numbers
	short *p_array[50];

	//Fill array with random numbers and connect pointer array
	srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		numbers[i] = rand() % 200;
		p_array[i] = &numbers[i];
	}

	//Print original array
	printf("Original array:\n");
	for (int i = 0; i < 50; i++) {
		printf("%d ", numbers[i]);
	}

	//Print sorted array
	PrintArray(SortArray(p_array, 50), 50);

	//Search for a rundom number in the sorted array
	short num_to_search = rand() % 200;
	printf("\nLooking for %d in the sorted array. The found index is: [%d].\n", num_to_search, ArraySearch(SortArray(p_array, 50), 50, num_to_search));
	
	return 0;
}

//Sorting the num array in a way that the original array is intact (returns pointer array)
short **SortArray(short *array[], unsigned char length) {
	short *temp;

	for (int i = 0; i <= length - 2; i++) {
		for (int j = 0; j <= length - 2 - i; j++) {
			if (*array[j] > *array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	return array;
}

void PrintArray(short *array[], unsigned char length) {
	printf("\nSorted array:\n");
	for (int i = 0; i < length; i++) {
		printf("%d ", *(array[i]));
	}
	printf("\n");
}

signed char ArraySearch(short *array[], unsigned char length, short num_to_search) {
	for (int i = 0; i < length; i++) {
		if (*array[i] == num_to_search) {
			return i;
		}
	}
	return -1;
}