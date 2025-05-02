#include <stdio.h>
#include "adt_pq/pq.h"

/* This example, uses a MIN priority queue.
Please note that the code for MIN and MAX PQs is exactly the same, the only
thing that changes is your comparasion function! */

int compareInts(void * t1, void * t2) 
{
  int* i1 = (int*) t1;
  int* i2 = (int*) t2;
  return *i1 - *i2;
}

int main() {
  int data[] = {6, 3, 7, 2, 5, 1, 8, 0, 4, -1, 9, -2, 10, -3, 11, -4, 0, 5, 1, -2};
  int N = sizeof(data) / sizeof(int);

  pq * min_pq1 = pq_create(30, compareInts);
  int i, *min;
  int *ptr = data;
  for(i = 0; i < N; i ++, ptr ++) 
  {
    pq_offer(min_pq1, ptr);
    printf("Adding: %3d. ", *ptr);
    min = (int*) pq_peek(min_pq1);  
    printf("Peek: %3d\n", *min);
  }

  while(pq_size(min_pq1) > 0) 
  {
    min = (int*) pq_poll(min_pq1);
    printf("Poll: %3d\n", *min);
  }
  return 0;
}
