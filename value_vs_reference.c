#include <stdio.h>
#define CLEAR printf("\033[0;0H\033[2J");

/* Remember this concept of value vs reference can be applied to
  EVERYTHING:
    integer,
    chars
    structs
    even pointers!

  In this file we will remember:
    typedefs, defines
    how passing the arguments as reference is useful

    excercise : blackjack.c
*/

int sum(int, int, int *);
#define TRUE 1
#define FALSE 0
typedef int boolean;

void add10(int);
void add10_r(int *);

void add10_test();
void in_and_out_args();

void swap_me();

      
int main()
{
  CLEAR
  //test 1
  //add10_test();  

  //test 2
  in_and_out_args();

  //test 3
  //swap_me()
}

void add10_test()
{
  int number = 100;
  printf("Press ENTER to start \n");
  getchar();
  printf("number = %d\n", number);
  add10(number);
  printf("Number after calling add10 = %d\n", number);
  printf(" = = = = = = = = = = = = = = = = = = = \n");
  
  getchar();
  
  int number2 = 200;
  add10_r(&number2);
  printf("Number after calling add10_r = %d\n", number2);

}

void add10(int numero)
{
	numero += 10;
	printf("\t (add10): %d\n", numero);
}

void add10_r(int * numero)
{
	*numero += 10;
	printf("\t (add10_r): %d\n", *numero);
}

int sum(int x, int y, int * m)
{
  if(x == 10 || y == 10)
    *m = TRUE;
  
  return x+y;
}

void in_and_out_args()
{
  /* Functions can have arguments and return values:

    result = sum(a,b);

  A function that returns the sum of a and b,
  But what if we want to return more than one thing?

  ie:
      sum(a, b, magic); 

  A function that returns a+b and tell us if any of those is a "magic"
  number, lets define a magic number as 10;
  
  Out arguments are areas of memory that we pass to a function and
  that a function can write to them directly. This is done by passing
  the REFERENCE (not the value)
  */

  int a = 10;
  int b = 14;
  boolean magic = FALSE; //int set to zero
  
  int result = sum(a, b, &magic);
  
  printf("The sum is %d... \n", result);
  if(magic == TRUE)
    printf("\tAnd it was done using a Magic number!\n");
}