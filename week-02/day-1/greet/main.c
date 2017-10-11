#include <stdio.h>
#include <stdlib.h>
#include "greet.h"
// define a variable and assign the value `Greenfox` to it in a .h file
// create a function called `greet` that greets it's input parameter
// define more names to greet, call the function multiple times

void greet(char person[]);

int main()
{
    greet("Zoli");
    greet("Gergo");
    greet("Gabor");
    greet("Miki");
    return 0;
}

void greet(char person[]) {
    printf("Hello and welcome to %s dear %s!\n", PLACE, person);
    return;
}
