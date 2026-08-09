#pragma once
#include "../headers/Air_vehicle.h"

class Eagle : public Air_vehicle
{
private:
	double koef;
public:	
	Eagle(double distance);
	double get_time() override;
};