#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL)); // This initializes the random generator.
	int rnd = 0;

	for (int i=0; i<20; i++) {
		rnd = rand() % 5; // generate a random number in the range [0, 4]
		try {
			switch (rnd) {
				case 0:
					throw 3.2f;
					break;
				case 1:
					throw double(43.56);
					break;
				case 3:
					throw "Abrakadabra";
					break;
				case 4:
					throw false;
					break;
				default:
					throw 12;
					break;
			}
		}
// Write catch blocks for each possibly thrown exception.
// In each catch block write out what the exception's type was. And what the exceptions value was.
		catch(float e) {
			cout << "Error type: float, value: " << e << endl;
		} catch(double e) {
			cout << "Error type: double, value: " << e << endl;
		} catch(const char* e) {
			cout << "Error type: string, value: " << e << endl;
		} catch(bool e) {
			cout << "Error type: boolean, value: " << e << endl;
		} catch(int e) {
			cout << "Error type: integer, value: " << e << endl;
		}
	}

	return 0;
}