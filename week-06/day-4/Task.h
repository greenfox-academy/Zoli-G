#ifndef TASK_H
#define TASK_H

#include <iostream>

using namespace std;

//Enum for task done or undone status
typedef enum {NOTDONE = 0, DONE = 1} IsDone;

//Class for function return values: return number and return string
class Response {
public:
    signed char return_value;
    string answer;
};

//Class for task datas
class Task {
    public:
        Task();
        Task(string TaskName, unsigned char Priority, IsDone IsTaskDone);
        ~Task();
        string getTaskName();
        unsigned char getTaskPriority();
        IsDone getTaskIsDone();
        void setTaskDone();

    private:
        string TaskName;
        unsigned char Priority;
        IsDone IsTaskDone;
};

//Function prototypes
void PrintMenu();
string EnterCommand();
Response RecognizeCommand(string c);
void AddTask(string name);
void ListTasks();
void SaveToFile(string filename);
void LoadFromFile(string name);
void ListEmpty();
void RemoveTask(string name);
void CompleteTask(string name);
void AddPriorityTask(string name);
//---

#endif // TASK_H
