#include "../headers/Eagle.h"

Eagle::Eagle(double distance) : Air_vehicle(8, "Îğ¸ë", distance)
{
	this->koef = 0.94;
}
double Eagle::get_time()
{
	return distance * koef / speed;
}
