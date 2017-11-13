#include <iostream>
#include <string>
// Create your own namespace, called Person
// store your name as a string
// your age as an integer
// and your favorite number as an integer
// write them out in main()

namespace Person {
  std::string name = "Zoli";
  int age = 36;
  int fav_num = 106;
}

int main()
{
    std::cout << Person::name << ", " << Person::age << ", " << Person::fav_num;
    return 0;
}
