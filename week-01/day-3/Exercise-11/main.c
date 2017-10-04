#include <stdio.h>

int main() {
	int k = 1521;

	// tell if k is dividable by 3 or 5
    if ((k % 3)*(k % 5) == 0) {
        printf("%d is certainly divisible by 3 or 5.", k);
    }
    else {
        printf("%d is not divisible by either 3 or 5, or both.", k);
    }

	return 0;
}
