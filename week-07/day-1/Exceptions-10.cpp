#include <iostream>
using namespace std;

/**
 * Create a function that prints out the fist "N" positive odd numbers.
 * It should take the "N" number as a parameter, and print the output to the console.
 *
 * The output should look like this for 5 as parameter:
 *   1, 3, 5, 7, 9
 *
 * Non-positive "N" numbers should be treated as errors, handle it!
 */
void OddNumberPrinter(int n) {
	if (n <= 0) {
		throw 0;
	}

	for (int i = 0; i < n; ++i) {
		cout << (2 * i + 1) << (i == n - 1 ? "" : ", ");
	}
}


int main() {
	try {
		OddNumberPrinter(28);
	} catch(int e) {
		cout << "Error: negative nuber as parameter in odd number function." << endl;
	}
  return 0;
}