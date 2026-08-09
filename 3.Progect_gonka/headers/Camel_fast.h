#pragma once
#include "../headers/Ground_vehicle.h"

class Camel_fast : public Ground_vehicle
{
private:
	double time_rest_1;
	double time_rest_2;

public:	
	Camel_fast(double distance);
	double get_time() override;
};