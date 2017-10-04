#include <stdio.h>

int main() {
	int j1 = 10;
	int j2 = 3;

	// tell if j1 is higher than j2 squared and smaller than j2 cubed
    if (j2*j2 < j1 < j2*j2*j2) {
        printf("%d is greater than %d^2, but smaller than %d^3.", j1, j2,j2);
    }
    else {
        printf("%d is not greater than %d^2 and smaller than %d^3.", j1, j2,j2);
    }
	return 0;
}
