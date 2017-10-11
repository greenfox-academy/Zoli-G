#include <stdio.h>
#include <stdlib.h>
#include "gcd.h"
// create a function to find the greatest common divisor of two numbers (a and b)
// again the parameters value should be stored in a .h file
// use recursion

int gcd_recursive(int num1, int num2);

int main() {
    //int a = 20;
    //int b = 12;

    printf("The greatest common divisor of %d & %d is %d.\n", A, B, gcd_recursive(A, B));
    //printf("The greatest common divisor of %d & %d.\n", A, B);

    return 0;
}

int gcd_recursive(int num1, int num2) {
    //https://en.wikipedia.org/wiki/Euclidean_algorithm
    if (num2 == 0)
        return num1;
    else
        return gcd_recursive(num2, num1 % num2);
}
