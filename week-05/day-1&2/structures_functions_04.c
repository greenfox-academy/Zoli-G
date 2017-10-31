/*
 * Extend the previous exercise by adding a function that sorts the numbers in a 
 * descending order. This function should take the Structure as the first argument as well.
 *
 * Create an enum whit two values: SORT_ASC, SORT_DESC.
 * Create a functions which takes the structure as the first argument and takes the enum as the second and sorts the
 * elements in the structure accordingly, using the other two functions.
 *
 * Test them in the main function. Demonstrate they work.
 */
#include <stdio.h>
#include <stdlib.h>

struct ArrayStorage {
	int level;		//How many items are in the array
	int array[];	//Flexibel sized array is at the end of the struct
};

struct ArrayStorage arrS;

typedef enum {SORT_ASC, SORT_DESC} sortorder;

int ADD(int num);
int GETNUM(int index);
int REPLACE(int index, int num);
void univSORT(struct ArrayStorage *as, sortorder so);
void PRINT();

int main()
{
	ADD(5);ADD(45);ADD(23);ADD(122);ADD(0);

	printf("\nOriginal array: ");
	PRINT();

	int g = GETNUM(2);
	printf("\nThe number at index is %d.\n", g);

	int f = REPLACE(4, 56);

	printf("\nReplaced array: ");
	PRINT();

	univSORT(&arrS, SORT_DESC);

	printf("\nSorted array: ");
	PRINT();

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

void PRINT() {
	for (int i = 0; i < arrS.level; i++) {
		printf("%d ", arrS.array[i]);
	}
}

//Bubble sort asc, desc according to the parameter
void univSORT(struct ArrayStorage *as, sortorder so) {
	int temp = 0;

	for (int i = 0; i < (*as).level - 1; i++) {
		for (int j = 0; j < (*as).level - 1 - i; j++) {
			if ( so == SORT_DESC ? ((*as).array[j] < (*as).array[j + 1]) : ((*as).array[j] > (*as).array[j + 1]) ){
				temp = (*as).array[j];
				(*as).array[j] = (*as).array[j + 1];
				(*as).array[j + 1] = temp;
			}
		}
	}
}

