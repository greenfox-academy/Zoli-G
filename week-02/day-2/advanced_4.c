#include <stdio.h>
int main()
{
    //write a program which loads up fully a 50-sized integer array starting from 200
    //in descending order
    //but your array should contain elements which are divisible by 5 and 17
    //print out the array

    int my_array[50];
    int i = 200, id = 0;

    do {
        if ((i % 5 == 0) && (i % 17 == 0)) {
            my_array[id] = i;
            id++;
            i--;
        }
        else {
            i--;
        }
    } while (id < 50);

    for (i = 0; i < 50; i++) {
        printf("%d ", my_array[i]);
    }

    return 0;
}
