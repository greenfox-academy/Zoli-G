#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
	vector<uint8_t> grades;
public:
	void add_grade(uint8_t _grade) {
		if (_grade < 1 || _grade > 5) {
			return;
		}
		grades.push_back(_grade);
		cout << "Grade " << (unsigned) _grade << " added." << endl;
	}
	float get_average() {
		if (grades.size() == 0) {
			cout << "There's no grades to compute." << endl;
			return 0;
		}

		unsigned int sum = 0;
		//for (uint8_t g : grades) {
		for (int i = 0; i < grades.size(); ++i) {
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

    s.add_grade(4);
    s.add_grade(5);
    s.add_grade(3);
    s.add_grade(3);

    cout << "The average grade is: " << s.get_average() << endl;

  return 0;
}
