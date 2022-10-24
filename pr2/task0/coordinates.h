typedef struct
{
    int x;
    int y;
    int z;
} Coordinates;

Coordinates coordinates_init(int x, int y, int z);
void coordinates_print(Coordinates coordinates);
