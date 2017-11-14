#ifndef STUDENT_H
#define STUDENT_H

class Student
{
    private:
        vector<unsigned char> grades;
    public:
        ~Student();
        void add_grade(unsigned char grade);
        float get_average();
};

#endif // STUDENT_H
