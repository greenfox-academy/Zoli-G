#include <iostream>
using namespace std;

// Create 3 functions: each should take respectively 2, 3 and 4 strings.
// Each should return a string that contains all the input string concatenated.
// (Combined into one in a linear order.)
// Write code that showcases how this works and prints out the result of the function.
string scat(string, string);
string scat(string, string, string);
string scat(string, string, string, string);

int main() {

	cout << "With two params: " << scat("Igyál", "tejet") << endl;
	cout << "With three params: " << scat("Igyál", "sok", "tejet") << endl;
	cout << "With two params: " << scat("Igyál", "nagyon", "sok", "tejet") << endl;
	return 0;
}

string scat(string s1, string s2) {
	return s1 + s2;
}

string scat(string s1, string s2, string s3) {
	return s1 + s2 + s3;
}

string scat(string s1, string s2, string s3, string s4) {
	return s1 + s2 + s3 + s4;
}