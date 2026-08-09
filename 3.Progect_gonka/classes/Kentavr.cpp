#include "../headers/Kentavr.h"

Kentavr::Kentavr(double distance) : Ground_vehicle(8, 2, 15, "Кентавр", distance)
{
}
double Kentavr::get_time()
{
	int N_rest = static_cast<int>(distance / (speed * time_to_rest));
	double time = distance / speed;
	for (int i = 1; i <= N_rest; ++i)
	{
		time += time_rest;
	}
	return time;
}
