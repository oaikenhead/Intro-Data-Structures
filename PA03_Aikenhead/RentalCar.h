/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 3                 *
 * Rental Car Header File    *
 * Due Feb 6th, 2020         *
 * * * * * * * * * * * * * * */

#ifndef RENTALCAR_H_
#define RENTALCAR_H_

const int SIZE = 256;
const int CAR_INV = 5;
const int ZIP = 5;
const int AGENCIES = 3;

class RentalCar{
  public:
    // default ctor
    RentalCar();

    // param ctor
    RentalCar(int year, char * make, char * model, float price, bool available);

    // get methods
    int getYear() const;
    char * getMake();
    char * getModel();
    float getPrice() const;
    bool getAvailable() const;

    // set methods
    void setYear(int year);
    void setMake(char * make);
    void setModel(char * model);
    void setPrice(float price);
    void setAvailable(bool available);

    // print fcn
    void print() const;

    // estimate cost fcn
    float estimateCost(const int days);

  private:
    int m_year;
    char m_make[SIZE];
    char m_model[SIZE];
    float m_price;
    bool m_available;
};

#endif//RENTALCAR_H_
