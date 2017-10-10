#include <stdio.h>
#include <stdlib.h>
#include "double.h"
// create a function called `doubling` that doubles it's input parameter
// again the parameters value should be stored in a .h file

int main()
{
    printf("The double value of %d is %d.\n", double_par, doubling(double_par));
    return 0;
}

int doubling() {
    return double_par * 2;
}
