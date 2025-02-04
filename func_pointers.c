#include <stdio.h>
#include <unistd.h>

/* Function pointers! :

A function pointer is a special type of pointer that can store the address where a function lives.
It is capable of executing this function, and point to any other function of its kind 

Syntax:
return_type (* function_ptr_name) (optional_parameters)

ex:
  char (*foo)(int, int, int)

Here, "foo" is a function pointer variable capable of pointing to ALL the 
functions that meet the following two properties: 
    - returns an char
    - receives 3 ints
  
This two properties together all called "signature of a function"
Remember the typedef can be used here too.

The following example declares 3 functions with the same signature: */

// add a + b, prints and returns result
int sum(int a, int b)
{
  printf("returning %d+%d\n", a,b);
  return a+b;
}

// substracts a - b, prints and returns result
int minus(int a, int b)
{
  printf("returning %d-%d\n", a,b);
  return a-b;
}

// multiply a * b, prints and returns result
int multiply(int a, int b)
{
  printf("returning %dx%d\n", a,b);
  return a*b;
}

/* The 3 share the same signature so they can be pointed by a pointer like this: */
typedef int (*two_operand_func) (int, int);

/*
  func_f_ab_plus_c 
  la function receives a functionm pointer. and 3 integers
  it runs the function passed (any) with a and b, to the result it adds c
  prints and returns. */  

                   //func_ptr function pointer!
int func_plus_c(int(*  func_ptr)(int,int), int a, int b, int c)
{
  int temporal_res = func_ptr(a, b);
  return temporal_res + c;
  // what func_ptr is doing here? we don't really know, it could be
  // add, plus, mutiply ... or something lese that matches the function signature
}

/* exactly the same as above, but with using the typedef for simplicity */
int func_plus_c2(two_operand_func func_ptr, int a, int b, int c)
{
  int temporal_res = func_ptr(a, b);
  return temporal_res + c;
}

/* Triples, receives 3 integers, this is NOT compatible with the pointer we created. */
int triples (int a, int b, int c)
{
  return a+b+c;
}

void func_pointers_theory()
{
  int (*fun_ptr) (int, int);

  fun_ptr = sum; 
  //fun_ptr = triples; //TRY ME

  //the name of he function represent the address, no need to put & ... but that works too.
  int(*ptr2)(int, int) = &minus;                        
  int(*foo)(int, int) = multiply;

  two_operand_func func = multiply;
                              
  fun_ptr(2,4);
  ptr2(4,2);
  foo(5,5);
  func(6,6);    // created with typedef


  printf("==============\n");
  getchar();
                                          //a  b  c
  printf("result = %d\n", func_plus_c(ptr2, 5, 5, 6));

  /*what you CAN DO:
  reuse the pointer: */
  getchar();
  ptr2 = multiply;                             //a b  c
  printf("result = %d\n", func_plus_c(ptr2, 5, 5, 6));

  /*what you CAN'T DO:
  assign a function with a different signature to ptr;*/
  //ptr2 = triples;      //because types are incompatible

  printf("======= array of functions =======\n");
  getchar();
  two_operand_func functions[3];

  functions[0] = sum;
  functions[1] = NULL;
  functions[2] = NULL;

  for(int x = 0 ; x < 3; x++)
  {
    if(functions[x]!=NULL)
      functions[x](x,x);
    else
      printf("sorry function not loaded\n");
  }
  
}

int main()
{
  func_pointers_theory();
  return 0;
}