#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
	int a = 654;
	uint64_t b = 654987312;

	printf("%"PRIu64"\n", b/a);
	printf("%"PRIu64"\n", b%a);

	// Tell if the reminder of b devided by a is 3
    if (b % a == 3) {
        printf("The reminder of 654987312 divided by %d is 3.", a);
    }
    else {
        printf("The reminder of 654987312 divided by 654 is not 3, because it's %"PRIu64, b%a);
    }

	return 0;
}
