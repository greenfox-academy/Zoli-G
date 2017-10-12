#include <stdio.h>
#include <stdlib.h>

char* create_palindrom(char* text, int size) {
    char palindrom[size * 2];

    for (int i = 0; i < size; i++) {
        palindrom[i] = text[i];
        //printf("%c", palindrom[i]);
    }

    for (int i = size; i < size * 2; i++) {
        palindrom[i] = text[size * 2 - i - 1];
        //printf("%c", palindrom[i]);
    }
    //printf("size: %d", size*2);
    palindrom[size * 2] = '\0';
    //printf("Size of palindrom: %d", strlen(palindrom));
    return palindrom;
}

void main() {
    char word[50];
    char word_size = 0;

    printf("Palindrom maker program\n");
    printf("-----------------------\n\n");

    printf("Enter string to make palindrom: ");
    scanf("%s", &word);

    word_size = strlen(word);

    //printf("%s - %d\n", word, word_size);
    char p[word_size * 2];
    strcpy(p, create_palindrom(word, word_size));
    printf("\nPalindrom: %s.\n", p);

}
