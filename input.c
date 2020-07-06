/*******************************************************************************
 * Obada Alagha cssc2115 RedID: 819 852 274
 * Amiel Nava   cssc2124 RedID: 824 264 864
 * CS570 Summer 2020
 * Project:    Assignment #3, Management of Threads
 * Filename:   input.c
 * Notes:      File that will hold the functions to manage the input that the
 *             user will pass when launching the program.
 ******************************************************************************/

#include "header.h"

void validate_args(int argc){
    /* Handle incorrect arguments entered (not 1 nor 4) */
    if(argc != 1 && argc != 4){
        switch(argc){
            case 2:     /* Only 1 arg entered                                 */
                printf("***Error. Only one argument entered out of 3\n");
                break;
            case 3:     /* Only 2 arg entered                                 */
                printf("***Error. Only two arguments entered out of 3\n");
                break;
            default:    /* More than 3 arguments entered                      */
                printf("***Error. More than three arguments entered.\n");
        }
        printf("Please restart application and only enter zero or three arguments.\n");
        printf("Now exiting...\n");
        exit(EXIT_FAILURE);
    }
}
/* Set the timers in our timers structure. Then it checks if inputs are ok    */
void set_timers(int argc, char **argv, struct timers *input_t){
    /* Use default values if user entered no arguments                        */
   if(argc == 1){
       input_t->run_time = DFL_RUN_TIME;
       input_t->print_time = DFL_PRINT_TIME;
       input_t->alarm_time = DFL_ALARM_TIME;
   }
   /* Enter the user's arguments and then check if they are valid             */
   else{
       input_t->run_time = (int) strtol(argv[1],(char **)NULL,10);
       input_t->print_time = (int) strtol(argv[2],(char **)NULL,10);
       input_t->alarm_time = (int) strtol(argv[3],(char **)NULL,10);
       validate_input(input_t);
   }
}
/* Will handle any incorrect inputs from user and display a message           */
void validate_input(struct timers *input_t){
    /* Check if user entered negative values for arguments                    */
    if(input_t->run_time < 1 || input_t->print_time < 1 || input_t->alarm_time < 1){
        printf("***Error. Non-positive input entered for arguments.\n");
        printf("Now exiting...\n");
        exit(EXIT_FAILURE);
    }
    /* Checks if if print_time value is valid                                 */
    if((input_t->print_time) != 1 && (input_t->print_time != 60) ){
        printf("Incorrect input for print frequency time (second arg).\n");
        printf("Print frequency must be 1 or 60.\n");
        printf("Now exiting...\n");
        exit(EXIT_FAILURE);
    }
}
