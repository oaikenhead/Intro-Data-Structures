/*
 * Menu Function Definitions
 */

#include <iostream>
#include <fstream>
#include "menu.h"
#include "my_string.h"

const int CARS = 5;

// Displays User Menu that Reiterates
void userMenuPrompt(){
  // variables needed
  RentalCar list_of_cars[CARS];
  char output_file[30];
  int days = 0;
  int index = 0;
  int option;

  while(true){
    std::cout << std::endl
              << "\t*** User Input Menu ***" << std::endl
              << "\t{1} Enter the input file name" << std::endl
              << "\t{2} Print out all the car data" << std::endl
              << "\t{3} Print car data to outpout file" << std::endl
              << "\t{4} Sort cars by ascending price" << std::endl
              << "\t{5} Show available cars for amount of days to rent" << std::endl
              << "\t{6} Select the car you would like to rent" << std::endl
              << "\t{7} Exit the program" << std::endl
              << "\n\tPlease enter a menu option: ";
              std::cin >> option;

    switch(option){
      default:
        std::cout << "\nPlease input a valid menu option" << std::endl;
        break;

      case 1: // menu option 1
        readCars(list_of_cars);
        break;

      case 2: // menu option 2
        printCarsToTerminal(list_of_cars);
        break;

      case 3: // menu option 3
        printCarsToFile(output_file, list_of_cars);
        break;

      case 4: // menu option 4
        sortCarsByPrice(list_of_cars);
        break;

      case 5: // menu option 5
        rentalCarQuery(list_of_cars, days);
        break;

      case 6: // menu option 6
        rentalCarReserve(list_of_cars, days, index);
        break;

      case 7: // menu option 7
        std::cout << "\nYou are now exiting the program!\n" << std::endl;
        return;
        break;
    }
  }
}

// (1) - reads data from file
void readCars(RentalCar list_of_cars []){
  char input_file[30];

  std::cout << "\nEnter the input file name: ";
  std::cin >> input_file;

  std::ifstream FILE (input_file);

  if(FILE.is_open()){
    for(int i=0; i<CARS && !FILE.eof(); i++){
      FILE >> list_of_cars[i].year;
      FILE >> list_of_cars[i].make;
      FILE >> list_of_cars[i].model;
      FILE >> list_of_cars[i].price;
      FILE >> list_of_cars[i].available;
    }
  }
  else{
    std::cout << "\nFile could not be opened" << std::endl;
    return;
  }

  FILE.close();
}

// (2) - helper fcn for menu option 2
void sendCarInfo(std::ostream& out, RentalCar list_of_cars []){
  int index_number = 0;

  for(int i=0; i<CARS; i++, index_number++){
    out << "[" << i << "]:" << ' '
        << list_of_cars[i].year << ' '
        << list_of_cars[i].make << ' '
        << list_of_cars[i].model << ',' << ' '
        << "$" << list_of_cars[i].price << ' ' << "per day" << ", "
        << "Available: "  << std::boolalpha << list_of_cars[i].available << std::endl;
  }
}

// (2) - fcn for menu option 2
void printCarsToTerminal(RentalCar list_of_cars []){
  std::cout << std::endl;
  sendCarInfo(std::cout, list_of_cars);
}

// (3) - helper fcn for menu option 3, sends info without index
void sendCarInfoToFile(std::ostream& out, RentalCar list_of_cars []){
  int index_number = 0;

  for(int i=0; i<CARS; i++, index_number++){
    out /* << "[" << i << "]:" << ' ' */
        << list_of_cars[i].year << ' '
        << list_of_cars[i].make << ' '
        << list_of_cars[i].model << ',' << ' '
        << "$" << list_of_cars[i].price << ' ' << "per day" << ", "
        << "Available: " << std::boolalpha << list_of_cars[i].available << std::endl;
  }
}

// (3) - prints cars to output file
void printCarsToFile(char file_name [], RentalCar list_of_cars []){
  char output_file[30];
  std::ofstream FILE;

  std::cout << "\nEnter the output file name: ";
  std::cin >> output_file; // was output_file (WORKS)

  FILE.open(file_name, std::fstream::out);

  sendCarInfoToFile(FILE, list_of_cars);

  FILE.close();
}

// (4) -
void mySwap(RentalCar * swap1, RentalCar * swap2){
  RentalCar temp = *swap1;
  *swap1 = *swap2;
  *swap2 = temp;
}

// DONE (4)
void sortCarsByPrice(RentalCar list_of_cars []){
  std::cout << "\nThe cars have been sorted by ascending price.\n";

  bool condition = false;
  do{
    condition = false;

    for(int i=0; i<CARS-1; i++){
      if(list_of_cars[i].price > list_of_cars[i+1].price){
        mySwap(&list_of_cars[i], &list_of_cars[i+1]);
        condition = true;
      }
    }
  } while(condition);
}

// DONE (5)
void rentalCarQuery(RentalCar list_of_cars [], int days){
  std::cout << "\nHow many days do you want to rent the car for: ";
  std::cin >> days;
  std::cout << std::endl;

  // printing cars from struct
  for(int i=0; i<CARS; i++){
    if(list_of_cars[i].available == true){
      std::cout << "[" << i << "]:" << ' '
                << list_of_cars[i].year << ' '
                << list_of_cars[i].make << ' '
                << list_of_cars[i].model << ", "
                << "Total Cost: $" << list_of_cars[i].price * days
                << std::endl;
    }
  }
}

// DONE (6)
void rentalCarReserve(RentalCar list_of_cars [], int days, int index){
  std::cout << "\nWhich car would you like to rent (by index): ";
  std::cin >> index;
  std::cout << "How many days would you like to rent the car for: ";
  std::cin >> days;

  // rental of available car
  if(list_of_cars[index].available == true){
    std::cout << "\nThe car has been rented.\n"
              << "Total Cost: $" << list_of_cars[index].price * days
              << std::endl;
    // making the car unavailable bc it has been rented
    list_of_cars[index].available = false;
  }

  else if(list_of_cars[index].available == false){
    std::cout << "\nWarning! This car is not currently available or the input was invalid.\n";

    rentalCarReserve(list_of_cars, days, index);
  }
}
