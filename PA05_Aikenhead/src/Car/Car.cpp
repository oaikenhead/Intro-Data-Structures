// car source file

#include <iostream>
#include <string.h>
#include <Vehicle/Vehicle.h>
#include <Car/Car.h>

// default ctor
Car::Car(){
  m_plates[0] = '\0';
  m_throttle = 0;

  // debug
  std::cout << "Car #" << m_vin << ": Default-ctor" << std::endl;
}

// param ctor
Car::Car(const char * plates, const int vin, const float * lla)
  : Vehicle(vin, lla){

    strcpy(m_plates, plates);
    m_throttle = 0;

    // debug
    std::cout << "Car #" << m_vin << ": Parametrized-ctor" << std::endl;
}

// copy ctor
Car::Car(const Car & other)
  : Vehicle(other){
    strcpy(m_plates, other.m_plates);

    // debug
    std::cout << "Car #" << m_vin << ": Copy-ctor" << std::endl;
}

// dtor
Car::~Car(){

  // debug
  std::cout << "Car #" << m_vin << ": Dtor" << std::endl;
}

// assign op
Car & Car::operator=(const Car & rhs){
  Vehicle::operator=(rhs);
  strcpy(m_plates, rhs.m_plates);
  m_throttle = rhs.m_throttle;

  // debug
  std::cout << "Car #" << m_vin << ": Assignment" << std::endl;
}

// get methods
const char * Car::getPlates() const{ return m_plates; }
const int Car::getThrottle() const{ return m_throttle; }

// set methods
void Car::setPlates(const char * plates){ strcpy(m_plates, plates); }
void Car::setThrottle(const int throttle){ m_throttle = throttle; }

// drive method
void Car::drive(const int throttle){ setThrottle(throttle); }

// move method overload
void Car::move(const float * lla){
  std::cout << "Car #" << m_vin << ": DRIVE to destination, with throttle @ 75" << std::endl;

  // setting drive and LLA to req variables
  this -> drive( 75 );
  this -> setLLA( lla );
}

// overload operator
std::ostream & operator<<(std::ostream & os, const Car & car){
  // variable for position
  const float * pos = car.getLLA();

  // terminal output
  os << "Car #" << car.getVin()
     << " Plates: " << car.getPlates()
     << ", Throttle: " << car.getThrottle()
     << " @ [" << pos[0] << ", " << pos[1] << ", " << pos[2] << "]";

  return os;
}
