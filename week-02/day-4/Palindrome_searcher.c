#include <stdio.h>
#include <stdlib.h>

//Is the parameter sting is a palindrome? Returns 0 if not, 1 if it is!
int is_palindrom(char* string) {
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
        if ((int)string[i] != (int)string[length - i - 1])
            return 0;
    }
    return 1;
}

//Copies a substring from the parameter string from start to end position
char* substring(char* string, int start, int end) {
    char* result[end - start + 2];

    for (int i = start; i <= end; i++) {
        result[i] = string[i];
        printf("%c", result[i]);
    }
    result[end - start + 2] = '\0';
    return result;
}

//Get palindrome substrings from a larger string
char* get_palindroms_from_string(char* string, int length) {
    int radius;
    for (int i = 0; i < length; i++) {
        printf("i = %d\n", i);
        radius = 1;
        while ((i - radius >= 0) && (i + radius <= length)) {
            //printf("%s", substring(string, i - radius, i + radius));
            if (is_palindrom(substring(string, i - radius, i + radius)) == 1) {
                printf("%s\n", substring(string, i - radius, i + radius));
                radius++;
            }
            else {
                printf("%s\n", substring(string, i - radius, i + radius));
                break;
            }
        }
    }
}

void main() {
    char text[] = "dog god is\0";
    int text_length = strlen(text);

    printf("The text is: '%s' (%d characters)\n", text, text_length);
    printf("Is the string '%s' a palindrome? %d\n", text, is_palindrom(text));

    printf("Substring: %s\n", substring(text, 2, 8));

    //get_palindroms_from_string(text, text_length);
}
