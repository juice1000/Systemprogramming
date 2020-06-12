#include "../lib/MLF.h"



int MLF_startup(){

    MLF_queue = new_level_queue();
    //this_quantum = initial_quantum;
    //time_left_quantum = initial_quantum;
    level = 0;
    if (MLF_queue==NULL){
        return 1;
    }
    return 0;    
}


process* MLF_tick (process* running_process){

    if (running_process == NULL || running_process->time_left == 0 || time_left_quantum == 0){
        
        if (running_process != NULL && time_left_quantum == 0 && running_process->time_left != 0){
            queue_add(running_process, MLF_queue[level+1]);
            
        }
        running_process = NULL;
    }
    process * new_running_process = running_process;

    if(new_running_process == NULL){
        for(int i = 0; i<level_num; i++){
            new_running_process = queue_poll(MLF_queue[i]);
            if(new_running_process != NULL){
                level = i;
               
                if(level == level_num-1){
                    time_left_quantum = new_running_process->time_left;
                }
                else{
                    int power = 1;
                    for (int j = 0; j < level; j++){
	                    power *= 2;
                    }
                    time_left_quantum = power;
                }
                break;

            }
        }
    }

    if(new_running_process != NULL){
        new_running_process->time_left--;
        time_left_quantum--;
    }

   return new_running_process;
}

process* MLF_new_arrival(process* arriving_process, process* running_process){
    if(arriving_process!=NULL){
        queue_add(arriving_process, MLF_queue[0]);
    }
    return running_process;
}


void MLF_finish(){
    for(int i= 0; i<level_num; i++){
        free_queue(MLF_queue[i]);
    }
    free(MLF_queue);
}
