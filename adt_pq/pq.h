#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

typedef struct pq_str pq;

/* returns < 0 if the first element has higher priority than the second.
   0 if they have the same priority
   >0 if the second element has higher priority than the first */
typedef int (*CompareFunc) (void *, void *);
typedef int boolean;
#define TRUE 1
#define FALSE 0

/* creates a priority queue with "initialCapacity" and uses
"CompareFunc" to order the elements, highest priority first */
pq * pq_create(int initialCapacity, CompareFunc);

/* inserts into the priority queue */
void pq_offer(pq * , void *);

/* tell me which element is next in the priority queue (DOES NOT REMOVE) */
void * pq_peek (pq *);

/* removes an element from the priority queue */
void * pq_poll (pq *);

/* returns the current number of elements in the priority queue
TIP: It’s the index where the next insertion will occur */
int  pq_size (pq *); 

#endif /* PRIORITYQUEUE_H_ */
