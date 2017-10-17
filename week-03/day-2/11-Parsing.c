#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

char command[256];
char logged_in = 0;
char registered = 0;

void init() {
	system("cls");
	printf("Welcome to World Secure Server!\n");
	printf("-------------------------------\n");
	printf("\tOnly registered members can use our services.\n\n");
}

void promt() {

while (strcmp(command, "exit") != 0) {
    (registered == 1) ? printf("[Registered, ") : printf("[Unregistered, ");
    (logged_in == 1) ? printf("logged in.]") : printf("logged out.]");
    printf(" Type [login], [logout], [register] or [exit]: ");
	gets(command);
	//getchar();

	if (strcmp(command, "login") == 0) {
		if (logged_in == 1) {
			printf("\n\tAlready logged in.\n");
			Sleep(1000);
		}
        else if (registered == 0) {
            printf("\n\tYou are not registered.\n");
        }
		else {
			printf("\n\tLogging in...\n");
			logged_in = 1;
		}
	}
	else if (strcmp(command, "logout") == 0) {
		if (logged_in == 0) {
			printf("\n\tAlready logged out.\n");
		}
		else {
			printf("\n\tLogging out...\n");
			logged_in = 0;
		}
	}
	else if (strcmp(command, "register") == 0) {
		if (registered == 1) {
			printf("\n\tYou are already registered.\n");
		}
		else {
			printf("\n\tRegistration...\n");
			registered = 1;
		}
	}
}
}

int main()
{


    //TODO: write a register-login-logout program
    //if you type in register print out "Registration..." or "You are already registered." if you are registered.
	//you are able to log in, if you are already registered, otherwise not. In that case print out "You are not registered.".
    //if you type in login print out "Logging in..." or "Already logged in." if are logged in.
    //if you type in logout print out "Logging out..." or "Already logged out." if are logged out.
    init();
    promt();
}
