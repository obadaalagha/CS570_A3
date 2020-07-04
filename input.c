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
            case 2:
                printf("***Error. Only one argument entered out of 3\n");
                break;
            case 3:
                printf("***Error. Only two arguments entered out of 3\n");
                break;
            default:
                printf("***Error. More than three arguments entered.\n");
        }
        printf("Please restart application and only enter zero or three arguments.\n");
        printf("Now exiting...\n");
        exit(EXIT_FAILURE);
    }
}
/* Set the timers in our timers structure. Then it checks if inputs are ok    */
void set_timers(int argc, char **argv){
    /* Use default values if user entered no arguments                        */
   if(argc == 1){
       input_t.run_time = DFL_RUN_TIME;
       input_t.print_time = DFL_PRINT_TIME;
       input_t.alarm_time = DFL_ALARM_TIME;
   }
   /* Enter the user's arguments and then check if they are valid             */
   else{
       input_t.run_time = (int) strtol(argv[1],(char **)NULL,10);
       input_t.print_time = (int) strtol(argv[2],(char **)NULL,10);
       input_t.alarm_time = (int) strtol(argv[3],(char **)NULL,10);
       validate_input();    /* Checks if inputs are valid                     */
   }
}
/* Will handle any incorrect inputs from user and display a message           */
void validate_input(){
    /* Check if user entered negative values for arguments                    */
    if(input_t.run_time < 0 || input_t.print_time < 0 || input_t.alarm_time < 0){
        printf("***Error. Negative input entered for arguments.\n");
        printf("Now exiting...\n");
        exit(EXIT_FAILURE);
    }
    /* Checks if if print_time value is valid                                 */
    if((input_t.print_time) != 1 && (input_t.print_time != 60) ){
        printf("Incorrect input for print frequency time (second arg).\n");
        printf("Print frequency must be 1 or 60.\n");
        printf("Now exiting...\n");
        exit(EXIT_FAILURE);
    }
}

void parse_input(int argc, char **argv) {
    /* Declare & intialize the three parameters to the default values */
    int timeToRun = 32;
    int printEvery = 1;
    int totalTime = 17;

    /* Verify how the user inputted the information */
    if(argc == 1) {
        /* If one arg, pass default parameters declared above */
        start_threads(timeToRun, printEvery, totalTime);
    } else if (argc == 4) {
        /* Convert the parameters from strings to integers */
        timeToRun = atoi(argv[1]);
        printEvery = atoi(argv[2]);
        totalTime = atoi(argv[3]);

        /* Check second parameter to see if input is legal or not. */
        if((printEvery == 1) || (printEvery == 60)) {
            /* If input is legal, pass through function */
            start_threads(timeToRun, printEvery, totalTime);
        } else {
            /* If input is illegal, */
            printf("INCORRECT PRINT PARAMETER. PLEASE INPUT 1 OR 60.\n");
            exit(0);
        }
    } else {
        /* If here, user inputted and incorrect number of parameters */
        printf("INCORRECT NUMBER OF PARAMETERS.\n");
        exit(0);
    }
}
