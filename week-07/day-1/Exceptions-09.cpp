#include <iostream>
using namespace std;

/**
 * Create a function that prints a multiplication table with a given base number.
 * It should take the base number as a parameter, and print the output to the console.
 *
 * The output should look like this for 5 as base:
 *   1 * 5 = 5
 *   2 * 5 = 10
 *   3 * 5 = 15
 *   4 * 5 = 20
 *   5 * 5 = 25
 *   6 * 5 = 30
 *   7 * 5 = 35
 *   8 * 5 = 40
 *   9 * 5 = 45
 *   10 * 5 = 50
 *
 *  If the function gets invalid parameter
 *  Negative numbers are invalid parameters.
 *  It should throw an exceptions
 */

void CreateMultiplicationTable(int n) {
	if (n < 0) {
		throw -1;
	} else if (n == 0) {
		throw 0;
	}

	for (int i = 1; i <= 10; ++i) {
		cout << i << " * " << n << " = " << n * i << endl;
	}
}

int main() {

	try {
		CreateMultiplicationTable(5);
	} catch(int e) {
		switch(e) {
			case -1 : cout << "Error: negative parameter." << endl;
					  break;
			case 0 : cout << "Error: zero parameter." << endl;
					 break;
		}
	}
  	return 0;
}