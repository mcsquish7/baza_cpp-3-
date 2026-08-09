#pragma once
#include "../headers/Air_vehicle.h"

class Broom : public Air_vehicle
{
private:
	double koef;
public:	
	Broom(double distance);
	double get_time() override;
};