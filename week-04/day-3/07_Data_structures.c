#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct BYTE {
    unsigned bit7 : 1; //Starts occuping the space backwards
    unsigned bit6 : 1;
    unsigned bit5 : 1;
    unsigned bit4 : 1;
    unsigned bit3 : 1;
    unsigned bit2 : 1;
    unsigned bit1 : 1;
    unsigned bit0 : 1;
};

struct FIRSTBIT {
    unsigned _2to8 : 7; //Starts occuping the space backwards
    unsigned _1st : 1;
};

struct SPLITBIT {
    unsigned _lower5 : 5;
    unsigned _upper3 : 3;
};

typedef union {
    //TODO: make a custom type from union and nested structs. this type should be 8 bit wide.
	//you should be able to assign values:
	// - each bits
	// - upper 3 bits and lower 5 bits
	// - the whole 8-bit memory
    uint8_t _whole : 8;
    struct BYTE byte;
    struct FIRSTBIT firstbit;
    struct SPLITBIT splitbit;
} my_memory;

int main()
{
    my_memory mem;
    mem._whole = 0b11100010;

    printf("The whole memory: %d\n", mem._whole);
    printf("The upper 3 bits: %d\n", mem.splitbit._upper3);
    printf("The lower 5 bits: %d\n", mem.splitbit._lower5);
    printf("The first bit: %d\n\n", mem.firstbit._1st);

    printf("Bitmap: %d%d%d%d%d%d%d%d\n", mem.byte.bit0, mem.byte.bit1, mem.byte.bit2, mem.byte.bit3, mem.byte.bit4, mem.byte.bit5, mem.byte.bit6, mem.byte.bit7);
    return 0;
}
