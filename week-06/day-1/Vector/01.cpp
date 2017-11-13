#include <iostream>
#include <vector>

using namespace std;

//create an integer vector with the size of 5 and print all elements of it

int main() {
  vector<int> v = {3, 67, 88, 432, 0};

  for (int i = 0; i < v.size(); i++) {
      cout << v.at(i) << " ";
  }

  return 0;
}
