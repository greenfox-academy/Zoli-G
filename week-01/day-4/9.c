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

    switch (num1 > num2) {
        case 0:
            printf("Num1 is less than num2.\n");
            break;
        case 1:
            printf("Num1 is greater than num2.\n");
            break;
    }

    return 0;
}
