#include <iostream>
#include <string>

using namespace std;

// store your personal data in Variables
// string name, int age, int slice_of_pizza_you_can_eat
// allocate memory dynamically for these variables
// create a sentense using these variables
// free the allocated memory

int main() {
  string *name = NULL;
  int *age = NULL, *slice_of_pizza_you_can_eat = NULL;

  name = new string;
  age = new int;
  slice_of_pizza_you_can_eat = new int;

  *name = "Zoli";
  *age = 36;
  *slice_of_pizza_you_can_eat = 4;

  cout << "Hello! My name is " << *name << " (" << *age << ") and I can eat max. " << *slice_of_pizza_you_can_eat << " slices of pizza.";

  delete name;
  delete age;
  delete slice_of_pizza_you_can_eat;

  return 0;
}
