/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 3                 *
 * Agency Header File        *
 * Due Feb 6th, 2020         *
 * * * * * * * * * * * * * * */

#ifndef AGENCY_H_
#define AGENCY_H_

#include "RentalCar.h"

struct RentalAgency{
  char name[SIZE];
  int zipcode[ZIP];
  RentalCar inventory[CAR_INV];
};

#endif//AGENCY_H_
