#include "prio_q.h"

struct prio_q * prio_q_create()
{
	struct prio_q * q = malloc(sizeof(struct prio_q));
	q->size = 0;
	q->front = NULL;
	printf("\n Created Queue");
	return (q);
}



void prio_q_enqueue(struct prio_q *q, void *data)
{
	struct prio_q_elem * elem = malloc(sizeof(struct prio_q_elem));
	elem->data = data;
    elem->next = NULL;
	

	if (q->front == NULL){
		q->front = elem;
	}
	else{
		struct prio_q_elem * tmp = q->front;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = elem;
	}
    //printf("\n %p enqueued to queue", data);
}

void * prio_q_dequeue(struct prio_q *q)
{
	
}

void * prio_q_front(struct prio_q *q)
{
	// TODO
}

int prio_q_destroy(struct prio_q *q, void ** data)
{
	// TODO
}

void prio_q_print(struct prio_q * q, void (*print_data)(void*))
{
	// Implementierung dieser Funktion ist OPTIONAL und wird daher NICHT BEWERTET!
	struct prio_q_elem * tmp = q->front;
	printf("\n Values: \n");
	// print data -> pointer auf data

	while (tmp != NULL){
		print_data(tmp->data);
		printf("\n");
		tmp = tmp->next;
	}
	
}
