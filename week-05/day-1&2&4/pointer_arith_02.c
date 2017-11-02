/*
 * Create an array of integers. Make it 16 long. Fill itnup with numbers as You wish. Print them out.
 *     * Iterate over it with a pointer so, that You only get to each _second_ element. Print out only these.
 *     * Iterate over it only touching each _fourth_ element. Print out only these.
 *     * Iterate over it only touching each _eighth_ element. Print out only these.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {

	int array[] = {2,56,78,45,10,3,0,6,88,55,22,34,10,23,78,89};

	for (int i = 0; i < 15; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	int *p = array;

	for(int* ptr = p; ptr - p < (sizeof(array) / sizeof(int) ); ptr += 2) {
        printf("%d ", *ptr);
    }
    printf("\n");

	for(int* ptr = p; ptr - p < (sizeof(array) / sizeof(int) ); ptr += 4) {
        printf("%d ", *ptr);
    }
    printf("\n");

	for(int* ptr = p; ptr - p < (sizeof(array) / sizeof(int) ); ptr += 8) {
        printf("%d ", *ptr);
    }
    printf("\n");

	return 0;
}