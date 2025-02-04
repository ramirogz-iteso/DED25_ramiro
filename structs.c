#include <stdio.h>
/*==============================
      STRUCTS IN C
      In case you forgot... 
=================================*/

/* 
   typedef : allows to declare a new datatype, base on existing ones
   
   Syntax
    a)  
        typedef struct name_of_struct
        {
          variables
        } name_ofStruct;
    
    or b)
        struct name_of_struct
        {
          variables
        }
        typedef struct name_of_struct

    After this typedef, we will be able to create structs or struct pointers
    easily as this:
    
        name_of_struct s1;         // a structure of name_struct type  (.)
        name_of_struct * ptr_s;    // a pointer to a struct (->)

    https://www.educative.io/answers/how-to-use-the-typedef-struct-in-c
    
*/

/* Create  a struct node, with a typedef; */
typedef struct node
{
  int n;    // int number // 4
  float f;  // a float    // 4
  char *s;  // a char     // 8
  int i;                  // 4
  char c2;                // 1
  char name[100];         // 100 times 1
}node;

/* quiz , what is the size of the struct?
          what is the size of the pointer to the struct?
*/ 

int structs()
{
  printf(" = = = = = = = = = = = = = = = = = = = \n");
  node n;

  //the old way:
  n.n = 5;
  n.f = 2.999;
  //n.s = 's';  //TRY ME
  
  //now with a pointer to a struct!
  node *ptr_n = &n;
  printf("sizeof struct :%ld , sizeof ptr %ld\n",
          sizeof(node), sizeof(ptr_n));

  getchar();

  /* To access the elements of a struct we use the "." POINT operator */
  printf("node : %d, %f and %s \n",  n.n, n.f, n.s);
  
  /* the only difference, when we have a pointer*/
  printf("node : %d, %f and %s \n", ptr_n->n, ptr_n->f, ptr_n->s);
  return 0;
}

int main()
{
  structs();
}