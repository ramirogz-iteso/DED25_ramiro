#include "adt_map/map.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// converts any number into a positive one using abs (absolute number)
int intHash(void *t) 
{
  int *key = (int *)t;
  int hash = abs(*key);
  return hash;
}

int floatHash(void *t) 
{
  float key = *((float *)t);
  return (int)(key * 1000);
}

int wordHash(void *t) {
  char *key = (char *)t;
  int i, hash = 0;
  for (i = 0; i < strlen(key); i++) 
  {
    hash += (key[i] - 'a');
  }
  return hash;
}

boolean wordEquals(void * t1, void * t2) {
  char *c1 = (char *)t1;
  char *c2 = (char *)t2;
  printf("comparing %s with %s\n", c1, c2);
  return strcmp(c1, c2) == 0;
}

int main() 
{
                          //size // hash // keycompare
  map * map1 = map_create(100, wordHash, wordEquals);
  printf("Inserting Lunes into map... \n");
  map_put(map1, "Lunes", "Monday");
  printf("Inserting Martes into map... \n");
  map_put(map1, "Martes", "Tuesday");
  printf("Inserting Jueves into map... \n");
  map_put(map1, "Jueves", "Thursday");
  printf("Inserting Viernes into map... \n");
  map_put(map1, "Viernes", "Friday");
  printf("Inserting Jueves into map... \n");
  map_put(map1, "Jueves", "Juebebes");
  printf("%d\n", map_size(map1));

  printf("=========== Whats inside the map?==== \n");
  if (map_contains(map1, "Jueves"))
    printf("YES, Contains Jueves\n");
  if (map_contains(map1, "Domingo"))
    printf("YES, Contains Domingo\n");
  if (map_contains(map1, "Lunes"))
    printf("YES, Contains Lunes\n");
  if (map_contains(map1, "Martes"))
    printf("YES, Contains Martes\n");
  if (map_contains(map1, "Viernes"))
    printf("YES, Contains Viernes\n");
  printf("====================================== \n");

  char *value = (char *)map_get(map1, "Lunes");
  printf("%s\n", value);

  return 0;
}
