#include <stdio.h>

int assort_odd_elements(int *array, int size);

int main(void)
{
	int num_array[] = {8, 7, 9, 20, 3, 81, 79, 66};

    //TODO: write a function which filters out the odd elements of an integer array
    //do it in the original array
    //your return value should be the real size of the filtered array
    //print out the filtered array's elements
	int no_of_filtered_elements = 0;
	no_of_filtered_elements = assort_odd_elements(num_array, 8);

	printf("There are %d pieces of even number in the array.\n", no_of_filtered_elements);

	for (int i = 0; i < no_of_filtered_elements; i++) {
		printf("%d\n", num_array[i]);
	}

    return 0;
}

int assort_odd_elements(int *array, int size) {
	int temp_array[size];
	int counter = 0;

	//Fill the temp array with even numbers from the original array
	for (int i = 0; i < size; i++) {
		if (array[i] % 2 == 0) {
			temp_array[counter] = array[i];
			//printf("%d ", array[i]);
			counter++;
		}
	}

	for (int i = 0; i < counter; i++) {
		array[i] = temp_array[i];
	}

	return counter;
}