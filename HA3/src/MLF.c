#include "../lib/MLF.h"


int MLF_startup(){
    for(int i=0; i<4; i++){
        MLF_queue = new_level_queue();
    if (MLF_queue==NULL){
        return 1;
    }
    return 0;
    }
    
}


process* MLF_tick (process* running_process){
// We have to put elements in first queue and set level to 0
// If no elements in first queue, go to next one, etc.
    queue_object* Queue;
// int that gets current level
    int level = 0;

    while(queue_peek(Queue)!=NULL){
        level++;

        if (level == (sizeof(MLF_queue)/sizeof(MLF_queue[0]))-1){
            //Reached last queue
            break;
        }

    }

    Queue = MLF_queue[level];

    //Length of one Sequence
	int power = 1;
	for (int j = 0; j < level; ++j){
		power *= 2;
	}
    this_quantum = power;

    //For both, when FIFO queue process ends || when process of higher-level queues reached end
    //Time_left_quantum extra for higher-level queues
    if (running_process==NULL || running_process->time_left==0){
        time_left_quantum = this_quantum;
        running_process = queue_poll(Queue);  
    }

    if(time_left_quantum == 0 && level != 4){
            queue_add(running_process, Queue); //Push to lower queue level
            running_process = queue_poll(Queue);
            time_left_quantum = this_quantum;
    }

    if (running_process!=NULL){
        running_process->time_left--;
        time_left_quantum--;
        
    }
    
    return running_process;

}

process* MLF_new_arrival(process* arriving_process, process* running_process){
    if(arriving_process!=NULL){
        queue_object* Queue = MLF_queue[0];
        queue_add(arriving_process, Queue);
    }
    return running_process;
}


void MLF_finish(){
    free_queue(MLF_queue);
}