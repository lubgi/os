#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define TIMESPAN_SECONDS 5

int main() {
	pid_t pid = fork();
	time_t start = time(NULL);
	int childCounts = 0, parentCounts = 0;
	while(time(NULL) < start + TIMESPAN_SECONDS){
		if(pid == 0){
			childCounts++;
		}
		if(pid > 0){
			parentCounts++;
		}
	}

    if (pid > 0)
    {
        printf("Parent counts: %d\n", parentCounts);
    }
    if (pid == 0)
    {
        printf("Child counts:  %d\n", childCounts);
    }

	return 0; 
}
