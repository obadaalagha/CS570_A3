/*******************************************************************************
 * Obada Alagha cssc2115 RedID: 819 852 274
 * Amiel Nava   cssc2124 RedID: 824 264 864
 * CS570 Summer 2020
 * Project:    Assignment #3, Management of Threads
 * Filename:   threads.c
 * Notes:
 ******************************************************************************/
#include <pthread.h>
#include "header.h"
#define NUM_THREADS 4
static pthread_barrier_t barrier;
struct thread_data{
    int thread_id;
};

void start_threads(struct timers input_t) {
    printf("Reached start threads\n");
    pthread_t main_t;
    int rc;
    long t_id;
    void *status;
    
    rc = pthread_create(&main_t,NULL,main_thread,(void *)t_id);
    if (rc){
        printf("ERROR; return code from pthread_create for main thread\n");
        exit(EXIT_FAILURE);
    }

    pthread_exit(NULL);


}

void *main_thread(void *thread_arg){

}

void *sig_handler_thread(void *thread_arg){

}

void *counter_thread(void *thread_arg){

}

void *clock_thread(void *thread_arg){

}

void *alarm_thread(void *thread_arg){

}

