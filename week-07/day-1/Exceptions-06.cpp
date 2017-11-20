#include <iostream>
#include <stdexcept>
using namespace std;

// Create a function which throws a bulit-in exception
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws
float division(int a, int b) {
	if (b == 0) {
		throw runtime_error("Runtime error: zero divisor.");
	}
	return a / b;
}

int main() {

	try {
		cout << "Result: " << division(89, 0) << endl;
	} catch(runtime_error &e) {
			cout << e.what() << endl;
	}
	return 0;
}