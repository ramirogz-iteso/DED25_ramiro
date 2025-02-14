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

void print_star(int b) {while(b--) printf("|*|"); printf("\n");}

int main() 
{
  int arrA[5] = {5,4,3,2,1};
  int arrB[5] = {2,2,4,4,5};
}

void process(/*COMPLETE ME*/)
{
}
