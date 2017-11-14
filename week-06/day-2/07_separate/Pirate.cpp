#include <iostream>
#include "Pirate.h"

Pirate::Pirate()
{
    cout << "Welcome to the PirateBar! Wooden leg and a sword are a must.\n-----" << endl;
}

Pirate::~Pirate()
{
    cout << "-----\nGoodbye! Come again to PirateBar mate!" << endl;
}

void Pirate::drink_rum() {
    drink_counter++;
}

string Pirate::hows_goin_mate() {
    if (drink_counter >= 5)
        return "Arrrr! (after " + to_string(drink_counter) + " cups)";
    else
        return "Nothin' leave me alone! (after " + to_string(drink_counter) + " cups)";
}
