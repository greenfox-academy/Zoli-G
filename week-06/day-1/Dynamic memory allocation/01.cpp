#include <iostream>
#include <ctime>
using namespace std;

// Please allocate a 5 long array and fill it with numbers from 0 to 4, then print the whole array
// Please delete the array before the program exits

int main() {
  int* pointer = NULL;
  pointer = new int[5];

  srand(time(0));
  for (size_t i = 0; i < 5; i++) {
    pointer[i] = rand() % 5;
  }

  for (size_t i = 0; i < 5; i++) {
    cout << pointer[i] << " ";
  }

  delete [] pointer;

  return 0;
}
