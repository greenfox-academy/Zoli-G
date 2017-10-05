#include <stdio.h>
#include <stdlib.h>

/*
write a program to check whether a given number is positive or negative
*/

int main()
{
    int a = -212;

    if (a == 0) {
        printf("Value is zero, so not negative nor positive.");
    }
    else if (a > 0) {
        printf("Value is positive.");
    }
    else {
        printf("Value is negative.");
    }

    return 0;
}
