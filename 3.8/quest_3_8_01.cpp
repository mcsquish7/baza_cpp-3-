#include <iostream>
#include <string>
#include <cassert>
#define MODE 4

using namespace std;

class Fraction
{
private:
	int up, down;
public:
	Fraction(int up, int down)
	{	
		if (down == 0)
		{
			throw invalid_argument("Знаменатель равен нулю. На ноль делить запрещено.");
		}
		this->up = up;
		this->down = down;
		NOD(this->up, this->down);
	}
	bool operator==(Fraction other)
	{
		return (up * other.down == other.up * down);
	}
	bool operator!=(Fraction other)
	{
		return (!(*this == other));
	}
	bool operator<(Fraction other)
	{
		return (up * other.down < other.up* down);
	}
	bool operator>(Fraction other)
	{
		return (up * other.down > other.up* down);
	}
	bool operator<=(Fraction other)
	{
		return (!(*this > other));
	}
	bool operator>=(Fraction other)
	{
		return (!(*this < other));
	}
	Fraction operator+(Fraction other)
	{
		return Fraction(up * other.down + other.up * down, down* other.down);
	}
	Fraction operator-(Fraction other)
	{
		return Fraction(up * other.down - other.up * down, down * other.down);
	}
	Fraction operator*(Fraction other)
	{
		// тут надо перед return привести к несокращаемой дроби
		Fraction temp(up * other.up, down * other.down);
		NOD(temp.up, temp.down);
		return temp;
	}
	Fraction operator/(Fraction other)
	{	
		if (other.up == 0)
		{
			throw invalid_argument("Числитель второй дроби равен нулю. Деление на эту дробь запрещено.");
		}
		// тут надо перед return привести к несокращаемой дроби
		Fraction temp(up * other.down, down * other.up);
		NOD(temp.up, temp.down);
		return temp;
	}
	Fraction operator-()
	{	
		return Fraction(-up, down);
	}
	Fraction& operator++()
	{
		up+=down;
		return *this;
	}
	Fraction operator++(int)
	{	
		Fraction temp = *this;
		++(*this);
		return temp;
	}
	Fraction& operator--()
	{
		up -= down;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction temp = *this;
		--(*this);
		return temp;
	}
	string dump()
	{	
		if ((up < 0 && down < 0) || (up > 0 && down < 0))
			return (to_string(-up) + '/' + to_string(-down));
		else
			return (to_string(up) + '/' + to_string(down));
	}
private:
	void NOD(int& up, int& down) 
	{
		int a = abs(up);
		int b = abs(down);
		while (b != 0)
		{
			int c = b;
			b = a % b;
			a = c;
		}
		up /= a;
		down /= a;
	}
};

int main()
{	
	setlocale(LC_ALL, "Russian");

#if MODE == 1

	try
	{
		Fraction f1(4, 3);
		Fraction f2(6, 11);
		cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
		cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
		cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
		cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
		cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
		cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	}
	catch (const exception& ex)
	{
		cout << ex.what();
		return 1;
	}
	
#elif MODE == 2

	try
	{
		Fraction f1(4, 3);
		Fraction f2(8, 6);

		cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	}
	catch (const exception& ex)
	{
		cout << ex.what();
		return 1;
	}
	

#elif MODE == 3

	int up1 = 1, down1 = 1, up2 = 1, down2 = 1;
	cout << "Введите числитель дроби 1: ";
	cin >> up1;
	cout << "Введите знаменатель дроби 1: ";
	cin >> down1;
	cout << "Введите числитель дроби 2: ";
	cin >> up2;
	cout << "Введите знаменатель дроби 2: ";
	cin >> down2;

	try
	{
		Fraction f1(up1, down1), f2(up2, down2);

		cout << f1.dump() << " + " << f2.dump() << " = " << (f1 + f2).dump() << '\n';
		cout << f1.dump() << " - " << f2.dump() << " = " << (f1 - f2).dump() << '\n';
		cout << f1.dump() << " * " << f2.dump() << " = " << (f1 * f2).dump() << '\n';
		cout << f1.dump() << " / " << f2.dump() << " = " << (f1 / f2).dump() << '\n';
		cout << "++" + f1.dump() << " * " << f2.dump() << " = " << (++f1 * f2).dump() << '\n';
		cout << "Значение дроби 1 = " + f1.dump() << '\n';
		cout << f1.dump() + "--" << " * " << f2.dump() << " = " << (f1-- * f2).dump() << '\n';
		cout << "Значение дроби 1 = " + f1.dump() << '\n';
	}
	catch (const exception& ex)
	{
		cout << ex.what();
		return 1;
	}

#elif MODE == 4

	try
	{
		// Тест 1: Проверка конструкторов и dump
		{
			Fraction f1(3, 4);
			Fraction f2(4, 5);
			assert(f1.dump() == "3/4");
			assert(f2.dump() == "4/5");
		}
		// Тест 2: Проверка неравенства    
		{
			Fraction f1(4, 3);
			Fraction f2(6, 11);
			assert(!(f1 == f2));
			assert(f1 != f2);
			assert(!(f1 < f2));
			assert(f1 > f2);
			assert(!(f1 <= f2));
			assert(f1 >= f2);
		}
		// Тест 3: Проверка равенства    
		{
			Fraction f1(4, 3);
			Fraction f2(8, 6);
			assert(f1 == f2);
			assert(!(f1 != f2));
			assert(!(f1 < f2));
			assert(!(f1 > f2));
			assert(f1 <= f2);
			assert(f1 >= f2);
		}
		// Тест 4: Проверка сценария    
		{
			Fraction f1(3, 4);
			Fraction f2(4, 5);
			assert((f1 + f2).dump() == "31/20"); // 3/4 + 4/5 = 31/20        
			assert((f1 - f2).dump() == "-1/20"); // 3/4 - 4/5 = -1/20        
			assert((f1 * f2).dump() == "3/5");   // 3/4 * 4/5 = 3/5        
			assert((f1 / f2).dump() == "15/16"); // 3/4 / 4/5 = 15/16        
			assert((++f1 * f2).dump() == "7/5"); // ++3/4 * 4/5 = 7/5        
			assert(f1.dump() == "7/4");          // Значение дроби 1 = 7/4        
			assert((f1-- * f2).dump() == "7/5"); // 7/4-- * 4/5 = 7/5        
			assert(f1.dump() == "3/4");          // Значение дроби 1 = 3/4    
		}
		// Тест 5: Дополнительные проверки с унарным минусом    
		{
			Fraction f1(2, 3);
			Fraction f2(-2, 3);
			assert((-f1).dump() == "-2/3");
			assert((-f2).dump() == "2/3");
			assert((-f1) == f2);
		}
		// Тест 6: Проверка сокращения дробей    
		{
			Fraction f1(4, 8);
			Fraction f2(2, 4);
			Fraction f3(1, 2);
			assert(f1.dump() == "1/2");
			assert(f2.dump() == "1/2");
			assert(f3.dump() == "1/2");
			assert(f1 == f2);
			assert(f2 == f3);
		}
		// Тест 7: Проверка с отрицательными дробями    
		{
			Fraction f1(-3, 4);
			Fraction f2(3, -4);
			Fraction f3(-3, -4);
			assert(f1.dump() == "-3/4");
			assert(f2.dump() == "-3/4");
			assert(f3.dump() == "3/4");
			assert(f1 == f2);
			assert(f1 != f3);
		}
		std::cout << "All tests passed!" << std::endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what();
		return 1;
	}

#endif

	return 0;
}