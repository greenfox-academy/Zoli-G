#include <stdio.h>

void print_array(int *array, int size);

int main()
{
	int a[] = {6, 8, 48, 1, -9, 89};

	//TODO: write a function, which prints out the passed array's elements.
	print_array(a, sizeof(a) / sizeof(int));	//sizeof(a) / sizeof(int)

	return 0;
}

void print_array(int *array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d \n", *(array + i));
	}
}