#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header_data.h"

void ScreenMenu();	//prints menu
void Promt();		//command prompt for entering commands
void ExitProgram();
int GetCommand();	//gets the user inputted commands and interprets it
int GetNoOfQuotsFromText(char string[]);
void ToDo_add(char param[]);
void ToDo_write_to_file();
void ToDo_read_from_file();
void ToDo_list();
void ToDo_empty();
void ToDo_remove(char param[]);
void ToDo_complete(char param[]);
void ToDo_addPrio(char param[]);
void ToDo_listPrio();
//----------------------------------------------------------------------
int main()
{
    ScreenMenu();

    //Initialize command variable with -1. Values from 0 to 10 gets from ToDoCommands array
    int command;
    //Get commands until exit is entered
    do {
    	Promt();
    	command = GetCommand();
    } while (command != 10);

    return 0;
}
//----------------------------------------------------------------------
void ScreenMenu() {
	system("cls");
	printf(
	"Todo application\n"
	"================\n"
	"Commands:\n"
	" -a   Adds a new task \t\t\t(eg.: -a \"Take out garbage\")\n"
	" -wr  Write current todos to file \t(eg.: -wr \"text.txt\")\n"
	" -rd  Read todos from a file \t\t(eg.: -rd \"text.txt\")\n"
	" -l   Lists all the tasks \t\t(no parameters)\n"
	" -e   Empty the list \t\t\t(no parameters)\n"
	" -rm  Removes a task by ID \t\t(eg.: -rm 2)\n"
	" -c   Completes a task by ID \t\t(eg.: -c 2)\n"
	" -p   Add a task with priority \t\t(eg.: -p \"Cook dinner\" 9)\n"
	" -lp  Lists all the tasks by priority \t(no parameters)\n"
	" menu Prints menu\n"
	" exit Exits program\n"
	"=====================================\n"
	"Please enter command: ");
}
//----------------------------------------------------------------------
void Promt() {
	printf("\n> ");
}
//----------------------------------------------------------------------
void ExitProgram() {
	printf("\nGood-bye & do not forget about your tasks!\n");
}
//----------------------------------------------------------------------
int GetCommand() {
	char enteredCommand[128] = "\0";	//storing input command string

	gets(enteredCommand);	//gets the user inputted string from the promt

	//if the string contains 1 or more than 2 "'s than exit with error
	int noOfQuotes = GetNoOfQuotsFromText(enteredCommand);
	switch (noOfQuotes) {
		case 0 : break;
		case 1 : printf("Syntax error: only one quotation mark found. Needs two of them.\n"); return -1;
		case 2 : break;
		default : printf("Syntax error: more than two quotation marks found.\n"); return -1;
	}

	//separating command and parameters and save them to strings
	char enteredCommand_command[32] = "\0";
	char *p_command = strtok(enteredCommand, " ");
	strcpy(enteredCommand_command, p_command);
	char enteredCommand_parameters[128] = "\0";
	char *p_param = p_command + strlen(enteredCommand_command) + 1;
	strcpy(enteredCommand_parameters, p_param);

	//identifying command through the array
	signed char commandID = -1;

	for (int i = 0; i < MAXCOMMAND; i++) {
		if (strcmp(enteredCommand_command, ToDoCommands[i]) == 0) {
			commandID = i;
			break;
		}
	}
	//exit if the inputted command is not in the defined array
	if (commandID == -1) {
		printf("Command error: command not recognized.\n");
		return -1;
	}

	//Run functions according to the command
	switch (commandID) {
		case 0 : ToDo_add(enteredCommand_parameters); break;
		case 1 : ToDo_write_to_file(); break;
		case 2 : ToDo_read_from_file(); break;
		case 3 : ToDo_list(); break;
		case 4 : ToDo_empty(); break;
		case 5 : ToDo_remove(enteredCommand_parameters); break;
		case 6 : ToDo_complete(enteredCommand_parameters); break;
		case 7 : ToDo_addPrio(enteredCommand_parameters); break;
		case 8 : ToDo_listPrio(10); break;
		case 9 : ScreenMenu(); break;
		case 10 : ExitProgram(); return 10;
	}
}
//----------------------------------------------------------------------
int GetNoOfQuotsFromText(char string[]) {
	int counter = 0;

	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == 34) {
			counter++;
		}
	}
	return counter;
}
//----------------------------CASE-0------------------------------------
void ToDo_add(char param[]) {
	int length = strlen(param);
	if (length == 0) {
		printf("Parameter error: -a -> parameter missing.\n");
		return;
	}
	else if (param[0] != '\"' || param[length - 1] != '\"') {
		printf("Parameter error: -a -> quotation marks missing or in wrong place.\n");
		return;
	}
	else if (length < 5 || length > 34) {
		printf("Parameter error: -a -> Task name is between 3 and 32 characters long.\n");
		return;
	}
	else if (ToDoTaskElements == 10) {
		printf("Warning: -a -> Task array is full. Maximum no. of items are 10.\n");
		return;
	}
	else {
		ToDoTaskElements++;
		char *p = param;
		*(p + length - 1) = '\0';	//cut the ending quote
		strcpy(ToDoTaskArray[ToDoTaskElements - 1].TaskName, p + 1); //ignore the first quote
		ToDoTaskArray[ToDoTaskElements - 1].ToDoCheck = NOTDONE;
		ToDoTaskArray[ToDoTaskElements - 1].TaskPrio = 0;
		printf("Task saved at position %d.\n", ToDoTaskElements);
	}
}
//----------------------------CASE-1------------------------------------
void ToDo_write_to_file() {
	size_t counter = 0;
	FILE *fp;

	fp = fopen("todo-save.bin", "wb");

	if (fp == 0) {
		printf("Failed to write to 'todo-save.bin'.\n");
        return;
    }
 
 	for (int i = 0; i < ToDoTaskElements; i++) {
		counter += fwrite(&(ToDoTaskArray[i]), sizeof(struct ToDoTask), 1, fp);
    }

    printf("%d record(s) have been saved.\n", counter);
    
    fclose(fp);
}
//----------------------------CASE-2------------------------------------
void ToDo_read_from_file() {
	FILE *fp;
	size_t i = 0;

	fp = fopen("todo-save.bin", "rb");

	ToDo_empty();

	while (fread(&ToDoTaskArray[i], sizeof(struct ToDoTask), 1, fp) == 1) {
        i++;
	}

    ToDoTaskElements = i;

    printf("%d record have been read.\n", i);
}
//----------------------------CASE-3------------------------------------
void ToDo_list() {

	printf(
		" List by number\n"
		" ====================\n"
		" Num\tTasks\t\tPriority\n");

	for (int i = 0; i < ToDoTaskElements; i++) {
		printf(" %d-[%c]\t%s\t%d\n", i + 1, ToDoTaskArray[i].ToDoCheck == DONE ? 'x' : ' ', ToDoTaskArray[i].TaskName, ToDoTaskArray[i].TaskPrio);
	}

	printf("\n%d records listed.\n", ToDoTaskElements);
}
//----------------------------CASE-4------------------------------------
void ToDo_empty() {
	memset(&ToDoTaskArray, 0, sizeof(ToDoTaskArray));
	ToDoTaskElements = 0;
	printf("Task list cleared.\n");
}
//----------------------------CASE-5------------------------------------
void ToDo_remove(char param[]) {
	int length = strlen(param);
	int index = strtol(param, NULL, 10);

	if (length == 0) {
		printf("Parameter error: -rm -> parameter missing.\n");
		return;
	}
	else if (index == 0) {
		printf("Parameter error: -rm -> parameter should be a non-zero number.\n");
		return;
	}
	else if (index > 10 || index < 1) {
		printf("Parameter error: -rm -> parameter not in range (1-10).\n");
		return;
	}
	else if (index > ToDoTaskElements) {
		printf("Warning: given index is not exists.\n");
		return;
	}
	else {
		for (int i = index; i <= ToDoTaskElements; i++) {
			ToDoTaskArray[i - 1] = ToDoTaskArray[i];
		}
		ToDoTaskElements--;
		printf("Task no. %d is removed.\n", index);
	}
}
//----------------------------CASE-6------------------------------------
void ToDo_complete(char param[]) {
	int length = strlen(param);
	int index = strtol(param, NULL, 10);

	if (length == 0) {
		printf("Parameter error: -c -> parameter missing.\n");
		return;
	}
	else if (index == 0) {
		printf("Parameter error: -c -> parameter should be a non-zero number.\n");
		return;
	}
	else if (index > 10 || index < 1) {
		printf("Parameter error: -c -> parameter not in range (1-10).\n");
		return;
	}
	else if (index > ToDoTaskElements) {
		printf("Warning: given index is not exists.\n");
		return;
	}
	else {
		ToDoTaskArray[index - 1].ToDoCheck = DONE;
		printf("Task no. %d is marked as done.\n", index);
	}
}
//----------------------------CASE-7------------------------------------
void ToDo_addPrio(char param[]) {
	int length = strlen(param);
	if (length == 0) {
		printf("Parameter error: -p -> parameter missing.\n");
		return;
	}
	else if (param[0] != '\"' || param[length - 3] != '\"' || param[length - 2] != 32 || isdigit(param[length - 1]) == 0) {
		printf("Parameter error: -p -> priority should be 0-9.\n");
		return;
	}
	else if (length < 7 || length > 36) {
		printf("Parameter error: -a -> Task name is between 3 and 32 characters long.\n");
		return;
	}
	else if (ToDoTaskElements == 10) {
		printf("Warning: -a -> Task array is full. Max items are 10.\n");
		return;
	}
	else {
		ToDoTaskElements++;
		char *p = param;
		*(p + length - 3) = '\0';	//cut the ending quote
		strcpy(ToDoTaskArray[ToDoTaskElements - 1].TaskName, p + 1); //ignore the first quote
		ToDoTaskArray[ToDoTaskElements - 1].ToDoCheck = NOTDONE;
		ToDoTaskArray[ToDoTaskElements - 1].TaskPrio = param[length - 1] - '0';	//ASCII - code of '0'
		printf("Task with priority saved at position %d.\n", ToDoTaskElements);
	}
}
//----------------------------CASE-8------------------------------------
//Recursive function to print tasks sorted by priority in descending order
void ToDo_listPrio() {
	struct ToDoTask *pArray[10];
	struct ToDoTask *p;

	//Fill pointer array
	for (int i = 0; i < ToDoTaskElements; i++) {
		pArray[i] = &ToDoTaskArray[i];
	}
	
	//Print header
	printf(
		" List by priority\n"
		" ====================\n"
		" Num\tTasks\t\tPriority\n");

	//Run through all the tasks (ToDoTaskElements) and bubble sort it
	for (int i = 0; i <= ToDoTaskElements - 2; i++) {
		for (int j = ToDoTaskElements - 2; j >= i; j--) {
			if ((*pArray[j]).TaskPrio < (*pArray[j + 1]).TaskPrio) {
				p = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = p;
			}
		}
	}

	//Print the sorted pointer array
	for (int i = 0; i < ToDoTaskElements; i++) {
			printf(" [%c]\t%s\t%d\n", (*pArray[i]).ToDoCheck == DONE ? 'x' : ' ', (*pArray[i]).TaskName, (*pArray[i]).TaskPrio);
	}
}
