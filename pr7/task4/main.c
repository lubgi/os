#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

unsigned long long factorial(int n){
    if (n == 0 || n==1)
        return 1;
    
    return n * factorial(n - 1);
}

int isPrime(int n){
    for (int i = 2; i < n/2; i++)
    {
        if (n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void * get_katalana_list(void * args){
	int n = 1;
	int iter = *(int*)args;
	unsigned long long *katalanaValues = malloc(sizeof(unsigned long long)*iter);;
	for(int i = 0; i < iter; i++){
		katalanaValues[i] = factorial(2*i)/((factorial(i+1)*factorial(i)));
	}
	return (void *)katalanaValues;
}

void * get_primes_list(void * args){
	int n = *(int*)args;
	int *primesArray = malloc(sizeof(int)*n);
    int primesCount = 0;
	for (int j = 2; j < n; j++)
    {
        if (isPrime(j))
        {
            primesArray[primesCount++] = j;
        }
    }
    
	return (void *)primesArray;
}

int main (){
	int num_count = 10;
	int res0, res1;
	unsigned long long *katalana_values;
	int *prime_values; 
	pthread_t thread0, thread1;
	
	res0 = pthread_create(&thread0, NULL, &get_katalana_list, &num_count);
	res1 = pthread_create(&thread1, NULL, &get_primes_list, &num_count);
	
	pthread_join(thread0, (void *)&katalana_values);
	pthread_join(thread1, (void *)&prime_values);
	
	printf("Katalana values:\n");
	for(int i = 0; i < num_count; i++)
		printf("%llu ", katalana_values[i]); 

    printf("\n");

	printf("Prime values: \n");
	for(int i = 0; i < num_count; i++)
        if (prime_values[i] != 0)
        {
            printf("%d ", prime_values[i]);
        }
        
	return 0;
}
