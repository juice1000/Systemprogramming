// DIES IST EINE VOGABE, NICHT EDITIEREN!
#ifndef PRIO_Q_H
#define PRIO_Q_H

#include <stdio.h>
#include <stdlib.h>

// forward declaration for priority queue element
struct prio_q_elem;

// struct representing the priority queue
struct prio_q {
	int size;                   // number of elements in queue
	struct prio_q_elem *front;  // first element in queue
};

// struct representing an element in the priority queue
struct prio_q_elem {
    void * data;                // user data
    int priority;               // priority of the element
    struct prio_q_elem * next;  // pointer to next element in the queue
};

/**
 * Allocates and initializes priority queue.
 * Returns pointer to new priority queue.
 */
struct prio_q * prio_q_create();

/**
 * Enqueues data in queue with given priority.
 * q: Pointer to initialized priority queue.
 * data: Pointer to arbitrary user data to be added to the queue.
 * prio: Priority of the data being pushed. A higher value corresponds to a higher priority.
 */
void prio_q_enqueue(struct prio_q *q, void *data, int prio);

/**
 * Returns and extracts (dequeues) the front element, that is the element with the highest priority.
 * q: Pointer to initialized priority queue.
 * Returns the data pointer of the element with the highest priority or NULL if the queue is empty.
 */
void * prio_q_dequeue(struct prio_q *q);

/**
 * Returns the element with the highest priority without changing the queue.
 * q: Pointer to initialized priority queue.
 * Returns the data pointer with the highest priority or NULL if the queue is empty.
 */
void * prio_q_front(struct prio_q *q);

/**
 * Destroys the queue and all of its elements.
 *  If parameter 'data' is not NULL, the data pointers, held by the elements,
 *  are written into data[0], data[1], ... , data[n-1], with data[0] beeing the data in the first/front element.
 *  Otherwise the data pointers are discarded and will no longer be accessible via the queue.
 * q: Pointer to inititalized priority queue.
 * data: an array of data pointers
 * Returns the number of data pointers written into the 'data' array
 */
int prio_q_destroy(struct prio_q *q, void** data);

/**
 * Print all the elements in the queue to stdout
 * q: pointer to priority queue
 * print_data: pointer to function that receives the data held by each element and prints it to stdout
*/
void prio_q_print(struct prio_q * q, void (*print_data)(void*));

#endif
