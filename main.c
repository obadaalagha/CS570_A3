/*******************************************************************************
 * Obada Alagha cssc2115 RedID: 819 852 274
 * Amiel Nava   cssc2124 RedID: 824 264 864
 * CS570 Summer 2020
 * Project:    Assignment #3, Management of Threads
 * Filename:   main.c
 * Notes:      
 ******************************************************************************/

#include "header.h"

int main(int argc, char **argv) {
    /* Call functions to parse the input */
    validate_args(argc);
    set_timers(argc,argv);
    start_threads();

    //parse_input(argc, argv);

    return 0;
}
