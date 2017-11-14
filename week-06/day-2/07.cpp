#include <iostream>
#include <string>

using namespace std;

class Pirate {
private:
  unsigned char drink_counter = 0;
public:
  Pirate() {
    cout << "Welcome to the PirateBar! Wooden leg and a sword are a must.\n-----" << endl;
  }
  ~Pirate() {
    cout << "-----\nGoodbye! Come again to PirateBar mate!" << endl;
  }
  void drink_rum() {
    drink_counter++;
  }
  string hows_goin_mate() {
    if (drink_counter >= 5)
      return "Arrrr! (" + to_string(drink_counter) + " cups)";
    else
      return "Nothin' leave me alone! (" + to_string(drink_counter) + " cups)";
  }
};

int main() {
    // create a pirate class
    // it should have 2 methods
    // drink_rum()
    // hows_goin_mate()
    // if the drink_rum was called at least 5 times:
    // hows_goin_mate should return "Arrrr!"
    // "Nothin'" otherwise
    Pirate p;

    p.drink_rum();
    p.drink_rum();

    cout << p.hows_goin_mate() << endl;

    p.drink_rum();
    p.drink_rum();
    p.drink_rum();

    cout << p.hows_goin_mate() << endl;

  return 0;
}
