/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 4                 *
 * Car Header File           *
 * * * * * * * * * * * * * * */

#ifndef CAR_H_
#define CAR_H_

#include "Sensor.h"

class Car{
	private:
		char m_make[SIZE];
		char m_model[SIZE];
		int m_year;
		Sensor m_sensors[SENSORS];
		float m_baseprice;
		float m_finalprice;
		bool m_available;
		char m_owner[SIZE];
		int sensor_data; // my own variable to keep track of sensors

	public:
		// default ctor
		Car();

		// param ctor
		Car(char * make, char * model, int year, float baseprice, Sensor * sensors, bool available);

		// copy ctor
		Car(const Car & obj);

		// get methods
		char * getMake();
		char * getModel();
		int getYear();
		Sensor * getSensors();
		float getBasePrice();
		float getFinalPrice();
		bool getAvailable();
		char * getOwner();

		// set methods
		void setMake(const char * make);
		void setModel(const char * model);
		void setYear(const int year);
		void setBasePrice(float baseprice);
		void setAvailable(bool available);
		void setOwner(const char * owner);
		//void setSensor(Sensor * sensors);

		// update price
		void updatePrice();

		// print
		void print();

		// estimate cost
		float estimateCost(const int days);

		// operator overload - adding a sensor
		Car & operator+(Sensor & sens);

		// add lessee
		Car & operator+(const char * lessee);
};

#endif//CAR_H_
