#pragma once
#include "../headers/Ground_vehicle.h"

class Kentavr : public Ground_vehicle
{
public:	
	Kentavr(double distance);
	double get_time() override;
};