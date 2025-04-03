#include <stdio.h>
#include "date.h"

int main()
{
  date * hoy;   //struct date **
  date today = date_new(1,10,2022);
  date_printl(today);
  date_prints(today);

  date today_copy = date_copy(today);

  printf("Printing using the copy...\n");
  date_printl(today_copy);
  date_prints(today_copy);

  if (date_comp (today, today_copy) == 0)
  {
    printf("This dates are equal\n");
  }
}