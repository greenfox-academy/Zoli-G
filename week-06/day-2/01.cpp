#include <iostream>
#include <string>

using namespace std;

class Student {
  public:
    string name;
    unsigned int age;
};

int main() {
  // Create a new instace of the Student class and set it's name to "John" and
  // it's age to 21
  Student st; //Creating a Student object

  st.name = "John"; //Set name of the object
  st.age = 21; //Set age

  cout << "Student name: " << st.name << ", age: " << st.age;

  return 0;
}
