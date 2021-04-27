/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 4                 *
 * Sensor Header File        *
 * * * * * * * * * * * * * * */

#ifndef SENSOR_H_
#define SENSOR_H_

#include "my_string.h"

const int SIZE = 256;
const int INV = 5;
const int SENSORS = 3;

class Sensor{
	private:
		char m_type[SIZE];
		float m_extracost;
		static int gps_cnt;
		static int camera_cnt;
		static int lidar_cnt;
		static int radar_cnt;

	public:
		// default ctor
		Sensor();

		// param ctor
		Sensor(char * type);

		// copy ctor
		Sensor & operator=(const Sensor & other);

		// get methods
		char * getType();
		float getExtraCost();
		static int getGps();
		static int getCamera();
		static int getLidar();
		static int getRadar();

		// set methods
		void setType(char * type); // was const
		void setExtraCost(float extracost);

		// reset static member fcn
		void resetGps();
		void resetCamera();
		void resetLidar();
		void resetRadar();

		// operator overload
		bool operator==(const Sensor & ref) const;
};

#endif//SENSOR_H_
