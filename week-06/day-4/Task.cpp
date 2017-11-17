#include "Task.h"

Task::Task() {}

Task::Task(string TaskName, unsigned char Priority, IsDone IsTaskDone) {
    this->TaskName = TaskName;
    this->Priority = Priority;
    this->IsTaskDone = IsTaskDone;
}

Task::~Task() {}

string Task::getTaskName() {
    return TaskName;
}

unsigned char Task::getTaskPriority() {
    return Priority;
}

IsDone Task::getTaskIsDone() {
    return IsTaskDone;
}

void Task::setTaskDone() {
    IsTaskDone = DONE;
}
