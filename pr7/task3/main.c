#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define EXPECTED_RANDOM_VALUE 2

void * print_iterate(void * args){
	int iter = *(int*)args;
	for(int i = 0; i < iter; i++){
		printf("Iterate Thread. Iteration: %d\n", i);
	}
	return 0;
}

void * random_iterate(void * args){
	int random;
	int iter = *(int*)args;
	for(int i = 0; i < iter; i++){
        random = rand() % 5;
		if(random == EXPECTED_RANDOM_VALUE){
			printf("Pseudo Thread. Generated expected value %d\n", EXPECTED_RANDOM_VALUE);
			return 0;
		}
		printf("Pseudo Thread. Pseudo: %d\n", random);
	}
	return 0;
}

int main (){

	int iterations = 10, pdata;
    srand(time(NULL));
    setbuf(stdout, NULL);
	pthread_t thread0, thread1;
	pthread_create(&thread0, NULL, &random_iterate, &iterations);
	pthread_create(&thread1, NULL, &print_iterate, &iterations);
	
	pthread_join(thread0, (void *)&pdata);
	pthread_join(thread1, (void *)&pdata);
	printf("Main thread. End");
	return 0;
}
