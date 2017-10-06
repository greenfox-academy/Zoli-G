#include <stdio.h>
#include <stdlib.h>

//how much odd numbers are between 179 & 371
//you should be able to change the limits, like from 10 to 234
//and the program should print out the odd numbers between those two numbers
//example from 11 to 27 the program should print out:
// 13, 15, 17, 19, 21, 23, 25 this is 7 odd number between 11 and 27

int main()
{
    int max = 371;
    int min = 179;

    int i;
    int counter = 0;
    for (i = min; i <= max; i++) {
        if (i % 2 != 0) {
            printf("%d ", i);
            counter++;
        }
    }

    printf("\nThere are %d odd numbers between %d and %d.", counter, min, max);

	return 0;
}
