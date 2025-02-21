#include <stdio.h>

/* In this file we will learn how we can make arrays
   made of arrays.
   
  a = [1,5,9]  b = [0,2,4]
        
      [  a   ,   b   ]

  Todo do this, we need to understand the use of double pointers,
  or pointers to a pointer type:  
    
*/

void array_pointers_basics();

int main()
{
  array_pointers_basics();
}

void array_pointers_basics()
{
  printf(" = = = = = = = = = = = = = = = = = = = \n");
  int arr0[3] = {0,1,2};
  int arr1[3] = {3,4,5};
  int arr2[3] = {6,7,8};

  /* super basics: lets remember how we traverse over a simple array
  using pointer arithmetic and remember basic rules:

    1) the array name, represents the address of the first element
    2) the array name, cannot do pointer math   arr0++ will not work
    3) to move a pointer, we need a pointer of the stored type (int *) here
  */
    
  // create a pointer to the stored type:
  int * iptr = NULL;

  //point this to the beginning of the array
  // iptr =  &arr0[0]  or  iptr = arr0;
  iptr = arr0;

  //using pointer arithmetic, we can traverse the array
  printf("value arr0[0] = %d at addr %p\n", *iptr, iptr);
  iptr++;
  printf("value arr0[1] = %d at addr %p\n", *iptr, iptr);
  iptr++;
  printf("value arr0[2] = %d at addr %p\n", *iptr, iptr);

  getchar();

  /* all of the above can also be done in a for loop if we know the size of the
     array, if its is a string we can use the '\0' (NULL) character to end */
  
  iptr = arr2;
  for(int i = 0; i<3; i++, iptr++)
  {
    printf("value arr2[0] = %d at addr %p\n", *iptr, iptr);

  }

  /* what if we want an array that stores arr[0], arr[1], and arr[2])*/
 
  iptr = arr2;
  int * ptr_array[3] = { arr0, &arr1[0], iptr};
  // { arr0, arr1, arr2}; o inicializarlo despues.

  printf("\n\nAddress of the original array: \n");
  for(int i = 0;i<3;i++)
  {
    printf("%p, %p, %d\n", &ptr_array[i], ptr_array[i], *ptr_array[i]);
  }
  printf("\n");

  getchar();

  // -------------  Here comes the NEW things!  (and not so new) ----------
  // just as we declared and int *, to traverse an int array.
  // if we have an array of int * .... we need an int * * to traverse it.
  // in general it works like this:

  // to traverse an array, you need a pointer, of the data stored in the array

  int **dptr = ptr_array; //&ptr_array[0]
  printf("Address stored on pointer dptr:  \n");
  for(int i = 0;i<3;i++)
  {
    printf("%p - ", *dptr);   // why * y not dptr?
    printf("%d \n", **dptr);
    dptr++;
  }
  printf("\n");
  getchar();
  
  /* Usemos solo la variable tipo doble apuntador dptr   
    dptr controla las "filas"    
    iptr controla las "columnas"
    En realidad la memoria "Es plana" y no existe el concepto de 
    filas y columnas que anteriormente habiamos usado para entender
    mas facilmente matrices (x,y) */
  
  dptr = NULL;
  dptr = ptr_array; //reset position
  int * int_ptr = NULL;
  
  printf("using double pointers and pointers ");
  for(int i = 0;i<3;i++)
  {
    int_ptr = *dptr;
    for(int x = 0; x<3; x++)
    {
      printf(" %d ",*int_ptr);
      int_ptr++;
    }
    dptr++;
  }
  printf("\n");  
  getchar();

  //  ---- lo mismo pero con corchetes ----
  printf("con corchetes: ");
  for(int i = 0;i<3;i++)
  {
    iptr = ptr_array[i];
    for(int x = 0; x<3; x++)
    {
      printf(" %d ", iptr[x]);
    }
  }
  printf("\n");
  getchar();

  printf("\n============================\n");
  getchar();

  /* now with chars */ 
  char letters[5] = {'s', 'e', 'b', 'a', 's'};
  char name[3] = "ale";

  char *str[5] = {"edgar", name, "T", "nacho", letters};
  //char *str[4] = {name name, name, name};
  char ** str_ptr = str;

  printf("%s\n", *str_ptr);
  str_ptr++;
  for(int i=1; i<=4; i++)
  {
    printf("%s\n", *str_ptr);
    str_ptr++;
  }

  //TODO , talk about continuos memory, however this only applies to statically
  //       defined 2D arrays. (its compiler dependant)
  
  // ---- Same logic but using strings (arrays of chars)

  char classroom[3][7] = {"Mateo", "Iker", "Walls"};
  char * student = &classroom[0][0];

  // reminder, printf prints all chars up to the  '\0' mark
  printf("student 1 = %s\n", student);

  char * c = student;
  for (int x = 0; x <= 21; x++)
  {
    printf("[%c]", *c);
    c++;
  }
}

