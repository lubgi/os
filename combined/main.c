#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double f(double x){
    return exp(-fabs(x)) * sin(x);
}

double g(double x){
    return exp(-fabs(x)) * cos(x);
}

int main(int argc, char *argv[]){
    if (argc == 1 || argc > 2){
        printf("Supply x as only command line argument");
        exit(-1);
    }

    double x = strtod(argv[1], NULL);

    printf("x = %f \n", x);
    printf("f(x) = %f \n", f(x));
    printf("g(x) = %f \n", g(x));
}
