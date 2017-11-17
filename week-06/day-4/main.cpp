#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "task.h"

using namespace std;

vector<Task> TaskList;

int main() {
    string command;
    Response r;

    PrintMenu();
    while (command = EnterCommand(), command != "exit") {
        r = RecognizeCommand(command);
        switch (r.return_value) {
            case 0 : AddTask(r.answer); break;
            case 1 : SaveToFile(r.answer); break;
            case 2 : LoadFromFile(r.answer); break;
            case 3 : ListTasks(); break;
            case 4 : ListEmpty(); break;
            case 5 : RemoveTask(r.answer); break;
            case 6 : CompleteTask(r.answer); break;
            case 7 : AddPriorityTask(r.answer); break;
            case 9 : PrintMenu(); break;
        }
    }

    return 0;
}

void PrintMenu() {
  cout <<
    "Todo application\n" <<
	"================\n" <<
	"Commands:\n" <<
	" -a   Adds a new task \t\t\t(eg.: -a \"Take out garbage\")\n" <<
	" -wr  Write current todos to file \t(eg.: -wr \"text.txt\")\n" <<
	" -rd  Read todos from a file \t\t(eg.: -rd \"text.txt\")\n" <<
	" -l   Lists all the tasks \t\t(no parameters)\n" <<
	" -e   Empty the list \t\t\t(no parameters)\n" <<
	" -rm  Removes a task by ID \t\t(eg.: -rm 2)\n" <<
	" -c   Completes a task by ID \t\t(eg.: -c 2)\n" <<
	" -p   Add a task with priority \t\t(eg.: -p \"Cook dinner\" 9)\n" <<
	" -lp  Lists all the tasks by priority \t(no parameters)\n" <<
	" menu Prints menu\n" <<
	" exit Exits program\n" <<
	"=====================================\n";
}

string EnterCommand() {
    string command;

    cout << endl;
    cout << "Please enter command: ";
    getline(cin, command);

    return command;
}

Response RecognizeCommand(string c) {
    string ToDoCommands[11] = {"-a", "-wr", "-rd", "-l", "-e", "-rm", "-c", "-p", "-lp", "menu", "exit"};
    Response result;

    string command_token = c.substr(0, c.find_first_of(' '));
    string param_token = c.substr(c.find_first_of(' ') + 1, c.length());

    //cout << "command: " << command_token << endl;
    //cout << "parameter(s): " << param_token << endl;

    for (int i = 0; i < 11; i++) {
        if (command_token == ToDoCommands[i]) {
            //cout << "Command recognized as #" << i << endl;
            result.return_value = i;
            result.answer = param_token;
            return result;
        }
    }
    cout << "Command not recognized." << endl;
    result.return_value = -1;
    result.answer = "Error";
    return result;
}

void AddTask(string name) {

    //Checking if the parameter is encapsulated in quotes, or not...
    if (name.at(0) != '"' && name.at(name.length() - 1) != '"') {
        cout << "Error: Task name not in quotes." << endl;
        return;
    }

    //Remove quotes from parameter string
    name.erase(name.begin());
    name.erase(name.end() - 1);

    //Create new Task pointer with DMA and constructor
    Task *t = new Task(name, 0, NOTDONE);

    //Put pointer class value to the class vector
    TaskList.push_back(*t);

    cout << "\tTask created with '" << name << "'. Total of " << TaskList.size() << " task(s)." << endl;

    //Free up memory
    delete t;
}

void ListTasks() {
    if (TaskList.size() == 0) {
        cout << "There's no task in the database." << endl;
        return;
    }
    cout << "\tListing tasks by ID" << endl;
    cout << "\t-------------------" << endl;
    cout << "\tid com prio name" << endl;
    cout << "\t-------------------" << endl;
    for (int i = 0; i < TaskList.size(); i++) {
        cout << "\t" << i + 1 << "  ["  << (TaskList.at(i).getTaskIsDone() == 0 ? " " : "x") << "]  (" <<  (int)TaskList.at(i).getTaskPriority() << ") " << TaskList.at(i).getTaskName() << endl;
    }
    cout << "\t-------------------" << endl;
    cout << "\tTotal of " << TaskList.size() << " task(s)." << endl;
}

void SaveToFile(string name) {
    //Checking if the parameter is encapsulated in quotes, or not...
    if (name.at(0) != '"' && name.at(name.length() - 1) != '"') {
        cout << "Error: File name not in quotes." << endl;
        return;
    }

    //Remove quotes from parameter string to get filename
    name.erase(name.begin());
    name.erase(name.end() - 1);

    cout << "\tSaving to " << name << "... ";

    ofstream outfile;
    outfile.open(name);

    for (int i = 0; i < TaskList.size(); i++) {
        outfile << TaskList.at(i).getTaskName() << "|" << (int)TaskList.at(i).getTaskPriority() << "|" << TaskList.at(i).getTaskIsDone();
        if (i != TaskList.size() - 1) {
                outfile << endl;
        }
    }
    cout << TaskList.size() << " task saved." << endl;
    outfile.close();
}

void LoadFromFile(string name) {
    string TaskName;
    unsigned char Priority;
    IsDone IsTaskDone;

    unsigned char counter = 0;
    string line;

    //Checking if the parameter is encapsulated in quotes, or not...
    if (name.at(0) != '"' && name.at(name.length() - 1) != '"') {
        cout << "Error: File name not in quotes." << endl;
        return;
    }

    //Remove quotes from parameter string to get filename
    name.erase(name.begin());
    name.erase(name.end() - 1);

    cout << "\tLoading from " << name << "... ";

    ifstream ifile;
    ifile.open(name);

    //Till the end of file...
    while (!ifile.eof()) {
        //...read the whole line from file into the string buffer
        getline(ifile, line);
        counter++;
        //Tokenizing and converting strings to numbers:
        TaskName = line.substr(0, line.find_first_of("|"));
        Priority = (unsigned char) atoi(line.substr(line.find_first_of("|"), line.find_last_of("|") - line.find_first_of("|")).c_str());
        IsTaskDone = (IsDone) (line.at(line.size() - 1) - '0');
        //Create task with constructor, push it to vector, and delete the temp class
        Task *t = new Task(TaskName, Priority, IsTaskDone);
        TaskList.push_back(*t);
        delete t;
    }
    cout << (int)counter << " task loaded." << endl;
	ifile.close();
}

void ListEmpty() {
    TaskList.clear();
    cout << "\tList emptied. Save file not deleted." << endl;
}

void RemoveTask(string name) {
    unsigned char temp = atoi(name.c_str());
    if (temp <= 0 || temp > TaskList.size()) {
        cout << "\tInvalid index. Nothing removed." << endl;
        return;
    }
    TaskList.erase(TaskList.begin() + temp - 1);
    cout << "\tItem removed." << endl;
}

void CompleteTask(string name) {
    unsigned char temp = atoi(name.c_str());
    if (temp <= 0 || temp > TaskList.size()) {
        cout << "\tInvalid index. Nothing changed." << endl;
        return;
    }
    TaskList.at(temp - 1).setTaskDone();
    cout << "\tItem marked as completed." << endl;
}

void AddPriorityTask(string name) {
    string TaskName;
    unsigned char Priority;

    if (name.at(0) != '"' || name.at(name.size() - 3) != '"' || name.at(name.size() - 2) != ' ' || isdigit(name.at(name.size() - 1)) == 0) {
        cout << "\tInvalid syntax. Quotes mistyped or priority out of range [0-9]." << endl;
        return;
    }

    Priority = (unsigned char) (name.at(name.size() - 1) - '0');
    TaskName = name.substr(1, name.size() - 4);

    //Create new task with constructor
    Task *t = new Task(TaskName, Priority, NOTDONE);

    //Put pointer class value to the class vector
    TaskList.push_back(*t);

    cout << "\tTask named '" << TaskName << "' with priority: "  << (int)Priority << " added." << endl;
}
