#include <stdio.h>
#include <stdlib.h>
#include <time.h>

  /* LETS LEARN HOW TO GENERATE RANDOM NUMBERS :)
      This will come handy in your project.

     1) include stdlib.h
     2) incldue time.h

     3) Set the initial seed for the random generator,
     do this in the MAIN loop and BEFORE calling rand()
       
     srand(time(NULL));

     4) Call rand(); each time you call it you will get a
     new pseudo random number between 0 and a very big num;
 */
void tip_for_project();

int main()
{
  //this is only done ONCE
  srand(time(NULL));

  int myrandomnum = rand();
  printf("%d\n", myrandomnum);

  getchar();
  getchar();
  
  int num;
  for(int i=0; i<10; i++)
  {
    num = rand();
    printf("num = %d\n", num);
  }
  getchar();

  /* what if we want this numbers to range 0-3 only*/

  int random_small_nums[100];
  int is5=0;
  for(int i=0; i<100; i++)
  {
    random_small_nums[i] = rand() % 4;    
    printf("%d\n", random_small_nums[i]);
    if(random_small_nums[i] == 5) is5++;
  }
  printf("We got %d number 5s\n", is5);
}