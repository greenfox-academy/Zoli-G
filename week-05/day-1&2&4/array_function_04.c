/*
 * Create a representation of a chess board in the form of a two dimensional character array.
 * Each figure should have a character representing it. Empty places should be a single space: ' '.
 *
 * Create a function which sets up the board.
 *
 * Create a function for checking the moves for each figurs. They should get coords for the figure and where to move it.
 * They should return 0 if the move is acceptable in chess and -1 if not.
 *
 * Create a function which moves figures by getting the initial coordinate and the target coordinate.
 * This should return -1 if the move was not successful and 0 if all is right and if all is right then also move the figure.
 *
 * Determine what kind of arguments You need for the functions. Write them accordingly.
 *
 * For the sake of this exercise it's enough if You write the specific functions for peasants and horse.
 *
 * In the main functions set up the board and try them. Check if they work as intended.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING} Figures;

//Initialize board with graphical mapping, easier than with cycles
char chess_board[9][9] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                          '8', 'R', 'K', 'B', 'Q', '*', 'B', 'K', 'R',
                          '7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
                      	  '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                      	  '5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                      	  '4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                      	  '3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                      	  '2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
                      	  '1', 'R', 'K', 'B', 'Q', '*', 'B', 'K', 'R'};

//---Function prototypes---
void PrintBoard();
void Promt();
void ClearScreen();
int GetMoves(char string[6]);
int CheckSourceGrid(unsigned char x, unsigned char y);
Figures IdentifyTargetFigure(unsigned char x, unsigned char y);
int ValidateMove(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, Figures figure);
int IsEmpty(unsigned char x, unsigned char y);
int ValidatePawnMove(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);
int ValidateKnightMove(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);
//---

int main() {
	char command[6];
	int GM = 0;

	do {
		//Print out board only if the move was valid
		//if (GM == 0) {ClearScreen();
		PrintBoard();//}
		Promt();
	} while (gets(command), GM = GetMoves(command), strcmp(command, "exit") != 0);

	return 0;
}

void PrintBoard() {
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {
			printf("%c ", chess_board[i][j]);
		}
		printf("\n");
	}
}

void Promt() {
	printf("[Enter move (ex: b1-a3)]: ");
}

void ClearScreen() {
	system("cls");
}

int GetMoves(char string[6]) {
	//If the given string is not 5 character long with a - in the middle than exit
	if (strlen(string) != 5) {printf("Command length error.\n"); return -1;}
	if (string[2] != '-') {printf("Command dash error.\n"); return -1;}

	//Number in coordinates
	unsigned char from_y = atoi(&string[1]);
	unsigned char to_y = atoi(&string[4]);

	//Letters in coordinates
	unsigned char from_x = string[0];
	unsigned char to_x = string[3];

	//If the coords ane not in the 8x8 range exit
	if (from_y < 1 || from_y > 8 || to_y < 1 || to_y > 8) {printf("Command number error (1-8).\n"); return -1;}
	if (from_x < 'a' || from_x > 'h' || to_x < 'a' || to_x > 'h') {printf("Command letter error (a-h).\n"); return -1;}

	from_x -= 96;	//Map a to 1, ... h to 8
	to_x -= 96;

	//Check if there is a piece on that part of the table
	if (CheckSourceGrid(from_x, from_y) != 0) {printf("No piece to move from.\n"); return -1;}

	if (ValidateMove(from_x, from_y, to_x, to_y, IdentifyTargetFigure(from_x, from_y)) != 0) {return -1;}

	//Perform a move...
	//In the char matrix x & y coords are transposed and there is a +9 shift and a direction change (-) for the first coord
	chess_board[9 - to_y][to_x] = chess_board[9 - from_y][from_x];
	chess_board[9 - from_y][from_x] = ' ';

	return 0;
}

int CheckSourceGrid(unsigned char x, unsigned char y) {
	//Check whether there is really a piece on the place where we supposed to move from.
	if (chess_board[9 - y][x] == ' ') {return -1;}
	else {return 0;}
}

Figures IdentifyTargetFigure(unsigned char x, unsigned char y) {
	unsigned char f = chess_board[9 - y][x];

	switch (f) {
		case 'P': /*printf("Pawn\n");*/ return PAWN;
		case 'R': /*printf("Rook\n");*/ return ROOK;
		case 'K': /*printf("Knight\n");*/ return KNIGHT;
		case 'B': /*printf("Bishop\n");*/ return BISHOP;
		case 'Q': /*printf("Queen\n");*/ return QUEEN;
		case '*': /*printf("King\n");*/ return KING;
	}
}

int ValidateMove(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, Figures figure) {

	switch (figure) {
		case PAWN : return ValidatePawnMove(x1, y1, x2, y2);
		case ROOK : break;
		case KNIGHT : return ValidateKnightMove(x1, y1, x2, y2);
		case BISHOP : break;
		case QUEEN : break;
		case KING : break;
	}
}

int IsEmpty(unsigned char x, unsigned char y) {
	//Returns 0 if the given grid is empty, -1 else
	return chess_board[9 - y][x] == ' ' ? 0 : -1;
}

int ValidatePawnMove(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2) {
	//Setting rules...

	printf("Moving with Pawn...\n");

	//Pawn can move 1 or 2 steps only forward from the starting line and only if the grids are empty before him
	if (y1 == 2 && y2 == 3 && x2 - x1 == 0 && IsEmpty(x2, y2) == 0) {return 0;}
	if (y1 == 2 && y2 == 4 && x2 - x1 == 0 && IsEmpty(x2, y2) == 0 && IsEmpty(x2, y2 - 1) == 0) {return 0;}

	if (y1 == 7 && y2 == 6 && x2 - x1 == 0 && IsEmpty(x2, y2) == 0) {return 0;}
	if (y1 == 7 && y2 == 5 && x2 - x1 == 0 && IsEmpty(x2, y2) == 0 && IsEmpty(x2, y2 + 1) == 0) {return 0;}

	//Pawn can move 1 forward any time if the destination is empty (before him)
	if (abs(y2 - y1) == 1 && x2 - x1 == 0 && IsEmpty(x2, y2) == 0) {return 0;}

	//Pawn can capture opponents figure diagonally
	if (abs((y2 - y1) * (x2 - x1)) == 1 && IsEmpty(x2, y2) == -1) {return 0;}

	printf("Invalid move with Pawn...\n");
	return -1;
}

int ValidateKnightMove(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2) {
	//Setting rules...

	printf("Moving with Knight...\n");

	//Knight can move 2-1 or 1-2 and jump over figures too
	if (abs((y2 - y1) * (x2 - x1)) == 2) {return 0;}

	printf("Invalid move with Knight...\n");
	return -1;
}
