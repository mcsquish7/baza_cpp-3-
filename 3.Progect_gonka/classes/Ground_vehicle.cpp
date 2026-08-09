#include "../headers/Ground_vehicle.h"

Ground_vehicle::Ground_vehicle(double time_to_rest, double time_rest, int speed, std::string name, double distance) : Vehicle(speed, name, distance)
{
	this->time_to_rest = time_to_rest;
	this->time_rest = time_rest;
}