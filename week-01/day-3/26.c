#include <stdio.h>
#include <stdlib.h>

/*
swap the values of the to number
print out first the original values then print out the swapped values
*/

int main()
{
    int x = 32;
    int y = 20;

    printf("Original - x = %d, and y = %d \n", x, y);

    //At regular swap I need an extra variable to save one value.
    int temp;

    temp = x;
    x = y;
    y = temp;

    printf("Swapped - x = %d, and y = %d \n", x, y);
    printf("Success! But I needed a temp variable to do this.\n");

    return 0;
}
