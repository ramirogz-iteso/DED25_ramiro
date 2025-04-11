#include "queue.h"
#include <stdlib.h>

/* Queue */
struct node_str {
  void * data;
  struct node_str * next;
};

typedef struct node_str node;

struct queue_str {
  node * head;  // first
  node * tail;  // last
  int size;
};

/* creates a new queue and inits all pointers */
queue * queue_create() {
  queue * q = (queue *) malloc(sizeof(queue));
  q->head = NULL;
  q->tail = NULL;
  q->size = 0;
  return q;
}

/* destroys a queue, frees all the memory */
void queue_destroy(queue * q) {
  node * current = q->head;
  while(current != NULL) {
    node * next = current->next;
    free(current);
    current = next;
  }
  free(q);
}

/* get queue size */
int queue_size(queue * q) 
{
  return q->size;
}

/* Returns TRUE or FALSE if the queue is empty */
boolean queue_isEmpty(queue * q) 
{
  if(q->size == 0)
    return TRUE;
  else
    return FALSE;
}

/* Insert in the queue q, the info data */
void queue_enqueue(queue * q, void * data) 
{
  node * n = (node *) malloc(sizeof(struct node_str));
  n->data = data;
  n->next = NULL;
  if(queue_isEmpty(q)) 
  {
    q->head = n;
  } 
  else 
  {
    q->tail->next = n;
  }
  q->tail = n;
  q->size ++;
}

/* see first element  */
void * queue_peek (queue * q) 
{
  if(queue_isEmpty(q)) return NULL;
  return q->head->data;
}

/* removes from the queue */
void * queue_dequeue(queue * q) 
{
  if(queue_isEmpty(q)) return NULL;
  node * n = q->head;
  q->head = q->head->next;
  void * data = n->data;
  free(n);
  q->size --;
  return data;
}