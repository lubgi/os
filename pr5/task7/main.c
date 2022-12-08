#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char** environ;

int main(int argc, char *argv[]){
    if (argc == 1)
    {
        return clearenv();
    }
    if (argc >= 3)
    {
        return printf("Invalid params");
    }
    
    unsetenv(argv[1]);

    for (int i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}