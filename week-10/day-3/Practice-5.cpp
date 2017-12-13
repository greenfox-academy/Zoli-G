#include <iostream>
#include <string>
#include <ctime>
#include <time.h>

using namespace std;

class Character {
private:
    string name;
    int8_t health_points;
    uint8_t attack_points;
    uint8_t defence_points;
public:
    Character(string name, int8_t health, uint8_t attack, uint8_t defence) {
        this->name = name;
        this->health_points = health;
        this->attack_points = attack;
        this->defence_points = defence;
    }
    string getName() {return name;}
    int8_t getHealth() {return health_points;}
    uint8_t getAttack() {return attack_points;}
    uint8_t getDefence() {return defence_points;}

    void setHealthLow(int8_t h) {health_points -= h;}
    void attack(Character& ch) {
        
        uint8_t rnd = rand() % 2;
        int8_t result;

        if (rnd == 0)
            result = this->attack_points - ch.getDefence();
        else
            result = 2 * this->attack_points - ch.getDefence();

        if (result <= 0) {
            cout << this->name << " attacked " << ch.getName() << " without success." << endl;
            return;
        }

        ch.setHealthLow(result);

        cout << this->name << " attacked " << ch.getName() << "! " << ch.getName() << "'s health now: " << (signed int)ch.getHealth() << endl;
    }
};

int main() {
    //RPG Game lite
    //Create a Character class with the following preferences:
    //name
    //character type (player/monster)
    //health point value
    //attack value
    //defense value
    //attacking method which takes a character class and decreases its health
    //value with (current character class attack - input character class defense),
    //if the output is minus, then our health is decreased
    //set the attacking method to have 50% chanse to count our attack value twice,
    //(2xcurrent attack - input defense) before calculating the final health points.

    //create 2 instances of the character class and fill their base stats from their constructor
    //make them attack each other with the attack method from the character class
    //after each round print both the attacker, and the attacked character health
    //make them fight each other until one of them has a health point lower or equal 0
    //print the winner and offer a new game

    //dont forget to use private variables, and get/set methods, and also place out_of_range
    //character class into a seperate file
    srand(time(NULL));

    Character Monster("Mmmonsterrrr", 100, 80, 70);
    Character Knight("Black Knight", 80, 75, 90);

    string winner;

    do {
        Monster.attack(Knight);
        if ((signed int)Knight.getHealth() <= 0) {winner = "Monster"; break; }

        Knight.attack(Monster);
        if ((signed int)Monster.getHealth() <= 0) {winner = "Knight"; break;}

        cout << endl;
    } while ((signed int)Monster.getHealth() > 0 && (signed int)Knight.getHealth() > 0);

    cout << endl << "-------------" << endl << "The winner is " << winner << "!" << endl;

    return 0;
}
