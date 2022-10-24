#include <stdlib.h>
#include <stdio.h>

typedef struct {
    unsigned long size,resident,share,text,lib,data,dt;
} statm_t;

int main(int argc, char *argv[]){
    char* text = malloc(1000*sizeof(char));
    text = getenv(argv[1]);
    if (text == NULL)
    {   
        statm_t result;
        const char* statm_path = "/proc/self/statm";

        FILE *f = fopen(statm_path,"r");
        fscanf(f,"%ld %ld %ld %ld %ld %ld %ld",
            &result.size,&result.resident,&result.share,&result.text,&result.lib,&result.data,&result.dt);
        fclose(f);
        sprintf(text, "Size: %ld\nResident: %ld\nShare: %ld\nText: %ld\nLib: %ld\nData: %ld\nDT:: %ld\n", result.size, result.resident, result.share, result.text, result.lib, result.data, result.dt);
    }
    
    printf("%s", text);
}

