#include <iostream>
#include "my_math.h"

int main()
{	
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите первое число: ";
	int a=1, b=1;
	std::cin >> a;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	std::cout << "Выберите операцию (1 - сложение, 2 - вычетание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	int ans = 1;
	std::cin >> ans;

	switch (ans)
	{
	case 1:
		std::cout << a << " + " << b << " = " << plus(a, b);
		break;
	case 2:
		std::cout << a << " - " << b << " = " << minus(a, b);
		break;
	case 3:
		std::cout << a << " * " << b << " = " << mult(a, b);
		break;
	case 4:
		std::cout << a << " / " << b << " = " << divide(a, b);
		break;
	case 5:
		std::cout << a << " в степени " << b << " = " << my_pow(a, b);
		break;
	default:
		std::cout << "Нет такого варианта";
		break;
	}

	return 0;
}