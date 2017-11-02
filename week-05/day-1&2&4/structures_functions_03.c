/*
 * Take the previous exercise and add a function which sorts the elements in an ascending order.
 *
 * Test it in the main function and print the results.
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
void SORT();
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

	SORT();

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

void SORT() {
	int temp = 0;
	for (int i = 0; i < arrS.level - 1; i++) {
		for (int j = 0; j < arrS.level - 1 - i; j++) {
			if (arrS.array[j] > arrS.array[j + 1]){
				temp = arrS.array[j];
				arrS.array[j] = arrS.array[j + 1];
				arrS.array[j + 1] = temp;
			}
		}
	}
}

void PRINT() {
	for (int i = 0; i < arrS.level; i++) {
		printf("%d ", arrS.array[i]);
	}
}