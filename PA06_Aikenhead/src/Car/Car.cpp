/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 6                 *
 * Car Source File           *
 * Due March 12th, 2020      *
 * * * * * * * * * * * * * * */
#include <iostream>
#include <Car/Car.h>
#include <Vehicle/Vehicle.h>

// default ctor
Car::Car()
  : m_throttle( 0 ) {

    // debug output
    std::cout << "Car: Default-ctor" << std::endl;
}

// param ctor
Car::Car(const float * lla)
  : Vehicle( lla ), m_throttle( 0 ) {

    // debug output
    std::cout << "Car: Parametrized-ctor" << std::endl;
}

// copy ctor
Car::Car(const Car & other)
  : Vehicle( other ), m_throttle( other.m_throttle ) {

    // debug output
    std::cout << "Car: Copy-ctor" << std::endl;
}

// virtual dtor
Car::~Car(){

  // debug output
  std::cout << "Car: Dtor" << std::endl;
}

// assign op
void Car::operator=(const Car & rhs){
  this -> SetLLA(rhs.getLLA());
  this -> setThrottle(rhs.getThrottle());

  // debug output
  std::cout << "Car: Assignment" << std::endl;
}

// get/set method
const int Car::getThrottle() const{ return m_throttle; }

void Car::setThrottle(const int throttle){ m_throttle = throttle; }

// drive method
void Car::drive(const int value){
  this -> setThrottle(value);
}

// virt move method
void Car::Move(const float * lla){
  this -> drive(75);
  this -> SetLLA(lla);

  // debug output
  std::cout << "Car: DRIVE to destination, with throttle @ 75" << std::endl;
}

// serialize car fcn
void Car::serialize(std::ostream & os) const{
  const float *ptr = this -> getLLA();

  os << "Car: Throttle: " << this->getThrottle()
     << " @ [" << *ptr << ", ";
  ptr++;

  os << *ptr << ", ";
  ptr++;

  os << *ptr << "]";
}
