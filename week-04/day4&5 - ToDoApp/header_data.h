#define MAXCOMMAND 11

//List of commands accepted by the interpreter
const char ToDoCommands[11][5] = {"-a", "-wr", "-rd", "-l", "-e", "-rm", "-c", "-p", "-lp", "menu", "exit"};


enum ToDoCheck {NOTDONE, DONE};

struct ToDoTask {
	char TaskName[33];			//eg: "To take out garbage"
	enum ToDoCheck ToDoCheck;	//Have I done this task? Store the answer: 0 or 1
	unsigned char TaskPrio;		//Task priority 0 to 9
};

struct ToDoTask ToDoTaskArray[10];	//Create an array of task types. 10 task is available at the moment

unsigned char ToDoTaskElements = 0;	//Stores elements in todotaskarray