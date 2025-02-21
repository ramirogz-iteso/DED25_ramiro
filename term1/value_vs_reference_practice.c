#include <stdio.h>

void swap(int *, int *);
int blackjack(int, int*, char *);

int main()
{

  /* Exercise 1:  swap num1 and num2 value */
  int num1 = 1;
  int num2 = 20;

  swap(&num1, &num2);
  printf("num1 = %d num2 = %d\n", num1, num2);

  /* Exercise 2:  Blackjack 
    Call and test your program here */

  char flag = '0';  //init value
  int result = blackjack( num1, &num2, &flag);

  if(flag == 'W') printf("We have a winner!\n");
  if (result)
    printf("Sum is POSITIVE = %d\n", num2);
  else
    printf("Sum is NEGATIVE = %d\n", num2);
  
  return 0;
}

/* 
  Excercise 1 : swap
  Create a function that "swaps" the contents of two variables.
  It should receive two intengers, return nothing and after it execution
  whatever what inside one variable should be inside the other and viceversa 
*/

void swap(int *x, int *y)
{
  int tmp = *x;
  *x=*y;
  *y=tmp;
  printf("\tInside Swap : The value of x = %d, and y = %d\n", *x,*y);
}


/* Excercise 2 : blackjack

Create a blackjack function that:
  -receives 2 numbers and a FLAG (char)
  -returns 1 if the sum of the numbers is positive (greater than 0).
  -returns 0 if the sum of the numbers is negative.
  -Stores the sum of the two numbers in number2.
  -If the sum is 21, set the FLAG to = 'W' (winner)
*/
int blackjack(int num1, int *num2, char *flag)
{
  int result = 0;
  
  if(num1 + *num2 > 0)
    result = 1;

  *num2 = num1 + *num2;
  if(*num2 == 21)
    *flag = 'W';

  return result;

}