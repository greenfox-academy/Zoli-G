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
//--------------------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------------------
void clearscreen() {
	system("cls");
}
//--------------------------------------------------------------------------------------------------------------
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
		//The command contains less elements than necessary, don't bother
		printf("At least two numbers and the operator is necessary to compute. Mind the space between.\n");
		return;
	}

	//Ok, so there are at least 3 strings divided by space
	
	//Check whether either of the two numbers or the operator is not valid 
	if (is_this_a_number(command_elements[0]) * is_this_a_number(command_elements[2]) * is_this_an_operator(command_elements[1]) == 0) {
		printf("Either the number or the operator is not in a valid format.\n");
		return;
	}
		
	//Ok, so finally we can do stuff with the given three date:
	//Define operands as int or float
	float operand_1 = atof(command_elements[0]);
	float operand_2 = atof(command_elements[2]);
	//if (is_this_a_number(command_elements[0]) == 1) {int operand_1 = atoi(command_elements[0]);}
	//else {float operand_1 = atof(command_elements[0]);}
	//if (is_this_a_number(command_elements[2]) == 1) {int operand_2 = atoi(command_elements[2]);}
	//else {float operand_2 = atof(command_elements[2]);}

	switch (is_this_an_operator(command_elements[1])) {
		case 1: do_summation(operand_1, operand_2); break;
		case 2: do_subtraction(operand_1, operand_2); break;
		case 3: do_multiplication(operand_1, operand_2); break;
		case 4: do_division(operand_1, operand_2); break;
		/*case 5: do_mod(operand_1, operand_2); break;
		case 6: do_squaring(operand_1, operand_2); break;
		case 7: do_sqrt(operand_1, operand_2); break;
		case 8: do_logarithm(operand_1, operand_2); break;
		case 9: do_binto(operand_1, operand_2); break;
		case 10: do_hexto(operand_1, operand_2); break;
		case 11: do_decto(operand_1, operand_2); break;*/
	}
}
//--------------------------------------------------------------------------------------------------------------
int is_this_a_number(char *string) {
	int no_of_digits_found = 0;
	int no_of_dots_found = 0;
	int length = strlen(string);

	for (int i = 0; i < length; i ++) {						//Run through the letters
		if (isdigit(string[i]) == 0 && string[i] != '.') {	//if the letter is not a number or not a dot
			printf("\n\tNot a number or dot: %c\n", string[i]);
			return 0;										//exit with 0: not a real number
		}
		else if (string[i] == '.') {						//if it's a dot than
			//printf("\n\tFound a dot: %c\n", string[i]);
			no_of_dots_found++;								//let's count it, maybe there is more dots.
		}
		else if (isdigit(string[i]) != 0) {					//if it's a number count that too
			//printf("Found a number: %d\n", string[i]);
			no_of_digits_found++;
		}
	}

	//Reached this line, so no letters found in string, just numbers and dotts! So far OK.

	//If more than two dotts found in the string besides the numbers, than this is not a real number
	if (no_of_dots_found > 1) {
		printf("\n\tWay too much dots! Not a number: %d\n", no_of_dots_found);
		return 0;											//exit with 0: not a number, syntax error
	}
	else if (no_of_dots_found == 1) {
		printf("\n\tFloat number!\n");
		return -1;											//return -1: float number with decimal places
	}
	else {
		printf("\n\tInteger number!\n");
		return 1;											//return 1: integer number
	}
}
//--------------------------------------------------------------------------------------------------------------
int is_this_an_operator(char *string) {
	char operator_list[11][6] = {"+", "-", "*", "/", "%", "^", "<", "log", "binto", "hexto", "decto"};

	for (int i = 0; i < 11; i++) {					//if the parameter matches one of the operators then
		if (strcmp(string, operator_list[i]) == 0)
			return i + 1;							//return with an id of the operator 1 - 11
	}

	return 0;										//return 0 if it's not a valid operator
}
//--------------------------------------------------------------------------------------------------------------
void do_summation(float operand_1, float operand_2) {
	printf("%f + %f = %g\n", operand_1, operand_2, operand_1 + operand_2);
}

void do_subtraction(float operand_1, float operand_2) {
	printf("%f - %f = %g\n", operand_1, operand_2, operand_1 - operand_2);
}

void do_multiplication(float operand_1, float operand_2) {
	printf("%f * %f = %g\n", operand_1, operand_2, operand_1 * operand_2);
}

void do_division(float operand_1, float operand_2) {
	printf("%f / %f = %g\n", operand_1, operand_2, operand_1 / operand_2);
}