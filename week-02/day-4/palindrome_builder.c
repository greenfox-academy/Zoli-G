#include <stdio.h>
#include <stdlib.h>

char* create_palindrom(char* text) {
    int size = strlen(text);

    char text2[size];

    for (int i = 0; i < size; i++) {
        text2[i] = text[size - i - 1];
        //printf("%c", text2[i]);
    }

    text2[size] = '\0';

    return strcat(text, text2);
}

int main() {
    char word[50];
    char word_size = 0;

    printf("Palindrom maker program\n");
    printf("-----------------------\n\n");

    printf("Enter string to make palindrom: ");
    scanf("%s", &word);

    printf("\nPalindrom: %s.\n", create_palindrom(word));

    return 0;
}
