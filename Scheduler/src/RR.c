#include "../lib/RR.h"
#include <stdio.h>


// THIS SCRIPT WAS DEVELOPED BY JULIEN LOOK

process* RR_tick (process* running_process){
    if (running_process==NULL || running_process->time_left==0){
        time_left_quantum = this_quantum;
        running_process = queue_poll(RR_queue);
        
    }
    if(time_left_quantum == 0){
            queue_add(running_process,RR_queue);
            running_process = queue_poll(RR_queue);
            time_left_quantum = this_quantum;
    }
    if (running_process!=NULL){
        running_process->time_left--;
        time_left_quantum--;
        
    }

    return running_process;
}

int RR_startup(int quantum){
    RR_queue = new_queue();
    this_quantum = quantum;
    time_left_quantum = quantum;
    if (RR_queue==NULL){
        return 1;
    }
    return 0;
}


process* RR_new_arrival(process* arriving_process, process* running_process){
     if(arriving_process!=NULL){
        queue_add(arriving_process, RR_queue);
    }
    return running_process;
}


void RR_finish(){
    free_queue(RR_queue);
}