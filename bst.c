#include <stdio.h>
#include <stdlib.h>

/* This file contains all the necessary three theory that we will neeed
 to review the following data structure : SET (Abstract dataype set)

 Before generalizing the ADT, we will do a simple excercise with a node
 that can only store INTEGERS, similar to how we build a stack_simple first
 before doing the ADT stack */

typedef struct node
{
  int value;
  struct node * left;
  struct node * right;
} node;

/*
               NODE
         /            \
   left child      right child

*/

typedef int boolean;
#define TRUE 1
#define FALSE 0

void print_inorder(node * n);

/* check if a three cointains a number, do it iteratively */
boolean contains_iter(node * n, int value);

/* check if a three cointains a number, do it recursively */
boolean contains_recur(node * n, int value);

node * create_node(int num)
{
  node * node = malloc (sizeof(node));
  node->value = num;
  node->left = NULL;
  node->right = NULL;
  return node;
}

/* add a number VALUE into the three, do it iteratively */
boolean add_iter(int value);

/* add a number VALUE into the three, do it recursively */
boolean add_recu(node *node, int value);

/* In all this examples, the pointer "root" contains the root of the
binary tree, its a global pointer and its the first element 
to access the full three. Similar to how stack_top was our global
pointer for our stack.

Despues de entender la logica, lo convertiremos en un TDA */

node * root = NULL;



/*              root
                 25
              /      \
          20           36
         /  \         /   \
       10    22     30     40
                   /
                  28
*/

/* learn_traversing_tree for a given existing three,
in this function we will learn how to traverse a tree, from the top
until we can print all nodes in it.

We can do this in three ways:
   IN ORDER   :
   PRE ORDER  :
   POST ORDER :
*/


void learn_traversing_tree()
{
 // ====  STATIC creation of a three (from the diagram above)
  node n25; n25.value = 25;
  node n20, n36; n20.value = 20; n36.value = 36;
  n25.left = &n20; n25.right = &n36;
  node n10, n22, n30, n40; 
  n10.value = 10;  n22.value=22; n30.value=30; n40.value=40;
  n20.left = &n10; n20.right = &n22; n36.left=&n30; n36.right=&n40;
  n10.left=NULL; n10.right=NULL;
  n22.left=NULL; n22.right=NULL;
  n30.right=NULL;
  n40.left=NULL; n40.right=NULL;
  node n28; n28.value = 28; n28.left = NULL; n28.right = NULL;
  n30.left=&n28;   

  root = &n25;

  //print in order (recursively)
  printf("\nPRINTING IN ORDER (using recursion) \n");
  print_inorder(root);
  
  //print pre order (recursively)
  printf("\nPRINTING IN ORDER (using recursion) \n");
  //Complete here

  //print post order (recursivo)
  printf("\nPRINTING POST ORDER (using recursion) \n");
  //Complete here

  //Cand you print a tree WITHOUT Recursion?:
  //YES! But you need an auxiliary stack
  //https://www.educative.io/answers/how-to-perform-an-iterative-inorder-traversal-of-a-binary-tree
  
  return;
}

void learn_building_tree()
{
  root = NULL;

  int numbers[9] = {5, 4, 6, 8, 10, 2, 1, 10, 7};

  //Add the above elements too the tree
  add_iter(0);
  
  for (int x = 0; x<9; x++)
  {
    printf("Adding %d to BST(Set)\n", numbers[x]);
    add_iter(numbers[x]);
  }
  printf("Adding nodes done\n");

  print_inorder(root);
 
  getchar();
 
  //contains (iterative)
  printf("%s",contains_iter(root, 28) ? "\tTRUE":"\tFALSE");
  printf("%s",contains_iter(root, 25) ? "\tTRUE":"\tFALSE");
  printf("%s",contains_iter(root, 42) ? "\tTRUE":"\tFALSE");
}


boolean add_iter(int num)
{
  /* Complete me :) */
  return TRUE;
}


void print_inorder(node *n)
{
  if(n == NULL)
  {
    printf("\tInORDER : END ");
    return;
  }
  printf("\tCalling my left child\n");
  print_inorder(n->left);   //L
  printf("%d ", n->value);  //P
  printf("\tCalling my right child\n");
  print_inorder(n->right);

}

boolean contains_recur(node * n, int value)
{
  // complete me :) 
  return TRUE;
}

boolean contains_iter(node * n, int value)
{
  // complete me :)
  return FALSE;
}

int main()
{
  /* Run example1, where a tree already exists and traverse it */
  /*Step 1, lets print a existing tree */
  printf("traversing_tree() ... \n");
  learn_traversing_tree();

  getchar();

  /* Example 2 contains the code to add nodes and create a tree */
  learn_building_tree(); 
}

