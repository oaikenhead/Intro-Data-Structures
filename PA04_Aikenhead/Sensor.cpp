/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 4                 *
 * Sensor Source File        *
 * * * * * * * * * * * * * * */

#include "Sensor.h"

int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

// default ctor
Sensor::Sensor(){
	setType('\0');
	setExtraCost(0);
}

// param ctor
Sensor::Sensor(char * type){
	myStringCopy(m_type, type);
	setExtraCost(0);
}

// copy
Sensor & Sensor::operator=(const Sensor & other){
	if(this != &other){
		myStringCopy(m_type, other.m_type);
		m_extracost = other.m_extracost;
	}
	return *this;
}

// get fcn defs
char * Sensor::getType(){
	return m_type;
}

float Sensor::getExtraCost(){
	return m_extracost;
}

int Sensor::getGps(){
	return gps_cnt;
}

int Sensor::getCamera(){
	return camera_cnt;
}

int Sensor::getLidar(){
	return lidar_cnt;
}

int Sensor::getRadar(){
	return radar_cnt;
}

// set fcn defs
void Sensor::setType(char * type){
	myStringCopy(m_type, type);

	if(myStringCompare(m_type, "gps") == 0){
		gps_cnt++;
	}
	else if(myStringCompare(m_type, "camera") == 0){
		camera_cnt++;
	}
	else if(myStringCompare(m_type, "lidar") == 0){
		lidar_cnt++;
	}
	else if(myStringCompare(m_type, "radar") == 0){
		radar_cnt++;
	}
}

void Sensor::setExtraCost(float extracost){
	if(myStringCompare(m_type, "gps") == 0){
		m_extracost = 5.0;
	}
	else if(myStringCompare(m_type, "camera") == 0){
		m_extracost = 10.0;
	}
	else if(myStringCompare(m_type, "lidar") == 0){
		m_extracost = 15.0;
	}
	else if(myStringCompare(m_type, "radar") == 0){
		m_extracost = 20.0;
	}
	else if(myStringCompare(m_type, "none") == 0){
		m_extracost = 0.0;
	}
}

void Sensor::resetGps(){
	gps_cnt = 0;
}

void Sensor::resetCamera(){
	camera_cnt = 0;
}

void Sensor::resetLidar(){
	lidar_cnt = 0;
}

void Sensor::resetRadar(){
	radar_cnt = 0;
}

// operator overload
bool Sensor::operator==(const Sensor & ref) const{
	return(myStringCompare(ref.m_type, m_type)) && (ref.m_extracost == m_extracost);
}
