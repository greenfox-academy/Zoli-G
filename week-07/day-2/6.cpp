#include <iostream>
using namespace std;

// Take the Integer class from the previous exercise and
// add two methods:
// One which takes an Integer& parameter and adds the value of it
// to the member variable of this.
// One which takes an int and adds the value of it
// to the member variable of this.
//
// Write code which uses them both and Prints out the results respectively.
class Integer {
private:
    int number;
public:
    Integer() {number = 0;}; //First constructor
    Integer(Integer& otherObj) : number(otherObj.number) {}; //Second constructor
    Integer(int number) : number(number) {}; //Third constructor
    Integer& add(Integer& otherObj) {
        this->number += otherObj.number;
        return *this;
    }
    Integer& add(int otherNum) {
        this->number += otherNum;
        return *this;
    }
    int getInteger() {
        return this->number;
    }
};

int main() {
    Integer i(56);
    cout << "Value of created single object: " << i.getInteger() << endl;

    Integer j(2017);
    i.add(j);
    cout << "Value of addition of two objects: " << i.getInteger() << endl;

    Integer k(1900);
    k.add(56);
    cout << "Value of addition of int and object: " << k.getInteger() << endl;

	return 0;
}
