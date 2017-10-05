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
    int star = lines * 2 - 1;
    int space = size - star;

    for (i = 1; i <= lines; i++) {
        //for (j = 1; j <= ((lines - 1) * 2); j++) {printf(" ");}
        printf("*\n");
    }

    return 0;
}
