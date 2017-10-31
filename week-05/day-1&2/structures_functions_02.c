/*
 * Create a structure to represent a list of numbers.
 * The structure should know how many nuber it has stored.
 * Store the numbers in an array.
 * Create functions to:
 *    * Add a new number at the end.
 *    * Get a number at a given index.
 *    * Replace a number at a given index if it exists.
 *
 * If the array is too smal, create a new one, copy everything into it, add the new element and delete the old array.
 *
 * Test in the main function whether everything works.
 */
#include <stdio.h>
#include <stdlib.h>

struct ArrayStorage {
	int level;		//How many items are in the array
	int array[];	//Flexibel sized array is at the end of the struct
};

struct ArrayStorage arrS;

int ADD(int num);
int GETNUM(int index);
int REPLACE(int index, int num);

int main()
{
	ADD(5);ADD(45);ADD(23);ADD(122);ADD(0);

	for (int i = 0; i < arrS.level; i++) {
		printf("%d ", arrS.array[i]);
	}

	int g = GETNUM(2);
	printf("\nThe number at index is %d.\n", g);

	int f = REPLACE(4, 56);

	for (int i = 0; i < arrS.level; i++) {
		printf("%d ", arrS.array[i]);
	}

	return 0;
}

int ADD(int num) {
	arrS.array[arrS.level] = num;
	arrS.level++;
}

int GETNUM(int index) {
	if (index > arrS.level) {
		printf("Index not in range.\n");
		return -1;
	}
	return arrS.array[index];
}

int REPLACE(int index, int num) {
	if (index > arrS.level) {
		printf("Index not in range.\n");
		return -1;
	}
	arrS.array[index] = num;
	return 0;
}