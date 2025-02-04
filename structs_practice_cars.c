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