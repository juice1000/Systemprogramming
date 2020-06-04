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
    queue->next=new_queue_object;
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