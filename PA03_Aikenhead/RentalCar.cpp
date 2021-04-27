/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 3                 *
 * Rental Car CPP File       *
 * Due Feb 6th, 2020         *
 * * * * * * * * * * * * * * */

#include "RentalCar.h"
#include "my_string.h"

// default ctor
RentalCar::RentalCar(){
  RentalCar::setYear(0);
  RentalCar::setPrice(0.0);
  RentalCar::setAvailable(0);
}

// param ctor
RentalCar::RentalCar(int year, char * make, char * model, float price, bool available){
  RentalCar::setYear(year);
  RentalCar::setMake(make);
  RentalCar::setModel(model);
  RentalCar::setPrice(price);
  RentalCar::setAvailable(available);
}

// get methods
int RentalCar::getYear() const{
  return m_year;
}

char * RentalCar::getMake(){
  return m_make;
}

char * RentalCar::getModel(){
  return m_model;
}

float RentalCar::getPrice() const{
  return m_price;
}

bool RentalCar::getAvailable() const{
  return m_available;
}

// set methods
void RentalCar::setYear(int year){
  m_year = year;
}

void RentalCar::setMake(char * make){
  myStringCopy(m_make, make);
}

void RentalCar::setModel(char * model){
  myStringCopy(m_model, model);
}

void RentalCar::setPrice(float price){
  m_price = price;
}

void RentalCar::setAvailable(bool available){
  m_available = available;
}

// print fcn
void RentalCar::print() const{
  std::cout << m_year << ' '
            << m_make << ' '
            << m_model << ", $"
            << m_price << " per day, "
            << "Available: " << std::boolalpha << m_available
            << std::endl;
}

// estimate cost fnc
float RentalCar::estimateCost(const int days){
  return m_price * days;
}
