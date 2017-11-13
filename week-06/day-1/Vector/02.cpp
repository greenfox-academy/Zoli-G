#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int main() {
	//Create a vector of integers
	//reserve place for 10 element, then fill those place with random numbers between 0 and 10
  vector<int> v(10);

  srand(time(0));

  for (int i = 0; i < 10; i++) {
    v[i] = rand() % 11;
  }

  for (int i = 0; i < 10; i++) {
    cout << v[i] << " ";
  }
  return 0;
}
