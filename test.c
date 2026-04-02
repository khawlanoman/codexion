#include <pthread.h>
#include <stdio.h>


void *print_it(){
    printf("HELLO");
    return NULL;
}


int main(){
        pthread_t t1;

        pthread_create(&t1,NULL, print_it,NULL);    
        pthread_join(t1, NULL);
}