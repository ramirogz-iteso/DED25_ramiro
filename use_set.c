
#include <stdio.h>
#include <string.h>
#include "adt_set/set.h"

int compareInts(void * t1, void * t2) {
  int	*i1 = (int*) t1;
  int *i2 = (int*) t2;
  return *i1 - *i2;
}

int compareStrings(void * t1, void * t2) {
  char* c1 = (char*) t1;
  char* c2 = (char*) t2;
  return strcmp(c1, c2);
}

void printInt(void * t) {
  int* i = (int*) t;
  printf("%2d", *i);
}

void printString(void * t) {
  char* c = (char*) t;
  printf("%s", c);
}

int main() {
  set * intSet = set_create(compareInts, printInt);
  int array[] = { 5, 3, 8, 2, 9, 2, 3, 1, 7, 4, 10, 6, 5, 0, 7, 10, 1 };
//                0  1  2  3  4  5 6   7  8 9
//			 5
//	    3          8
//	  2   4      7   9
//	 1          6     10
//	0


//  Recorrido in-orden:   0, 1, 2, 3, 4, 5, 6,  7, 8, 9, 10

  int N = sizeof(array) / sizeof(int);
  int i;
  for(i = 0; i < N; i ++) {
    boolean added = set_add(intSet, &array[i]);
    if(added) 
      printf("%2d added\n", array[i]);
    else
      printf("Already exists\n");
    getchar();
  }
  printf("Size: %d\n", set_size(intSet));

  if(set_contains(intSet, &array[3])) printf("Contains %d\n", array[3]);  // 2
  if(set_contains(intSet, &array[4])) printf("Contains %d\n", array[4]);  // 9
  if(set_contains(intSet, &array[7])) printf("Contains %d\n", array[7]);  // 1
  int x = -1;
  if(set_contains(intSet, &x)) printf("Contains %d\n", x);  // 11
  else printf("Does NOT contains %d\n", x);

  // ------------------------ Ejemplo pero con Strings ------------------------

  set * stringSet = set_create(compareStrings, printString);
  if(set_add(stringSet, "hola"))  printf("Added hola\n");
  if(set_add(stringSet, "hoja"))  printf("Added hoja\n");
  if(set_add(stringSet, "adios")) printf("Added adios\n");
  if(set_add(stringSet, "hoja"))  printf("Added hoja\n");
  if(set_add(stringSet, "hola"))  printf("Added hola\n");
  if(set_add(stringSet, "mundo")) printf("Added mundo\n");
  printf("Size: %d\n", set_size(stringSet));

  char str[] = "holanda";
  if(set_contains(stringSet, str)) printf("Contains %s\n", str);
  else printf("Does not contains %s\n", str);

  printf("LETS SEE THE CONTENTS OF BOTH SETS:\n");
  set_print(intSet);
  set_print(stringSet);

  //COMPLETE ME
  //set_destroy(intSet);
  //set_destroy(stringSet);

  return 0;
}
