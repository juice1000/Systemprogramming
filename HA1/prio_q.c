#include "prio_q.h"

struct prio_q * prio_q_create() //creates a function that has a pointer to prio q as an output 
{
	struct prio_q * q = malloc(sizeof(struct prio_q));
    //defines a variable named q that can store an address of a variable of the type struct prio_q and allocates enough memory for the struct.
	q->size = 0; //-> is used with pointers pointing to a structure to assigne values to its attributes.
	q->front = NULL;
	printf("\n Created Queue");
	return (q);
}


void prio_q_enqueue(struct prio_q *q, void *data, int prio)
{
	struct prio_q_elem * elem = malloc(sizeof(struct prio_q_elem));
	elem->data = data;
    elem->next = NULL;
	elem->priority = prio;
	

	if (q->front == NULL || elem->priority > q->front->priority){
		elem->next = q->front;
		q->front = elem;
	}

	else{
		struct prio_q_elem * prev = q->front;
    	while(prev->next != NULL && prev->next->priority > elem->priority){
        	prev=prev->next;
		}
		struct prio_q_elem * tmp = prev->next;
    	prev->next = elem;
    	elem->next = tmp;
	}
	
}

void * prio_q_dequeue(struct prio_q *q)
{
    if (q->front == NULL){
        return NULL;
	}
	else{
		struct prio_q_elem * temp = q->front;
		struct prio_q_elem * tmp = q->front->data;

		q->front = q->front->next;
		free(temp);
    	return tmp;
	}
    
}


void * prio_q_front(struct prio_q *q)
{
	if (q->front == NULL){
    	return NULL;
	}
	else{
		return q->front->data;
	}
	
}

int prio_q_destroy(struct prio_q * q, void ** data)
{
	
	int count = 0;

	while (q->front != NULL){
		struct prio_q_elem * tmp = q->front;
		if (q->front->data != NULL){
			data[count] = q->front->data;
			count++;
		}
		q->front = q->front->next;
		free(tmp);
	}

	free(q);
	return count;
}

void prio_q_print(struct prio_q * q, void (*print_data)(void*))
{
	struct prio_q_elem * tmp = q->front;
	printf("\n List Values: ");
	// print data -> pointer auf data

	while (tmp != NULL){
		print_data(tmp->data);
		printf(" ");
		tmp = tmp->next;
	}
	
}