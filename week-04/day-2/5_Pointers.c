#include <stdio.h>

int main() {
    int numbers[] = {5, 6, 7, 8, 9};
    int* number_pointer = &numbers[0];

    //TODO:
    // The "number_pointer" should point to the third element of the array called "numbers",
    // than please print its value with it. Solve the problem without reusing the "&" operator
    // for geting the address of the third element.
    number_pointer = &numbers[2];

    printf("Third element: %d\n", *number_pointer);

    number_pointer = numbers;

    printf("Third element without using array brackets: %d\n", *(number_pointer + 2));

    return 0;
}
