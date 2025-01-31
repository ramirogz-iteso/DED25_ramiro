#include <stdio.h>

/* Theory: A void pointer is a generic pointer that does not yet have a 
   specific data type to which it points.

    Syntax: void *ptr;

Rules:
A void pointer cannot be dereferenced directly because its data type is unknown.
To be used, it must be cast—a process where the programmer explicitly tells the
compiler the actual data type it points to.

It is the programmer's responsibility to ensure the correct type casting.
Pointer arithmetic on a void pointer works byte by byte (like char).

Reference:
GeeksforGeeks: Void Pointer in C/C++

*/

void myprint(void *, int);
#define CHAR 1
#define INTEGER 2
#define FLOAT 3
typedef int TYPE;

int main()
{
  int a = 10;
  void * vptr = &a;

  /*vptr is a generic pointer storing the address of variable a */

  //printf("valor de a = %d", *vptr); // <-- TRY ME
  //argument void type is incomplete

  /* 2 ways to use it */
  //1) direct casting
  printf("el valor de a = %d\n", *(int *)vptr);

  //2) restoring the void pointer into the real pointer
  int * iptr = vptr;
  printf("a value = %d\n", *iptr);

  printf("void ptr addr %p and value is %d \n", vptr, *(int *)vptr);
  printf("int ptr addr %p and value is %d \n", iptr, *iptr);

  char l = 'A';
  vptr = &l;

  printf("lastly %d\n", *(char *)vptr);

  //practice use, like the powerpoint:
  //create a single function that prints anything it receives.
  
  int z = 150;
  char b = 'R';
  float f = 999.99;
  
  int * intptr = &z;
  myprint((void*) &z, INTEGER);
  
  void * gen_ptr = &b;
  myprint(gen_ptr, CHAR);

  gen_ptr = &f;
  myprint(gen_ptr, FLOAT);

  getchar();
  //What happens if I print NULL value?
  myprint(NULL, FLOAT);
  void * new_ptr = NULL;
  myprint(new_ptr, FLOAT);
}

void myprint(void * ptr, TYPE t)
{
  if(ptr == NULL)
  {
    // another sintax .... if(!ptr)    if not valid ...   
    printf("Error, NULL pointer, it is dangerous to go alone\n");
    return;
  }
  
  if(t == INTEGER)
    printf("NUM: %d",*(int *)ptr);
  if(t == CHAR)
    printf("Letter [%c] ", *(char *)ptr);
  if(t == FLOAT)
    printf("Float %f ", *(float *)ptr);

  printf("\n");
}