#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Exam Term 3: NAME_HERE 
/* ---------    THEORY SECTION OF THE EXAM  --------- */
/* ---------    THEORY SECTION OF THE EXAM  --------- */
/* ---------    THEORY SECTION OF THE EXAM  --------- */

/*

(5 PTS)
1)	Every header of our ADTs have this two lines at the very top:
#ifndef MAP_H_
#define MAP_H_

Can you explain in your own words why they are important and what they do?

  R=


(5 PTS)
2)	Mention the differences betwen a SET and Linkedlist, from the point of their 
    logical behaviour (not actual implementation)

  R=



(5 PTS)
3)	Why do we implement a SET using binary tree as the underlying structure?
    What are the main advantages

  R=


(10 PTS)
4)  Draw how the following binary tree will be after inserting 14 and 13 
    in that order. Its really not that hard to draw :) 

             10
          /      \
        3         16
      /   \      /   \
    1      8   11     18 
   /     /              \
  0     6                20

  R=

(5 PTS)
5)	Mention the difference between a Priority Queue, and a regular queue, from
    the point of view of the Datastructure behaviour (not implementation)
    
  R=

(20 PTS)
6)  Assuming we have a Min Heap (PQ) = [ 3, 5, 9, 6, 10, 12, 15, 8, 16 ] 
    How will the heap look like after: 
    Offer (4)  :    R = [  ]
    Poll ()    :    R = [  ]
   

(5 PTS)
7)	Why do we use the MOD operation after executing the hash function?
    

(15 PTS)
8)	Maps: Imagine you have a structure that you want to use as unique KEY in 
    your map, the struct has <day(int), month(int), year(int).
    Assuming the hash function does Day+Month+Year AND our map as a hash table
    size of 100: Where (in which bucket) will the following two keys will be 
    stored in the array

    < 2 / 12 / 2022 >
    < 5 / 05 / 1040 > 


// THE FOLLOWING 2 QUESTIONS NEED TO BE COMPLETED AND RUN IN THE MAIN LOOP 
// WHICH IS BELOW THE EXAMEN

(20 PTS)
9) Create a function that Counts the number of nodes in a binary tree that
   match the following criteria:
     - node has an odd number

     "In mathematics, "odd" numbers are whole numbers that cannot be divided 
     evenly by 2, meaning they leave a remainder of 1 when divided by 2."
   
   Bonus points for also being able to know the SUM of all the matching nodes.

   TIP : Feel free to use Global variables if needed

(20 PTS)
10)	Complete the code below to map chickens to their corresponding store as
    follows: 

    |       KEY        |       VALUE                 |
    | ------------------------------------------------
    |  Pollito1      	 |  Goes to Store1             |
    |  Pollito2	       |  Goes to Store2             | 
    |  Pollito3	       |  Goes to Store3             |
    --------------------------------------------------

    Use the Map seen in class (provided in this exam), insert the struct
    into the map and verify that the correct chicken lives in the right place
    by callig map_get for any check in you want (we need to see where it lives)
  */

/* ---------    PRACTICAL PART OF THE EXAM  --------- */
/* ---------    PRACTICAL PART OF THE EXAM  --------- */
/* ---------    PRACTICAL PART OF THE EXAM  --------- */

// Define the structure for a tree node
typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} node;

// Pre-allocate all nodes statically (max 9 in this case)
node n0, n1, n2, n3, n4, n5, n6, n7, n8;


// this function will create a sample tree for you to try your function
// in exercise 09, no nede to modify it. It's a free tree for you :) 
node * create_exam_tree() 
{
  // Initialize values
  n0.value = 6;
  n1.value = 4;
  n2.value = 1;
  n3.value = 2;
  n4.value = 5;
  n5.value = 14;
  n6.value = 18;
  n7.value = 21;
  n8.value = 23;

  // Build the tree by wiring left/right pointers
  n0.left = &n1;  n0.right = &n5;
  n1.left = &n2;  n1.right = &n4;
  n2.left = NULL; n2.right = &n3;
  n3.left = NULL; n3.right = NULL;
  n4.left = NULL; n4.right = NULL;
  n5.left = NULL; n5.right = &n6;
  n6.left = NULL; n6.right = &n7;
  n7.left = NULL; n7.right = &n8;
  n8.left = NULL; n8.right = NULL;

  return &n0; // root of the tree
}

// pollitos and Rotisserie stores for Exericse 10
typedef struct pollito
{
  int hp;
  int mp;
} pollito;

typedef struct store
{
  char name[20];
}store;

int main()
{

  // Exercise 09:
  node * root = create_exam_tree();
  /* COMPLETE EXCERCISE 9 HERE : */



  /* -----  END OF EX 09 ------  */

  // Exercise 10:
  pollito pollito1 = {100, 100};
  pollito pollito2 = {75, 70};
  pollito pollito3 = {50, 40};  
  store r1, r2, r3;

  strcpy(r1.name, "Pollo Pepe");
  strcpy(r2.name, "Pechugon");
  strcpy(r3.name, "Daddy Pollo");

  /* COMPLETE EXCERCISE 10 HERE : */


  /* -----  END OF EX 10 ------  */
  
}


