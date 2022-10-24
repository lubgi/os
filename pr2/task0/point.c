
#include "point.h"
#include "math.h"
#include <stdio.h>

Point point_initcm(Coordinates coordinates, int mass){
    Point point;

    point.coordinates = coordinates;
    point.mass = mass;

    return point;
}

Point point_initxyzm(int x, int y, int z, int mass){
    Coordinates coordinates = coordinates_init(x, y, z);
    return point_initcm(coordinates, mass);
}

double point_finddistance(Point a, Point b){
    double distance = sqrt(   pow(b.coordinates.x - a.coordinates.x, 2)
                            + pow(b.coordinates.y - a.coordinates.y, 2)
                            + pow(b.coordinates.z - a.coordinates.z, 2)
                            );
    return distance;
}

void point_print(Point point){
    coordinates_print(point.coordinates);
    printf(", mass = %d", point.mass);
}