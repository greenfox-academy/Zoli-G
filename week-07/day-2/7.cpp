#include <iostream>
using namespace std;

// Take the Integer class from the previous exercise and create two operators for it:
// a + operator that takes a Integer& and adds it's member variables value to this.
// a + operator that takes an int and adds it's value to the member variable of this.
//
// Consider what the return value of the operator should be: Integer& or void? Or something else?
// Make it so that the code below compiles and works.
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
    //Operator overloading
    Integer& operator + (int otherNum) {
        this->number += otherNum;
        return *this;
    }
    Integer& operator + (Integer& otherIntObj) {
        this->number += otherIntObj.number;
        return *this;
    }
    //End of op.ol.
    int get() {
        return this->number;
    }
};

int main() {
    Integer a(12);
    Integer b(12);

    cout << "a + b = " << (a + b).get() << endl;
    cout << "a + 12 = " << (a + 12).get() << endl;
    cout << "a + b + 12 = " << (a + b + 12).get() << endl;

    return 0;
}
