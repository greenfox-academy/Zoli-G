/* Static- Final Exam
   2018.02.02.
   8. Create a function that takes two arrays and mixes them into a third one
   like this: [1, 2, 3] and [6, 7, 8] becomes [1, 6, 2, 7, 3, 8]
   (order does not matter)
*/

#include <stdio.h>
#include <stdint.h>

uint8_t* make_union_array(uint8_t a[], uint8_t sizea, uint8_t b[], uint8_t sizeb);

void main() {
    //Variables
    uint8_t sizes = 0;
    uint8_t num_array_a[5] = {0, 45, 6, 2, 5};
    uint8_t num_array_b[4] = {1, 23, 11, 7};

    make_union_array(num_array_a, 5, num_array_b, 4);
}

uint8_t* make_union_array(uint8_t a[], uint8_t sizea, uint8_t b[], uint8_t sizeb) {

    uint8_t sizes = sizea + sizeb;

    printf("Total no. of elements in the two array are: %d\n", sizes);

    uint8_t union_array[sizes];
    for (uint8_t i = 0; i < sizea; ++i) {
        union_array[i] = a[i];
    }
    for (uint8_t i = 0; i < sizeb; ++i) {
        union_array[i + sizea] = b[i];
    }

    for (uint8_t i = 0; i < sizes; ++i) {
        printf("%d ", union_array[i]);
    }
    return union_array;
}
