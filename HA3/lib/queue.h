#ifndef QUEUE_H
#define QUEUE_H
#include "process.h"


typedef struct _queue_object{
    void* object;
    struct _queue_object* next;
    //The following attributes were introduced in order to implement the scheduling algorithms
    int priority;      
    int time_left;
    int service_time;
    int waiting_time;
    float rr;
}queue_object;

/**
 * @param new_object pointer to some object you want to add into the FIFO queue
 * @param queue the pointer to a queue you want to add the obejct to 
 * @return 0 if everything was fine
 */
int queue_add(void* new_obejct, queue_object* queue);

/**
 * @param new_object pointer to some object you want to add into the FIFO queue
 * @param queue the pointer to a queue you want to add the obejct to 
 * @return 0 if everything was fine
 * Adds the new element in its correct position according to its priority
 */
int queue_add_PRIOP(process* new_obejct, queue_object* queue);

/**
 * @param new_object pointer to some object you want to add into the FIFO queue
 * @param queue the pointer to a queue you want to add the obejct to 
 * @return 0 if everything was fine
 * Adds the new element in its correct position according to its remaining time
 */
int queue_add_SRTNP(process* new_obejct, queue_object* queue);

/**
 * @param new_object pointer to some object you want to add into the FIFO queue
 * @param queue the pointer to a queue you want to add the obejct to 
 * @return 0 if everything was fine
 * Functions similarly to queue_add and initializes the required attributes for HRRN.c
 */
int queue_add_HRRN(process* new_obejct, queue_object* queue);

/**
 * gets and deletes the newest item from the queue
 * @param queue The pointer to a queue handler you want to poll from
 * @result pointer to an object that was previously added using function int queue_add or NULL if the queue is empty
 */ 
void* queue_poll2(queue_object* queue);

/**
 * calculates the response ratio (rr) for all queue elements and gets and deletes the element with the highest rr
 * @param queue The pointer to a queue handler you want to poll from
 * @result pointer to an object that was previously added using function int queue_add or NULL if the queue is empty
 */ 
void* queue_poll_HRRN(queue_object* queue);
/**
 * increases the waiting time of all elements in the queue by 1
 * @param queue The pointer to a queue handler you want to update 
 */
void update_HRRN(queue_object* queue);

/**
 * gets and deletes the oldest item from the queue
 * @param queue The pointer to a queue handler you want to poll from
 * @result pointer to an object that was previously added using function int queue_add or NULL if the queue is empty
 */ 
void* queue_poll(queue_object* queue);

/**
 * Creates and returns a new queue. Should be called before working with the queue.
 * @result a pointer to a new queue handler.
 */
queue_object* new_queue();

/**
 * deletes and frees all queue items
 * @param queue The pointer to the queue you want to delete
 */
void free_queue(queue_object* queue);


/**
 * gets the oldest item in the queue, but doesn't delete it
 * @param queue Pointer to the queue you want to peek from
 * @result pointer to an object that was previously added using queue add or NULL if the queue is empty
 */
void* queue_peek(queue_object* queue);
#endif //QUEUE_H