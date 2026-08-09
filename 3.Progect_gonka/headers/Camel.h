#pragma once
#include "../headers/Ground_vehicle.h"

class Camel : public Ground_vehicle
{
private:
	double time_rest_1;

public:	
	Camel(double distance);
	double get_time() override;
};