#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
  Continues from iteso_debt_rt_wb  read text - write binary
  This is the C file that reads binary and confirms its all OK.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    float debt;
} student;

void print_school_debt (student ** school, int num_students, char * name)
{

  printf("School: %s\n", name);
  for (int i = 0; i < num_students; i++)
  {
    printf("Student %d debt is $%.2f\n", 
            school[i]->id, school[i]->debt);
  }
}

int main() 
{
    char binary_filename[] = "iteso_debt.dump";
    char school_name[50];
    student ** school;
    int num_students;
    
    printf("Hellow\n");

    FILE * file = fopen(binary_filename, "rb");
    if (!file) 
    {
        perror("Error opening file");
        return 0;
    }

    fread(&num_students, sizeof(int), 1, file);
    printf("Found %d students in the file from binary file\n", num_students);
    
    
    fseek(file, sizeof(student)*num_students, SEEK_CUR );
    fread(school_name, sizeof(school_name), 1, file);
    printf("The school name is %s\n", school_name);
    printf("PRESS ENTER TO LOAD THIS FILE\n\n");
    getchar();
    rewind(file);
    fseek(file, sizeof(int), SEEK_CUR );

    school = (student **)malloc(sizeof(student *) * num_students);
    
    for(int i = 0; i < num_students; i++)
    {
      school[i] = malloc(sizeof(student));
      fread(school[i], sizeof(student), 1, file);
    }
    fread(school_name, sizeof(school_name), 1, file);

    
    
    print_school_debt(school, num_students, school_name);
    fclose(file);    
    return 0;
}