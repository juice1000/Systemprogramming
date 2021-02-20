#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h> // for memset


typedef enum State{
    gather,
    copy_data
} State;

State s = gather;
pthread_mutex_t buffer;
pthread_mutex_t s;
pthread_cond_t calc_ready;
pthread_cond_t gather_ready;


int main(){


}