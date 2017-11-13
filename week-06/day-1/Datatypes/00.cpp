#include <iostream>

using namespace std;

// Write a program that prints a few details to the terminal window about you
// It should print each detail to a new line.
//  - Your name
//  - Your age
//  - Do you like coffee? (as a boolen variable)
//
//  Example output:
//  John Doe
//  31
//  Likes coffee: true

int main()
{
   string name = "Zoli";
   string age = "36";
   string likes_coffee = "Do I like coffe? - ";

   bool coffee = false;

   cout << name << endl;
   cout << age << endl;
   cout << likes_coffee << (coffee == true ? "yes" : "no") << endl;
   return 0;
}
