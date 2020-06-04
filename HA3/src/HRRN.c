#include "../lib/HRRN.h"


process* HRRN_tick (process* running_process){

    if (running_process==NULL || running_process->time_left==0){
        running_process=queue_poll(HRRN_queue);
            //check which rr is biggest
    //biggest rr will be put to front
        if (HRRN_queue->next != NULL){
            // while HRRN_queue->next != NULL{}
            // int rr_1 = response_rate(HRRN_front)
             // int rr_2 = response_rate(HRRN_next)

            response_rate(HRRN_queue->waiting_time, HRRN_queue->duration);
        }
    }

    if (running_process!=NULL){
        running_process->time_left--;
        queue_object * prev = queue; 
        while(prev->next != NULL){
            prev->next->waiting_time++;
            prev = prev -> next;
        }
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
        queue_add(arriving_process, HRRN_queue);
    }
    return running_process;
}

void HRRN_finish(){
    free_queue(HRRN_queue);
}