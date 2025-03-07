#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CLEAR printf("\033[0;0H\033[2J");

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

int add_chicken(chicken ** farm, int size)
{
  for(int x = 0; x < size; x++)
  {
    if(farm[x] == NULL)
    {
      farm[x] = create_chicken(x);
      return 1;
    }
  }
  //if we get to this point we fail to find an empty slot. no new chicken added
  return 0;
}

void freeweaks(chicken ** farm, int size)
{
  printf("Freeing average chickens (hp <50)\n");
  for(int x = 0; x < size; x++)
  {
    if(farm[x]!= NULL && farm[x]->hp <= 50)
    {
      printf("Found a weak chicken at: %d let it fly!\n", x);
      free(farm[x]);
      farm[x] = NULL;
    } 
  }
}

void deletechicken(chicken ** farm, int idx)
{
  free(farm[idx]);
  farm[idx] = NULL;
}

void print_all(chicken ** farm, int size)
{
  printf(" = = WELCOME TO THE FARM = =\n");
  //chicken * p = NULL; 
  for(int i=0; i < size; i++)
  {
    printf("[%d] : ", i);

    if(farm[i] != NULL)
    {
      //p = *farm;
    
      //printf("chicken with ID %d hp %d\n", p->id, p->hp);
      //of course using brackets also works :) 
      printf("chicken with ID %d = %d\n", farm[i]->id, farm[i]->hp);
    }
    else
    {
      printf("FREE\n");
    }
    
    //farm++;
  }
  printf(" = = = = = = = = = = = = = =\n");

  // NOTE! It is NOT a good idea to access elements that we don't know if 
  // they exists or NOT. Find a way to print "FREE" if a slot in the farm
  // is available

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

  //size of chicken 
  //    /* <= drop // to kill all code below
  chicken bigfarm[250];
  chicken * ptr_farm[250];
  chicken * pchicken;
  
  //size of chicken 
  /*
  printf("One chicken is : %ld bytes\n", sizeof(chicken));
  printf("One chicken ptr is : %ld bytes\n", sizeof(pchicken));
  printf("The farm is : %ld bytes\n", sizeof(bigfarm));
  printf("The farm is : %ld bytes\n", sizeof(ptr_farm));
  //*/

  getchar();

  /* 0 Create with the professor a lot of chickens  */
  chicken * c1 = (chicken *) malloc (sizeof(chicken));
  chicken * c2 = (chicken *) malloc (sizeof(chicken));
  chicken * c3 = (chicken *) malloc (sizeof(chicken));
  
  c1->id = 99;   c1->hp = 100;
  c2->id = 100;  c2->hp = 100;
  c3->id = 101;  c3->hp = 100;

  /* Will this scale to create many more chickens? NO!  because the code 
  to create chicken has to be defined, so lets instead convert the chicken
  creation process into a function that returnsa a pointer to a NEWLY CREATED
  chicken every time it gets called. 
  The caller, needs to be sure to "save" those pointers somewhere */


  /* Step number 1: Lets create a function to allocate 1 chicken */
  // chicken * p = create_chicken(10);

  // printf("We have dynamically created 1 chicken with id = %d\n", p->id);

  /* Lets create all the farm at once using dynamic memory */
  /* step one, create top level */ 
  int FARMSIZE = 10;
  chicken ** farm = (chicken **) malloc(sizeof(chicken *) * FARMSIZE);

  for(int x = 0; x < FARMSIZE; x++)
    farm[x] = NULL;

  farm[0] = c1;
  farm[1] = c2;
  farm[2] = c3;

  //TODO #1 Set all the chicken pointers in the ARRAY to NULL,
  //So we know which "position in the array" is empty (free):
  
  print_all(farm, FARMSIZE);
  //   Did it crash? 
  //   You might want to check the comments inside the function, FIX IT!
  
  /* step two, for each ptr, we need another malloc */
  for(int i = 3; i<FARMSIZE; i++)
  {
    //farm[i] = malloc(sizeof(chicken));
    //farm[i]->id = i+6;
    farm[i] = create_chicken(i);
    //printf("Created chicken with ID %d\n", all[i]->id);
  } 
  // NOTE show the class the bug, what happend to c1, c2 and c3?

  /* print all the chickens using a function that receives
     the array */
  getchar();
  print_all(farm, FARMSIZE);


  //TODO
  //We DON'T like WEAK chickens, free the chickens that are weak (hp < 30)
  for(int x = 0; x < FARMSIZE; x++)
  {
    if(farm[x] != NULL && farm[x]->hp <= 30)
    {
      printf("Found a weak chicken at: %d let it fly!\n", x);
      free(farm[x]);
      farm[x] = NULL;
    }
  }

  //TODO
  //Print the farm again, verify that we freed those little useless chickens
  // I want to be able to see the "FREE" slots.
  printf("After freeing weak chickens... \n");
  getchar();
  print_all(farm, FARMSIZE);
  getchar();

  //TODO
  //We need to refill those chickens, but its going to be a pain 
  // to find "where to put them" so:
  // Create a function that is called "add_chicken" that receives
  // the farm and creates 1 chicken in the FIRST available row
  // the ID of the newly created chicken MUST correspond to the slot
  // ON SUCCESS the function returns 1. ON FAIL returns 0
  
  while(add_chicken(farm, FARMSIZE) == 1)
  {
    printf("Chicken refilled succesfully\n");
    getchar();
  };

  print_all(farm, FARMSIZE);
  getchar();

  //FINAL TODO
  //Use a while / switch - case to the program to add user interaction to it.
  //Add function that allows you add your own chicken at the slot that you want
  //    // ON SUCCESS the function returns 1. ON FAIL returns 0
  //Add a function to double the farm size if no more chickes can be added

  printf("Entering interactive / MANUAL mode now.... \n");

  int exit = 1;
  int opc = 0;
  int result; 
  int idx;

  CLEAR;

  while(exit)
  {
    printf("Select one of the following options:\n");
    printf("\t 1) Print farm\n");
    printf("\t 2) Free weaks\n");
    printf("\t 3) Add chicken\n");
    printf("\t 4) Add chicken at ... \n");
    printf("\t 5) delete chicken\n");
    printf("\t 6) expand farm size (double it)\n");
    printf("\t 7) exit and destroy\n");
    printf("\t\t SELECT : ");

    scanf("%d", &opc);
    getchar();

    switch(opc)
    {
      case 1:
        print_all(farm, FARMSIZE);
        getchar();
      break;

      case 2:
        freeweaks(farm, FARMSIZE);
        getchar();
      break;
      case 3:
        
        result = add_chicken(farm, FARMSIZE);
        if (result)
          printf("Your chicken was added succesfully\n");
        else
          printf("FARM FULL cannot add anymore\n");
      break;
      case 4:
      break;
      case 5:
        printf("which chicken? (IDX): ");
        scanf("%d", &idx);
        deletechicken(farm, idx);
      break;
      case 6:
        printf("Expanding size of farm from %d to .... %d\n", FARMSIZE, FARMSIZE*2);
        int oldsize = FARMSIZE;
        FARMSIZE = FARMSIZE * 2;
        farm = realloc(farm, FARMSIZE * sizeof(chicken *));
      
        // NULL all new pointers we just created.
        for(int x=oldsize; x<FARMSIZE; x++)
        {
          farm[x] = NULL;
        }
        printf("done!");
      break;
      case 7:
      break;
    }
    
    getchar();
    CLEAR;
  }

  /* EXAMPLE     :

     WELCOME TO THE FARM, what do you want to do?
         a) print all chickens
         b) add_chicken    (random chicken gets created at the next avail slot)
         c) add_chicken_user  (user specifies data (slot and hp))
         d) delete chicken at slot given
         e) expand farm size
         f) exit program free all chicken
  */
}