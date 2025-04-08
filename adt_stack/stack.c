#include "stack.h"
#include <stdlib.h>

struct node_str {
  void * data;
  struct node_str * prior;
};

typedef struct node_str node;

struct stack_str {
  node * top;
  int size;
};

stack * stack_create() 
{
  stack * stack = malloc(sizeof(struct stack_str));
  stack->top  = NULL;
  stack->size = 0;
  return stack;
}

// destroye el stack, recuerda que liberar la memoria del cliente es
// responsabilidad del cliente.
void stack_destroy(stack * st) 
{
  node * n = st->top;
  while(n != NULL) 
  {
    node * pr = n->prior;
    free(n);
    n = pr;
  }
  free(st);
}

// regresa si el top del stack is NULL (TRUE or FALSE)
boolean stack_isEmpty(stack * st) 
{
  if(st->top == NULL)
    return TRUE;
  else
    return FALSE;
}

// regresa el numero de elementos en el stack
int stack_size(stack * st) 
{
  return st->size;
}

void stack_push(stack * st, void * data) 
{
    node * n = (node *) malloc(sizeof(struct node_str));
    n->data  = data;
    n->prior = st->top;
    st->top  = n;
    st->size ++;
}

void * stack_pop(stack * st) 
{
  if(st->top == NULL)  // pila vacia, imposible hacer pop
    return NULL;

  void * data = st->top->data;
  node * prior = st->top->prior;
  free(st->top);
  st->top = prior;
  st->size --;
  return data;
}

void * stack_top(stack *st)
{
  if(st->top == NULL)
    return NULL;

  void * data = st->top->data;
  return data;
}
