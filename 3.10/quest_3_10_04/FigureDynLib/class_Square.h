#pragma once
#ifdef FIGUREDYNLIB_EXPORTS
#define FIGURELIB_API __declspec(dllexport)
#else
#define FIGURELIB_API __declspec(dllimport)
#endif
#include "class_Quadrilateral.h"

class Square : public Quadrilateral
{
public:
	FIGURELIB_API Square(int a);
};