#include <iostream>
#include "Student.h"

int main()
{
    Student s;

    s.add_grade(5);
    cout << s.get_average() << "\t(" << s.get_no_of_grades() << " grades)" << endl;

    s.add_grade(4);
    cout << s.get_average() << "\t(" << s.get_no_of_grades() << " grades)" << endl;

    s.add_grade(2);
    cout << s.get_average() << "\t(" << s.get_no_of_grades() << " grades)" << endl;

    s.add_grade(5);
    cout << s.get_average() << "\t(" << s.get_no_of_grades() << " grades)" << endl;

    s.add_grade(1);
    cout << s.get_average() << "\t(" << s.get_no_of_grades() << " grades)" << endl;

    return 0;
}
