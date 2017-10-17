#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i_array[10] = {260, 259, 258, 257, 256, 255, 254, 253, 252, 251};
    unsigned char uc_array[10];

	//TODO: write a program, which copies the values from the given array to an unsigned char array
    //print out the elements of the unsigned char array, with the "%d" format specifier

	for (int i = 0; i < 10; i++) {
		uc_array[i] = i_array[i];
		printf("%d ", uc_array[i]);
	}

	 //what do you see?
	//Unsigned char range is 0-255. Values over 255 causing overflow event, and restarts counting from 0
    return 0;
}
