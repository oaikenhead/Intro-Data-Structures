/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 4                 *
 * Agency Source File        *
 * * * * * * * * * * * * * * */

#include <fstream>
#include "Agency.h"

Agency::Agency(){
	myStringCopy(m_name, "Null");
	m_zipcode = 0;
}

// get fcns
char * Agency::getName(){
	return m_name;
}

int Agency::getZipcode(){
	return m_zipcode;
}


// set fcns
void Agency::setName(char * name){
	myStringCopy(m_name, name);
}

void Agency::setZipcode(int zipcode){
	m_zipcode = zipcode;
}

// operator []
Car & Agency::operator[](int var){
	return m_inventory[var];
}

// read all data
void Agency::readAllData(char file[]){
	std::ifstream FILE;
	int year;
	float baseprice;
	bool available;
	char make[SIZE], model[SIZE], sensor[SIZE], lessee[SIZE];

	FILE.open(file, std::ios::in);

	FILE >> m_name;
	FILE >> m_zipcode;

	Car * car = m_inventory;

	for(int i=0; i<INV && !FILE.eof(); i++){
		FILE >> year;
		car->setYear(year);
		FILE >> make;
		car->setMake(make);
		FILE >> model;
		car->setModel(model);
		FILE >> baseprice;
		car->setBasePrice(baseprice);

		// setting the sensor
		FILE >> sensor;
		char * type = sensor + 1;
		while(true){
			char * ptr = type;
			while(*ptr != '}' && *ptr != '\0'){
				ptr++;
			}
			if(*ptr == '}'){
				if(ptr == type){
					break;
				}
				*ptr = '\0';
				Sensor arr(type);
				*car = *car + arr;
				break;
			}
			else{
				Sensor arr(type);
				*car = *car +arr;
				FILE >> sensor;
				type = sensor;
			}
		}

		// setting available
		FILE >> available;
		if(!available){
			FILE >> lessee;
			car->setOwner(lessee);
		}
		car->setAvailable(available);
		car++;
	}
	FILE.close();
}

// print active sensors
/*void Agency::printActiveSensors(){}*/

// print data
void Agency::printData(){
	std::cout << m_name << ' '
						<< m_zipcode << ' '
						<< std::endl;
	Car * car = m_inventory;
	for(int i=0; i<INV; i++){
		car->print();
		car++;
	}
}

// print all cars
/*void Agency::printAllCars(){}*/

// print available cars
void Agency::printAvailableCars(){
	std::cout << m_name << std::endl;

	Car * car = m_inventory;

	for(int i=0; i<INV; i++){
		if(car -> getAvailable()){
			car -> print();
		}
		car++;
	}
}
