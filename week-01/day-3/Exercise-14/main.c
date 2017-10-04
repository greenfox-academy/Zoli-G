#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t number = 254;
	uint8_t result;

	result = number + 23;

	// Check the result with printf
    printf("The result is: %d\n", result);

 	// What happened?!
 	printf("uint8_t owerflow happens when I add 23 to 254! 8-bit numbers, huh?\n");

	// Try again with different datatype
	uint16_t result_16 = number + 23;

	// Check the result with printf
    printf("With 16-bit number, the result is: %d\n", result_16);

	// What happened and why?
	printf("Owerflow can happen more often with 8-bit numbers, use 16-bit if necessary!\n");

	//----------------------------------------
	int8_t number_negative = number;

	// Check the result with printf
    printf("The value of 254 is represented with signed 8-bit integer format is: %d\n", number_negative);

	// What happened and why?
	printf("A number is represented differently by assigning it to signed/unsigned variable!");
    return 0;
}
