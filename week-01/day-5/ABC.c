//#include <stdio.h>
//#include <stdlib.h>
#include <stdint.h>

//writing ABC with loop like this : aAbBcC...zZ

int main()
{
    int i;
    for (i = 65; i <= 90; i++) {
        printf("%c%c", i + 32, i);
    }

	return 0;
}
