#include "class_Quadrilateral.h"

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, std::string name) : Figure(name)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
}
void Quadrilateral::get_sides()
{
	std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n';
}
void Quadrilateral::get_angles()
{
	std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
}