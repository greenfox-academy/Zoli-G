#include <stdio.h>
#include <stdlib.h>

// write a program to find the largest number of three

int main()
{
    int a = 13;
    int b = 29;
    int c = 7;
    char maxi = "";

    if (a > b) {
        //a, b
        if (c < a) {maxi = "a";} else {maxi = "c";}
    }
    else {
        //b, a
        if (c < b) {maxi = "b";} else {maxi = "c";}
    }


    printf("Max number is %c", maxi);

    return 0;
}
