#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
  vector<unsigned char> grades;
public:
  ~Student() {
    grades.clear();
    cout << "\n-----\nClass Log closed.\n";
  }
  void add_grade(unsigned char grade) {
    grades.push_back(grade);
  }
  float get_average() {
    size_t sum = 0;
    for (size_t i = 0; i < grades.size(); i++) {
      sum += grades.at(i);
    }
    return (float) sum / grades.size();
  }
};

int main() {
    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades
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
