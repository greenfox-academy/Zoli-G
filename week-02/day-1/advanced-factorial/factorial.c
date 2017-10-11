#include <stdio.h>
#include <stdlib.h>

// create a function to calculate factorial of a number using recursion


int main()
{
    int number = 7;

    printf("Factorial calculation: %d! is %d.\n", number, factorial_recursive(number));

    return 0;
}

int factorial_recursive(int num) {
    if (num == 1)
        return 1;
    else if (num == 0)
        return 0;
    else if (num < 0)
        return -1;      //Error
    else
        return num * factorial_recursive(num - 1);
}
