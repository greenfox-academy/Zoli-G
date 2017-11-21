#include <iostream>
using namespace std;

// Take the Integer class from the previous exercise.
// Create 3 constructors for them:
// One empty which sets the member variable to 0;
// A copy constructor, that takes an Integer& argument
// A third one which takes an int as argument and makes the member variable equal to the int it took.
//
// Write code that uses these and prints out the value of the member variable of the integers created.
// (You will have to create a get method to do this appropriately.)
class Integer {
private:
    int number;
public:
    Integer() {number = 0;}; //First constructor
    Integer(Integer& otherObj) : number(otherObj.number) {}; //Second constructor
    Integer(int number) : number(number) {}; //Third constructor
    int getInteger() {
        return this->number;
    }
};

int main() {
    Integer i;
    cout << "Integer object created with empty constructor: " << i.getInteger() << endl;

    Integer j(44);
    cout << "Integer object created with integer constructor: " << j.getInteger() << endl;

    Integer tocopy(555);
    Integer k(tocopy);
    cout << "Integer object created with another integer object: " << k.getInteger() << endl;

	return 0;
}
