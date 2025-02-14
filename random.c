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
  srand(time(NULL));
  
  int num;
  for(int i=0; i<10; i++)
  {
    num = rand();
    printf("num = %d\n", num);
  }
  getchar();

  /* Y si queremos numeros mas chicos? digmaos del 1 al 10 */

  int random_small_nums[100];
  int is5=0;
  for(int i=0; i<100; i++)
  {
    random_small_nums[i] = rand() % 4;    
    printf("%d\n", random_small_nums[i]);
    if(random_small_nums[i] == 5) is5++;
  }
  printf("We got %d number 5s\n", is5);

  tip_for_project();
}

void tip_for_project()
{
  /* Tu projecto va a requerir que alternes entre 2 jugadores:
     primero el player1
     luego el player2

     Como podemos alternar una variable de 1 a 2 , o de 0 a 1 
     en cada iteracion de un ciclo while?

  */
  int turn = 0;
  int life = 10;
  
  while(life--)
  {
    printf("Player at turn is %d\n", turn);
    turn = !turn;
    getchar();
  }
  printf("Game over\n");
  

  life = 10;
  while(life--)
  {
    int atplay;
    if(turn % 2 == 0)
      atplay=0;
    else
      atplay=1;
    
    printf("Player at turn is %d\n", atplay);

    turn++;
    getchar();
  }
  printf("Game over, and we played %d times\n", turn);
}