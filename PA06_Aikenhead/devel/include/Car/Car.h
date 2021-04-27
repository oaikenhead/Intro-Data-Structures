/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 6                 *
 * Car Header File           *
 * Due March 12th, 2020      *
 * * * * * * * * * * * * * * */
#ifndef CAR_H_
#define CAR_H_

#include <Vehicle/Vehicle.h>

class Car : public Vehicle {
  private:
    int m_throttle;

    // virt serialize fcn
    virtual void serialize(std::ostream & os) const override;

  public:
    // default ctor
    Car();

    // param ctor
    Car(const float * lla);

    // copy ctor
    Car(const Car & other);

    // virtual dtor
    virtual ~Car();

    // assign op
    void operator=(const Car & rhs);

    // get/set methods
    const int getThrottle() const;
    void setThrottle(const int throttle);

    // drive method
    void drive(const int value);

    // virtual move (override)
    virtual void Move(const float * lla) override;

};

#endif//CAR_H_
