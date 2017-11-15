#include <iostream>
#include <string>
using namespace std;

// Create a class called ParentClass. It should have two public functions. Both return a string. One virtual, the other not.
// Each should return a unique string.
// Create a ChildClass which inherits from the ParentClass publicly.
// This should override both functions. The virtual and the nonvirtual one both.
// These should return unique string again.
//
// Create a main() function. In this function, create a ParentClass* pointer and instanciate a ChildClass member for that pointer.
// Hint: This should look something like this: ParentClass* a = new ChildClass();
// Print out the result of both functions on this a ponter.
// Print out the result of both functions if You first cast pointer a to be interpreted as of type ChildClass*
class ParentClass {
public:
  virtual string FirstName() {return "Anna";};
  string LastName() {return "Alchemy";};
};

class ChildClass : public ParentClass {
public:
  string FirstName() {return "Goldy";};
  string LastName() {return "Alchemy";};
};

int main() {
  //ChildClass c;
  //ParentClass *p_pc = &c;
  //cout << p_pc->FirstName() << " " << p_pc->LastName() << endl;

  ParentClass *a = new ChildClass();
  cout << a->FirstName() << " " << a->LastName() << endl;

  //ChildClass *aa = new ChildClass();
  //cout << aa->FirstName() << " " << aa->LastName() << endl;

  cout << ((ChildClass*) a)->FirstName() << " " << ((ChildClass*) a)->LastName() << endl;

  return 0;
}
