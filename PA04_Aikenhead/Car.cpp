/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 4                 *
 * Car Source File           *
 * * * * * * * * * * * * * * */

#include "Car.h"

// default ctor
Car::Car(){
	setMake("none");
	setModel("none");
	setYear(0);
	setBasePrice(0.00);
	setAvailable(0);

	sensor_data = 0;
}

// param ctor
Car::Car(char * make, char * model, int year, float baseprice, Sensor * sensors, bool available){
	setMake(make);
	setModel(model);
	setYear(year);
	setBasePrice(baseprice);
	setAvailable(available);
}

// copy ctor
Car::Car(const Car & obj){
	myStringCopy(m_make, obj.m_make);
	myStringCopy(m_model, obj.m_model);
	m_year = obj.m_year;
	//sensor_data = obj.sensor_data;
	m_baseprice = obj.m_baseprice;
	m_available = obj.m_available;
	myStringCopy(m_owner, obj.m_owner);
}

// get methods
char * Car::getMake(){
	return m_make;
}

char * Car::getModel(){
	return m_model;
}

int Car::getYear(){
	return m_year;
}

Sensor * Car::getSensors(){
	return m_sensors;
}

float Car::getBasePrice(){
	return m_baseprice;
}

float Car::getFinalPrice(){
	return m_finalprice;
}

bool Car::getAvailable(){
	return m_available;
}

char * Car::getOwner(){
	return m_owner;
}

// set methods
void Car::setMake(const char * make){
	myStringCopy(m_make, make);
}

void Car::setModel(const char * model){
	myStringCopy(m_model, model);
}

void Car::setYear(const int year){
	m_year = year;
}

void Car::setBasePrice(float baseprice){
	m_baseprice = baseprice;
}

void Car::setAvailable(bool available){
	m_available = available;
}

void Car::setOwner(const char * owner){
	myStringCopy(m_owner, owner);
}

/*void Car::setSensor(Sensor * sensor){
	for(int i=0; i<SENSORS; i++){
		m_sensors[i].setType(sensor->getType());
		m_sensors[i].setExtraCost();
		sensor++;
	}
}*/

// update price
void Car::updatePrice(){

}

// print
void Car::print(){
	std::cout << getYear() << ' '
						<< getMake() << ' '
						<< getModel() << ' '
						<< "Base: " << getBasePrice() << ' '
						<< "With {";

	Sensor * get = this -> getSensors();
	bool hasSensor = false;

	for(int i=0; i<SENSORS; i++){
		if(myStringCompare(get -> getType(), "none") != 0){
			std::cout << get->getType() << ' ';
			hasSensor = true;
		}
		get++;
	}

	if(!hasSensor){
		std::cout << "\t\t\t";
	}

	updatePrice();
	std::cout << "}:" << getFinalPrice() << ' '
						<< "Available: " << std::boolalpha << getAvailable() << std::endl;

}

// method to add a sensor
Car & Car::operator+(Sensor & sens){
	if(sensor_data > 2){
		return *this;
	}
	Sensor * part = m_sensors;

	for(int i=0; i<sensor_data; i++){
		part++;
	}

	sensor_data++;
	*part = sens;
	return *this;
}

Car & Car::operator+(const char * lessee){
	setOwner(lessee);
	//setAvailable(false);
	return *this;
}
