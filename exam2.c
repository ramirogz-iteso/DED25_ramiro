#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* GENERAL INSTRUCTION:
   Always code inside the sections: */

   /* ----------  EXPECTED RESPONSE:  --------------- */
        // your exam code
        // goes in this section 
   /* ----------  EXPECTED RESPONSE:  --------------- */

/*  = = = = = = = Exercise 01: = = = = = =
    = = = = = = = = = = = = = = = = = = = =   
    Read the following from the text file "matrix.txt":
    Matrix is NxM        <===  number N = rows M columns
    a b c ...
    d e f ...
    g h i ...

    where [a ... i] are integer numbers.
    NOTE, there is a space between N and M

    Example: 
    Matrix is 2x2    or    Matrix is 4x4 
    5 4                    1 2 3 4
    3 2                    5 6 7 8
                           9 1 2 3
                           4 5 6 7 

    Build a 2D dynamic array to store the information read from the file
  
    Finally, write (with your program) your full name in a new line below the
    matrix in the same file

    The file should look like:
    Matrix is 2x2
    5 4
    3 2
    Ramiro Garcia Zepeda

    TIP, if between runs, you destroy the file, I recommend you rewrite it by
    hand to always have the input properly formatted.

    VALUE 20 pts:
    a) (10 pts) File reading 5 pts
    b) (10 pts) Dynamic memory creation and deallocation.
      NOTE: If you can't read the file, ask for the data from the console, 
      but it will only be worth 10pts.
*/
int e01()
{
  int col, row;
  int ** matrix;
  /* ----------  EXPECTED RESPONSE:  --------------- */
  

  /* ----------  EXPECTED RESPONSE:  --------------- */

  /* verify results  --  (Do not touch the for loops) --  */
  for (int j=0; j<col; j++)
  {
    for (int k=0; k<row; k++)
    {
      printf("m[%d][%d] = %d ", j,k, matrix[j][k]);
    }
    printf("\n");
  }
  /* verify results  --  (Do not touch) --  */
  /* anything else to do? remember the Malloc rule */ 
  /* ----------  EXPECTED RESPONSE:  --------------- */
 
  /* ----------  EXPECTED RESPONSE:  --------------- */
  return 0;
}

/*  = = = = = = = Exercise 02: = = = = = =
    = = = = = = = = = = = = = = = = = = = =  
  Create a function called joinList, that joins 2 linked lists.
  The function receives list A and list B
    
  The only rule is that the list with the smallest first element
  will go first. The lists should never be split.

  ie 
         List A      4-5-9-10
         List B      2-11-8

    new_header = joinList(A,B);
    printtList(new_header);
    2-11-8-4-5-9-10     

  Use the provided function printList and verify the result.
  Use the example lists L1 and L2 created

  VALUE 20 pts
*/
struct node
{
  int value;
  struct node * next;
}typedef node;

void printlist(node * n)  //DO NOT TOUCH
{
  while(n)
  {
    printf("%d ", n->value);
    n=n->next;
  }
  printf("\n");
}                        // DO NOT TOUCH

/* ----------  EXPECTED RESPONSE:  --------------- */


/* ----------  EXPECTED RESPONSE:  --------------- */

/* DO NOT TOUCH, initialization of demo lists L1 and L2 */
node *L1, *L2;
node L1n1, L1n2, L1n3, L1n4;
node L2n1, L2n2, L2n3;
/* DO NOT TOUCH */

int e02()
{
  /* DO NOT TOUCH, initialization of demo lists L1 and L2 */
  L1n1.value=1; L1n2.value=5; L1n3.value=9; L1n4.value=10;
  L1n1.next=&L1n2; L1n2.next = &L1n3; L1n3.next = &L1n4; L1n4.next = NULL;
  L2n1.value=3; L2n2.value=11; L2n3.value=8;
  L2n1.next=&L2n2; L2n2.next = &L2n3; L2n3.next = NULL;
  L1 = &L1n1; L2 = &L2n1;

  node * result;
  /* DO NOT TOUCH */
 
  printlist(L1);
  printlist(L2);
  //UNCOMMENT THIS LINE WHEN YOU HAVE YOUR FUNCTION
  //result = joinlist(L1, L2);
  printlist(result);
   /* DO NOT TOUCH */
  return 0;
}

/*  = = = = = = = Exercise 03: = = = = = =
    = = = = = = = = = = = = = = = = = = = =  
  Along with your exam, you will find the file fugitive_dump.bin. This file 
  contains a memory dump of an old FBI Fugitive Database. 
  Thanks to intelligence analysis, part of the 
  structure used to store the data has been obtained:

  struct fugitive {
    char name[20];
    UNKNOWN DATA TYPE 10 bytes
    UNKNOWN DATA TYPE 4 bytes
    short age;
    POSSIBLE ID, Stored in an INT variable
  }
  We know that each fugitive_dump file contains information about ONE SINGLE
  fugitive. 
  
  The entire structure is unknown, but it is believed that there may be 
  valuable information to help locate the fugitives in it. 
  A reverse engineering team will be required to analyze the 14 unknown bytes. This is costly and will take time.

  Your task, if you accept it, is to help the FBI create a function to 
  quickly extract the age of the fugitive from this memory dump. 
  With your program, the search and analysis space will be reduced to 
  only those dumps that match the age.

  VALUE 15 Pts
*/
int e03()
{
  /* ----------  EXPECTED RESPONSE:  --------------- */
 
  // I RAN THE PROGRAM, AND 
  // THE AGE OF THE FUGUTIVE ON THIS DUMP IS _____ <= write it here!
  /* ----------  EXPECTED RESPONSE:  --------------- */
}

/*  = = = = = = = Exercise 04: = = = = = =
    = = = = = = = = = = = = = = = = = = = =  
  Pepito has just created a perfect circular singly linked list.
  His list is perfectly done. Do not touch it.
  
  Pepito thought that by copying the content of printlist
  from exercise 02 he could print his list
  but it seems to have a big problem and it never ends!
  It is stuck in an infinite While loop.
  
  Help Pepito fix his function.

  VALUE 15pts
*/
void print_circular_list(node * n)
{
  while(n)
  {
    printf("%d ", n->value);
    n=n->next;
  }
  printf("\n");
}

int e04()
{
  /* DO NOT TOUCH, initialization of demo circular list L3 */
  node *L3;
  node L3n1, L3n2, L3n3;
  L3n1.value=1; L3n2.value=2; L3n3.value=3;
  L3n1.next=&L3n2; L3n2.next = &L3n3; L3n3.next = &L3n1;
  L3 = &L3n2;
  /* DO NOT TOUCH, initialization of demo circular list L3 */

  print_circular_list(L3);
  return 0;
}

/*  = = = = = = = Exercise 05: = = = = = =
    = = = = = = = = = = = = = = = = = = = =  
    Create (with dynamic memory) an array of roots to store 
    10 linked lists.
    For now, store lists L1 and L2 in the first 2 positions
    of the array. Test them with your printList function.

    Value 20pts
*/
int e05()
{
  /* ----------  EXPECTED RESPONSE:  --------------- */

  /* ----------  EXPECTED RESPONSE:  --------------- */
  return 0;
}

/*  = = = = = = = Exercise 06: = = = = = =
    = = = = = = = = = = = = = = = = = = = =  
    Use the STACK we saw in class,
    To program a function called reverse that reverses the contents of a string

    eg
    char test[10] = {"ITESO"};

    printf("%s\n", test); //Should print "ITESO"
    reverse(test, strlen(test));
    printf("%s\n", test); //Should print "OSETI"

    Value 20pts
  */

// DO NOT TOUCH, MODIFICATIONS ARE NOT NEEDE HERE
typedef struct stack_node {
    char info;
    struct stack_node *prev;
}stack_node;

// DO NOT TOUCH, MODIFICATIONS ARE NOT NEEDE HERE
/* STACK GLOBAL */
stack_node *stack_top = NULL;
int count = 0;

// DO NOT TOUCH, MODIFICATIONS ARE NOT NEEDE HERE
// Push() operation to add elements to the stack 
void push(int data) 
{
  /* inserting is always possible, create the node */
  stack_node *new_node  = (stack_node *)malloc(sizeof(stack_node));
  new_node->info = data;

  /* if it's the first node of the stack */
  if (stack_top == NULL)
  {
    stack_top = new_node;
    stack_top->prev = NULL;
  }
  else
  {
    new_node->prev = stack_top;
    stack_top = new_node;
  }
  count++;
  printf("\tnode inserted\n");
}

// DO NOT TOUCH, MODIFICATIONS ARE NOT NEEDE HERE
// For this version of the integer stack, returns -1 if there's nothing to pop
int pop() 
{
  stack_node *nptr = stack_top;

  if (nptr == NULL)
  {
      printf("\nStack Underflow\n");
      return -1;
  }
  else
  {
    nptr = nptr->prev;
  }

  int popped = stack_top->info;
  free(stack_top);
  stack_top = nptr;
  count--;
  return popped;
}

/* ----------  EXPECTED RESPONSE:  --------------- */

/* ----------  EXPECTED RESPONSE:  --------------- */

void e06()
{
  char test[10] = "ITESO";
  /* ----------  EXPECTED RESPONSE:  --------------- */
  //Call your function here, and print to verify it reversed:
  //reverse(test, strlen(test));
  
  /* ----------  EXPECTED RESPONSE:  --------------- */
  printf("%s\n", test);
}

int main()
{
  printf("Midterm Exam 2 by : %s\n", "YOURNAMEHERE");
  printf("=== E01: Matrix \n");
  e01();
  getchar();
  printf("=== E02: Join lists \n");
  e02();
  printf("=== E03: Secret age \n");
  e03();
  printf("=== E04: Stop the infinite loop (circular list) \n");
  e04();
  printf("=== E05: Multiple lists (array of lists) \n");
  e05();
  printf("=== E06: Stack \n");
  e06();
  return 0;
}