/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 3                 *
 * * * * * * * * * * * * * * */

#include <iostream>
#include "RentalCar.h"
#include "Agency.h"
#include "menu.h"

int main(){

  // intial message for the start of the program
  std::cout << "\n\t============================================" << std::endl
            << "\t=== Car Agency Rental Assistance Program ===" << std::endl
            << "\t============================================"
            << std::endl;

  userMenuPrompt();

  return 0;
}
