#include <stdio.h>
#include <stdlib.h>
#include "adt_queue/queue.h"

typedef struct pollito
{
  int id;
  int hp;
  int mp;
} pollito;

int main() {

  queue * q1 = queue_create();
  queue * string_q = queue_create();
  queue * matadero = queue_create();

  queue_enqueue(q1, "Hugo");
  queue_enqueue(q1, "Paco");
  queue_enqueue(q1, "Luis");
  queue_enqueue(q1, "Donald");

  char *is_at_top = (char *) queue_peek(q1);
  printf("%s se encuentra al tope de la fila\n", is_at_top );
  getchar();

  /* aqui tambien podriamos decir: 
    mientras queue_dequeue no nos regrese NULL */
  while(!queue_isEmpty(q1)) {
    char * data = (char *) queue_dequeue(q1);
    printf("Atendido: %s. Tamaño: %d\n", data, queue_size(q1));
    getchar();
   }

  int n1 = 100, n2 = 200, n3 = 300, n4 = 400;
  queue_enqueue(q1, &n4);
  queue_enqueue(q1, &n3);
  queue_enqueue(q1, &n2);
  queue_enqueue(q1, &n1);

  int *ptr_to_int;

  ptr_to_int = (int *)queue_dequeue(q1);
  printf("Saque de la fila el entero %d\n", *ptr_to_int);
  ptr_to_int = (int *)queue_dequeue(q1);
  printf("Saque de la fila el entero %d\n", *ptr_to_int);
  ptr_to_int = (int *)queue_dequeue(q1);
  printf("Saque la fila el entero %d\n", *ptr_to_int);
  ptr_to_int = (int *)queue_dequeue(q1);
  printf("Saque de la fila el entero %d\n", *ptr_to_int);

  getchar();


  pollito p1, p2, p3;
  pollito *ptr_p = malloc(sizeof(pollito));
  pollito *p;

  p1.hp = 100;
  p2.hp = 99;
  p3.hp = 80;
  ptr_p->hp = 999;

  /* Enviar pollos al matadero! se forman como fueron llegando */
  queue_enqueue(q1, &p1);
  queue_enqueue(q1, &p2);
  queue_enqueue(q1, &p3);
  queue_enqueue(q1, ptr_p);

  /* el matadero */
  while(!queue_isEmpty(q1))
  {
    p = (pollito *) queue_dequeue(q1);
    printf("El pollito con HP = %d ha sido desplumado\n", p->hp);
  }

  /* la memoria de los pollos no fue destruida, solo la de los nodos
  que nos ayudaron a formarlo. En todos los ejemplos anteriores usamos
  memoria estatica, pero seguimos siendo responsables de eliminar lo que haya
  sido dinamico */ 
  free(ptr_p);
  queue_destroy(q1);
  return 0;
}
