#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lets create a 2D INT matrix of 5 columns and 3 rows 
    [1, 2, 3, 4,  5]
    [6, 7, 8, 9, 10]
    [11,12,13,14,15] 

    Don't forget to free it!
   */   

int main()
{
  // step # 1. create the double pointer that will be used to reference to
  // the 2D matrix
  
  int **matrix;

  // step #2 . allocate enough memory for the rows (what is the data type?)
  matrix = malloc (3 * sizeof(int *));

  // step #3 . for each one of the rows, allocate enough memory for the columns
  for(int i = 0; i<3; i++)
  {
    matrix[i] = malloc(sizeof(int) * 5);
  }

  // step #4 . verify that the 2D matrix works as usual, just as you saw in the
  // previous semesters, you can use brackets [ ] fill matrix and print to test 
  
  int cont=1;
  //fill it
  for(int x = 0; x<3; x++)
  {
    for(int y = 0; y<5; y++)
    {
      matrix[x][y] = cont;
      cont++;
    }  
  }

  //print
  for(int x = 0; x<3; x++)
  {
    for(int y = 0; y<5; y++)
    {
      printf("[%d]", matrix[x][y]);
    }  
    printf("\n");
  }

  /* Can you do the same to store the following :

  ["WELCOME"]                len = 8
  ["TO"]                     len = 3 
  ["DATA STRUCTURE CLASS"]   len = 21

  */

  char ** banner = malloc (sizeof(char *) * 3);

  banner[2] = malloc(sizeof(char) * 21);
  banner[0] = malloc(sizeof(char) * 8);
  banner[1] = malloc(sizeof(char) * 3);
  

  strcpy(banner[0], "WELCOME");
  strcpy(banner[1], "TO");
  strcpy(banner[2], "DATA STRUCTURE CLASS");

  /* can you print it using pointer math :) ? */
  char ** charp = banner;
  printf("%s %s %s\n", *charp, *(charp+1), *(charp+2));

  charp++;
  char * letter = *charp;


  /* can you print it with brackers [] ? */
  printf("%s %s %s\n", banner[0], banner[1], banner[2]);
  

  /* FREE everything we just created */
  free(banner[0]);
  free(banner[1]);
  free(banner[2]);
  free(banner);

    
  for(int i = 0; i<3; i++)
  {
    free(matrix[i]);
  }
  free(matrix);

}