// vehicle header file

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>
#include <ostream>

const int COOR = 3;

class Vehicle{
  protected:
    float m_lla[COOR];
    const int m_vin;

  private:
    static int s_idgen;

  public:
    // default ctor
    Vehicle();

    // param ctor
    Vehicle(const int vin, const float * lla);

    // copy ctor
    Vehicle(const Vehicle & other);

    // dtor
    ~Vehicle();

    // assign op =
    Vehicle & operator=(const Vehicle & rhs);

    // get methods
    const float * getLLA() const;
    const int getVin() const;
    static const int getIdgen();

    // set methods
    void setLLA(const float * lla);

    // a move method
    void move(const float * lla);

    // insertion overload operator
    friend std::ostream & operator<<(std::ostream& os, const Vehicle & vehicle);
};

#endif//VEHICLE_H_
