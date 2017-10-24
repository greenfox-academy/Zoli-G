#include <stdio.h>

void reverse_name(char *name, char *reversed_name);

int main(void)
{
	char name[] = "Gipsz Jakab";

    char reversed[50];

    //write a function which reverse a name's last name and first name. Use a void function. Put your 'return' value in the second parameter.
    printf("Original name: %s.\n", name);

    reverse_name(name, reversed);

    printf("Name reversed: %s.\n", reversed);
}

void reverse_name(char *name, char *reversed_name) {
	char *firstname, *secondname;

	secondname = strtok(name, " ");
	firstname = strtok(NULL, " ");

	*reversed_name = '\0';	//Emptying string

	strcat(reversed_name, firstname);
	strcat(reversed_name, " ");
	strcat(reversed_name, secondname);
}