#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc != 3)
    {
        return printf("Use ./program [env_variable_name] [env_variable_value]");
    }
    
    if (setenv(argv[1], argv[2], 1) == 0)
    {
        return printf("%s=%s", argv[1], getenv(argv[1]));
    }
    
    printf("Something went wrong");
}