#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//project-guessing-game
//Note: the program gets harder, when you set a lower range

int main()
{
	int x, y;
	int count;
	int guess = 0;
	int rand_max;
	int rand_min;
	printf("please add the minimum number!\n");
	scanf("%d", &rand_min);
	printf("please add the maximum number!\n");
	scanf("%d", &rand_max);
	srand(time(NULL));
	int rand_num = rand() % (rand_max + 1 - rand_min) + rand_min;
	y = rand_max - rand_min;
	x = log10(y) / log10(2);

	//x-1, not x-3
	printf("I have a number between %d and %d. You have %d lives\n", rand_min, rand_max, x - 1);

	//x-1 to x
	for (count = 0; count < x; count++) {

		//count <= x instead of 1
		while (x > 0) {
            //put this two lines into while
            printf("\n>");
            scanf("%d", &guess);

			if (guess == rand_num) {
                //count+1 to count+2
				printf("Yeeeeey, you did well! It took you %d tires!", count + 2);
				break;
			}

			if (guess > rand_num) {
                //x-1
				printf("Too big, You have %d, lives left\n", x - 1);
				x--;
			}
			else {
			    //x-1
				printf("Too low, You have %d, lives left\n", x - 1);
				x--;
			}
		}

	}

	//count = x to x==0
	if (x == 0)
		printf("You have used all your lives!");

	return 0;
}
