  #include "map.h"
  #include <stdlib.h>
  #include <stdio.h>
  
  struct node_str {
    void * key, * value;
    struct node_str * next;
  };
  
  typedef struct node_str node;
  
  struct map_str {
    hash_func hash;
    equals_func key_equals;
    int M, size;
    node ** hashTable;
  };
  
  /* 
     Creates the memory for map struct, also creates
     the memory for the array of linked list for our table with M number
     of buckets. Stores the hash function and the comparision function inside
     the map. Finally intialize all buckets to NULL, to mark that all possible
     linked list are empty */
  map * map_create(int M, hash_func hf, equals_func eq) 
  {
    map * m = (map *) malloc(sizeof(struct map_str));
    m->M = M;
    m->hash = hf;
    m->key_equals = eq;
    m->size = 0;
    m->hashTable = (node **) malloc(M * sizeof(node *));
  
    for(int i = 0; i < M ; i ++) 
      m->hashTable[i] = NULL;
    return m;
  }
  
  /* returns map size */
  int map_size (map * m) 
  {
    return m->size;
  }
  
  /* creates node and stores data in it */
  node * createNode(void * key, void * value) {
    node * n = (node *) malloc(sizeof(struct node_str));
    n->key = key;
    n->value = value;
    n->next = NULL;
    return n;
  }
  
  /* Stores a key-value pair relationship in them map
    1) for a given key, generate hash code
    2) do mod M on hash code to make sure it fits in the table
    3) Traverse that linked list to insert our update our element
       3.1) if not found, insert on the list
  */
  void map_put(map * m, void * key, void * value)
  {
    /* get bucket number to insert */
    int hashcode = m->hash(key);
    int bucket = hashcode % m->M;
    printf("map_put: hashing key = %d\n", hashcode);
    printf("map_put: bucket = hash mod %d = %d\n", m->M, bucket);
   
    node * n = m->hashTable[bucket];
    printf("map_put:start, looking in bucket %d\n", bucket);

    if(m->hashTable[bucket] == NULL) 
    {
      /* case: the bucket is empty, no elements in the list */
      printf("map_put: List is NULL, creating first node at bucket %d\n", bucket);
      m->hashTable[bucket] = createNode(key, value);
      m->size ++;
      return;
    } 
  
    /* traverse linked list */
    while(n != NULL) 
    {
      /* for every element, review if its the one we are trying to insert
         or replace, using the equals function */
      if(m->key_equals(key, n->key))
      { 
        /* Update value (overwrites) and return */
        printf("map_put: Found, update!\n");
        n->value = value;
        return;
      }
      else
      {
        /* not in this node? continue with the next */
        printf("map_put: Not here, keep searching\n");
        n = n->next;
      }
    }

    /* if we reach this point we have traversed the whole bucket list without
      finding our key, so lets insert a new one, lets put it in the header
      of the list */

    printf("map_put:key not found create new node\n");
    node * new = createNode(key, value);
    new->next = m->hashTable[bucket];
    m->hashTable[bucket] = new;
    m->size ++;
    
  }
  
  /* returns TRUE if map contains the key */
  boolean map_contains(map *m, void * key) 
  {
    int bucket = m->hash(key) % m->M;
    node * n = m->hashTable[bucket];
    while(n != NULL) 
    {
      if(m->key_equals(n->key, key)) 
        return TRUE;
      else
        n = n->next;
    }
    return FALSE;
  }
  
  void * map_get(map *m, void *key) 
  {
    /* 
       Searches the key in the map, if found returns the data it maps to
       if not found returns a void NULL pointer
       
       we need to determine in which of the many linked list we need to search,
       so compute bucket number just as we did with insert map_put*/
    
    int bucket = m->hash(key) % m->M;
    node * n = m->hashTable[bucket];

    /* traverse all list until a node with equal key is found.
    if node exists, return node -> value, otherwise return NULL */
    while(n != NULL) 
    {
      if(m->key_equals(n->key, key)) 
        break;
      else
        n = n->next;
    }
    return n != NULL ? n->value : NULL;
  }