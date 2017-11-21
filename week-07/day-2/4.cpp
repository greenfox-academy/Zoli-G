#include <iostream>
using namespace std;

// Create a Class named Integer.
//It should have one int member variable.
// Create add() methods to it.
//They should take Integer& parameters.
// Make variations of add() method 1, 2, 3, 4 and 5 arguments respectively.
// All methods should add the value of the parameters
//to the member variable of this.
//
// Try them out. Write code that demonstrates how they work.
class Integer {
private:
    int number;
public:
    Integer(int number) : number(number) {}
    Integer& add(Integer& otherIntObj) {
        this->number += otherIntObj.number;
        return *this;
    }
    Integer& add(Integer& o1, Integer& o2) {
        this->number += o1.number + o2.number;
        return *this;
    }
    Integer& add(Integer& o1, Integer& o2, Integer& o3) {
        this->number += o1.number + o2.number + o3.number;
        return *this;
    }
    Integer& add(Integer& o1, Integer& o2, Integer& o3, Integer& o4) {
        this->number += o1.number + o2.number + o3.number + o4.number;
        return *this;
    }
    Integer& add(Integer& o1, Integer& o2, Integer& o3, Integer& o4, Integer& o5) {
        this->number += o1.number + o2.number + o3.number + o4.number + o5.number;
        return *this;
    }
    int getInteger() {
        return this->number;
    }
};


int main() {
    Integer i(2);
    Integer j(5);
    Integer k(67);
    Integer l(450);
    Integer m(-22);
    Integer n(2017);

    cout << "Printing single object: " << i.getInteger() << endl;

    i.add(j);
    cout << "After adding two objects together: " << i.getInteger() << endl;

    i.add(j, k);
    cout << "After adding three objects together: " << i.getInteger() << endl;

    i.add(j, k, l);
    cout << "After adding four objects together: " << i.getInteger() << endl;

    i.add(j, k, l, m);
    cout << "After adding five objects together: " << i.getInteger() << endl;

    i.add(j, k, l, m ,n);
    cout << "After adding six objects together: " << i.getInteger() << endl;

	return 0;
}
