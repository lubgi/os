
#include "coordinates.h"

typedef struct
{
    Coordinates coordinates;
    int mass;
} Point;

Point point_initcm(Coordinates coordinates, int mass);
Point point_initxyzm(int x, int y, int z, int mass);
double point_finddistance(Point a, Point b);
void point_print(Point point);