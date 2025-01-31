#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* This excersise shows how we can take advantage of a void pointer
   and different types of casting (typecast) in pecuilar ways 
   
   EXTRA BONUS KNOWLEDGE :
   To access the elements of a Struct, using a Struct pointer we use
      ->     instead of      .
    (arrow)                (dot)
   
   */

typedef struct student
{
  int type;
  char name[20];
  int grade;
} student;

typedef struct student_prepa
{
  int type;
  char name[20];
  int grade;
  int age;
  int parent_phone;
} student_prepa;


void print_student_grade(void * s)
{
 
  int type = *(int *) s;
  int * int_ptr = (int *) s;

  /* Wait why the hell this works? We cast a struct... to an INT!*/
  printf("-----------PRINT-------------\n");
  printf("Student struct type is: %d\n", type);

  getchar();
  /* Know that we know the actual data that is stored in the memory we can cast
     to the particular type that it really is: */
  if(type == 1)
  { 
    student *s1 = (student *)s;
    printf("Student name = %s and type %d\n", s1->name, s1->type);
  }
  if(type == 2)
  {
    student_prepa *p = (student_prepa *)s;
    /* p now knows how to get to the full struct */
    printf("Student name = %s and type %d\n", p->name, p->type);
    printf("Student age = %d and phone %d\n", p->age, p->parent_phone);
    
  }  
  printf("-----------------------------\n");
}
  
int main()
{
  // type 1 = regular
  // type 2 = highschool (<18)
  
  student s;
  
  s.type = 1;
  strcpy(s.name, "Jose");
  s.grade = 100;

  print_student_grade((void *)&s);

  student_prepa p;
  p.type = 2;
  strcpy(p.name, "Pepito");
  p.grade = 90;
  p.age = 16;
  p.parent_phone = 33311122;
  
  print_student_grade((void *)&p);

  /* What happens if we send a Highschool student miscategorized? 
     or if we do the wrong cast? */
  getchar();
  //Sending JOSE as if it were a highschool student.
  s.type = 2;
  print_student_grade((void *)&s);
  
}