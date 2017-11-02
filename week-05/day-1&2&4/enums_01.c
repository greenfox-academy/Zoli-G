/*
 * Take exercise array_function_04.c
 *
 * We're creating an exploration oput of it.
 * Create a program that takes user input,  kinds: 'q' 'w' 'a' 's' 'd'.
 * For 'q' it quits.
 * For 'w' ig oeas up if possible.
 * For 'a' it goes left, for 's' down, for 'd' to the right if possible.
 * Create enums fot these steps.
 *
 * Let the user explore the chess board and write out at each case whether the place is empty
 * or if there is a figure, which one is there. 
 * And also, if there is a figure which places it could go to, with the possible targets coordinates.
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef enum {UP = 119, DOWN = 115, RIGHT = 100, LEFT = 97};

void set_cursor_pos(unsigned char x, unsigned char y);

int main() {
	unsigned char x = 0, y = 2;
	unsigned char key;

	system("cls");
	printf("Move with [a,s,d,w], ESC to quit!\n");
	do {
		set_cursor_pos(x, y);

		printf("%c", 219);

		key = getch();
		switch (key) {
			case RIGHT : if (x <= 50) set_cursor_pos(++x, y); break;
			case LEFT : if (x >= 1) set_cursor_pos(--x, y); break;
			case UP : if (y >= 1) set_cursor_pos(x, --y); break;
			case DOWN : if (y <= 25) set_cursor_pos(x, ++y); break;
		}
	} while (key != 27);

	return 0;
}

void set_cursor_pos(unsigned char x, unsigned char y) {
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
   	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   	GetConsoleScreenBufferInfo(hConsole, &coninfo);
   	coninfo.dwCursorPosition.Y = y;
   	coninfo.dwCursorPosition.X = x;
   	SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);
}