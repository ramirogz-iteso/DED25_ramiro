#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the previous pointer
typedef struct stack_node {
    char info;
    struct stack_node *prev;
}stack_node;

/* GLOBAL STACK */
stack_node *stack_top = NULL;
int count = 0;

// Push() operation on a stack
void push(int data) 
{
  /* Insertion is always possible, create the node */
  stack_node *new_node = (stack_node *)malloc(sizeof(stack_node));
  new_node->info = data;

  /* If it is the first node in the stack */
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

void isvalidformula_simple(char * formula)
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
      if(popped == '0')
      { 
        printf("ERROR, %s \n\tthis is not a valid formula\n\n", formula);
        return;
      }
    }
  }
  if(count!=0)
  {
     printf("ERROR, %s \n\tthis is not a valid formula\n\n", formula);
     printf("stack contains %d elements\n", count);
     return;
  }
  // If we reach this point, the stack is empty, so
  // it is a valid formula!
  printf("%s is a valid formula!\n\n", formula);
}

void isvalidformula(char * formula)
{
  for(int c = 0; c<30; c++)
  {
    if(formula[c] == '\0')
      break;

    if(formula[c]=='(' || formula[c]=='{')
    {
      push(formula[c]);
    }
    else if(formula[c]==')') 
    {
      char popped = pop();
      if(popped == '0' || popped != '(')
      { 
        printf("ERROR, %s \n\tthis is not a valid formula\n\n", formula);
        return;
      }
    }
    else if(formula[c]=='}') 
    {
      char popped = pop();
      if(popped == '0' || popped != '{')
      { 
        printf("ERROR, %s \n\tthis is not a valid formula: ", formula);
        printf("pop = %c\n", popped);
        return;
      }
    }
  }
  if(count!=0)
  {
     printf("ERROR, %s \n\tthis is not a valid formula\n\n", formula);
     printf("stack contains %d elements\n", count);
     return;
  }
  // If we reach this point, the stack is empty, so
  // it is a valid formula!
  printf("%s is a valid formula!\n\n", formula);
}

int main() 
{
  char formula1[30] = "(a+b)+((b))";
  char formula2[30] = "(123))";

  //char formula1[30] = "}({}){";
  //char formula2[30] = "{{}()}{{((";

  isvalidformula_simple(formula1);
  isvalidformula_simple(formula2);

  //use isvalidformula to fi
}