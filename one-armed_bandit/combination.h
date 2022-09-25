#include <stdbool.h>

#define ROWS_COUNT 3

typedef struct Combination* CombinationPtr;

CombinationPtr createCombination(int values[], int prize);

CombinationPtr createRandomCombination();

int* generateValues(int size);

bool equals(CombinationPtr first, CombinationPtr second);

bool isJackpot(CombinationPtr combination);

int getPrize(CombinationPtr combination);

int* getValues(CombinationPtr combination);

void printCombination(CombinationPtr combination);