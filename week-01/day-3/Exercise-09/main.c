#include <stdio.h>

int main() {
	int i = 53625;

	// tell if it has 11 as a divisor
    if (i % 11 == 0) {
        printf("%d can be divided by 11.", i);
    }
    else {
        printf("%d cannot divided by 11.");
    }

	return 0;
}
