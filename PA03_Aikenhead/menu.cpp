/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 3                 *
 * Menu CPP File             *
 * Due Feb 6th, 2020         *
 * * * * * * * * * * * * * * */

#include <iostream>
#include <fstream>
#include "menu.h"

// the user menu
void userMenuPrompt(){
  RentalAgency agency_list[AGENCIES];
  int option;

  while(true){
    std::cout << std::endl
              << "\t*** USER INPUT MENU ***\n"
              << "\t{1} Enter the input file name\n"
              << "\t{2} Display all Agency Car data\n"
              << "\t{3} Estimate the Car rental cost\n"
              << "\t{4} Find the cheapest available Car\n"
              << "\t{5} Reserve a Car\n"
              << "\t{6} Exit the program\n"
              << "\n\tPlease enter a menu option: ";
    std::cin >> option;

    switch(option){
      default:
        std::cout << "\nPlease input a valid menu option\n";
        break;

      case 1: // menu option 1
        readCars(agency_list);
        break;

      case 2: // menu option 2
        printAgenciesToTerminal(agency_list);
        break;

      case 3: // menu option 3
        estimateRentalCost(agency_list);
        break;

      case 4: // menu option 4
        findCheapestRental(agency_list);
        break;

      case 5: // menu option 5
        reserveCar(agency_list);
        break;

      case 6: // menu option 6
        std::cout << "\nYou are now exiting the program." << std::endl;
        return;
        break;

    }
  }
}

// menu option 1 fcn
void readCars(RentalAgency * agency_list){
  // file variables
  char input_file[SIZE];
  std::ifstream FILE;

  // class & struct variables
  int year;
  char make[SIZE];
  char model[SIZE];
  int zip;
  float price;
  bool available;

  // getting the file to open and read contents
  std::cout << "\nEnter an input file name: ";
  std::cin >> input_file;

  FILE.open(input_file, std::fstream::in);

  if(FILE.is_open()){
    for(int i=0; i<AGENCIES && !FILE.eof(); i++){
      FILE >> agency_list -> name;
      FILE >> zip;

      // storing the zip
      int * temp = agency_list -> zipcode;

      // getting the correct zip
      for(int j=ZIP-1; j>=0; j--){
        *(temp + j) = zip % 10;
        zip /= 10;
      }

      RentalCar * car = agency_list -> inventory;

      for(int k=0; k<CAR_INV && !FILE.eof(); k++){
        FILE >> year;
        car -> setYear(year);
        FILE >> make;
        car -> setMake(make);
        FILE >> model;
        car -> setModel(model);
        FILE >> price;
        car -> setPrice(price);
        FILE >> available;
        car -> setAvailable(available);

        car++;
      }
      agency_list++;
    }
  }

  // closing the file
  FILE.close();
}

// helper fcn for print agencies
void sendAgencyData(RentalAgency * agency_list){
  int * arrPtr = agency_list -> zipcode;
  RentalCar * invPtr = agency_list -> inventory;

  std::cout << agency_list -> name << ' ';

  for(int i=0; i<ZIP; i++){
    std::cout << *arrPtr++;
  }
  std::cout << std::endl;

  //printing the inventory
  for(int j=0; j<CAR_INV; j++){
    invPtr -> print();
    invPtr++;
  }
}

// menu option 2 fcn
void printAgenciesToTerminal(RentalAgency * agency_list){
  std::cout << std::endl;

  for(int i=0; i<AGENCIES; i++){
    sendAgencyData(agency_list++);
  }
}

// menu option 3 fcn
void estimateRentalCost(RentalAgency * agency_list){
  int agency_index, vehicle_index, days;

  // getting specific car from user
  std::cout << "Which agency would you like to rent from? (0-2): ";
  std::cin >> agency_index;
  std::cout << "Select a vehicle to rent (0-4): ";
  std::cin >> vehicle_index;
  std::cout << "How many days would you like to rent the car for?: ";
  std::cin >> days;

  // getting the cost of specific car
  if(agency_index < AGENCIES && agency_index >= 0 && days > 0){
    RentalCar * car = (agency_list + agency_index) -> inventory;
    std::cout << "\nTotal Cost: $" << (car + vehicle_index) -> estimateCost(days) << std::endl;
  }
  else{
    std::cout << "\nPlease enter valid input values.\n";
  }
}

// menu option 4 fcn
void findCheapestRental(RentalAgency * agency_list){
  RentalCar * car = NULL;
  RentalAgency * move = agency_list;

  // looking through the cars
  for(int i=0; i<AGENCIES; i++){
    RentalCar * current_car = move -> inventory;

    for(int j=0; j<CAR_INV; j++){
      if(car==NULL || current_car->getPrice() < car->getPrice()){
        car = current_car;
      }
      current_car++;
    }
    move++;
  }

  // displays the text for least expensive car
  std::cout << "\nThe least expensive car is the "
            << car->getYear() << ' '
            << car->getMake() << ' '
            << car->getModel() << ", $"
            << car->getPrice() << ' ' << std::endl;
}

// menu option 5 fcn
void reserveCar(RentalAgency * agency_list){
  int agency_index, vehicle_index;

  // gets the parameters for the car
  std::cout << "\nWhich agency would you like to rent from? (0-2): ";
  std::cin >> agency_index;
  std::cout << "\nSelect a vehicle to rent (0-4): ";
  std::cin >> vehicle_index;

  // finds the car and changes its availability to false
  if(agency_index < AGENCIES && agency_index >= 0){
    RentalCar * car = (agency_list + agency_index) -> inventory;
    car -> setAvailable(false);
  }
  // warning message for non available cars
  else{
    std::cout << "Warning, this car is not available" << std::endl;

    // runs the menu option again
    reserveCar(agency_list);
  }
  printAgenciesToTerminal(agency_list);
}
