#include <stdio.h>
#include <stdlib.h>

// create a function which returns the power of a base number


int main()
{
    int base = 2;
    int power = 7;

    printf("Power function calculation: %d^%d = %d.\n", base, power, power_of_number(base, power));

    return 0;
}

int power_of_number(int base, int power) {
    int i, result = 1;

    if ((base != 0) && (power == 0))
        return 1;
    else if (base == 0)
        return 0;

    for (i = 2; i <= power; i++) {
        result *= base;
    }

    return result;
}
