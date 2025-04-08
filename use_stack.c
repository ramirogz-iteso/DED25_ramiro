#include <stdio.h>
#include "adt_stack/stack.h"

int main()
{
  // INTRO
  int n1 = 100;
  int n2 = 200;
  int n3 = 500;

  stack * s = stack_create();

  stack_push(s, &n1);
  stack_push(s, &n2);
  stack_push(s, &n3);

  int * popped_num;
  popped_num = (int *)stack_pop(s);
  printf("Pop = %d\n", *popped_num);
  getchar();

  popped_num = (int *)stack_pop(s);
  printf("Pop = %d\n", *popped_num);
  getchar();

  popped_num = (int *)stack_pop(s);
  printf("Pop = %d\n", *popped_num);
  getchar();

  /* 1 , a stack to store numbers  * */
  stack * intStack = stack_create();
  int a = 10, b = 17, c = 12, d = 8;
  stack_push(intStack, &a);
  stack_push(intStack, &b);
  stack_push(intStack, &c);
  stack_push(intStack, &d);

  stack_destroy(s);

  printf("==============Numeros===================\n");
  int * top = (int*) stack_top(intStack);
  printf("Top: %d\n", *top);
  printf("Size: %d\n", stack_size(intStack));
  getchar();

  while(!stack_isEmpty(intStack)) {
    int* popped = (int*) stack_pop(intStack);
    printf("Popped: %d\n", *popped);
    printf("Size: %d\n", stack_size(intStack));
  }
  stack_destroy(intStack);

  printf("===============Arrays==================\n");
  /* 2, stack of "strings" */
  stack * strStack = stack_create();
  char str1[] = "hello";
  char str2[] = "world";
  stack_push(strStack, str1);
  stack_push(strStack, str2);
  stack_push(strStack, "happy");
  while(!stack_isEmpty(strStack)) {
    char* spopped = (char*) stack_pop(strStack);
    printf("Popped: %s\n", spopped);
    printf("Size: %d\n", stack_size(strStack));
  }
  
  stack_destroy(strStack);
}