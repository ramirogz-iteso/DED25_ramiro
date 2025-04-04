#include <stdio.h>
#include <stdlib.h>
#include "adt_stack/stack.h"

/* This file use ADT Stack 
  Complete the ADT stack code and test in here.
  This does the same as we did before to run the formula validator 
  only with parentesis */

void isvalidformula(char * formula)
{
  //COMPLETE CREATE YOUR OWN STACK
  
  for(int c = 0; c<30; c++)
  {
    if(formula[c] == '\0')
      break;

    if(formula[c]=='(')
    {
      //PUSH INTO YOUR NEW STACK
      //PUSH!
    }
    else if(formula[c]==')') 
    {
      //POP FROM THE STACK
      char * popped = /* POP! */
      if(popped == NULL)
      { 
        printf("ERROR, %s \n\tthis not valid formula\n\n", formula);
        return;
      }
      else
        printf("Popped element %c\n", *popped);
    }
  }
  // Check if the stack is empty ...  and print its size
  //if(// the stack contains something)
  {
     printf("ERROR, %s \n\tthis not valid formula\n\n", formula);
     //printf("stack contains %d elements\n", /* get stack size */);
     return;
  }
 
  printf("%s is a valid formula!\n\n", formula);

  //DONT FORGET TO DESTROY THE STACK
}

int main() 
{
  char formula1[30] = "((30+5)+(5))";
  isvalidformula(formula1);
}