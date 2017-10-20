int is_this_a_number(char *string) {

	for (int i = 0; i < length; i ++) {
		if (isdigit(string[i]) == 0 && string[i] != '.' && string[i] != '-') {
			printf("\n\tInvalid character in string: %c\n", string[i]);
			return 0;
		}
		else if (string[i] == '.') 			{no_of_dots_found++;}
		else if (string[i] == '-') 			{no_of_negative_found++;}
		else if (isdigit(string[i]) != 0) 	{no_of_digits_found++;}
	}

	if (no_of_dots_found > 1 || no_of_negative_found > 1) {
		printf("\n\tToo many dots or dashes in number: %s\n", string);
		return 0;
	}
	else if (no_of_negative_found == 1 && string[0] != '-') {
		printf("\n\tMinus sign not in prefix position: %s\n", string);
		return 0;
	}
	else if (no_of_dots_found == 0 && no_of_digits_found > 1 && string[0] == '0') {
		printf("\n\tMultiple digit number cannot start with 0's: %s\n", string);
		return 0;
	}
	else if (no_of_dots_found == 1) {
		return -1;
	}
	else {
		return 1;
	}
}