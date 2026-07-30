#pragma once
#ifdef FIGUREDYNLIB_EXPORTS
#define FIGURELIB_API __declspec(dllexport)
#else
#define FIGURELIB_API __declspec(dllimport)
#endif
#include "class_Triangle.h"

class RS_triangle : public Triangle
{
public:
	FIGURELIB_API RS_triangle(int a, int A);
};