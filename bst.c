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

/* prints folling the IN-ORDER principile (L-P-R)*/
void print_inorder(node * n);

/* check if a three cointains a number, do it iteratively */
boolean contains_iter(node * n, int value);

/* check if a three cointains a number, do it recursively */
boolean contains_recur(node * n, int value);

/* function to create and allocatem memory for a new tree node */
node * create_node(int num)
{
  node * n = malloc (sizeof(node));
  n->value = num;
  n->left = NULL;
  n->right = NULL;
  return n;
}

/* add a number VALUE into the three, do it iteratively */
boolean add_iter(int value);

/* add a number VALUE into the three, do it recursively */
boolean add_recu(node *node, int value);

/* In all this examples, the pointer "root" contains the root of the
binary tree, its a global pointer and its the first element 
to access the full three. Similar to how stack_top was our global
pointer for our stack. */

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
  //comment

  //print in order (recursively)
  printf("\nPRINTING IN ORDER (using recursion) \n");
  print_inorder(root);
  printf("\n");
  
  //print pre order (recursively)
  printf("\nPRINTING IN ORDER (using recursion) \n");
  //Complete here
  printf("\n");

  //print post order (recursivo)
  printf("\nPRINTING POST ORDER (using recursion) \n");
  //Complete here
  printf("\n");

  //Cand you print a tree WITHOUT Recursion?:
  //YES! But you need an auxiliary stack
  //https://www.educative.io/answers/how-to-perform-an-iterative-inorder-traversal-of-a-binary-tree
  
  return;
}

void learn_building_tree()
{
  root = NULL;

  int numbers[] = {42, 5, 4, 6, 8, 1, 2, 1, 10, 7, 25};
  
  for (int x = 0; x<11; x++)
  {
    printf("Adding %d to BST (Set)\n", numbers[x]);
    add_iter(numbers[x]);
  }
  printf("Adding nodes done\n");

  print_inorder(root);
 
  //contains (iterative)

  printf("\nDoes my tree contains 28? %s", 
         contains_iter(root, 28) ? "\tTRUE\n":"\tFALSE\n");

  printf("Does my tree contains 25? %s", 
         contains_iter(root, 25) ? "\tTRUE\n":"\tFALSE\n");

  boolean contains_42 = contains_iter(root, 42);
  if(contains_42)
    printf("My tree contains 42!\n");
  else
    printf("My tree does NOT contain 42 :( \n");

  //contains (recursivo) 
  //Complete and try
}

boolean add_iter(int num)
{
  #ifdef DEBUG
  printf("add_iter: about to add %d\n", num);
  #endif 

  node *nptr, *new_node;
  if(root == NULL)
  {
    new_node = create_node(num);
    root = new_node;
    #ifdef DEBUG
    printf("add_iter: Root created\n");
    #endif 
  
    return TRUE;
  }

  boolean added = FALSE;
  nptr = root;
  while(added != TRUE)
  {
    #ifdef DEBUG
      printf("  add_iter: is %d vs %d = %s\n", num, nptr->value, 
              num > nptr->value ? "+ take right" : "- take left");
    #endif 
    
    if(num < nptr->value)
    {
      if(nptr->left == NULL)
      {
        #ifdef DEBUG 
          printf("  add_iter: %d empty LEFT child, create here\n", 
                 nptr->value);
        #endif
        
        node * n = create_node(num);
        nptr->left = n;
        added = TRUE;
      }
      else
      {
        #ifdef DEBUG
          printf("  add_iter: smaller, take left...\n");
        #endif
        nptr = nptr->left;
      }
    }
    else if (num > nptr->value)
    {
      if(nptr->right == NULL)
      {
        #ifdef DEBUG
          printf("  add_iter: %d empty RIGHT child, create here\n", 
                 nptr->value);
        #endif

        node * n = create_node(num);
        nptr->right = n;
        added = TRUE;
      }
      else
      {
        #ifdef DEBUG
          printf("  add_iter: greather, take right...\n");
        #endif
        nptr = nptr->right; 
      }
    }
    else
    {
      //value already exists, return FALSE
      #ifdef DEBUG
        printf("  add_iter: value exists, abort\n");
      #endif
      
      added = FALSE;
      
      break;
    }
  }
  return (added ? TRUE : FALSE);
}

// Follows L P R
void print_inorder(node *n)
{
  if(n == NULL)
  {
    #ifdef DEBUG
    printf("\tInORDER : END\n ");
    #endif 
    return;
  }
  #ifdef DEBUG
  printf("\tCalling my left child\n");
  #endif

  print_inorder(n->left);   //L

  printf("%d ", n->value);  //P
  #ifdef DEBUG
  printf("%d\n", n->value);  //P
  printf("\tCalling my right child\n");
  #endif
  print_inorder(n->right);   //R

  /* Don't get confused, wihtout all this debug, 
     this is how the function looks:

  if(n == NULL)
    return;

  print_inorder(n->left);
  printf("%d ", n->value);
  print_inorder(n->right);

  Only 5 lines */
}

boolean contains_recur(node * n, int value)
{
  if(n == NULL) return FALSE;
  printf("  comparing with %d\n", n->value);

  if(n->value == value)
  {
    printf("  found\n");
    return TRUE;
  }
  if(value < n->value)
  {
    boolean existinchild = contains_recur(n->left, value);
    printf("node %d my child %s containse\n", 
      n->value, existinchild ? "YES" : "NO");
    return existinchild;
  }
  else
    return contains_recur(n->right, value);

  /*
    if(n == NULL) return FALSE;
    if(n->value == value) return TRUE;

    if(value < n->value)
      return contains(n->left, value);
    else
      return contains(n->right, value);


  */
}

boolean contains_iter(node * n, int value)
{
  node * current = n;
  while(current != NULL)
  {
    #ifdef DEBUG
    printf("  contains: curr node %d\n", current->value);
    #endif
    if(current->value == value)
    {
      #ifdef DEBUG
      printf("  contains: found it! returning TRUE\n");
      #endif
      return TRUE;
      //found!
    }
    else
    { 
      #ifdef DEBUG
      printf("  contains: Not here, lets compare...");
      printf("%d < or > %d\n", value, current->value);
      #endif
      if (value < current->value)
      {
        #ifdef DEBUG
        printf("  contains: taking left...\n");
        #endif
        current = current->left;
        //left
      }
      else
      {
        #ifdef DEBUG
        printf("  contains: taking right...\n");
        #endif
        current = current->right; 
        //right
      }
    }
  }
  //nothing found
  return FALSE;
}

int main()
{
  /* Run example1, where a tree already exists and traverse it */
  /*Step 1, lets print a existing tree */
  printf("traversing_tree() ... \n");
  learn_traversing_tree();

  /* Example 2 contains the code to add nodes and create a tree */
  learn_building_tree(); 
}

