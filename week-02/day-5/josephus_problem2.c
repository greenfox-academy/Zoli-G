#include <stdio.h>
#include <stdlib.h>

//Josephus Problem solver
//People standing in circle: people
//Starting cycle with people indexed: 1
//Killing every k-th people, in this program k = 2 (-> meaning the killer stabs the neighboring soldier -> skipping 0 people)
//(direction is constant: always left or right)

int safe_place_for_josephus(int people) {
    int array[people + 1];                   //This array goes from 0 to people, but I'll use it only from 1 to people. Stores 1 if the given soldier on that position is alive, 0 if not
    int index = 1, counter = 1, step = 1;    //Index: in array we're at the moment, counter (index = counter without overflow), step: the processed living & being killed soldier
    int people_left_alive = people;          //Stores how many people are still standing alive in the circle

    for (int i = 1; i <= people; i++) {      //Fill array with 1's meaning everyone is alive at the beginning (do not used 0 indexed position)
        array[i] = 1;
    }

    do {
        index = (counter % people == 0) ? (people) : (counter % people); //Making a circular array: let the index be "people" if the counter = n * people, and counter % people otherwise
                                                                                                                    //printf("Counter: %d, step: %d, index: %d ", counter, step, index);
        if (array[index] == 1 && step % 2 == 0) {           //If he's alive and he's every k-th (2nd) in the circle...
            step++;                                         //...we processed a living soldier...
            array[index] = 0;                               //...let's kill him (sorry!)...
            people_left_alive--;                            //...let's decrease the no. of remaining people...
                                                                                                                    //printf("Killing soldier. ");
        }
        else if (array[index] == 1 && step % 2 != 0) {      //If he's alive but he's not the k-th (2nd) in the circle...
            step++;                                         //...we processed a living soldier...
                                                                                                                    //printf("Passing soldier. ");
        }
                                                                                                                    //for (int j = 1; j <= people; j++) {
                                                                                                                    //    printf("%d ", array[j]);
                                                                                                                    //}
                                                                                                                    //printf("people alive: %d\n", people_left_alive);
        counter++;                                          //Increase the counter.

    } while (people_left_alive != 1);                       //Proceed until only 1 survivor left.


    for (int k = 1; k <= people; k++) {                     //Look for the position of the living soldier
        if (array[k] == 1) {
            return k;
        }
    }
}

void main() {
    printf("Josephus Problem Solver\n");
    printf("-----------------------\n\n");

    int n = 41;

    printf("If %d soldier are standing in the circle, the #%d will survive.\n", n, safe_place_for_josephus(n));

    printf("\n*[Safe position is counted from the first (starting) person in the same direction the 'game' continues.]\n");
}
