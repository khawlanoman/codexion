#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

void *print_it(){
    printf("HELLO");
    return NULL;
}


int main(){
     struct timeval tv;
     gettimeofday(&tv,NULL);
     printf("%ld, %ld",tv.tv_sec,tv.tv_usec);
     
}
