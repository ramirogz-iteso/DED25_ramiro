/*
   PLEASE, rename this file as follows:
      yourname_exam1.c
   
   Theory                          10 pts
   Exam01 - Money                  10 pts
   Exam02 - Flip bits              15 ots
   Exam03 - Function poitners      15 pts
   Exam04 - Pointers               10 pts
   Exam05 - Structs sum            20 pts
   Exam06 - Array pointers         20 pts                    
                                   _______
                                    100
*/

/* =============================================================
    ====================   Theory 10 pts =======================
    ============================================================

  1: Describe in your own words, what a pointer is.
    R:
      
  2: How big is a pointer in size and why? 
    
    R: 

  3: What is a typedef use for?
    R:

  4: What is a void * used for?
    R:   

  5: What do I need to do before dereferencing or
     try to use a void pointer?
    R:
*/

#include <stdio.h>
#include <stdlib.h>
#define CLEAR printf("\033[0;0H\033[2J");

int exam01();
int exam02();
int exam04();
int exam05();
int exam06();

int main()
{
  CLEAR
  char name[20] = "WHOAREYOU?";
  printf("Data Structures : Exam 1: \n\tBy: \t\t%s\n", name);
  
  printf("--------------------ex01 ------------------------\n");
  exam01();
  printf("--------------------ex02 ------------------------\n");
  exam02();
  printf("--------------------ex04 ------------------------\n");        
  exam04();
  printf("--------------------ex05 ------------------------\n");
  exam05();
  printf("--------------------ex06 ------------------------\n");
  exam06();
  
  return 0;
}

/* ################         EX 01 :        ################################ 
   ################         15 pts         ################################ 
  
  Implement a function called "ConvertMoney" that receives a float "money"
  a char "type" and converts USD to MXN or vice versa.
     [ 20.30 MXN = 1 USD ]
  
  NOTE: type is always 'D' for USD or 'P' for MXN 
 
  The function must alter the variables directly and does not need to return
  anythig at all. Converting has a 10% fee, the house never loses =) 
  
  So if the user wants to convert and calls our function with:
  char type = 'D'
  float quantity = 100.50;

  After the call:
  type should be 'P' and quantity should be $2050.20 - 10% =  $1,845.18
*/

/* ------------------- ANSWER STARTS HERE   ------------------ */


/* ------------------- ANSWER STARTS HERE   ------------------ */

int exam01()
{
  char type = 'D';      //D = USD y P = MXN
  float  money = 21.5;

  printf("Original Currency #1 is: %.2f %c\n", money, type);

  /* ------------------- ANSWER STARTS HERE   ------------------ */
  // call your function

  /* -------------------  ANSWER ENDS HERE    ------------------ */
  printf("Converted currency #2 is: %.2f %c\n", money, type);
  
  /* lets try MXN to USD too */
  type = 'P';
  money = 500;
  printf("Original Currency #1 is: %.2f %c\n", money, type);
  /* ------------------- ANSWER STARTS HERE   ------------------ */
  // call your function

  /* -------------------  ANSWER ENDS HERE    ------------------ */
  printf("Converted currency #2 is: %.2f %c\n", money, type);

  /* For 10 extra points can you make this to work?*/
  char types[3] = {'P','D','P'};
  float moneys[5] = {33.50, 101.79, 15.99};
  int num_moneys = 3;

  //convert_multipleMoney();  UNCOMMENT and complete
  
  for (int i = 0; i < num_moneys; i++)
  {
    printf("Operation [%d] is: %.2f%c\n", i, moneys[i], types[i]);
  }
  
  return 0;
}


/* ################          EX 02 :       ################################ 
################            15 pts         ################################ 
Implement a function that inverts all the odd (pares) bits in a given
binary string (a char array made of '1' and '0's)

                  "001110111" will become  "010011101"
              bit: 123456789    
                  "11111"     will become  "10101"

Do not use brackets [], or strlen using only pointer arithmetic and basic
operations to determine the size.

*/
  /* ------------------- ANSWER STARTS HERE   ------------------ */
  //Code your function here, test it in exam02() which is already invoked
    

  /* -------------------  ANSWER ENDS HERE    ------------------ */

int exam02()
{
  char binary_chain[10] = "001110111";
  printf("original chain =  001110111  | flipped chain = ");

  /* ------------------- ANSWER STARTS HERE   ------------------ */
  // test your function here with the string provided above. It doesn't hurt
  // to try it with more examples! Make sure it works for all.

  /* -------------------  ANSWER ENDS HERE    ------------------ */
  
  printf("%s", binary_chain);
  printf("\n");
 
  return 0;
}

/* ################          EX 03 :       ################################ 
################            15 pts         ################################ 
Declare the MINUMUM number of function pointers required to be able to store
the following functions in them. Use the typedef if needed */
int welcometothejungle(int *num, char letra)
{
  printf("%c", letra);
  return (100);
}

int double_it(int num)   
{
  return(num + num);
}

int * sort(int *letters, char ** veces)
{
  char *result;
  return (int*) result;
}

int triple_it (int num)
{
  return (num + num + num);
}

/* Declare your function pointers here : */
/* ------------------- ANSWER STARTS HERE   ------------------ */

/* -------------------  ANSWER ENDS HERE    ------------------ */

/* This is the end of exam03, nothing else to do */


/* ################          EX 04 :       ################################ 
   ################         10 pts         ################################ 
  
  The following exercise has two arrays: the_numbers and the_letters

  Assign the following values respectively "15, 20, 33" and 'a', 'z' y 'x'
  without using brackets []! use only pointers. 
   
  If you do it right, the program will output:
  
    15 - a 
    20 - z 
    33 - x 

  PS. Doing: int the_numbers[3] = {15,20,33}; is obviously NOT a good answer
*/
int exam04()
{
  int the_numbers[3]; 
  char the_letters[3];

  /* ------------------- ANSWER STARTS HERE   ------------------ */

  /* -------------------  ANSWER ENDS HERE    ------------------ */
  
  for(int i = 0; i < 3; i++)
  {
    printf("%d - %c \n", the_numbers[i], the_letters[i]);
  }
  return 0;
}



/* ################          EX 05 :       ################################
   ################         20 pts         ################################   
  Implement a function "add" that receives:
    argument 1 : a void * to a struct. The struct contains only a number (int)
                 and a letter (char).
    argument 2 : other number (int)
  
  returns :  An intenger with the results of adding the number inside the struct 
             + the number passed as arugment 2.
  
  This exercise has 3 parts: 
  Part 1: Define your struct

  Part 2: Implement add()

  Part 3: Verify that everything works and complete exam05()
*/
/* ------------------- ANSWER STARTS HERE   ------------------ */

/* -------------------  ANSWER ENDS HERE    ------------------ */
int exam05()
{
  /* ------------------- ANSWER STARTS HERE   ------------------ */


  /* -------------------  ANSWER ENDS HERE    ------------------ */
  return 0;
}


/* ################         EX 06 :        ################################
   ################         20 pts         ################################ 

Read and understand exam06() function.

There is an important array that stores, two function pointers, an integer
array that contain all the base numbers we will use, and two empty arrays
to store the results of executing both functions over the base array.

The positions in the array are clearly labeled using some defines
The array is already initialized, and there is even auxiliary code to help
you print the contents of all the arrays.

DO NOT TOUCH any of the existing code outisde the function foo.


OBJECTIVE:
Complete the function foo(), so you can extract all the data you need
from the single void pointer called "all" and:

Run the function "double_it" on the DATA array and store the
results in the array at DOBULE_RES position

Run the function "triple_it" on the DATA array and store the
results in the array at TRIPLE_RES position


NOTE: double_it and triple_it are the same functions we declared in EX03
Perhaps the solution for that exercise will come handy here ;)

  Expected output:
  ==== init ====
  arr[0] = 5
  arr[1] = 6
  arr[2] = 7
  ==== Doubles Result ==== 
  arr[0] = 10
  arr[1] = 12
  arr[2] = 14
  ==== Triples Result ====
  arr[0] = 15
  arr[1] = 18
  arr[2] = 21

  Visual representation:
           0             1         2     3       4
  all [double_it() , triple_it,   [5] , [10] , [15]
                                  [6]   [12] , [18]
                                  [7]   [14] , [21]

   arays at 3 and 4 starts empty
 
*/

#define MAXELEM 3
#define DOUBLE_OP 0
#define TRIPLE_OP 1
#define DATA 2
#define DOUBLE_RES 3
#define TRIPLE_RES 4

void * foo(void * all)
{
  /* ------------------- ANSWER STARTS HERE   ------------------ */

  
  /* -------------------  ANSWER ENDS HERE    ------------------ */
  return NULL;
}

/* DO NOT TOUCH THIS CODE */
void InitArray(int *arr, int len)
{
  int *parr = arr;
  for (int i=0;i<len; i++, parr++)
  {
    *parr = 5+i;
  }
}
/* DO NOT TOUCH THIS CODE EITHER */
void PrintArray(int *arr, int len)
{
  int i = 5;
  int *parr = arr;
  for (i=0;i<len; i++, parr++)
  {
    printf("  arr[%d] = %d\n", i, *parr);
  }
}

/* DO NOT TOUCH THIS, NOTHING TO BE DONE */
int exam06(void) 
{

  int numbers[MAXELEM];
  int doubles[MAXELEM], triples[MAXELEM];
  void * MyData[5] = {};
  void **ptrToMyData = MyData;

  printf("==== init ====\n");
  InitArray(numbers, MAXELEM);
  PrintArray(numbers, MAXELEM);

  MyData[DOUBLE_OP] = double_it;
  MyData[TRIPLE_OP] = triple_it;
  MyData[DATA]   = numbers;
  MyData[DOUBLE_RES] = doubles;
  MyData[TRIPLE_RES] = triples;
  
  foo((void *)ptrToMyData);
 
  printf("==== Doubles Result ====\n");
  PrintArray(doubles, MAXELEM);

  printf("==== Triplets Result ====\n");
  PrintArray(triples, MAXELEM);
  return 0;
}