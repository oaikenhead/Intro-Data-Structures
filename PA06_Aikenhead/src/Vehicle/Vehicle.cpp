/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 6                 *
 * Vehicle Source File       *
 * Due March 12th, 2020      *
 * * * * * * * * * * * * * * */
#include <iostream>
#include <cstring>
#include <Vehicle/Vehicle.h>

// default ctor
Vehicle::Vehicle(){
  // debug output
  std::cout << "Vehicle: Default-ctor" << std::endl;
}

// param ctor
Vehicle::Vehicle(const float * lla){
  this -> SetLLA(lla);

  // debug output
  std::cout << "Vehicle: Parametrized-ctor" << std::endl;
}

// copy ctor
Vehicle::Vehicle(const Vehicle & other){
  this -> SetLLA(other.getLLA());

  // debug output
  std::cout << "Vehicle: Copy-ctor" << std::endl;
}

// virtual dtor
Vehicle::~Vehicle(){
  // debug output
  std::cout << "Vehicle: Dtor" << std::endl;
}

// assign op
void Vehicle::operator=(const Vehicle & rhs){
  this -> SetLLA(rhs.getLLA());

  // debug output
  std::cout << "Vehicle: Assignment" << std::endl;
}

// get/set methods
const float * Vehicle::getLLA() const{
  return m_lla;
}

void Vehicle::SetLLA(const float * lla){
  m_lla[0] = lla[0];
  m_lla[1] = lla[1];
  m_lla[2] = lla[2];
}

// insertion operator
std::ostream & operator<<(std::ostream & os, const Vehicle & vehicle){
  vehicle.serialize(os);
  return os;
}

// virtual serialize
void Vehicle::serialize(std::ostream & os) const{
  const float *ptr = this -> getLLA();

  os << "Vehicle @ [" << *ptr << ", ";
  ptr++;

  os << *ptr << ", ";
  ptr++;

  os << *ptr << "]";
}
