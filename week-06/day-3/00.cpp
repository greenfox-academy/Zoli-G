#include <iostream>

using namespace std;

// Create a Human class which is a base class for
// SuperHuman and AquaHuman
// Create a virtual function in Human class called travelling()
// It should print out different ways to travel
// For example: Human is walking. SuperHuman is flying. AquaHuman is riding with dolphins.

class Human {
public:
  virtual void travelling() {
    cout << "I can walking (at least)." << endl;
  }
};

class SuperHuman : public Human {
public:
  void travelling() {
    cout << "I can fly!" << endl;
  }
};

class AquaHuman : public Human {
public:
  void travelling() {
    cout << "Usually I'm riding on dolphins." << endl;
  }
};

void TravellingMethod(Human *h);


int main() {
    Human h;
    SuperHuman sh;
    AquaHuman ah;

    TravellingMethod(&h);
    TravellingMethod(&sh);
    TravellingMethod(&ah);

    return 0;
}

void TravellingMethod(Human *h) {
  h->travelling();
}
