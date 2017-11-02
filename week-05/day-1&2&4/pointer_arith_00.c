/*
 * Check out the following code.
 * Read it for Yourself, decode what is happening here.
 *
 */

#include <stdio.h>

int main(){
    //Fill integer array
    int integers[] = {12,23,34,45,56,67,78,89,90};

    //Make a pointer to array
    int* apointer = integers;

    //Print out pointer mem address and value
    printf("address\t\tvalue\n%p\t%d\n",apointer, *apointer);

    //Pointer to the 4th element
    apointer+=3;

    //Print out 4th element mem address and value
    printf("%p\t%d\n",apointer, *apointer);
    printf("-------------------------------\n\n");

    //Print first 9 element of array through pointer
    for(int* ptr = integers; ptr-integers < 9; ptr++){
        printf("%p\t%d\n", ptr, *ptr);
    }
    return 0;
}