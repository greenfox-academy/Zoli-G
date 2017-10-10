#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tom, Mark and Jerry went to the supermarket
//help them decide what can they buy out of their money

int tom_money = 2000;
int mark_money = 3500;
int jerry_money = 1200;

int can_they_buy_a_new_tv()
{
    int tv_price = 6950;

    //if they can, the program should write out that how much
    //money they have after they bought the tv
    //if they can't tell, how much money they need to buy it
    if (tom_money >= tv_price)
        printf("Tom can buy this TV! He still have $%d.\n", tom_money - tv_price);
    else
        printf("Tom, you cannot buy this TV, sorry. You still need $%d.\n", tv_price - tom_money);

    if (mark_money >= tv_price)
        printf("Mark can buy this TV! He still have $%d.\n", mark_money - tv_price);
    else
        printf("Mark, you cannot buy this TV, sorry. You still need $%d.\n", tv_price - mark_money);

    if (jerry_money >= tv_price)
        printf("Jerry can buy this TV! He still have $%d.\n", jerry_money - tv_price);
    else
        printf("Jerry, you cannot buy this TV, sorry. You still need $%d.\n", tv_price - jerry_money);

}

int can_they_make_a_cake()
{
    int milk = 200;
    int chocolate = 340;
    int flour = 75;
    int egg = 345;
    int sugar = 160;
    int salt = 90;
    int oven_shape = 330;
    int cream = 220;

    //if they can buy all these stuff calculate how much
    //each of them should pay to share the bill equally
    int sum = milk + chocolate + flour + egg + sugar + salt + oven_shape + cream;

    int shared_cost = sum / 3;  //If equally shared...

    printf("The 3 friend shared cost making cake is $%d.\n", shared_cost);
}

int can_they_make_ham_and_eggs()
{
    int milk = 200;
    int egg = 345;
    int salt = 90;
    int ham = 450;
    int onion = 60;
    int spice = 25;

    //if they can buy all these stuff calculate how much
    //each of them should pay to share the bill equally
    int sum = milk + egg + salt + ham + onion + spice;

    int shared_cost = sum / 3;  //If equally shared...

    printf("The 3 friend shared cost making h&e is $%d.\n", shared_cost);
}

//is there any local or global variables we did not use well?
//are we using functions correctly?

int main()
{
    can_they_buy_a_new_tv();
    can_they_make_a_cake();
    can_they_make_ham_and_eggs();
	return 0;

}
