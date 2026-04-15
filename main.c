#include <stdio.h>
#include "head.h"

int main(int argc, char **argv){
    if (argc == 9){
        int number_of_coders;
        long time_to_burnout;
        long time_to_compile;
        long time_to_debug;
        long time_to_refactor;
        int number_of_compiles_required;
        long dongle_cooldown;
        char *scheduler;

        number_of_coders = atoi(argv[1]);
        time_to_burnout = atoi(argv[2]);
        time_to_compile = atoi(argv[3]);
        time_to_debug = atoi(argv[4]);
        time_to_refactor = atoi(argv[5]);
        number_of_compiles_required = atoi(argv[6]);
        dongle_cooldown = atoi(argv[7]);
        scheduler = argv[8];
        
    }
}