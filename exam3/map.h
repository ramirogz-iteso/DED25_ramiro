#ifndef MAP_H_
#define MAP_H_

typedef int boolean;
#define TRUE 1
#define FALSE 0

typedef int  (*hash_func)(void *);
typedef boolean (*equals_func)(void *, void *);
typedef struct map_str map;

map *  map_create  (int m, hash_func, equals_func);
int  map_size    (map * m);
void map_put     (map * m, void * key, void * value);
boolean map_contains(map * m, void * key);
void * map_get     (map * m, void * key);

#endif /* MAP_H_ */
