#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
	unsigned int hunger;
	unsigned int thirst;
public:
	Animal() {
		hunger = 50;
		thirst = 50;
	}
	virtual void name() {cout << "I'm an unknown animal!" << endl;}
	void eat() {--hunger; cout << "I ate and my hunger is now " << hunger << endl;}
	void drink() {--thirst; cout << "I drank and my thirst is now " << thirst << endl;}
	void play() {++hunger; ++thirst; cout << "After playing my hunger is " << hunger << " and my thirst is " << thirst << endl;}
};

class Fox : public Animal {
public:
	void name() {cout << "I'm an orange Fox!" << endl;}
};
class Dog : public Animal {
public:
	void name() {cout << "Hello! I'm a dog! Wwwauuu..." << endl;}
};

int main() {
//Create Animal class
//Every animal has a hunger value, which is a whole number
//Every animal has a thirst value, which is a whole number
//when creating a new animal object these values are created with the default 50 value
//Every animal can eat() which decreases their hunger by one
//Every animal can drink() which decreases their thirst by one
//Every animal can play() which increases both by one
	Animal an;
	Animal* a = &an;
	
	a->name();

	cout << endl;

	Fox f;

	a = &f;
	a->name();
	a->eat();
	a->play();

	cout << endl;

	Dog g;

	a = &g;
	a->name();
	a->drink();
	a->eat();

  return 0;
}
