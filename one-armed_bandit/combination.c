#include <stdlib.h>
#include <stdio.h>
#include "combination.h"

struct Combination
{
    int* values;
    int prize;
};

CombinationPtr createCombination(int* values, int prize){
    
    CombinationPtr combination = malloc(sizeof *combination);
    if (combination)
    {
        combination -> values = values;
        combination -> prize = prize;
    }
    //printf("\nProvided values: {%d, %d, %d}", combination -> values[0], combination -> values[1], combination -> values[2]);
    return combination;
}

CombinationPtr createRandomCombination(){
    return createCombination(generateValues(ROWS_COUNT), 0);
}

bool isJackpot(CombinationPtr combination){
    for (size_t i = 0; i < ROWS_COUNT; i++)
    {
        if (combination->values[i] != 7)
        {
            return false;
        }
    }
    return true;
}

int* generateValues(int size){
    int* values = (int*) malloc(size * sizeof(int));

    for (size_t i = 0; i < size; i++)
    {
        values[i] = random() % 10;
    }

    return values;
}

int getPrize(CombinationPtr combination){
    return combination->prize;
}

bool equals(CombinationPtr first, CombinationPtr second){

    for (size_t i = 0; i < ROWS_COUNT; i++)
    {
        int a = first -> values[i];
        int b = second -> values[i];
        //printf("a = %d, b = %d", a, b);
       if (first  -> values[i] == -1
        || second -> values[i] == -1) {
            return true;
       }

        if(first -> values[i] != second -> values[i]){
            //printf("\nComparing values %d and %d returned false\n", first -> values[i], second -> values[i]);
            return false;
        }
    }
    return true;
}

int* getValues(CombinationPtr combination){
    return combination -> values;
}

void printCombination(CombinationPtr combination){
    printf("Printing combination: ");
    for (size_t i = 0; i < ROWS_COUNT; i++)
    {
        printf("%d ", combination ->values[i]);
    }
    printf("\n");
}