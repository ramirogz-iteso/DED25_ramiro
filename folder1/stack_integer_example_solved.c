#include <stdio.h>
#include <stdlib.h>

/* OJO Todo este stack, funciona solo con numeros enteros, ya que 
el nodo del Stack guarda un valor entero. En el proximo parcial
veremos como mejorar esto y generalizarlo utilizando un 
TDA (Tipo de dato abstracto) */

// Estructura para crear un stack_node, esta tendra el previous node
typedef struct stack_node {
    int info;
    struct stack_node *prev;
}stack_node;

/* STACK GLOBAL */
stack_node *stack_top = NULL;
int count = 0;

// Operacion Push() para meter elementos al stack 
void push(int data) 
{
  /* insertar siempre es posible, crear el nodo */
  stack_node *new_node  = (stack_node *)malloc(sizeof(struct stack_node));
  new_node->info = data;

  /* si es el primer nodo del stack */
  if (stack_top == NULL)
  {
    stack_top = new_node;
    stack_top->prev = NULL;
  }
  else
  {
    new_node->prev = stack_top;
    stack_top = new_node;
  }
  count++;
  printf("\tNode is Inserted\n");
}

// Para esta version de stack de enteros, regresa -1 si no hay 
// nada que hacer pop
int pop() 
{
  stack_node *nptr = stack_top;

  if (nptr == NULL)
  {
      printf("\nStack Underflow\n");
      return -1;
  }
  else
  {
    nptr = nptr->prev;
  }

  int popped = stack_top->info;
  free(stack_top);
  stack_top = nptr;
  count--;
  return popped;
}

// Muestra los elementos actuales del stack
void display() 
{
  stack_node * nptr = stack_top;
  
  if (nptr == NULL)
  {
      printf("\nStack Underflow\n");
      return;
  }
  
  printf("The stack is \n");
  while (nptr != NULL)
  {
      printf("%d--->", nptr->info);
      nptr = nptr->prev;
  }
  printf("NULL\n\n");
}

int main() 
{
  int choice, value, ret;
  printf("\nSTACK:\n");
  while (1) 
  {
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    printf("\n\tChoice : ");
    ret = scanf("%d", &choice);
    switch (choice) 
    {
      case 1:
        printf("\tEnter the value to insert: ");
        ret = scanf("%d", &value);
        push(value);
        break;
      case 2:
        printf("Popped element is :%d\n", pop());
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("\nWrong Choice\n");
    }
  }
}