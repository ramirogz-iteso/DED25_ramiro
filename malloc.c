#include <stdio.h>
#include <stdlib.h>

/*  Malloc / Free 

  Use only dynamic memory for this excercise.
  Remember, for EVERY malloc, there must exist a free */

int main()
{
  /* 1) create an int, and assign the value 10 to it. Print it to be sure */
  int x = 10; // this is static, not this
  int *iptr = (int *) malloc (sizeof(int));
  //or
  //int *i = NULL;
  //i = (int *) malloc (4);

  //to give value, we need to derefence the pointer, but we already know this :) 
  //*iptr = 10;
  //* i   = 10;
   
  printf("the value of iptr and i is both %d %d\n", *i, *iptr);
  getchar();

  /* 2) create an array of 10 integers  */
  int array[10];  // this is static, not this

  int * arptr = malloc(sizeof(int) * 10);
  int * a = arptr;

  /* 2.1) fill every space with random numbers  */
  for(int i = 0; i<10; i++)
  {
    //arptr[i] = i;
    //show what happens if I use pointer math instead.
    *arptr = i;
    arptr++;
  }

  //verify with a print
  for(int i = 0; i<10; i++)
  {
    printf("%d ", arptr[i]);
  }
  printf("\n");
  getchar();

  /* 2.1) fill every space with random numbers and print them  */
 

  /* 3) Create an array with 20 chars, and put your name in it, (request it to the user)
        and print it  */
  char name_s[20] = {"Ramiro"};   // this is static, not this

  //malloc
  char * name = malloc (sizeof(char)*20);
  printf("Input your name: ");
  int ret = scanf("%s", name);
  /* 3.1 print it */
  printf("My name is : %s\n", name);
 


  /* before this simple program complete. What do we need to do? 
    Remember the golden rule! */
  
  // destroy the memory for the integer create at 1)
  free(iptr);
  // destory the memory for the array of integers created at 2)
  free(arptr);

  // destroy the memory for the array that contained your name.
  free(name);

  /* and who will release the memory for the pointers? We don't! because all
  of our pointers, were created with STATIC memory and the program will free that
  memory for us as soon as the scope of the variable ends. */

  /* ==================================================================== */
}