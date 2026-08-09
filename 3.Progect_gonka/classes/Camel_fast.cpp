#include "../headers/Camel_fast.h"

Camel_fast::Camel_fast(double distance) : Ground_vehicle(10, 8, 40, "Верблюд-быстроход", distance)
{
	this->time_rest_1 = 5;
	this->time_rest_2 = 6.5;
}
double Camel_fast::get_time()
{
	int N_rest = static_cast<int>(distance / (speed * time_to_rest));
	double time = distance / speed;
	for (int i = 1; i <= N_rest; ++i)
	{
		if (i == 1) time += time_rest_1;
		else if (i == 2) time += time_rest_2;
		else time += time_rest;
	}
	return time;
}
