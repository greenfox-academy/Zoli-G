#include <stdio.h>
#include <stdlib.h>

/*
swap the values of the two number
print out first the original values then print out the swaped values
but this time use bitwise operators only
*/

int main()
{
    int x = 32;
    int y = 20;

    printf("Original - x = %d, and y= %d \n", x, y);

    //XOR swap algorithm
    //X := X XOR Y
    //Y := Y XOR X
    //X := X XOR Y

    x = x ^ y;
    y = y ^ x;
    x = x ^ y;

    printf("Swapped - x = %d, and y= %d \n", x, y);
    printf("Yay! No need an addition variable to save a value.\n");

    return 0;
}
