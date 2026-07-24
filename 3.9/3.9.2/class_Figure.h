#pragma once
#include <string>
#include <iostream>

class Figure
{
protected:
	std::string name;
	Figure(std::string name);
public:
	void get_name();
	virtual void get_sides();
	virtual void get_angles();
};