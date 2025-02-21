/* Practice:

  Declare a struct "vehicle" with the following attributes:
  -brand, a 20 char array to store the maker info ("ford, honda, vw, etc")
  -year, an integer to store its model year (1999, 2020, 2025 etc)
  
  Use a typedef whenever possible
  ej.  "Honda", 2001

  In the main loop create an array of 4 vehicles variables.
  Create a function "vehicle_set" that receives the address of a vehicle struct
  and sets their properties accordingly.
  
  Initialize vehicle 1, without using pointers, but ask the data to the user
  Intialize vehicles 2, 3 and 4 using your newly created function like this:

  ex.  vehicle_set(car_ptr, "Ford", 2020);
       vehicle_set(&vehicle_array[3], name1var, year);

  PRACTICE as many combinations or way to pass your vehicles to your function
  Will it be a good idea to verify and print the contents after each vehicle_set?
  DEBUG your code.

  Feel free to either use preset values, or ask again the user if you want.

  Finally, create a function called "print_lot" that receives the entire vehicle 
  array and WITHOUT USING BRACKETS, prints in the screen all the cars. 
  The same function should return which car is the Oldest of the lot, to do this:
     -return, as an integer the year
     -write the name of the car, in an output buffer passed by the user.
  
  How do you determine how many vehicles to print? What else besides the array
  do you need? Remember this are not NULL terminated strings.

  oldest_year  print_lot ( IN : Vehicle Array,   OUT : Oldest vehicle name);

  Expected usage:
    
     1: char oldest_buffer[20];
     2: int oldest_year = print_lot (YOUR_VECHILE_ARRAY, oldest_buffer);

     After executing line 2, oldest_year will be populated and oldest_buffer 
     will contain the name

  Use NULL pointer validations whenever possible to prevent the user causing a 
  SEGMENTATION FAULT

*/

#include <stdio.h>
#include <string.h>

#define MAX_CARS 4

typedef struct vehicle
{
  char brand[20];
  int year;
} vehicle;

int print_lot ( vehicle *, char *);
void vehicle_set ( vehicle *, char *, int );

int main()
{
   vehicle cars[4];
   char v4name[20];
   int v4year;
   char oldest[20];

   while(1)
   {
      printf("aaaaaaaa\n");
   }
  
   //step 1: init vehicle # 1 without pointers:
   strcpy(cars[0].brand, "Honda");
   cars[0].year = 2013;

   //step 2: set up vehicles 2 and 3 using my function and static data
   vehicle *vptr = &cars[1];
   vehicle_set(vptr, "TOYOTA", 2022);
   vehicle_set(&cars[2], "FORD", 1990);

   //step 3: set up the last vehicle with user input
   printf("Enter the name of the last vehicle: ");
   scanf("%s", v4name);
   printf("Enter the model (year) of the last vehicle: ");
   scanf("%d", &v4year);
   vehicle_set(vptr+2, v4name, v4year); //where is vptr pointing to?
   
   //step 4: PRINT ALL!
   print_lot(cars, oldest );
   /*
   printf("Hello world! I have only 1 vehicle\n");
   for(int x = 0; x<4; x++)
     printf("name: %s, year %d\n", cars[x].brand, cars[x].year);

   */  
   return 0;
}

void vehicle_set(vehicle * v, char * c, int y)
{
  strcpy(v->brand, c);
  v->year = y;
}


int print_lot( vehicle *v, char * oldest_name)
{
  vehicle * vptr = v;
  int oldest_year = v->year;
  int oldest_idx = 0;

  printf(" ==== PRINT LOT: ===\n");
  for(int x = 0; x < MAX_CARS; x++)
  {
   printf("comparing %d with %d\n", vptr->year, oldest_year);
   if(vptr->year < oldest_year)
   {
      oldest_year = vptr->year;
      oldest_idx = x;
   }
   printf("\tname: %s, year %d\n", vptr->brand, vptr->year);
   vptr++;
  }
  printf("Oldest found at idx [%d]\n", oldest_idx);
  return 0;
}
