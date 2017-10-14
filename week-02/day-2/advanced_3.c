#include <stdio.h>
#include <math.h>

int arr[20];
int freq[20];

int arr_size;

void del_element_from_freq(int num) {
    int i;
    for (i = num; i < arr_size; i++) {
        freq[i] = freq[i + 1];
    }
    arr_size--;
}

int main()
{
    // TODO: write a program which asks for a number, that will be the real size of the array
     //(20 elements are allocated, that's the maximum size)

    do {
        printf("Enter size for array (<= 20): ");
        scanf("%d", &arr_size);
    } while ((arr_size > 20) || (arr_size < 2));

    // Then load up the array with integer values
    int i;
    for (i = 0; i < arr_size; i++) {
        arr[i] = sin(i * 5) * 4;
        printf("%d ", arr[i]);
    }

    // Fill up unique array
    for (i = 0; i < arr_size; i++) {    //copy arr to freq
        freq[i] = arr[i];
        //printf("%d ", freq[i]);
    }
    printf("(Array size is %d.)\n", arr_size);

    i = 0;
    int j = 1;
    int element_to_check;

    while (i < arr_size) {
        element_to_check = freq[i];
        while (j < arr_size) {
            if (freq[j] == element_to_check) {
                del_element_from_freq(j);
                //printf("%d = %d del\n", element_to_check, freq[j]);
            }
            else {
                j++;
                //printf("%d <> %d pass\n", element_to_check, freq[j]);
            }
        }
        i++;
        j = i + 1;
        //printf("%d", i);
    }

    printf("\nUnique array:\n");
    for (i = 0; i < arr_size; i++) {    //print freq
        printf("%d ", freq[i]);
    }
    printf("(Array size: is %d.)\n", arr_size);

    return 0;
}
