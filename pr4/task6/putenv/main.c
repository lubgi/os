#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc != 2)
    {
        return printf("Use ./program [env_variable_name] [env_variable_value]");
    }
    
    if (putenv(argv[1]) == 0)
    {
        char* env_variable_name = strtok(argv[1], "=");
        return printf("%s=%s", env_variable_name, getenv(env_variable_name));
    }
    
    printf("Something went wrong");
}