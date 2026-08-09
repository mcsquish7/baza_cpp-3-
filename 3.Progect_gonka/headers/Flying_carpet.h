#pragma once
#include "../headers/Air_vehicle.h"

class Flying_carpet : public Air_vehicle
{
private:
	double koef;
public:	
	Flying_carpet(double distance);
	double get_time() override;
};