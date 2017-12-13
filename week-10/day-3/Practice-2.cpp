#include <iostream>
#include <string>

using namespace std;

class Pirate {
private:
	uint8_t drunk_factor = 0;
public:
	void drink_rum() {
		++drunk_factor;
	}
	void hows_goin_mate() {
		if (drunk_factor >= 5) {
			cout << "Arrrr! (" << (unsigned) drunk_factor << ")" << endl;
		} else {
			cout << "Nothin' (" << (unsigned) drunk_factor << ")" << endl;
		}
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
    p.hows_goin_mate();

    p.drink_rum();
    p.drink_rum();
    p.drink_rum();
    p.drink_rum();
    p.drink_rum();
    p.drink_rum();
    p.hows_goin_mate();

  return 0;
}
