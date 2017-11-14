#include <iostream>
#include "Student.h"

Student::~Student()
{
    grades.clear();
    cout << "-----\nClass Log closed. Dear Teacher: You can go on holiday now!\n";
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

unsigned int Student::get_no_of_grades() {
    return grades.size();
}
