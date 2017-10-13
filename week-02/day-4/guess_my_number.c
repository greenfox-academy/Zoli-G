#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lives = 5;

void init() {
    printf("Guess My Number\n");
    printf("===============\n\n");

    printf("\tIn this game you'll need to guess a number which was already calculated by this computer.\n\tYou can choose the range between 20 and 100.\n\tDon't forget to be brave!\n");
    printf("\t-----------------------------------------------------------------------------------------\n\n");
}

int enter_range() {
    printf("\tI will think a number between 0 and a number you can enter.\n\n");
    int range;
    while (range < 20 || range > 100) {
        printf("\tEnter range (20 - 100): ");
        scanf("%d", &range);
    }
    return range;
}

int randomize(int max) {
    int min = 0;
    srand(time(NULL));
    return (rand() % (max + 1 - min)) + min;
}

void ask_for_number(int range, int number_guessed) {
    int shot;
    if (lives == 0) {
        printf("\n\n\tSorry your game is over. Better luck next time!\n\tThe guessed number was %d.\n", number_guessed);
        //restart();
        exit(0);
    }
    printf("\n\tEnter your guess (%d tries to go): ", lives);
    scanf("%d", &shot);
    if (shot > range || shot < 0 ) {
        printf("\tNot in range! (0 - %d)", range);
        return ask_for_number(range, number_guessed);
    }
    else {
        if (shot < number_guessed) {
            printf("\t\t\t\t\t\tToo low! Think of a higher number.");
            lives--;
            return ask_for_number(range, number_guessed);
        }
        else if (shot > number_guessed) {
            printf("\t\t\t\t\t\tToo high! Think of a lower number.");
            lives--;
            return ask_for_number(range, number_guessed);
        }
        else {
            printf("\t\t\t\t\t\tBang! You guessed right!");
        }
    }

}

/*
void restart() {
    printf("Do you want to try your luck again? Press ENTER to play or ESC to exit.");
    char key;
    do {
        key = getch();
        printf("'%d' ", key);
    } while ((key == 13) || (key == 27));

    switch (key) {
    case 13: main();
             break;
    case 27: exit(0);
             break;
    }
}
*/

void main() {
    init();
    int range = enter_range();
    int number_guessed = randomize(range);
    //printf("%d", number_guessed);
    ask_for_number(range, number_guessed);

}
