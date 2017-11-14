#ifndef STUDENT_H
#define STUDENT_H

#include <vector>

using namespace std;

class Student
{
    private:
        vector<unsigned char> grades;
    public:
        ~Student();
        void add_grade(unsigned char grade);
        float get_average();
        unsigned int get_no_of_grades();
};

#endif // STUDENT_H
