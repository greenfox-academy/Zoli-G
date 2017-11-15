#include <iostream>
#include <string>

using namespace std;
// Countinue the Shape exercise!
// Create getter methods for each values
// (for example: in a Triangle class you should be able to
// get: Height, Base and Area)
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
  float get_radius() {
    return radius;
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
  float get_base() {
    return base;
  };
  float get_height() {
    return height;
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

    cout << "-----" << endl;

    cout << "Triangle: base is " << t.get_base() << ", the height is " << t.get_height() << "." << endl;
    cout << "Circle: radius is " << c.get_radius() << "." << endl;
    return 0;
}

void getShapeArea(Shape *s) {
  cout << "Shape is a " << s->name() << " and its area is " << s->get_area() << "." << endl;
}
