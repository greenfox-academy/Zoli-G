#include <stdio.h>

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  enum CarType type;
  double km;
  double gas;
};

void printcar(struct Car c);

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

int main() {
	struct Car cars;

	cars.type = TESLA;
	cars.km = 460;
	cars.gas = 60;
	
	printcar(cars);

	return 0;
}

void printcar(struct Car c) {
	if (c.type == TESLA) {
		printf("Range: %g", c.km);
	}
	else {
		printf("Range: %g\n"
			   "Tank volume: %g\n", c.km, c.gas);	
	}
}