#pragma once
#ifdef FIGUREDYNLIB_EXPORTS
#define FIGURELIB_API __declspec(dllexport)
#else
#define FIGURELIB_API __declspec(dllimport)
#endif
#include "class_Quadrilateral.h"

class PR_q : public Quadrilateral
{
public:
	FIGURELIB_API PR_q(int a, int b);
};