#ifndef STACK_H_

  #define STACK_H_

  typedef int boolean;
  #define TRUE 1
  #define FALSE 0

  typedef struct stack_str stack;

  stack * stack_create();
  void  stack_destroy(stack *);

  int  stack_size(stack *);
  boolean stack_isEmpty(stack *);

  void stack_push(stack *, void *);
  void * stack_pop(stack *);

  //Regresa el elemento del tope, pero NO lo remueve
  void * stack_top(stack *);

#endif
