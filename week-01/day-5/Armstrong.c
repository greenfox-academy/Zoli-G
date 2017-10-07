#include <stdio.h>
#include <math.h>
/*
This program checks whether the entered number is an Armstrong number or not.
*/

void main()
{
    int num, i, temp;

    //Init..
    printf("---Armstrong number checker---\n\n");
    printf("Enter number to check: ");
    scanf("%d", &num);

    //Determine the no. of decimal places of the number
    int dec_places = log10(num) + 1;

    //Armstrong sum
    int Arm = 0;
    int digit;
    temp = num;

    printf("\nDecimal places: %d\n", dec_places);

    for (i = dec_places; i >= 1; i--) {
       //Had to use ceil for pow function, cuz pow(10,2) = 99 for the C
        digit =(int)(temp / ceil(pow(10,i-1)));
        printf("\tDigit: %d\n", digit);
        temp -= digit * ceil(pow(10,i-1));

        Arm += pow(digit, dec_places);
    }

    printf("\nSum of powered digits: %d.\n\n", Arm);

    if (num == Arm)
        printf("This is Armstrong number, because %d = %d.", Arm, num);
    else
        printf("Sorry, this isn't an Armstrong number, because %d <> %d.", Arm, num);

    return 0;
}
