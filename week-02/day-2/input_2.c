#include <stdio.h>

int main() {
    char buffer[255];   // Buffer variable for user input

    //TODO:
    // Get the user's name with gets
    printf("Please enter your name: ");
    gets(buffer);

    //TODO:
    // Print it out with puts
    printf("\n\nHello ");
    puts(buffer);

    //TODO:
    // Get the user's pet name with getch
    printf("\n\nWhat's your pets name?: ");
    int ch, i = 0;
    char petname[255];

    do {
        ch = getch();
        petname[i] = ch;
        printf("%c", ch);
        i++;
    } while (ch != 13);

    petname[i - 1] = 0;

    //TODO:
    // Print it out
    printf("\nYour pets name is %s.\n", petname);

    return 0;
}
