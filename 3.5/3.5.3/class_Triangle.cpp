#include "class_Triangle.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C, std::string name) : Figure(name)
{
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
