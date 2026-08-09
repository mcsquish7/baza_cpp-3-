#include "../headers/Broom.h"

Broom::Broom(double distance) : Air_vehicle(20, "Метла", distance)
{
	this->koef = 1.0 - (distance >= 100000.0 ? 1.0 : static_cast<int>(distance / 1000)/100.0);
}
double Broom::get_time()
{
	return distance * koef / speed;
}
