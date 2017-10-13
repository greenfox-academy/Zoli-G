#include <stdio.h>
#include <stdlib.h>

void bubble_sort(char string[]);

void main() {

    char string_a[] = "railsafety";
    char string_b[] = "fairytales";

    printf("Anagram checker program\n");
    printf("-----------------------\n\n");

    int size_a = strlen(string_a);
    int size_b = strlen(string_b);

    printf("Elements of string a is %d, of b is %d.\n\n", size_a, size_b);

    if (size_a == size_b) {
        printf("Length of strings match, computing similarity is on progress...\n\n");

    }
    else {
        printf("Length of strings does not match, so these cannot be anagrams of each other. Program terminates.\n\n");
        exit(0);
    }

    printf("String A: %s, ", string_a);
    bubble_sort(string_a);
    printf("sorted: %s.\n", string_a);

    printf("String B: %s, ", string_b);
    bubble_sort(string_b);
    printf("sorted: %s.\n", string_b);

    if (strcmp(string_a, string_b) == 0)
        printf("\n\nThese are anagrams!\n\n");
    else
        printf("\n\nThese are not anagrams!");
}

void bubble_sort(char string[]) {
    int temp;
    int size = strlen(string);
    //printf("Size: %d", size);
    for (int i = 0; i < size - 1; i++) {
        //printf("Pass %d\n", i);
        for (int j = 0; j < size - 1 - i; j++) {
            //printf("Comparing %c (%d) and %c (%d).\n", string[j], (int)string[j], string[j + 1], (int)string[j + 1]);
            if (string[j] > string[j + 1]) {
                //printf("Switching %c and %c.\n", string[j], string[j + 1]);
                temp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = temp;
            }
        }
    }
}
