#include <iostream>
#include <string>

using namespace std;

// Create a Shape class, inherit two derived class from it
// One should be Circle, and the other one is Triangle
// For each derived class, implement a calc_area() method
// which calculates the area of the shape and stores it inside
// the class (so it is a private method)
class Shape {
public:
  virtual void calc_area() = 0;    //Pure virtual, cuz no area of an unknown shape
  virtual float get_area() = 0;
  virtual string name() = 0;
};

class Circle : public Shape {
public:
  Circle(int radius) {
    this->radius = radius;
    calc_area();
  };
  void calc_area() {
    area = radius * radius * 3.14;
  };
  float get_area() {
    return area;
  };
  string name() {return "Circle";};
private:
  int radius;
  float area;
};

class Triangle : public Shape {
public:
  Triangle(float base, float height) {
    this->base = base;
    this->height = height;
    calc_area();
  };
  void calc_area() {
    area = base * height / 2;
  };
  float get_area() {
    return area;
  };
  string name() {return "Triangle";};
private:
  float base;
  float height;
  float area;
};

//Function prototype
void getShapeArea(Shape *s);

int main()
{
    //Instanciating objects
    Circle c(10);
    Triangle t(10, 5);

    getShapeArea(&c);
    getShapeArea(&t);

    return 0;
}

void getShapeArea(Shape *s) {
  cout << "Shape is a " << s->name() << " and its area is " << s->get_area() << "." << endl;
}
