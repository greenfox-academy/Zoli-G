#include <stdio.h>
#include <stdlib.h>
#include "factorio.h"
// create a function called `factorio`
// that returns it's input's factorial with and without recursion
// again the parameters value should be stored in a .h file
//
int factorio(int num);
int factorio_rec(int num);

int main()
{
    printf("Factorial calculation with for: %d! = %d.\n", factorio_limit, factorio(factorio_limit));
    printf("Factorial calculation with recursion: %d! = %d.\n", factorio_limit, factorio_rec(factorio_limit));
    return 0;
}

int factorio(int num) {
    int i, result = 1;

    if (num == 1)
        return result;

    for (i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

int factorio_rec(int num) {
    if (num == 1)
        return 1;
    else
        return num * factorio_rec(num - 1);
}
