#include "../headers/Flying_carpet.h"

Flying_carpet::Flying_carpet(double distance) : Air_vehicle(10, "Ковёр-самолёт", distance)
{
	if (distance < 1000) this->koef = 1.0;
	if (distance < 5000 && distance >= 1000) this->koef = 0.97;
	if (distance < 10000 && distance >= 5000) this->koef = 0.9;
	if (distance >= 10000) this->koef = 0.95;
}
double Flying_carpet::get_time()
{
	return distance * koef / speed;
}
