#include "machine.h"
#include "combination.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

CombinationPtr* initializeWinningCombinations();
int* createArrayOfValues(int values[], int size);

int main(int argc, char *argv[]){
    srand((long int)time(NULL));
    CombinationPtr* winningCombinations = initializeWinningCombinations();
    MachinePtr machine = createMachine(winningCombinations, 30);
    PlayerPtr player = createPlayer(5000);

    while (true)
    {
        CombinationPtr combination = roll(machine, player);
        int* values = getValues(combination);
        printf("\nRolled combination: %d %d %d Current balance: %d", values[0], values[1], values[2], getBalance(player));
    }
    
}

CombinationPtr* initializeWinningCombinations(){
    CombinationPtr* winning_combinations = malloc(11*sizeof(CombinationPtr));

    winning_combinations[0] = createCombination(createArrayOfValues((int[]){0,  0,  0}, ROWS_COUNT),   50);
    winning_combinations[1] = createCombination(createArrayOfValues((int[]){1,  1,  1}, ROWS_COUNT),   50);
    winning_combinations[2] = createCombination(createArrayOfValues((int[]){2,  2,  2}, ROWS_COUNT),   50);
    winning_combinations[3] = createCombination(createArrayOfValues((int[]){3,  3,  3}, ROWS_COUNT),   50);
    winning_combinations[4] = createCombination(createArrayOfValues((int[]){4,  4,  4}, ROWS_COUNT),   50);
    winning_combinations[5] = createCombination(createArrayOfValues((int[]){5, -1, -1}, ROWS_COUNT),   60);
    winning_combinations[6] = createCombination(createArrayOfValues((int[]){5,  5, -1}, ROWS_COUNT),   80);
    winning_combinations[7] = createCombination(createArrayOfValues((int[]){5,  5,  5}, ROWS_COUNT),   150);
    winning_combinations[8] = createCombination(createArrayOfValues((int[]){7, -1, -1}, ROWS_COUNT),   100);  
    winning_combinations[9] = createCombination(createArrayOfValues((int[]){7,  7, -1}, ROWS_COUNT),   200);
    winning_combinations[10] = createCombination(createArrayOfValues((int[]){6,  6,  6}, ROWS_COUNT), -200);

    return winning_combinations;
}

int* createArrayOfValues(int values[], int size){
    int* arr = malloc(sizeof(int)*size);
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = values[i];
    }
    return arr;
}