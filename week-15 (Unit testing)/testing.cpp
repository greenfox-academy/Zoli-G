#include <iostream>
#include <string>
#include "catch.hpp"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()

using namespace std;

/*
1 - Create a function which takes an array of integer as a parameter and returns the sum of the elements.
2 - Create a function which takes an integer as a parameter and returns true if that number is prime and false if it is not.
3 - Create a function which takes a string as a parameter and returns the lenght of it.
4 - Create Animal class
        Every animal has a hunger value, which is a whole number
        Every animal has a thirst value, which is a whole number
        when creating a new animal object these values are created with the default 50 value
        Every animal can eat() which decreases their hunger by one
        Every animal can drink() which decreases their thirst by one
        Every animal can play() which increases both by one
*/
//Function prototypes
int16_t num_array_sum(vector<int8_t>& v);
bool is_prime(uint16_t p);
size_t string_length(string s);

//Variables
vector<int8_t> num_array = {56, 8, 9, 0, -10, 44, 6, 10};

int main()
{
    cout << "Unit Testing Workshop (2018.01.30)" << endl;

    cout << "Sum function: " << num_array_sum(num_array) << endl;

    cout << "Prime? " << is_prime(5) << endl;
    cout << "Prime? " << is_prime(1) << endl;
    cout << "Prime? " << is_prime(26) << endl;
    cout << "Prime? " << is_prime(99) << endl;
    cout << "Prime? " << is_prime(101) << endl;

    cout << "String length: " << string_length("Hello!!!!") << endl;

    return 0;
}

int16_t num_array_sum(vector<int8_t>& v) {
    int16_t sum = 0;

    for (uint8_t i = 0; i < v.size(); ++i) {
        sum += v.at(i);
    }
    return sum;
}

bool is_prime(uint16_t p) {
   if (p < 2) {return false;}

   if (p == 2 || p == 3) {return true;}

   uint8_t divider_limit = sqrt(p);

   for (uint8_t i = 2; i <= divider_limit; ++i) {
        if (p % i == 0) {
            return false;
        }
   }

   return true;
}

size_t string_length(string s) {
    return s.length();
}

TEST_CASE( "Primes are computed", "[is_prime]" ) {
    REQUIRE( is_prime(1) == false );
    REQUIRE( is_prime(2) == true );
    REQUIRE( is_prime(3) == true );
    REQUIRE( is_prime(10) == false );
}
