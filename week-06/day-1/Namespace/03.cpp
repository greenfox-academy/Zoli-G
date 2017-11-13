#include <iostream>
#include <string>
// Use your costume namespace from the last exercise
// Create a function, which takes the age as a parameter
// and returns the year when you were born

namespace Person {
  std::string name = "Zoli";
  int age = 36;
  int fav_num = 106;

  int BOY(int age) {
    return 2017 - age;
  }
}

int main()
{
    std::cout << Person::BOY(36) << std::endl;
    return 0;
}
