#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
typedef struct stack_node {
    char info;
    struct stack_node *prev;
}stack_node;

/* STACK GLOBAL */
stack_node *stack_top = NULL;
int count = 0;

int main() 
{
  char formula1[30] = "aa()bb({c})(ddd((rr((a)a))))";
  char formula2[30] = "((a+b)-(z*d))";

  isvalidformula(formula1);
  isvalidformula(formula2);
}

// Push() operation on a stack
void push(int data) 
{
  /* insertar siempre es posible, crear el nodo */
  stack_node *new_node = (stack_node *)malloc(sizeof(stack_node));
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
}

char pop() 
{
  stack_node *nptr = stack_top;

  if (nptr == NULL)
  {
      return '0';
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

void display() 
{
  // Display the elements of the stack
  stack_node * nptr = stack_top;

  if (nptr == NULL)
  {
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

void isvalidformula(char * formula)
{
  for(int c = 0; c<30; c++)
  {
    if(formula[c] == '\0')
      break;

    if(formula[c]=='(')
    {
      push(formula[c]);
    }
    else if(formula[c]==')')
    {
      char popped = pop();
      if(popped == '0' || popped != '(')
      { 
        printf("ERROR, %s \n\tthis not valid formula\n\n", formula);
        return;
      }
    }
  }
  if(count!=0)
  {
     printf("ERROR, %s \n\tthis not valid formula\n\n", formula);
     return;
  }
  //si llegamos a esta este punto, el stack se encuentra vacio por lo tanto
  //es una formula valida!
  printf("%s is a valid formula!\n\n", formula);

}

