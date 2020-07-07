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
struct thread_data{
    int thread_id;
    char *msg;      /*  For Debugging                                       */
};
/* To hold data for our threads                                             */
struct thread_data t_data_arr[NUM_THREADS];

void start_threads(struct timers input_t) {
    printf("Reached start threads\n");
    pthread_t main_t;   /* Our main thread                                  */
    int rc;             /* error code                                       */
    long t_id;          /* thread id                                        */
    /* Create the main thread                                               */
    rc = pthread_create(&main_t,NULL,main_thread,(void *)t_id);
    check_t_err(rc);
    pthread_exit(NULL);
}

void *main_thread(void *thread_arg){
    printf("MAINN\n");
    pthread_t threads[NUM_THREADS]; /* Create our thread array              */
    int rc;                         /* Ret/Err code when creating thread    */
    pthread_attr_t attr;            /* Thread attribute to set our threads  */
    void *status;                   /* Status for joining our threads       */
    
    /*  Initiate attribute and set as joinable                              */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    /* Create threads with their own function threads                       */
    rc = pthread_create(&threads[0],NULL,sig_handler_thread, (void *)&t_data_arr[1]);
    check_t_err(rc);
    rc = pthread_create(&threads[1],NULL,counter_thread, (void *)&t_data_arr[2]);
    check_t_err(rc);
    rc = pthread_create(&threads[2],NULL,clock_thread, (void *)&t_data_arr[3]);
    check_t_err(rc);
    rc = pthread_create(&threads[3],NULL,alarm_thread, (void *)&t_data_arr[3]);
    check_t_err(rc);

    /* join our threads to wait till all threads are done                   */
    int t_id;
    for(t_id=0;t_id<NUM_THREADS; t_id++){
        rc = pthread_join(threads[t_id],&status);
        /* If pthread_join was not successful it returns a positive number  */
        if(rc){
            printf("ERROR; return code from pthread_join() is %d\n",rc);
            exit(EXIT_FAILURE);
        }
    }
    /* Free attribute */
    pthread_attr_destroy(&attr);
    printf("Threads done\n");
    pthread_exit(NULL);
}

void check_t_err(int rc){
    if(rc){
        printf("ERROR; return code from pthread_create() is %d\n",rc);
        exit(EXIT_FAILURE);
    }
}

void *sig_handler_thread(void *thread_arg){
    printf("Signal handler\n");
    pthread_exit(NULL);
}

void *counter_thread(void *thread_arg){
    printf("Counter thread\n");
    pthread_exit(NULL);
}

void *clock_thread(void *thread_arg){
    printf("Clock thread\n");
    pthread_exit(NULL);
}

void *alarm_thread(void *thread_arg){
    printf("Alarm thread\n");
    pthread_exit(NULL);
}

