// vehicle source file

#include <Vehicle/Vehicle.h>

// static variable intialization
int Vehicle::s_idgen = 1;

// default ctor
Vehicle::Vehicle()
  : m_vin( s_idgen ){
    // setting default parameters 
    m_lla[0] = 0;
    m_lla[1] = 0;
    m_lla[2] = 0;

    // debug output
    std::cout << "Vehicle #"
              << this -> getVin()
              << ": Default Ctor"
              << std::endl;
    s_idgen++;
}

// param ctor
Vehicle::Vehicle(const int vin, const float * lla)
  : m_vin(vin > s_idgen ? vin : s_idgen){
    setLLA(lla);

    std::cout << "Vehicle #"
              << this -> getVin()
              << ": Parametrized-ctor"
              << std::endl;
    s_idgen++;
}

// copy Ctor
Vehicle::Vehicle(const Vehicle & other)
  : m_vin(s_idgen){
  setLLA(other.m_lla);
  std::cout << "Vehicle #" << this -> getVin()
            << ": Copy-ctor" << std::endl;
}

// dtor
Vehicle::~Vehicle(){
  // debug output
  std::cout << "Vehicle #" << this -> getVin()
            << ": Dtor" << std::endl;
}

// assign op =
Vehicle & Vehicle::operator=(const Vehicle & rhs){
  this -> setLLA(rhs.getLLA());

  std::cout << "Vehicle #" << this -> getVin()
            << ": Assignment" << std::endl;
}

// get methods
const float * Vehicle::getLLA() const{ return this -> m_lla; }

const int Vehicle::getVin() const{ return this -> m_vin; }

const int Vehicle::getIdgen(){ return s_idgen; }

// set methods
void Vehicle::setLLA(const float * lla){
  m_lla[0] = lla[0];
  m_lla[1] = lla[1];
  m_lla[2] = lla[2];
}

// move method
void Vehicle::move(const float * lla){
  std::cout << "Vehicle #" << this -> getVin()
            << ": CAN’T MOVE - I DON'T KNOW HOW" << std::endl;
}

// insertion op overload
std::ostream & operator<<(std::ostream & os, const Vehicle & vehicle){
  const float * pos = vehicle.getLLA();

  os << "Vehicle #" << vehicle.getVin() << " @ ["
     << pos[0] << ", " << pos[1] << ", " << pos[2] << "]";

  return os;
}
