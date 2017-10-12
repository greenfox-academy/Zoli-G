#include <stdio.h>
#include <stdlib.h>

void bubble_sort(char string[], int size);

int fullsize = 0;

void main() {
    printf("Anagram checker program\n");
    printf("-----------------------\n\n");

    char string_a[] = "hellobello";
    char string_b[] = "leolheollb";

    int size_a = sizeof(string_a) / sizeof(char);
    int size_b = sizeof(string_b) / sizeof(char);

    printf("Elements of string a is %d, of b is %d.\n\n", size_a, size_b);

    if (size_a == size_b) {
        printf("Length of strings match, computing similarity is on progress...\n\n");
        fullsize = size_a;
    }
    else {
        printf("Length of strings does not match, so these cannot be anagrams of each other. Program terminates.\n\n");
        exit(0);
    }

    printf("String A: %s, ", string_a);
    bubble_sort(string_a, fullsize-1);
    printf("sorted: %s.\n", string_a);

    printf("String B: %s, ", string_b);
    bubble_sort(string_b, fullsize-1);
    printf("sorted: %s.\n", string_b);

    if (strcmp(string_a, string_b) == 0)
        printf("\n\nThese are anagrams!\n\n");
    else
        printf("\n\nThese are not anagrams!");
}

void bubble_sort(char string[], int size) {
    int temp;
    for (int i = size; i > 1; i--) {
        for (int j = 0; j < i - 1; j++) {
            //printf("Comparing %c (%d) and %c (%d).\n", string[j], (int)string[j], string[j + 1], (int)string[j + 1]);
            if ((int)string[j] > (int)string[j + 1]) {
                //printf("Switching %c and %c.\n", string[j], string[j + 1]);
                temp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = temp;
            }
        }
    }
}
