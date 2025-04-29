#include <stdlib.h>
#include <stdio.h>
#include "set.h"

/* Set
A Set is a container that allows us to store elements
following the property:

  - Elements NEVER repeat, they are always unique.

To ensure that the element does not exist, we must check all previously 
inserted elements. Using a linked list would be very costly since we cannot
avoid traversing every single element.

To facilitate this task, we rely on a classic data structure called 
"Binary Search Tree" or BST. This structure helps reduce the search space for 
an element since only the branches that are likely to lead to it are traversed.

More theory and diagrams in the class presentation */

/* Node, a BST is made up of nodes, and each must have 2 pointers, one for the 
left child and one for the right. Like all other ADTs we've seen in class, it 
stores a Type which is a void * to allow storing "anything". */

struct node_str 
{
  void * data;
  struct node_str *left, *right;
};

typedef struct node_str node;

/* Our set contains a pointer to the root of the tree, its single point of 
entry, as well as the size of the tree and 2 function pointers:
  - compare, which we use to determine the order of the elements
  - print, which we use to interpret and print the node's content  */
struct set_str 
{
  node * root;
  int size;
  comp_func compare;
  print_func   printme;
};

/* Creates a set and initializes its values */
set * set_create(comp_func cf, print_func pf) 
{
  set * s1 = (set *) malloc(sizeof(struct set_str));
  s1->root = NULL;
  s1->size = 0;
  s1->compare = cf;
  s1->printme   = pf;
  return s1;
}

/* returns the size of the set (how many unique elements it has) */
int set_size(set * s) 
{
  return s->size;
}

/* function to allocate and create a new leaf (node) of the tree */
node * createLeaf(void * data) {
  node * leaf   = (node *) malloc(sizeof(struct node_str));
  leaf->data   = data;
  leaf->left  = NULL;
  leaf->right = NULL;
  return leaf;
}

/* function to add (insert) the newly created leaf into the tree.
This is the main function that contains the logic to build the tree
following these rules:
  - If the element is smaller -> it becomes* the left child
  - If the element is larger -> it becomes* the right child.
  - If the element is equal, it is not inserted, since it already exists.

*it only becomes left or right child if there's a free pointer,
otherwise, we must repeat the operation on that node.
NOTE: THIS FUNCTION IS RECURSIVE (but it can also be implemented 
iteratively) */
boolean add_node(node * n, void * data, comp_func compare) 
{ 
  int res = compare(data, n->data);
  if(res == 0)
  {
    /* element already exists, cannot be inserted */
    return FALSE;
  }
  else if(res < 0) 
  {
    /* element is smaller, take the left path if possible */
    if(n->left == NULL) 
    {
      /* reached end of this branch, space available for insertion */
      n->left = createLeaf(data);
      return TRUE;
    } 
    else 
    {
      return add_node(n->left, data, compare);
    }
  } 
  else 
  {
    /* element is larger, take the right path if possible */
    if(n->right == NULL) 
    {
      /* reached end of this branch, space available for insertion */
      n->right = createLeaf(data);
      return TRUE;
    } 
    else 
    {
      return add_node(n->right, data, compare);
    }
  }
}

/* Entry point for adding an element to the set. Remember that since this is 
an ADT, we could maintain multiple Sets in memory at the same time. 
If we were just building a Binary Tree for a known data type, we could go 
straight to inserting at the root. */

boolean set_add(set * s, void * data) 
{
  /* if the root is NULL or if there are no elements, we know the SET is
  empty, and we can start building the tree by inserting the first
  element as the root */
  if(s->root == NULL) 
  {
    s->root = createLeaf(data);
    s->size = 1;
    return TRUE;
  }

  /* if the root is occupied, we start searching for the spot where the new
  node (leaf) will exist. THIS IS WHERE OUR RECURSION BEGINS.

  we know add_node will insert the new element in the tree or return FALSE 
  if it already existed. Either way, we’ll know the result after this function 
  finishes */
  
  boolean inserted = add_node(s->root, data, s->compare);
  if(inserted)
  {
    s->size++;
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

/* Function to add a new element iteratively (without recursion) */
boolean set_add_iterative(set * s, void * data) 
{
  if(s->root == NULL) {		// if(set->size == 0) {
    s->root = createLeaf(data);
    s->size = 1;
    return TRUE;
  }
  //	The tree is not empty. We need to find the spot for the new key
  boolean found = FALSE, added = FALSE;
  node * current = s->root;
  while(!found && !added) 
  {
    int res = s->compare(data, current->data);
    if(res == 0)      // key = current->key, EXISTS ALREADY ignore
    {				
      found = TRUE;
    } 
    else if(res < 0)  // key < current->key  ... take LEFT
    {		
      if(current->left == NULL) 
      {
        current->left = createLeaf(data);
        added = TRUE;
      } else 
      {
        current = current->left;
      }
    } 
    else // key > current->key ... take RIGHT
    {  					
      if(current->right == NULL) 
      {
        current->right = createLeaf(data);
        added = TRUE;
      } else 
      {
        current = current->right;
      }
    }
  }
  if(added) s->size ++;
  return added;
}

/* In-Order Print 
  Prints LEFT - NODE - RIGHT  
  until it reaches NULL pointers (leaves of the tree) */
void printKey(node * n, print_func p) 
{
  if(n == NULL) 
    return;

  printKey(n->left, p);
  p(n->data); printf("\n");
  printKey(n->right, p);

}

/* Entry point for printing all contents of a SET
This function performs an "In Order" tree traversal 
https://dev.to/javinpaul/how-to-implement-inorder-traversal-in-a-binary-search-tree-1787
*/
void set_print(set *s) 
{
  printKey(s->root, s->printme);
  printf("-------------------\n");
}

/* Checks if an element already exists in the tree. This function follows the 
same traversal logic (print) but adds the check for whether the element exists
and avoids exploring branches where we know the element can no longer be found*/
boolean containsKey(node * n, void * data, comp_func compare) 
{
  if(n == NULL) 
    return FALSE;

  int res = compare(data, n->data);
  if(res == 0) return TRUE;

  if(res  < 0) 
  {
    return containsKey(n->left, data, compare);
  }
  else
  { 
    return containsKey(n->right, data, compare);
  }
}

/* Entry point for set_contains */
boolean set_contains(set * s, void * data) {
  return containsKey(s->root, data, s->compare);
}


/* To destroy the SET we must destroy the entire tree. In this case we do it by 
traversing each node in POST-ORDER and freeing the memory of the nodes we've 
visited. Always from the leaves, never from intermediate nodes.
The POST-ORDER traversal algorithm helps us traverse the tree in this way:

https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

*/ 
void destroyNode(node * n, print_func pf) 
{
  if(n == NULL) 
    return;

  destroyNode(n->left,  pf);
  destroyNode(n->right, pf);

  printf("The node with key will be deleted: ");
  pf(n->data);
  printf("\n");
  free(n);
}

void set_destroy(set * s) 
{
  destroyNode(s->root, s->printme);
}