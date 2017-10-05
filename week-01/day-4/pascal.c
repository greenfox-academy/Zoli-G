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
    int i, j;
    int size = 7;
    int lines = (size + 1) / 2;
    int star;   //no. of stars in a line
    int space;    //no. of spaces in indentation in a line

    for (i = 1; i <= lines; i++) {
        star = lines * 2 - 1;   //no. of stars in a line
        space = size - star;    //no. of spaces in indentation in a line

        printf("*\n");
    }

    return 0;
}
