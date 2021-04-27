/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 3                 *
 * Menu Header File          *
 * Due Feb 6th, 2020         *
 * * * * * * * * * * * * * * */

#ifndef MENU_H_
#define MENU_H_

#include "Agency.h"

/* reiterates menu prompt
 * will terminate and then program terminates
 */
void userMenuPrompt();

/* menu option 1
 * reads in the car and agency data from a text file
 * asks user for input file name
 */
void readCars(RentalAgency * agency_list);

/* helper fcn for menu 2
 * sends the data to be printed to the terminal 
 */
void sendAgencyData(RentalAgency * agency_list);

/* menu option 2
 * displays the data for each agency to the screen
 */
void printAgenciesToTerminal(RentalAgency * agency_list);

/* menu option 3
 * asks user for index of agency, index for the car
 * and how many days they would like to rent for
 */
void estimateRentalCost(RentalAgency * agency_list);

/* menu option 4
 * finds the cheapest car for rent and displays it
 * to the screen
 */
void findCheapestRental(RentalAgency * agency_list);

/* menu option 5
 * reserves a car and refreshes the agency list to the screen
 */
void reserveCar(RentalAgency * agency_list);

#endif//MENU_H_
