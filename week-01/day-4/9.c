#include <stdio.h>
#include <stdlib.h>

/*
write a program that decides which number is bigger
use switch-statement
*/

int main()
{
    int num1;
    int num2;

    num1 = 85;
    num2 = 96;

    float diff = num1 / num2;
    int diff_digit = diff;

    //printf("%d\n", diff_digit);

    switch (diff_digit) {
        case 0 :
            printf("Num1 is less than num2.\n");
            break;
        case 1 :
            printf("Num1 is greater than num2.\n");
            break;
    }

    return 0;
}
