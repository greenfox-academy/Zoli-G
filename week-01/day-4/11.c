#include <stdio.h>

/*
Write a program that prints the numbers from 1 to 100.
But for multiples of three print "Fizz" instead of the number
and for the multiples of five print "Buzz".
For numbers which are multiples of both three and five print "FizzBuzz".
But this time, use switch
*/

int main() {

    int i;
    for (i = 1; i <= 100; i++) {
        switch (i % 15) {
            case 0: printf("FizzBuzz\n"); continue;
        }
        switch (i % 3) {
            case 0: printf("Fizz\n"); continue;
        }
        switch (i % 5) {
            case 0: printf("Buzz\n"); continue;
        }
        printf("%d\n", i);
    }

    return 0;
}
