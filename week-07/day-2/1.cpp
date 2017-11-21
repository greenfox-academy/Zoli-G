#include <iostream>
using namespace std;

// create a function that adds two integers.
// Create an other function of the same name that takes 3 integers and returns the result of adding these 3 integers.
// Write code that uses both after one an other and prints out the results in a new line each.
// For input use 1 and 2, then 1, 2 and 3.

int add(int, int);
int add(int, int, int);

int main() {

	cout << "Adding two numbers: " << add(1, 2) << endl;
	cout << "Adding three numbers with overloaded function: " << add(1, 2, 3) << endl;

	return 0;
}

int add(int a, int b) {
	return a + b;
}

int add(int a, int b, int c) {
	return a + b + c;
}