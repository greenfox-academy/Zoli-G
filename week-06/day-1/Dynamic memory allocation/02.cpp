#include <iostream>

using namespace std;

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it shoud print the average of the nubmers.
 * It should delete any dynamically allocated resource before the program exits.
 */

int main() {

  int *count = NULL, *num = NULL;
  count = new int;
  num = new int;

  cout << "Average calculator" << endl << "------------------" <<endl;
  cout << "Enter # of numbers to input: ";
  cin >> *count;

  cout << endl;

  int* v  = NULL;
  v  = new int[*count];

  for (size_t i = 0; i <= *count - 1; i++) {
    cout << "Enter #" << i + 1 << ": ";
    cin >> *num;
    v[i] = *num;
  }

  //Average
  float *sum = NULL;
  sum = new float;
  for (int i = 0; i <= *count - 1; i++) {
    *sum += *(v + i);
  }
  cout << endl << "The average is: " << *sum / *count;

  delete [] v;
  delete count;
  delete num;
  delete sum;

  return 0;
}
