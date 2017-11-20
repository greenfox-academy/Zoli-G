#include <iostream>
#include <string>
using namespace std;

// Write a function that can throw two kinds of exceptions: int and const char*
// It should receive an integer.
// It should return a string from the char* array defined below.
// If the integer is larger than 5, throw an integer exception.
// The value of the exception should be how much larger it is.
// If the integer is less than 0, it should throw a const char* exception stating, that it is a negative number.
//
// Illustrate both cases in the main function.
// HINT: Put each protected code segmetn in a new try-catch block.
string function(int i);

const char* sentence[6] = {"What", "a", "pleasant", "surprie", "this", "is."};

int main() {
	try {
		function(12);
	} catch(int e) {
		cout << "Index +" << e << " elements largen than the array size." << endl;
	}

	try {
		function(-3);
	} catch(const char* e) {
		cout << "Error: array index negative" << endl;
	}

}

string function(int i) {
	if (i > 5) {
		throw i - 5;
	} else if (i < 0) {
		throw "Negative index, error.";
	}
	return sentence[i];
}