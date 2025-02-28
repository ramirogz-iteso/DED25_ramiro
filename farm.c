#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct chicken
{
  int id;
  int hp;

  /* imagine another 4k of data live here... like what?
    chicken DNA sequence
    chicken Health Records
    chicken's parents and grand parents data
    chicken's color in full RGB (purple, green)
  */
  int DNA[2048];
} chicken;

chicken * create_chicken(int id)
{
  chicken * new_chicken = (chicken *)malloc(sizeof(chicken));
  new_chicken->id = id;
  new_chicken->hp = rand() % 100;
  return new_chicken;
}

void print_all(chicken ** farm, int farm_size)
{
  //TODO #2 ... It is NOT a good idea to access elements
  //that we don't know if they exists...
  //Find a way to print "EMPTY" if a slot in the farm
  //is available

  /* LIKE THIS:
     = = WELCOME TO THE FARM = =
    [0] : chicken with ID 0 hp 100
    [1] : FREE
    [2] : FREE
    [3] : chicken with ID 3 hp 70 */  
}

int main()
{
  srand (time(NULL));
  #define FARMSIZE 10  
  
  chicken farm[250];
  chicken * pfarm[250];
  chicken * pchicken;
  
  //size of chicken 
  ///*
  printf("One chicken is : %ld bytes\n", sizeof(chicken));
  printf("One chicken ptr is : %ld bytes\n", sizeof(pchicken));
  printf("The farm is : %ld bytes\n", sizeof(farm));
  printf("The farm is : %ld bytes\n", sizeof(pfarm));
  //*/

  /* Step number 1: Lets create a function to allocate 1 chicken */
  // chicken * p = create_chicken(10);

  // printf("We have dynamically created 1 chicken with id = %d\n", p->id);

  /* Lets create all the farm at once using dynamic memory */
  /* step one, create top level */ 
  chicken ** all = (chicken **) malloc(sizeof(chicken *) * FARMSIZE);
  chicken ** ptr = all;

  //TODO #1 Set all the chicken pointers in the ARRAY to NULL,
  //So we know which "position in the array" is empty (free):
  
  //print_all(all, FARMSIZE);
  //Did it crash? You might want to check TODO #2 inside
  //print_all function.
  
  /* step two, for each ptr, we need another malloc */
  for(int i = 0; i<FARMSIZE; i++)
  {
    //all[i] = malloc(sizeof(chicken));
    //all[i]->id = i+6;
    all[i] = create_chicken(i);
    //printf("Created chicken with ID %d\n", all[i]->id);
  } 

  /* print all the chickens using a function that receives
     the array */
  print_all(all, FARMSIZE);


  //TODO #3
  //We DON'T like WEAK chickens, free the chickens that are weak
  //weak = hp < 30; 


  //TODO #4
  //Print the whole farm again, verify that we freed those little
  //useless chickens :)
  //I want to be able to see the "Empty" slots.


  //TODO #5
  //We need to recover those chickens, but its going to be a pain
  //to find "where to put them" so:
  //Create a function that is called "add_chicken" that receives
  //the farm and creates 1 chicken in the FIRST available row
  //the ID of the newly created chicken MUST correspond to the slot
  
  //TODO #6
  /* destroy all the FARM, how many frees do you need? */
  
}