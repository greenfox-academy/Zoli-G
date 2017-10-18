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
	}
}

void clearscreen() {
	system("cls");
}
