#include <stdio.h>
#include <inttypes.h>

// TODO:
// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters
struct House {
	char* address;
	int price;
	uint8_t rooms;
	float area;
};

// TODO:
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a pointer to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)
void worthtobuy(struct House *house) {
	float price_per_m2 = (*house).price / (*house).area;
	if (price_per_m2 < 400) {
		printf("Worth to buy: %g.\n", price_per_m2);
	}
	else {
		printf("Too pricey! (%g)\n", price_per_m2);
	}
}
// TODO:
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.

void counthousestobuy(struct House houses[], int size) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		printf("A house #%d - size: %g m2, price: EUR%d -> %g EUR/m2\n", i, houses[i].area, houses[i].price, houses[i].price / houses[i].area);
		if (houses[i].price / houses[i].area <= 400) {
			counter++;
		}
	}
	printf("There are %d houses worth buying!\n", counter);
} 

int main() {
	struct House houses[5];

	houses[0].price = 40000;
	houses[0].area = 100;

	houses[1].price = 33000;
	houses[1].area = 50;

	houses[2].price = 12000;
	houses[2].area = 23;

	houses[3].price = 100000;
	houses[3].area = 160;

	houses[4].price = 56000;
	houses[4].area = 84;

	int length = sizeof(houses) / sizeof(struct House);
	//printf("No of houses: %d\n", length);

	counthousestobuy(houses, length);

  return 0;
}
