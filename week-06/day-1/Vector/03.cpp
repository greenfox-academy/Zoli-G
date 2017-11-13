//create a vector of integers with the size of 20
//fill this vector with random numbers from 0 to 10
//print the items of the vector
//remove the even numbers, then print the items again


#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int main() {

    vector<int> v(20);

    srand(time(0));

    //Filling vector
    for (int i = 0; i < v.size(); i++) {
      v[i] = rand() % 11;
    }
    //Printing full vector
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    //Remove even numbers
    for (int i = 0; i < v.size(); i++) {
      if (v[i] % 2 == 0) {
        v.erase(v.begin() + i);
        --i;
      }
    }

    cout << endl;

    //Printing vector
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    return 0;
  }
