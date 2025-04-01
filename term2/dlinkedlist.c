#include <stdio.h>
#include <stdlib.h>
#define CLEAR printf("\033[0;0H\033[2J");

/* USE THE CODE SEEN IN THE CLASS SLIDES TO COMPLETE THE FOLLOWING EXERCISE */

/* The node */
typedef struct node {
  int value;
  struct node *next;
  struct node *prev;
} node;

/* Our header is called "header" and is a GLOBAL variable  initialized to NULL
   All functions in this exercise will consider "header" as the head of the 
   only list that exists here.  
   In reality, there should be many lists, and functions should receive the 
   list to apply operations to, but we will see that later. */

node *header = NULL;  //<--- this is our first linked list! :) 

//Pending:
node *newNode(int n) 
{
  node *new = malloc(sizeof(node));
  new->next = NULL; // VERY VERY IMPORTANT
  new->value = n;
  return new;
}

//Pending:
void printlist(node *list) 
{
  node *aux = list;
  printf("Current list elements:\n\t");
  while (aux->next != NULL) 
  {
    printf("[%d]<->", aux->value);
    aux = aux->next;
  }
  printf("[%d]<->", aux->value);
  printf("-back-");
  while (aux != NULL) 
  {
    printf("[%d]<->", aux->value);
    aux = aux->prev;
  }
  printf("NULL\n\n");
}

//Pending:
void add(node *n) 
{
  node *nptr = header;

  // handle the case where there is no list, header will be null
  // just update header.
  if(nptr == NULL)
  {
    header = n;
    return;
  }
   
  // cases for adding node n, at the end of a existing list.
  while (nptr->next != NULL) 
  {
    nptr = nptr->next;
  }
  nptr->next = n;
  n->prev = nptr;
}

//Pending:
/* Function that inserts a node N after X
   Finds the first node with value X and inserts N immediately after..

   Returns 1 if it was inserted, or 0 if not 
   The return code is used by the caller to determine if the created node
   needs to be freed or not (the one this function failed to insert )*/

int insertafter(node *new, int n)
{
  node *nptr = header;
  node *next = NULL;
  printf("\t\t(insertafter): number to find: %d\n", n);
  while (nptr != NULL) {
    if (nptr->value == n) 
    {
      printf("\t\t(insertafter): found it!: %d\n", n);
      next = nptr->next;
      nptr->next = new;
      new->next = next;
      return 1;
    } else {
      printf("\t\t(insertafter): not yet, %d\n", nptr->value);
      nptr = nptr->next;
    }
  }
  printf("\t\t(insertafter): failed to find %d, return 0\n", n);
  /* If we reach this, we failed to insert */
  return 0;
}

//Pending:
/* Function that inserts a node N before X
   Finds the first node with value X and inserts
   N immediately before...

   Returns 1 if it was inserted, or 0 if not 
   The return code is used by the caller to determine if the created node
   needs to be freed or not (the one this function failed to insert )*/

int insertbefore(node *new, int n)
{
  node * nptr = header;
  node * back = NULL;
  printf("\t\t(insertbefore): number to find: %d\n", n);
  while(nptr->next != NULL)
  {
    if(nptr->value == n)
    {
      if(nptr == header)
      {
        node *next = nptr;
        header = new;
        header->next = next;
        printf("\t\t(insertbefore): done, replaced header\n");
        return 1;
      }
      else
      {  
        back->next = new;
        new->next = nptr;
        printf("\t\t(insertbefore): done\n");
        return 1;
      }
    }
    else
    { 
      back = nptr;
      nptr = nptr->next;
    }
  }
  printf("\t\t(insertbefore): failed to find %d, return 0\n", n);
  /* If we reach this, we failed to insert */
  return 0;
}

//Pending
/* Function to delete the node that contains number N */
void delete(int n)
{
  node * nptr = header;
  printf("\t\t(delete): number to delete: %d\n", n);
  while(nptr != NULL)
  {
    if(nptr->value == n)
    {
      if(nptr == header)
      {
        // Found element in header, update header and delete
        printf("\t\t(delete): found elem %d at Head", nptr->value);
        header = nptr->next;
        free(nptr);
        return;
      }  
      else
      {  
        printf("\t\t(delete): found elem %d\n", nptr->value);
        // Delete a non-header node
        //node * behindme = nptr -> prev;
        //node * infront = nptr -> next;

        //behindme->next = infront;
        //infront->prev = behindme;

        (nptr->prev)->next = nptr -> next;
        if(nptr->next != NULL)
          nptr->next->prev = nptr -> prev;
        free(nptr);

        printf("\t\t(delete): element deletion completed\n");
        return;
      }
    }
    else
    {
      // Not this node, continue searching (keeping a pointer
      // to the previous node)
      printf("\t\t(delete): not found (%d)... next\n", nptr->value);
      nptr = nptr->next;
    }
  }
}

//Pending
/* Function to search for a node containing number N. If found,
   it should print the memory address where it resides; 
   if not found, it should print "NULL" */

void search(int to_search)
{
  node * n = header;
  while(n->next != NULL)
  {
    if(n->value == to_search)
    {
      printf("\t\t(search): found node [%d] at %p\n", to_search, n);
      return;
    }
    else
    {  
      n = n->next;
    }
  }
  printf("NULL\n\n");
}

int main() 
{
  /* #1 :
  Create a function newNode(n) that creates a new node with value n
  and returns a pointer to the newly created node */

  /* #2:
  Using this function, create a new node to act as the first
  element "header" of our list */

  node *n = newNode(50);
  header = n;

  /* #3:
  Create 5 additional nodes, so that we have a total list of 5 nodes
  properly linked together. Write a function
  add() that receives a node (created with newNode()) and
  adds this node to the end of the list.

  Use a FOR loop to fill the 5 nodes */
  for (int x = 1; x <= 2; x++) 
  {
    node *n = newNode(x + 1);
    add(n);
  }

  /* #4:
  Create a print function to print the entire linked list.
  It should look like this:
    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL
  */
  //printlist(header);

  /* #5:
  Create a menu (inside an infinite while loop), with the following functionalities:
    1) Delete a node
    2) Insert after a given node
    3) Insert before a given node
    4) Search for a node
    6) Insert at the end of the list
  */

  int selection, todel, toinsert, tosearch, putafter, putbefore;
  node *new_node;
  int r;

  while (1) 
  {
    printlist(header);
    printf("\n");
    printf("Select option:\n 1) Delete\n 2) Insert after\n 3) Insert before\n"
           " 4) Search\n 5) add-to-end\n 6) print");
    printf("\topc: ");
    r = scanf("%d", &selection);
    switch (selection) {
    case 1:
      printf("\tNumber to delete: ");
      r = scanf("%d", &todel);
      delete(todel);
      break;
    case 2:
      printf("\tNumber to insert: ");
      r = scanf("%d", &toinsert);
      printf("\tInsert after which node?: ");
      r = scanf("%d", &putafter);

      //allocate new node:
      new_node = newNode(toinsert);

      /* if the node insertion fails, because we cannot find the node it goes 
      before, then delete the previously created node to avoid memory leak*/
      if (!insertafter(new_node, putafter))
        free(new_node);
      break;

    case 3:
      printf("\tNumber to insert: ");
      r = scanf("%d", &toinsert);
      printf("\tInsert before which node?: ");
      r = scanf("%d", &putbefore);
      
      //allocate new node:
      new_node = newNode(toinsert);

      /* if the node insertion fails, because we cannot find the node it goes 
      before, then delete the previously created node to avoid memory leak*/
      if (!insertbefore(new_node, putbefore))
        free(new_node);
      break;

    case 4:
      printf("\tNumber to search: ");
      r = scanf("%d", &tosearch);
      search(tosearch);
      break;
    case 5:
      printf("\tNumber to add: ");
      r = scanf("%d", &toinsert);
      node *n = newNode(toinsert);
      add(n);
      break;
    case 6:
      printlist(header);  
      break;
    }
    getchar();
    printf("press enter to continue\n");
    getchar();
    CLEAR
  }
}

/* #6 Once everything is working, make a copy of this file and  
   name it: doublelinkedlist.c. Add the element "back" to the structure  
   and create a doubly linked list. All functionality must persist.

   The print function should print the list "forward" using `next` and  
   "backward" using `back`, and it should look like this:

     1 -> 2 -> 3 -> 4 -> ... 10 -> 9 -> 8 -> 7 -> ..... 1 -> NULL
*/