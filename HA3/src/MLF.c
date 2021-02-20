#include "../lib/MLF.h"


// THIS SCRIPT WAS DEVELOPED BY JULIEN LOOK

int MLF_startup(){

    MLF_queue = new_level_queue();
    level = 0;  //First element starts at highest level queue
    if (MLF_queue==NULL){
        return 1;
    }
    return 0;    
}


process* MLF_tick (process* running_process){

    //Set running prc NULL if scheduled time or current level queue quantum has turned 0
    if (running_process == NULL || running_process->time_left == 0 || time_left_quantum == 0){
        // if running prc still active, but time quantum expired, put prc in lower level queue
        if (running_process != NULL && time_left_quantum == 0 && running_process->time_left != 0){
            queue_add(running_process, MLF_queue[level+1]);
            
        }
        // in any case, running prc becomes NULL for current level queue
        running_process = NULL;
    }
    // create tmp running prc that iterates through queues
    process * new_running_process = running_process;

    // Get new running prc from queues, starting at highest level
    if(new_running_process == NULL){
        for(int i = 0; i<level_num; i++){
            new_running_process = queue_poll(MLF_queue[i]);
            if(new_running_process != NULL){
                level = i; // Set level according to queue that has none-empty element at front
               
                if(level == level_num-1){ // FIFO principle, run prc until finished
                    time_left_quantum = new_running_process->time_left;
                }
                else{
                    // Calculate time quantum based on 2^level
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
    // run prc as usual and decrement time variables
    if(new_running_process != NULL){
        new_running_process->time_left--;
        time_left_quantum--;
    }

   return new_running_process;
}

process* MLF_new_arrival(process* arriving_process, process* running_process){
    if(arriving_process!=NULL){
        // always add new prc to highest level queue
        queue_add(arriving_process, MLF_queue[0]);
    }
    return running_process;
}

// Free all level queues + whole MLF_queue
void MLF_finish(){
    for(int i= 0; i<level_num; i++){
        free_queue(MLF_queue[i]);
    }
    free(MLF_queue);
}
