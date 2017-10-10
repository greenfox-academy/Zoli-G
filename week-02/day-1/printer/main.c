#include <stdio.h>
#include <stdlib.h>
#include "printer.h"
// Create a function called `printer`
// which prints the input parameters
// can have multiple number of arguments
// store your variables in a .h file

void printer(char* book_title, int book_year, float book_price);

void main()
{
    printer(TITLE, YEAR, PRICE);
    return;
}

void printer(char* book_title, int book_year, float book_price) {
    printf("The book '%s', which published in %d has a price of $%.2f.\n", book_title, book_year, book_price);
    return;
}
