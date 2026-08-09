#pragma once
#include "../headers/Vehicle.h"

class Air_vehicle : public Vehicle
{
protected:
	Air_vehicle(int speed, std::string name, double distance);
};