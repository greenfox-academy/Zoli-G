#include "Student.h"

Student::~Student()
{
    grades.clear();
    cout << "\n-----\nClass Log closed.\n";
}

void Student::add_grade(unsigned char grade) {
    grades.push_back(grade);
}

float Student::get_average() {
    size_t sum = 0;
    for (size_t i = 0; i < grades.size(); i++) {
      sum += grades.at(i);
    }
    return (float) sum / grades.size();
}
