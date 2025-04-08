#include <stdio.h>
#include "adt_date/date.h"

/* ABSTRACT DATA TYPES:
   Here we have an example of how we can use our own data type
   or data structure called "date"
   
   The most important part, is that we cannot access ANY of the date struct
   properties, because the struct definition is NOT exposed to the user

   The user "learns" how to use the ADT and by reading the header
   file that contains the definition of the public methods that we can use

   The header file, needs to be included with #include "path_to_header.h"

   To compile:

   gcc file1.c abstract_data_type.c 

   IN REAL LIFE we would actually use library files (lib objects) as we saw 
   previous semester to avoid shipping the source code. But for the sake of 
   simplicity and because creating libraries is system dependant we will do it
   this way for the rest of the semester
   */

int main()
{
  date * today;
  today = date_new (1, 10, 2022);
  date_printl(today);
  date_prints(today);

  date * today_copy = date_copy(today);

  printf("Printing using the copy...\n");
  date_printl(today_copy);

  date_prints(today_copy);

  if (date_comp (today, today_copy) == 0)
  {
    printf("This dates are equal\n");
  }
  //date_destroy(today);
  //date_destroy(today_copy);
}