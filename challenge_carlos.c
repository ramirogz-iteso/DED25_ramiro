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

     ex :   process_one(all_data_into_one);
     
  GOOD LUCK!
*/
typedef void(*func_ptr)(int);

void process(int **, func_ptr);

void print_star(int b) 
{
  while(b--) 
  printf("|*|"); 
  printf("\n");
}
func_ptr stars = print_star;


int main() 
{
  
  int arrA[5] = {5,4,3,2,1};
  int arrB[5] = {2,2,4,4,5};
  int *arrX[2] = {arrA, arrB};
  //printf("%d", *arrX[0]);
  process(arrX, stars );
  //p(*arrX);
}

void process(int **arrX, func_ptr stars)
{
  int **normptr;
  normptr = arrX;
  int *int_ptr = NULL;
  for(int i = 0; i < 2; i++)
  {
    int_ptr = *normptr;
    for(int j = 0; j < 5; j++)
    {
      //printf("%d", *int_ptr);
      stars(*int_ptr);
      int_ptr++;
    }
    printf("\n");
    normptr++;
  }
  printf("\n");
 /* for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 5; j++, normptr++)
    {
      printf("%d \t", *normptr);
    }
    arrX++;
    normptr = arrX;
    printf("\n");
  }
*/
  //stars(c);
}