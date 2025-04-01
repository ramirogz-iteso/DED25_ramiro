#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int num;
  struct node * next;
} node;

node * create_node(int num)
{
  node * new_node = (node *)malloc(sizeof(node));
  new_node->next = NULL;
  new_node->num = num;
  return new_node;
}

void static_node_example()
{
  node n1, n2, n3;
  n1.num = 1;
  n1.next = &n2;

  n2.num = 2;
  n2.next = &n3;

  n3.num = 3;
  n3.next = NULL;

  printf("Node 1 [%p] num = %d, next = %p\n", 
          &n1, n1.num, n1.next);
  printf("Node 2 [%p] num = %d, next = %p\n", 
          &n2, n2.num, n2.next);
  printf("Node 3 [%p] num = %d, next = %p\n", 
          &n3, n3.num, n3.next);
  printf("\n");
}

void dynamic_node_example()
{
  node * n1 = create_node(1);
  node * n2 = create_node(2);
  node * n3 = create_node(3);

  n1->next = n2; 
  n2->next = n3;
  // Node 3, next already points to null because create_node does that
  
  printf("List = %d -> %d -> %d\n", n1->num, n2->num, n3->num);

  /* EXERCISE 1: Print the entire list in a smarter way 
  (so that it works for N number of nodes) */
  // Tips: Declare a pointer or list start
  node * tmp = n1;

   /* 
      n1   n2   n3
       |    |   |
       1 -> 2 ->3 -> NULL
      /
  tmp         tmp points to n1, both pointers reach "1" */
  
  /* Algorithm:
      While the tmp pointer is not pointing to null:
        Print the number stored in tmp
        Move tmp to the next node   */


  
  /* EXERCISE 2: Add a node at the end of the list and print 
  again to verify */
  node * new_node = create_node(10);

  /* Algorithm: 
    Traverse the entire list until you find the last element
    that points to NULL. Call this last element LAST.
    LAST -> next is currently null.
    Store the address of the new node here.
  
       n1   n2   n3                new_node
       |    |   |                     |
       1 -> 2 ->3 -> NULL            10
               /
            tmp  

       n1   n2   n3                new_node
       |    |   |                     |
       1 -> 2 ->3          ->         10
               /
            tmp                                  */
  getchar();
  tmp = n1; // Very important to reset the pointer, remember it ended up
            // at NULL in the previous operation.
            // Segmentation fault if this is not done.

  // Test print again

  /* How many pointers do we need to traverse and store a list?
  Just 1: The root (or header), as long as all nodes are linked
  to each other and the last node points to NULL. */

  /* Finally, add an element after node [2]
  Print one last time to verify
  
  1 -> 2 -> 5 -> 3 -> 10 -> NULL       */
  new_node = create_node(5);

}

int main()
{
  //static_node_example();
  dynamic_node_example();
  
  return 0;
}
