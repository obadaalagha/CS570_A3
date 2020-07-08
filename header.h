/*******************************************************************************
 * Obada Alagha cssc2115 RedID: 819 852 274
 * Amiel Nava   cssc2124 RedID: 824 264 864
 * CS570 Summer 2020
 * Project:    Assignment #3, Management of Threads
 * Filename:   header.h
 * Notes:      This is the header file used to include libraries, define
 *             constants, global variables, structures, and function prototypes
 *             in order to get the program running.
 *             LAYOUT BY OBADA, ADDITIONS BY AMIEL AS NEEDED.
 ******************************************************************************/

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>          /* To use standar input/output                    */
#include <stdlib.h>         /* Use the standard library                       */ 
#include <string.h>         /* To use string functions                        */
#include <signal.h>         /* To use signals for our threads                 */
#include <unistd.h>         /* To use alarm                                   */
#include <pthread.h>        /* To use threads and its functions               */
#include <time.h>           /* To print the time in our threads               */
/* Default time values if user does not enter any arguments                   */
#define DFL_RUN_TIME 25     /* Default running time value                     */
#define DFL_PRINT_TIME 1    /* Default print frequency time                   */
#define DFL_ALARM_TIME 17   /* Default alarm time                             */
#define NUM_THREADS 4       /* Number of threads needed                       */

/* Declare structure to define the timers                                     */
struct timers{
    int run_time;           /* Running time of prog. before it exits          */
    int print_time;         /* Frequency time to print the time               */
    int alarm_time;         /* Alarm time to print notification on terminal   */
};

/* Function Prototype Declarations */
void validate_args(int);
void set_timers(int, char **,struct timers*);
void validate_input(struct timers*);
void print_timers(struct timers);
void print_args(int,char**);
void start_threads(struct timers*);
void check_t_err(int);
/* Worker threads															  */
void *main_thread(void *);
void *sig_handler_thread(void *);
void *counter_thread(void *);
void *clock_thread(void *);
void *alarm_thread(void *);

#endif
