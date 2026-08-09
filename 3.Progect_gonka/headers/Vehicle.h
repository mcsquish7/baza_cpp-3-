#pragma once
#include <string>

class Vehicle
{
protected:
	int speed;
	std::string name;
	double distance;
	Vehicle(int speed, std::string name, double distance);
public:
	std::string get_name();
	virtual double get_time();
};