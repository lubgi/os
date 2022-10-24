#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main(){
    struct utsname info;

    if (uname(&info) == -1)
    {
        perror("Couldnt retrieve info");
        return -1;
    }

    char hostname[100];
    gethostname(hostname, 100);
    
    printf("HostId: %ld\nHostname: %s\nSysname: %s\nNodename: %s\nRealease: %s\nVersion: %s\nMachine: %s\n", gethostid(), hostname, info.sysname, info.nodename, info.release, info.version, info.machine);
}