#include <stdio.h>

int main()
{
    int arr[20];
    int freq[20];

    // TODO: write a program which asks for a number, that will be the real size of the array
     //(20 elements are allocated, that's the maximum size)
    int arr_size;
    printf("Enter size for array (<= 20): ");
    scanf("%d", &arr_size);

    do {
        printf("\n\nEnter array ID to delete element: ");
        scanf("%d", &del_id);
    } while ((del_id > arr_size) || (del_id < 0));

    // Then load up the array with integer values
    // Finally print all unique elements in array


    return 0;
}
