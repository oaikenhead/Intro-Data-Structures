// Car header file

#ifndef CAR_H_
#define CAR_H_

#include <ostream>
#include <Vehicle/Vehicle.h>

const int SIZE = 256;

class Car : public Vehicle{
  private:
    char m_plates[SIZE];
    int m_throttle;

  public:
    // default ctor
    Car();

    // param ctor
    Car(const char * plates, const int vin, const float * lla);

    // copy ctor
    Car(const Car & other);

    // dtor
    ~Car();

    // assign op
    Car & operator=(const Car & rhs);

    // get methods
    const char * getPlates() const;
    const int getThrottle() const;

    // set methods
    void setPlates(const char * plates);
    void setThrottle(const int throttle);

    // drive method
    void drive(const int throttle);

    // move method overload
    void move(const float * lla);

    // overload operator
    friend std::ostream & operator<<(std::ostream & os, const Car & car);
};
#endif//CAR_H_
