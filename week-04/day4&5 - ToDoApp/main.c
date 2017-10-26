#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "header_data.h"

int main()
{
    ScreenMenu();
    Promt();

    for (int i = 0; i < 10; i++) {
    	ToDoTaskArray[i].TaskID = i;
    	ToDoTaskArray[i].ToDoCheck = DONE;
    	printf("Task ID: %d, done: %d\n", ToDoTaskArray[i].TaskID, ToDoTaskArray[i].ToDoCheck);
    }

    for (int i = 0; i < 9; i++) {
    	printf("'%s' ", ToDoCommands[i]);
	}

    return 0;
}
