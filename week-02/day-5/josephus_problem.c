#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Josephus Problem solver
//People standing in circle: n
//Starting cycle with people indexed: 1
//Killing every k-th people, in this program k = 2 (-> meaning the killer stabs the neighboring soldier -> skipping 0 people)
//(direction is constant: always left or right)

//Let n represent the no. of people standing in circle:
//n     1 	2 	3 	4 	5 	6 	7 	8 	9 	10 	11 	12 	13 	14 	15 	16  17  18  19  20  etc.
//Let f(n) repesent the indexed place for surviving the "game" f(n) is a function of n.
//If we do this algo in graphically, we get the following result:
//f(n)  1 	1 	3 	1 	3 	5 	7 	1 	3 	5 	7 	9 	11 	13 	15 	 1   3   5   7   9  etc.

//The value of f(n) resets itself when n = 2^m. Meaning in these cases the safe position is 1.
//Any other position we can write n = 2^m + l. The safe positions are odd numbers starting from 1.
//If n = 2^m + l    ->  f(n) = 2 * l + 1 (odd).

//Task is to calculate f(n) from n:

//m = [log2(n)] ([] - floor function)
//l = n - 2 ^ [log2(n)]
//f(n) = 2 * (n - 2 ^ [log2(n)]) + 1


int safe_place_for_josephus(int people) {
    return 2 * (people - pow(2, (int)log2(people))) + 1;
}

void main() {
    printf("Josephus Problem Solver\n");
    printf("-----------------------\n\n");

    printf("\tNo. of people in circle \tSafe position*\n");

    for (int i = 1; i <= 20; i++) {
        printf("\t\t%d \t\t\t\t %d\n", i, safe_place_for_josephus(i));
    }

    printf("\n*[Safe position is counted from the first (starting) person in the same direction the 'game' continues.]\n");
}
