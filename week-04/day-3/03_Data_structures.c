#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point_t;

// TODO:
// Create a function the constructs a point
// It should take it's x and y coordinate as parameter

// TODO:
// Create a function that takes 2 Points as a pointer and returns the distance between them
void getcoords(point_t *x);
float distance_in_plane(point_t *p1, point_t *p2);

int main()
{
	point_t Point1;
	point_t Point2;

	getcoords(&Point1);	//Call a function with the mem addr of the points variables
	getcoords(&Point2);
	
	float d = distance_in_plane(&Point1, &Point2);

	printf("\tDistance between points: %g\n", d);
    return 0;
}

void getcoords(point_t *x) {
	printf("Enter coord X: ");
	scanf("%d", &(*x).x);					//Only x here, because x is a pointer already, so no *x or &x
	printf("Enter coord Y: ");
	scanf("%d", &(*x).y);					//Only y here

	printf("Point created: [x = %d, y = %d]\n\n", (*x).x, (*x).y);
}

float distance_in_plane(point_t *p1, point_t *p2) {

	return sqrt(((*p1).x - (*p2).x) * ((*p1).x - (*p2).x) + ((*p1).y - (*p2).y) * ((*p1).y - (*p2).y));
}