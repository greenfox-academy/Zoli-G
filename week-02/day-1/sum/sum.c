#include <stdio.h>
#include <stdlib.h>
#include "sum.h"
// Write a function called `sum` that sum all the numbers
// until the given parameter which you store in a .h file

int main()
{
    printf("The sum of numbers till %d is %d.", limit, sum(limit));
    return 0;
}

int sum(int number) {
    int i, result = 0;
    for (i = 1; i <= number; i++) {
        result += i;
    }
    return result;
}
