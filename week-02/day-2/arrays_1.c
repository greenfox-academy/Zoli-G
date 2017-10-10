#include <stdio.h>

int main() {
    char my_name_array[] = "My Name is Zoli.";

	//TODO:
    // Print out the array character-by-character
    int i;
    for (i = 0; i < sizeof(my_name_array) - 1; i++) {
        printf("%c\n", my_name_array[i]);
    }
    return 0;
}
