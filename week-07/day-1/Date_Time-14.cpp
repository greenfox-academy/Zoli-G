#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

class Person {
private:
public:
	Person() {
		time_t now = time(0);

		tm *ltm = localtime(&now);

   		cout << 1900 + ltm->tm_year << ".";
   		cout << 1 + ltm->tm_mon << ".";
   		cout << ltm->tm_mday << ". ";
   		cout << 1 + ltm->tm_hour - 1<< ":";
   		cout << 1 + ltm->tm_min << ":";
   		cout << 1 + ltm->tm_sec << endl;
	}
};

// Create a class named Person.
// This class shoud have a constructor which prints out the
// date of the creation of the istance. 

int main() {

	Person p;
}