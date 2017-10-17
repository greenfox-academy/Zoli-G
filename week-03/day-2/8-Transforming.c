#include <stdio.h>
#include <stdlib.h>

void transform(char str[], int original_base, int new_base);

//TODO: write a program, which transforms a number from a number system to another.
//use the stdlib.h functions, and take care of error handling (see the reference)
//the transform() function should print out the result.

int main()
{
    char str[20];
    int original_base;
    int new_base;

    printf("Give me a number to transform it in an other system: ");
    scanf("%s", str);
    printf("Give me the original base: ");
    scanf("%d", &original_base);
    printf("Give me the number of the new base: ");
    scanf("%d", &new_base);

    transform(str, original_base, new_base);
    return(0);
}

void transform(char str[], int original_base, int new_base) {
    char *p, maxch = 0;
    char buffer[20];
    long int temp;

    for (int i = 0; i < strlen(str); i++) {
        switch (str[i]) {
            case 0 ... 47:
            case 58 ... 64:
            case 91 ... 96:
            case 123 ... 255: printf("\n\t[Error] Invalid character - out of range [0-9] and [a..zA..Z].\n");
                              exit(0);
            case 48 ... 57: maxch = str[i] - 48;
                            break;
            case 65 ... 90: maxch = str[i] - 55;
                            break;
            case 97 ... 122: maxch = str[i] - 87;
                             break;
            default: printf("\n\t[Error] Unknown character! Program terminates.\n");
                     exit(0);
        }
    }
    //printf("\n\tThe base of the number is at least %d.", maxch + 1);

    if (original_base < 2 || original_base > 36) {
        printf("\n\t[Error] The original base should be between 2 and 36.\n\n");
        exit(0);
    }
    else if (new_base < 2 || new_base > 36) {
        printf("\n\t[Error] The new base should be between 2 and 36.\n\n");
        exit(0);
    }
    else if (maxch > original_base - 1) {
        printf("\n\tError: The entered number does not fit with the entered base!\n\tThe number is in base %d or higher. You entered it's in base %d.\n", maxch + 1, original_base);
        exit(0);
    }
    else {
        temp = strtol(str, &p, original_base);

        printf("\n\tThe converted number represented in base %d: %s\n\t--------------------\n", new_base, itoa(temp, buffer, new_base));
    }
}
