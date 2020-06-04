#include "../lib/PRIOP.h"
#include <stdio.h>



process* PRIOP_tick (process* running_process){
    if (running_process==NULL || running_process->time_left==0){
        running_process=queue_poll(PRIOP_queue);
    }
    if(PRIOP_queue->next != NULL){
        front_process = queue_peek(PRIOP_queue);
        
        if(running_process->priority < front_process->priority){
            queue_add_PRIOP(running_process,PRIOP_queue);
            running_process=queue_poll(PRIOP_queue);
        }
    }
    if (running_process!=NULL){
        running_process->time_left--;
    
    }

    return running_process;
}

int PRIOP_startup(){
    PRIOP_queue=new_queue();
    if (PRIOP_queue==NULL){
        return 1;
    }
    return 0;
}

process* PRIOP_new_arrival(process* arriving_process, process* running_process){
    if(arriving_process!=NULL){
        
        queue_add_PRIOP(arriving_process,PRIOP_queue);
    }
    return running_process;
}

void PRIOP_finish(){
   free_queue(PRIOP_queue);
}