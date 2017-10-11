#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// create a function which returns a Fibonacci number like in the example code
// this time do it with memoization
// again the parameters value should be stored in a .h file

void print_fib(int f) {
    for (int i = 1; i < f + 1; i++) {
        printf("%d ", MEMO[i]);
    }
}

long long int fibonacci(int number)
{
    long long int f;
    if ((number == 1) || (number == 2)) {
        MEMO[number] = 1;
        return 1;
    }
    else if (MEMO[number] != 0)
        return MEMO[number];
    else
        f = fibonacci(number - 1) + fibonacci(number - 2);
        MEMO[number] = f;
        return f;
}

int main()
{
    int f;
    do {
        printf("\n\n");
        printf("Fibonacci series calculator\n");
        printf("---------------------------\n\n");
        printf("Enter Fibonacci parameter or 0 to exit: ");

        scanf("%d", &f);

        fibonacci(f);

        print_fib(f);
    } while (f != 0);

    return 0;
}
