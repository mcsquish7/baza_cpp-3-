#include "../headers/Boots_rover.h"

Boots_rover::Boots_rover(double distance) : Ground_vehicle(60, 5, 6, "Ботинки-вездеходы", distance)
{
	this->time_rest_1 = 10;
}
double Boots_rover::get_time()
{
	int N_rest = static_cast<int>(distance / (speed * time_to_rest));
	double time = distance / speed;
	for (int i = 1; i <= N_rest; ++i)
	{
		time += (i == 1 ? time_rest_1 : time_rest);
	}
	return time;
}
