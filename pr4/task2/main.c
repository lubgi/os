#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "ho:c")) != -1){
        switch (opt) {
            case 'h': 
                printf("Usage:\nh - help\no out_file_name - custom ouput file name\nc - special mode\n"); 
                return 0;
            case 'o': 
                printf("out_file_name: %s\n", optarg);
                break;
            case 'c': 
                printf("You have entered the special mode\n"); 
                break;
            case '?': 
                printf("Parameter %c requires value!\n", optopt); 
                break;
        }
    }
    return 0; 
}
