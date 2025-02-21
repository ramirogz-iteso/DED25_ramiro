#include <stdio.h>
#include <unistd.h>

int foo1(int n)
{
  printf("I am an evil function that just ignores what you send :P \n");
  return 10;
}

int foo2(int n)
{
  printf("You sent %d to me, I will give you 2 * %d in return", n, n);
  return n*2;
}

void foo3(int n)
{
  printf("the third function that just prints the number %d", n);
}

int main()
{
  int v1 = 10;
  int v2 = 20;
  int v3 = 50;

  int * vptr = NULL;

  //general syntax to create function pointers
  // return_type (*pointer_name) ([parameters])
  int (*func_pointer)(int);

  typedef void (*voidf)(int);

  func_pointer = NULL;

  func_pointer = &foo1; //()
    
  int x = func_pointer (500);
  printf("%d\n", x);

  printf("-------\n");
  func_pointer = foo2;
  x = func_pointer (500);
  printf("%d\n", x);

  printf("-------\n");
  voidf p1;

  p1 = foo3;

  p1(1);

  return 0;
}