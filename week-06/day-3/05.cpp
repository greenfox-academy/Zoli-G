#include <iostream>
#include <vector>

using namespace std;

// Create a Car class.
// Create the following private variables : age, kms_runed, manufacturer, number_of_seats
// use proper variable types.
// Implement a method which has one parameter, and increases the kms_runed variable by its parameter value.
// Implement a method which can add a person to a car, if the number of persons in the car reached
// the value of number of seats in the car it should tell you that 'The car is full!' or something like that.
// Inherit at least two car models and try out the methods you have created.
class Car {
public:
  Car(unsigned char age, int kms_runed, string manufacturer, unsigned char number_of_seats) {
    this->age = age;
    this->kms_runed = kms_runed;
    this->manufacturer = manufacturer;
    this->number_of_seats = number_of_seats;
    people_in_car = 0;
  }
  void addKm(int km) {
    kms_runed += km;
  }
  void addPeopleToCar() {
    if (people_in_car < number_of_seats) {
      cout << "There's " << (int) people_in_car << " person in the car, so a person added. Total of " << people_in_car + 1 << " people in car. (# of seats: " << (int) number_of_seats << ")" << endl;
      people_in_car++;
    } else {
      cout << "The car is full! (" << (int)people_in_car << "/" << (int)number_of_seats << ")" << endl;
    }
  }
  void getName() {
    cout << endl << manufacturer << endl << "-------------------------" << endl;
  }
private:
  unsigned char age;
  int kms_runed;
  string manufacturer;
  unsigned char number_of_seats;
  unsigned char people_in_car;
};

class KXZ1000 : public Car {
public:
  KXZ1000(unsigned char age, int kms_runed, string manufacturer, unsigned char number_of_seats) :
    Car(age, kms_runed, manufacturer, number_of_seats) {}
};

class Family_RV : public Car {
public:
  Family_RV(unsigned char age, int kms_runed, string manufacturer, unsigned char number_of_seats) :
    Car(age, kms_runed, manufacturer, number_of_seats) {}
};

int main()
{
    //Car c(5, 123000, "Junkkaar", 6);
    KXZ1000 k(1, 0, "KXZ-1000 Sport Ed.", 2);

    k.getName();
    k.addPeopleToCar();
    k.addPeopleToCar();
    k.addPeopleToCar();
    k.addPeopleToCar();

    Family_RV f(3, 2300, "Envio Family RV 3.5 Turbo", 8);

    f.getName();
    f.addPeopleToCar();
    f.addPeopleToCar();
    f.addPeopleToCar();
    f.addPeopleToCar();

    return 0;
}
