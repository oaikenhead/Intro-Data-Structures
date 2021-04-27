/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 4                 *
 * Agency Header File        *
 * * * * * * * * * * * * * * */

#ifndef AGENCY_H_
#define AGENCY_H_

#include "Car.h"

class Agency{
	private:
		char m_name[SIZE];
		int m_zipcode;
		Car m_inventory[INV];

	public:
		// ctor
		Agency();

		// get methods
		char * getName();
		int getZipcode();

		// set methods
		void setName(char * name);
		void setZipcode(int zipcode);
		void setInv(Car * inventory);

		// operator[]
		Car & operator[](int);

		// read all data
		void readAllData(char file[]);

		// print active sensors
		void printActiveSensors();

		// print data
		void printData();

		// print all cars
		void printAllCars();

		// print available cars
		void printAvailableCars();

};

#endif//AGENCY_H_
