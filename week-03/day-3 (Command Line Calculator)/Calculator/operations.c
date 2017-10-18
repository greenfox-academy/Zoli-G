#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

void print_menu() {
	printf("           CLI Calculator           \n");
	printf("====================================\n");
	printf("usage: [number] [operation] [number]\n");
	printf("Commands:\n");
	printf("\n");
	printf("+	summation\n");
	printf("-	subtraction\n");
	printf("*	multiplication\n");
	printf("/	division\n");
	printf("%	division with remainder\n");
	printf("^	squaring\n");
	printf("<	square root\n");
	printf("log	logarithm\n");
	printf("binto	binary to hex or dec\n");
	printf("hexto	hexadecimal to bin or dec\n");
	printf("decto	decimal to bin or hex\n");
	printf("====================================\n");
	printf("exit	exiting from the program\n");
	printf("clear	clear the screen\n");
	printf("help	print usage\n");
	printf("====================================\n");
	printf("Hit enter to start!\n");
	printf("====================================\n");
}

void promt() {
	char command[32];
	while (1) {
		printf("\n> ");
		gets(command);
        if (strcmp(command, "exit") == 0) {
        	break;
        }
        else if (strcmp(command, "clear") == 0) {
        	clearscreen();
        }
        else if (strcmp(command, "help") == 0) {
        	print_menu();
        }
        else {
        	interpreter(command);
        }
	}
}

void clearscreen() {
	system("cls");
}

void interpreter(char *command) {
	char *command_elements[30];
	char *token;
	int counter = 0;

	printf("Command: %s\n", command);

	token = strtok(command, " ");
	command_elements[counter] = token;
	//printf("%s\n", token);

	while (token != NULL) {
    	//subsequent tokens gets NULL parameter to continue serch where it left off
    	token = strtok(NULL, " ");
    	counter++;
    	command_elements[counter] = token;
	}

	if (counter < 3) {
		printf("The command contains less (%d) elements than necessary.\n", counter);
	}
	else if (counter >= 3) {
		printf("The command contains more (%d) elements than necessary. Skipping the rest.\n", counter);
		printf("%s ", command_elements[0]);
		printf("%s ", command_elements[1]);
		printf("%s ", command_elements[2]);

		if (is_this_a_number(command_elements[0]) * is_this_a_number(command_elements[2]) == 1)
			printf("Both number found and the sum is: %f", atof(command_elements[0]) + atof(command_elements[2]));
		else
			printf("One of the strings cannot convert to number!");
		
	}
}

int is_this_a_number(char *string) {
	int no_of_digits_found = 0;
	int no_of_dots_found = 0;
	int index_of_dot = -1;
	int length = strlen(string);

	for (int i = 0; i < length; i ++) {						//Run through the letters
		if (isdigit(string[i]) == 0 && string[i] != '.') {	//if the letter is not a number or not a dot
			printf("\n\tNot a number or dot: %c\n", string[i]);
			return 0;										//exit
		}
		else if (string[i] == '.') {						//if it's a dot than
			//printf("\n\tFound a dot: %c\n", string[i]);
			no_of_dots_found++;								//let's count it, maybe there is more dots.
			index_of_dot = i;								//save the dot position, maybe it's in a wrong place
		}
		else if (isdigit(string[i]) != 0) {					//if it's a number count that too
			//printf("Found a number: %d\n", string[i]);
			no_of_digits_found++;
		}
	}

	//Reached this line, so no letters found in string, just numbers and dotts! So far OK.

	//If more than two dotts found in the string besides the numbers, than this is not a real number
	if (no_of_dots_found > 1) {
		printf("\n\tWay too much dots: %d\n", no_of_dots_found);
		return 0;
	}

	//If the dot position is in the first or last place, than it's also not a number: .45 or 456.
	//if (index_of_dot == 0 || index_of_dot == length - 1) {
	//	printf("\n\tInvalid dot position: %d\n", index_of_dot);
	//	return 0;
	//}

	return 1;
}
