//List of commands accepted by the interpreter
const char ToDoCommands[9][4] = {"-a", "-wr", "-rd", "-l", "-e", "-rm", "-c", "-p", "-lp"};

enum ToDoCheck {NOTDONE, DONE};

struct ToDoTask {
	unsigned short int TaskID;	//0-65.535 task range for busy people
	char TaskName[32];			//eg: "To take out garbage"
	enum ToDoCheck ToDoCheck;	//Have I done this task? Store the answer: 0 or 1
	unsigned short int TaskPrio;//Task priority 0 to 9
};

struct ToDoTask ToDoTaskArray[10];	//Create an array of task types. 10 task is available at the moment

