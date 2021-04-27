/* * * * * * * * * * * * * * * * * * * *
 * Olliver Aikenhead                   *
 * Project 2                           *
 * Due 2/5/2020                        *
 * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include "my_string.h"
#include "menu.h"

int main(){
  // message that displays at the beginning of the program
  std::cout << "\n\t*********************************" << std::endl
            << "\t* Car Rental Assistance Program *" << std::endl
            << "\t*********************************" << std::endl;

  // this function displays the user menu and reiterates it
  userMenuPrompt();

  return 0;
}
