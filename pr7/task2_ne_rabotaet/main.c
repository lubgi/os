#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

struct thread_arg{
	char* name;
	char* str;
	int i;
};

void * child_func(void * arg){
	struct thread_arg targ = *(struct thread_arg *) arg;
	for(; targ.i > 0; targ.i--){
		printf("Thread %s. %s %d\n", targ.name, targ.str, targ.i);
	}
	return NULL;
}

int main (){

    for (int i = 0; i < 4; i++)
    {
        struct thread_arg targ;
        pthread_t thread;
        targ.i = i;
        
        
        pthread_create(&thread, NULL, &child_func, &targ);
    }
    
	sleep(1);
	return 0;
}
