#include <iostream>
#include <string>

using namespace std;

class Figure
{
protected:
	string name;
	int sides;
public:
	Figure() { name = "Фигура"; sides = 0; }
	Figure(string name, int sides) { this->name = name; this->sides = sides; }
	void get_name() { cout << name << ":\n"; }
	virtual void check_correct() { cout << "Правильная\n"; }
	void get_num_sides() { cout << "Количество сторон: " << sides << '\n'; }
	virtual void get_len_sides() {}
	virtual void get_angles() { cout << '\n'; }
};

class Triangle : public Figure
{
protected:
	int a, b, c, A, B, C;
public:
	Triangle(int a, int b, int c, int A, int B, int C, string name = "Треугольник") : Figure(name, 3)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}
	void check_correct() override
	{
		cout << (((A + B + C) == 180 && (a>0 && b >0 && c>0 && A > 0 && B > 0 && C > 0)) ? "Правильная\n" : "Неправильная\n");
	}
	void get_len_sides() override
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
	PR_triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник") {}
};

class RB_triangle : public Triangle
{
public:
	RB_triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A, "Равнобедренный треугольник") {}
};

class RS_triangle : public Triangle
{
public:
	RS_triangle(int a, int A) : Triangle(a, a, a, 60, 60, 60, "Равтосторонний треугольник") {}
};

class Quadrilateral : public Figure
{
protected:
	int a, b, c, d, A, B, C, D;
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, string name = "Черытёхугольник") : Figure(name, 4)
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
	void check_correct() override
	{
		cout << (((A + B + C + D) == 360 && (a > 0 && b > 0 && c > 0 && d>0 && A > 0 && B > 0 && C > 0 && D>0)) ? "Правильная\n" : "Неправильная\n");
	}
	void get_len_sides() override
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
	PR_q(int a, int b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90, "Прямоугольник") {}
};

class Square : public Quadrilateral
{
public:
	Square(int a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90, "Квадрат") {}
};

class Romb : public Quadrilateral
{
public:
	Romb(int a, int A, int B) : Quadrilateral(a, a, a, a, A, B, A, B, "Ромб") {}
};

class Parallelogramm : public Quadrilateral
{
public:
	Parallelogramm(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B, "Параллелограмм") {}
};


void print_info(Figure* fig)
{
	fig->get_name();
	fig->check_correct();
	fig->get_num_sides();
	fig->get_len_sides();
	fig->get_angles();
}

int main()
{	
	setlocale(LC_ALL, "Russian");

	Figure fig;
	print_info(&fig);

	Triangle tr(1, 2, 3, 1, 2, 3);
	PR_triangle pr_tr(1, 2, 3, 1, 2);
	RB_triangle rb_tr(1, 2, 1, 2);
	RS_triangle rs_tr(1, 60);
	print_info(&tr);
	print_info(&pr_tr);
	print_info(&rb_tr);
	print_info(&rs_tr);

	Quadrilateral quad(1,2,3,4,1,2,3,4);
	PR_q pr_q(1,2);
	Square sq(1);
	Romb r(1,60,50);
	Parallelogramm paralm(1,2,60,50);
	print_info(&quad);
	print_info(&pr_q);
	print_info(&sq);
	print_info(&r);
	print_info(&paralm);


	return 0;
}