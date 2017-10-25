#include <stdio.h>

struct Pirate {
    char name[256];
    int has_wooden_leg;
    short int gold_count;
};

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns
// the sum of the golds of all pirates
int golds(struct Pirate pirates[], int size) {
    int golds_of_pirates = 0;

    for (int i = 0; i < size; i++) {
        golds_of_pirates += pirates[i].gold_count;
    }
    return golds_of_pirates;
}

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns 
// the average of the gold / pirate
float avg_golds(struct Pirate pirates[], int size) { 
    return ((float)golds(pirates, size) / size);
}

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns 
// the name of the richest that has wooden leg
char *richest_wooden_legged_pirate(struct Pirate pirates[], int size) {
    int maxgold = 0, index = -1;

    for (int i = 0; i < size; i++) {
        if (pirates[i].has_wooden_leg == 1 && pirates[i].gold_count > maxgold) {
            maxgold = pirates[i].gold_count;
            index = i;
        }
    }

    return pirates[index].name;
}

int main() {
    struct Pirate pirates[] = {
        {"Jack", 0, 18},
        {"Uwe", 1, 8},
        {"Hook", 1, 12},
        {"Halloween kid", 0, 0},
        {"Sea Wolf", 1, 14},
        {"Morgan", 0, 1}
    };

    printf("Sum of golds of all pirates: %d\n", golds(pirates, 6));
    printf("Avarage of golds of all pirates: %f\n", avg_golds(pirates, 6));
    printf("Richest wooden-legged pirate is: %s\n", richest_wooden_legged_pirate(pirates, 6));

    return 0;
}
