#pragma once
#ifdef FIGUREDYNLIB_EXPORTS
#define FIGURELIB_API __declspec(dllexport)
#else
#define FIGURELIB_API __declspec(dllimport)
#endif
#include "class_Quadrilateral.h"

class Romb : public Quadrilateral
{
public:
	FIGURELIB_API Romb(int a, int A, int B);
};