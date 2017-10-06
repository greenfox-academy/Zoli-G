#include <stdio.h>
#include <math.h>
/*
Create a program which prints out oll the prime numbers
aslo add a feature where you can tell the from - to limits
for example :
from = 11;
to = 34;
output :
13, 17, 19, 23, 29, 31 , this is 6 prime numbers
*/

void main()
{
    int from;
    int to;

    printf("---Prime number finder---\n");
    printf("Enter lower limit: ");
    scanf("%d", &from); //from = 13;
    printf("\nEnter upper limit: ");
    scanf("%d", &to); //to = 31;
    printf("\n");

    int i, j;
    int limit;

    for (i = from; i <= to; i++) {
        limit = sqrt(i);
        for (j = 2; j <= limit; j++) {
            if (i % j == 0) {
                break;
            } else if ((i % j != 0) && (j == limit)) {
                printf("%d ", i);
            }
        }
    }
    return 0;
}
