/*
 * Use the union type we've defined below to write out the integer array nums 
 * as if it was an array of characters;
 * Use pointer arithmethircs to iterate over the array with the ptr.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef union {
    int *asInt;
    unsigned char *asChar;
} ptr;

//1952540759
//01110100 01100001 01101000 01010111
//   116      97      104      87     
int main(){
    int nums[] = {1952540759, 544171040, 1685221239, 1869573152, 1768693867, 1847616875, 1700949365, 4158322};

    ptr X;

    X.asInt = &nums[0];

    //It's possible to access the integers in 1 bytes chunks: 10 digit num stored in 4 bytes
	printf("%d-%d-%d-%d\n", X.asChar[3], X.asChar[2], X.asChar[1], X.asChar[0]);

    return 0;
}