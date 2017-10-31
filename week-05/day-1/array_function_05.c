/*
 * Take this array of characters: "2319834571976548721b1992456t831977451963782"
 * Create a function that takes an array of characters as the input. (Test it with the one above).
 * It should return an array of integers. Each representing a valid birthdate year extracted from
 * the string of characters. (A valid boirthyear is either 19??, 20?? or 21??)
 * The 0th element of the returned array should be the number of valid birthyears found. Then there should be 
 * the birthyears in each element.
 *
 * Create a main function to test this and print out the birthyears in a new line each.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int *birthyearsSearch(char text[]);

int main() {

	char years[] = "2319834571976548721b1992456t831977451963782";

	int *found = birthyearsSearch(years);

	printf("%d years found in text: ", *found);
	for (int i = 1; i < *found + 1; i++) {
		printf("%d ", *(found + i));
	}

	return 0;
}

int *birthyearsSearch(char text[]) {
	char *p;

	//Temp storage for years in text
	char year[5];
	//Pointer moving in text
	p = text;

	//Function return array is always pointer
	int* result;
	//Allocate memory to form an array
	result = malloc(strlen(text) * sizeof(int));

	//Counter to count the occurrances
	int counter = 0;

	//Do while substring is found from the actual memory position (p)
	while (strstr(p, "19") != NULL) {
		//Set the actual position in the memory, before the found year (4 char)
		p = strstr(p, "19");
		//Saving the first 4 digit in string 
		strncpy(year, p, 4);
		//Set the null char after string just in case
		year[5] = '\0';
		//If the last two char is not a number than it is not a year so jump to the next loop
		if (isdigit(year[2]) == 0 || isdigit(year[3] == 0)) {continue;}
		//Save number in the return array (reserved the 0th element)
		*(result + 1 + counter) = atoi(year);
		//Shift pointer position after the saved number
		p += 4;
		//Increase counter after successfully found a new year
		counter++;
	}
	//The 0th element is the occurrances
	*result = counter;

	return result;
}