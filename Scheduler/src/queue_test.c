#include "../lib/queue.h"
#include "../lib/process.h"
#include <stdlib.h>
#include <stdio.h>

//TODO: Fehlerbehandlung
int queue_add(void* new_obejct, queue_object* queue){
    queue_object* new_queue_object= calloc(1,sizeof(queue_object));
    if (new_queue_object==NULL){
        return 1;
    }
    new_queue_object->object=new_obejct;
    new_queue_object->next=queue->next;
    new_queue_object->waiting_time = 0;

    queue->next = new_queue_object;
    return 0;
}

int queue_add_HRRN(process* new_obejct, queue_object* queue){
    queue_object* new_queue_object= calloc(1,sizeof(queue_object));
    if (new_queue_object==NULL){
        return 1;
    }
    new_queue_object->object=new_obejct;
    new_queue_object->next=queue->next;
    new_queue_object->waiting_time = 0;

    //printf("PROBLEM WITH INITIALIZATUO");
    new_queue_object->rr = 1.0;
    new_queue_object->service_time = new_obejct->time_left;

    queue->next = new_queue_object;
    return 0;
}

int queue_add_PRIOP(process* new_obejct, queue_object* queue){
    queue_object* new_queue_object= calloc(1,sizeof(queue_object));
    if (new_queue_object==NULL){
        return 1;
    }
    new_queue_object->object = new_obejct;
    new_queue_object->next = NULL;
    new_queue_object->priority = new_obejct->priority;


	queue_object * prev = queue;  
    while(prev->next != NULL && prev->next->priority < new_queue_object->priority){ //slides the newly added element through the queue until it reaches its correct position
    	prev=prev->next;		
    }
	queue_object * tmp = prev->next;
    prev->next = new_queue_object;
    new_queue_object->next = tmp;

	return 0;
}

int queue_add_SRTNP(process* new_obejct, queue_object* queue){
    queue_object* new_queue_object= calloc(1,sizeof(queue_object));
    if (new_queue_object==NULL){
        return 1;
    }
    new_queue_object->object = new_obejct;
    new_queue_object->next = NULL;
    new_queue_object->time_left = new_obejct->time_left;


	queue_object * prev = queue;  
    while(prev->next != NULL && prev->next->time_left > new_queue_object->time_left){ //slides the newly added element through the queue until it reaches its correct position
    	prev=prev->next;		
    }
	queue_object * tmp = prev->next;
    prev->next = new_queue_object;
    new_queue_object->next = tmp;

	return 0;
}

int queue_add_MLF(process* new_obejct, queue_object* queue){
    queue_object* new_queue_object= calloc(1,sizeof(queue_object));
    if (new_queue_object==NULL){
        return 1;
    }
    new_queue_object->object = new_obejct;
    new_queue_object->next = NULL;
    queue->next = new_queue_object;

	return 0;
}

void* queue_poll(queue_object* queue){
    if(queue==NULL || queue->next==NULL){
        return NULL;
    }
    queue_object* object_to_find=queue;
    queue_object* previous_object=queue;
    while(object_to_find->next!=NULL){
        previous_object=object_to_find;
        object_to_find=object_to_find->next;
    }
    previous_object->next=NULL;
    void* object=object_to_find->object;
    free(object_to_find);
    return object;
}

int queue_MLF_prio(queue_object* queue){
    if(queue==NULL || queue->next==NULL){
        return NULL;
    }
    queue_object* object_to_find=queue;
    while(object_to_find->next!=NULL){
        object_to_find=object_to_find->next;
    }
    object_to_find->priority = object_to_find->priority +1;
    if (object_to_find->priority > 3){
        object_to_find->priority = 3;
    }
    int power = 1;
	for (int j = 0; j < object_to_find->priority; ++j)
	{
	    power *= 2;
	}
    object_to_find->service_time = 1*power;

    return object_to_find->priority;
}

queue_object* new_queue(){
    queue_object* new_queue=malloc(sizeof(queue_object));
    if (new_queue==NULL){ //In case of an error
        return 0;
    }
    new_queue->next=NULL;
    new_queue->object=NULL;
    return new_queue;
}

queue_object* new_level_queue(){
    int num_queues = 4;
    queue_object* new_level_queue[]=malloc(sizeof(queue_object) * num_queues);
    if (new_level_queue==NULL){ //In case of an error
        return 0;
    }
	
    //initialize queues
    for(int i = 0; i < num_queues; i++){
        new_level_queue[i] = new_queue();
        new_level_queue[i]->next=NULL;
        new_level_queue[i]->object=NULL;
        
    }

    return new_level_queue;



	
	//int time_steps[] = malloc(sizeof(int)*num_queues);
	//int time_steps_left = malloc(sizeof(int)*num_queues);

	
	//	if(i == num_queues-1){
	//		//last Queue (FIFO)
	////	}
		// calculate each time step

		// initialize queues and set time steps
	//new_level_queue[i] = 
	//time_steps[i] = time_step*power;
	//time_steps_left[i] = time_step*power;
}




void free_queue(queue_object* queue){
    queue_object* obj_to_delete=queue->next;
    while(obj_to_delete!=NULL){
        queue->next=obj_to_delete->next;
        //free(obj_to_delete->object);
        free(obj_to_delete);
        obj_to_delete=queue->next;
    }
    free(queue);
}

void* queue_peek(queue_object* queue){
    if(queue==NULL || queue->next==NULL){
        return NULL;
    }
    queue_object* object_to_find=queue;
    while(object_to_find->next!=NULL){
        object_to_find=object_to_find->next;
    }
    return object_to_find->object;
}

void* queue_poll2(queue_object* queue){
    
    if(queue==NULL || queue->next==NULL){
        return NULL;
    }
    queue_object* object_to_find=queue->next;
    //printf("%f \n", queue->next->rr);
    //printf("%f \n", queue->next->service_time);
    printf("%d outer scope\n", object_to_find->waiting_time);
    void* object = object_to_find->object;
    queue->next = queue->next->next;
    free(object_to_find);
    return object;
}

void response_rate(queue_object* queue){

    queue->rr = (queue->waiting_time + queue->service_time)/ queue->service_time;
    printf(" rr is %f", queue->rr);
}
//
//int queue_add_HRRN(process* new_obejct, queue_object* queue){
//    queue_object* new_queue_object= calloc(1,sizeof(queue_object));
//    if (new_queue_object==NULL){
//        return 1;
//    }
//    new_queue_object->object = new_obejct;
//    new_queue_object->next = NULL;
//    new_queue_object->time_left = new_obejct->time_left;
//
//
//	queue_object * prev = queue;  
//    while(prev->next != NULL){
//        printf("PROBLEM WITH RR CALC");
//        prev->rr = response_rate(prev->waiting_time, prev->service_time);
//        prev = prev->next;
//    }
//
//    queue_object * prev2 = queue;  
//    while(prev2->next->next != NULL && prev2->next->rr < new_queue_object->rr){ //slides the newly added element through the queue until it reaches its correct position
//    	prev=prev->next;		
//    }
//	queue_object * tmp = prev->next;
//    prev->next = new_queue_object;
//    new_queue_object->next = tmp;
//
//	return 0;
//}
//
void HRRN_rearrange(queue_object* queue){

    queue_object * prev = queue; 
    float max_rr = 0.0;
    queue_object * front = queue;
    while(prev->next != NULL){
        response_rate(prev);
        if (prev->rr > max_rr){
            max_rr = prev->rr;
        }
        prev = prev->next;
    }

    printf(" max rr is %f", max_rr);

    queue_object * prev2 = queue;
    while(prev2->next != NULL){
        if(prev2->rr == max_rr){
            front = prev2;
        }
        prev2 = prev2->next;
    }

    front->next = prev2->next;
    prev2->next = front;

    while(queue->next != NULL && queue->next->rr != max_rr){
        printf("\nqueue %f and front %f", queue->next->rr, max_rr);
        queue = queue->next;
        
    }
    queue_object* tmp_obj=queue->next;
    void * temp = tmp_obj->next->object;
    queue->next = queue->next->next;
    free(temp);
    
}