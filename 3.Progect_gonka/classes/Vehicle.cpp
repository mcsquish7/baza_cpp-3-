#include "../headers/Vehicle.h"

Vehicle::Vehicle(int speed, std::string name, double distance) 
{ 
	this->speed = speed; 
	this->name = name; 
	this->distance = distance;
}
std::string Vehicle::get_name() { return name; }
double Vehicle::get_time() { return 0; }