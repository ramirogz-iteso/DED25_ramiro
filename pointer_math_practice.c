/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEAR printf("\033[0;0H\033[2J");

void ex01();
void ex02();
void upper_to_lower(char*);
//void ex03();
//void ex04();

int main()
{
  //ex01();
  //ex02();

  char string[50];
  char *ret; 

  printf("Enter your name: ");
  ret = fgets(string, 50,stdin);
  upper_to_lower(string);
  puts(string);
  return 0;
}

void ex01()
{
  /* Excerice 01:
  Create an array of 10 integers, set their value (whatever you want)
  Using pointer arithmetic and a for loop traverse and print all the array

  DO NOT USE BRACKETS [ ]
  
  Print both the value and the address.
  
  ie
    int array = [ 2 , 3 , 5 , 6]

    array[0] = 2 -> addr = 0x00001
    array[1] = 3 -> addr = 0x00004
    array[2] = 5 -> addr = 0x00008
    array[3] = 6 -> addr = 0x0000B
*/
  int nums[10] = {1,2,3,4,5,6,7,8,9,10};
  int * iptr = nums;
  for(int i = 0; i<10; i++)
  {
    printf("array[%d] = %d -> addr = %p\n",
      i, *iptr, iptr);
    iptr++;
  } 

}

int mylenght(char * arr)
{
  char *ptr = arr;
  int count = 0;
  
  while(*ptr != '\0')
  {
    count++;
    ptr++;
  }
  return count;
}

void ex02()
{
  /* Excercise 02:
  Implement a function mylenght() that returns the size of the passed 
  string (char array). DO NOT USE strlen(), use only pointer arithmetic.

  DO NOT USE BRACKETS [ ]

  TIP: all strings are array of chars, terminated by '\0' character.
*/
  char name[400];
  int ret;

  printf("Please give me your name: \n");
  ret = scanf("%s", name);

  printf("My name is %s\n", name);
  printf("len = %d\n", mylenght(name));
}

/* More practice excerises (similar to Ex02)

  NOTA :  DO NOT USE [BRACKETS] in any function
  
  Excercise 03
  Implement a function that receives an array, traverses the array
  chaging all letters in CAPs to Lowercase.
  The array must be printed in the main loop to verify the results.
  TIP: See ASCII table
  
*/

void upper_to_lower(char * string)
{
  char *cptr = string;
  
  while (*cptr != '\0')
  {
    if(*cptr < 97 && *cptr >= 65)
      *cptr+=32;

    cptr++;
  }
}

/* Exercise 04
  Implement an isBinary function that receives a string and determines
  if its a binary number (must be formed of only 1s and 0s).

  SOMETHING SIMILAR IS ON THE EXAM!
*/
  
