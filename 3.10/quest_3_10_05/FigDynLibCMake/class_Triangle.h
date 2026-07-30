#pragma once
#include "class_Figure.h"

class Triangle : public Figure
{
protected:
	int a, b, c, A, B, C;
public:
	Triangle(int a, int b, int c, int A, int B, int C, std::string name = "Треугольник");
	void get_sides() override;
	void get_angles() override;
};