#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "header.h"

char *command_string[32];

void print_menu() {
	printf(
	"           CLI Calculator           \n"
	"====================================\n"
	"usage: [number] [operation] [number]\n"
	"Commands:\n"
	"\n"
	"+	summation\n"
	"-	subtraction\n"
	"*	multiplication\n"
	"/	division\n"
	"%	division with remainder\n"
	"^	squaring\n"
	"<	square root\n"
	"log	logarithm\n"
	"binto	binary to hex or dec\n"
	"hexto	hexadecimal to bin or dec\n"
	"decto	decimal to bin or hex\n"
	"====================================\n"
	"exit	exiting from the program\n"
	"clear	clear the screen\n"
	"help	print usage\n"
	"====================================\n");
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

	strcpy(command_string, command);

	//printf("Command: %s\n", command);

	token = strtok(command, " ");
	command_elements[counter] = token;
	//printf("%s\n", token);

	while (token != NULL) {
    	//subsequent tokens gets NULL parameter to continue serch where it left off
    	token = strtok(NULL, " ");
    	counter++;
    	//printf("%s\n", token);
    	command_elements[counter] = token;
	}

	if (counter < 3) {
		//The command contains less elements than necessary, don't bother
		printf("At least two numbers and the operator is necessary to compute. Mind the space between.\n");
		return;
	}

	//Ok, so there are at least 3 strings divided by space
	//Define operands:
	float operand_1 = 0, operand_2 = 0;
	//Save the operator type according to the list for future reference:
	int op_type = is_this_an_operator(command_elements[1]);

	//If the operator is not valid, exit with error
	if (op_type == 0) {
		printf("\n\tThe operator is invalid.\n");
		return;
	}
	else if (is_this_a_number(command_elements[2]) == 0) {	//if the second operand is also invalid exit too
		printf("\n\tThe second operand is invalid.\n");
		return;
	}

	//if the op is not the hex and the second operand is invalid then exit
	if (op_type != 10 && is_this_a_number(command_elements[0]) == 0) {
		printf("\n\tThe first operand is invalid (not hex functions).\n");
		return;
	}
	else if (op_type == 10) {
		operand_2 = atof(command_elements[2]);
	}
	else {
		operand_1 = atof(command_elements[0]);
		operand_2 = atof(command_elements[2]);
	}

	switch (op_type) {
		case 1: do_summation(operand_1, operand_2); break;
		case 2: do_subtraction(operand_1, operand_2); break;
		case 3: do_multiplication(operand_1, operand_2); break;
		case 4: do_division(operand_1, operand_2); break;
		case 5: do_mod(operand_1, operand_2); break;
		case 6: do_squaring(operand_1, operand_2); break;
		case 7: do_sqrt(operand_1, operand_2); break;
		case 8: do_logarithm(operand_1, operand_2); break;
		case 9: do_binto(command_elements[0], operand_2); break;
		case 10: do_hexto(command_elements[0], operand_2); break;
		case 11: do_decto(command_elements[0], operand_2); break;
	}
}
//--------------------------------------------------------------------------------------------------------------
int is_this_a_number(char *string) {
	int no_of_digits_found = 0;
	int no_of_dots_found = 0;
	int no_of_negative_found = 0;
	int length = strlen(string);

	for (int i = 0; i < length; i ++) {						//Run through the letters
		if (isdigit(string[i]) == 0 && string[i] != '.' && string[i] != '-') {	//if the letter is not a number or not a dot or negative sign
			printf("\n\tNot a number or dot: %c\n", string[i]);
			return 0;										//exit with 0: not a real number
		}
		else if (string[i] == '.') {						//if it's a dot than
			//printf("\n\tFound a dot: %c\n", string[i]);
			no_of_dots_found++;								//let's count it, maybe there is more dots.
		}
		else if (string[i] == '-') {						//if it's a minus sign than
			//printf("\n\tFound a dot: %c\n", string[i]);
			no_of_negative_found++;							//let's count it, maybe there is more sign.
		}
		else if (isdigit(string[i]) != 0) {					//if it's a number count that too
			//printf("Found a number: %d\n", string[i]);
			no_of_digits_found++;
		}
	}

	//Reached this line, so no letters found in string, just numbers and dotts! So far OK.

	//If more than two dots or minus sign found in the string besides the numbers, than this is not a real number
	if (no_of_dots_found > 1 || no_of_negative_found > 1) {
		printf("\n\tWay too much dots or negative sign in number: %s\n", string);
		return 0;											//exit with 0: not a number, syntax error
	}
	//if there is one negative sign, but it is not the first character, it's also not a real number
	else if (no_of_negative_found == 1 && string[0] != '-') {
		printf("\n\tNegative number minus sign not in place: %s\n", string);
		return 0;
	}
	//if only one dot is in the string it is a float number. Dot is allowed to be on the first or last position too
	else if (no_of_dots_found == 1) {
		//printf("\n\tFloat number found: %s\n", string);
		return -1;											//return -1: float number with decimal places
	}
	//if there's no dots and the number is more than 1 digit long, let's not allow the leading 0's: 007 in not a number
	else if (no_of_dots_found == 0 && no_of_digits_found > 1 && string[0] == '0') {
		printf("\n\tMultiple digit integer number cannot start with 0's: %s\n", string);
		return 0;
	}
	//if non of the above, it's an integer
	else {
		//printf("\n\tInteger number found: %s\n", string);
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
	set_cursor_pos();
	printf(" = %g\n", operand_1 + operand_2);
}

void do_subtraction(float operand_1, float operand_2) {
	set_cursor_pos();
	printf(" = %g\n", operand_1 - operand_2);
}

void do_multiplication(float operand_1, float operand_2) {
	set_cursor_pos();
	printf(" = %g\n", operand_1 * operand_2);
}

void do_division(float operand_1, float operand_2) {
	if (operand_2 == 0) {
		printf("\n\tDivision by zero is not allowed!\n");
	}
	else {
		set_cursor_pos();
		printf(" = %g\n", operand_1 / operand_2);
	}
}

void do_mod(float operand_1, float operand_2) {
	if (ceilf(operand_1) != operand_1 || ceilf(operand_2) != operand_2) {
		printf("\n\tModulus operator needs integer numbers to compute!\n");
	}
	else {
		set_cursor_pos();
		printf(" = %d\n", (int)operand_1 % (int)operand_2);
	}
}

void do_squaring(float operand_1, float operand_2) {
	if (operand_1 == 0 || operand_2 == 0) {
		set_cursor_pos();
		printf(" = 0\n");
	}
	else if (operand_1 < 0 && ceilf(operand_2) != operand_2) {
		printf("\n\tIf the base is negative, the power function cannot accept non-integer exponent.\n");
	}
	else {
		set_cursor_pos();
		printf(" = %g\n", pow(operand_1, operand_2));
	}
}

void do_sqrt(float operand_1, float operand_2) {
	if (operand_1 == 0) {
		printf("\n\tZero root of a number is not allowed.\n");
	}
	//if the root is integer and even number: 2, 4 etc than the base cannot be negative (no complex calc)
	else if (ceilf(operand_1) == operand_1 && (int)operand_1 % 2 == 0 && operand_2 < 0) {
		printf("\n\tNo even-numbered root of negative numbers. Look for a complex calculator.\n");
	}
	//if the root is float and the base is negative that's not allowed too
	else if (ceilf(operand_1) != operand_1 && operand_2 < 0) {
		printf("\n\tNon-integer root of a negative number is not allowed.\n");
	}
	//if the root is integer and odd number and the base is negative:
	else if (ceilf(operand_1) == operand_1 && (int)operand_1 % 2 == 1 && operand_2 < 0) {
		set_cursor_pos();
		printf(" = %g\n", -pow(-operand_2, 1/operand_1));
	}
	//by any other cases
	else {
		set_cursor_pos();
		printf(" = %g\n", pow(operand_2, 1./operand_1));
	}
}

void do_logarithm(float operand_1, float operand_2) {
	if (operand_1 == 1) {
		printf("\n\tThe base cannot be 1.\n");
	}
	else if (operand_1 <= 0) {
		printf("\n\tThe base must be positive number.\n");
	}
	else if (operand_2 <= 0) {
		printf("\n\tThe number must be positive.\n");
	}
	else {
		set_cursor_pos();
		printf(" = %g\n", log10(operand_2) / log10(operand_1));
	}
}

void do_binto(char *operand_1, float operand_2) {
	int bin_value = 0;
	//char *p;
	char buffer[32];
	int length = strlen(operand_1);
	//check if the binary string contains only 0's and 1's
	for (int i = 0; i < length; i++) {
		if (operand_1[i] != '0' && operand_1[i] != '1') {
			printf("\n\tNot a binary number, invalid digits (out of [0,1] range).\n");
			return;
		}
	}
	//if the number system is not integer and < 2 than error
	if (ceilf(operand_2) != operand_2 && operand_2 < 2) {
		printf("\n\tThe base of the number system must be integer and at least 2.\n");
		return;
	}
	//let's convert the base-10 number to
	bin_value = strtol(operand_1, NULL, 2);

	//if the base is 10 do not calculate more, just print out
	if (operand_2 == 10) {
		set_cursor_pos();
		printf(" = %d\n", bin_value);
	}
	//else convert to string the base-10 value in base op_2 and save it to buffer
	else {
		itoa(bin_value, buffer, (int)operand_2);
		set_cursor_pos();
		printf(" = %s\n", buffer);
	}
}

void do_hexto(char *operand_1, float operand_2) {
	int bin_value = 0;
	char buffer[32];
	int length = strlen(operand_1);

	//printf("\n\tValues: %s %f, length: %d\n", operand_1, operand_2, length);
	//check if the hex string contains only 0-F's
	for (int i = 0; i < length; i++) {
		if (strchr("0123456789aAbBcCdDeEfF", operand_1[i]) == NULL) {
			printf("\n\tNot a hex number, invalid digits (out of [0,F] range).\n");
			return;
		}
	}
	//if the number system is not integer and < 2 than error
	if (ceilf(operand_2) != operand_2 && operand_2 < 2) {
		printf("\n\tThe base of the number system must be integer and at least 2.\n");
		return;
	}
	//let's convert the base-10 number to
	bin_value = strtol(operand_1, NULL, 16);
	//printf("\n\tBin value: %d\n", bin_value);
	//if the base is 10 do not calculate more, just print out
	if (operand_2 == 10) {
		set_cursor_pos();
		printf(" = %d\n", bin_value);
	}
	//else convert to string the base-10 value in base op_2 and save it to buffer
	else {
		itoa(bin_value, buffer, (int)operand_2);
		set_cursor_pos();
		printf(" = %s\n", buffer);
	}
}

void do_decto(char *operand_1, float operand_2) {
	int bin_value = 0;
	char buffer[32];
	int length = strlen(operand_1);

	//check if the hex string contains only 0-F's
	for (int i = 0; i < length; i++) {
		if (strchr("0123456789", operand_1[i]) == NULL) {
			printf("\n\tNot a decimal integer number, invalid digits (out of [0,9] range).\n");
			return;
		}
	}
	//if the number system is not integer and < 2 than error
	if (ceilf(operand_2) != operand_2 && operand_2 < 2) {
		printf("\n\tThe base of the number system must be integer and at least 2.\n");
		return;
	}
	//let's convert the base-10 number to
	bin_value = strtol(operand_1, NULL, 10);
	//printf("\n\tBin value: %d\n", bin_value);
	//if the base is 10 do not calculate more, just print out
	if (operand_2 == 10) {
		set_cursor_pos();
		printf(" = %d\n", bin_value);
	}
	//else convert to string the base-10 value in base op_2 and save it to buffer
	else {
		itoa(bin_value, buffer, (int)operand_2);
		set_cursor_pos();
		printf(" = %s\n", buffer);
	}
}
//--------------------------------------------------------------------------------------------------------------
void set_cursor_pos() {
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
   	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   	GetConsoleScreenBufferInfo(hConsole, &coninfo);
   	coninfo.dwCursorPosition.Y -= 1;
   	coninfo.dwCursorPosition.X += strlen(command_string) + 2;
   	SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);
}