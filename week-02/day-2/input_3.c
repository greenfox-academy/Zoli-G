#include <stdio.h>

int char_to_ascii(int c) {
    if (c < 0) c += 256;

    switch (c) {
    case  8: printf("Pressed button: BACKSPACE - ASCII code: %d.\n", c, c);
             break;
    case  9: printf("Pressed button: TAB - ASCII code: %d.\n", c, c);
             break;
    case 13: printf("Pressed button: ENTER - ASCII code: %d.\n", c, c);
             break;
    case 27: printf("Pressed button: ESC - ASCII code: %d.\n", c, c);
             break;
    case 32: printf("Pressed button: SPACE - ASCII code: %d.\n", c, c);
             break;
    default: printf("Pressed button: '%c' - ASCII code: %d.\n", c, c);
    }
}

int main()
{
    //as you know, a character is represented as a numeric value(ASCII value) in the memory
    //write a function which asks for one charcter and prints out the character in character format then in ASCII too
    printf("Type in one character (press ESC to exit):\n");

    int c;

    do {
        c = getch();
        char_to_ascii(c);
    } while (c != 27);

    return 0;
}
