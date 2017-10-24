#include <stdio.h>
#define MAX_CHARS 255 // Maximum characters allowed

char char_frequency(char *string, int *output_freq);

int main()
{
    //TODO: write a function which finds the maximum occurrence of a character in a given string.
    //return with the most frequent character
    //the number of occurrence should be an output parameter

    char str[] = "e is the most frequent element.";

    char most_frequent_letter;
    int frequency_of_letter = 0;

    most_frequent_letter = char_frequency(str, &frequency_of_letter);

    printf("The most frequent character is '%c' and it occurrence id %d in the string.\n", most_frequent_letter, frequency_of_letter);
    return 0;
}

char char_frequency(char *string, int *output_freq) {
	int charmap[256];

	printf("String: '%s', length: %d.\n", string, strlen(string));

	//Zero out the new array values
	for (int i = 0; i < 256; i++) {
		charmap[i] = 0;
	}

	//Fill the character map: ex: if we found an 'a' char, then let's increase the map[64]
	for (int i = 0; i < strlen(string); i++) {
		charmap[string[i]]++;
	}

	//Let's search for the max values
	int max = 0, max_counter = 0;
	for (int i = 0; i < 256; i++) {
		if (max < charmap[i]) {
			max_counter = i;
			max = charmap[i];
		}
	}

	*output_freq = max;
	return max_counter;
}