#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

pid_t createChildProcess(int *counter){
    pid_t childPid = fork();
    if (childPid == 0)
    {
        *counter += 1;
    }

    return childPid;
}

int main() {
    int counter = 0;
    
    
	return 0; 
}
