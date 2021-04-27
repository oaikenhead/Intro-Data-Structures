/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 6                 *
 * Vehicle Header File       *
 * Due March 12th, 2020      *
 * * * * * * * * * * * * * * */
#ifndef VEHICLE_H_
#define VEHICLE_H_

const int COORD = 3;

class Vehicle{
  protected:
    float m_lla[COORD];

  private:
    // virtual serialize method
    virtual void serialize(std::ostream & os) const;

  public:
    // default ctor
    Vehicle();

    // param ctor
    Vehicle(const float * lla);

    // copy ctor
    Vehicle(const Vehicle & other);

    // virtual dtor
    virtual ~Vehicle();

    // assign op
    void operator=(const Vehicle & rhs);

    // get/set methods
    const float * getLLA() const;
    void SetLLA(const float * lla);

    // pure virtual move method
    virtual void Move(const float * lla) = 0;

    // insertion operator
    friend std::ostream & operator<<(std::ostream & os, const Vehicle & vehicle);

};

#endif//VEHICLE_H_
