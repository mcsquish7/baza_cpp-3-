#pragma once
#include "../headers/Vehicle.h"

class Ground_vehicle : public Vehicle  
{
protected:
	double time_to_rest;
	double time_rest;
	Ground_vehicle(double time_to_rest, double time_rest, int speed, std::string name, double distance);
};