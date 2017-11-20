#include <iostream>
#include <ctime>

using namespace std;

// Create a simple program which has a time lock
// The program shoul ask for a user input, but the user only has
// 10 seconds to reply, if the user falis (reaches the time limit)
// the program should print out: "faild, it took you too much time"
// This program cloud be the engine of a quiz game.

int main() {

	string input;

	cout << "Enter 'unarm' to disarm the bomb and hit enter. You have 10 seconds to go!" << endl;

	time_t now = time(0);

	cin >> input;

	time_t after = time(0);

	if (after - now <= 10 && input == "unarm") {
		cout << "Successfully disarmed! You  can lean back now!" << endl;
	} else {
		cout << "*#@>|... Booom! You're late!" << endl;
	}
}
