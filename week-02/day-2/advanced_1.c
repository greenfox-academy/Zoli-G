#include <stdio.h>

int main()
{
    int arr[50];
    int arr_size;

    // TODO: write a program which asks for a number, that will be the real size of the array (50 elements are allocated, that's the maximum size)
    printf("Enter size for array (<= 50): ");
    scanf("%d", &arr_size);

    // Then load up the array with integer values
    int i;
    for (i = 0; i < arr_size; i++) {
        arr[i] = i * 2;
    }

	// print out the array
	printf("Array: (%d element)\n", arr_size);
	for (i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    // Then ask for a number, that will be the position, where you want the element to be deleted
    // handle the problem when trying to delete from invalid positions (e.g. negative number)
    int del_id;
    do {
    printf("\n\nEnter array ID to delete element (1 to %d): ", arr_size);
    scanf("%d", &del_id);
    } while ((del_id > arr_size) || (del_id < 0));

    //deleting element
    for (i = del_id - 1; i < arr_size; i++) {
        arr[i] = arr[i + 1];
    }

    // print out the the array after the deleting
    printf("\nNew array after deleting element:\n");
    for (i = 0; i < arr_size - 1; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    return 0;
}
