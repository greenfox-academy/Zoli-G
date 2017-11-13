#include <iostream>
#include <string>
#include <vector>

using namespace std;

//create an integer vector with the size of 5 and print the 3rd element of it

int main() {
  vector<int> v = {3, 67, 88, 432, 0};

  cout << "The third element of the vector is: " << v.at(2);

  return 0;
}
