#include "../lib/HRRN.h"
#include <stdlib.h>
#include <stdio.h>

// THIS SCRIPT WAS DEVELOPED BY JULIEN LOOK

process* HRRN_tick (process* running_process){
    update_HRRN(HRRN_queue);
    if (running_process==NULL || running_process->time_left==0){
        running_process = queue_poll_HRRN(HRRN_queue);
    }
    if (running_process!=NULL){
        running_process->time_left--;
    }
    return running_process;
}
int HRRN_startup(){
    HRRN_queue=new_queue();
    if (HRRN_queue==NULL){
        return 1;
    }
    return 0;
}

process* HRRN_new_arrival(process* arriving_process, process* running_process){
    if(arriving_process!=NULL){
        queue_add_HRRN(arriving_process, HRRN_queue);
    }
    return running_process;
}

void HRRN_finish(){
    free_queue(HRRN_queue);
}