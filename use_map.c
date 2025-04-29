#include "adt_map/map.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

// convierte cualquier nuemero a su valor absolto (fabs)
// falta pasarlo por el % para asegurarnos que quepa dentro del
// rango de nuestro arreglo, pero eso ya es parte de la implementacion
// de set.c
int intHash(void *t) {
  int *key = (int *)t;
  int hash = fabs(*key);
  return hash;
}

int floatHash(void *t) {
  float key = *((float *)t);
  return (int)(key * 1000);
}

int wordHash(void *t) {
  char *key = (char *)t;
  int i, hash = 0;
  for (i = 0; i < strlen(key); i++) {
    hash += (key[i] - 'a');
  }
  //printf("wordHash(): key %s, hash %d\n", key, hash);
  return hash;
}

boolean wordEquals(void * t1, void * t2) {
  char *c1 = (char *)t1;
  char *c2 = (char *)t2;
  return strcmp(c1, c2) == 0;
}

int main() {
  map * map1 = map_create(1, wordHash, wordEquals);  //size // hash // keycompare
  map_put(map1, "Lunes", "Monday");
  map_put(map1, "Martes", "Tuesday");
  map_put(map1, "Jueves", "Thursday");
  map_put(map1, "Viernes", "Friday");
  map_put(map1, "Jueves", "Juebebes");
  printf("%d\n", map_size(map1));

  printf("=========== Whats inside the map?==== \n");
  if (map_contains(map1, "Jueves"))
    printf("Contiene a Jueves\n");
  if (map_contains(map1, "Domingo"))
    printf("Contiene a Domingo\n");
  if (map_contains(map1, "Lunes"))
    printf("Contiene a Lunes\n");
  if (map_contains(map1, "Martes"))
    printf("Contiene a Martes\n");
  if (map_contains(map1, "Viernes"))
    printf("Contiene a Viernes\n");
  printf("====================================== \n");

  char *value = (char *)map_get(map1, "Lunes");
  printf("%s\n", value);

  int ret = wordHash("nelson");
  printf("retrun %d ret mod 4 %d\n", ret, ret % 4);

  return 0;
}
