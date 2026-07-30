#pragma once
#ifdef FIGUREDYNLIB_EXPORTS
#define FIGURELIB_API __declspec(dllexport)
#else
#define FIGURELIB_API __declspec(dllimport)
#endif
#include <string>
#include <iostream>

class Figure
{
protected:
	std::string name;
	Figure(std::string name);
public:
	FIGURELIB_API void get_name();
	FIGURELIB_API virtual void get_sides();
	FIGURELIB_API virtual void get_angles();
};