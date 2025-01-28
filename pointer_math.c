/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEAR printf("\033[0;0H\033[2J");

void pointers_math();
void overflow();
void structs();

int main()
{
  CLEAR
  pointers_math();
  //getchar();

  CLEAR
  overflow();
  //getchar();

  CLEAR
  structs();

  return 0;
}

void pointers_math()
{
  int numbers[5] = {99, 100, 101, 102, 105};

  //int * i_ptr = &numbers[0];
  int * i_ptr = numbers;

  // !!!!! NOTE !!!!!
  /* THE NAME OF THE ARRAY, represents the ADDRESS of the first element */
  /* lets use that :) 

    WE CANT DO numbers++
  */

  printf("Number = %p\n", i_ptr);
  i_ptr++;
  getchar();
  printf("Number = %d\n", *i_ptr);
  i_ptr = i_ptr + 3;
  getchar();
  printf("Number = %d\n", *i_ptr);
  getchar();
  i_ptr--;
  printf("Number = %d\n", *i_ptr);
  getchar();

  printf("\nThe addresses on the array are: \n\n");
  for(int i = 0; i<5; i++)
  {
    printf("%p - ", &numbers[i]);
  }
  printf("\n");

  /* How can we do the above for loop, without "[]" ?*/
  int * a_pointer_to_int = numbers;;
  for(int i = 0; i<5; i++, a_pointer_to_int++)
  {
    printf("%p - %d ", i_ptr, *i_ptr);
    i_ptr++;
  }
  printf("\n");
  
  printf(" = = = = = = = = = = = = = = = = = = = \n");
  getchar();
  
  char name[6] = "ramiro";
  char another_arr[10] = "GAMEOVER";
  /* 3 */
  printf("now printing letter by letter:\n");
  char *c_ptr = &name[0];
  printf("%c\n", *c_ptr);
  c_ptr++;
  printf("%c\n", *c_ptr);
  c_ptr--;
   printf("%c\n", *c_ptr);

  getchar();

  char * c_ptr2 = name;
  /* now in a for loop */
  printf("now in a loop\n");
  printf("START of for \n");
  for(int i=0; i<10; i++)
  {
    printf("\t%c\n", *c_ptr2);
    c_ptr2++;
  }
  printf("END of for \n");
  printf("name = %s\n\n\n", name);

  int nums[10] = {10,20,30,40,50,60,70,80,90,100};
  int * ptr_num;
  ptr_num = nums;
  
  for(int i=0; i<10; i++)
  {
    printf("addr[%p] = %d \n", &nums[i], nums[i]);
  }

  getchar();
  i_ptr = nums;
  printf("i_ptr = nums   =>  %p, %d\n", i_ptr, *i_ptr);
  i_ptr += 5;
  printf("i_ptr = nums   =>  %p, %d\n", i_ptr, *i_ptr);
  i_ptr = &nums[9];
  printf("i_ptr = nums   =>  %p, %d\n", i_ptr, *i_ptr);
  
  
}

void overflow()
{
  /* using pointers is a manual way to access the memory,
  what you do, is up to you. You will not get errors at compile time,
  but very weird behaviour at run time */
  printf(" = = = = = = =OVERFLOW = = = = = = = = \n");
  int num[3] = {64, 01, 10};
  int * ptr_num = num;
  
  printf("address of ptr_num = %p\n", ptr_num);
  getchar();

  ptr_num--;
  ptr_num--;
  /* ugly, but short */
  for(int i = 0; i<7; i++, ptr_num++)
  {
    printf("address ptr_num %p -> value %d\n", ptr_num, *ptr_num);
    getchar();
  }

  //while(1)
  //{
  //  printf("address ptr_num %p -> value %d\n", ptr_num, 
  //  *ptr_num);
  //
  //  ptr_num++;
  //}
}

void structs()
{
  typedef struct box 
  {
    int x;
    int y;
    int z;
  } box;

  box boxes[5];

  box * boxptr = boxes;

  /* NEW NEW NEW .... If you have a pointer to a struct.
     AND you want to access its elements.

      use " -> "  instead of   "."

  */
  
  boxptr->x = 10;
  boxptr->y = 5;
  boxptr->z = 20;

  printf("The box array, has a box[0] with this properties:\n");
  printf("X = %d\n", boxes[0].x);
  printf("Y = %d\n", boxptr->y);
  printf("Z = %d\n", boxes[0].z);  
  
}