#include <stdio.h>
#include <stdlib.h>

void binary_adder(char *bin_op_1, char *bin_op_2);

//TODO: write a program which asks for two binary numbers.
//write a function, which prints out the sum of the 2 binary numbers.

int main()
{

    char a[20];
    char b[20];

    printf("Give me a binary number: ");
    scanf("%s", &a);
    printf("Give me another binary number: ");
    scanf("%s", &b);

    binary_adder(a, b);

    return(0);
}

void binary_adder (char *bin_op_1, char *bin_op_2) {
	char buffer[20];
    char *p;

	for (int i = 0; i < strlen(bin_op_1); i++) {
		if (bin_op_1[i] != '0' && bin_op_1[i] != '1') {
			printf("Invalid characters found in the first binary number! Program stops.\n\n");
			exit(0);
		}
	}
	for (int j = 0; j < strlen(bin_op_2); j++) {
		if (bin_op_2[j] != '0' && bin_op_2[j] != '1') {
			printf("Invalid characters found in the second binary number! Program stops.\n\n");
			exit(0);
		}
	}

    int bin1 = strtol(bin_op_1, &p, 2);
    int bin2 = strtol(bin_op_2, &p, 2);

    int sum = bin1 + bin2;

    printf("\n\tThe sum is %d (in base 10) and %s (in base 2).\n", sum, itoa(sum, buffer, 2));
}
