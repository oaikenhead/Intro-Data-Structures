/*
 * Menu Function Declarations
 */

#ifndef MENU_H_
#define MENU_H_

const size_t SIZE = 10;

struct RentalCar{
  int year;
  char make[SIZE];
  char model[SIZE];
  float price;
  bool available;
};

/* Loop menu options in
 * terminal
 */
void userMenuPrompt();

/* Menu Option 1
 * takes input from user for input file
 * reads data from input file into the struct
 */
void readCars(RentalCar list_of_cars []);

/* helper function for print cars
 * to terminal
 */
void sendCarInfo(std::ostream& out, RentalCar list_of_cars []);

/* Menu Option 2
 * uses the struct to print data
 * to the terminal for the user to see
 */
void printCarsToTerminal(RentalCar list_of_cars []);

/* helper fcn for menu option 3
 * this sends the data WITHOUT the indicies to the output file 
 */
void sendCarInfoToFile(std::ostream& out, RentalCar list_of_cars []);

/* Menu Option 3
 *
 */
void printCarsToFile(char file_name [], RentalCar list_of_cars []);

/* helper function for swap
 *
 */
void mySwap(RentalCar * swap1, RentalCar * swap2);

/* Menu Option 4
 * sorts cars by ascending price
 */
void sortCarsByPrice(RentalCar list_of_cars []);

/* Menu Option 5
 * lets you know how much to pay for days of rent
 */
void rentalCarQuery(RentalCar list_of_cars [], int days);

/* Menu Option 6
 * this functions reserves one of the cars and marks them as unavailable
 */
void rentalCarReserve(RentalCar list_of_cars [], int days, int index);

#endif//MENU_H_
