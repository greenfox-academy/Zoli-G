#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
Create a program which can tell how to pay an exact amount of money
for example 45670 Ft, is the amount (store this as an integer)
and the output should be:
2-20000Ft
1-5000Ft
1-500Ft
1-100Ft
1-50Ft
1-20Ft
*/

/*
Take care of the rounding (when giving back 5 coins):
1, 2 - 0 down
3, 4 - 5 up
6, 7 - 5 down
8, 9 - 0 up
*/

int main()
{
    int amount_of_money = 57549;
    int last_digit = amount_of_money % 10;

    switch (last_digit) {
    case 1:
    case 2: amount_of_money -= last_digit; break;
    case 3:
    case 4: amount_of_money += 5 - last_digit; break;
    case 6:
    case 7: amount_of_money -= last_digit - 5; break;
    case 8:
    case 9: amount_of_money += 10 - last_digit; break;
    }

    printf("Rounded value: %d Ft\n", amount_of_money);

    int money_counter = amount_of_money;

    int Ft20000 = money_counter / 20000;
    printf("\t20000Ft: \t %d db\n", Ft20000);
    money_counter -= 20000 * Ft20000;

    int Ft5000 = money_counter / 5000;
    printf("\t5000Ft: \t %d db\n", Ft5000);
    money_counter -= 5000 * Ft5000;

    int Ft500 = money_counter / 500;
    printf("\t500Ft: \t\t %d db\n", Ft500);
    money_counter -= 500 * Ft500;

    int Ft100 = money_counter / 100;
    printf("\t100Ft: \t\t %d db\n", Ft100);
    money_counter -= 100 * Ft100;

    int Ft50 = money_counter / 50;
    printf("\t50Ft: \t\t %d db\n", Ft50);
    money_counter -= 50 * Ft50;

    int Ft20 = money_counter / 20;
    printf("\t20Ft: \t\t %d db\n", Ft20);
    money_counter -= 20 * Ft20;


    return 0;
}
