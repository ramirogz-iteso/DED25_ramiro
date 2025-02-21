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
  one void pointer?
  
     ex :   process ((void*)all_data_into_one);
  GOOD LUCK!
*/

void print_star(int b) {while(b--) printf("|*|"); printf("\n");}

// *** DELETE THIS BEFORE SHARING *****
typedef void (*print_ptr)(int b);
void process(int **, print_ptr);
void process_v(void *, print_ptr);
void process_single_v(void *);
// *** DELETE THIS BEFORE SHARING *****

int main() {

  int arrA[5] = {5,4,3,2,1};
  int arrB[5] = {2,2,4,4,5};

  int * arrays[2] = {arrA, arrB};
  int ** dptr = arrays;

  process(dptr, print_star);
  printf("\n\n=============\n\n");
  getchar();
  void * v = (void *) dptr;
  process_v((void *)dptr, print_star);

  printf("\n\n=============\n\n");
  void * data[4];
  int num = 5;
  data[0] = arrA;
  data[1] = arrB;
  data[2] = &num;
  data[3] = print_star;
  process_single_v((void *)data);
  
  return 0;
}

void process(int ** all, print_ptr p) 
{  
  int * arr1 = NULL;
  int * arr2 = NULL;

  // [0] contains first array
  arr1 = *all;
  for(int i = 0; i<5; i++, arr1++)
  {
    p(*arr1);
    //printf("%d ", *arr1);
  }
  all++;

  arr2 = *all;
  for(int i = 0; i<5; i++, arr2++)
  {
    p(*arr2);
  }
  all++;
}

void process_v(void * data, print_ptr p) 
{
  int ** all = (int **)data;
  
  int * arr1 = NULL;
  int * arr2 = NULL;

  // [0] contains first array
  arr1 = *all;
  for(int i = 0; i<5; i++, arr1++)
  {
    p(*arr1);
  }
  all++;

  arr1 = *all;
  for(int i = 0; i<5; i++, arr1++)
  {
    p(*arr1);
  }
  all++;
}
/*
     int x = 10;
     int *ptri = &x;

     printf("%d", ptri);  0xFFFFA
     printf("%d", *ptri);

  */
// This could come in the exam!

void process_single_v(void * data)
{
  // *** DELETE THIS BEFORE SHARING *****
  void ** all = (void **)data;
  int * arr1 = all[0];
  int * arr2 = all[1];
  int num = *(int *) all[2];
  print_ptr p = (print_ptr)all[3];
  
  for(int i = 0; i < num; i++)
  {
    p(*arr1);
    arr1++;
  }
  for(int i = 0; i < num; i++)
  {
    p(*arr2);
    arr2++;
  }
  // *** DELETE THIS BEFORE SHARING *****
}