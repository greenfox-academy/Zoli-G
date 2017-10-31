/*
 * Create an array of integers. Make it 10 long at least. Fill it up with numbers - random or toherwise - as You wish.
 * Iterate over this array using a pointer. Print out it's elements.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {

	int array[] = {2,56,78,45,10,3,0,6,88,55};

	int *p = array;

	for(int* ptr = p; ptr - p < (sizeof(array) / sizeof(int) ); ptr++){
        printf("%p\t%d\n", ptr, *ptr);
    }

	return 0;
}