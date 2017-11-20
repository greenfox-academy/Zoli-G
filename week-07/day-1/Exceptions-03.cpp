#include <iostream>
#include <stdexcept>
using namespace std;

// Write a try - catch block.
// Throws a bulit-in exception in the try block
// Catch it in the catch block and write it out.
// Don't forget includes

int main() {

	int a = 34;
	int b = 0;
	int result;

	try {

		if (b == 0) {
			throw runtime_error("Runtime error: zero divisor");
		}

		result = a / b;

	} catch(runtime_error &e) {

		cout << e.what() << endl;
	}
	return 0;
}