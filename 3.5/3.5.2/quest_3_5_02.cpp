#include <iostream>
#include <string>
#include "class_Counter.h"

using namespace std;

void do_command(Counter& count)
{
	char command = 'x';
	while (true)
	{
		cout << "Введите команду ('+', '-', '=' или 'x'): ";
		cin >> command;
		if (command == '+')
		{
			count.inc();
			continue;
		}
		if (command == '-')
		{
			count.dec();
			continue;
		}
		if (command == '=')
		{
			count.get_count();
			continue;
		}
		if (command == 'x')
		{
			cout << "До свидания!";
			break;
		}

	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string ans = "";
	int val = 0;

	cout << "Вы хотите указать начальное значение счётчика? Введите y или n: ";
	cin >> ans;
	if (ans == "y")
	{
		cout << "Введите начальное значение счётчика: ";
		cin >> val;
		Counter count(val);
		do_command(count);
	}
	else if (ans == "n")
	{
		Counter count;
		do_command(count);
	}

	return 0;
}