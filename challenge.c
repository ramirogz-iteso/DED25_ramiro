#include <stdio.h>

/*
  CHALLENGE!
  Arrays, pointers to pointer, function pointers and void pointers

  Step 1: Declare 2 arrays (5 integers each)
   arrA [5, 4, 3 , 2, 1]
   arrB [2, 2, 4,  4, 5]

  Save the starting address of each array, in a new array called arrX.

  arrX[0] -> should store the address to get to arrA [5,4,3,2,1]
  arrX[1] -> should store the address to get to arrB [2,2,4,4,5]

  Create a function called "process" that receives 2 things :

  argument#1  : As a void pointer:
                The array of arrays (arrX) should be passed here

  argument#2  : A function pointer to a function that receives 1 number and
                prints it on screen. Use the function "print_star()" to test it

  The function "process" should then, call print_star() for every number
  inside both arrays arrA and arrB

  The use of brackets [] is forbidden

  TIP:
  You can do this in two phases to verify this works:

  PHASE 1: process receives the array of arrays, and function pointer
  PHASE 2: process receives the void * and the function pointer

  FOR EXTRA FUN (this could be in the exam!)
  Can you do it in a way that process function only receives one and only
  one argumment? (please add a new function, don't delete the old one)
  DO NOT USE A STRUCT!

     ex :   process_one(all_data_into_one);

  GOOD LUCK!
*/

void print_star(int b)
{
  while (b--)
  {
    printf("|*|");
  }
  printf("\n");
}

//declare the function pointer here
typedef void (*f)(int);


void print_array(int *);
void process(int **, f s);


int main()
{
  // all int
  int arrA[5] = {5, 4, 3, 2, 1};
  int arrB[5] = {2, 2, 4, 4, 5};

  printf("arrA[0] %p\n", &arrA[0]);
  printf("arrB[0] %p\n", &arrB[0]);

  //
  //[ArrA, ArrB]
  int *arrX[2] = {arrA, arrB};

  // print_star(10);

  // basic poointer reminder
  int var = 5;       // var = 5 , addr 0x1
  int *ptr = &var;   // ptr = 0x1 , adrr 0xFF
  int **dptr = &ptr; // dptr = 0xFF , addr  0x20

  ptr = arrA;
  print_array(ptr);

  dptr = arrX;

  printf("==================\n");
  f f1 = print_star;
  process(dptr, f1);
}

// general rule for passing arrays is: pointer to the type
void print_array(int *a)
{
  printf("%d\n", a[4]);
  printf("%d\n", *(a + 4));

  // using brackets
  for (int x = 0; x <= 4; x++)
  {
    printf("%d ", a[x]);
  }
  // using pointer math
  for (int x = 0; x <= 4; x++)
  {
    printf("%d ", *a);
    a++;
  }
}

// general rule for passing arrays is: pointer to the type
void process(int **dptr, f f1)
{
  int **adptr = dptr;
  printf("[0] %d ", *dptr[0]);
  printf("[0] %d ", *dptr[1]);

  printf("\n");
  // printf("[0] %d ", **adptr);
  //  adptr++;
  //  printf("[0] %d ", **adptr);

  printf("\n");

  int *a1 = *adptr;
  adptr++;
  int *a2 = *adptr;
  // using pointer math
  for (int x = 0; x <= 4; x++)
  {
    // printf("%d ", *a1);
    f1(*a1);
    a1++;
  }
  printf("\n");
  // using pointer math
  for (int x = 0; x <= 4; x++)
  {
    // printf("%d ", *a2);
    f1(*a2);
    a2++;
  }
}

// general rule for passing arrays is: pointer to the type
void process_v(int * void, f f1)
{
  int **adptr = dptr;
  printf("[0] %d ", *dptr[0]);
  printf("[0] %d ", *dptr[1]);

  printf("\n");
  // printf("[0] %d ", **adptr);
  //  adptr++;
  //  printf("[0] %d ", **adptr);

  printf("\n");

  int *a1 = *adptr;
  adptr++;
  int *a2 = *adptr;
  // using pointer math
  for (int x = 0; x <= 4; x++)
  {
    // printf("%d ", *a1);
    f1(*a1);
    a1++;
  }
  printf("\n");
  // using pointer math
  for (int x = 0; x <= 4; x++)
  {
    // printf("%d ", *a2);
    f1(*a2);
    a2++;
  }
}
