#include <stdio.h>
#include <stdint.h>

struct Bitfield{
    uint8_t boolean_value_1:1;
    uint8_t boolean_value_2:1;
    uint8_t boolean_value_3:1;
    uint8_t boolean_value_4:1;
    uint8_t boolean_value_5:1;
    uint8_t boolean_value_6:1;
    uint8_t boolean_value_7:1;
    uint8_t boolean_value_8:1;
};

struct NotBitfield{
    uint8_t boolean_value_1;
    uint8_t boolean_value_2;
    uint8_t boolean_value_3;
    uint8_t boolean_value_4;
    uint8_t boolean_value_5;
    uint8_t boolean_value_6;
    uint8_t boolean_value_7;
    uint8_t boolean_value_8;
};

int main() {
    // TODO:
    // Print out the size of both structs (use sizeof() function)
    struct Bitfield st_bf;
    printf("Size of bitfield structure: %d\n", sizeof(st_bf));

    struct NotBitfield st_nbf;
    printf("Size of a non-bitfield structure: %d\n", sizeof(st_nbf));

    return 0;
}