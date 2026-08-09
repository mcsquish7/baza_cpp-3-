#pragma once
#include "../headers/Ground_vehicle.h"

class Boots_rover : public Ground_vehicle
{
private:
	double time_rest_1;

public:	
	Boots_rover(double distance);
	double get_time() override;
};