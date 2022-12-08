#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define CHILD_SLEEP_SECONDS 2
#define PARENT_SLEEP_SECONDS 1

void* childLoopedPrint(void * args){
	for(int i = 1; i <= 10; i++){
		printf("Child Thread. Iteration: %d\n", i);
		sleep(CHILD_SLEEP_SECONDS);
	}
}

int main (){
    pthread_t threadId;
    pthread_create(&threadId, NULL, &childLoopedPrint, NULL);

	for(int i = 1; i <= 10; i++){
		printf("Main Thread. Iteration: %d\n", i);
		sleep(PARENT_SLEEP_SECONDS);
	}
	return 0;
}
