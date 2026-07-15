#include <iostream>
#include <string>

using namespace std;

class Figure
{
private:
	int sides;
	string name;
protected:
	Figure(int sides, string name)
	{
		this->sides = sides;
		this->name = name;
	}
public:
	Figure()
	{
		sides = 0;
		name = "Фигура";
	}
	
	void get_sides_info()
	{
		cout << name << ": " << sides << '\n';
	}
};

class Triangle: public Figure
{
public:
	Triangle():Figure(3, "Треугольник")
	{}
};

class Quadrilateral : public Figure
{
public:
	Quadrilateral() :Figure(4, "Четырёхугольник")
	{}
};


int main()
{	
	setlocale(LC_ALL, "Russian");

	Figure fig;
	Triangle tr;
	Quadrilateral quadr;

	cout << "Количество сторон:\n";
	fig.get_sides_info();
	tr.get_sides_info();
	quadr.get_sides_info();

	return 0;
}