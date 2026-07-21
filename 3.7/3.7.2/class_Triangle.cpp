#include "class_Triangle.h"
#include "fig_error_class.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C, std::string name) : Figure(name)
{	
	if (!((A + B + C) == 180))
	{
		throw fig_error("Ошибка создания фигуры. Причина: сумма углов не равна 180");
	}
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
}
void Triangle::get_sides()
{
	std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n';
}
void Triangle::get_angles() 
{
	std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
}
