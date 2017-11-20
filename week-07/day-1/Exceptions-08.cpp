#include <iostream>
using namespace std;

/* Write a function which is called "get_fibonacci_number". It returns the "N"th
 * Fibonacci number, where "N" is received as a paramter.
 * For example:
 *  - get_fibonacci_number(1) returns 0
 *  - get_fibonacci_number(2) returns 1
 *  - get_fibonacci_number(3) returns 1
 *  - get_fibonacci_number(4) returns 2
 *  - get_fibonacci_number(5) returns 3
 *  - get_fibonacci_number(6) returns 5
 *
 *  If the function gets invalid parameter
 *  Negative numbers are invalid parameters.
 *  It should throw an exception
 */
int get_fibonacci_number(int n) {
	if (n <= 0) {
		throw -1;
	} else if (n == 1) {
		return 0;
	} else if (n == 2 || n == 3) {
		return 1;
	}
	return get_fibonacci_number(n - 1) + get_fibonacci_number(n - 2);
}

int main() {

	try {
		cout << "Fibonacchi: " << get_fibonacci_number(-8) << endl;
	} catch(int e) {
		switch(e) {
			case -1 : cout << "FibError: negative parameter.";
		}
	}

	return 0;
}