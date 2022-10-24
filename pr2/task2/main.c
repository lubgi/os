#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int getIndexOf(int* array, int value, int arraySize);
int findAverage(int* array, int size);
int countElementsHigherThan(int* array, int size, int value);
int sumAfterIndex(int* array, int arraySize, int index);
int sumAfterIndexAbs(int* array, int arraySize, int index);
void printArray(int* array, int size);
void fillArrayWithRandomValues(int* arr, int size);
int getIndexOfNegative(int* arr, int size);

int main(){
    int size = 10;
    int* arr = malloc(sizeof(int) * size);
    fillArrayWithRandomValues(arr, size);
    printArray(arr, size);

    int average = findAverage(arr, size);
    int elementsCount = countElementsHigherThan(arr, size, average);
    printf("\nAverage = %d, elements count higher: %d", average, elementsCount);

    printf("\nSum after first negative:\n");

    int indexOfNegative = getIndexOfNegative(arr, size);
    int negative = arr[indexOfNegative];
    printf("First negative value = %d, sum = %d", negative, sumAfterIndexAbs(arr,size,indexOfNegative));
}

int getIndexOf(int* array, int value, int arraySize){
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int getIndexOfNegative(int* arr, int size){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            return i;
        }  
    }
    return -1;
}

int findAverage(int* array, int size){
    return sumAfterIndex(array, size, -1)/size;
}

int countElementsHigherThan(int* array, int size, int value){
    int elementsCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > value)
        {
            elementsCount++;
        }
    }
    return elementsCount;
}

int sumAfterIndex(int* array, int arraySize, int index){
    int sum = 0;
    for (int i = ++index; i < arraySize; i++)
    {
        sum += array[i];
    }
    return sum;
}

int sumAfterIndexAbs(int* array, int arraySize, int index){
    int sum = 0;
    for (int i = ++index; i < arraySize; i++)
    {
        sum += abs(array[i]);
    }
    return sum;
}

void printArray(int* array, int size){
    printf("Array: [ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]");
}

void fillArrayWithRandomValues(int* arr, int size){
    int upperBound = 101;
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % upperBound) * (pow(-1, rand() % 2 + 1));
    }
}