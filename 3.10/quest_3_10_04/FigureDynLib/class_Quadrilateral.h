#pragma once
#ifdef FIGUREDYNLIB_EXPORTS
#define FIGURELIB_API __declspec(dllexport)
#else
#define FIGURELIB_API __declspec(dllimport)
#endif
#include "class_Figure.h"

class Quadrilateral : public Figure
{
protected:
	int a, b, c, d, A, B, C, D;
public:
	FIGURELIB_API Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, std::string name = "Черытёхугольник");

	FIGURELIB_API void get_sides() override;
	FIGURELIB_API void get_angles() override;
};
