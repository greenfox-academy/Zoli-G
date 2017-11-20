#include <iostream>
using namespace std;

// Write a try - catch block.
// Throw a char in the try block
// Catch it in the catch block and write it out.

int main() {

	int a = 34;
	int b = 0;
	int result;

	try {

		if (b == 0) {
			throw 'z';
		}

		result = a / b;

	} catch(char e) {

		switch (e) {
			case 122 : cout << "Error (" << e << "): zero divisor." << endl;
					   break;
			default : cout << "Error: unknown error." << endl;
		}

	}

	return 0;
}