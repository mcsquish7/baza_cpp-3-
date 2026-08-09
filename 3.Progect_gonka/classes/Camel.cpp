#include "../headers/Camel.h"

Camel::Camel(double distance) : Ground_vehicle(30, 8, 10, "Верблюд", distance)
{
	this->time_rest_1 = 5;
}
double Camel::get_time()
{
	int N_rest = static_cast<int>(distance / (speed * time_to_rest));
	double time = distance / speed;
	for (int i = 1; i <= N_rest; ++i)
	{
		time += (i == 1 ? time_rest_1 : time_rest);
	}
	return time;
}
