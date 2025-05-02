#include <stdlib.h>
#include "pq.h"

struct pq_str 
{
  void ** heap;		/* heap is the array that will store the data 
                     in the form of a heap */
  int capacity;	  /* physical size/capacity of the array */
  int size;				/* logical size of the priority queue 
                     <--> position of the next element to insert */
  CompareFunc compare;	/* Comparison function between two data items */
};

pq * pq_create(int initialCapacity, CompareFunc compare) 
{
  pq * queue = (pq * ) malloc(sizeof(struct pq_str));
  if(initialCapacity < 1) initialCapacity = 1;

  queue->capacity     = initialCapacity;
  queue->size         = 0;
  queue->compare      = compare;
  queue->heap         = (void *) malloc(initialCapacity * sizeof(void *));

  return queue;
}

int parent(int child) 
{
  //if(child == 0) return -1;
  return (child - 1) / 2;   // (0 - 1) / 2 = -1 / 2 = 0
}

int left(int parent) {
  return 2 * parent + 1;
}

int right(int parent) {
  return 2 * parent + 2;
}

void swap(void ** a, void ** b) {
  void * c = *a;
  *a = *b;
  *b =  c;
}

void pq_offer(pq * q, void * data)
{
  int current_idx = q->size;    // the current index where the element is inserted
  int parent_idx;               // will be used only if needed 
  
  /* insert at the final position */
  q->heap[current_idx] = data;
  q->size++;

  /* nothing else to do if we just inserted the first element */
  if(q->size == 1)
    return;

  /* For all others, we must ensure the heap still maintains
     all its properties and bubble up the inserted value to its final position 
     if necessary:
    current = the current index where the element to insert is
              by default, it's always inserted at the end (at slot size)
    parent  = the parent node of current.
    Both indices will update until the data is in its proper place */
  
  parent_idx = parent(current_idx);

  /* while current has higher priority than its parent, swap */
  while(q->compare(q->heap[current_idx], q->heap[parent_idx]) < 0) 
  {
    swap(&q->heap[current_idx], &q->heap[parent_idx]);
    current_idx = parent_idx;
    parent_idx = parent(parent_idx);

    /* if current reaches index 0, there are no more swaps to do */
    if(current_idx == 0)
     break;  
  }
}

void * pq_peek(pq * q)
{
  if(q->size == 0) return NULL;
  else return q->heap[0];
}

void * pq_poll(pq * q) 
{
  /* if the heap is empty, nothing to return */
  if(q->size == 0) return NULL;

  /* the root will always have the highest-priority element, and that's returned */
  void * toPoll = q->heap[0];
  q->size --;

  /* if it was the only element, no tree to fix, we’re done here */
  if(q->size == 0) return toPoll;

  /* if there were more nodes in the heap, we need to ensure 
     it still satisfies all the properties */

  /* step 1: move the last inserted element to the new root */
  q->heap[0] = q->heap[q->size];
  int current_idx = 0;
  boolean stop_swapping = FALSE;

  /* step 2: bubble down that element until it finds its place,
     swapping with the child of higher priority */
  while(!stop_swapping) 
  {
    int toSwap = current_idx;
    int left_idx = left(current_idx);
    int right_idx = right(current_idx);
    
    /* find the highest-priority child of the current idx */
    if(left_idx < q->size &&
       q->compare(q->heap[left_idx], q->heap[current_idx]) < 0)
    {
      toSwap = left_idx;
    }
    if(right_idx < q->size && 
       q->compare(q->heap[right_idx], q->heap[toSwap]) < 0)
    {
      toSwap = right_idx;
    }

    /* if the value of toSwap changed, we need to perform a swap */
    if(toSwap != current_idx) 
    {
      swap(&q->heap[current_idx], &q->heap[toSwap]);
      current_idx = toSwap;
    }
    else 
    {
      stop_swapping = TRUE;
    }
  }
  return toPoll;
}

int pq_size(pq * q) 
{
  return q->size;
}
