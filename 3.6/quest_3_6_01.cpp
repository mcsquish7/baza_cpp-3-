#include <iostream>
#define MODE 1

#ifndef MODE
#error MODE required
#endif // !MODE

#if MODE == 1
int add(int a, int b)
{
	return a + b;
}
#endif // MODE == 1


int main()
{
	setlocale(LC_ALL, "Russian");
#if MODE == 0
	std::cout << "Режим тренировки";
#elif MODE == 1
	std::cout << "Работаю в боевом режиме\n";
	int a=0, b=0;
	std::cout << "Введите число 1: ";
	std::cin >> a;
	std::cout << "Введите число 2: ";
	std::cin >> b;
	std::cout << "Результат сложения: " << add(a, b);
#else 
	std::cout << "Неизвестный режим. Завершение работы";
#endif // MODE == 0

	return 0;
}