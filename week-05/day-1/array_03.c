#include <stdio.h>
#include <stdlib.h>
/*
 * Create a 2 dimensonal array of characters. 8x8
 * Fill the array with X and space alternating.
 * Print it out row by row. (It should resemble a chess board)
 * Designate a character for each chess peace. (Queen could be Q, King could be K, etc.)
 * Set up the start of a game.
 * Print it out again.
 * Make one move with a horse.
 * Print it again.
 */
void fillBoard();
void fillPieces();
int CheckMove(char move[]);
void printBoard();

unsigned char chess_board[8][8];

int main() {
	char move[4];

	fillPieces();
	fillBoard();

	printf("Enter Knight's move (ex: b1c3): ");
	gets(move);
	CheckMove(move);

	printBoard();

	return 0;
}

void fillBoard() {
	printf("  abcdefgh\n  --------\n");
	for (int i = 1; i <= 8; i++) {
		printf("%d|", i);
		for (int j = 1; j <= 8; j++) {
			((i + j) % 2 == 0) ? (chess_board[i][j] = 178) : (chess_board[i][j] = 176);
			fillPieces();
			printf("%c", chess_board[i][j]);
		}
		printf("\n");
	}
}

void printBoard() {
	printf("  abcdefgh\n  --------\n");
	for (int i = 1; i <= 8; i++) {
		printf("%d|", i);
		for (int j = 1; j <= 8; j++) {
			printf("%c", chess_board[i][j]);
		}
		printf("\n");
	}
}

void fillPieces() {
	chess_board[1][1] = 'R'; //11,18,81,88
	chess_board[1][2] = 'K'; //12,17,82,87
	chess_board[1][3] = 'B'; //13,16,83,86
	chess_board[1][4] = 'Q';

	for (int j = 1; j <= 4; j++)
		chess_board[2][j] = 'P';

	for (int i = 5; i <= 8; i++) {
		for (int j = 1; j <= 2; j++) {
			chess_board[j][i] = chess_board[j][9 - i];
		}
	}

	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 2; j++) {
			chess_board[9 - j][i] = chess_board[j][9 - i];
		}
	}

	chess_board[1][5] = 'G';
	chess_board[8][5] = 'G';
}

int CheckMove(char move[]) {
	int x1 = move[0] - 'a' + 1;
	int y1 = move[1] - '0';

	int x2 = move[2] - 'a' + 1;
	int y2 = move[3] - '0';

	if (chess_board[y1][x1] == 'K')
		printf("Knight found!\n");
	else {
		printf("No Knight.\n");
		return -1;
	}

	if ((abs(x1 - x2) == 1 && abs(y1 - y2) == 2) || (abs(x1 - x2) == 2 && abs(y1 - y2) == 1)) {
		printf("A valid move for the Knight!\n");
	}
	else {
		printf("Invalid move for this Knight.\n");
		return -1;
	}

	if (chess_board[y2][x2] == 176 || chess_board[y2][x2] == 178) {
		chess_board[y2][x2] = 'K';
		chess_board[y1][x1] = ((y1 + x1) % 2 == 0) ? 178 : 176;
	}
	else {
		printf("Other piece stands on the destination place: %d.\n", chess_board[y2][x2]);
	}
}