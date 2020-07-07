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
/* To hold data for our threads                                             */
static sigset_t signal_mask; /*signals to block                             */

void start_threads(struct timers input_t) {
    printf("Reached start threads\n");
    pthread_t main_t;   /* Our main thread                                  */
    int rc;             /* error code                                       */
    long t_id;          /* thread id                                        */
    /* Create the main thread                                               */
    rc = pthread_create(&main_t,NULL,main_thread,(void *)&input_t);
    check_t_err(rc);
    pthread_exit(NULL);
}

void *main_thread(void *thread_arg){
    printf("Main thread\n");
    
    struct timers *my_timers;
    my_timers = (struct timers *) thread_arg;

    int alarm_time = my_timers->alarm_time;

    pthread_t threads[NUM_THREADS]; /* Create our thread array              */
    int rc;                         /* Ret/Err code when creating thread    */
    pthread_attr_t attr;            /* Thread attribute to set our threads  */
    void *status;                   /* Status for joining our threads       */
    
    /*  Initiate attribute and set as joinable                              */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    /* set signals                                                          */
    sigemptyset(&signal_mask);
    sigaddset(&signal_mask,SIGINT);
    sigaddset(&signal_mask,SIGALRM);
    pthread_sigmask(SIG_BLOCK,&signal_mask,NULL);


    /* Create threads with their own function threads                       */
    rc = pthread_create(&threads[0],&attr,sig_handler_thread, NULL);
    check_t_err(rc);
    rc = pthread_create(&threads[1],&attr,counter_thread, NULL);
    check_t_err(rc);
    rc = pthread_create(&threads[2],&attr,clock_thread, NULL);
    check_t_err(rc);
    rc = pthread_create(&threads[3],&attr,alarm_thread, NULL);
    check_t_err(rc);


    /* join our threads to wait till all threads are done                   */
    int t_id;
    pthread_attr_destroy(&attr);
    for(t_id=0;t_id<NUM_THREADS; t_id++){
        rc = pthread_join(threads[t_id],&status);
        /* If pthread_join was not successful it returns a positive number  */
        if(rc){
            printf("ERROR; return code from pthread_join() is %d\n",rc);
            exit(EXIT_FAILURE);
        }
    }
    /* Free attribute */
    printf("Threads done.\n");
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

    int sig_caught;         /* signal catcher for our threads               */
    sigwait(&signal_mask,&sig_caught);
    
    switch (sig_caught){
        case SIGINT:
            printf("\nInterrupted\n"); 
            break;
        case SIGALRM:
            printf("alarm\n");
            break;
        default:
            printf("\nUnexpected signal %d\n",sig_caught);
            break;
    }

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

