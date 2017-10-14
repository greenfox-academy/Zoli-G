#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Is the parameter sting is a palindrome? Returns 0 if not, 1 if it is!
int is_palindrom(char string[]) {
    int length = strlen(string);
    int cycles;

    //printf("%s - %d", string, strlen(string));

    switch (length % 2) {
    case 0: cycles = length / 2;
            break;
    case 1: cycles = (length - 1) / 2;
            break;
    }

    for (int i = 0; i < cycles; i++) {
        //printf("Cycle(%d): %d", cycles, i);
        //printf("%c(%d)", string[i], (int)string[i]);
        if (string[i] != string[length - i - 1])
            return 0;
    }
    return 1;
}

//Copies a substring out of the parameter string from start to end position
char* substring(char string[], int start, int end) {
    char result[64];
    //char result[end - start + 1];

    for (int i = start; i <= end; i++) {
        result[i - start] = string[i];
        //printf("%c", result[i - start]);
    }
    result[end - start + 1] = '\0';
    //printf("'%s'\n", result);
    return result;
}

/*Get palindrome substrings from a larger string
char* get_palindroms_from_string(char string[]) {
    int radius;
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        //printf("i = %d\n", i);
        radius = 1;
        while ((i - radius >= 0) && (i + radius <= length)) {
            //printf("%s", substring(string, i - radius, i + radius));
            if (is_palindrom(substring(string, i - radius, i + radius)) == 1) {
                printf("Palindrom: '%s'\n", substring(string, i - radius, i + radius));
                radius++;
            }
            else {
                //printf("Not palindrom: '%s'\n", substring(string, i - radius, i + radius));
                break;
            }
        }
    }
}*/

//Get palindrome substrings from a larger string
char* get_palindroms_from_string(char string[]) {
    int length = strlen(string);
    for (int i = 3; i <= length; i++) {             //smallest palindrom size is 3, the largest is the text itself
        for (int j = 0; j <= length - i; j++) {     //starting position is 0, ending is
            if (is_palindrom(substring(string, j, j + i - 1)) == 1) {
                printf("Palindrom(i = %d, j = %d): '%s'\n", i, j, substring(string, j, j + i - 1));
            }
            else {
                //printf("Not palindrom(i = %d, j = %d): '%s'\n", i, j, substring(string, j, j + i - 1));
            }
        }
    }
}

void main() {
    char text[] = "dog goat dad duck doodle never";
    int text_length = strlen(text);

    printf("The text is: '%s' (%d characters)\n", text, text_length);
    printf("Is the whole string a palindrome? %d\n", is_palindrom(text));

    get_palindroms_from_string(text);

    //printf("'%s'\n", substring(text, 5, 20));
}
