#include <iostream>

using namespace std;

// Define several things as a variable then print their values
// Your name as a string
// Your age as an integer
// Your height in meters as a double
// Whether you are married or not as a boolean

int main()
{
    string name = "Zoli";
    int age = 36;
    double hight = 1.75;
    bool married = false;

    cout << "My name is " << name << " and I'm " << age << " years old." << endl;
    cout << "My height is " << hight << "m and I'm " << (married == false ? "not" : "") << " married." << endl;

    return 0;
}
