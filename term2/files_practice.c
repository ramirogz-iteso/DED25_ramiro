#include <stdlib.h>
#include <stdio.h>

/* I/O File Reading: */


int main()
{

  /* Open the file sales.txt */
  /* Read the daily consumption line by line:

    day 5 sales $100.50 items 15
    day 6 sale $210.99 items 21
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

  FILE *sales = fopen("sales.txt", "r+");
  FILE *promedios = fopen("average_sales.txt", "w");
  int day;
  float cost;
  int items;
  int ret;
  char c;

  fputs("MONTHLY AVERAGES\n", promedios);

  while((ret=fscanf(sales, "day %d sales $%f items %d\n", 
                &day, &cost, &items)) != EOF)
  {
    printf("read from file %d %f %d\n", day, cost, items);
    fprintf(promedios, "day %d average %f\n", day, cost/(float)items);
    getchar();
    printf("loop\n");
  }

  fputs("\nAVERAGES WRITTEN IN average_sales.txt", sales);

  fclose(sales);
  fclose(promedios);
  
  /* After finishing writing in average_sales.txt, return
     to ventas.txt and write the following message on a new line:
     AVERAGES WRITTEN IN average_sales.txt
     The file should end up like this...

     ...
     day 9 sales $1200 items 150
     day 19 sales $200 items 50
     AVERAGES WRITTEN IN average_sales.txt
  */

  return 0;
}
