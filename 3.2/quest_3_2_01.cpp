#include <iostream>

using namespace std;

class Calculator
{
public:

	double add()
	{
		return num1 + num2;
	}

	double multiply()
	{
		return num1 * num2;
	}
	double substract_1_2()
	{
		return num1 - num2;
	}
	double substract_2_1()
	{
		return num2 - num1;
	}
	double divide_1_2()
	{
		return num1 / num2;
	}
	double divide_2_1()
	{
		return num2 / num1;
	}
	bool set_num1(double num1)
	{	
		if (num1 == 0) return false;
		this->num1 = num1;
		return true;
	}
	bool set_num2(double num2)
	{	
		if (num2 == 0) return false;
		this->num2 = num2;
		return true;
	}
private:
	double num1, num2;

};

int main()
{	
	setlocale(LC_ALL, "Russian");
	Calculator calc;
	double num1 = 0, num2 = 0;
	while (true)
	{
		while (true)
		{
			cout << "Введите num1: ";
			cin >> num1;
			if (!calc.set_num1(num1))
			{
				cout << "Неверный ввод!\n";
				continue;
			}
			break;
		}

		while (true)
		{
			cout << "Введите num2: ";
			cin >> num2;
			if (!calc.set_num2(num2))
			{
				cout << "Неверный ввод!\n";
				continue;
			}
			break;
		}

		cout << "num1 + num2 = " << calc.add();
		cout << "\nnum1 - num2 = " << calc.substract_1_2();
		cout << "\nnum2 - num1 = " << calc.substract_2_1();
		cout << "\nnum1 * num2 = " << calc.multiply();
		cout << "\nnum1 / num2 = " << calc.divide_1_2();
		cout << "\nnum2 / num1 = " << calc.divide_2_1() << "\n";
	}

	return 0;
}