#ifndef PIRATE_H
#define PIRATE_H

#include <string>

using namespace std;

class Pirate
{
private:
    unsigned char drink_counter = 0;
public:
    Pirate();
    ~Pirate();
    void drink_rum();
    string hows_goin_mate();
};

#endif // PIRATE_H
