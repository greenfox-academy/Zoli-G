#include <stdio.h>

int main() {
    int number = 1234;
    int* number_pointer = &number;

    //TODO:
    // update the value of number variable to 42 using the "number_pointer"
    printf("The value of var 'number' through its pointer: %d\n", *number_pointer);

    *number_pointer = 42;
    printf("The value changed through the pointer: %d\n", *number_pointer);

    return 0;
}
