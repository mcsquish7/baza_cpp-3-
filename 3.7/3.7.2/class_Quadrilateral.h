#pragma once
#include "class_Figure.h"

class Quadrilateral : public Figure
{
protected:
	int a, b, c, d, A, B, C, D;
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, std::string name = "Черытёхугольник создан");

	void get_sides() override;
	void get_angles() override;
};
