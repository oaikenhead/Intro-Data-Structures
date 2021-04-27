/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 4                 *
 * Menu Source File          *
 * * * * * * * * * * * * * * */

#include <fstream>
#include "menu.h"

void userMenuPrompt(){
	Agency agency;
	int option;

	while(true){
		std::cout << "\t*** USER INPUT MENU ***" << std::endl
							<< "\t{1} Provide an input file name" << std::endl
							<< "\t{2} Display all Agency data with Cars" << std::endl
							<< "\t{3} Display all Agency data with available Cars only" << std::endl
							<< "\t{4} Reserve a Car and show updated list" << std::endl
							<< "\t{5} Exit the program" << std::endl
							<< "\n\tPlease enter a menu option: ";
		std::cin >> option;

		switch(option){
			default:
				std::cout << "\nInput a valid menu option\n" << std::endl;
				break;

			case 1: // menu option 1
				readIn(agency);
				break;

			case 2: // menu option 2
				printAll(agency);
				break;

			case 3: // menu option 3
				break;

			case 4: // menu option 4
				break;

			case 5: // menu option 5
				std::cout << "\nYou are now exiting the program" << std::endl;
				return;
				break;
		}
	}
}

void readIn(Agency agency){
	char file[SIZE];

	std::cout << "\nPlease enter an input file name: ";
	std::cin >> file;
	std::cout << std::endl;

	agency.readAllData(file);
}

void printAll(Agency agency){
	agency.printData();
}
