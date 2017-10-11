#include <stdio.h>
#include <math.h>
/*
Write a program where you have five functions
first the program should ask for an integer, then
these functions should do various mathematical operations on a given integer
last but not least there should be a variable which counts how many operations
have been done on the given integer
*/
int counter = 0;

int add_5(int num) {
    counter++;
    return num + 5;
}

int half_if(int num) {
    counter++;
    if (num % 2 == 0)
        return num / 2;
    else
        return num;
}

int multi_if(int num) {
    counter++;
    if (num <= 10)
        return num * 2;
    else
        return num;
}

int pi(int num) {
    counter++;
    return num * 3.1415;
}

int logar(int num) {
    counter++;
    return log10(num);
}

int main() {
    int num;

    printf("Please enter number to calculate: ");
    scanf("%d", &num);
    printf("%d. step: %d.\n", counter, logar(num));
    printf("%d. step: %d.\n", counter, pi(num));
    printf("%d. step: %d.\n", counter, multi_if(num));
    printf("%d. step: %d.\n", counter, half_if(num));
    printf("%d. step: %d.\n", counter, add_5(num));

    return 0;
}
