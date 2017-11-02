/*
 * Create a structure representing the data of a book:
 *    * Title
 *    * Author
 *    * Year of publication
 *
 * Create functions for:
 *    * Creating a new book.
 *    * Changeing or setting the Title
 *    * Changeing or setting the Author
 *    * Changeing or setting the Year of publication
 *    * Getting each of these separately by a singel function each.
 *
 * IMPORTANT: The first parameter of each function should be a "Book", a variable of the type of this structure.
 *
 * Create a main where You demonstrate that each of these works and print out the necessary info.
 * IMPORTANT: You should only print from the main function. All other functions should return the info needed.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
	char Title[64];
	char Author[32];
	int Year;
};

struct Book books[10];

char commandArray[7][5] = {"exit", "list", "c", "mt", "ma", "my", "help"};

void Menu();
void Promt();
int GetCommand(char string[]);
void Exit();
void List();
void Create(char string[]);
int FreeIndex();
void ModifyTitle(char param[]);
void ModifyAuth(char param[]);
void ModifyYear(char param[]);

int main()
{
	char command[128];
	signed char c = -1;

	Menu();
	do {
		Promt();
		gets(command);
		c = GetCommand(command);
		//printf("Command id: %d", c);
	} while (c != 0);
	return 0;
}
//-----------------------------------------------------------------------------
void Menu() {
	printf( "Book Catalogue\n"
			"--------------\n"
			"List books:         list\n"
			"Create new book:    c Book Title|Author Name|Year of Publishing\n"
			"Modify title:       mt id New Book Title\n"
			"Modify author name: ma id Author Name\n"
			"Modify year:        my id Year\n"
			"Help:               help\n"
			"Exitprogram:        exit\n");
}
//-----------------------------------------------------------------------------
void Promt() {
	printf("\n[Choose catalog command]: ");
}
//-----------------------------------------------------------------------------
int GetCommand(char string[]) {
	char *p = strtok(string, " ");
	char *pp = p + strlen(p) + 1;
	char param[128] = "\0";
	strcpy(param, pp);

	unsigned char commandID = 100;

	for (int i = 0; i < 7; i++) {
		//printf("%s-%s\n", commandArray[i], p);
		if (strcmp(commandArray[i], p) == 0) {commandID = i;}
	}

	switch(commandID) {
		case 0 : Exit(); return 0;
		case 1 : List(); break;
		case 2 : Create(param); break;
		case 3 : ModifyTitle(param); break;
		case 4 : ModifyAuth(param); break;
		case 5 : ModifyYear(param); break;
		case 6 : Menu(); break;
	}

	return -1;
}
//-----------------------------------------------------------------------------
void Exit() {
	printf("Good-bye!\n");
}
//-----------------------------------------------------------------------------
void List() {
	printf("Listing books: \n");
	unsigned char counter = 0;

	while (strlen(books[counter].Title) != 0) {
		printf("\t%d. %s - %s - %d\n", counter + 1, books[counter].Title, books[counter].Author, books[counter].Year);
		counter++;
	}

	printf("\t-----\n");
	printf("\t%d books listed.\n", counter);
}
//-----------------------------------------------------------------------------
void Create(char param[]) {
	//printf("Parameters: %s\n", param);

	//Tokenize with pipes:
	char *p_title = strtok(param, "|");
	char *p_auth = strtok(NULL, "|");
	char *p_year = strtok(NULL, "|");

	//printf("%s - %s - %s\n", p_title, p_auth, p_year);

	if (p_title == NULL || p_auth == NULL || p_year == NULL) {
		printf("[Function argument error: c]: Book data mising.\n");
		return;
	}

	//Determine free slot for new book
	unsigned char index = FreeIndex();

	strcpy(books[index].Title, p_title);
	strcpy(books[index].Author, p_auth);
	books[index].Year = atoi(p_year);

	printf("\tBook added to position %d.\n", index + 1);
}
//-----------------------------------------------------------------------------
int FreeIndex() {
	//Determine free slot for new book
	unsigned char index = 0;
	while (strlen(books[index].Title) != 0) {
		index++;
	}
	return index;
}
//-----------------------------------------------------------------------------
void ModifyTitle(char param[]) {
	//printf("%s\n", param);
	//Tokenize with pipes:
	char *p_id = strtok(param, " ");
	char *p_title = p_id + strlen(p_id) + 1;

	if (p_id == NULL || p_title == NULL) {
		printf("[Function argument error: mt]: Book id and/or new title mising.\n");
		return;
	}

	if (strlen(p_title) < 3) {
		printf("[Function argument error: mt]: Book title length is min. 3 characters.\n");
		return;
	}

	if (atoi(p_id) == 0) {
		printf("[Function argument error: mt]: Book id not a valid number.\n");
		return;
	}

	//Get the first free slot in array, meaning there's (p_books - 1) books or 0
	char p_books = FreeIndex();

	if (atoi(p_id) > p_books) {
		printf("[Function argument error mt]: id out of range.\n");
		return;
	}

	strcpy(books[atoi(p_id) - 1].Title, p_title);

	printf("Book title modified.");
}
//-----------------------------------------------------------------------------
void ModifyAuth(char param[]) {

	//Tokenize with pipes:
	char *p_id = strtok(param, " ");
	char *p_auth = p_id + strlen(p_id) + 1;

	if (p_id == NULL || p_auth == NULL) {
		printf("[Function argument error: ma]: Book id and/or new author mising.\n");
		return;
	}

	if (strlen(p_auth) < 3) {
		printf("[Function argument error: ma]: Author length is min. 3 characters.\n");
		return;
	}

	if (atoi(p_id) == 0) {
		printf("[Function argument error: ma]: Book id not a valid number.\n");
		return;
	}

	//Get the first free slot in array, meaning there's (p_books - 1) books or 0
	char p_books = FreeIndex();

	if (atoi(p_id) > p_books) {
		printf("[Function argument error ma]: id out of range.\n");
		return;
	}

	strcpy(books[atoi(p_id) - 1].Author, p_auth);

	printf("Book author modified.");
}
//-----------------------------------------------------------------------------
void ModifyYear(char param[]) {

	//Tokenize with pipes:
	char *p_id = strtok(param, " ");
	char *p_year = p_id + strlen(p_id) + 1;

	if (p_id == NULL || p_year == NULL) {
		printf("[Function argument error: my]: Book id and/or new date missing.\n");
		return;
	}

	if (atoi(p_year) == 0) {
		printf("[Function argument error: my]: Year is not number.\n");
		return;
	}
	else if (atoi(p_year) < 1900 || atoi(p_year) > 2017) {
		printf("[Function argument error: my]: Year is between 1900 and 2017.\n");
		return;	
	}

	if (atoi(p_id) == 0) {
		printf("[Function argument error: my]: Book id not a valid number.\n");
		return;
	}

	//Get the first free slot in array, meaning there's (p_books - 1) books or 0
	char p_books = FreeIndex();

	if (atoi(p_id) > p_books) {
		printf("[Function argument error my]: id out of range.\n");
		return;
	}

	books[atoi(p_id) - 1].Year = atoi(p_year);

	printf("Book publication year modified.");
}