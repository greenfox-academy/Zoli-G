#include <stdio.h>
#include <stdlib.h>

/*
Create a program which converts days to years, months, weeks and days
to keep it simple we say every year is 365 days long, every month is 30 days
*/

int main()
{
    int days = 3243;

    int year = (days - (days % 365)) / 365;

    int remaining_days = days - year * 365;

    int month = (remaining_days - (remaining_days % 30)) / 30;

    remaining_days = remaining_days - month * 30;

    printf("%d years, %d months, %d days.", year, month, remaining_days);

    return 0;
}
