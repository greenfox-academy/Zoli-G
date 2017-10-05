#include <stdio.h>
#include <stdlib.h>

/*
find the greatest common divisor of the two given variables
use Euclid's algorithm, if you don't know it look it up on the internet
*/

int main()
{
    int x = 32;
    int y = 20;

    //int x = 1071;
    //int y = 462;

    int max = (x > y) ? x : y;
    int min = (x < y) ? x : y;
    int max_s;

    printf("Max: %d, min: %d.\n", max, min);

    do {
        max_s = max;
        max = min;
        min = max_s % min;
        printf("%d, %d \n", max, min);
    } while (min != 0);

    printf("%d", max);

    return 0;
}
