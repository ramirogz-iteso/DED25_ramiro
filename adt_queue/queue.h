#ifndef QUEUE_H_
  #define QUEUE_H_
  
  typedef int boolean;
  
  #define TRUE 1
  #define FALSE 0
  
  typedef struct queue_str queue;
  
  queue * queue_create();
  void  queue_destroy(queue *);
  
  int   queue_size(queue *);
  boolean  queue_isEmpty(queue *);
  
  // enqueue, form in line

  void queue_enqueue(queue *, void *);  

  // see who is in front (without removing)

  void * queue_peek(queue *);  

  // get out of the queue 
  void * queue_dequeue (queue *);	  	  
  
#endif /* QUEUE_H_ */
