#include <stdio.h>
#include <stdlib.h>

int prime_array[1000000];
int limit = 2;

void fill_array() {
    for (int i = 0; i <= limit - 2; i++)
        prime_array[i] = i + 2;
}

void print_array() {
    for (int i = 0; i <= limit - 2; i++)
        printf("%d ", prime_array[i]);
}

int print_array_only_primes() {
    int counter = 0;
    for (int i = 0; i <= limit - 2; i++)
        if (prime_array[i] != 0) {
            printf("%d ", prime_array[i]);
            counter++;
        }
    return counter;
}

void del_from_array(int place) {
    for (int i = place; i <= limit - 2; i++)
        prime_array[i] = prime_array[i + 1];
}

void eliminate_non_prime_numbers() {
    int check;
    for (int i = 0; i <= limit - 2; i++) {
        if (prime_array[i] != 0)
            check = prime_array[i];
        else
            continue;
        //printf("Eliminating the multiples of %d.\n", check);
        for (int j = i + check; j <= limit - 2; j += check) {
            prime_array[j] = 0;
        }
    }
}

int main()
{
    printf("Eratosthenes prime finding algorithm\n");
    printf("------------------------------------\n\n");

    while ((limit < 10) || (limit > 1000000)) {
        printf("Please enter limit (10-1.000.000): ");
        scanf("%d", &limit);
        if ((limit < 10) || (limit > 1000000))
            printf("\n\tWrong ingut! Enter integer between 10 and 1.000.000.\n\n");
        else
            printf("\n\tInput OK! Calculation started...\n\n");
    }

    fill_array();

    printf("\tWe are searching primes between 2 and %d.\n\n", limit);
    //print_array();

    eliminate_non_prime_numbers();
    printf("\tPlease wait, computing...\n\n");

    printf("\nThe found prime numbers are between 2 and %d are:\n", limit);
    printf("---------------------------------------------------\n\n");

    int primes_found = print_array_only_primes();
    printf("\n\nTotal of %d primes found.\n\n", primes_found);

    return 0;
}
