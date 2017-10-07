#include <stdio.h>
#include <stdlib.h>

// write a program to find the largest number of three

int main()
{
    int a = 13;
    int b = 29;
    int c = 7;

    int max = 0;

    if (a > b) {
        //a, b
        if (c < a) max = 1;
        else max = 3;
    }
    else {
        //b, a
        if (c < b) max = 2;
        else max = 3;
    }

    if (max == 1) printf("Max number is %d", a);
    if (max == 2) printf("Max number is %d", b);
    if (max == 3) printf("Max number is %d", c);

    return 0;
}
