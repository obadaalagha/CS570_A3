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
