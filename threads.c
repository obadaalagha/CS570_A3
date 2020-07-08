/*******************************************************************************
 * Obada Alagha cssc2115 RedID: 819 852 274
 * Amiel Nava   cssc2124 RedID: 824 264 864
 * CS570 Summer 2020
 * Project:    Assignment #3, Management of Threads
 * Filename:   threads.c
 * Notes:
 ******************************************************************************/
#include <pthread.h>
#include <time.h>
#include "header.h"

/* To hold data for our threads                                               */
static sigset_t signal_mask;        /* Signals to block                       */
pthread_t threads[NUM_THREADS];     /* Create our thread array                */
/* Volatile variable used so it is safe to use among threads and we tell      */
/* the compiler to not optimize this variable giving it a value of 1 in loop  */
volatile sig_atomic_t stop_timer;       

void start_threads(struct timers *input_t) {
    pthread_t main_t;               /* Our main thread                        */
    int rc;                         /* error code from create thread          */
    /* Create the main thread                                                 */
    rc = pthread_create(&main_t,NULL,main_thread,input_t);
    check_t_err(rc);
    pthread_exit(NULL);             /* Exit main thread                       */

}

void *main_thread(void *thread_arg){
    int rc;                         /* Ret/Err code when creating thread      */
    pthread_attr_t attr;            /* Thread attribute to set our threads    */
    void *status;                   /* Status for joining our threads         */
    
    /*  Initiate attribute and set as joinable                                */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    /* set signals                                                            */
    sigemptyset(&signal_mask);      /* Create empty set                       */
    /* Add signals to be masked                                               */
    sigaddset(&signal_mask,SIGUSR1);/* Using SIGUSR to sig user alarm timer   */ 
    sigaddset(&signal_mask,SIGALRM);/* To set alarm when timer stops          */
    /* Add the signals that will be threads by the threads                    */
    pthread_sigmask(SIG_BLOCK,&signal_mask,NULL);

    /* Create threads with their own function threads                         */
    rc = pthread_create(&threads[0],&attr,sig_handler_thread, NULL);
    check_t_err(rc);
    rc = pthread_create(&threads[1],&attr,alarm_thread, thread_arg);
    check_t_err(rc);
    rc = pthread_create(&threads[2],&attr,counter_thread, thread_arg);
    check_t_err(rc);
    rc = pthread_create(&threads[3],&attr,clock_thread, thread_arg);
    check_t_err(rc);


    /* Join our threads and busy wait till all threads are done               */
    int t_id;                       /* thread index for our thread arr        */
    pthread_attr_destroy(&attr);  /* Free attribute                           */
    for(t_id=0;t_id<NUM_THREADS; t_id++){
        rc = pthread_join(threads[t_id],&status);
        /* If pthread_join was not successful it returns a positive number    */
        if(rc){
            printf("ERROR; return code from pthread_join() is %d\n",rc);
            exit(EXIT_FAILURE);
        }
    }
    printf("Timers are shutdown.\n"); /* Print friendly exit of timers        */    
    printf("Now exiting program....\n");    /* Print friendly exit            */
    pthread_exit(NULL);             /* Exit main thread                       */
}

void check_t_err(int rc){
    if(rc){
        printf("ERROR; return code from pthread_create() is %d\n",rc);
        exit(EXIT_FAILURE);
    }
}

void *sig_handler_thread(void *thread_arg){
    int sig_caught;                 /* signal catcher for our threads         */
    while(!stop_timer){
        /* Wait until a a pending signal is generated                         */
        sigwait(&signal_mask,&sig_caught); 
        /* Decide what appropriate action to do with the generated action     */
        switch (sig_caught){
            /* SIGALARM caused by the first argument. Will exit threads       */
            case SIGALRM:
                stop_timer =1;      /* Signal all threads to stop             */
                /* Print friendly message that timers are stopping            */
                printf("Wow! Look at how the time has passed...\n"); 
                printf("Shutting down timers....\n");
                /* Close of the alarm thread so it wont run anymore           */
                pthread_cancel(threads[1]);
                break;
            /* SIGUSR1 signal caused by the third argument of the user        */
            case SIGUSR1:
                /* Print friendly alarm                                       */
                printf("BEEP BEEP BEEP BEEP BEEP\n");
                break;
            /* In case for whatever reasons we pick up a random signal        */
            default:
                printf("\nWoops! Unexpected signal %d caught. \n",sig_caught);
                break;
        }
    }
    pthread_exit(NULL);             /* Exit signal handler thread             */
}

void *alarm_thread(void *thread_arg){
    struct timers *my_timers;
    my_timers = (struct timers *) thread_arg;
    sleep(my_timers->alarm_time);   /* Sleep for whatever argv[3] is          */
    /* Send signal handler when waken up from a good sleep                    */
    pthread_kill(threads[0],SIGUSR1);   
    pthread_exit(NULL);             /* Exit user alarm thread                 */
}
void *counter_thread(void *thread_arg){
    struct timers *my_timers;
    my_timers = (struct timers *) thread_arg;
    alarm(my_timers->run_time);     /* Set alarm to stop all timers           */
    pthread_exit(NULL);             /* Exit timer countdown thread            */
}

void *clock_thread(void *thread_arg){
    struct timers *my_timers;
    my_timers = (struct timers *) thread_arg;
    time_t t;                       /* To get our current time                */
    /* Will print time at a frequency the user enter in argv[2] (1sec/1min)   */
    /* Will print until the timer has expired                                 */
    while(!stop_timer){
        time(&t);                   /* Get current time                       */
        printf("%s",ctime(&t));     /* Print the str formatted time           */ 
        sleep(my_timers->print_time);   /* Go back to sleep                   */
    }
    pthread_exit(NULL);             /* Exit clock thread                      */
}
