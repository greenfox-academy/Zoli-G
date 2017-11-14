#include <iostream>
#include <string>
#define PI 3.1415

using namespace std;

class Circle {
private:
  float radius;
public:
  Circle(float radius) {
    this->radius = radius;
  }
  float get_circumference() {
    return radius * 2 * PI;
  }
  float get_area() {
    return radius * radius * PI;
  }
};

int main() {
    // Create a `Circle` class that takes it's radius as constructor parameter
    // It should have a `get_circumference` method that returns it's circumference
    // It should have a `get_area` method that returns it's area
    Circle c(4.5);

    cout << "Circumference: " << c.get_circumference() << endl;
    cout << "Area: " << c.get_area() << endl;

  return 0;
}
