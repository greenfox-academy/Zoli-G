#include <stdio.h>

/*
create a program which converts the fahrenheit to celsius
the output should look like this:
Fahrenheit       Celsius
  0               -17.8
 20                -6.7
 40                 4.4
 60                15.6
...
print out at least 10 lines
*/

int main() {

    int i;
    float j;
    float c;

    printf("Fahrenheit\tCelsius\n");

    for (i = 0; i <= 200; i += 20) {
        j = i;
        c = (j - 32) * 5 / 9;
        printf("%d \t\t %.1f \n", i, c);
    }

	return 0;
}
