#include <iostream>

using namespace std;

int main()
{
    Student s;

    s.add_grade(5);
    cout << s.get_average() << endl;

    s.add_grade(4);
    cout << s.get_average() << endl;

    s.add_grade(2);
    cout << s.get_average() << endl;

    s.add_grade(5);
    cout << s.get_average() << endl;

    s.add_grade(1);
    cout << s.get_average() << endl;

    return 0;
}
