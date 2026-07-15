#include <iostream>
#include <string>

using namespace std;

class Figure
{
protected:
	string name;
	Figure(string name) { this->name = name; }
public:
	void get_name() { cout << name << ":\n"; }
	virtual void get_sides() {}
	virtual void get_angles() {}
};

class Triangle : public Figure
{
protected:
	int a, b, c, A, B, C;
public:
	Triangle(int a, int b, int c, int A, int B, int C, string name = "Треугольник") : Figure(name)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}
	void get_sides() override
	{
		cout << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n';
	}
	void get_angles() override
	{
		cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
	}
};

class PR_triangle : public Triangle
{
public:
	PR_triangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C, "Прямоугольный треугольник")
	{
		if (C != 90)
		{
			throw invalid_argument("В прямоугольном треугольнике угол 'C' должен быть равен 90°");
		}
	}
};

class RB_triangle : public Triangle
{
public:
	RB_triangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C, "Равнобедренный треугольник")
	{
		if (a != c || A != C)
		{
			throw invalid_argument("В равнобедренном треугольнике угол 'A' должен быть равен углу 'C', а сторона 'a' стороне 'c'");
		} 
	}
};

class RS_triangle : public Triangle
{
public:
	RS_triangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C, "Равтосторонний треугольник")
	{
		if ((a != b && b != c) || (A != B && B != C && A!=60))
		{
			throw invalid_argument("В равностороннем треугольнике все стороны должны быть равны между собой, а углы должны быть все равны 60°");
		}
	}
};

class Quadrilateral : public Figure
{
protected:
	int a, b, c, d, A, B, C, D;
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, string name = "Черытёхугольник") : Figure(name)
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
	void get_sides() override
	{
		cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n';
	}
	void get_angles() override
	{
		cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
	}
};

class PR_q : public Quadrilateral
{
public:
	PR_q(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, c, d, A, B, C, D, "Прямоугольник")
	{
		if (!(a == c && b == d) || !(A == B && B == C && C == D && A==90))
		{
			throw invalid_argument("В прямоугольнике стороны 'a', 'c' и 'b', 'd' должны быть попарно равны, все углы должны быть по 90°");
		}
	}
};

class Square : public Quadrilateral
{
public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, c, d, A, B, C, D, "Квадрат")
	{
		if (!(a == b && b == c && c == d) || !(A == B && B == C && C == D && A == 90))
		{
			throw invalid_argument("В квадрате все стороны должны быть равны, все углы должны быть по 90°");
		}
	}
};

class Romb : public Quadrilateral
{
public:
	Romb(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, c, d, A, B, C, D, "Ромб")
	{
		if (!(a == b && b == c && c == d) || !(A == C && B == D))
		{
			throw invalid_argument("В ромбе все стороны должны быть равны, углы 'A', 'C' и 'B', 'D' должны быть попарно равны");
		}
	}
};

class Parallelogramm : public Quadrilateral
{
public:
	Parallelogramm(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, c, d, A, B, C, D, "Параллелограмм")
	{
		if (!(a == c && b == d) || !(A == C && B == D))
		{
			throw invalid_argument("В параллелограмме стороны 'a', 'c' и 'b', 'd' должны быть попарно равны, углы 'A', 'C' и 'B', 'D' должны быть попарно равны");
		}
	}
};


void print_info(Figure* fig)
{
	fig->get_name();
	fig->get_sides();
	fig->get_angles();
}

int main()
{	
	setlocale(LC_ALL, "Russian");
	try
	{
		Triangle tr(1, 2, 3, 1, 2, 3);
		PR_triangle pr_tr(1, 2, 3, 1, 2, 90);
		RB_triangle rb_tr(1, 2, 1, 1, 2, 1);
		RS_triangle rs_tr(1, 1, 1, 60, 60, 60);
		print_info(&tr);
		print_info(&pr_tr);
		print_info(&rb_tr);
		print_info(&rs_tr);

		Quadrilateral quad(1,2,3,4,1,2,3,4);
		PR_q pr_q(1,2,1,2,90,90,90,90);
		Square sq(1,1,1,1,90,90,90,90);
		Romb r(1,1,1,1,60,50,60,50);
		Parallelogramm paralm(1,2,1,2,60,50,60,50);
		print_info(&quad);
		print_info(&pr_q);
		print_info(&sq);
		print_info(&r);
		print_info(&paralm);

	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}

	return 0;
}