#include <stdlib.h>
#include <stdio.h>

/* I/O File Reading: */


int main()
{

  /* Open the file sales.txt */
  /* Read the daily consumption line by line:

    day 5 sales $100.50 items 15
    day 6 sales $210.99 items 21
    ..

  */

  /* Calculate the average cost per item per day and write it
     in ANOTHER FILE (average_sales.txt), 
     each line should be formatted as follows:

     MONTHLY AVERAGES
     day 5 average $6.7
     day 6 average $10.04
     ..
  */
  
  /* After finishing writing in average_sales.txt, return
     to sales.txt and write the following message on a new line (at the end):
     AVERAGES WRITTEN IN average_sales.txt
     The file should end up like this...

     ...
     day 9 sales $1200 items 150
     day 19 sales $200 items 50
     AVERAGES WRITTEN IN average_sales.txt
  */

  return 0;
}
