#include <stdio.h>
/*
create a program which draws a diamond, like this:
      *
    * * *
  * * * * *
* * * * * * *
* * * * * * *
  * * * * *
    * * *
      *
*/

int main()
{
    int size = 51;               //Size of diamond (only input)

    int line = (size + 1) / 2;  //No. of lines of the half-diamond
    int stars;                  //No. of stars in a line
    int indentation;            //No. of spaces used for indentation

    int i, j, k;
    for (i = 1; i <= line * 2; i++) {
        if (i <= line) {                        //On upper half...
            stars = i * 2 - 1;                  //...the no. of stars depends on the row no.
            indentation = size - stars;         //...just like the indentation.
        } else if (i >= line + 2) {                                //On the lower half...
            stars -= 2;                         //...let's reduce the max no. of stars by 2
            indentation += 2;                   //... and two more space for indentation.
        }
        for (j = 1; j <= indentation; j++) {
            printf(" ");
        }
        for (k = 1; k <= stars; k++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
