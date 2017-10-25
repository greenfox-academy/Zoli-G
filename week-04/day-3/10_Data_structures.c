#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float x;
    float y;

} point_t;

typedef struct
{
    point_t start;
    point_t end;

} section_t;

typedef struct
{
    point_t p;
    float right_side;
} equation_t;

//Function prototype
point_t intersection_point(section_t sec1, section_t sec2);

//TODO: write a C program which can find the intersection point of two section

int main()
{
    section_t first_sect, second_sect;

    first_sect.start.x = -8;
    first_sect.start.y = 1;
    first_sect.end.x = 2;
    first_sect.end.y = 5;

    second_sect.start.x = -4;
    second_sect.start.y = 9;
    second_sect.end.x = 2;
    second_sect.end.y = -3;

    point_t intersect = intersection_point(first_sect, second_sect);
    printf("Intersection point: x = %f, y = %f.\n", intersect.x, intersect.y);

    return 0;
}

point_t intersection_point(section_t sec1, section_t sec2) {
    float m1, m2, b1, b2;
    point_t result;

    //y2 - y1 = m(x2 - x1)
    //m = (y2 - y1)/(x2 - x1)
    m1 = (sec1.start.y - sec1.end.y) / (sec1.start.x - sec1.end.x);
    m2 = (sec2.start.y - sec2.end.y) / (sec2.start.x - sec2.end.x);

    //y - y0 = m(x - x0)
    //y = m*x + (y0 - m*x0)
    //b = y0 - m*x0
    b1 = sec1.start.y - m1 * sec1.start.x;
    b2 = sec2.start.y - m2 * sec2.start.x;

    //y = m1*x + b1 and y = m2*x + b2
    //x = -(b2 - b1)/(m2-m1)
    result.x = - (b2 - b1) / (m2 - m1);
    result.y = m1 * result.x + b1;

    return result;
}