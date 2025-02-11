#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* This function is called when student has a non probatory grade */
void mad (char * name, int grade)
{
  printf("Hey %s, you are a Bad boy you better study\n" 
         "your grade is %d!\n",
          name, grade);
  
  printf("Calling parents... \n");
  for(int x = 0; x<3; x++)
  {
    printf("ring...\n");
    sleep(1); // this funcion is inside unistd.h!!
  }
  printf("Thank you, go home.\n");
}

/* This is the regular funcion for any normal student with a normal grade */
void normal (char * name, int grade)
{
  printf("Hey %s, Your grade is %d!\n",
         name, grade);
}

/* Use this funcion to refer to the BEST of the BEST of your class */
void happy (char * name, int grade)
{
  printf("Congrats! %s, Your grade is %d you are the best!\n",
         name, grade);
}

/* CHALLENGE: 
  On the main method, create an ARRAY of 3 function pointers
  Store each one of the function pointers in the following positions :  */
#define MAD 0
#define NORMAL 1
#define BEST 2

/* Complete the function "process_student_grade" so it receives this arrays.
  the student, and the grade.

  The function should, depending on the student, call the right function
  following this rules:

    Grade 100, run function store at BEST positon
    Grade < 60, run MAD.
    For everyone else, run NORMAL.
*/

typedef void (* greeting) (char* name, int grade);

void process_student_grade(greeting *f, char *s, int g)
{

  greeting function_to_execute;

   if(g == 100)
     function_to_execute = f[BEST];
  else if(g >= 60)
     function_to_execute = f[NORMAL];
  else
    function_to_execute = f[MAD];

  /* finally run the right function */
  function_to_execute(s, g);

  /*
  if(g == 100)
     f[BEST](s,g);
  else if(g >= 60)
     f[NORMAL](s,g);
  else
    f[MAD](s,g); */
}

typedef struct s
{
  char name[10];
  int grade;
  greeting f;
} s;

void process_student(s * sptr)
{
  sptr->f(sptr->name, sptr->grade);
}
  
int main()
{
  char student[10] = "Ramiro";
  int grade;
  printf("Enter your grade... ");
  int ret = scanf("%d", &grade);

  greeting messages[3];
  //void (* greeting2[3]) (char* name, int grade);
  
  messages[MAD] = mad;
  messages[NORMAL] = normal;
  messages[BEST] = happy;

  /* TODO #1 call process_student_grade */
  process_student_grade (messages, student, grade);

  /* TODO #2 Now that we think about, would it be nice for the 
  function to be embeeded inside a student structure? 
  
  |--student---|
  | name  ..
  | grade .. 
  | func ----------> ()

  Enhance the program to create a simple student struct, and
  store the relevant function pointer in the struct. 

  Now create a new process_student() function, that receives a 
  student struct pointer and executes the function in it.

  Here you will learn that funcitons pointers can be stored
  inside another object. Use pointers 
  */
  s s1;
  strcpy(s1.name, "PERFECT");
  s1.grade = 100;
  s1.f = happy;

  process_student(&s1);


}