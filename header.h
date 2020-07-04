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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Default time values if user does not enter any arguments                    */
#define DFL_RUN_TIME 25     /* Default running time value                      */
#define DFL_PRINT_TIME 1    /* Default print frequency time                    */
#define DFL_ALARM_TIME 17   /* Default alarm time                              */

/* Declare structure to define the timers                                      */
struct timers{
    int run_time;           /* Running time of prog. before it exits           */
    int print_time;         /* Frequency time to print the time                */
    int alarm_time;         /* Alarm time to print notification on terminal    */
};

struct timers input_t;      /* Use to access our timer values                  */

/* Function Prototype Declarations */
void parse_input(int argc, char **argv);

void validate_args(int);
void set_timers(int, char **);
void validate_input();
void print_timers();
void print_args(int,char**);

void start_threads();

#endif
