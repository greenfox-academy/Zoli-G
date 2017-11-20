#include <iostream>
using namespace std;

// Create a function which throws an char
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws
float division(int a, int b) throw(char) {
	if (b == 0) {
		throw 'z';
	}
	return a / b;
}

int main() {

	try {
		cout << "Result: " << division(89, 0) << endl;
	} catch(char e) {
		switch (e) {
			case 122 : cout << "Error (" << e << ") : zero divisor." << endl;
					 break;
		}
	}
	return 0;
}