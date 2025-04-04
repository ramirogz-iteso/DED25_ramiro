#include "date.h"
#include <stdio.h>
#include <stdlib.h>

struct date_s {
  int day;
  int month;
  int year;
};

date * date_new(int d, int m, int y)
{
  date * new_date = malloc (sizeof(struct date_s));
  new_date->day = d;
  new_date->month = m;
  new_date->year = y;
  return new_date;
}

date * date_copy(date * d)
{
  date * new_date = malloc(sizeof(struct date_s));
  new_date->day = d->day;
  new_date->month = d->month;
  new_date->year = d->year;
  return new_date;
}

int date_comp(date * d1, date * d2)
{
  int d1_days;
  int d2_days;

  /* assumes all months are 30 days */
  d1_days = d1->year * 365 + d1->month * 30 + d1->day;
  d2_days = d2->year * 365 + d2->month * 30 + d2->day;

  if(d1_days == d2_days) return 0;
  else if(d1_days < d2_days) return 1;
  else return 2;

  /* you can also do like 
    if(d1->year == d2->year && d1->month == d2->month &&
       d1->day == d2->day)
    {
      return 0 // dates are equal...
    }
   */ 
}

void date_prints(date * d)
{
  printf("%d / %d / %d\n", d->day, d->month, d->year);
}

void date_printl(date * d)
{
  printf("%d", d->day);
  if(d->day == 1 || d->day == 31)
    printf("st");
  else if(d->day == 2 || d->day == 22)
    printf("nd");
  else if(d->day == 3)
    printf("rd");
  else
    printf("th");
  printf(" of ");
  switch(d->month)
  { 
    case 1:
      printf("January");
    break;
    case 2:
      printf("February");
    break;
    case 3:
      printf("March");
    break;
    case 4:
      printf("April");
    break;
    case 5:
      printf("May");
    break;
    case 6:
      printf("June");
    break;
    case 7:
      printf("July");
    break;
    case 8:
      printf("August");
    break;
    case 9:
      printf("Sept");
    break;
    case 10:
      printf("October");
    break;
    case 11:
      printf("November");
    break;
    case 12:
      printf("December");
    break;
  }
  printf("\n");
}