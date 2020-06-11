#ifndef QUEUE_H
#define QUEUE_H
#include "process.h"


typedef struct _queue_object{
    void* object;
    struct _queue_object* next;
    int priority;
    int time_left;
    int service_time;
    int waiting_time;
    float rr;
    int start_time;
    int id;
}queue_object;

/**
 * @param new_object pointer to some object you want to add into the FIFO queue
 * @param queue the pointer to a queue you want to add the obejct to 
 * @return 0 if everything was fine
 */
int queue_add(void* new_obejct, queue_object* queue);

int queue_add_PRIOP(process* new_obejct, queue_object* queue);

int queue_add_SRTNP(process* new_obejct, queue_object* queue);

void* queue_poll2(queue_object* queue);

//void HRRN_rearrange(queue_object* queue);

int queue_add_HRRN(process* new_obejct, queue_object* queue);

void* queue_poll_HRRN(queue_object* queue);

void update_HRRN(queue_object* queue);

void test_waiting_time(queue_object* queue);

//int update_waiting_time(queue_object* queue , int Currenttime);

//int Currenttime = 0;

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