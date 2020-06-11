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
    queue->next = new_queue_object;
    return 0;
}
int queue_add_HRRN(process* new_obejct, queue_object* queue){
    queue_object* new_queue_object= calloc(1,sizeof(queue_object));
    if (new_queue_object==NULL){
        return 1;
    }
    new_queue_object->waiting_time = 0;
    new_queue_object->rr = 1;
    new_queue_object->start_time = new_obejct->start_time;
    //printf("                               start_time = %d\n",new_queue_object->start_time);
    new_queue_object->id = new_obejct->id;
    new_queue_object->service_time = new_obejct->time_left;

    new_queue_object->object=new_obejct;
    new_queue_object->next=queue->next;
    queue->next = new_queue_object;
    //if (queue->next->next == NULL){
    //    printf("                                       id from add = %d\n",queue->next->id);
    //}
    
    //printf("Time-left = %d\n",new_obejct->time_left);
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

void* queue_poll(queue_object* queue){
    //printf("hello from poll\n");
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

queue_object* new_queue(){
    queue_object* new_queue=malloc(sizeof(queue_object));
    if (new_queue==NULL){ //In case of an error
        return 0;
    }
    new_queue->next=NULL;
    new_queue->object=NULL;
    return new_queue;
}

queue_object** new_level_queue(){
    int num_queues = 4;
    queue_object** MLF_queue = malloc(sizeof(queue_object*)*4);
	
    //initialize queues
    for(int i = 0; i < num_queues; i++){
        MLF_queue[i] = new_queue();
        
    }

    return MLF_queue;
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
    void* object = object_to_find->object;
    queue->next = queue->next->next;
    free(object_to_find);
    return object;
}


void update_HRRN(queue_object* queue){
    queue_object* temp = queue;

    while(temp->next != NULL){
        //printf("waiting time before is %d\n",temp->next->waiting_time);
        temp->next->waiting_time = temp->next->waiting_time + 1;
        //printf("waiting time after is %d\n",temp->next->waiting_time);
        temp = temp->next;
    }
}

void test_waiting_time(queue_object* queue){
    queue_object* temp = queue;

    while(temp->next != NULL){
        printf("waiting time after update is %d and id is %d\n",temp->next->waiting_time,temp->next->id);
        temp = temp->next;
    }
}

void* queue_poll_HRRN(queue_object* queue){
    //printf("hello from poll\n");
    if(queue->next==NULL){
        return NULL;
    }
    queue_object* object_to_find=queue;
    queue_object* previous_object=queue;
    while(object_to_find->next!=NULL){
        previous_object=object_to_find;
        object_to_find=object_to_find->next;

        float servicetime = object_to_find->service_time;
        float waitingtime = object_to_find->waiting_time;
        object_to_find->rr = (servicetime + waitingtime) / (servicetime);
        
    }
    object_to_find = queue;
    previous_object = queue;
    queue_object* max = queue;
    queue_object* max_prev = queue;
    max->rr = 1;
    while(object_to_find->next!=NULL){
        previous_object=object_to_find;
        object_to_find=object_to_find->next;
        if(max->rr < object_to_find->rr){
            max = object_to_find;
            max_prev = previous_object;
        }
        
    }
    
    void* object=max->object;
    if(max->next == NULL){
        max_prev->next = NULL;
    }
    max_prev->next = max->next;
    free(max);
    return object;
}
