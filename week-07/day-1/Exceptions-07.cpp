#include <iostream>
using namespace std;
//Try to run the following code!

int main () {

    int int_array[5] = {1, 2, 3, 4, 5};
    int n = 4;

    try {

    	if (n >= sizeof(int_array) / sizeof(int)) {
    		throw 'i';
    	}

    	cout << int_array[n];
    } catch(char e) {
    	cout << "Array index error (" << e << "): out of range." << endl;
    }
    return 0;
}

//The program should compile but crash!
//Create a solution for this problem using try-catch block!
