#include <iostream>

// Create your own namespace, called Mark
// store your name as a string
// your age as an integer
// and your favorite number as an integer
//
// Create your own namespace, called Maria
// store your name as a string
// your age as an integer
// and your favorite number as an integer
//
// create a function that can add the two age, and returns it

namespace Mark {
  std::string name = "Marky Mark";
  int age = 26;
  int fav_num = 6;
}

namespace Maria {
  std::string name = "Maria Garcia";
  int age = 31;
  int fav_num = 3;
}

int add_ages(int p1, int p2);

int main()
{
    std::cout << add_ages(Mark::age, Maria::age);
    return 0;
}

int add_ages(int p1, int p2) {
  return p1 + p2;
}
