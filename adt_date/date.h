#ifndef MY_DATE
#define MY_DATE

/* The definition of the date struct */
typedef struct date_s date;

/* Welcome to my DATE, thank you for downloading and
using this wonderful TDA that will save you TONS of time.

We accept donations at ramirogz@iteso.mx
*/

/* Public functions 
  date_new 
  creates a new "date" type and uses the passed
  arguments (day, month, year) to set it */

date * date_new(int day, int month, int year);

/* frees the memory for the date obj */
void  date_destroy(date * d);

/* prints date in long format : 5th of september 2022 */
void date_printl(date * d);

/* prints date in short format : 5 / 9 / 22 */
void date_prints(date * d);

/* returns a new date that is a copy of "d" */
date * date_copy(date * d);

/* returns 0 if both dates are equal, 1 of d1 is more recent than d2
   or 2 if d2 is more recent than d1 
  NOTE : This assumes all months are 30 days */
int date_comp(date * d1, date * d2);

#endif
