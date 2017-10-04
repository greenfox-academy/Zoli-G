#include <stdio.h>
#include <stdint.h>

int main() {
	int a = 654;
	uint64_t b = 654987312;
	//printf("%d", b);

	// Tell if the reminder of b devided by a is 3
    if (b % a == 3) {
        printf("The reminder of 654987312 divided by %d is 3.", a);
    }
    else {
        printf("The reminder of 654987312 divided by %d is not 3, because it's (b % a)", a);
    }

	return 0;
}
