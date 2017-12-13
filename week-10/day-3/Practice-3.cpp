#include <iostream>
#include <string>

using namespace std;

class Car {
private:
	string type;
	unsigned int km;
public:
	Car(string _type, unsigned int _km) : type(_type), km(_km) {}
	void run(unsigned int _km) {
		km += _km;
		cout << "Now your " << type << " car's mileage is set to " << km << "." << endl;
	}
};

int main() {
    // Create a class called "Car"
    // It should have a "type" property that stores the car's type in a string eg: "Mazda"
    // It should have a "km" property that stores how many kilometers it have run
    // The km and the type property should be a parmeter in the constructor
    // It should have a method called "run" that takes a number and increments the "km" property by it
	Car c("4Kereku", 124555);
	c.run(4500);

	Car cc = Car("Ocskavas", 500000);
	cc.run(300);

	Car* ccc = new Car("Super GT", 12);
	ccc->run(120);
	delete ccc;

  return 0;
}
