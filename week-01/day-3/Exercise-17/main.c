#include <stdio.h>

int main() {
	float w = 24;
	int out = 0;

	int w_int = w;
	// if w is even increment out by one
    if (w_int % 2 == 0) {
        printf("%d is even.\n", w_int);
        out++;
    }

	return 0;
}
