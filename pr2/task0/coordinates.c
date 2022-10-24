#include "coordinates.h"
#include <stdio.h>

Coordinates coordinates_init(int x, int y, int z){
    Coordinates coordinates;
    coordinates.x = x;
    coordinates.y = y;
    coordinates.z = z;
    
    return coordinates;
}

void coordinates_print(Coordinates coordinates){
    printf("(%d, %d, %d)", coordinates.x, coordinates.y, coordinates.z);
}