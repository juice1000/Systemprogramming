#include "../lib/SRTNP.h"
#include <stdio.h>
#include <stdlib.h>



process* SRTNP_tick (process* running_process){
    if (running_process==NULL || running_process->time_left==0){
        running_process=queue_poll(SRTNP_queue);
    }
    if(SRTNP_queue->next != NULL){
        front_process = queue_peek(SRTNP_queue);
        
        if(running_process->time_left > front_process->time_left){
            queue_add_SRTNP(running_process,SRTNP_queue);
            running_process=queue_poll(SRTNP_queue);
        }
    }
    if (running_process!=NULL){
        running_process->time_left--;
        
    
    }
    
    return running_process;
}

int SRTNP_startup(){
    SRTNP_queue=new_queue();
    if (SRTNP_queue==NULL){
        return 1;
    }
    return 0;
}

process* SRTNP_new_arrival(process* arriving_process, process* running_process){
    if(arriving_process!=NULL){
        
        queue_add_SRTNP(arriving_process,SRTNP_queue);
    }
    return running_process;
}

void SRTNP_finish(){
   free_queue(SRTNP_queue);
}