#include <stdio.h>

/*
modify the previous program to print the table reverse order
for example:
Fahrenheit       Celsius
300               148.9
280               137.8
260               126.7
240               115.6
...
print out at least 10 lines
*/

int main() {

    int i;
    float j;

    float c;

    printf("Fahrenheit\tCelsius\n");

    for (i = 300; i >= 100; i -= 20) {
        j = i;
        c = (j - 32) * 5 / 9;
        printf("%d \t\t %.1f \n", i, c);
    }

	return 0;
}
