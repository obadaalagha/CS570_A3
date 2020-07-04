/*******************************************************************************
 * Obada Alagha cssc2115 RedID: 819 852 274
 * Amiel Nava   cssc2124 RedID: 824 264 864
 * CS570 Summer 2020
 * Project:    Assignment #3, Management of Threads
 * Filename:  debug.c 
 * Notes:       Use to debug only. May be deleted before submission.
 ******************************************************************************/

#include "header.h"
/* Print what we have in the timers structure                                 */
void print_timers(){
    printf("Run time:   %d seconds\n",input_t.run_time);
    printf("Print time: %d seconds\n",input_t.print_time);
    printf("Alarm time: %d seconds\n",input_t.alarm_time);
}
/* Print the arguments entered                                                */
void print_args(int argc, char **argv){
    int index;
    printf("Arguments:  %d\n",argc);
    for(index =0;index<argc;index++){
        printf("%s\n",argv[index]);
    }
}
