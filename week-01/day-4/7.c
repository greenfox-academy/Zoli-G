#include <stdio.h>
#include <stdlib.h>

/*
create a simple program which checks if the num is odd or even
*/

int main()
{
    int num;
    num = 13;

    if (num % 2 == 0) printf("Even number.");
    else printf("Odd number.");

    return 0;
}
