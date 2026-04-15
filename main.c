#include <stdio.h>
#include "head.h"

int main(int argc, char **argv){
    if (argc == 9){
       
        struct args arg;
        char *err;
        arg.number_of_coders = atoi(argv[1]);
        arg.time_to_burnout = atoi(argv[2]);
        arg.time_to_compile = atoi(argv[3]);
        arg.time_to_debug = atoi(argv[4]);
        arg.time_to_refactor = atoi(argv[5]);
        arg.number_of_compiles_required = atoi(argv[6]);
        arg.dongle_cooldown = atoi(argv[7]);
        arg.scheduler = argv[8];

        err = check_args(arg);
        if (err)
        {
           printf("%s", err);
           return 1;
        }
    }
}