#include <iostream>

using namespace std;

// An average Green Fox attendee codes 6 hours daily
// The semester is 17 weeks long
//
// Print how many hours is spent with coding in a semester by an attendee,
// if the attendee only codes on workdays.
//
// Print the percentage of the coding hours in the semester if the average
// work hours weekly is 52

int main()
{
    int daily_work = 6; //hours
    int semester = 17; //weeks

    cout << "Time spent with coding in a semester (in hours): " << semester * 5 * daily_work << endl;
    cout << "Time spent with coding in avarage: " << 100 * (float) daily_work * 5 / 52 << "%" << endl;

    return 0;
}
