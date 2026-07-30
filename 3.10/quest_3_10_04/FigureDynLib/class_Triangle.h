#pragma once
#ifdef FIGUREDYNLIB_EXPORTS
#define FIGURELIB_API __declspec(dllexport)
#else
#define FIGURELIB_API __declspec(dllimport)
#endif
#include "class_Figure.h"

class Triangle : public Figure
{
protected:
	int a, b, c, A, B, C;
public:
	FIGURELIB_API Triangle(int a, int b, int c, int A, int B, int C, std::string name = "Треугольник");
	FIGURELIB_API void get_sides() override;
	FIGURELIB_API void get_angles() override;
};