#include <stdio.h>
#include <stdlib.h>
#include "adt_stack/stack.h"

/* This file use ADT Stack 
  Complete the ADT stack code and test in here.
  This does the same as we did before to run the formula validator 
  only with parentesis */

void isvalidformula(char * formula)
{
  stack * s = stack_create();
  for(int c = 0; c<30; c++)
  {
    if(formula[c] == '\0')
      break;

    if(formula[c]=='(')
    {
      stack_push(s, (void *)&formula[c]);
    }
    else if(formula[c]==')') 
    {
      char * popped = (char *)stack_pop(s);
      if(popped == NULL)
      { 
        printf("ERROR, %s \n\tthis not valid formula\n\n", formula);
        return;
      }
      else
        printf("Popped element %c\n", *popped);
    }
  }
  if(stack_isEmpty(s) == FALSE)
  {
     printf("ERROR, %s \n\tthis not valid formula\n\n", formula);
     printf("stack contains %d elements\n", stack_size(s));
     return;
  }
  //si llegamos a esta este punto, el stack se encuentra vacio por lo tanto
  //es una formula valida!
  printf("%s is a valid formula!\n\n", formula);

  stack_destroy(s);
}

int main() 
{
  char formula1[30] = "((30+5)+(5))";
  isvalidformula(formula1);

}