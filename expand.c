#include <stdio.h>
/*
  NOTE: Only write code where you see:
     YOUR CODE STARTS HERE

        in this section :) 
  
     YOUR CODE ENDS HERE 
  
  Expanding the linked list:

  The following program constructs a list as follows:


  * L0:     1 -  5 - 7 - 9 -  6
  *         |        |
  * L1:     3        2
  *                  |
  * L2:              0

  Each node can have a child below it.
 

  Printing the list using the provided "print" function gives the following output:
  
  list : 1c 5 7c 9 6

  The "c" indicates that node **N** has a child (which is not printed).
  The `print` function only traverses and prints nodes in L0.

  "Expanding the list" should convert all child nodes of N into next nodes 
  (to the right via the `next` pointer).

  In the given example, after expanding the list, `print` should output:

   list : 1 3 5 7 2 0 9 6

  NOTE: Only nodes at level 0 (L0) can have elements to the right (`next`).
    e.g., the following is not allowed:
    
  * L0:     1 -  5 - 7 - 9 -  6
  *         |        |
  * L1:     3 - 4    2   <---- node 3 should not have another node in `next`.
  *                  |
  * L2:              0

  `NULL` is used as an end-of-list indicator both horizontally (`next`) 
  and vertically (`down`).

  Only implement the `expand()` function. Do not modify the rest of the program.

  This is the correct output of the program:

  Before expanding:
  list : 1c 5 7c 9 6 
  list : 1 5c 10 
  list : 1c 8c 
  list : 10 
  After expanding:
  list : 1 3 5 7 2 0 9 6 
  list : 1 5 2 10 
  list : 1 2 3 8 9 0 
  list : 10 
*/


/* Global variables DO NOT MODIFY */
typedef struct node
{
  int val;
  struct node *next;
  struct node *down;
} node;

/* DO NOT MODIFY */
node node1, node2, node3, node4, node5, node6, node7, node8;
node *head;

node d1, d5, d2, d0;
node *head2;

node b1, b2, b3, b8, b9, b0;
node *head3;

node v1;
node *head4;

void build_list()
{
  /* Do not modify, seriously don't touch :) */
  node1.val = 1; node1.down = &node6; node1.next = &node2;
  node2.val = 5; node2.down = NULL; node2.next = &node3;
  node3.val = 7; node3.down = &node7; node3.next = &node4;
  node4.val = 9; node4.down = NULL; node4.next = &node5;
  node5.val = 6; node5.down = NULL; node5.next = NULL;
  node6.val = 3; node6.down = NULL; node6.next = NULL;
  node7.val = 2; node7.down = &node8; node7.next = NULL;
  node8.val = 0; node8.down = NULL; node8.next = NULL;
  head = &node1;

  d1.val=1; d1.next=&d5; d1.down=NULL;
  d0.val=10; d0.next=NULL; d0.down=NULL;
  d5.val=5; d5.next=&d0; d5.down=&d2;
  d2.val=2; d2.next=NULL; d2.down=NULL;
  head2 = &d1;

  b1.val=1; b1.next=&b8; b1.down=&b2;
  b2.val=2; b2.next=NULL; b2.down=&b3;
  b3.val=3; b3.next=NULL; b3.down=NULL;
  b8.val=8; b8.next=NULL; b8.down=&b9;
  b9.val=9; b9.next=NULL; b9.down=&b0;
  b0.val=0; b0.next=NULL; b0.down=NULL;
  head3 = &b1;

  v1.val=10; v1.next=NULL; v1.down=NULL;
  head4 = &v1;
}

/* Traverses through next only, prints "c" if it has a child 
   DO NOT MODIFY */
void print(node *header)
{
  node * tmp = header;
  printf("list : ");
  while(tmp != NULL)
  {
    printf("%d%s ", tmp->val, (tmp->down) ? "c":"");
    tmp = tmp->next;
  }
  printf("\n");
}

void expand(node  *h)
{
  /* YOUR CODE STARTS HERE */

  /* YOUR CODE ENDS HERE */
}

int main()
{
  build_list();

  printf("Before expanding\n");
  print(head);
  print(head2);
  print(head3);
  print(head4);
  
  expand(head);
  expand(head2);
  expand(head3);
  expand(head4);

  printf("After expanding\n");
  print(head);
  print(head2);
  print(head3);
  print(head4);

}
