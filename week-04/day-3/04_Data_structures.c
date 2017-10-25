#include <stdio.h>

struct rectangular_cuboid {
    double a;
    double b;
    double c;
};

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
double GetSurface(struct rectangular_cuboid rc) {
	return 2 * (rc.a * rc.b + rc.a * rc.c + rc.b * rc.c);
}

// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume
double GetVolume(struct rectangular_cuboid rc) {
	return rc.a * rc.b * rc.c;
}

int main() {
	struct rectangular_cuboid rc;

	printf("Rectangular Cuboid Surface & Volume Calculator\n"
		   "----------------------------------------------\n"
		   "Enter first size: ");
	scanf("%lf", &rc.a);

	printf("Enter second size: ");
	scanf("%lf", &rc.b);

	printf("Enter third size: ");
	scanf("%lf", &rc.c);

	//double A = GetSurface(rc);
	printf("\n\tSurface is: %g\n", GetSurface(rc));
	printf("\tVolume is: %g\n", GetVolume(rc));

    return 0;
}
