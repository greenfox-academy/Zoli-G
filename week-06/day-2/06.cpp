#include <iostream>
#include <string>

using namespace std;

class Car {
private:
  string type;
  unsigned int km;
public:
  Car(string type, unsigned int km) {
    this->type = type;
    this->km = km;
  }
  ~Car() {
    cout << endl << "Car Database Closed." << endl;
  }
  void run(unsigned int km) {
    this->km += km;
  }
  void getData() {
    cout << "Car type: " << type << ", km status: " << km << endl;
  }
};

int main() {
    // Create a class called "Car"
    // It should have a "type" property that stores the car's type in a string eg: "Mazda"
    // It should have a "km" property that stores how many kilometers it have run
    // The km and the type property should be a parmeter in the constructor
    // It should have a method called "run" that takes a number and increments the "km" property by it
    Car c("Lada", 123451);
    c.getData();

    c.run(200);
    c.getData();

  return 0;
}
